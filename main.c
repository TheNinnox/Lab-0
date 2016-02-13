/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1
#define SW1 PORTDbits.RD6

volatile int ledState = 1;

//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    led1, led2, led3, wait, wait2, debouncePress, debounceRelease, debounceRelease2
} stateType;

//TODO: Use volatile variables that change within interrupts

int main() {
    //This function is necessary to use interrupts. 
    enableInterrupts();
    SYSTEMConfigPerformance(10000000);

    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    initTimer2();
    initTimer1();
    
    int ledState;
    
    while(1){

        //TODO: Implement a state machine to create the desired functionality
        switch(ledState){
            case 1:
                LATDbits.LATD0 = 1;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                break;
            case 2:
                LATDbits.LATD0 = 1;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                break;
            case 3:
                LATDbits.LATD0 = 1;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                break;
            
            
                
                      
        }
    
    return 0;
}
    void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt(){
        IFS0bits.T1IF = 0;
        if(ledState ==1) ledState = 2;
        else if (ledState ==2) ledState = 3;
        else if (ledState ==3) ledState = 1;
    }
    /*
    void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt() {
        IFS1bits.CNDIF = 0;
        int i;
        i = PORTD;
        if(SW1 == 1){
            LED1 = ON;
        }
        else {
            LED1 = OFF;
        }
    }*/