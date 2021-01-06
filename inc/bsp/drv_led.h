/*
 * drv_led.h
 *
 *  Created on: Jan 3, 2021
 *      Author: Nima Mohammadi
 */

#ifndef INC_BSP_DRV_LED_H_
#define INC_BSP_DRV_LED_H_

#include "Utils.h"

#include <DSP28x_Project.h>
#include <flash.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum DevLeds {

    LED_ERR,
    LED_WARN,
    LED_UART_TX,
    LED_UART_RX,

} device_led_t;

/**
 *
 */
result_t ledInitGpio(void);

/**
 *
 */
result_t ledOn(const DevLeds& dev_leds);

/**
 *
 */
result_t ledOff(const DevLeds& dev_leds);


#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_DRV_LED_H_ */
