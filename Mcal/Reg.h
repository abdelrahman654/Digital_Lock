﻿/*
 * Reg.h
 *
 * Created: 04/06/2023 10:22:24 ص
 *  Author: ascom
 */ 


#ifndef REG_H_
#define REG_H_
#include "StdTypes.h"
/*********************************************************_DIO_REGISTERS_**********************************/
#define PINA          *(volatile u8*)0x39
#define DDRA          *(volatile u8*)0x3A
#define PORTA         *(volatile u8*)0x3B
#define PINB          *(volatile u8*)0x36
#define DDRB          *(volatile u8*)0x37
#define PORTB         *(volatile u8*)0x38
#define PINC          *(volatile u8*)0x33
#define DDRC          *(volatile u8*)0x34
#define PORTC         *(volatile u8*)0x35
#define PIND          *(volatile u8*)0x30
#define DDRD          *(volatile u8*)0x31
#define PORTD         *(volatile u8*)0x32
/*********************************************************_SREG_REGISTER_**********************************/
#define SREG          *(volatile u8*)0x5F
/********************************************************_I2C_REGISTERS_**********************************/
#define TWBR          *(volatile u8*)0x20
#define TWAR          *(volatile u8*)0x22
#define TWCR          *(volatile u8*)0x56
#define TWDR          *(volatile u8*)0x23
#define TWSR          *(volatile u8*)0x21


#endif /* REG_H_ */