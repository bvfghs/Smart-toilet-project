#include "svc_scheduler.h"
#include "bsp_systick.h"


volatile uint32_t g_events  = 0;

static SchedSlot_t s_slots[SCHED_MAX_SLOTS];/* 是一个包含 8 个 SchedSlot_t 元素的数组 调度器槽位  */
static uint8_t     s_slot_count = 0;/* 调度器槽位计数 */

/* ---- 软件定时器 ---- */

void SoftTimer_Start(SoftTimer_t *t, uint32_t ms)//启动软件定时器
{
    t->start_tick  = g_tick_ms;
    t->duration_ms = ms;
    t->running     = 1;
}

uint8_t SoftTimer_Expired(SoftTimer_t *t)//检查软件定时器是否超时
{
    if (!t->running) return 0;
    if ((g_tick_ms - t->start_tick) >= t->duration_ms) {
        t->running = 0;
        return 1;
    }
    return 0;
}

/* ---- 协作式调度器 ---- */

/**
 * @brief  初始化调度器，清空全部槽位
 * @note   在 main() 中先于 Sched_Register 调用；
 *         将 s_slot_count 归零，所有槽位的 handler 置空、
 *         period_ms 和 last_run 清零，使调度器回到无任务状态。
 */
void Sched_Init(void)
{
    s_slot_count = 0;
    for (uint8_t i = 0; i < SCHED_MAX_SLOTS; i++) {
        s_slots[i].handler   = (void *)0;
        s_slots[i].period_ms = 0;
        s_slots[i].last_run  = 0;
    }
}

/**
 * @brief  向调度器注册一个周期任务
 * @param  handler    任务回调函数（无参无返回值）
 * @param  period_ms  执行周期（ms）；0 表示每轮 Sched_Run 都执行
 * @retval 1 注册成功，0 槽位已满（上限 SCHED_MAX_SLOTS = 8）
 * @note   注册顺序决定 Sched_Run 中的执行顺序；
 *         last_run 初始化为 0，保证首次满足 (now - 0) >= period_ms 时即执行；
 *         不支持注销，s_slot_count 单调递增。
 *         在 main.c 中注册了 Safety_Poll(10ms)、Scale_Poll(每轮)、
 *         Sensor_Poll(100ms)、Protocol_Poll(每轮)、
 *         App_Nursing_Poll(50ms)、HMI_Poll(500ms) 共 6 个任务。
 
 */
uint8_t Sched_Register(void (*handler)(void), uint32_t period_ms)    //
{
    if (s_slot_count >= SCHED_MAX_SLOTS) return 0;
    s_slots[s_slot_count].handler   = handler;
    s_slots[s_slot_count].period_ms = period_ms;
    s_slots[s_slot_count].last_run  = 0;
    s_slot_count++;
    return 1;
}
//--------------------------------------------------------
// 调用 1: Sched_Register(Safety_Poll, 10)
//     s_slot_count: 0 -> 1
//     s_slots[0] = {Safety_Poll, 10, 0}
// 调用 2: Sched_Register(Scale_Poll, 0)
//     s_slot_count: 1 -> 2
//     s_slots[1] = {Scale_Poll, 0, 0}
//----------------------------------------------------------



/**
 * @brief  调度器主循环体，在 main() 的 while(1) 中反复调用
 * @note   遍历所有已注册槽位：
 *         - handler 为空则跳过；
 *         - period_ms == 0：每次都执行；
 *         - period_ms > 0：比较 (now - last_run) >= period_ms，
 *           满足时更新 last_run 并调用 handler。
 *         时基 g_tick_ms 由 SysTick 中断每 1ms 累加（bsp_systick.c）。
 */
void Sched_Run(void)
{
    uint32_t now = g_tick_ms;
    for (uint8_t i = 0; i < s_slot_count; i++) {    //遍历所有已注册槽位
        SchedSlot_t *s = &s_slots[i];             //s 是一个指向 SchedSlot_t 结构体的指针，指向 s_slots 数组中的第 i 个元素
        if (s->handler == (void *)0) continue;    //如果 s->handler 为空，则跳过

        if (s->period_ms == 0) {                  //如果 s->period_ms 为 0，则每次都执行
            s->handler();                         //调用 s->handler 函数
        } else if ((now - s->last_run) >= s->period_ms) {  //如果 (now - s->last_run) >= s->period_ms，则更新 s->last_run 并调用 s->handler 函数
            s->last_run = now;                    //更新 s->last_run
            s->handler();                         //调用 s->handler 函数
        }
    }
}

/**
 * @brief  获取当前系统节拍（ms）
 * @retval g_tick_ms 的快照，由 SysTick 中断驱动每 1ms 递增
 */
uint32_t Sched_GetTick(void)
{
    return g_tick_ms;
}
