/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

void initLEDs(){
    //TODO: Initialize LEDs
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
}
void turnOnLED(int led){

    //TODO: You may choose to write this function
    // as a matter of convenience
   
}