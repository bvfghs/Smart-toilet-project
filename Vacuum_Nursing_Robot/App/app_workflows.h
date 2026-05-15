#ifndef __APP_WORKFLOWS_H
#define __APP_WORKFLOWS_H

#include "app_flow_manager.h"

// 声明各个流程（外部引用）
extern const FlowDef_t Flow_Defecate;   // 大便冲洗
extern const FlowDef_t Flow_Urinate;    // 小便冲洗
extern const FlowDef_t Flow_Clean;      // 清洗模式
extern const FlowDef_t Flow_Dry;       // 干燥模式
extern const FlowDef_t Flow_CleanAir;  // 空气清洁模式

// 提供流程结束时的回调（用于复位按钮）
void Flow_OnFinished_Defecate(void); // 大便冲洗结束回调
void Flow_OnFinished_Urinate(void);   // 小便冲洗结束回调
void Flow_OnFinished_Clean(void);    // 清洁模式结束回调
void Flow_OnFinished_Dry(void);      // 干燥模式结束回调
void Flow_OnFinished_CleanAir(void);  // 空气清洁模式结束回调
	
/* ---------- 通用：动态修改任意流程的步骤时间 ---------- */
bool Flow_SetStepDuration(const FlowDef_t* flow, uint8_t step_idx, uint32_t seconds);//写工作流程步骤时间 flow工作流程，step_idx步骤序号，seconds步骤秒数
uint32_t Flow_GetStepDuration(const FlowDef_t* flow, uint8_t step_idx);//读工作流程步骤时间 flow工作流程，step_idx步骤序号

#endif
