/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------    -------------------------------------------
 *         \file:  Gpt_Cfg.h
 *        \brief:  -
 *
 *      \details:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_CFG_H
#define GPT_CFG_H



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Gpt_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//Uncomment only one timer type
#define GPT_PREDEF_TIMER_1US_16BIT
// #define GPT_PREDEF_TIMER_1US_24BIT
// #define GPT_PREDEF_TIMER_1US_32BIT
// #define GPT_PREDEF_TIMER_100US_32BIT


#define GPT_CONFIG_ARRAY_SIZE 2

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Gpt_ConfigType global_GptConfig[GPT_CONFIG_ARRAY_SIZE];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 

#endif /* GPT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Cfg.h
 *********************************************************************************************************************/
