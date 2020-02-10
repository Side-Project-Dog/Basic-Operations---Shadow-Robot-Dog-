
/*******************************************************************************
**  FILENAME     : USART.c     			                                      **
**  VERSION      : 1.0                                                        **
**  DATE         : 8 Feb 2020                                                 **
**  PLATFORM     : AVR		                                                  **
**  AUTHOR       : Esraa Awad & Nada Mohamed                                  **                                 
*******************************************************************************/

#include "USART.h"



/**** This  API to initialize UART ************************************************************/
void USART_u8UsartInitialize (void)
{


	/**** set baud rate  ***/
	/*The UBRRH contains the four most significant bits,
	 *the UBRRL contains the 8 least significant bits of the USART baud rate.*/
	USART_UBRRH = (BAUDRATE >>8);        // 3 bits MSB on high REG
	USART_UBRRL = (u8)BAUDRATE ;         // 8 bits LSB on low REG


	/* UCSRB_RXEN  -> Writing this bit to one enables the USART Receiver.
	 * UCSRB_TXEN  -> Writing this bit to one enables the USART Transmitter. */
	USART_UCSRB |= UCSRB_TXEN | UCSRB_RXEN ;

	/* UCSRC_URSEL -> This bit selects between accessing the UCSRC or the UBRRH Register. It is read as
	                  one when reading UCSRC. The URSEL must be one when writing the UCSRC.
	  The UCSZ1:0  -> bits combined with the UCSZ2 bit in UCSRB sets the number of data bits
                      (Character Size) in a frame the Receiver and Transmitter us
                       UCSRC_UCSZ0 =1  &  UCSRC_UCSZ1	=1 (Character Size =8 bit)*/
	USART_UCSRC	|= UCSRC_URSEL  | UCSRC_UCSZ0 | UCSRC_UCSZ1	;



}

/*******************************************************************************************/
/* to transmit char of data
 *  Return Type :- void
 *  input argument :-
 *            Copy_u8Data :- the data
 */
void USART_voidTransmitByte(u8 Copy_u8Data)
{

	/* wait transmit buffer to be empty */
	while( !(USART_UCSRA & (UCSRA_UDRE)));
	/* Put the data into the buffer */
	USART_UDR = Copy_u8Data;
}

/******************************************************************************************/
/* to receive char of data
 *  Return Type :- Data_ReturnType ( u8 )
 *  input argument :-  void
 *
 */
Data_ReturnType USART_u8RecieveByte(void)
{

	/* wait data to be received */
	while( !(USART_UCSRA & UCSRA_RXC));

	/* return data from the buffer */
	return USART_UDR;
}
/*******************************************************************************************/
