#ifndef _VARIANT_NIBBLE_RP2350_
#define _VARIANT_NIBBLE_RP2350_

// Pin definitions exactly matching the U3 schematic drawing
#define PIN_LED_DEBUG 1
#define PIN_CS_ACCESSORY 2
#define PIN_I2C0_SDA 4
#define PIN_I2C0_SCL 5
#define PIN_SPI_SCK 10
#define PIN_SPI_MOSI 11
#define PIN_SPI_MISO 12
#define PIN_SPI_CS 13
#define PIN_RFM_IRQ 14
#define PIN_RFM_RESET 15
// End pin definitions

#define I2C_SDA PIN_I2C0_SDA // I2C pins for this board
#define I2C_SCL PIN_I2C0_SCL

// --- Standard LED (Heartbeat) ---
#define LED_PIN PIN_LED_DEBUG // If defined we will blink this LED
#define LED_STATE_ON 1        // Set to 1 because the LED is wired to GND (active-high)

// --- NeoPixel (Rich Status) ---
#define HAS_NEOPIXEL 1                            // Enable the use of neopixels
#define NEOPIXEL_COUNT 1                          // The Waveshare has exactly 1 NeoPixel
#define NEOPIXEL_DATA 16                          // Waveshare RP2350-Zero built-in WS2812 pin
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800)      // Standard WS2812 protocol

// #define ENABLE_AMBIENTLIGHTING

// #define BUTTON_PIN 0 // If defined, this will be used for user button presses
// #define BUTTON_NEED_PULLUP

#define HAS_CPU_SHUTDOWN 1

#define USE_RF95
#define LORA_SCK PIN_SPI_SCK
#define LORA_MISO PIN_SPI_MISO
#define LORA_MOSI PIN_SPI_MOSI
#define LORA_CS PIN_SPI_CS
#define LORA_DIO0 PIN_RFM_IRQ
#define LORA_RESET PIN_RFM_RESET

#define LORA_DIO1 RADIOLIB_NC
#define LORA_DIO2 RADIOLIB_NC

#endif
