#include "bsp_console.h"
#include "usart.h"               // 包含 huart3 声明
#include <stdio.h>


//调试用程序，主要将printf重定向到huart3


/* 重定向 printf 到 USART3 */
int fputc(int ch, FILE *f) {
    HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

void BSP_Console_Init(void) {
    // USART3 已在 MX_USART3_UART_Init() 中初始化，
    // 这里可添加额外配置，如清缓冲区等。
}

void BSP_Console_SendChar(uint8_t ch) {
    HAL_UART_Transmit(&huart3, &ch, 1, HAL_MAX_DELAY);
}
