/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#define PRESCALAR_256  3;

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 =0;
    T1CONbits.TCKPS = PRESCALAR_256;
    PR1 = 39061;
    T1CONbits.ON=1;
    IEC0bits.T1IE =1;
    IPC1bits.T1IP = 7;
    IFS0bits.T1IF = 0;
}

initTimer2(){
    //TODO: Initialize Timer 2.
    TMR2 =0;
    T2CONbits.TCKPS = PRESCALAR_256;
    PR2 = 39061;
    T2CONbits.ON=1;
    IEC0bits.T2IE =1;
    IPC2bits.T2IP = 7;
    IFS0bits.T2IF = 0;
}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
    TMR2 = 0;
    PR2 = delay*624;
    IFS0bits.T2IF = 0;
    T2CONbits.ON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.ON = 0;
}
void resetTimer1(){
    TMR1 = 0;
    T1CONbits.ON = 0;
}
    