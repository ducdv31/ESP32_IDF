#include <driver/adc.h>
#include <stdio.h>              // For c standart
#include "freertos/FreeRTOS.h"  // RTOS
#include "freertos/task.h"      // Multi-task
#include "esp_system.h"         // Same startup file
#include "driver/gpio.h"        // Config Input & Output
#include "driver/uart.h"
#include "esp_wifi.h"

#define led 2
#define ssid ""
#define pass ""


void hello_task(void *pvParameter){

    while (1)
    {
        printf("Hello world \n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    
}

void uart_task(void *pvParameter){

    const int uart_num = UART_NUM_2;
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_CTS_RTS,
        .rx_flow_ctrl_thresh = 122,
    };
    // Configure UART parameters
    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
    while (1)
    {
        
    }
    
}

void blink_task(void *pvParameters){

    gpio_pad_select_gpio(led);
    gpio_set_direction(led, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_set_level(led, 0);
        vTaskDelay(200/portTICK_PERIOD_MS);
        gpio_set_level(led, 1);
        vTaskDelay(200/portTICK_PERIOD_MS);
    }
    
}
void bluetooth_classic(void *pvParameter){

    while (1)
    {
        
    }
    
}

void wifi_config(void *pvParameter){

    while (1)
    {
        
    }
    
}
void app_main() {

    xTaskCreatePinnedToCore(&hello_task, "Hello", 1024, NULL, 5, NULL, 0);
    // xTaskCreatePinnedToCore(&uart_task, "UART", 2048, NULL, 6, NULL, 1);
    xTaskCreatePinnedToCore(&blink_task, "Blink_Led",  1024, NULL, 7, NULL, 1);
}
