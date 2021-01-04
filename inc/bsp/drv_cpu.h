/*
 * drv_cpu.h
 *
 *  Created on: Jan 4, 2021
 *      Author: Nima Mohammadi
 */

#ifndef INC_BSP_DRV_CPU_H_
#define INC_BSP_DRV_CPU_H_

#include <DSP28x_Project.h>
#include <flash.h>
#include <clk.h>
#include <pie.h>
#include <pll.h>

#include "inc/Utils.h"

#define PWM1_INT_ENABLE  1
#define PWM2_INT_ENABLE  1
#define PWM3_INT_ENABLE  1

#define PWM1_TIMER_TBPRD   0x1FFF
#define PWM2_TIMER_TBPRD   0x1FFF
#define PWM3_TIMER_TBPRD   0x1FFF

#ifdef __cplusplus
extern "C" {
#endif

result_t initDspFlash(void);

result_t setDspState(const FLASH_PowerMode_e state);

result_t init_cpu_comp(void);

result_t init_timers(void);


#ifdef __cplusplus
}
#endif


#endif /* INC_BSP_DRV_CPU_H_ */
