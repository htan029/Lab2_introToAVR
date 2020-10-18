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
    DDRC = 0xFF; PORTC= 0x00;

    unsigned char tempC = 0x00;
    unsigned char tempA = 0x00;
    /* Insert your solution below */
    while (1) {
        tempC = 0x00;
        tempA = PINA & 0x0F;
        tempC += (tempA & 0x01);
        tempC += (tempA & 0x02) >> 1;
        tempC += (tempA & 0x04) >> 2;
        tempC += (tempA & 0x08) >> 3;
        PORTC = tempC;
    }
    return 0;
}
