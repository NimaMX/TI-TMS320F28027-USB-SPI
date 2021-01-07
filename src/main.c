/*
 * main.c
 */


void main()
{
/*
    WDOG_Handle myWDog;
    myWDog = WDOG_init((void*) WDOG_BASE_ADDR, sizeof(WDOG_Obj));
    WDOG_disable(myWDog);

    CLK_Handle myClk;

    PLL_Handle myPll;

    myClk = CLK_init((void*) CLK_BASE_ADDR, sizeof(CLK_Obj));
    myPll = PLL_init((void*) PLL_BASE_ADDR, sizeof(PLL_Obj));

    CLK_setOscSrc(myClk, CLK_OscSrc_Internal);


    PLL_setup(myPll, PLL_Multiplier_12, PLL_DivideSelect_ClkIn_by_2);
// Selecting 60Mhz InternalClock

#ifdef _FLASH
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
#endif

    GPIO_Handle myGpio;
    myGpio = GPIO_init((void*) GPIO_BASE_ADDR, sizeof(GPIO_Obj));

    GPIO_setMode(myGpio, GPIO_Number_0, GPIO_0_Mode_GeneralPurpose);
    GPIO_setDirection(myGpio, GPIO_Number_0, GPIO_Direction_Output);

    GPIO_setMode(myGpio, GPIO_Number_1, GPIO_1_Mode_GeneralPurpose);
    GPIO_setDirection(myGpio, GPIO_Number_1, GPIO_Direction_Output);

    GPIO_setMode(myGpio, GPIO_Number_2, GPIO_2_Mode_GeneralPurpose);
    GPIO_setDirection(myGpio, GPIO_Number_2, GPIO_Direction_Output);

    GPIO_setMode(myGpio, GPIO_Number_3, GPIO_3_Mode_GeneralPurpose);
    GPIO_setDirection(myGpio, GPIO_Number_3, GPIO_Direction_Output);

    while (1) //This will run indefinitely
    {
        DELAY_US(1000000);

        GPIO_toggle(myGpio, GPIO_Number_0);
        GPIO_toggle(myGpio, GPIO_Number_1);
        GPIO_toggle(myGpio, GPIO_Number_2);
        GPIO_toggle(myGpio, GPIO_Number_3);
    }
*/

    while(1) {

    }
}

