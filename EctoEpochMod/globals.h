
#ifndef __GLOBALS__
#define __GLOBALS__

#include "Arduino.h"

//Full 32-bit values for each animation "frame"
uint32_t vals[] = {
0x00000000, 
0x00010001, 
0x00030003, 
0x00070007, 
0x000F000F, 
0x001F001F, 
0x003F003F, 
0x007F007F, 
0x00FF00FF, 
0x01FF01FF, 
0x03FF03FF, 
0x07FF07FF, 
0x0FFF0FFF, 
0x1FFF1FFF, 
0x3FFF3FFF, 
0x7FFF7FFF, 
0xFFFFFFFF
};
	
volatile uint32_t dispBuf;
unsigned long timeRef;
unsigned long timeOutRef;

volatile uint8_t bSave = 0;
volatile uint16_t bCount = 0;
volatile boolean holdFlag = false;
uint16_t holdMax = 60;

//helpers for button handling
#define BUTTON_A _BV(PIND2)
#define BUTTON_B _BV(PIND3)
#define BUTTON_MASK (BUTTON_A | BUTTON_B)
#define BUTTON_STATE PIND & BUTTON_MASK

//Who can ever remember what the prescaler combinations are?
//These are for Timer0
#define PRESCALE0_1 _BV(CS00)
#define PRESCALE0_8 _BV(CS01)
#define PRESCALE0_64 (_BV(CS01) | _BV(CS00))
#define PRESCALE0_256 _BV(CS02)
#define PRESCALE0_1024 (_BV(CS02) | _BV(CS00))

//These are for Timer1
#define PRESCALE1_1 _BV(CS10)
#define PRESCALE1_8 _BV(CS11)
#define PRESCALE1_64 (_BV(CS11) | _BV(CS10))
#define PRESCALE1_256 _BV(CS12)
#define PRESCALE1_1024 (_BV(CS12) | _BV(CS10))

//These are for Timer2
#define PRESCALE2_1 _BV(CS20)
#define PRESCALE2_8 _BV(CS21)
#define PRESCALE2_32 (_BV(CS21) | _BV(CS20))
#define PRESCALE2_64 _BV(CS22)
#define PRESCALE2_128 (_BV(CS20) | _BV(CS22))
#define PRESCALE2_256 (_BV(CS22) | _BV(CS21))
#define PRESCALE2_1024 (_BV(CS22) | _BV(CS21) | _BV(CS20))

//Change this to whatever your computer serial connection is set to
//TODO: Change this to whatever the arduino drivers default to.
#define SERIAL_BAUD 115200

//Helpers for Serial printing
#define OD(x) Serial.print(x, DEC)
#define OS(x) Serial.print(x)
#endif //__GLOBALS__
