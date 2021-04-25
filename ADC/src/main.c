#include <driver/adc.h>
#include <stdio.h>              // For c standart
#include "freertos/FreeRTOS.h"  // RTOS
#include "freertos/task.h"      // Multi-task
#include "esp_system.h"         // Same startup file
#include "driver/gpio.h"        // Config Input & Output

void adc_config(void);
void adc_task(void *pvParameters){
    adc_config();
    while (1)
    {
        int val = adc1_get_raw(ADC1_CHANNEL_5);
        printf("Gia tri adc %d", val);
        vTaskDelay( 1000 / portTICK_PERIOD_MS);
    }
    
}

void app_main() {
    
    xTaskCreate(&adc_task, "ADC read", 1024, NULL, 5, NULL);
    
}


void adc_config(){
    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_5, ADC_ATTEN_DB_0);
}