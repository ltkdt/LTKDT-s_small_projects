#include <driver/gpio.h>
#include <driver/i2c_master.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"

#include <u8g2.h>
#include "u8g2_esp32_hal.h"

// SDA - GPIO21
#define PIN_SDA 21

// SCL - GPIO22
#define PIN_SCL 22

static const char* TAG = "sh1106";

const unsigned char ytb [] = {
  	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xfe, 
	0xff, 0xff, 0x7f, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0x01, 0x80, 0xff, 0xff, 0xff, 
	0xff, 0x01, 0x80, 0xff, 0xff, 0xff, 0xff, 0x01, 0x80, 0xff, 0x8f, 0xff, 0xff, 0x01, 0x80, 0xff, 
	0x0f, 0xfe, 0xff, 0x01, 0x80, 0xff, 0x0f, 0xf8, 0xff, 0x01, 0x80, 0xff, 0x0f, 0xe0, 0xff, 0x01, 
	0x80, 0xff, 0x0f, 0xe0, 0xff, 0x01, 0x80, 0xff, 0x0f, 0xf8, 0xff, 0x01, 0x80, 0xff, 0x0f, 0xfe, 
	0xff, 0x01, 0x80, 0xff, 0x8f, 0xff, 0xff, 0x01, 0x80, 0xff, 0xff, 0xff, 0xff, 0x01, 0x80, 0xff, 
	0xff, 0xff, 0xff, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xfe, 0xff, 0xff, 
	0x7f, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void app_main(void) {
  u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
  u8g2_esp32_hal.bus.i2c.sda = PIN_SDA;
  u8g2_esp32_hal.bus.i2c.scl = PIN_SCL;
  u8g2_esp32_hal_init(u8g2_esp32_hal);

    u8g2_Setup_sh1106_i2c_128x64_noname_f(&u8g2, U8G2_R0,
      u8g2_esp32_i2c_byte_cb,
      u8g2_esp32_gpio_and_delay_cb);  // These are I2C callback function for mapping 

  u8g2_t u8g2;  // this structure which will contain all the data for the display

  u8x8_SetI2CAddress(&u8g2.u8x8, 0x78);  // The address is left-shifted 1 bit
  ESP_LOGI(TAG, "u8g2_InitDisplay");
  u8g2_InitDisplay(&u8g2);  // send init sequence to the display, display is in sleep mode after this,

  ESP_LOGI(TAG, "u8g2_SetPowerSave");
  u8g2_SetPowerSave(&u8g2, 0);  // wake up display
  ESP_LOGI(TAG, "u8g2_ClearBuffer");
  u8g2_ClearBuffer(&u8g2);

  u8g2_DrawXBM(&u8g2, 40, -5, 48,48, ytb);
  u8g2_SetFont(&u8g2 ,u8g2_font_helvR08_tr);
  u8g2_DrawButtonUTF8(&u8g2, 64, 50, U8G2_BTN_SHADOW1|U8G2_BTN_HCENTER|U8G2_BTN_BW2, 56,  2,  2, "Subscribe to ltkdt" );
  
  u8g2_SendBuffer(&u8g2); // Send the buffer data to display
  vTaskDelete(NULL);
}
