/*===========================================================================================
 * Filename   : seven_segment.h
 * Author     : Ahmad Haroun
 * Description: Header file for the seven_segment Driver
 * Created on : Jun 12, 2023
 *==========================================================================================*/
#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "std_types.h"
#include "gpio.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


/* the port that we send the number on */
#define Sev_Segment_Data_PORT_ID    PORTC_ID

/* the pins inside the port that we send the number on */
#define  Sev_Segment_Data1_ID       PIN0_ID
#define  Sev_Segment_Data2_ID       PIN1_ID
#define  Sev_Segment_Data3_ID       PIN2_ID
#define  Sev_Segment_Data4_ID       PIN3_ID


/* port  of the pins that we control the common pin of the 7-segment */
#define  Sev_Segment_Common_PORT_ID  PORTA_ID

#define   Sev_Segment_Common0_ID     PIN0_ID
#define   Sev_Segment_Common1_ID     PIN1_ID
#define   Sev_Segment_Common2_ID     PIN2_ID
#define   Sev_Segment_Common3_ID     PIN3_ID
#define   Sev_Segment_Common4_ID     PIN4_ID
#define   Sev_Segment_Common5_ID     PIN5_ID



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/**************************************************************************
 * Function Name: SEVEN_SEGMENT_init
 * Description  : Setup the direction of SEVEN SEGMENTS DATA PINS as output pins,
 *                Also Setup the direction of SEVEN SEGMENTS COMMON PINS as output pins,
 *                Display ZERO on SEVEN SEGMENT DISPLAY
 * INPUTS       : void
 * RETURNS      : void
 **************************************************************************/
void SEVEN_SEGMENT_init(void);


/**************************************************************************
 * Function Name: SEVEN_SEGMENT_Display_Number
 * Description  : Display the input SECOND, MINUTE and HOUR Values on the
 *                SEVEN SEGMENTS DISPLAY
 * INPUTS       : Second, Minute and Hour
 * RETURNS      : void
 **************************************************************************/
void SEVEN_SEGMENT_Display_Number(uint8 Second,uint8 Minute,uint8 Hour);

#endif /* SEVEN_SEGMENT_H_ */
