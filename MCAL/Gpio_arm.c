/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpio_arm.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpio_arm.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Gpio_PortInit(const Gpio_PinConfigType* configPtr)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Description                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Gpio_PortInit(const Gpio_PinConfigType* configPtr)
{
    //enable clock to the port
    WRITE_BIT_BB(RCGCGPIO_ADDR,configPtr[0].channel.port,STD_HIGH);
    uint8 i;
    for(i = 0 ; i < PORTF_CONFIG_ARR_SIZE ; i++)
    {
        
        //Pin direction for each pin in the port
        WRITE_BIT_BB(GPIODIR_ADDR(GPIO_PORTF),configPtr[i].channel.pin,configPtr[i].pinDirection);

        //Drive select
        switch(configPtr[i].pinOutputCurrent)
        {
            case TWO_MA:    WRITE_BIT_BB(GPIODR2R_ADDR(GPIO_PORTF),configPtr[i].channel.pin,STD_HIGH);  break;
            case FOUR_MA:   WRITE_BIT_BB(GPIODR4R_ADDR(GPIO_PORTF),configPtr[i].channel.pin,STD_HIGH);  break;
            case EIGHT_MA:  WRITE_BIT_BB(GPIODR8R_ADDR(GPIO_PORTF),configPtr[i].channel.pin,STD_HIGH);  break;
        }

        //Pull-up, pull-down or open drain
        switch (configPtr[i].pinInternalAttach)
        {
            case PULL_UP:       WRITE_BIT_BB(GPIOPUR_ADDR(GPIO_PORTF),configPtr[i].channel.pin,STD_HIGH);   break;
            case OPEN_DRAIN:    WRITE_BIT_BB(GPIOODR_ADDR(GPIO_PORTF),configPtr[i].channel.pin,STD_HIGH);   break;
            case PULL_DOWN:     WRITE_BIT_BB(GPIOPDR_ADDR(GPIO_PORTF),configPtr[i].channel.pin,STD_HIGH);   break;
            default:            WRITE_BIT_BB(GPIOPDR_ADDR(GPIO_PORTF),configPtr[i].channel.pin,STD_HIGH);   break;
        }

        //GPIODEN -> 1
        WRITE_BIT_BB(GPIODEN_ADDR(GPIO_PORTF),configPtr[i].channel.pin,STD_HIGH);

        //TODO pin mode
    }

	
}



/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelId)
* \Description     : Read a pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType channelId                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_PinLevelType Dio_ReadChannel(Gpio_ChannelType channelId)
{
    return (Dio_PinLevelType)READ_BIT_BB(GPIODATA_ADDR(channelId.port),channelId.pin);
}


/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType channelId, Dio_LevelType Level)
* \Description     : writes to a pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType channelId, Dio_LevelType Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Gpio_ChannelType channelId, Dio_PinLevelType level)
{
    
    WRITE_BIT_BB(GPIODATA_ADDR(channelId.port),channelId.pin,level);
}

/******************************************************************************
* \Syntax          : Dio_PortValueType Dio_ReadPort(Gpio_PortType portId)
* \Description     : Read a port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpio_PortType portId                    
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortValueType
*******************************************************************************/
Dio_PortValueType Dio_ReadPort(Gpio_PortType portId)
{
    return (Dio_PortValueType) GPIODATA(portId);
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType channelId, Dio_LevelType Level)
* \Description     : writes to a pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpio_PortType PortId, Dio_PortValueType Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Gpio_PortType portId, Dio_PortValueType level)
{
    GPIODATA(portId) = level;
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType channelId)
* \Description     : toggle a pin                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-reentrant                                             
* \Parameters (in) : Dio_ChannelType channelId                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_PinLevelType Dio_FlipChannel(Gpio_ChannelType channelId)
{
    return (Dio_PinLevelType) TOGGLE_BIT(GPIODATA(channelId.port),channelId.pin);
}


/**********************************************************************************************************************
 *  END OF FILE: Gpio_arm.c
 *********************************************************************************************************************/
