/*
 *  serial.c
 *
 *  Created on: Jan 3, 2021
 *      Author: Nima Mohammadi
 */

#include "bsp/drv_spi.h"

SPI_Handle mSpi;

void spiInit(void) {

    mSpi = SPI_init((void *) SPIA_BASE_ADDR, sizeof(SPI_Obj));

    SPI_setMode(mSpi, SPI_Mode_Master);
    SPI_enableTx(mSpi);
    SPI_setBaudRate(mSpi, SPI_BaudRate_500_KBaud);
    SPI_setCharLength(mSpi, SPI_CharLength_8_Bits);
    SPI_setClkPolarity(mSpi, SPI_ClkPolarity_OutputRisingEdge_InputFallingEdge); // doub-chk
    SPI_setClkPhase(mSpi, SPI_ClkPhase_Delayed);

    SPI_enable(mSpi);
    SPI_setPriority(mSpi, priority);

}

result_t spiWriteData(char *data, uint16_t size) {

}

result_t spiReadData(uint16_t *data) {

}
