/*
 * File:   newmain.c
 * Author: kerem
 *
 * Created on 07 Nisan 2021 Çar?amba, 18:26
 */

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000 

int i = 0, ones = 0, tens = 0, array[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};

void main(void) {

    TRISA = 0;
    TRISB = 0;

    PORTA = 0x03;
    PORTB = 0;

    while (1) {

        ones = i % 10;
        tens = i / 10;

        RA0 = 0;
        PORTB = array[ones];
        __delay_ms(50);
        RA0 = 1;

        RA1 = 0;
        PORTB = array[tens];
        __delay_ms(50);
        RA1 = 1;

        i++;

        if (i == 100) i = 0;
    }

    return;
}
