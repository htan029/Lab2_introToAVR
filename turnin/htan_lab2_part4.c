/*	Author: Heng Tan
 *  Partner(s) Name: 
 *	Lab Section: 024
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;
    unsigned char tempC = 0x00;
    unsigned char tempD = 0x00;
    unsigned char checkAC = 0x00;
    unsigned char totalABCchar = 0x00;
    unsigned short totalABC = 0x0000;
    
    /* Insert your solution below */
    while (1) {
        tempA = PINA;
        tempB = PINB;
        tempC = PINC;
        tempD = 0x00;
        totalABC = tempA + tempB + tempC;
        if(totalABC > 0x008C)
            tempD = tempD | 0x01;
            
        checkAC = tempA>tempC ? tempA - tempC : tempC - tempA;
        if(checkAC > 0x50)
            tempD = tempD | 0x02;
            
        totalABCchar = tempA + tempB + tempC;
        totalABCchar = totalABCchar << 2;
        tempD = tempD | totalABCchar;
        PORTD = tempD;
    }
    return 0;
}
