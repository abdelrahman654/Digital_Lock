/*
 * Led.c
 *
 * Created: 06/07/2023 01:01:42 ص
 *  Author: ascom
 */ 
#include "Led.h"

void H_Led_Init(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case LED0: M_Dio_PinMode(LED0_PIN,OUTPUT);break;
		case LED1: M_Dio_PinMode(LED1_PIN,OUTPUT);break;
		default:                                  break;
	}
}
void H_Led_On(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case LED0: M_Dio_PinWrite(LED0_PIN,HIGH);break;
		case LED1: M_Dio_PinWrite(LED1_PIN,HIGH);break;
		default:                                 break;
	}
}
void H_Led_Off(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case LED0: M_Dio_PinWrite(LED0_PIN,LOW);break;
		case LED1: M_Dio_PinWrite(LED1_PIN,LOW);break;
		default:                                break;
	}
}