#ifndef HardwareInit_H_
#define HardwareInit_H_

#include <stdint.h>

void HW_Init(void);
void HW_SetDateTime(void);
void HW_SetTime(uint8_t second,uint8_t minute,uint8_t hour);
void HW_SetDate(uint8_t DayOfMonth,uint8_t Month,uint16_t Year);

#endif
