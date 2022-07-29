/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpt.h"

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
* \Syntax          : Std_ReturnType Gpt_Init(const Gpt_ConfigType*ConfigPtr)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Description                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Gpt_Init(const Gpt_ConfigType* configPtr)
{
    uint8 i;
    for(i = 0 ; i < GPT_CONFIG_ARRAY_SIZE ; i++){ 

        WRITE_BIT_BB(RCGCTIMER_ADDR,CGC_BIT_TIMER(configPtr[i].channelId),STD_HIGH);       /* Enable clock gate to the timer*/
        WRITE_BIT_BB(GPTMCTL_ADDR_TIMER(configPtr[i].channelId),GPTMCTL_TAEN,STD_LOW);                /* Disables the timer*/


        //TODO: Wait 3 system clocks after the timer module clock is enabled
        
        GPTMCFG_TIMER(configPtr[i].channelId) = 0x0;                                       /* 32-bit timer configuration and 64-bit for wide timers */

        // 0b0000 0001 0001   -->                   0x21
        // TAMR: one-shot mode -->                  0x1
        // TACDIR: count down -->                   0x10
        // TAMIE: Match innerrupt enabled  ->       0x20
        if(configPtr[i].mode ==  GPT_MODE_PERIODIC)
        {
            GPTMTAMR_TIMER(configPtr[i].channelId) = 0x02;
        }
        else{
            GPTMTAMR_TIMER(configPtr[i].channelId) = 0x01;
        }
        // GPTMTAPR_TIMER(configPtr[i].channelId) = 0xFFFF;                                         /* Set the prescaler*/
    }
    return E_OK;
    

}


// GPT_PREDEF_TIMER_1US_16BIT
// GPT_PREDEF_TIMER_1US_24BIT
// GPT_PREDEF_TIMER_1US_32BIT
// GPT_PREDEF_TIMER_100US_32BIT

/**
 * @brief Starts the timer @param channel, and start counting from the @param value to zero
 * 
 * 
 * @param channel 
 * @param value in milliseconds
 */
void Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType value)
{
    GPTMTAILR_TIMER(channel) = value * 16000U;                                  /* Load value to the timer */
    WRITE_BIT_BB(GPTMIMR_ADDR_TIMER(channel),GPTMIMR_TATOIM ,STD_HIGH);     /*Enable Interrupt*/
    WRITE_BIT_BB(GPTMCTL_ADDR_TIMER(channel),GPTMCTL_TAEN   ,STD_HIGH);     /* Enable the timer and start counting*/	
}

void Gpt_StopTimer(Gpt_ChannelType channel)
{
    WRITE_BIT_BB(GPTMIMR_ADDR_TIMER(channel),GPTMIMR_TATOIM ,STD_LOW);    /*Disable Interrupt*/
    WRITE_BIT_BB(GPTMCTL_ADDR_TIMER(channel),GPTMCTL_TAEN   ,STD_LOW);    /* Disable the timer and stop counting*/
}


void Gpt_DisableNotification(Gpt_ChannelType channel)
{
    WRITE_BIT_BB(GPTMIMR_ADDR_TIMER(channel),GPTMIMR_TATOIM ,STD_HIGH);     /*Enable Interrupt*/
}

void Gpt_EnableNotification(Gpt_ChannelType channel)
{
    WRITE_BIT_BB(GPTMIMR_ADDR_TIMER(channel),GPTMIMR_TATOIM ,STD_LOW);    /*Disable Interrupt*/
}


void TIMER0A_Handler(void)
{
    WRITE_BIT_BB(GPTMICR_ADDR_TIMER(0),GPTMICR_TATOCINT,STD_HIGH);
    Gpt_Notification_Channel_0();
}

// Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
// {
//     //TODO: GPTMTAV  how to get elapsed time value {Ticks}

// }
// Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
// {
//     //TODO: GPTMTAV  how to get remaining time value {Ticks}

// }
// Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
// {

// }





/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
