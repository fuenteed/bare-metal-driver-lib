#include "stm32l476xx.h"
#include <stdint.h>

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;

int main(void);

void Reset_Handler(void);
void Default_Handler(void);

void NMI_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void PVD_PVM_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM15_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM16_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM17_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT3_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void ADC3_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void FMC_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void SDMMC1_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel1_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel2_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel3_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel4_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel5_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT0_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT1_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT2_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void COMP_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void LPTIM1_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void LPTIM2_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel6_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel7_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void LPUART1_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void QUADSPI_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void SAI1_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void SAI2_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void SWPMI1_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void TSC_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void LCD_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void RNG_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));

__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) =
{
    (void (*)(void))(&_estack),         /*   0 */
    Reset_Handler,                      /*   1 */
    NMI_Handler,                        /*   2 */
    HardFault_Handler,                  /*   3 */
    MemManage_Handler,                  /*   4 */
    BusFault_Handler,                   /*   5 */
    UsageFault_Handler,                 /*   6 */
    0,                                  /*   7 */
    0,                                  /*   8 */
    0,                                  /*   9 */
    0,                                  /*  10 */
    SVC_Handler,                        /*  11 */
    DebugMon_Handler,                   /*  12 */
    0,                                  /*  13 */
    PendSV_Handler,                     /*  14 */
    SysTick_Handler,                    /*  15 */

    /* Peripheral IRQs: index = 16 + IRQn */
    WWDG_IRQHandler,                    /*  16 */
    PVD_PVM_IRQHandler,                 /*  17 */
    TAMP_STAMP_IRQHandler,              /*  18 */
    RTC_WKUP_IRQHandler,                /*  19 */
    FLASH_IRQHandler,                   /*  20 */
    RCC_IRQHandler,                     /*  21 */
    EXTI0_IRQHandler,                   /*  22 */
    EXTI1_IRQHandler,                   /*  23 */
    EXTI2_IRQHandler,                   /*  24 */
    EXTI3_IRQHandler,                   /*  25 */
    EXTI4_IRQHandler,                   /*  26 */
    DMA1_Channel1_IRQHandler,           /*  27 */
    DMA1_Channel2_IRQHandler,           /*  28 */
    DMA1_Channel3_IRQHandler,           /*  29 */
    DMA1_Channel4_IRQHandler,           /*  30 */
    DMA1_Channel5_IRQHandler,           /*  31 */
    DMA1_Channel6_IRQHandler,           /*  32 */
    DMA1_Channel7_IRQHandler,           /*  33 */
    ADC1_2_IRQHandler,                  /*  34 */
    CAN1_TX_IRQHandler,                 /*  35 */
    CAN1_RX0_IRQHandler,                /*  36 */
    CAN1_RX1_IRQHandler,                /*  37 */
    CAN1_SCE_IRQHandler,                /*  38 */
    EXTI9_5_IRQHandler,                 /*  39 */
    TIM1_BRK_TIM15_IRQHandler,          /*  40 */
    TIM1_UP_TIM16_IRQHandler,           /*  41 */
    TIM1_TRG_COM_TIM17_IRQHandler,      /*  42 */
    TIM1_CC_IRQHandler,                 /*  43 */
    TIM2_IRQHandler,                    /*  44 */
    TIM3_IRQHandler,                    /*  45 */
    TIM4_IRQHandler,                    /*  46 */
    I2C1_EV_IRQHandler,                 /*  47 */
    I2C1_ER_IRQHandler,                 /*  48 */
    I2C2_EV_IRQHandler,                 /*  49 */
    I2C2_ER_IRQHandler,                 /*  50 */
    SPI1_IRQHandler,                    /*  51 */
    SPI2_IRQHandler,                    /*  52 */
    USART1_IRQHandler,                  /*  53 */
    USART2_IRQHandler,                  /*  54 */
    USART3_IRQHandler,                  /*  55 */
    EXTI15_10_IRQHandler,               /*  56 */
    RTC_Alarm_IRQHandler,               /*  57 */
    DFSDM1_FLT3_IRQHandler,             /*  58 */
    TIM8_BRK_IRQHandler,                /*  59 */
    TIM8_UP_IRQHandler,                 /*  60 */
    TIM8_TRG_COM_IRQHandler,            /*  61 */
    TIM8_CC_IRQHandler,                 /*  62 */
    ADC3_IRQHandler,                    /*  63 */
    FMC_IRQHandler,                     /*  64 */
    SDMMC1_IRQHandler,                  /*  65 */
    TIM5_IRQHandler,                    /*  66 */
    SPI3_IRQHandler,                    /*  67 */
    UART4_IRQHandler,                   /*  68 */
    UART5_IRQHandler,                   /*  69 */
    TIM6_DAC_IRQHandler,                /*  70 */
    TIM7_IRQHandler,                    /*  71 */
    DMA2_Channel1_IRQHandler,           /*  72 */
    DMA2_Channel2_IRQHandler,           /*  73 */
    DMA2_Channel3_IRQHandler,           /*  74 */
    DMA2_Channel4_IRQHandler,           /*  75 */
    DMA2_Channel5_IRQHandler,           /*  76 */
    DFSDM1_FLT0_IRQHandler,             /*  77 */
    DFSDM1_FLT1_IRQHandler,             /*  78 */
    DFSDM1_FLT2_IRQHandler,             /*  79 */
    COMP_IRQHandler,                    /*  80 */
    LPTIM1_IRQHandler,                  /*  81 */
    LPTIM2_IRQHandler,                  /*  82 */
    OTG_FS_IRQHandler,                  /*  83 */
    DMA2_Channel6_IRQHandler,           /*  84 */
    DMA2_Channel7_IRQHandler,           /*  85 */
    LPUART1_IRQHandler,                 /*  86 */
    QUADSPI_IRQHandler,                 /*  87 */
    I2C3_EV_IRQHandler,                 /*  88 */
    I2C3_ER_IRQHandler,                 /*  89 */
    SAI1_IRQHandler,                    /*  90 */
    SAI2_IRQHandler,                    /*  91 */
    SWPMI1_IRQHandler,                  /*  92 */
    TSC_IRQHandler,                     /*  93 */
    LCD_IRQHandler,                     /*  94 */
    0,                                  /*  95 */
    RNG_IRQHandler,                     /*  96 */
    FPU_IRQHandler,                     /*  97 */
};

void Reset_Handler(void)
{
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    while (dst < &_edata)
        *dst++ = *src++;

    dst = &_sbss;

    while (dst < &_ebss)
        *dst++ = 0;

    main();

    while (1);
}

void Default_Handler(void)
{
    while (1);
}