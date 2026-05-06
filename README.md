# Robo-Retia-Meshtastic

Official repository for Retia LLC's optimized Meshtastic firmware for the **Nibble** hardware series.

## 🚀 The "Turbo" Advantage
This repository provides a custom-tuned version of Meshtastic designed for rapid deployment and high-reliability hardware monitoring.

*   **Turbo Boot:** Initial network broadcast delay reduced from 30 seconds to **5 seconds**.
*   **Instant Radio Init:** Optimized power-up sequence for SX1262 and RFM95 modules.
*   **Hardware UI:** Built-in support for the Ear Heartbeat LED (GPIO 39/1) and NeoPixel status (GPIO 21).

---

## 🛠 Supported Hardware

### 1. Nibble Zero Connect
*   **Core:** Waveshare ESP32-S3 Zero
*   **Radio:** Seeed Studio SX1262
*   **Pins:** LED (39), NeoPixel (21), Button (1)

### 2. Nibble ESP32 (Open Source)
*   **Core:** ESP32-S3 Zero
*   **Radio:** RFM95 (SX127x)
*   **Pins:** LED (1), NeoPixel (21), Button (1)

---

## 📥 Quick Start: Flashing

If you just want to get your hardware running, use the pre-compiled factory binaries in the root folder.

### Using the Script (Linux/macOS)
1. Plug in your device via USB.
2. Run the included monitoring/flashing utility:
   ```bash
   ./compile_and_flash.sh [nibble-zero-connect | nibble-esp32]
   ```

### Using Web Flasher
1. Go to [flasher.meshtastic.org](https://flasher.meshtastic.org).
2. Select your device and upload the corresponding `-factory.bin` file starting at address **`0x0`**.

---

## 🏗 Developer Guide: Compiling from Source

If you want to modify the code or build it yourself:

1.  **Clone this repo:**
    ```bash
    git clone https://github.com/RetiaLLC/Robo-Retia-Meshtastic.git
    cd Robo-Retia-Meshtastic
    ```
2.  **Pull Meshtastic Firmware:**
    ```bash
    git clone --depth 1 https://github.com/meshtastic/firmware meshtastic-firmware
    ```
3.  **Build & Flash:**
    ```bash
    ./compile_and_flash.sh nibble-zero-connect
    ```

For more detailed architectural information and the "Clean Refactor" strategy, see [DEVELOPER.md](./DEVELOPER.md) and [GETTING_STARTED.md](./GETTING_STARTED.md).

---

## 📊 Performance Monitoring
To capture and compare boot sequences across different hardware, use the provided monitoring tool:
```bash
./monitor_meshtastic.sh my_node_performance.txt
```

---
**Retia LLC - Secure, Fast, Open Mesh.**
