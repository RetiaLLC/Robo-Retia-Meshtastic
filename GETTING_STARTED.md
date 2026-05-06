# Getting Started with Nibble Development

Welcome to the Retia Nibble firmware project. This guide will help you set up your environment and build custom firmware for Nibble hardware.

## 1. Prerequisites
*   **OS:** Linux (Recommended), macOS, or Windows (WSL2).
*   **PlatformIO CLI:** Install via `pip install platformio`.
*   **Meshtastic CLI:** Install via `pip install meshtastic`.
*   **Git:** To manage source code.

## 2. Environment Setup
1.  Clone the Retia hardware repository.
2.  Inside the directory, clone the Meshtastic firmware:
    ```bash
    git clone --depth 1 https://github.com/meshtastic/firmware meshtastic-firmware
    ```
3.  Run the sync command to install Retia variant files:
    ```bash
    ./compile_and_flash.sh [variant]
    ```

## 3. Building Firmware
You can build for either supported hardware target using the provided automation script:

### Target A: Nibble Zero Connect
*   **Hardware:** Waveshare ESP32-S3 Zero + SX1262
*   **Command:** `./compile_and_flash.sh nibble-zero-connect`

### Target B: Nibble ESP32 (Open Source)
*   **Hardware:** Retia Nibble (ESP32-S3 Zero + RFM95)
*   **Command:** `./compile_and_flash.sh nibble-esp32`

## 4. Troubleshooting
If the radio fails to initialize (Error -707):
1.  Check that `SX126X_DIO3_TCXO_VOLTAGE 1.8` is defined in `variant.h` for SX1262 boards.
2.  Ensure the ESP32-S3 is in bootloader mode (hold BOOT, tap RESET).
3.  Check the logs at `flash_log_[variant].txt`.

---
**Retia LLC - Secure, Fast, Open Mesh.**
