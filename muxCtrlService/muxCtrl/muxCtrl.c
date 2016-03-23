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

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH All IOT UART1 OFF.
 *
 * - The signal UART_EXP1_ENn is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllUart1Off
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT0 UART1 ON.
 *
 * - The signal UART_EXP1_ENn is set output as LOW
 * - The signal UART_EXP1_IN  is set output as HIGH
 *
 *
 * Example usage: IoT0 slot UART1 for IoT TI bluetooth module
 * 
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot0Uart1On
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    LE_INFO("****** muxCtrl Iot0 UART1 On \n");
    LE_INFO("****** muxCtrl Iot0 UART1 On: Exp1 Enn low \n");
    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    LE_INFO("****** muxCtrl Iot0 UART1 On: Exp1 In high \n");
    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_IN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_IN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT1 UART1 ON.
 *
 * - The signal UART_EXP1_ENn is set output as LOW
 * - The signal UART_EXP1_IN  is set output as LOW
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot1Uart1On
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_IN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP1_IN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH All IOT SPI OFF.
 *
 * - The signal SPI_EXP1_ENn is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllSpiOff
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT0 SPI1 ON.
 *
 * - The signal SPI_EXP1_ENn is set output as LOW
 * - The signal SPI_EXP1_IN  is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot0Spi1On
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_IN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_IN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT1 SPI1 ON.
 *
 * - The signal SPI_EXP1_ENn is set output as LOW
 * - The signal SPI_EXP1_IN  is set output as LOW
 *
 * Example usage: IoT1 slot SPI for IoT CAN bus module
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot1Spi1On
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_IN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_SPI_EXP1_IN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH All IOT UART2 OFF.
 *
 * - The signal UART_EXP2_ENn is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllUart2Off
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_UART_EXP2_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_UART_EXP2_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT2 UART2 ON.
 *
 * - The signal UART_EXP2_ENn is set output as LOW
 * - The signal UART_EXP2_IN  is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot2Uart2On
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_UART_EXP2_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_UART_EXP2_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP2_IN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP2_IN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH UART2 DEBUG ON.
 *
 * - The signal UART_EXP2_ENn is set output as LOW
 * - The signal UART_EXP2_IN  is set output as LOW
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Uart2DebugOn
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_UART_EXP2_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_UART_EXP2_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP2_IN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_UART_EXP2_IN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH PCM OFF.
 *
 * - The signal PCM_EXP1_ENn is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_PcmOff
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH PCM IOT0 ON.
 *
 * - The signal PCM_EXP1_ENn is set output as LOW
 * - The signal PCM_EXP1_SEL is set output as LOW
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_PcmIot0On
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_SEL);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_SEL);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH PCM CODEC ON.
 *
 * - The signal PCM_EXP1_ENn is set output as LOW
 * - The signal PCM_EXP1_SEL is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_PcmCodecOn
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_ENN);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_ENN);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_SEL);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_PCM_EXP1_SEL);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH SDIO SEL USDCARD.
 *
 * - The signal SDIO_SEL is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_SdioSelUsdcard
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_SDIO_SEL);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_SDIO_SEL);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH SDIO SEL IOT0.
 *
 * - The signal SDIO_SEL is set output as LOW
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_SdioSelIot0
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_SDIO_SEL);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_SDIO_SEL);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH ONBOARD CODEC SEL.
 *
 * - The signal PCM_ANALOG_SELECT is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_OnboardCodecSel
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_PCM_ANALOG_SELECT);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_PCM_ANALOG_SELECT);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH MODULE CODEC SEL.
 *
 * - The signal PCM_ANALOG_SELECT is set output as LOW
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_ModuleCodecSel
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    gpioRef = mangoh_gpioExpander_Request(1, MANGOH_GPIOEXPANDER_EXP1_PIN_PCM_ANALOG_SELECT);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:1 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP1_PIN_PCM_ANALOG_SELECT);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_LOW);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: IOT0 module out of reset.
 *
 * - The signal GPIO Expander3 GPIO_IOT0_RESET is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot0Reset
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    LE_INFO("****** muxCtrl Iot0 Reset \n");
    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_GPIO_IOT0_RESET);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_GPIO_IOT0_RESET);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: IOT1 module out of reset.
 *
 * - The signal GPIO Expander3 GPIO_IOT1_RESET(IO3) is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot1Reset
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    LE_INFO("****** muxCtrl Iot1 Reset \n");
    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_GPIO_IOT1_RESET);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_GPIO_IOT1_RESET);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: IOT2 module out of reset.
 *
 * - The signal GPIO Expander3 GPIO_IOT2_RESET is set output as HIGH
 *
 *
 * @return LE_FAULT       Function failed.
 * @return LE_OK          Function succeeded.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot2Reset
(
    void
)
{
    mangoh_gpioExpander_GpioRef_t gpioRef;

    LE_INFO("****** muxCtrl Iot1 Reset \n");
    gpioRef = mangoh_gpioExpander_Request(3, MANGOH_GPIOEXPANDER_EXP3_PIN_GPIO_IOT2_RESET);
    if (gpioRef == NULL)
    {
        LE_ERROR("Gpio Expander request module:3 gpio:%d failed\n", MANGOH_GPIOEXPANDER_EXP3_PIN_GPIO_IOT2_RESET);
        return LE_FAULT;
    }
    mangoh_gpioExpander_SetDirectionMode(gpioRef, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT);
    mangoh_gpioExpander_Output(gpioRef, MANGOH_GPIOEXPANDER_ACTIVE_TYPE_HIGH);
    mangoh_gpioExpander_Release(gpioRef);
    
    return LE_OK;
}

COMPONENT_INIT
{
    LE_INFO("This is sample mangOH Mux Control API service by using mangoh_gpioExpander.api and mangoh_muxCtrl.api\n");

    return;
}
