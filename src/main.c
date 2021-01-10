/*
 * main.c
 */

#include "bsp/drv_base.h"
#include "bsp/drv_usb.h"
#include "bsp/drv_led.h"
#include "bsp/drv_spi.h"

void main()
{
    /** init base system */
    initWdog();
    initInternalClk();
    initFlash();
    initPerherialsReq();

    /** init interfaces and peripheral */
    ledInitGpio();
    usbInit();
    spiInit();

    enablePIE();

    ledRxUpdate(true);
    ledTxUpdate(true);
    ledWarningUpdate(true);
    ledErrorUpdate(true);

    bool state = false;
    for(;;) {

        if(state)
            usbWriteData("Turning Led On\r\n", 16);
        else
            usbWriteData("Turning Led Off\r\n", 17);

        ledRxUpdate(!state);
        ledTxUpdate(state);

        state = !state;
        DELAY_US(1000000L);
    }
}

