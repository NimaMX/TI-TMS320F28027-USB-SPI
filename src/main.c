
#include "stdint.h"
#include "stdbool.h"

#include "DSP28x_Project.h"

#include "clk.h"
#include "pie.h"
#include "pll.h"

CLK_Handle mClk;
CPU_Handle mCpu;







/**
 * init base system
 */
void init_system(void) {


    // init handler
    //mClk = CLK_init((void *) CLK_BASE_ADDR, sizeof(CLK_Obj));
    //mCpu = CPU_init((void *) NULL, sizeof(CPU_Obj));
}

/**
 *
 */
int main(void)
{

    //init_system();

    return 0;
}
