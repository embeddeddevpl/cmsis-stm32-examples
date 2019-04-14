/**
 * @file    main.c
 * @author  Łukasz Łaguna
 * @brief   Main file
 */

#include "stm32f10x.h"
#include "gpio/gpio.h"

/**
 * Initialization of GPIO for LED and Button.
 */
static void gpio_init(void);

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

static void gpio_init(void)
{
    /* Enable clock for GPIO ports */
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;

    /* Led */
    gpio_pin_mode(GPIOA, 5, gpio_mode_output_PP_10MHz);

    /* Button */
    gpio_pin_mode(GPIOA, 9, gpio_mode_input_pupd);
    gpio_pin_pupd(GPIOA, 9, gpio_pupd_pd);

}