#define I2C_SDA 33 // I2C pins for this board
#define I2C_SCL 35

#define USE_SH1106

#define LED_POWER 15 // Updated to modern Meshtastic heartbeat macro
#define LED_STATE_ON 1 // Tells Meshtastic the LED circuit is Active-High

#define HAS_NEOPIXEL                         // Enable the use of neopixels
#define NEOPIXEL_COUNT 1                     // Fixed: v6 Schematic shows 1 WS2812B chip
#define NEOPIXEL_DATA 12                     // gpio pin used to send data to the neopixels
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800) // type of neopixels in use

#define ENABLE_AMBIENTLIGHTING

#define BUTTON_PIN 7 // If defined, this will be used for user button presses
#define BUTTON_NEED_PULLUP

#define USE_RF95
#define LORA_SCK 4   // Fixed for v6.0
#define LORA_MISO 6  // Fixed for v6.0
#define LORA_MOSI 8  // Fixed for v6.0
#define LORA_CS 10   // Fixed for v6.0
#define LORA_DIO0 16
#define LORA_RESET 5

#define LORA_DIO1 RADIOLIB_NC
#define LORA_DIO2 RADIOLIB_NC
