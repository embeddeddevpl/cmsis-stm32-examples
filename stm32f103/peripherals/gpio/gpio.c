/**
 * @file    gpio.c
 * @author  Łukasz Łaguna
 * @brief   GPIO driver.
 *
 * @details The functions are used to configure the GPIO in the STM32F103
 * microcontroller.
 */

#include "gpio.h"

void gpio_pin_mode(GPIO_TypeDef * gpio, uint8_t pin, gpio_mode_t mode)
{
    pin *= 4;

    if (pin < 32)
    {
        gpio->CRL &= ~((uint32_t)(0x0f << pin));
        gpio->CRL |= (uint32_t)(mode << pin);
    }
    else
    {
        pin -= 32;
        gpio->CRH &= ~((uint32_t)(0x0f << pin));
        gpio->CRH |= (uint32_t)(mode << pin);
    }
}

void gpio_pin_pupd(GPIO_TypeDef * gpio, uint8_t pin, gpio_pupd_t pupd)
{
    if (pupd)
    {
        gpio->ODR |= (uint32_t)(1<<pin);
    }
    else
    {
        gpio->ODR &= ~(uint32_t)(1<<pin);
    }
}

void gpio_init(void)
{
    /* Enable clock for GPIO ports */
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;

    /* Led */
    gpio_pin_mode(GPIOA, 5, gpio_mode_output_PP_10MHz);

    /* Button */
    gpio_pin_mode(GPIOA, 9, gpio_mode_input_pupd);
    gpio_pin_pupd(GPIOA, 9, gpio_pupd_pd);

}