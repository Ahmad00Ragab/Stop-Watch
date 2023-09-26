/*===========================================================================================
 * Filename   : External_Interrupts.h
 * Author     : Ahmad Haroun
 * Description: header file the Externa_Interrupts Driver
 * Created on : Jun 12, 2023
 *==========================================================================================*/

#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

#include "gpio.h"
#include <avr/interrupt.h>         /* To include the Prototype for each ISR */

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	FALLING_INTERRUPT,
	RAISING_INTERRUPT,
}EDGE_TYPE;


/*******************************************************************************
 *                               Global_Variables Declaration                  *
 *******************************************************************************/

/********************************************************************************
 * Global Array of 3 pointers to function
 * 1.static to use in this file and hold his value
 * 2.volatile to use in ISRs function and in the function 'External_Interrupt_set_CallBac'
 * 3.Initial value with Null or use NULL_Ptr in standard_types
 * EXTERNAL INT0  : INDEX 0
 * EXTERNAL INT1  : INDEX 1
 * EXTERNAL INT2  : INDEX 2
 *********************************************************************************/
static volatile void (*Ex_Interrupt_CallBack_Array[3])(void) = {NULL_PTR};



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/**************************************************************************
 * Function Name: INT0_init
 * Description  : Initialization Function for Interrupt 0
 * INPUT        : EDGE_TYPE
 * RETURNS      : void
 **************************************************************************/
void INT0_init(EDGE_TYPE EDGE);


/**************************************************************************
 * Function Name: INT1_init
 * Description  : Initialization Function for Interrupt 1
 * INPUT        : EDGE_TYPE
 * RETURNS      : void
 **************************************************************************/
void INT1_init(EDGE_TYPE EDGE);


/**************************************************************************
 * Function Name: INT2_init
 * Description  : Initialization Function for Interrupt 2
 * INPUT        : EDGE_TYPE
 * RETURNS      : void
 **************************************************************************/
void INT2_init(EDGE_TYPE EDGE);


/**********************************************************************************
 * Function Name: External_Interrupt_set_CallBack
 * Description  : A Function to set the callBack function for each external interrupt
 * INPUTS       : ptr_2_fun,index(which indicates which ISR would be Executed)
 * RETURNS      : void
 **********************************************************************************/
void External_Interrupt_set_CallBack(void(*ptr_2_fun)(void),uint8 index);


#endif /* EXTERNAL_INTERRUPTS_H_ */
