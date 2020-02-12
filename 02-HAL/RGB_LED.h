/*
 * RGB_LED.h

 *
 *  Created on: Feb 12, 2020
 *      Author: Esraa Awad
 */

#ifndef RGB_LED_H_
#define RGB_LED_H_

/** Configure RGB PORTS and PINS **/


#define RED_PORT	'A'
#define RED_PIN		 0

#define GREEN_PORT	'A'
#define GREEN_PIN	 1


#define BLUE_PORT	'A'
#define BLUE_PIN	 2



/** Colors **/
#define RED		1
#define GREEN 	2
#define BLUE	3



/** this API shall control Shadow`s Eye
 * it takes one Arguments :-
 * 1-RED
 * 2-GREEN
 * 3-BLUE
 */
void RGB_voidSetEyeColor (u8 Copy_u8Color);


#endif /* RGB_LED_H_ */
