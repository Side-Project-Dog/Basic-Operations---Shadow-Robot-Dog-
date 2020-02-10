
/*******************************************************************************
**  FILENAME     : USART.h       			                                  **
**  VERSION      : 1.0                                                        **
**  DATE         : 8 Feb 2020                                                 **
**  PLATFORM     : AVR		                                                  **
**  AUTHOR       : Esraa Awad & Nada Mohamed                                  **                                 
*******************************************************************************/
#ifndef USART_H_
#define USART_H_

/*********************************  Include Library ****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*************************** System Frequency *************************************************/
#ifndef F_CPU
#define F_CPU		8000000UL
#endif

typedef u8  Data_ReturnType;

/*********************** USART Registers **/
#define USART_UBRRH		*((volatile u8 *)0x40)
#define USART_UCSRC		*((volatile u8 *)0x40)
#define USART_UBRRL		*((volatile u8 *)0x29)
#define USART_UCSRA		*((volatile u8 *)0x2B)
#define USART_UCSRB		*((volatile u8 *)0x2A)
#define USART_UDR       *((volatile u8 *)0x2C)


/***************************** Masks *****************/
/* Writing this bit to one enables the USART Transmitter */
#define UCSRB_TXEN	 (u8)0x08
/* Writing this bit to one enables the USART Receiver */
#define UCSRB_RXEN	 (u8)0x10
/* This bit selects between accessing the UCSRC or the UBRRH Register. It is read as
   one when reading UCSRC. The URSEL must be one when writing the UCSRC*/
#define UCSRC_URSEL	 (u8)0x80
/* The UCSZ1:0 & UCSZ2 bits combined to set the number of data bits
   (Character Size) in a frame the Receiver and Transmitter use.*/
#define UCSRC_UCSZ0	 (u8)0x2
#define UCSRC_UCSZ1	 (u8)0x4


/************************************************** USART PINS number */
/*if UDRE is one, the buffer is empty, and therefore ready to be written*/
#define UCSRA_UDRE   (u8)0x20
/*This flag bit is set when there are unread data in the receive buffer
  and cleared when the receive buffer is empty */
#define UCSRA_RXC    (u8)0x80


/**** USART Configuration ****/

/* define baud */
#define BAUD      9600                                   

/* set baud rate value for UBRR */
#define BAUDRATE ( ( (F_CPU) / ( BAUD * 16UL ) )-1)   




/** Functions prototypes ***/
/* to initialize UART
 *  Return Type :- void
 *  input argument :- void
 *            
 */
void USART_u8UsartInitialize (void);


/* to transmit char of data
 *  Return Type :- void
 *  input argument :-
 *            Copy_u8Data :- the data 
 */
void USART_voidTransmitByte(u8 Copy_u8Data);

/* to receive char of data
 *  Return Type :- Data_ReturnType ( u8 ) return the data
 *  input argument :-  void
 *
 */
Data_ReturnType USART_u8RecieveByte(void);

#endif /* USART_H_ */
