#include "HardwareInit.h"

#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include <lpc17xx_uart.h>
#include <lpc17xx_rtc.h>

#include <Delay_RIT.h>

void HW_Init()
{
	// pinsel difenation for TXD2, port0.10
	PINSEL_CFG_Type usartPin;
	usartPin.Funcnum   = PINSEL_FUNC_1;
	usartPin.OpenDrain = PINSEL_PINMODE_NORMAL;
	usartPin.Pinmode   = PINSEL_PINMODE_TRISTATE;
	usartPin.Pinnum    = PINSEL_PIN_10;
	usartPin.Portnum   = PINSEL_PORT_0;
	PINSEL_ConfigPin(&usartPin);
	
	// pinsel difenation for RXD2, port0.11
	usartPin.Pinnum    = PINSEL_PIN_11;
	PINSEL_ConfigPin(&usartPin);	
	Delay_RIT_Init();
  
	// UART prepheral init
	UART_CFG_Type UartInint;
	UartInint.Baud_rate = 115200;
	UartInint.Databits  = UART_DATABIT_8;
	UartInint.Parity    = UART_PARITY_NONE;
	UartInint.Stopbits  = UART_STOPBIT_1;
	UART_Init(LPC_UART2,&UartInint);
	UART_TxCmd(LPC_UART2,ENABLE);
	
	// RTC
  RTC_Init(LPC_RTC);
	RTC_ResetClockTickCounter(LPC_RTC);
	RTC_Cmd(LPC_RTC,ENABLE);
	RTC_CalibCounterCmd(LPC_RTC,DISABLE);
}

void HW_SetDateTime()
{
	RTC_SetTime(LPC_RTC,RTC_TIMETYPE_SECOND,0);
	RTC_SetTime(LPC_RTC,RTC_TIMETYPE_MINUTE,0);
	RTC_SetTime(LPC_RTC,RTC_TIMETYPE_HOUR,0);
	
	RTC_SetTime(LPC_RTC,RTC_TIMETYPE_DAYOFMONTH,1);
	RTC_SetTime(LPC_RTC,RTC_TIMETYPE_MONTH,1);
	RTC_SetTime(LPC_RTC,RTC_TIMETYPE_YEAR,2018);
	
}
