/*
 * Simple blink program for MSP430G2553
 *
 * Created: 9/21/19
 * Last Edited: 9/21/19
 * Author: Andrew Hollabaugh
 */

#include <msp430.h> //msp identifiers
#include <stdint.h> //for uint64_t

#define LED_DIR_R P1DIR //define generic name for led port direction reg
#define LED_OUT_R P1OUT //define generic name for led port out reg
#define LED_PIN 0 //define led pin number of port

#define BLINK_PERIOD 10000UL //define the top value of the blink counter

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer
    LED_DIR_R |= (1 << LED_PIN); //set direction to output

    while(1)
    {
        LED_OUT_R ^= (1 << LED_PIN); //toggle LED output using XOR
        for(volatile uint64_t i = 0; i < BLINK_PERIOD; i++); //loop and count until counter equals BLINK_PERIOD
    }
}

