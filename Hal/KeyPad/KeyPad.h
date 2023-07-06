/*
 * KeyPad.h
 *
 * Created: 06/06/2023 09:04:24 م
 *  Author: ascom
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
/*************************************************_INCLUDES_********************************************/
#include "KeyPadCfg.h"
#include "StdTypes.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/**************************************************_MACROS_*********************************************/
#define KEYPAD_PRESSED     0
#define KEYPAD_RELEASED    1
#define TYPE_1             1
#define TYPE_2             2
/************************************************_PROTOTYPES_********************************************/
void H_KeyPad_Init(void);
u8   H_KeyPad_Read(void);




#endif /* KEYPAD_H_ */