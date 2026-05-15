#include "bsp_systick.h"
#include "main.h"                // 如果需要 HAL 定义

volatile uint32_t g_tick_ms = 0;

void HAL_SYSTICK_Callback(void) {
    g_tick_ms++;
}

uint32_t BSP_GetTick(void) {
    return g_tick_ms;
}

void BSP_DelayMs(uint32_t ms) {
    uint32_t start = BSP_GetTick();
    while ((BSP_GetTick() - start) < ms);
}
