/*
 * NVIC.c
 *
 *  Created on: Sep 5, 2022
 *      Author: robo1
 */


#include "NVIC.h"


// For all the bytes
inline void Interrupt_Enable(){
    NVIC_Set_Enable_EN0_R  |= VALUE_ON_EN0 ;
}

//
inline void Interrupt_Disable(){
    NVIC_Set_Disable_EN0_R |= VALUE_ON_DIS0;
}

//


// for an individual bits general bits
inline void Enable_bits(uint32_t bit){

    switch(bit){
      case 1:
        // ways to write in the registers bits
        // SCB->INTCTRL |= SCB_INTCTRL_PENDSV_SET
        // SCB_INTCTRL->PENDSV = SCB_INTCTRL_PENDSV_SET
        // SCB->INTCTRL_Bit.PENDSV = SCB_INTCTRL_PENDSV_SET
          NVIC_Set_Enable_EN0->RW_0 |= VALUE_ON_EN0;
       break;
      case 2:
          NVIC_Set_Disable_EN0->RW_0 |= VALUE_ON_DIS0;
        break;
      default:
          //this is not use in this switch case
      }

}
