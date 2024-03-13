/*
 * 	icu.c
 *	Description: source code for the AVR ICU driver
 *  Created on: Feb 20, 2024
 *  Author: AbdElRahman Khalifa
 */
#include"icu.h"
#include"common_macros.h"
#include<avr/io.h>
#include<avr/interrupt.h>

static volatile void (*g_ptr)(void)	=	NULL;

ISR(TIMER1_CAPT_vect){
	if (g_ptr != NULL) {
		g_ptr();
	}
}

/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr){
	/* Timer1 always work in normal mode */
	TCCR1A=(1<<FOC1A)|(1<<FOC1B);

	/* set clock as required & Timer1 always work in normal mode */
	TCCR1B=(Config_Ptr->clock);

	/* set Input Capture Edge Select as required */
	MAKE_BIT(TCCR1B,ICES1,Config_Ptr->edge);

	/* enable interrupt for ICU */
	SET_BIT(TIMSK,TICIE1);

	/* Initialize Timer1 Registers */
	TCNT1	=0;
	ICR1	=0;
}

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_setCallBack(void(*a_ptr)(void)){
	g_ptr=a_ptr;
}

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType edgeType){
	MAKE_BIT(TCCR1B, ICES1, edgeType);
}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void){
	return ICR1;
}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void){
	TCNT1=0;
}

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_deInit(void){
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;
	CLEAR_BIT(TIMSK, TICIE1);
	g_ptr = NULL;
}
