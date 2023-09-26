/*===========================================================================================
 * Filename   : seven_segment.c
 * Author     : Ahmad Haroun
 * Description: Source file for the seven_segment Driver
 * Created on : Jun 11, 2023
 *==========================================================================================*/

#include "seven_segment.h"
#include "gpio.h"
#include <util/delay.h>       /* To include _delay_us() Function */


/*******************************************************************************
 *                              Functions Definitions                          *
 *******************************************************************************/



/**************************************************************************
 * Function Name: SEVEN_SEGMENT_init
 * Description  : Setup the direction of SEVEN SEGMENTS DATA PINS as output pins,
 *                Also Setup the direction of SEVEN SEGMENTS COMMON PINS as output pins,
 *                Display ZERO on SEVEN SEGMENT DISPLAY
 * INPUTS       : void
 * RETURNS      : void
 **************************************************************************/
void SEVEN_SEGMENT_init(void)
{

	GPIO_setupPinDirection(Sev_Segment_Data_PORT_ID, Sev_Segment_Data1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Sev_Segment_Data_PORT_ID, Sev_Segment_Data2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Sev_Segment_Data_PORT_ID, Sev_Segment_Data3_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Sev_Segment_Data_PORT_ID, Sev_Segment_Data4_ID, PIN_OUTPUT);

	GPIO_setupPinDirection(Sev_Segment_Common_PORT_ID, Sev_Segment_Common0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Sev_Segment_Common_PORT_ID, Sev_Segment_Common1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Sev_Segment_Common_PORT_ID, Sev_Segment_Common2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Sev_Segment_Common_PORT_ID, Sev_Segment_Common3_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Sev_Segment_Common_PORT_ID, Sev_Segment_Common4_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Sev_Segment_Common_PORT_ID, Sev_Segment_Common5_ID, PIN_OUTPUT);

	/* Display 0 at the begining */
	PORTC = PORTC & (0xF0);
}


/**************************************************************************
 * Function Name: SEVEN_SEGMENT_Display_Number
 * Description  : Display the input SECOND, MINUTE and HOUR Values on the
 *                SEVEN SEGMENTS DISPLAY
 * INPUTS       : Second, Minute and Hour
 * RETURNS      : void
 **************************************************************************/
void SEVEN_SEGMENT_Display_Number(uint8 Second,uint8 Minute,uint8 Hour)
{
	uint8 displayed_num;

	displayed_num = (uint8)(Second % 10);                     /* Turn on the First 7-segment by setting its common pin and Turn off rest */
	PORTA = (1 << 0);									      /* display the first digit of the value of the Seconds */
	PORTC = (PORTC & 0xF0) | (displayed_num & 0x0F);
	_delay_us(10);

	displayed_num = (uint8)(Second / 10);                     /* Turn on the Second 7-segment by setting its common pin and Turn off rest */
	PORTA = (1 << 1);                                         /* display the Second digit of the value of the Seconds */
	PORTC = (PORTC & 0xF0) | (displayed_num & 0x0F);
	_delay_us(10);

	displayed_num = (uint8)(Minute % 10);                     /* Turn on the Third 7-segment by setting its common pin and Turn off rest */
	PORTA = (1 << 2);                                         /* display the Third digit of the value of the Minutes */
	PORTC = (PORTC & 0xF0) | (displayed_num & 0x0F);
	_delay_us(10);

	displayed_num = (uint8)( Minute / 10);                    /* Turn on the Fourth 7-segment by setting its common pin and Turn off rest */
	PORTA = (1 << 3);                                         /* display the Fourth digit of the value of the Minutes */
	PORTC = (PORTC & 0xF0) | (displayed_num & 0x0F);
	_delay_us(10);

	displayed_num = (uint8)( Hour % 10);                      /* Turn on the Fifth 7-segment by setting its common pin and Turn off rest */
	PORTA = (1 << 4);                                         /* display the Fifth digit of the value of the Hours */
	PORTC = (PORTC & 0xF0) | (displayed_num & 0x0F);
	_delay_us(10);

	displayed_num = (uint8)( Hour / 10);                      /* Turn on the sixth 7-segment by setting its common pin and Turn off rest */
	PORTA = (1 << 5);                                         /* display the Sixth digit of the value of the Hours */
	PORTC = (PORTC & 0xF0) | (displayed_num & 0x0F);
	_delay_us(10);
}
