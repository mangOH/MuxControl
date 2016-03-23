/**
 * @file gpioPin.c
 *
 * This is sample Legato GPIO app by using mangoh_gpioExpander.api on mangOH project.
 *
 * It includes functions to enable/disable IOT card LED1, LED2, LED3, and LED4.
 * Those IOT LEDs will be on or off one by one
 *
 * <HR>
 *
 * Copyright (C) Sierra Wireless, Inc. Use of this work is subject to license.
 */

/* Legato Framework */
#include "legato.h"
#include "interfaces.h"
#include "le_print.h"

//--------------------------------------------------------------------------------------------------
/**
 * Definition for connect service function pointer
 */
//--------------------------------------------------------------------------------------------------
typedef void (*ConnectServiceFunc_t)
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Help Message
 */
//--------------------------------------------------------------------------------------------------
static char* HelpMessage = "\
NAME:\n\
    mux - mangOH GPIO Mux Control tool\n\
\n\
SYNOPSIS:\n\
    mux help\n\
    \tExample: TI IoT Bluetooth module: IoT0 UART1, cmd:3 \n\
    \tExample: IoT Dust Network module: IoT1 UART1 On, cmd:4 \n\
    \tExample: IoT Dust Network module: IoT2 UART2 On, cmd:9 \n\
    \tExample: IoT module SPI loopback: IoT1 SPI, cmd:7 \n\
    \tExample: IoT MCP2515 CAN bus module: IoT1 SPI, cmd:7 \n\
    \tExample: IoT MCP2515 CAN bus module: IoT1 out of reset, cmd:18 \n\
    mux cmd number\n\
\n\
DESCRIPTION:\n\
    mux help\n\
      - Print this help message and exit\n\
    0.  exit this tool\n\
    1.  tool command list\n\
    2.  mangoh_muxCtrl_IotAllUart1Off\n\
    3.  mangoh_muxCtrl_Iot0Uart1On\n\
    4.  mangoh_muxCtrl_Iot1Uart1On\n\
    5.  mangoh_muxCtrl_IotAllSpiOff\n\
    6.  mangoh_muxCtrl_Iot0Spi1On\n\
    7.  mangoh_muxCtrl_Iot1Spi1On\n\
    8.  mangoh_muxCtrl_IotAllUart2Off\n\
    9.  mangoh_muxCtrl_Iot2Uart2On\n\
    10. mangoh_muxCtrl_Uart2DebugOn\n\
    11. mangoh_muxCtrl_PcmOff\n\
    12. mangoh_muxCtrl_PcmIot0On\n\
    13. mangoh_muxCtrl_PcmCodecOn\n\
    14. mangoh_muxCtrl_SdioSelUsdcard\n\
    15. mangoh_muxCtrl_SdioSelIot0\n\
    16. mangoh_muxCtrl_OnboardCodecSel\n\
    17. mangoh_muxCtrl_ModuleCodecSel\n\
    18. mangoh_muxCtrl_IoTSlot1Reset\n\
    19. mangoh_muxCtrl_IoTSlot0Reset\n\
    20. mangoh_muxCtrl_IoTSlot2Reset\n\
\n\
";


//--------------------------------------------------------------------------------------------------
/**
 * Print the help message to stdout
 */
//--------------------------------------------------------------------------------------------------
static void PrintHelp
(
    void
)
{
    puts(HelpMessage);
}

//--------------------------------------------------------------------------------------------------
/**
 * Thread used to recover from problems connecting to a service, probably because the service is
 * down.  It will timeout after 20 seconds, print an error message, and then exit.
 *
 * Once successfully connected to the service, this thread should be stopped.
 */
//--------------------------------------------------------------------------------------------------
static void* TimeoutThread
(
    void* contextPtr        ///< This should be string containing name of service
)
{
    char* serviceNamePtr = contextPtr;

    // This thread doesn't have to do anything else, at least for now, so just sleep.
    sleep(20);

    printf("Error: can't connect to service; is %s running?\n", serviceNamePtr);
    exit(EXIT_FAILURE);

    return NULL;
}

/**
 * Try calling the given function to connect to a service.  If can't connect to the service within
 * 20 seconds, then the program will exit.
 */
