// Pin definitions to match schematics drawing
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
#define PIN_WEMOS_S3_MINI_LED_DATA 21
#define PIN_UART_TX 43
#define PIN_UART_RX 44
// End pin definitions

#define I2C_SDA PIN_I2C0_SDA // I2C pins for this board
#define I2C_SCL PIN_I2C0_SCL

#define LED_POWER PIN_LED_DEBUG // Replaces LED_PIN for the modern Meshtastic heartbeat
#define LED_STATE_ON 1          // Tells Meshtastic the LED circuit is Active-High

#define HAS_NEOPIXEL                              // Enable the use of neopixels
#define NEOPIXEL_COUNT 1                          // How many neopixels are connected
#define NEOPIXEL_DATA PIN_WEMOS_S3_MINI_LED_DATA  // gpio pin used to send data to the neopixels
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800)      // type of neopixels in use

#define ENABLE_AMBIENTLIGHTING

// #define BUTTON_PIN 0 // If defined, this will be used for user button presses
// #define BUTTON_NEED_PULLUP

#define USE_RF95
#define LORA_SCK PIN_SPI_SCK
#define LORA_MISO PIN_SPI_MISO
#define LORA_MOSI PIN_SPI_MOSI
#define LORA_CS PIN_SPI_CS
#define LORA_DIO0 PIN_RFM_IRQ
#define LORA_RESET PIN_RFM_RESET

#define LORA_DIO1 RADIOLIB_NC
#define LORA_DIO2 RADIOLIB_NC
