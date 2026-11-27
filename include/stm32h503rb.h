#ifndef STM32H503RB_H
#define STM32H503RB_H

#include <stdint.h>

#define PERIPHERAL_BASE (0x40000000U)
#define APB1_BASE (PERIPHERAL_BASE)
#define APB2_BASE (PERIPHERAL_BASE + 0x00010000U)
#define USART1_BASE (APB2_BASE + 0x3800U)
#define USART2_BASE (APB1_BASE + 0x4400U)
#define USART3_BASE (APB1_BASE + 0x4800U)

typedef struct USART_Regs
{
    volatile uint32_t CR1;   // Control register 1
    volatile uint32_t CR2;   // Control register 2
    volatile uint32_t CR3;   // Control register 3
    volatile uint32_t BRR;   // Baud rate register
    volatile uint32_t GTPR;  // Guard time and prescaler register
    volatile uint32_t RTOR;  // Receiver Time Out register
    volatile uint32_t RQR;   // Request register
    volatile uint32_t ISR;   // Interrupt and status register
    volatile uint32_t ICR;   // Interrupt flag Clear register
    volatile uint32_t RDR;   // Receive Data register
    volatile uint32_t TDR;   // Transmit Data register
    volatile uint32_t PRESC; // Prescaler register
} USART_Regs;

#endif // STM32H503RB_H
