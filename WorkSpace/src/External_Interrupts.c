/*===========================================================================================
 * Filename   : External_Interrupts.c
 * Author     : Ahmad Haroun
 * Description: Source file the Externa_Interrupts Driver
 * Created on : Jun 12, 2023
 *==========================================================================================*/

#include "External_Interrupts.h"


/*******************************************************************************
 *                              Functions Definitions                          *
 *******************************************************************************/


/**************************************************************************
 * Function Name: ISR (INTERRUPT HANDLER FOR INT0)
 * Description  : Call the Function that is required to be Executed when INT0 happens
 **************************************************************************/
ISR(INT0_vect)
{
	(*Ex_Interrupt_CallBack_Array[0])();
}


/**************************************************************************
 * Function Name: ISR (INTERRUPT HANDLER FOR INT1)
 * Description  : Call the Function that is required to be Executed when INT1 happens
 **************************************************************************/
ISR(INT1_vect)
{
	(*Ex_Interrupt_CallBack_Array[1])();
}



/**************************************************************************
 * Function Name: ISR (INTERRUPT HANDLER FOR INT2)
 * Description  : Call the Function that is required to be Executed when INT2 happens
 **************************************************************************/
ISR(INT2_vect)
{
	(*Ex_Interrupt_CallBack_Array[2])();
}




/**************************************************************************
 * Function Name: INT0_init
 * Description  : Initialization Function for Interrupt 0
 * INPUT        : EDGE_TYPE
 * RETURNS      : void
 **************************************************************************/
void INT0_init(EDGE_TYPE EDGE)
{
	GPIO_setupPinDirection(PORTD_ID, PIN2_ID, PIN_INPUT); /* set PD2 input pin */
	if(EDGE == FALLING_INTERRUPT)
	{
		SET_BIT(MCUCR,ISC01);  /* Make INT0 happen with Falling Edge */

	}
	else if(EDGE == RAISING_INTERRUPT)
	{
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);  /* Make INT0 happen with Raising Edge */
	}
	SET_BIT(GICR,INT0);    /* Enable INT0 */
	SET_BIT(SREG,7); /* Enable Global Interrupt Enable */
}

/**************************************************************************
 * Function Name: INT1_init
 * Description  : Initialization Function for Interrupt 1
 * INPUT        : EDGE_TYPE
 * RETURNS      : void
 **************************************************************************/
void INT1_init(EDGE_TYPE EDGE)
{
	GPIO_setupPinDirection(PORTD_ID, PIN3_ID, PIN_INPUT); /* set PD2 input pin */
	if(EDGE == FALLING_INTERRUPT)
	{
		SET_BIT(MCUCR,ISC11);  /* Make INT1 happen with Falling Edge */

	}
	else if(EDGE == RAISING_INTERRUPT)
	{
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);  /* Make INT0 happen with Raising Edge */
	}
	SET_BIT(GICR,INT1);        /* Enable INT1 */
	SET_BIT(SREG,7);           /* Enable Global Interrupt Enable */
}


/**************************************************************************
 * Function Name: INT2_init
 * Description  : Initialization Function for Interrupt 2
 * INPUT        : EDGE_TYPE
 * RETURNS      : void
 **************************************************************************/
void INT2_init(EDGE_TYPE EDGE)
{
	GPIO_setupPinDirection(PORTB_ID, PIN2_ID, PIN_INPUT); /* set PD2 input pin */
	if(EDGE == FALLING_INTERRUPT)
	{
		CLEAR_BIT(MCUCSR,ISC2);
	}
	else if(EDGE == RAISING_INTERRUPT)
	{
		SET_BIT(MCUCSR,ISC2);    /* Make INT2 happen with Raising Edge */
	}
	SET_BIT(GICR,INT2);          /* Make INT1 happen with Raising Edge */

	SREG   |= (1<<7);            /* Enable interrupts by setting I-bit */
}



/**********************************************************************************
 * Function Name: External_Interrupt_set_CallBack
 * Description  : A Function to set the callBack function for each external interrupt
 * INPUTS       : ptr_2_fun,index(which indicates which ISR would be Executed)
 * RETURNS      : void
 **********************************************************************************/
void External_Interrupt_set_CallBack(void(*ptr_2_fun)(void),uint8 index)
{
	Ex_Interrupt_CallBack_Array[index] = ptr_2_fun;
}
