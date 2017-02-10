#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0;

unsigned long _avr_timer_M = 1;
unsigned long _avr_timer_cntcurr = 0;

//Switched to using the 8-bit Timer 2

void TimerOn() {
	TCCR2B = 0x0B; //0000 1011
	OCR2A = 125;
	TIMSK2 = 0x02;
	TCNT2 = 0;
	_avr_timer_cntcurr = _avr_timer_M;
	SREG = 0x80;
}

void TimerOff() {
	TCCR2B = 0x00;
}

void TimerISR() {
	TimerFlag = 1;
}

ISR(TIMER2_COMPA_vect) {
	_avr_timer_cntcurr--;
	if(_avr_timer_cntcurr == 0) {
		TimerISR();
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}