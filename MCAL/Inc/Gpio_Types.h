
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \file:  <Write File Name>
 *        \brief:  -
 *
 *      \details:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    PORTA = 0,
    PORTB = 1,
    PORTC = 2,
    PORTD = 3,
    PORTE = 4,
    PORTF = 5,
} Gpio_PortType;

typedef enum
{
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7
} Gpio_PinType;

typedef struct
{
    Gpio_PortType   port;
    Gpio_PinType    pin;
}Gpio_ChannelType;

typedef enum
{
    INPUT   = 0,
    OUTPUT  = 1
} Gpio_PinDirectionType;

typedef enum
{
    LOW = 0,
    HIGH
} Dio_PinLevelType;

typedef uint8 Dio_PortValueType;

typedef enum
{
    PIN_MODE_DIO = 0,
    PIN_MODE_EXT,
    PIN_MODE_ADC

    // TODO: add the rest of the modes from the datasheet
} Gpio_PinModeType;

typedef enum
{
    PULL_UP = 0,
    PULL_DOWN,
    OPEN_DRAIN
} Gpio_PinInternalAttachType;

typedef enum
{
    TWO_MA = 2,
    FOUR_MA = 4,
    EIGHT_MA = 8
} Gpio_PinOutputCurrentType;

typedef struct
{
    Gpio_ChannelType            channel;
    Gpio_PinModeType            pinMode;
    Dio_PinLevelType            pinValue;
    Gpio_PinDirectionType       pinDirection;
    Gpio_PinInternalAttachType  pinInternalAttach;
    Gpio_PinOutputCurrentType   pinOutputCurrent;
} Gpio_PinConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Types.h
 *********************************************************************************************************************/
