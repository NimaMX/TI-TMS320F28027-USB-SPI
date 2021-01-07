/*
 * drv_base.c
 *
 *  Created on: Jan 7, 2021
 *      Author: nima
 */

#include "bsp/drv_base.h"

CPU_Handle mCpu;
PLL_Handle mPll;
WDOG_Handle mWdog;
CLK_Handle mClk;
FLASH_Handle mFlash;
PIE_Handle mPie;
SCI_Handle mSci;
GPIO_Handle mGpio;

void initDrvObj(void) {
    mCpu = CPU_init((void *) NULL , sizeof(CPU_Obj));
    mPll = PLL_init((void *) PLL_BASE_ADDR , sizeof(PLL_Obj));
    mWdog = WDOG_init((void *) WDOG_BASE_ADDR , sizeof(WDOG_Obj));
    mClk = CLK_init((void *) CLK_BASE_ADDR , sizeof(CLK_Obj));
    mFlash = FLASH_init((void *) FLASH_BASE_ADDR , sizeof(FLASH_Obj));
    mPie = PIE_init((void *) PIE_BASE_ADDR, sizeof(PIE_Obj));
    mSci = SCI_init((void *) SCIA_BASE_ADDR, sizeof(SCI_Obj));
    mGpio = GPIO_init((void *) GPIO_BASE_ADDR, sizeof(GPIO_Obj));
}
