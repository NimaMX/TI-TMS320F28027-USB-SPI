/*
 * main.c
 */

#include "bsp/drv_base.h"
#include "bsp/drv_usb.h"
#include "bsp/drv_led.h"

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

    //
    ledRxUpdate(true);
    ledTxUpdate(true);
    ledWarningUpdate(true);
    ledErrorUpdate(true);

    for(;;) {

        //usbWriteData("Turning Led On\r\n", 16);
        ledRxUpdate(true);
        ledTxUpdate(false);

        DELAY_US(1000000L);

        //usbWriteData("Turning Led Off\r\n", 17);
        ledRxUpdate(false);
        ledTxUpdate(true);

        DELAY_US(1000000L);
    }
}

