#include "main.h"
#define led 2

void blink_task(void *pvParameter)
{
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_pad_select_gpio(led);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(led, GPIO_MODE_OUTPUT);
    while(1) {
        /* Blink off (output low) */
        gpio_set_level(led, 0);
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        /* Blink on (output high) */
        gpio_set_level(led, 1);
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    xTaskCreate(&blink_task, "hello_task", 2048, NULL, 5, NULL);
}