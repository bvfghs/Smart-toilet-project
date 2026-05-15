#ifndef __APP_FLOW_MANAGER_H
#define __APP_FLOW_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

/* ---------- 步骤结构 ---------- */
typedef struct {
    uint32_t duration_sec;          // 本步骤持续时间（秒）
    const char *desc;               // 步骤描述
    void (*on_enter)(void);         // 进入步骤时执行
    void (*on_exit)(void);          // 退出步骤时执行（可为NULL）
} FlowStep_t;

/* ---------- 流程定义结构 ---------- */
typedef struct {
    const char *name;               // 流程名称（调试用）
    const FlowStep_t *steps;        // 步骤数组（以duration_sec==0的步骤作为结束标记）
    void (*on_finished)(void);      // 整个流程结束时的回调（用于复位按钮等）
} FlowDef_t;

/* ---------- 公开 API ---------- */
void FlowManager_Init(void);                        // 初始化管理器
bool FlowManager_Start(const FlowDef_t *flow);      // 启动指定流程（若空闲则启动，返回true）
void FlowManager_Stop(void);                        // 强制停止当前流程（关闭所有设备）
bool FlowManager_IsActive(void);                    // 是否有流程正在运行
uint8_t FlowManager_GetCurrentStepIndex(void);      // 当前步骤序号（0-based, 用于显示+1）
uint32_t FlowManager_GetTimeLeft(void);              // 当前步骤剩余秒数
const char* FlowManager_GetStepDesc(void);           // 当前步骤描述
void FlowManager_Tick(void);                         // 每秒调用（由调度器驱动）

#endif
