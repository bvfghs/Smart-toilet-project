#ifndef __APP_TASKS_H
#define __APP_TASKS_H

void HMI_ProcessTask(void);
// 其他任务声明...

void RefreshFlowStepTimes(uint16_t screen_id, const FlowDef_t* flow, uint16_t start_id, uint8_t step_count); //刷新指定流程的步骤时间到串口屏的文本控件
 void RefreshAllScreensData(void);//刷新全部流程的步骤时间到串口屏的文本控件

#endif