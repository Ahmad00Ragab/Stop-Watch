/*===========================================================================================
 * Filename   : Main.c
 * Author     : Ahmad Haroun
 * Description: Implementation For STOP WATCH SYSTEM
 * Created on : Jun 12, 2023
 *==========================================================================================*/

/*===========================================================================================
 * Specification
 * MicroController: ATMega32
 * CPU Frequency  : 1Mhz
 * Timer          : Timer1, 16-bit,CTC Mode
 * Display        : Six Common Anode 7-segments
 *
 * ***Actions****
 *
 * EXTERNAL_INT0  : RESET STOP WATCH
 * EXTERNAL_INT1  : PAUSE STOP WATCH
 * EXTERNAL_INT2  : RESUME STOP WATCH
 *==========================================================================================*/

#include "timer1.h"
#include "External_Interrupts.h"
#include "seven_segment.h"


/*******************************************************************************
 *                               Global_Variables Declaration                             *
 *******************************************************************************/

extern volatile uint8 SECOND ;
extern volatile uint8 MINUTE ;
extern volatile uint8 HOUR ;


/*******************************************************************************
 *                              Functions Definitions                          *
 *******************************************************************************/



/**************************************************************************
 * Function Name: Increment_Watch
 * Description  : Increment the seconds every compare match or every second
 * INPUTS       : void
 * RETURNS      : void
 **************************************************************************/
void Increment_Watch(void)
{
	SECOND++;
		if(SECOND == 60)
		{
			SECOND = 0;
			MINUTE++;
			if(MINUTE == 60)
			{
				MINUTE = 0;
				HOUR++;
				if(HOUR == 24)
				{
					SECOND = 0;
					MINUTE = 0;
					HOUR = 0;
				}
			}
		}
}


/**************************************************************************
 * Function Name: Pause_Watch
 * Description  : Pause the time on the 7-segment display
 * INPUTS       : void
 * RETURNS      : void
 **************************************************************************/
void Pause_Watch(void)
{
	TCCR1B = (TCCR1B & 0xF8) | (NO_CLOCK);
}


/**************************************************************************
 * Function Name: Resume_Watch
 * Description  : Resume the time on the 7-segment display after pause
 * INPUTS       : void
 * RETURNS      : void
 **************************************************************************/
void Resume_Watch(void)
{
	TCCR1B = (TCCR1B & 0xF8) | (PRESCALER_1024);
}


/**************************************************************************
 * Function Name: Resume_Watch
 * Description  : Reset the stop watch and make it count from 0
 * INPUTS       : void
 * RETURNS      : void
 **************************************************************************/
void Reset_Watch(void)
{
	SECOND = 0;
	MINUTE = 0;
	HOUR = 0;
}


/*******************************************************************************
 *                               Main                                          *
 *******************************************************************************/
int main(void)
{
	SEVEN_SEGMENT_init();
	INT0_init(FALLING_INTERRUPT);
	INT1_init(RAISING_INTERRUPT);
	INT2_init(FALLING_INTERRUPT);
	TIMER1_Set_CallBack(Increment_Watch,1);
    External_Interrupt_set_CallBack(Reset_Watch,0);
    External_Interrupt_set_CallBack(Pause_Watch,1);
    External_Interrupt_set_CallBack(Resume_Watch,2);
    PORTB |= (1 <<PB2);                              /* activate internal pull_up resistor for PB2 */
    PORTD |= (1 <<PD2);                              /* activate internal pull_up resistor for PD2 */
    TIMER1_Init_CTC_Mode(977,NORMAL_PORT,PRESCALER_1024,ENABLE_INTERRUPT);

    while(1)
	{
    	SEVEN_SEGMENT_Display_Number(SECOND,MINUTE,HOUR);
	}

}
