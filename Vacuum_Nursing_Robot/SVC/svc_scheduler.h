#ifndef __SVC_SCHEDULER_H
#define __SVC_SCHEDULER_H
#include "main.h"

/* ---- 事件标志 ---- */
#define EVT_EMERGENCY_STOP    (1U << 0)
#define EVT_UART_BLE_FRAME    (1U << 1)
#define EVT_UART_SCALE_FRAME  (1U << 2)
#define EVT_UART_HMI_FRAME    (1U << 3)
#define EVT_UART_VOICE_FRAME  (1U << 4)

extern volatile uint32_t g_events;

static inline void    Event_Set(uint32_t mask)   { g_events |= mask;  }
static inline void    Event_Clear(uint32_t mask) { g_events &= ~mask; }
static inline uint8_t Event_Test(uint32_t mask)  { return (g_events & mask) != 0; }

/* ---- 软件定时器 ---- */
typedef struct {
    uint32_t start_tick;       //开始时间
    uint32_t duration_ms;      //持续时间
    uint8_t  running;          //运行状态
} SoftTimer_t;

void    SoftTimer_Start(SoftTimer_t *t, uint32_t ms);
uint8_t SoftTimer_Expired(SoftTimer_t *t);

/* ---- 协作式调度器 ---- */
#define SCHED_MAX_SLOTS  8

typedef struct {
    void (*handler)(void);
    uint32_t period_ms;
    uint32_t last_run;
} SchedSlot_t;

void     Sched_Init(void);//初始化调度器，清空全部槽位
uint8_t  Sched_Register(void (*handler)(void), uint32_t period_ms);//向调度器注册一个周期任务,period_ms按毫秒给执行周期
void     Sched_Run(void);//调度器主循环体，在 main() 的 while(1) 中反复调用
uint32_t Sched_GetTick(void);//获取当前系统节拍（ms）

/* ---- 10ms 节拍（TIM6 ISR 中递增） ---- */
extern volatile uint32_t g_tick_ms;

#endif
