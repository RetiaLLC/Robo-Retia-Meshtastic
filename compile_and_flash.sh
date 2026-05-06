#!/bin/bash

# Usage: ./compile_and_flash.sh [variant_name]
# Default to nibble-zero-connect if no argument provided
ENV_NAME="${1:-nibble-zero-connect}"

# Configuration
REPO_ROOT="/home/local/CompileMeshtastic"
PROJECT_DIR="$REPO_ROOT/meshtastic-firmware"
LOG_FILE="$REPO_ROOT/flash_log_${ENV_NAME}.txt"

echo "=== Starting Build and Flash for $ENV_NAME ===" | tee $LOG_FILE
date | tee -a $LOG_FILE

# 1. Sync variant files to ensure the latest changes are included
echo "Syncing variant files..." | tee -a $LOG_FILE
cp -r $REPO_ROOT/variants/retia-nibble/$ENV_NAME $PROJECT_DIR/variants/
mkdir -p $PROJECT_DIR/boards
find $REPO_ROOT/variants/retia-nibble/ -name "*.json" -exec cp {} $PROJECT_DIR/boards/ \;

# Ensure the environment is in the main platformio.ini
if ! grep -q "\[env:$ENV_NAME\]" $PROJECT_DIR/platformio.ini; then
    echo "Adding $ENV_NAME to platformio.ini..." | tee -a $LOG_FILE
    echo "" >> $PROJECT_DIR/platformio.ini
    sed "s/\[env:.*\]/[env:$ENV_NAME]/" "$PROJECT_DIR/variants/$ENV_NAME/platformio.ini" >> $PROJECT_DIR/platformio.ini
fi

cd $PROJECT_DIR || { echo "Failed to enter directory" | tee -a $LOG_FILE; exit 1; }

# Export environment variables for PlatformIO
export PATH="$HOME/.local/bin:$PATH"
export PLATFORMIO_BUILD_UNFLAGS="-DLED_BUILTIN"
export PLATFORMIO_BUILD_FLAGS="-I variants/$ENV_NAME -ULED_BUILTIN"
export PLATFORMIO_BOARD_BUILD_VARIANT="$ENV_NAME"

# Automatically find the device
PORT=$(ls /dev/ttyACM* 2>/dev/null | head -n 1)

if [ -z "$PORT" ]; then
    echo "ERROR: No /dev/ttyACM* device found! Is the board plugged in?" | tee -a $LOG_FILE
    exit 1
fi

echo "Found device on port: $PORT" | tee -a $LOG_FILE
echo "Compiling and Flashing... (See output below)" | tee -a $LOG_FILE

# Run compilation and upload, showing output to user AND saving to log
# We use 'unbuffer' or just standard piping. pio output is usually okay with tee.
pio run --target upload -e $ENV_NAME --upload-port $PORT 2>&1 | tee -a $LOG_FILE

if [ ${PIPESTATUS[0]} -eq 0 ]; then
    echo "------------------------------------------------" | tee -a $LOG_FILE
    echo "SUCCESS: Firmware compiled and flashed to $PORT." | tee -a $LOG_FILE
    
    # Trigger a soft reset via esptool just to be 100% sure the new code runs
    echo "Triggering software reset..." | tee -a $LOG_FILE
    ~/.platformio/packages/tool-esptoolpy/esptool.py --port $PORT --after hard_reset chip_id > /dev/null 2>&1
    
    echo "Done! You can now connect via Bluetooth or serial." | tee -a $LOG_FILE
else
    echo "------------------------------------------------" | tee -a $LOG_FILE
    echo "ERROR: Compilation or flashing failed." | tee -a $LOG_FILE
    echo "Check the errors above or in $LOG_FILE."
fi
