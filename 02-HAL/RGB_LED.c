/*
 * RGB_LED.c
 *
 *  Created on: Feb 12, 2020
 *      Author: pc
 */


#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "port_interface.h"
#include "DIO_interface.h"
#include "RGB_LED.h"



void RGB_voidSetEyeColor (u8 Copy_u8Color)
{

	switch (Copy_u8Color)
	{

	case RED:
		DIO_voidSetpinValue(RED_PORT,RED_PIN,1); break;

	case GREEN:
		DIO_voidSetpinValue(GREEN_PORT,GREEN_PORT,1); break;
	case BLUE:
		DIO_voidSetpinValue(BLUE_PORT,BLUE_PIN,1); break;
	}


}
