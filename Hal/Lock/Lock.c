/*
 * Lock.c
 *
 * Created: 06/07/2023 01:00:30 ص
 *  Author: ascom
 */ 
#include "Lock.h"

void H_Lock_Init(void)
{
	M_Dio_PinMode(LOCK_ON_PIN,OUTPUT);
	M_Dio_PinMode(LOCK_OFF_PIN,OUTPUT);
}
void H_Lock_On(void)
{
	M_Dio_PinWrite(LOCK_ON_PIN,HIGH);
	_delay_ms(500);
	M_Dio_PinWrite(LOCK_ON_PIN,LOW);
}
void H_Lock_Off(void)
{
	M_Dio_PinWrite(LOCK_OFF_PIN,HIGH);
	_delay_ms(500);
	M_Dio_PinWrite(LOCK_OFF_PIN,LOW);
}