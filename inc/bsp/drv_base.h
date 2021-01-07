/*
 * drv_base.h
 *
 *  Created on: Jan 7, 2021
 *      Author: nima
 */

#ifndef INC_BSP_DRV_BASE_H_
#define INC_BSP_DRV_BASE_H_

#include "DSP28x_Project.h"

#include "gpio.h"
#include "cpu.h"
#include "clk.h"
#include "pie.h"
#include "sci.h"
#include "flash.h"
#include "pll.h"
#include "wdog.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 */
extern CPU_Handle mCpu;
extern PLL_Handle mPll;
extern WDOG_Handle mWdog;
extern CLK_Handle mClk;
extern FLASH_Handle mFlash;
extern PIE_Handle mPie;
extern SCI_Handle mSci;
extern GPIO_Handle mGpio;

/**
 *
 */
void initDrvObj(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_DRV_BASE_H_ */
