/*
 *  serial
 *
 *  Created on: Jan 3, 2021
 *      Author: Nima Mohammadi
 */

#ifndef INC_BSP_DRV_SPI_H_
#define INC_BSP_DRV_SPI_H_

#include "bsp/drv_base.h"
#include "Utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 */
void spiInit(void);

/**
 *
 */
void spiWriteData(char *data, uint16_t size);

/**
 *
 */
void spiReadData(uint16_t *data);

/**
 *
 */
void spiConvertToSerialBuff(char *in_buf);


#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_DRV_SPI_H_ */
