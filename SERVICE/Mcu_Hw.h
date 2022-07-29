/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef union 
{
    uint32 R;
    struct 
    {
        uint32 VECACT   :8;
        uint32          :3;
        uint32 RETBASE  :1;
        uint32 VECPEND  :8;
        uint32          :2;
        uint32 ISRPEND  :1;
        uint32 ISRPRE   :1;
        uint32          :1;
        uint32 PENDSTCLR:1;
        uint32 PENDSTSET:1;
        uint32 UNPENDSV :1;
        uint32 PENDSV   :1;
        uint32          :2;
        uint32 NMISET   :1; 
    }B;
}INTCTRL_Type;

typedef union 
{
    uint32 R;
    struct 
    {
        uint32 VECTRESET    :1;
        uint32 VECTCLRACT   :1;
        uint32 SYSRESREQ    :1;
        uint32              :5;
        uint32 PRIGROUP     :3;
        uint32              :4;
        uint32 ENDIANESS    :1;
        uint32 VECTKEY      :16;
    }B;
}APINT_Type;

typedef struct
{
  volatile  uint32 ISER[5U];               /* Offset: 0x000 (R/W)  Interrupt Set Enable Register */
            uint32 RESERVED0[27U];
  volatile  uint32 ICER[5U];               /* Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
            uint32 RSERVED1[27U];
  volatile  uint32 ISPR[5U];               /* Offset: 0x100 (R/W)  Interrupt Set Pending Register */
            uint32 RESERVED2[27U];
  volatile  uint32 ICPR[5U];               /* Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
            uint32 RESERVED3[27U];
  volatile  uint32 IABR[5U];               /* Offset: 0x200 (R/W)  Interrupt Active bit Register */
            uint32 RESERVED4[59U];
  volatile  uint8  IP[140U];               /* Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
            uint32 RESERVED5[669U];
  volatile  uint32 STIR;                   /* Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;

/* Software Triggered Interrupt Register Definitions */
#define NVIC_STIR_INTID_Pos                 0U                                         /*!< STIR: INTLINESNUM Position */
#define NVIC_STIR_INTID_Msk                (0x1FFUL /*<< NVIC_STIR_INTID_Pos*/)        /*!< STIR: INTLINESNUM Mask */


typedef enum {
/* -------------------  Cortex-M4 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              /*   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,              /*   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*   3  Hard Fault, all classes of Fault                                 */
  MemoryManagement_IRQn         = -12,              /*   4  Memory Management, MPU mismatch, including Access Violation
                                                         and No Match                                                        */
  BusFault_IRQn                 = -11,              /*   5  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                         related Fault                                                       */
  UsageFault_IRQn               = -10,              /*   6  Usage Fault, i.e. Undef Instruction, Illegal State Transition    */
  SVCall_IRQn                   =  -5,              /*  11  System Service Call via SVC instruction                          */
  DebugMonitor_IRQn             =  -4,              /*  12  Debug Monitor                                                    */
  PendSV_IRQn                   =  -2,              /*  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*  15  System Tick Timer                                                */
/* -------------------  TM4C123GH6PM Specific Interrupt Numbers  ------------------ */
  GPIOA_IRQn                    =   0,              /*   0  GPIOA                                                            */
  GPIOB_IRQn                    =   1,              /*   1  GPIOB                                                            */
  GPIOC_IRQn                    =   2,              /*   2  GPIOC                                                            */
  GPIOD_IRQn                    =   3,              /*   3  GPIOD                                                            */
  GPIOE_IRQn                    =   4,              /*   4  GPIOE                                                            */
  UART0_IRQn                    =   5,              /*   5  UART0                                                            */
  UART1_IRQn                    =   6,              /*   6  UART1                                                            */
  SSI0_IRQn                     =   7,              /*   7  SSI0                                                             */
  I2C0_IRQn                     =   8,              /*   8  I2C0                                                             */
  PWM0_FAULT_IRQn               =   9,              /*   9  PWM0_FAULT                                                       */
  PWM0_0_IRQn                   =  10,              /*  10  PWM0_0                                                           */
  PWM0_1_IRQn                   =  11,              /*  11  PWM0_1                                                           */
  PWM0_2_IRQn                   =  12,              /*  12  PWM0_2                                                           */
  QEI0_IRQn                     =  13,              /*  13  QEI0                                                             */
  ADC0SS0_IRQn                  =  14,              /*  14  ADC0SS0                                                          */
  ADC0SS1_IRQn                  =  15,              /*  15  ADC0SS1                                                          */
  ADC0SS2_IRQn                  =  16,              /*  16  ADC0SS2                                                          */
  ADC0SS3_IRQn                  =  17,              /*  17  ADC0SS3                                                          */
  WATCHDOG0_IRQn                =  18,              /*  18  WATCHDOG0                                                        */
  TIMER0A_IRQn                  =  19,              /*  19  TIMER0A                                                          */
  TIMER0B_IRQn                  =  20,              /*  20  TIMER0B                                                          */
  TIMER1A_IRQn                  =  21,              /*  21  TIMER1A                                                          */
  TIMER1B_IRQn                  =  22,              /*  22  TIMER1B                                                          */
  TIMER2A_IRQn                  =  23,              /*  23  TIMER2A                                                          */
  TIMER2B_IRQn                  =  24,              /*  24  TIMER2B                                                          */
  COMP0_IRQn                    =  25,              /*  25  COMP0                                                            */
  COMP1_IRQn                    =  26,              /*  26  COMP1                                                            */
  SYSCTL_IRQn                   =  28,              /*  28  SYSCTL                                                           */
  FLASH_CTRL_IRQn               =  29,              /*  29  FLASH_CTRL                                                       */
  GPIOF_IRQn                    =  30,              /*  30  GPIOF                                                            */
  UART2_IRQn                    =  33,              /*  33  UART2                                                            */
  SSI1_IRQn                     =  34,              /*  34  SSI1                                                             */
  TIMER3A_IRQn                  =  35,              /*  35  TIMER3A                                                          */
  TIMER3B_IRQn                  =  36,              /*  36  TIMER3B                                                          */
  I2C1_IRQn                     =  37,              /*  37  I2C1                                                             */
  QEI1_IRQn                     =  38,              /*  38  QEI1                                                             */
  CAN0_IRQn                     =  39,              /*  39  CAN0                                                             */
  CAN1_IRQn                     =  40,              /*  40  CAN1                                                             */
  HIB_IRQn                      =  43,              /*  43  HIB                                                              */
  USB0_IRQn                     =  44,              /*  44  USB0                                                             */
  PWM0_3_IRQn                   =  45,              /*  45  PWM0_3                                                           */
  UDMA_IRQn                     =  46,              /*  46  UDMA                                                             */
  UDMAERR_IRQn                  =  47,              /*  47  UDMAERR                                                          */
  ADC1SS0_IRQn                  =  48,              /*  48  ADC1SS0                                                          */
  ADC1SS1_IRQn                  =  49,              /*  49  ADC1SS1                                                          */
  ADC1SS2_IRQn                  =  50,              /*  50  ADC1SS2                                                          */
  ADC1SS3_IRQn                  =  51,              /*  51  ADC1SS3                                                          */
  SSI2_IRQn                     =  57,              /*  57  SSI2                                                             */
  SSI3_IRQn                     =  58,              /*  58  SSI3                                                             */
  UART3_IRQn                    =  59,              /*  59  UART3                                                            */
  UART4_IRQn                    =  60,              /*  60  UART4                                                            */
  UART5_IRQn                    =  61,              /*  61  UART5                                                            */
  UART6_IRQn                    =  62,              /*  62  UART6                                                            */
  UART7_IRQn                    =  63,              /*  63  UART7                                                            */
  I2C2_IRQn                     =  68,              /*  68  I2C2                                                             */
  I2C3_IRQn                     =  69,              /*  69  I2C3                                                             */
  TIMER4A_IRQn                  =  70,              /*  70  TIMER4A                                                          */
  TIMER4B_IRQn                  =  71,              /*  71  TIMER4B                                                          */
  TIMER5A_IRQn                  =  92,              /*  92  TIMER5A                                                          */
  TIMER5B_IRQn                  =  93,              /*  93  TIMER5B                                                          */
  WTIMER0A_IRQn                 =  94,              /*  94  WTIMER0A                                                         */
  WTIMER0B_IRQn                 =  95,              /*  95  WTIMER0B                                                         */
  WTIMER1A_IRQn                 =  96,              /*  96  WTIMER1A                                                         */
  WTIMER1B_IRQn                 =  97,              /*  97  WTIMER1B                                                         */
  WTIMER2A_IRQn                 =  98,              /*  98  WTIMER2A                                                         */
  WTIMER2B_IRQn                 =  99,              /*  99  WTIMER2B                                                         */
  WTIMER3A_IRQn                 = 100,              /* 100  WTIMER3A                                                         */
  WTIMER3B_IRQn                 = 101,              /* 101  WTIMER3B                                                         */
  WTIMER4A_IRQn                 = 102,              /* 102  WTIMER4A                                                         */
  WTIMER4B_IRQn                 = 103,              /* 103  WTIMER4B                                                         */
  WTIMER5A_IRQn                 = 104,              /* 104  WTIMER5A                                                         */
  WTIMER5B_IRQn                 = 105,              /* 105  WTIMER5B                                                         */
  SYSEXC_IRQn                   = 106,              /* 106  SYSEXC                                                           */
  PWM1_0_IRQn                   = 134,              /* 134  PWM1_0                                                           */
  PWM1_1_IRQn                   = 135,              /* 135  PWM1_1                                                           */
  PWM1_2_IRQn                   = 136,              /* 136  PWM1_2                                                           */
  PWM1_3_IRQn                   = 137,              /* 137  PWM1_3                                                           */
  PWM1_FAULT_IRQn               = 138               /* 138  PWM1_FAULT                                                       */
} IRQn_Type;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SRAM_BASE_ADDR                               0x20000000UL //to 0x20007FFF
#define PERI_BASE_ADDR                               0x40000000UL //to 0x400FFFFF (0x40000000, 0x400FFFFF)

// The starting address of the alias region
#define SRAM_BIT_BAND_BASE_ADDR                      0x22000000UL //TODO: to 0x??????
#define PERI_BIT_BAND_BASE_ADDR                      0x42000000UL //to 0x43FFFFFF  (0x42000000, 0x43FFFFFF)

#define CORE_PERIPHERALS_BASE                        0xE000E000UL



//The RCGCGPIO register provides software the capability to enable and disable GPIO modules in Run mode.
#define RCGCGPIO_ADDR                           0x400FE608UL

#define CGC_PORTA                               0UL
#define CGC_PORTB                               1UL
#define CGC_PORTC                               2UL
#define CGC_PORTD                               3UL
#define CGC_PORTE                               4UL
#define CGC_PORTF                               5UL

//Another approach
// #define GPIO_PORT_B_BASS_ADDRESS                0x40005000
// #define GPIO_PORT_C_BASS_ADDRESS                0x40006000
// #define GPIO_PORT_D_BASS_ADDRESS                0x40007000
// #define GPIO_PORT_E_BASS_ADDRESS                0x40024000
// #define GPIO_PORT_F_BASS_ADDRESS                0x40025000

#define GPIO_PORT_A_BASS_ADDRESS                0x40004000UL

#define GPIO_PORTA                              0UL
#define GPIO_PORTB                              1UL
#define GPIO_PORTC                              2UL
#define GPIO_PORTD                              3UL
#define GPIO_PORTE                              4UL
#define GPIO_PORTF                              5UL


#define GPIO_PORT(x)                            ((x)<GPIO_PORTE)? ((GPIO_PORT_A_BASS_ADDRESS) + ((x)<<12U)):((0x40020000UL) + ((x)<<12U))

#define GPIODATA_ADDR(x)                        (((GPIO_PORT(x)) + 0x3FC))
#define GPIODIR_ADDR(x)                         (((GPIO_PORT(x)) + 0x400))
#define GPIOAFSEL_ADDR(x)                       (((GPIO_PORT(x)) + 0x420))
#define GPIOCTL_ADDR(x)                         (((GPIO_PORT(x)) + 0x52C))
#define GPIODR2R_ADDR(x)                        (((GPIO_PORT(x)) + 0x500))
#define GPIODR4R_ADDR(x)                        (((GPIO_PORT(x)) + 0x504))
#define GPIODR8R_ADDR(x)                        (((GPIO_PORT(x)) + 0x508))
#define GPIOODR_ADDR(x)                         (((GPIO_PORT(x)) + 0x50C))
#define GPIOPUR_ADDR(x)                         (((GPIO_PORT(x)) + 0x510))
#define GPIOPDR_ADDR(x)                         (((GPIO_PORT(x)) + 0x514))
#define GPIODEN_ADDR(x)                         (((GPIO_PORT(x)) + 0x51C))
#define GPIOLOCK_ADDR(x)                        (((GPIO_PORT(x)) + 0x520))
#define GPIOCR_ADDR(x)                          (((GPIO_PORT(x)) + 0x524))


#define GPIODATA(x)                             (*((volatile uint32*)     GPIODATA_ADDR(x)   ))
#define GPIODIR(x)                              (*((volatile uint32*)     GPIODIR_ADDR(x)    ))
#define GPIOAFSEL(x)                            (*((volatile uint32*)     GPIOAFSEL_ADDR(x)  ))
#define GPIOCTL(x)                              (*((volatile uint32*)     GPIOCTL_ADDR(x)    ))
#define GPIODR2R(x)                             (*((volatile uint32*)     GPIODR2R_ADDR(x)   ))
#define GPIODR4R(x)                             (*((volatile uint32*)     GPIODR4R_ADDR(x)   ))
#define GPIODR8R(x)                             (*((volatile uint32*)     GPIODR8R_ADDR(x)   ))
#define GPIOODR(x)                              (*((volatile uint32*)     GPIOODR_ADDR(x)    ))
#define GPIOPUR(x)                              (*((volatile uint32*)     GPIOPUR_ADDR(x)    ))
#define GPIOPDR(x)                              (*((volatile uint32*)     GPIOPDR_ADDR(x)    ))
#define GPIODEN(x)                              (*((volatile uint32*)     GPIODEN_ADDR(x)    ))
#define GPIOLOCK(x)                             (*((volatile uint32*)     GPIOLOCK_ADDR(x)   ))
#define GPIOCR(x)                               (*((volatile uint32*)     GPIOCR_ADDR(x)     ))

// #define GPIODATA_PORTF                          (GPIO_PORT_F_BASS_ADDRESS+0x000)
// #define GPIODIR_PORTF                           (GPIO_PORT_F_BASS_ADDRESS+0x400)
// #define GPIOAFSEL_PORTF                         (GPIO_PORT_F_BASS_ADDRESS+0x420)
// #define GPIOCTL_PORTF                           (GPIO_PORT_F_BASS_ADDRESS+0x52C)
// #define GPIODR2R_PORTF                          (GPIO_PORT_F_BASS_ADDRESS+0x500)
// #define GPIODR4R_PORTF                          (GPIO_PORT_F_BASS_ADDRESS+0x504)
// #define GPIODR8R_PORTF                          (GPIO_PORT_F_BASS_ADDRESS+0x508)
// #define GPIOODR_PORTF                           (GPIO_PORT_F_BASS_ADDRESS+0x50C)
// #define GPIOPUR_PORTF                           (GPIO_PORT_F_BASS_ADDRESS+0x510)
// #define GPIOPDR_PORTF                           (GPIO_PORT_F_BASS_ADDRESS+0x514)
// #define GPIODEN_PORTF                           (GPIO_PORT_F_BASS_ADDRESS+0x51C)
// #define GPIOLOCK_PORTF                          (GPIO_PORT_F_BASS_ADDRESS+0x520)
// #define GPIOCR_PORTF                            (GPIO_PORT_F_BASS_ADDRESS+0x524)
// #define GPIODIR_PORTF                           (GPIO_PORT_F_BASS_ADDRESS+0x400)



/*The RCGCTIMER register provides software the capability to enable and disable 16/32-bit timer modules in Run mode.*/
#define RCGCTIMER_ADDR                          0x400FE604UL
#define CGC_BIT_TIMER(x)                        ((x)<6UL)? (x):((x)-6UL)

// #define CGC_TIMER_0_BIT                         0
// #define CGC_TIMER_1_BIT                         1
// #define CGC_TIMER_2_BIT                         2
// #define CGC_TIMER_3_BIT                         3
// #define CGC_TIMER_4_BIT                         4
// #define CGC_TIMER_5_BIT                         5

#define GPT_TIMER0                              0U
#define GPT_TIMER1                              1U
#define GPT_TIMER2                              2U
#define GPT_TIMER3                              3U
#define GPT_TIMER4                              4U
#define GPT_TIMER5                              5U
#define GPT_TIMER0_WIDE                         6U
#define GPT_TIMER1_WIDE                         7U
#define GPT_TIMER2_WIDE                         8U
#define GPT_TIMER3_WIDE                         9U
#define GPT_TIMER4_WIDE                         10U
#define GPT_TIMER5_WIDE                         11U

/*
■ 16/32-bit Timer 0:      0x4003.0000
■ 16/32-bit Timer 1:      0x4003.1000
■ 16/32-bit Timer 2:      0x4003.2000
■ 16/32-bit Timer 3:      0x4003.3000
■ 16/32-bit Timer 4:      0x4003.4000
■ 16/32-bit Timer 5:      0x4003.5000
■ 32/64-bit Wide Timer 0: 0x4003.6000
■ 32/64-bit Wide Timer 1: 0x4003.7000
■ 32/64-bit Wide Timer 2: 0x4004.C000
■ 32/64-bit Wide Timer 3: 0x4004.D000
■ 32/64-bit Wide Timer 4: 0x4004.E000
■ 32/64-bit Wide Timer 5: 0x4004.F000
*/
//Base address of each timer
#define GPT_BASE_ADDR_TIMER(x)                  (((x) < (GPT_TIMER2_WIDE))?   ((0x40030000UL) + ((x)<<12U))  :  ((0x40044000UL) + ((x)<<12U)))

#define GPTMCFG_OFFSET                          (0x0000UL)
#define GPTMTAMR_OFFSET                         (0x0004UL)
#define GPTMCTL_OFFSET                          (0x000CUL)
#define GPTMIMR_OFFSET                          (0x0018UL)
#define GPTMMIS_OFFSET                          (0x0020UL)
#define GPTMICR_OFFSET                          (0x0024UL)
#define GPTMTAILR_OFFSET                        (0x0028UL)
#define GPTMTAPR_OFFSET                         (0x0038UL)
#define GPTMTAR_OFFSET                          (0x0048UL)
#define GPTMTAV_OFFSET                          (0x0050UL)
#define GPTMTAPV_OFFSET                         (0x0064UL)

// GPTMCTL useful bits
#define GPTMCTL_TAEN                            0U

// GPTMTAMR useful bits
#define GPTMTAMR_TACDIR                         4U
#define GPTMTAMR_TAMIE                          5U
#define GPTMTAMR_TAILD                          8U

// GPTMTAR


// useful bits GPTMICR
#define GPTMICR_TATOCINT                        0U

//GPTMIMR useful bits 
#define GPTMIMR_TATOIM                          0U


#define GPTMCFG_TIMER(x)                        (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMCFG_OFFSET   )))
#define GPTMTAMR_TIMER(x)                       (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMTAMR_OFFSET  )))
#define GPTMCTL_TIMER(x)                        (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMCTL_OFFSET   )))
#define GPTMIMR_TIMER(x)                        (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMIMR_OFFSET   )))
#define GPTMMIS_TIMER(x)                        (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMMIS_OFFSET   )))
#define GPTMICR_TIMER(x)                        (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMICR_OFFSET   )))
#define GPTMTAILR_TIMER(x)                      (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMTAILR_OFFSET )))
#define GPTMTAPR_TIMER(x)                       (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMTAPR_OFFSET  )))
#define GPTMTAR_TIMER(x)                        (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMTAR_OFFSET   )))
#define GPTMTAV_TIMER(x)                        (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMTAV_OFFSET   )))
#define GPTMTAPV_TIMER(x)                       (*((volatile uint32*)     (GPT_BASE_ADDR_TIMER(x) + GPTMTAPV_OFFSET  )))

#define GPTMCFG_ADDR_TIMER(x)                   ((GPT_BASE_ADDR_TIMER(x) + GPTMCFG_OFFSET   ))
#define GPTMTAMR_ADDR_TIMER(x)                  ((GPT_BASE_ADDR_TIMER(x) + GPTMTAMR_OFFSET  ))
#define GPTMCTL_ADDR_TIMER(x)                   ((GPT_BASE_ADDR_TIMER(x) + GPTMCTL_OFFSET   ))
#define GPTMIMR_ADDR_TIMER(x)                   ((GPT_BASE_ADDR_TIMER(x) + GPTMIMR_OFFSET   ))
#define GPTMMIS_ADDR_TIMER(x)                   ((GPT_BASE_ADDR_TIMER(x) + GPTMMIS_OFFSET   ))
#define GPTMICR_ADDR_TIMER(x)                   ((GPT_BASE_ADDR_TIMER(x) + GPTMICR_OFFSET   ))
#define GPTMTAPR_ADDR_TIMER(x)                  ((GPT_BASE_ADDR_TIMER(x) + GPTMTAPR_OFFSET  ))
#define GPTMTAR_ADDR_TIMER(x)                   ((GPT_BASE_ADDR_TIMER(x) + GPTMTAR_OFFSET   ))
#define GPTMTAV_ADDR_TIMER(x)                   ((GPT_BASE_ADDR_TIMER(x) + GPTMTAV_OFFSET   ))
#define GPTMTAPV_ADDR_TIMER(x)                  ((GPT_BASE_ADDR_TIMER(x) + GPTMTAPV_OFFSET  ))



#define NVIC_BASE                               (CORE_PERIPHERALS_BASE +  0x0100UL)                                             /*!< NVIC Base Address */
#define NVIC                                    (*((NVIC_Type*              )   NVIC_BASE                              ))       /*!< NVIC configuration struct */
#define APINT                                   (*((volatile APINT_Type*    )   (CORE_PERIPHERALS_BASE + 0xD0CUL)      ))
#define INTCTRL                                 (*((volatile INTCTRL_Type*  )   (CORE_PERIPHERALS_BASE + 0xD04UL)      ))



//accessing the bit band region if not in the peripheral range goes to the SRAM range
#define BIT_BAND(address, bit)          ((volatile uint32*)(((address)>=(PERI_BASE_ADDR))?  ((PERI_BIT_BAND_BASE_ADDR)+(((address)-(PERI_BASE_ADDR))<<5UL)+((bit)<<2UL)) \
                                                                                           :((SRAM_BIT_BAND_BASE_ADDR)+(((address)-(SRAM_BASE_ADDR))<<5UL)+((bit)<<2UL))    ))



// Writing to a bit using bit banding. Should use address instead of pointer e.g: GPIODATA_ADDR(PORTF) not GPIODATA(PORTF)
#define WRITE_BIT_BB(address,bit,value)         (*(BIT_BAND((address),(bit))            ) = (value)         )
#define READ_BIT_BB(address,bit)                (*(BIT_BAND((address),(bit))            )                   )

 
#define TOGGLE_BIT(register,bit)                ((register) ^= 1<<(bit))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
