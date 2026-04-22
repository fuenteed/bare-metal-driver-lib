#include "systick.h"
#include <stdint.h>

//in the systick control and status register SYST_CSR, the first bit correcsponds to enabling the systick counter.
#define CTRL_ENABLE (1U << 0) 

//selects the clock source in the SYS_CSR
#define CTRL_CLCKSRC (1U << 2)

//indicates whether the counter has reached zero since last read
#define CTRL_COUNTFLAG (1U << 16)

// frequency of MCU is 16mhz
#define DEFAULT_CLOCK_FREQ 16000

void systick_msc_delay(uint32_t delay)
{
    //set reload value register - set the period
    SysTick->LOAD = DEFAULT_CLOCK_FREQ - 1;

    //clear current value register
    SysTick->VAL = 0;

    //select internal clock source - set to 1 to enable SysTick Counter using OR to set
    SysTick->CTRL = CTRL_CLCKSRC;

    //enable systick
    SysTick->CTRL |= CTRL_ENABLE;

    for(int i = 0; i < delay; i++)
    {
        while((SysTick->CTRL & CTRL_COUNTFLAG) == 0){}
    }

    SysTick->CTRL = 0;

}