//--------------------------------------------------------------------------------------------------
static void TryConnect
(
    ConnectServiceFunc_t connectFuncPtr,    ///< Function to call to connect to service
    char* serviceNamePtr                    ///< String containing name of the service
)
{
    // Print out message before trying to connect to service to give user some kind of feedback
    printf("Connecting to service ...\n");
    fflush(stdout);

    // Use a separate thread for recovery.  It will be stopped once connected to the service.
    // Make the thread joinable, so we can be sure the thread is stopped before continuing.
    le_thread_Ref_t threadRef = le_thread_Create("timout thread", TimeoutThread, serviceNamePtr);
    le_thread_SetJoinable(threadRef);
    le_thread_Start(threadRef);

    // Try connecting to the service
    connectFuncPtr();

    // Connected to the service, so stop the timeout thread
    le_thread_Cancel(threadRef);
    le_thread_Join(threadRef, NULL);
}

COMPONENT_INIT
{
    int cmd;
    bool muxRunFlag = true;

    PrintHelp();

    TryConnect(mangoh_muxCtrl_ConnectService, "gpioMuxCtrlService");

    while(muxRunFlag)
    {
        printf("\nEnter the number for Mux Control function: \n");
        scanf("%d", &cmd);

        switch(cmd)
        {
            case 0:
                printf("Exit mux control tool\n");
                muxRunFlag = false;
                break;
            case 1:
                printf("Tool command list\n");
                PrintHelp();
                break;
            case 2:
                printf("%d: mangoh_muxCtrl_IotAllUart1Off\n", cmd);
                mangoh_muxCtrl_Iot0Uart1On();
                break;
            case 3:
                printf("%d: mangoh_muxCtrl_Iot0Uart1On\n", cmd);
                mangoh_muxCtrl_Iot0Uart1On();
                break;
            case 4:
                printf("%d: mangoh_muxCtrl_Iot1Uart1On\n", cmd);
                mangoh_muxCtrl_Iot1Uart1On();
                break;
            case 5:
                printf("%d: mangoh_muxCtrl_IotAllSpiOff\n", cmd);
                mangoh_muxCtrl_IotAllSpiOff();
                break;
            case 6:
                printf("%d: mangoh_muxCtrl_Iot0Spi1On\n", cmd);
                mangoh_muxCtrl_Iot0Spi1On();
                break;
            case 7:
                printf("%d: mangoh_muxCtrl_Iot1Spi1On\n", cmd);
                mangoh_muxCtrl_Iot1Spi1On();
                break;
            case 8:
                printf("%d: mangoh_muxCtrl_IotAllUart2Off\n", cmd);
                mangoh_muxCtrl_IotAllUart2Off();
                break;
            case 9:
                printf("%d: mangoh_muxCtrl_Iot2Uart2On\n", cmd);
                mangoh_muxCtrl_Iot2Uart2On();
                break;
            case 10:
                printf("%d: mangoh_muxCtrl_Uart2DebugOn\n", cmd);
                mangoh_muxCtrl_Uart2DebugOn();
                break;
            case 11:
                printf("%d: mangoh_muxCtrl_PcmOff\n", cmd);
                mangoh_muxCtrl_PcmOff();
                break;
            case 12:
                printf("%d: mangoh_muxCtrl_PcmIot0On\n", cmd);
                mangoh_muxCtrl_PcmIot0On();
                break;
            case 13:
                printf("%d: mangoh_muxCtrl_PcmCodecOn\n", cmd);
                mangoh_muxCtrl_PcmCodecOn();
                break;
            case 14:
                printf("%d: mangoh_muxCtrl_SdioSelUsdcard\n", cmd);
                mangoh_muxCtrl_SdioSelUsdcard();
                break;
            case 15:
                printf("%d: mangoh_muxCtrl_SdioSelIot0\n", cmd);
                mangoh_muxCtrl_SdioSelIot0();
                break;
            case 16:
                printf("%d: mangoh_muxCtrl_OnboardCodecSel\n", cmd);
                mangoh_muxCtrl_OnboardCodecSel();
                break;
            case 17:
                printf("%d: mangoh_muxCtrl_ModuleCodecSel\n", cmd);
                mangoh_muxCtrl_ModuleCodecSel();
                break;
            case 18:
                printf("%d: mangoh_muxCtrl_IoTSlot1Reset\n", cmd);
                mangoh_muxCtrl_IoTSlot1Reset();
                break;
            case 19:
                printf("%d: mangoh_muxCtrl_IoTSlot0Reset\n", cmd);
                mangoh_muxCtrl_IoTSlot0Reset();
                break;
            case 20:
                printf("%d: mangoh_muxCtrl_IoTSlot2Reset\n", cmd);
                mangoh_muxCtrl_IoTSlot2Reset();
                break;
            default:
                printf("Non Supported Mux Control command!\n\n");
                PrintHelp();
                break;
        }
    }
    exit(0);
}
