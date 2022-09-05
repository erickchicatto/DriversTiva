/*
 * NVIC.h
 *
 *  Created on: Sep 5, 2022
 *      Author: robo1
 */

#ifndef NVIC_H_
#define NVIC_H_


#include <stdint.h>

#define NVIC_BASE       (0xE000E000ul)

// For the enable register
#define NVIC_OFFSET_Enable_EN0      0x100
#define NVIC_TOTAL_Enable_EN0       (NVIC_BASE)+(NVIC_OFFSET_Enable_EN0)

// For enable interrupts E0
typedef struct{
    uint32_t RW_0:1;
    uint32_t RW_1:1;
    uint32_t RW_2:1;
    uint32_t RW_3:1;
    uint32_t RW_4:1;
    uint32_t RW_5:1;
    uint32_t RW_6:1;
    uint32_t RW_7:1;
    uint32_t RW_8:1;
    uint32_t RW_9:1;
    uint32_t RW_10:1;
    uint32_t RW_11:1;
    uint32_t RW_12:1;
    uint32_t RW_13:1;
    uint32_t RW_14:1;
    uint32_t RW_15:1;
    uint32_t RW_16:1;
    uint32_t RW_17:1;
    uint32_t RW_18:1;
    uint32_t RW_19:1;
    uint32_t RW_20:1;
    uint32_t RW_21:1;
    uint32_t RW_22:1;
    uint32_t RW_23:1;
    uint32_t RW_24:1;
    uint32_t RW_25:1;
    uint32_t RW_26:1;
    uint32_t RW_27:1;
    uint32_t RW_28:1;
    uint32_t RW_29:1;
    uint32_t RW_30:1;
}Set_Enable_EN0;

//For bits
#define VALUE_ON_EN0     (1)
#define VALUE_OFF_EN0    (0)

//Register NVIC enable
#define NVIC_Set_Enable_EN0     ((Set_Enable_EN0*)(NVIC_TOTAL_Enable_EN0))
#define NVIC_Set_Enable_EN0_R   (*((volatile uint32_t*) (NVIC_TOTAL_Enable_EN0)))

// for disable interrupts E0
typedef struct{
    uint32_t RW_0:1;
    uint32_t RW_1:1;
    uint32_t RW_2:1;
    uint32_t RW_3:1;
    uint32_t RW_4:1;
    uint32_t RW_5:1;
    uint32_t RW_6:1;
    uint32_t RW_7:1;
    uint32_t RW_8:1;
    uint32_t RW_9:1;
    uint32_t RW_10:1;
    uint32_t RW_11:1;
    uint32_t RW_12:1;
    uint32_t RW_13:1;
    uint32_t RW_14:1;
    uint32_t RW_15:1;
    uint32_t RW_16:1;
    uint32_t RW_17:1;
    uint32_t RW_18:1;
    uint32_t RW_19:1;
    uint32_t RW_20:1;
    uint32_t RW_21:1;
    uint32_t RW_22:1;
    uint32_t RW_23:1;
    uint32_t RW_24:1;
    uint32_t RW_25:1;
    uint32_t RW_26:1;
    uint32_t RW_27:1;
    uint32_t RW_28:1;
    uint32_t RW_29:1;
    uint32_t RW_30:1;
}Set_Disable_EN0;


//For bits
#define VALUE_ON_DIS0     (1)
#define VALUE_OFF_DIS0    (0)

// For disable register
#define NVIC_OFFSET_Disable_EN0      0x180
#define NVIC_TOTAL_Disable_EN0       (NVIC_BASE)+(NVIC_OFFSET_Disable_EN0)

//Register NVIC enable
#define NVIC_Set_Disable_EN0     ((Set_Disable_EN0*)(NVIC_TOTAL_Disable_EN0))
#define NVIC_Set_Disable_EN0_R   (*((volatile uint32_t*) (NVIC_TOTAL_Disable_EN0)))


///Functions

inline void Interrupt_Enable(void);
inline void Interrupt_Disable(void);
inline void Enable_bits(uint32_t bit);




#endif /* NVIC_H_ */
