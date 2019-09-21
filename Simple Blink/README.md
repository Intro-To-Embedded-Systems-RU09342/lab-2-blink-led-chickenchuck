# Simple Blink
Blinks LED at a constant rate. Compatible with MSP430G2553 and MSP430FR6989. To change the LED pin, change the LED_PORT to change the GPIO port and the LED_PIN to change the pin number of the port. Note that the development boards have LEDS connected to specific pins. To change the blink rate, change the BLINK_PERIOD.

The program uses a for loop to count until it reaches the BLINK_PERIOD value, then toggles the pin. This could be done more elegantly using a timer and timer overflow interrupt to toggle the pin, but this isn't necessary when the program doesn't have other tasks to do.

### Differences Between Implementation for each Processor
The only difference between the program for each processor is the fr6989 needs the line `PM5CTL0 &= ~LOCKLPM5`. This processor's GPIO pins are in a high-impedance state when the chip powers on. This line disables this by writing a zero to the LOCKLPM5 bit of the PM5CTL0 register.
