#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include "gpio.h"
#include "systick.h"

int main(void)
{
    led_init();

    while (1)
    {
        led_on();
        systick_msc_delay(1000);
        led_off();
        systick_msc_delay(1000);
    }
}
