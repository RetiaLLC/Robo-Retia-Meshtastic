# Retia Nibble Firmware Optimization & Build Guide

This document outlines the architectural changes and performance optimizations applied to the Meshtastic firmware for Retia LLC's Nibble hardware series.

## 1. Overview of Changes

We have optimized the firmware for two primary hardware variants:
*   **Nibble Zero Connect:** Waveshare ESP32-S3 Zero + Seeed Studio SX1262.
*   **Nibble ESP32:** Retia Open Source Nibble (ESP32-S3 Zero + RFM95).

### Key Optimizations:
1.  **"Turbo" Boot Sequence:** Reduced initial network broadcast delay from 30s to 5s.
2.  **Radio Initialization Fix:** Restored standard TCXO power-up sequence (`TCXO_VOLTAGE 1.8`) to ensure reliable SX1262 initialization on ESP32-S3.
3.  **Hardware UI defaults:**
    *   Heartbeat Status LED enabled on **GPIO 39** (Zero Connect) and **GPIO 1** (Open Source).
    *   NeoPixel enabled on **GPIO 21**.
    *   Ambient Lighting module auto-starts on fresh installs.

---

## 2. Engineering Implementation (The "Dirty" Hack)

To achieve maximum stability and performance, we modified two core Meshtastic files. These changes are required for the "Turbo" 5s boot and Ambient Lighting defaults.

### A. Core Modifications
*   **`src/mesh/MeshModule.h`**: Hardcoded `MESHMODULE_MIN_BROADCAST_DELAY_MS` to `5 * 1000`.
*   **`src/mesh/NodeDB.cpp`**: Hardcoded `moduleConfig.ambient_lighting.led_state = true` in `installDefaultModuleConfig`.

### B. Maintenance for Future Versions
When a new version of Meshtastic is released, these two files must be updated manually. Search for the macro names in the new source code and apply the 5s/true values to maintain Retia's optimized performance.

---

## 3. Developer Reproducibility

### Setup
Ensure you have PlatformIO CLI installed and the Meshtastic firmware repository cloned.

### Compilation & Flashing
We created an all-in-one script `compile_and_flash.sh` to handle the build logic.

```bash
# For Nibble Zero
./compile_and_flash.sh nibble-zero-connect

# For Open Source Nibble
./compile_and_flash.sh nibble-esp32
```

---
**Maintained by Retia LLC Engineering.**
