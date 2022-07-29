/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \file:  Gpio.h
 *        \brief:  -
 *
 *       \detail:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_ARM_H
#define GPIO_ARM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Gpio_Cfg.h"
#include "Gpio_Types.h"
#include "Mcu_Hw.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gpio_PortInit(const Gpio_PinConfigType* ConfigPtr);

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
* \Description     : Read a pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType ChannelId                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_PinLevelType Dio_ReadChannel(Gpio_ChannelType ChannelId);

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
void Dio_WriteChannel(Gpio_ChannelType channelId, Dio_PinLevelType Level);

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
Dio_PortValueType Dio_ReadPort(Gpio_PortType portId);

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
void Dio_WritePort(Gpio_PortType PortId, Dio_PortValueType Level);

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
* \Description     : toggle a pin                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType ChannelId                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_PinLevelType Dio_FlipChannel(Gpio_ChannelType ChannelId);

#endif /* GPIO_ARM_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio.h
 *********************************************************************************************************************/
