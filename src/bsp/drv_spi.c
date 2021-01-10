/*
 *  serial.c
 *
 *  Created on: Jan 3, 2021
 *      Author: Nima Mohammadi
 */

#include "bsp/drv_spi.h"

SPI_Handle mSpi;

char buf[99]={"Test Send data with spi to Computer serial!abcdefghijklmnopqrstuvw ABCDEFGHIJKLMNOPQRSTUVW \n \r"};
uint8_t out_buf[100];
unsigned char cnt = 200;

void spiInit(void) {

    mSpi = SPI_init((void *) SPIA_BASE_ADDR, sizeof(SPI_Obj));

    /** setup gpio */
    GPIO_setPullUp(mGpio, GPIO_Number_16, GPIO_PullUp_Enable);
    GPIO_setPullUp(mGpio, GPIO_Number_17, GPIO_PullUp_Enable);
    GPIO_setPullUp(mGpio, GPIO_Number_18, GPIO_PullUp_Enable);
    GPIO_setPullUp(mGpio, GPIO_Number_19, GPIO_PullUp_Enable);

    GPIO_setQualification(mGpio, GPIO_Number_16, GPIO_Qual_ASync);
    GPIO_setQualification(mGpio, GPIO_Number_17, GPIO_Qual_ASync);
    GPIO_setQualification(mGpio, GPIO_Number_18, GPIO_Qual_ASync);
    GPIO_setQualification(mGpio, GPIO_Number_19, GPIO_Qual_ASync);

    GPIO_setMode(mGpio, GPIO_Number_16, GPIO_16_Mode_SPISIMOA);
    GPIO_setMode(mGpio, GPIO_Number_17, GPIO_17_Mode_SPISOMIA);
    GPIO_setMode(mGpio, GPIO_Number_18, GPIO_18_Mode_SPICLKA);
    GPIO_setMode(mGpio, GPIO_Number_19, GPIO_19_Mode_SPISTEA_NOT);

    // configure spi-a registers
    SPI_setMode(mSpi, SPI_Mode_Master);
    SPI_enableTx(mSpi);
    SPI_setBaudRate(mSpi, SPI_BaudRate_500_KBaud);
    SPI_setCharLength(mSpi, SPI_CharLength_8_Bits);
    SPI_setClkPolarity(mSpi, SPI_ClkPolarity_OutputRisingEdge_InputFallingEdge); // doub-chk
    SPI_setClkPhase(mSpi, SPI_ClkPhase_Delayed);
    SPI_enable(mSpi);
    SPI_setPriority(mSpi, SPI_Priority_FreeRun);

    // init fifo registers
    SPI_enableChannels(mSpi);
    SPI_enableFifoEnh(mSpi);
    SPI_resetTxFifo(mSpi);
    SPI_clearTxFifoInt(mSpi);
    SPI_resetRxFifo(mSpi);
    SPI_clearRxFifoInt(mSpi);
    SPI_setRxFifoIntLevel(mSpi, SPI_FifoLevel_4_Words);
}
