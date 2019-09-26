# Multi Blink
Blinks two LEDs at two different rates. Compatible with MSP430G2553 and MSP430FR6989. To change the LED pins, change the LED_PORT and/or the LED_PIN values. Change the TAxCCR0 values to change the blink period.

The program initializes TimerA0 and TimerA1 to independently control the two LEDs. Each timer is set to up mode, 8x prescaling, and a certain value in the TAxCCR0 register which changes the blink period. One of each timer's two interrupt vectors is used. Whenever one of many events happen in the timer, the interrupt is called, then it checks to see if it was called because of a timer overflow by checking TAxIV. If so, it toggles the LED.

### Differences Between Implementation for each Processor
- The FR6989 needs the link `PM5CTL0 &= ~LOCKLPM5`, which disables the GPIO pins' default high impedance state
- The timers have different numbers of capture/compare registers, which affects the values of TAxIV: 0x0A is timer overflow for G2553, and 0x0E is timer overflow for FR6989
