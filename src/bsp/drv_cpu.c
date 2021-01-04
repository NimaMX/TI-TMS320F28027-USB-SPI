/*
 * drv_cpu.c
 *
 *  Created on: Jan 4, 2021
 *      Author: Nima Mohammadi
 */

#include "inc/bsp/drv_cpu.h"

FLASH_Handle mFlash = NULL;
CLK_Handle mClk = NULL;
PIE_Handle mHandle = NULL;
CPU_Handle mCpu = NULL;
PLL_Handle mPLLClk = NULL;
WDOG_Handle mWdog = NULL;

extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadSize;
extern Uint16 RamfuncsRunStart;

result_t initDsp(void) {



    return RES_OK;
}

result_t initDspFlash()
{
    if ((mFlash = FLASH_init((void*) FLASH_BASE_ADDR, sizeof(FLASH_Obj))) == NULL) {
        return RES_NULL_OBJ;
    }

    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t) &RamfuncsLoadSize);
    FLASH_setup(mFlash);

    return RES_OK;
}


result_t setDspState(const FLASH_PowerMode_e state) {

    if(mFlash == NULL) {
        return RES_NULL_OBJ;
    }

    FLASH_setPowerMode(mFlash, state);

    return RES_OK;
}
