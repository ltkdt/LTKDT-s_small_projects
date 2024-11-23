#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "freertos/queue.h"

#define BLINK_GPIO GPIO_NUM_32
#define BUTTON_GPIO GPIO_NUM_33

TaskHandle_t BlinkyTaskHandle = NULL;

QueueHandle_t myQueue; 

bool led_state = false;
 
void Blinky_Task(void *arg)
{
    while(1){
        if(xQueueReceive(myQueue, &led_state, portMAX_DELAY)){
            gpio_set_level(BLINK_GPIO, led_state);
        }
    }
}
 
static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    led_state = !led_state;
    xQueueSendFromISR(myQueue, &led_state, NULL);
}
 
void app_main(void){
    esp_rom_gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
 
    esp_rom_gpio_pad_select_gpio(BUTTON_GPIO);
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
 
    gpio_pullup_en(BUTTON_GPIO);
 
    gpio_pulldown_dis(BUTTON_GPIO);

    /* Raising edge signal will trigger our interrupt */
    gpio_set_intr_type(BUTTON_GPIO, GPIO_INTR_POSEDGE);

    /* install gpio isr service to default values */
    gpio_install_isr_service(0);

    /* Attach the ISR to the GPIO interrupt */
    gpio_isr_handler_add(BUTTON_GPIO, gpio_isr_handler, NULL);

    /* Enable the Interrupt */
    gpio_intr_enable(BUTTON_GPIO);

    // Create the queue
    myQueue = xQueueCreate(3, sizeof(char));
 
    xTaskCreatePinnedToCore(Blinky_Task, "Blinky", 4096, NULL, 10, &BlinkyTaskHandle, 0);  // Core 0
}