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

    while(1)
    {
        if( !(GPIOA->IDR & (uint32_t)(1<<9)) ) GPIOA->BSRR = GPIO_BSRR_BS5;
        else GPIOA->BSRR = GPIO_BSRR_BR5;
    }

    return 0;
}