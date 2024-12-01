#include <string.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_adc/adc_oneshot.h"
#include "hal/adc_types.h"

#include "esp_adc/adc_cali_scheme.h"
#include "esp_adc/adc_cali.h"

/*
This code sample prints out the ADC input in the monitor.
The ADC input is obtained from the middle pin of the potentiometer.
*/

TaskHandle_t ADCTaskHandle = NULL;

void ADCTask(void *arg){
    int potentiometer_read, potentiometer_output;
    
    /*                        CREATE ADC UNIT                           */

    adc_oneshot_unit_handle_t handle = NULL;

    adc_oneshot_unit_init_cfg_t init_config1 = {
    .unit_id = ADC_UNIT_2,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
    };

    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &handle));

    adc_oneshot_chan_cfg_t config = {
    .bitwidth = ADC_BITWIDTH_12, // or you can use ADC_BITWIDTH_DEFAULT here
    .atten = ADC_ATTEN_DB_12,
    };

    ESP_ERROR_CHECK(adc_oneshot_config_channel(handle, ADC_CHANNEL_9, &config));
    
    // You can apply the same config to a different channel or pin 
    // ESP_ERROR_CHECK(adc_oneshot_config_channel(handle, ADC_CHANNEL_8, &config));
    
    /*                          CALIBRATION                             */

    adc_cali_handle_t cali_handle = NULL;

    adc_cali_line_fitting_config_t cali_config = {
        .unit_id = ADC_UNIT_2,
        .atten = ADC_ATTEN_DB_12,
        .bitwidth = ADC_BITWIDTH_12,
    };

    ESP_ERROR_CHECK(adc_cali_create_scheme_line_fitting(&cali_config, &cali_handle));

    /*          READ RAW ADC INPUT AND CONVERT TO MILIVOLTS             */
    while(1)
    {
        ESP_ERROR_CHECK(adc_oneshot_read(handle, ADC_CHANNEL_9, &potentiometer_read));
        printf(" ADC_CHANNEL_9 (GPIO 26) ADC input from potentiometer:   %d \n", potentiometer_read);
        adc_cali_raw_to_voltage(cali_handle, potentiometer_read, &potentiometer_output);
        printf(" Milivolt output after calibration - Channel 9 %d \n", potentiometer_output);
        printf("\n * \n\n");

        vTaskDelay(100);
    }
    adc_oneshot_del_unit(handle);
    adc_cali_delete_scheme_line_fitting(cali_handle);
    vTaskDelete(NULL);
}

void app_main(void){
    xTaskCreatePinnedToCore(ADCTask, "ADC Task", 4096, NULL, 10, &ADCTaskHandle, 0);
}