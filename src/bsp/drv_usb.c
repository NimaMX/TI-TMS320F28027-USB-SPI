/*
 * drv_usb.c
 *
 *  Created on: Jan 6, 2021
 *      Author: nima mohammadi
 */

#include "bsp/drv_usb.h"

SCI_Handle mUsbSci;

/**
 *
 */
result_t usbInit(void) {

    mUsbSci = SCI_init((void *) SCIA_BASE_ADDR, sizeof(SCI_Obj));

    //setup the gpio pins
    GPIO_setPullUp(mGpio, GPIO_Number_28, GPIO_PullUp_Enable);
    GPIO_setPullUp(mGpio, GPIO_Number_29, GPIO_PullUp_Disable);

    GPIO_setQualification(mGpio, GPIO_Number_28, GPIO_Qual_ASync);

    GPIO_setMode(mGpio, GPIO_Number_28, GPIO_28_Mode_SCIRXDA);
    GPIO_setMode(mGpio, GPIO_Number_29, GPIO_29_Mode_SCITXDA);

    // enable read/write -> NO Parity, 8-bit, async, autobuad,
    SCI_disableParity(mUsbSci);
    SCI_setNumStopBits(mUsbSci, SCI_NumStopBits_One);
    SCI_setCharLength(mUsbSci, SCI_CharLength_8_Bits);
    SCI_setBaudRate(mUsbSci, SCI_BaudRate_115_2_kBaud);

    // enable rx,tx and interrupts
    SCI_enableTx(mUsbSci);
    SCI_enableRx(mUsbSci);
    SCI_enableTxInt(mUsbSci);
    SCI_enableRxInt(mUsbSci);
    SCI_enable(mUsbSci);

    // enable recv fifo
    SCI_enableFifoEnh(mUsbSci);
    SCI_resetTxFifo(mUsbSci);
    SCI_clearTxFifoInt(mUsbSci);
    SCI_resetChannels(mUsbSci);
    SCI_setTxFifoIntLevel(mUsbSci, SCI_FifoLevel_Empty);
    SCI_resetRxFifo(mUsbSci);
    SCI_clearRxFifoInt(mUsbSci);
    SCI_setRxFifoIntLevel(mUsbSci, SCI_FifoLevel_4_Words);

    return RES_OK;
}

/**
 *
 */
result_t usbWriteData(char *data, uint16_t size) {

    uint16_t cnt;

    for(cnt = 0; cnt < size; cnt++) {

        while(SCI_getTxFifoStatus(mUsbSci) != SCI_FifoLevel_Empty);

        SCI_putDataBlocking(mUsbSci, data[cnt]);

    }

    return RES_OK;
}

/**
 *
 */
result_t usbReadData(uint16_t *data) {

    // check for incoming data on rx line
    while(SCI_getTxFifoStatus(mUsbSci) < SCI_FifoStatus_1_Word) {

    }

    // read characther
    *data = SCI_getData(mUsbSci);

    return RES_OK;
}
