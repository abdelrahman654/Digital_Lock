﻿/*
 * Lcd.h
 *
 * Created: 05/06/2023 09:22:35 م
 *  Author: ascom
 */ 


#ifndef LCD_H_
#define LCD_H_
/*************************************************_INCLUDES_********************************************/
#include "LcdCfg.h"
#include "Dio.h"
#include "StdTypes.h"
#include <math.h> 
#define F_CPU 16000000UL
#include <util/delay.h>
/**************************************************_MACROS_*********************************************/
#define _8_BIT_MODE                     1
#define _4_BIT_MODE                     2
#define LCD_8_BIT_MODE                  0x38
#define LCD_4_BIT_MODE_1                0x33
#define LCD_4_BIT_MODE_2                0x32
#define LCD_4_BIT_MODE_3                0x28
#define LCD_DISPLAY_ON_CURSUR_OFF       0x0C
#define LCD_CLEAR                       0x01
#define LCD_RETURN_HOME                 0x02
#define LCD_SHIFT_RIGHT                 0x05
#define LCD_SHIFT_LEFT                  0x07
#define MOVE_TO_SECOND_LINE             0xC1
#define DISPLAY_ON_CURSOR_BLINKING      0x0E
#define NULL_                           '\0'
/************************************************_PROTOTYPES_********************************************/
void H_Lcd_Init(void);
void H_Lcd_WriteCharacter(u8);
void H_Lcd_WriteCommand(u8);
void H_Lcd_WriteString(u8*);
void H_Lcd_WriteNumber(s32);
void H_Lcd_WriteFloat(f32,u8);
void H_Lcd_Clr(void);
void H_Lcd_GoTo(u8,u8);
void H_Lcd_ShiftRight(void);
void H_Lcd_ShiftLeft(void);




#endif /* LCD_H_ */