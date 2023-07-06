/*
 * DigitalLock.c
 *
 * Created: 05/07/2023 08:51:25 م
 * Author : ascom
 */ 

//#include <avr/io.h>
#include "StdTypes.h"
#include "BitMath.h"
#include "Lcd.h"
#include "KeyPad.h"
#include "Eeprom.h"
#include "Lock.h"
#include "Led.h"
#define F_CPU 16000000UL
#include <util/delay.h>


//PassWord -> [123]

u8 SystemStateFlag = 0;
u8 Counter = 0;
u8 PassArr[3];
u8 PassEntered = 0;
u8 PassReading = 0;



int main(void)
{
	H_Eeprom_Init();
	H_Lcd_Init();
	H_KeyPad_Init();
	H_Led_Init(LED0);
	H_Led_Init(LED1);
	H_Lock_Init();
	u8 Local_u8_KeyPadReading = 0;
    while (1) 
    {
		Local_u8_KeyPadReading = H_KeyPad_Read();
		if(Local_u8_KeyPadReading != 0)
		{
			if(Local_u8_KeyPadReading == 'C')
			{
				SystemStateFlag ^= 1;
				if(SystemStateFlag == 1)
				{
					H_Lcd_WriteString("Enter The Pass");
					H_Lcd_WriteCommand(MOVE_TO_SECOND_LINE);
					H_Lcd_WriteCommand(DISPLAY_ON_CURSOR_BLINKING);
				}
			}
			if(SystemStateFlag == 1)
			{
				if(Local_u8_KeyPadReading != 'C')
				{
					if(Counter <= 3)
					{
						PassArr[Counter] = Local_u8_KeyPadReading;
						H_Lcd_WriteCharacter('*');
						Counter++;
						if(Counter == 3)
						{
							PassEntered = (u16)(PassArr[0]*100 + PassArr[1]*10 + PassArr[2]*1);
							PassReading = H_Eeprom_Read(0x0000);
							if(PassEntered != PassReading)
							{
								H_Lcd_Clr();
								H_Lcd_WriteString("Access Denied");
								H_Led_On(LED1);
								_delay_ms(500);
								H_Led_Off(LED1);
								_delay_ms(500);
								H_Led_On(LED1);
								_delay_ms(500);
								H_Led_Off(LED1);
								H_Lcd_Clr();
								H_Lcd_WriteString("Enter The Pass");
								H_Lcd_WriteCommand(MOVE_TO_SECOND_LINE);
								H_Lcd_WriteCommand(DISPLAY_ON_CURSOR_BLINKING);
								Counter = 0;
							}
							else if(PassEntered == PassReading)
							{
								H_Lcd_Clr();
								H_Lcd_WriteString("Accepted");
								H_Led_On(LED0);
								H_Lock_On();
								_delay_ms(3000);
								H_Led_Off(LED0);
								H_Lock_Off();
								H_Lcd_Clr();
								H_Lcd_WriteCommand(LCD_DISPLAY_ON_CURSUR_OFF);
								Counter = 0;
								SystemStateFlag = 0;
							}
						}
					}
				}
			}
			else if(SystemStateFlag == 0)
			{
				H_Lcd_Clr();
			}
		}
    }
}

