/*
 * drv_usb.c
 *
 *  Created on: Jan 6, 2021
 *      Author: nima
 */

#include "bsp/drv_usb.h"

/**
 *
 */
result_t usbInit(void) {

    // enable SCI A clock
    CLK_enableSciaClock((CLK_Obj *) mClk);

    //setup the gpio pins
    GPIO_setPullUp(mGpio, GPIO_Number_28, GPIO_PullUp_Enable);
    GPIO_setPullUp(mGpio, GPIO_Number_29, GPIO_PullUp_Disable);

    GPIO_setQualification(mGpio, GPIO_Number_28, GPIO_Qual_ASync);

    GPIO_setMode(mGpio, GPIO_Number_28, GPIO_28_Mode_SCIRXDA);
    GPIO_setMode(mGpio, GPIO_Number_29, GPIO_29_Mode_SCITXDA);

    // enable read/write -> NO Parity, 8-bit, async, autobuad,
    SCI_disableParity(mSci);
    SCI_setNumStopBits(mSci, SCI_NumStopBits_One);
    SCI_setCharLength(mSci, SCI_CharLength_8_Bits);
    SCI_setBaudRate(mSci, SCI_BaudRate_115_2_kBaud);

    // enable rx,tx and interrupts
    SCI_enableTx(mSci);
    SCI_enableRx(mSci);
    SCI_enableTxInt(mSci);
    SCI_enableRxInt(mSci);
    SCI_enable(mSci);

    // enable recv fifo
    SCI_enableFifoEnh(mSci);
    SCI_resetTxFifo(mSci);
    SCI_clearTxFifoInt(mSci);
    SCI_resetChannels(mSci);
    SCI_setTxFifoIntLevel(mSci, SCI_FifoLevel_Empty);
    SCI_resetRxFifo(mSci);
    SCI_clearRxFifoInt(mSci);
    SCI_setRxFifoIntLevel(mSci, SCI_FifoLevel_4_Words);

    return RES_OK;
}

/**
 *
 */
result_t usbWriteData(char *data) {

    int i = 0;
    while(data[i] != '\0') {

        while(SCI_getTxFifoStatus(mSci) != SCI_FifoLevel_Empty);

        SCI_putDataBlocking(mSci, data[i]);

    }

    return RES_OK;
}

/**
 *
 */
result_t usbReadData(uint16_t *data) {

    // check for incoming data on rx line
    while(SCI_getTxFifoStatus(mSci) < SCI_FifoStatus_1_Word) {

    }

    // read characther
    *data = SCI_getData(mSci);

    return RES_OK;
}
