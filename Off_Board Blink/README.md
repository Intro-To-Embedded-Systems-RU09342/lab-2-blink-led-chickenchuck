# Off Board Blink
Blinks two leds at different speeds. Each LED cycles through four led blinking states when a button is pressed. The states are shown below:

State Number | LED0 Function | LED1 Function
--- | --- | ---
0 | off | off
1 | fast blink | slow blink
2 | medium blink | medium blink
3 | slow blink | fast blink

State 0 is entered on startup. To change the LED and button pins, change the #define statements at the top that give generic names for gpio registers and pins.

The program uses TimerA0 and TimerA1 to time LED flashes. They set to up mode, 8x prescaling, and the values of TA0CCR0 and TA1CCR0 (timer top values) changes depending on the state. An interrupt is generated when the timers overflow, which is caught by an interrupt vector, which toggles the LED pin.

The button press is detected using an interrupt as well. The interrupt is configured to generate on a rising edge, which corresponds to the press (not release) of the button. In the button's interrupt vector, the current state is updated, then TA0CCR0 is updated to its new value based on the new state.

This program is only compatible with the MSP430G2553. The program was tested with the MSP chip on a breadboard separated from the development board. The MSP chip could be programmed directly on the breadboard via the JTAG signals from the dev board (SBWTDIO and TBWTCK). The board was powered using the 3.3V power from the dev board.

![picture](picture.jpg)

