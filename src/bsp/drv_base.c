/*
 * drv_base.c
 *
 *  Created on: Jan 7, 2021
 *      Author: nima
 */

#include "bsp/drv_base.h"

GPIO_Handle mGpio;
WDOG_Handle mWdog;
PLL_Handle mPll;
CLK_Handle mClk;
PIE_Handle mPie;
CPU_Handle mCpu;

void initWdog(void)
{
    mWdog = WDOG_init((void*) WDOG_BASE_ADDR, sizeof(WDOG_Obj));
    WDOG_disable(mWdog);
}

void initInternalClk(void)
{
    mClk = CLK_init((void*) CLK_BASE_ADDR, sizeof(CLK_Obj));
    mPll = PLL_init((void*) PLL_BASE_ADDR, sizeof(PLL_Obj));
    mCpu = CPU_init((void*) NULL, sizeof(CPU_Obj));
    mPie = PIE_init((void*) PIE_BASE_ADDR, sizeof(PIE_Obj));

    CLK_enableAdcClock(mClk);
    (*Device_cal )();
    CLK_setOscSrc(mClk, CLK_OscSrc_Internal);

    // 60 Mhz
    PLL_setup(mPll, PLL_Multiplier_12, PLL_DivideSelect_ClkIn_by_2);

    PIE_disable(mPie);
    PIE_disableAllInts(mPie);
    CPU_disableGlobalInts(mCpu);
    CPU_clearIntFlags(mCpu);
}

void initPerherialsReq(void)
{
    mGpio = GPIO_init((void*) GPIO_BASE_ADDR, sizeof(GPIO_Obj));

    CLK_enableSciaClock((CLK_Obj*) mClk);
    CLK_enableSpiaClock((CLK_Obj*) mClk);
}

void initFlash(void)
{
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t) &RamfuncsLoadSize);
}

void enablePIE(void)
{
    PIE_setDebugIntVectorTable(mPie);
    PIE_enable(mPie);
}
