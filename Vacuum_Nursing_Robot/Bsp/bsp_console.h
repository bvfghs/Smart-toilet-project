#ifndef __BSP_CONSOLE_H
#define __BSP_CONSOLE_H

#include <stdint.h>

void BSP_Console_Init(void);
void BSP_Console_SendChar(uint8_t ch);

#endif
