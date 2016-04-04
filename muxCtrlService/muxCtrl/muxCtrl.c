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

// TODO: Should the functions in this API bother returning a result?  It seems like it is a
//       critical system error if you lose control over the GPIO expander.

/* Legato Framework */
#include "legato.h"
#include "interfaces.h"

//--------------------------------------------------------------------------------------------------
/**
 * Helper macro which initializes the given pin to output and issues a fatal error if unsuccessful
 */
//--------------------------------------------------------------------------------------------------
#define CONFIGURE_AS_OUTPUT(_gpioDefine_) \
    LE_FATAL_IF( \
        mangoh_gpioExpander_SetDirectionMode( \
            _gpioDefine_, MANGOH_GPIOEXPANDER_PIN_MODE_OUTPUT) != LE_OK, \
        "Could not configure pin %s as output", \
        STRINGIZE(_gpioDefine_))

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH All IOT UART1 OFF.
 *
 * - The signal UART_EXP1_ENn is set output as HIGH
 *
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllUart1Off
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to disable UART 1");
        return LE_FAULT;
    }

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
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot0Uart1On
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP1_IN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to select IoT slot 0 for UART 1");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to enable UART 1");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT1 UART1 ON.
 *
 * - The signal UART_EXP1_ENn is set output as LOW
 * - The signal UART_EXP1_IN  is set output as LOW
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot1Uart1On
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP1_IN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to select IoT slot 1 for UART 1");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to enable UART 1");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH All IOT SPI OFF.
 *
 * - The signal SPI_EXP1_ENn is set output as HIGH
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllSpiOff
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_SPI_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to disable SPI");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT0 SPI1 ON.
 *
 * - The signal SPI_EXP1_ENn is set output as LOW
 * - The signal SPI_EXP1_IN  is set output as HIGH
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot0Spi1On
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_SPI_EXP1_IN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to select IoT slot 0 for SPI");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_SPI_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to enable SPI");
        return LE_FAULT;
    }

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
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot1Spi1On
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_SPI_EXP1_IN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to select IoT slot 1 for SPI");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_SPI_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to enable SPI");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH All IOT UART2 OFF.
 *
 * - The signal UART_EXP2_ENn is set output as HIGH
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotAllUart2Off
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP2_ENN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to disable UART 2");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH IOT2 UART2 ON.
 *
 * - The signal UART_EXP2_ENn is set output as LOW
 * - The signal UART_EXP2_IN  is set output as HIGH
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Iot2Uart2On
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP2_IN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to select IoT slot 2 for UART 2");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP2_ENN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to enable UART 2");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH UART2 DEBUG ON.
 *
 * - The signal UART_EXP2_ENn is set output as LOW
 * - The signal UART_EXP2_IN  is set output as LOW
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_Uart2DebugOn
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP2_IN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to select debug for UART 2");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_UART_EXP2_ENN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to enable UART 2");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH SDIO SEL USDCARD.
 *
 * - The signal SDIO_SEL is set output as HIGH
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_SdioSelUsdcard
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_SDIO_SEL, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to select MicroSD slot for SDIO");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: mangOH SDIO SEL IOT0.
 *
 * - The signal SDIO_SEL is set output as LOW
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_SdioSelIot0
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_SDIO_SEL, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to select IoT slot 0 for SDIO");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Disable the audio path
 *
 * @return
 *      LE_OK on success or LE_FAULT on failure
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_AudioDisable
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to disable PCM");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_ANALOG_SELECT, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to select off-chip codec location");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Route audio via a codec installed in IoT slot 0
 *
 * @return
 *      LE_OK on success or LE_FAULT on failure
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_gpioExpander_AudioSelectIot0Codec
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_EXP1_SEL, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to select IoT slot 0 for PCM");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_ANALOG_SELECT, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to select off-chip codec location");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to enable PCM");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Route audio via the codec on the mangOH board
 *
 * @return
 *      LE_OK on success or LE_FAULT on failure
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_gpioExpander_AudioSelectOnboardCodec
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_EXP1_SEL, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to select onboard for PCM");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_ANALOG_SELECT, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to select off-chip codec location");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_LOW) != LE_OK)
    {
        LE_ERROR("Failed to enable PCM");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Route audio via the codec on the mangOH board
 *
 * @return
 *      LE_OK on success or LE_FAULT on failure
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_gpioExpander_AudioSelectOnboardCodec
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_EXP1_ENN, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to disable PCM");
        return LE_FAULT;
    }

    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_PCM_ANALOG_SELECT, MANGOH_GPIOEXPANDER_LEVEL_HIGH) != LE_OK)
    {
        LE_ERROR("Failed to select on-chip codec location");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: IOT0 module out of reset.
 *
 * - The signal GPIO Expander3 GPIO_IOT0_RESET is set output as HIGH
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot0Reset
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_GPIO_IOT0_RESET, MANGOH_GPIOEXPANDER_LEVEL_HIGH))
    {
        LE_ERROR("Failed to take IoT slot 0 out of reset");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: IOT1 module out of reset.
 *
 * - The signal GPIO Expander3 GPIO_IOT1_RESET(IO3) is set output as HIGH
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot1Reset
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_GPIO_IOT1_RESET, MANGOH_GPIOEXPANDER_LEVEL_HIGH))
    {
        LE_ERROR("Failed to take IoT slot 1 out of reset");
        return LE_FAULT;
    }

    return LE_OK;
}

//--------------------------------------------------------------------------------------------------
/**
 * Mux Control: IOT2 module out of reset.
 *
 * - The signal GPIO Expander3 GPIO_IOT2_RESET is set output as HIGH
 *
 * @return
 *      - LE_FAULT
 *      - LE_OK
 */
//--------------------------------------------------------------------------------------------------
le_result_t mangoh_muxCtrl_IotSlot2Reset
(
    void
)
{
    if (mangoh_gpioExpander_Output(
            MANGOH_GPIOEXPANDER_PIN_GPIO_IOT2_RESET, MANGOH_GPIOEXPANDER_LEVEL_HIGH))
    {
        LE_ERROR("Failed to take IoT slot 2 out of reset");
        return LE_FAULT;
    }

    return LE_OK;
}

COMPONENT_INIT
{
    LE_INFO(
        "This is sample mangOH Mux Control API service by using mangoh_gpioExpander.api and "
        "mangoh_muxCtrl.api\n");

    // Select the debug uart or else the rs232 port won't be usable
    mangoh_muxCtrl_Uart2DebugOn();

    // Configure all of the pins controlled by this service to outputs
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_UART_EXP1_ENN);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_UART_EXP1_IN);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_SPI_EXP1_ENN);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_SPI_EXP1_IN);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_UART_EXP2_ENN);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_UART_EXP2_IN);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_PCM_EXP1_ENN);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_PCM_EXP1_SEL);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_SDIO_SEL);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_PCM_ANALOG_SELECT);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_GPIO_IOT0_RESET);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_GPIO_IOT1_RESET);
    CONFIGURE_AS_OUTPUT(MANGOH_GPIOEXPANDER_PIN_GPIO_IOT2_RESET);

    return;
}
