#pragma once

// --- Pin Definitions (Matching U1 ESP32-S3-Zero) ---
#define PIN_LED_DEBUG 1
#define PIN_CS_ACCESSORY 2
#define PIN_RFM_RESET 4
#define PIN_RFM_IRQ 5
#define PIN_SPI_SCK 6
#define PIN_SPI_MISO 7
#define PIN_SPI_MOSI 8
#define PIN_SPI_CS 9
#define PIN_I2C0_SCL 10
#define PIN_I2C0_SDA 11
#define PIN_NEOPIXEL_DATA 21
#define PIN_UART_TX 43
#define PIN_UART_RX 44

// --- I2C ---
#define I2C_SDA PIN_I2C0_SDA
#define I2C_SCL PIN_I2C0_SCL

// --- Heartbeat Status LED ---
#define LED_PIN PIN_LED_DEBUG
#define LED_STATE_ON 1

// --- RGB NeoPixel ---
#define HAS_NEOPIXEL 
#define NEOPIXEL_COUNT 1
#define NEOPIXEL_DATA PIN_NEOPIXEL_DATA
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800)
#define ENABLE_AMBIENT_LIGHTING

// --- Battery Telemetry (Uncomment when voltage divider is soldered) ---
// #define BATTERY_PIN PIN_CS_ACCESSORY // Assumes you repurpose GPIO 2 for the divider
// #define ADC_MULTIPLIER 2.0           // Start at 2.0 for a 100k/100k divider, adjust via multimeter

// --- Radio Setup (RFM95W) ---
#define USE_RF95
#define LORA_SCK PIN_SPI_SCK
#define LORA_MISO PIN_SPI_MISO
#define LORA_MOSI PIN_SPI_MOSI
#define LORA_CS PIN_SPI_CS
#define LORA_DIO0 PIN_RFM_IRQ
#define LORA_RESET PIN_RFM_RESET
#define LORA_DIO1 RADIOLIB_NC
#define LORA_DIO2 RADIOLIB_NC
