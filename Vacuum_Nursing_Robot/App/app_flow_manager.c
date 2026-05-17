#include "app_flow_manager.h"
#include "bsp_actuator.h"    // 设备控制
#include <stddef.h>

/* ---------- 当前运行状态 ---------- */
static const FlowDef_t *s_current_flow = NULL;   // 当前运行的流程
static const FlowStep_t *s_current_step = NULL;   // 当前步骤指针
static uint32_t s_remaining_sec = 0;              // 当前步骤剩余秒数
static uint8_t s_step_index = 0;                  // 当前步骤索引（0,1,2...）

/* ---------- 私有函数：停止当前步骤（调用on_exit） ---------- */
static void stop_current_step(void) {
    if (s_current_step != NULL && s_current_step->on_exit != NULL) {
        s_current_step->on_exit();
    }
}

/* ---------- 私有函数：开始执行新步骤 ---------- */
static void start_step(const FlowStep_t *step, uint8_t idx) {
    // 先退出之前的步骤（如果存在）
    if (s_current_step != NULL && s_current_step != step) {
        stop_current_step();
    }

    s_current_step = step;
    s_step_index = idx;
    s_remaining_sec = (step->duration_sec > 0) ? step->duration_sec : 0;

    if (step->on_enter != NULL) {
        step->on_enter();
    }
}

/* ---------- 私有函数：结束整个流程 ---------- */
static void finish_flow(void) {
    // 退出当前步骤
    if (s_current_step != NULL) {
        stop_current_step();
    }

    // 关闭所有执行器（安全）
    Actuator_AllOff();

    // 调用流程完成回调（例如复位按钮）
    if (s_current_flow != NULL && s_current_flow->on_finished != NULL) {
        s_current_flow->on_finished();
    }

    // 清空状态
    s_current_flow = NULL;
    s_current_step = NULL;
    s_remaining_sec = 0;
    s_step_index = 0;
}

/* ---------- API 实现 ---------- */
void FlowManager_Init(void) {
    s_current_flow = NULL;
    s_current_step = NULL;
    s_remaining_sec = 0;
    s_step_index = 0;
    Actuator_AllOff();   // 初始确保所有设备关闭
}

bool FlowManager_Start(const FlowDef_t *flow) {
    if (flow == NULL) return false;
    if (s_current_flow != NULL) return false;   // 已有流程运行

    // 检查流程至少有一个有效步骤（第一个步骤duration_sec>0）
    if (flow->steps == NULL || flow->steps[0].duration_sec == 0) {
        return false;   // 无效流程定义
    }

    s_current_flow = flow;
    // 从第一个步骤开始
    start_step(&flow->steps[0], 0);
    return true;
}

void FlowManager_Stop(void) {
    if (s_current_flow != NULL) {
        finish_flow();
    }
}

bool FlowManager_IsActive(void) {
    return (s_current_flow != NULL);
}

uint8_t FlowManager_GetCurrentStepIndex(void) {
    return s_step_index;   // 0-based，显示时可+1
}

uint32_t FlowManager_GetTimeLeft(void) {
    return s_remaining_sec;
}

const char* FlowManager_GetStepDesc(void) {
    if (s_current_step == NULL) return "空闲";
    return s_current_step->desc;
}

void FlowManager_Tick(void) {
    if (s_current_flow == NULL || s_current_step == NULL) {
        return;
    }

    // 减少剩余时间
    if (s_remaining_sec > 0) {
        s_remaining_sec--;
    }

    // 当前步骤时间到 → 进入下一步
    if (s_remaining_sec == 0) {
        // 查找下一步骤（步骤数组中的下一个）
        const FlowStep_t *next_step = s_current_step + 1;
        // 判断是否结束：duration_sec == 0 表示结束标记
        if (next_step->duration_sec == 0) {
            finish_flow();   // 流程结束
        } else {
            start_step(next_step, s_step_index + 1);
        }
    }
}

//读取当前工作流程的名称
const char* FlowManager_GetCurrentFlowName(void) {
    if (s_current_flow == NULL) return "空闲";
    return s_current_flow->name;
}