#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H

#include <stdint.h>

uint32_t BSP_GetTick(void);      // 返回系统启动后的毫秒数
void BSP_DelayMs(uint32_t ms);   // 阻塞延时（可选）

#endif
