#include "stm32l476xx.h"
#include "stm32l4xx.h"
#include "gpio.h"

int main(void)
{
    led_init();
    button_init();

    while (1)
    {
        if (get_btn_state())
        {
            led_on();
        }
        else
        {
            led_off();
        }
    }
}
