#!/bin/bash

# Usage: ./monitor_meshtastic.sh [output_filename]
# Default log name if none provided
LOG_NAME="${1:-meshtastic_boot_log.txt}"
REPO_ROOT="/home/local/CompileMeshtastic"
LOG_FILE="$REPO_ROOT/$LOG_NAME"

echo "=== Meshtastic Serial Monitor & Logger ==="
echo "Saving output to: $LOG_FILE"
echo "Press Ctrl+C to stop monitoring."
echo "----------------------------------------"

# 1. Automatically find the device
PORT=$(ls /dev/ttyACM* 2>/dev/null | head -n 1)

if [ -z "$PORT" ]; then
    echo "ERROR: No /dev/ttyACM* device found! Is the board plugged in?"
    exit 1
fi

echo "Connected to: $PORT"
echo "Waiting for data... (Reset your board now to capture boot sequence)"
echo "----------------------------------------"

# 2. Configure the serial port (115200 baud, raw mode)
stty -F "$PORT" 115200 raw -echo -echoe -echok

# 3. Mirror to console and file until Ctrl+C
# We use 'tee' to mirror output. 
# We use 'cat' to read the port directly for maximum speed/low overhead.
cat "$PORT" | tee "$LOG_FILE"
