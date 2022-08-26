/*
 * SCB.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Erick Chicatto
 */

#include "SCB.h"
#include "tm4c123gh6pm.h"

void WriteRegister(uint32_t u32RegisterAddress,
                   uint32_t u32RegisterValue,
                   uint32_t u32RegisterMask,
                   uint32_t u32RegisterShift) {

    uint32_t u32StatusRegister = 0U;
    uint32_t u32Reg = 0U; //registro temporal

    //u32StatusRegister = _get_interrupt_state();
    u32Reg = u32RegisterValue;
    volatile uint32_t* pu32RegisterAddress=(volatile uint32_t*)0U;

    //obtengo la direccion
    pu32RegisterAddress =(volatile uint32_t*)u32RegisterAddress;

    //bits en especifico para modificar
    if(0xFFFFU != u32RegisterMask)
    {
        u32Reg= pu32RegisterAddress; //obtengo el valor actual del registro
        //procesamiento del registro
        u32RegisterValue&=u32RegisterMask; //extraer bits que me interesan

        if(0U != u32RegisterShift){
            u32RegisterValue<<=u32RegisterShift;
            u32RegisterMask<<=u32RegisterShift;
        }
        u32Reg &=~u32RegisterMask; //limpiar el registro
        u32Reg |= u32RegisterValue; //nuevo valor que yo quiero ingresar
    }



    //si tengo la mascara al maximo entonces lo igualo al sigt valor
    *pu32RegisterAddress=u32Reg;

}



