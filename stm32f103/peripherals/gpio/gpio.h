/**
 * @file    gpio.h
 * @author  Łukasz Łaguna
 * @brief   GPIO driver.
 *
 * @details The functions are used to configure the GPIO in the STM32F103
 * microcontroller.
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f10x.h"

/**
 * Possible modes of GPIO pin
 */
typedef enum {
    gpio_mode_output_PP_2MHz = 2,       /**< Push-Pull 2MHz */
    gpio_mode_output_PP_10MHz = 1,      /**< Push-Pull 10MHz */
    gpio_mode_output_PP_50MHz = 3,      /**< Push-Pull 50MHz */
    gpio_mode_output_OD_2MHz = 6,       /**< Open-Drain 2MHz */
    gpio_mode_output_OD_10MHz = 5,      /**< Open-Drain 10MHz */
    gpio_mode_output_OD_50MHz = 7,      /**< Open-Drain 50MHz */
    gpio_mode_alternate_PP_2MHz = 10,   /**< Alternate Push-Pull 2MHz */
    gpio_mode_alternate_PP_10MHz = 9,   /**< Alternate Push-Pull 10MHz */
    gpio_mode_alternate_PP_50MHz = 11,  /**< Alternate Push-Pull 50MHz */
    gpio_mode_alternate_OD_2MHz = 14,   /**< Alternate Open-Drain 2MHz */
    gpio_mode_alternate_OD_10MHz = 13,  /**< Alternate Open-Drain 10MHz */ 
    gpio_mode_alternate_OD_50MHz = 15,  /**< Alternate Open-Drain 50MHz */
    gpio_mode_input_analog = 0,         /**< Analog input */
    gpio_mode_input_floating = 4,       /**< Floating input (Hi-Z) */
    gpio_mode_input_pupd = 8            /**< Digital input with pull-up/down */
} gpio_mode_t;

/**
 * Possible pulling resistor configurations
 */
typedef enum {
    gpio_pupd_pu = 1,   /**< Pull-Up */
    gpio_pupd_pd = 0    /**< Pull-Down */
} gpio_pupd_t;

/**
 * Initialize pins for standard I/O use.
 */
void gpio_init(void);

/**
 * Configure mode of GPIO pin.
 *
 * @param gpio      Port of configured GPIO pin.
 * @param pin       Number of configured pin.
 * @param mode      Mode of configured pin.
 */
void gpio_pin_mode(GPIO_TypeDef * gpio, uint8_t pin, gpio_mode_t mode);

/**
 * Configure pulling resistor.
 *
 * @param gpio      Port of configured GPIO pin.
 * @param pin       Number of configured pin.
 * @param mode      Pulling mode of configured pin.
 */
void gpio_pin_pupd(GPIO_TypeDef * gpio, uint8_t pin, gpio_pupd_t pupd);

#endif /* GPIO_H_ */