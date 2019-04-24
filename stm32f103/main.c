/**
 * @file    main.c
 * @author  Łukasz Łaguna
 * @brief   Main file
 */

#include "stm32f10x.h"
#include "gpio/gpio.h"

int main(void)
{
    gpio_init();

    SysTick_Config(8000000); //TODO: write function with more options

    while(1)
    {
        if( !(GPIOA->IDR & (uint32_t)(1<<9)) ) GPIOA->BSRR = GPIO_BSRR_BS5;
        else GPIOA->BSRR = GPIO_BSRR_BR5;
    }

    return 0;
}

void SysTick_Handler(void) {
//    GPIOA->ODR ^= 1<<5;
}