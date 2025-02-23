/*

Description: Create a triangular wave then cosine wave out of pin 25 (channel 0)
I'm using a cheap oscilloscope to monitor the waveform. You can also wire the GPIO 25 pin to another ADC pin and then monitor the analog
values yourself if you don't own an oscilloscope

*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/dac_cosine.h"
#include "esp_check.h"
#include "driver/dac_oneshot.h"

TaskHandle_t CosWaveGeneratorHandle = NULL;
TaskHandle_t DACOneShotOutputHandle = NULL;

// Cosine wave generator

void init_dac_cosine_channel(dac_cosine_handle_t* handle){
    dac_cosine_config_t cos_cfg = {
        .chan_id = DAC_CHAN_0,      // Chan 0 - GPIO 25
        .freq_hz = 1000,        // 1 KHz 
        .clk_src = DAC_COSINE_CLK_SRC_DEFAULT,
        .offset = 0,
        .phase = DAC_COSINE_PHASE_0,
        .atten = DAC_COSINE_ATTEN_DEFAULT,
        .flags.force_set_freq = false,
    };
    ESP_ERROR_CHECK(dac_cosine_new_channel(&cos_cfg, handle));
}


void cos_wave_generator_task(){
    vTaskSuspend(NULL);
    dac_cosine_handle_t cos_handle;
    
    init_dac_cosine_channel(&cos_handle);
    dac_cosine_start(cos_handle);

    for(;;);                // This endless loop is meant to stop the ESP32 from reseting itself once the task ended
}

// This task creates triangular waveform
void dac_oneshot_output_task(void *args)
{
    int i =0;
    dac_oneshot_handle_t oneshot_handle;
    dac_oneshot_config_t oneshot_config = {
        .chan_id = DAC_CHAN_0,
    };
    ESP_ERROR_CHECK(dac_oneshot_new_channel(&oneshot_config, &oneshot_handle));
    uint8_t val = 0;

    while(i < 50){


        for(val = 0; val < 255; val += 5){
            ESP_ERROR_CHECK(dac_oneshot_output_voltage(oneshot_handle, val));
            vTaskDelay(10/portTICK_PERIOD_MS);
        }

        for(val = 255; val > 0; val-=5){
            ESP_ERROR_CHECK(dac_oneshot_output_voltage(oneshot_handle, val));
            vTaskDelay(10/portTICK_PERIOD_MS);
        }
        // Delete line 63 to 65 will create sawtooth wave :>

        i++;
    }
        
    dac_oneshot_del_channel(oneshot_handle);
    vTaskResume(CosWaveGeneratorHandle);
    vTaskDelete(NULL);

    // The Cosine Wave Generator will run once this task is deleted
}

void app_main(void)
{
    // Cosine Wave Generator
    xTaskCreatePinnedToCore(cos_wave_generator_task, "Cos Wave Generator", 4096, NULL, 5, &CosWaveGeneratorHandle,0); 
    
    // DAC One Shot Output - Triangular wave
    xTaskCreatePinnedToCore(dac_oneshot_output_task, "DAC OneShot Output", 4096, NULL, 5, &DACOneShotOutputHandle,1);
}