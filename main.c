/// file : Main for the test to Tiva
/// brief : just for practice driver coding

#include "SCB.h"
#include "NVIC.h"
#include <stdint.h>

///@startuml
/// main->SCB++:
/// rnote over SCB: Execute SCB functions
/// main<--SCB--:
///@enduml

// state machines to apply the concepts
#define MAX_STATE  6
#define SCB_FAULTSTAT_OFFSET    0x0D28

enum states {
    STATE_A=0,
    STATE_B,
    STATE_C
};

typedef enum states State_type;

void state_a_function(void);
void state_b_function(void);
void state_c_function(void);
void state_machine_init(void);

static void(*state_table[])(void)={
   state_a_function,
};

static State_type current_state;
static int clock;


int main(void){

    //volatile int number1=0;
    //volatile int number2=0;

    //float fnumber1=0.1;
    //float fnumber2=0.2;

    //SCB__vReqSysReset();
    //SCB__vEnableTraps();
    //SCB__vEnableExceptions();
    //SCB__enSetPriorityGroup(SCB_enPRIGROUP_XXX);
    //SCB__enSetStackAligment(SCB_enALIGN_4BYTE);

    //example 1 NMI
    //SCB_NMI__vSetPending();

    //example 2
    //SCB_PENDSV__vSetPending();

    //example 3
    //SCB_UsageFault__vSetPending();

    //example 4 UsageFault DIV0
    //number2/=number1;

    //example 5 UsageFault UNALIGMENT SCB
    //(*((volatile uint32_t *)(SCB_BASE+SCB_FAULTSTAT_OFFSET+1)))=number2;

    //example 6 UsageFault NOCP
    //(*((volatile uint32_t*)((0xE000E000)+(0x0D88))))=0; //FPU Coprocessor disable
    //fnumber1*=fnumber2;

    /*
    while(1){
      state_table[current_state]();
      clock++;
    }*/


    //This is for the NVIC Memory examples

    Interrupt_Enable();
    Interrupt_Disable();
    Enable_bits(1);
    Enable_bits(2);

    //
    Enable_Bits_For_PRI0(INTA1);
    Enable_Bits_For_PRI0(INTA2);
    Enable_Bits_For_PRI0(INTA3);

    // for disable registers PRI0
    Disable_Off_Registers_PRI0(2u);


}


//machine states for dummy usages
void state_machine_init(void){
    current_state = STATE_A;
    clock=0;
}


void state_a_function(void){

    if(clock==1){
        current_state = STATE_B;
    }

}

void state_b_function(void){

    if(clock==2){
       current_state = STATE_C;
    }
}

void state_c_function(void){

    if(clock==9){
        current_state=STATE_A;
    }

}









