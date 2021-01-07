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

/**
 *
 */
void initWdog(void)
{
    mWdog = WDOG_init((void*) WDOG_BASE_ADDR, sizeof(WDOG_Obj));
    WDOG_disable(mWdog);
}

/**
 *
 */
void initInternalClk(void)
{
    mClk = CLK_init((void*) CLK_BASE_ADDR, sizeof(CLK_Obj));
    mPll = PLL_init((void*) PLL_BASE_ADDR, sizeof(PLL_Obj));

    // use internal oscillator
    CLK_setOscSrc(mClk, CLK_OscSrc_Internal);

    // 60 Mhz
    PLL_setup(mPll, PLL_Multiplier_12, PLL_DivideSelect_ClkIn_by_2);

}

void initPerherialsReq(void) {
    mGpio = GPIO_init((void*) GPIO_BASE_ADDR, sizeof(GPIO_Obj));

    // enable usb-serial clock
    CLK_enableSciaClock((CLK_Obj*) mClk);

    // enable spi clock
    CLK_enableSpiaClock((CLK_Obj*) mClk);

}

void initFlash(void) {

    // copy just ram functions to ram from flash
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t) &RamfuncsLoadSize);
}
