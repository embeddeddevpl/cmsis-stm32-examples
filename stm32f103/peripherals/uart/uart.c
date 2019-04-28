/**
 * @file    uart.c
 * @author  Łukasz Łaguna
 * @brief   UART driver.
 *
 * @details Simple UART library for STM32F103 microcontroller.
 */

#include "stm32f10x.h"

#include "uart/uart.h"
#include "gpio/gpio.h"

void uart_init(void)
{
    /* Enable clocks */
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    /* UART RX */
    gpio_pin_mode(GPIOA, 3, gpio_mode_input_floating);

    /* UART TX */
    gpio_pin_mode(GPIOA, 2, gpio_mode_alternate_PP_50MHz);

    /* UART Configuration */
    USART2->BRR |= 8000000/115200;
    USART2->CR1 |= USART_CR1_RXNEIE | USART_CR1_RE | USART_CR1_TE | USART_CR1_UE;

    NVIC_EnableIRQ(USART2_IRQn);

}

void USART2_IRQHandler(void) {

    if ( USART2->SR & USART_SR_RXNE) {

        USART2->SR &= ~USART_SR_RXNE;
        uint16_t tmp = USART2->DR;
        if (tmp < 123 && tmp > 96) USART2->DR = tmp - 32;
        else USART2->DR = tmp;

    }

}