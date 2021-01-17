/*
 * drv_led.h
 *
 *  Created on: Jan 3, 2021
 *      Author: Nima Mohammadi
 */

#ifndef INC_DRV_DRV_LED_H_
#define INC_DRV_DRV_LED_H_

#include <drv/drv_base.h>
#include "Utils.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 */
void ledInitGpio(void);

/**
 *
 */
void ledErrorUpdate(bool state);

/**
 *
 */
void ledWarningUpdate(bool state);

/**
 *
 */
void ledRxUpdate(bool state);

/**
 *
 */
void ledTxUpdate(bool state);


#ifdef __cplusplus
}
#endif

#endif /* INC_DRV_DRV_LED_H_ */
