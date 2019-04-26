
#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_rtc.h"
#include "lpc17xx_uart.h"

#include "HardwareInit.h"
#include "Delay_RIT.h"

#include <stdio.h>

int main()
{
	uint8_t bufferUart[50];
	uint8_t lenBuf=0;
	HW_Init();
	
	HW_SetDateTime();
	Delay_RIT_ms(500);
	
	RTC_TIME_Type timeDate;
	
	while(1)
	{
		Delay_RIT_ms(1000);
		RTC_GetFullTime(LPC_RTC,&timeDate);
	  lenBuf = sprintf(bufferUart,"Time: %02u:%02u:%02u\n",timeDate.HOUR,timeDate.MIN,timeDate.SEC);
	  UART_Send(LPC_UART2,bufferUart,lenBuf,BLOCKING);
		lenBuf = sprintf(bufferUart,"Date: %04u:%02u:%02u\n",timeDate.YEAR,timeDate.MONTH,timeDate.DOM);
	  UART_Send(LPC_UART2,bufferUart,lenBuf,BLOCKING);
		
	}
}
