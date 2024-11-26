#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "sdkconfig.h"
#include "driver/ledc.h"

/*
According to the datasheet, the frequency should be 50Hz, which means that each period lasts 20 ms.

For our pulse width:
Position "0" (1.5 ms pulse) is middle, "90" (~2ms pulse) is all the way to the right, 
"-90" (~1ms pulse) is all the way to the left.

We are working with 15 bit duty resolutions here, so the maximum value is 2^15 - 1 = 32767.
1 ms and 2 ms are respectively "full" left and "full" right. Its corresponding duty value is 1638 and 3276 (since 1638 / 32767 ≈ 1ms / 20ms and 3276 / 32767 ≈ 2ms / 20ms)

We want the servo to rotate from left to right then reverse the direction once done. This operation is repeated infinitely.

We start from our initial duty cycle of 1638 then increment its value to 3276 then reduce it back to 1638. 
The boolean value stores the direction. So once the duty reaches its minimum or maximum value, the direction should change itself.

Doing it a little bit of Maths. We can can set the delta / step to be 14, and the number of iteration for the duty cycle to reach the 
maximum from the inital minimum value is 117 as:

1638 + 14 * 117 = 3276
*/

void servoRotate_task(void *args) {

	int duty = 1638 ; // The duty will vary from 1638 to 3276
    int step = 14; // each iteration, the duty increments itself by this step
	int total_cycles = 117; // 117 iterations in total
	bool pos_direction = true; // true = up, false = down
	int iteration_time = 10; // msecs

	ledc_timer_config_t timer_conf = {
		.duty_resolution = LEDC_TIMER_15_BIT,
		.freq_hz = 50,
		.speed_mode = LEDC_HIGH_SPEED_MODE,
		.timer_num = LEDC_TIMER_0,
		.clk_cfg = LEDC_AUTO_CLK,
	};

	ledc_timer_config(&timer_conf); // Apply timer config

	ledc_channel_config_t ledc_conf = {
		.channel = LEDC_CHANNEL_0,
		.duty = duty,
		.gpio_num = 25,
		.intr_type = LEDC_INTR_DISABLE,
		.speed_mode = LEDC_HIGH_SPEED_MODE,
		.timer_sel = LEDC_TIMER_0,
	};

	ledc_channel_config(&ledc_conf); //  Apply channel config

	int i;
	while(1) {
		for (i=0; i < total_cycles; i++) {
			// If the direction is positive, the duty increments itself, otherwise it will be reduced in value
			pos_direction ? (duty += step) : (duty -= step);

			// Set the new duty and update it in each iteration

			ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty);
			ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
			
			// Wait for 10 microseconds
			vTaskDelay(iteration_time/portTICK_PERIOD_MS);
		}
		// Change the direction
		pos_direction = !pos_direction;
	} 
}

void app_main()
{	   
    xTaskCreate(&servoRotate_task,"servoRotate_task",2048,NULL,5,NULL);
}