/*
 * drv_led.c
 *
 *  Created on: Jan 7, 2021
 *      Author: nima mohammadi
 */

#include <drv/drv_led.h>

void ledInitGpio(void) {

    // led error
    GPIO_setMode(mGpio, GPIO_Number_0, GPIO_0_Mode_GeneralPurpose);
    GPIO_setDirection(mGpio, GPIO_Number_0, GPIO_Direction_Output);

    // led  warn
    GPIO_setMode(mGpio, GPIO_Number_1, GPIO_1_Mode_GeneralPurpose);
    GPIO_setDirection(mGpio, GPIO_Number_1, GPIO_Direction_Output);

    // led rx
    GPIO_setMode(mGpio, GPIO_Number_2, GPIO_2_Mode_GeneralPurpose);
    GPIO_setDirection(mGpio, GPIO_Number_2, GPIO_Direction_Output);

    // led tx
    GPIO_setMode(mGpio, GPIO_Number_3, GPIO_3_Mode_GeneralPurpose);
    GPIO_setDirection(mGpio, GPIO_Number_3, GPIO_Direction_Output);
}

void ledErrorUpdate(bool state) {

    if(state)
        GPIO_setHigh(mGpio, GPIO_Number_0);
    else
        GPIO_setLow(mGpio, GPIO_Number_0);
}

void ledWarningUpdate(bool state) {

    if(state)
        GPIO_setHigh(mGpio, GPIO_Number_1);
    else
        GPIO_setLow(mGpio, GPIO_Number_1);
}

void ledRxUpdate(bool state) {

    if(state)
        GPIO_setHigh(mGpio, GPIO_Number_2);
    else
        GPIO_setLow(mGpio, GPIO_Number_2);
}

void ledTxUpdate(bool state) {

    if(state)
        GPIO_setHigh(mGpio, GPIO_Number_3);
    else
        GPIO_setLow(mGpio, GPIO_Number_3);
}
