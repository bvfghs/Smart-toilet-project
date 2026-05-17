#include "svc_scheduler.h"
#include "hmi.h"
#include "cmd_queue.h"
#include "hmi_driver.h"
#include "app_flow_manager.h"
#include "app_workflows.h"
#include <stdio.h>

 volatile qsize  size;
 
/**
 * @brief  HMI 指令处理任务（由调度器每轮调用）
 */
void HMI_ProcessTask(void)//此处为单片机处理接受的串口信息的任务，主循环中每次都调用
{

    size = queue_find_cmd(cmd_buffer, CMD_MAX_SIZE);
    if (size > 0) {
        if (cmd_buffer[1] != 0x07) {
            ProcessMessage((PCTRL_MSG)cmd_buffer, size);
            // printf("get data\r\n");  // 可保留用于调试
        } else {
            __disable_irq();
            NVIC_SystemReset();
        }
    }
}

/**
 * @brief 刷新指定流程的步骤时间到串口屏的文本控件
 * @param screen_id  画面ID
 * @param flow       流程指针（&Flow_Defecate, &Flow_Urinate 等）
 * @param start_id   第一个步骤对应的控件ID
 * @param step_count 步骤数量（必须与实际步骤数一致）
 */
void RefreshFlowStepTimes(uint16_t screen_id, const FlowDef_t* flow, uint16_t start_id, uint8_t step_count) {
    char buf[12];
    for (uint8_t i = 0; i < step_count; i++) {
        uint32_t sec = Flow_GetStepDuration(flow, i);
        sprintf(buf, "%lu", sec);
        SetTextValue(screen_id, start_id + i, (uint8_t*)buf);
    }
}

//刷新全部流程的步骤时间到串口屏的文本控件
 void RefreshAllScreensData(void) {
    // 画面10：设置画面，控件ID分配如下：
    // 大便流程：22步，起始控件ID 7
    RefreshFlowStepTimes(4, &Flow_Defecate, 7, 22);//进入大便设置时间时，更新步骤时间到屏幕
    // 小便流程：14步，起始控件ID 7
    RefreshFlowStepTimes(5, &Flow_Urinate, 7, 14);  //进入小便设置时间时，更新步骤时间到屏幕
    // 清洗流程：14步，起始控件ID 7
    RefreshFlowStepTimes(6, &Flow_Clean, 7, 14);     //进入清洗设置时间时，更新步骤时间到屏幕
    // 干燥流程：3步，起始控件ID 7
    RefreshFlowStepTimes(7, &Flow_Dry, 7, 3);     //进入干燥设置时间时，更新步骤时间到屏幕
    // 清洁空气流程：2步，起始控件ID 7
    RefreshFlowStepTimes(8, &Flow_CleanAir, 7, 2);     //进入空气清洁设置时间时，更新步骤时间到屏幕
    // 真空箱自清洁流程：2步，起始控件ID 7
    RefreshFlowStepTimes(9, &Flow_VacSelfClean, 7, 2);//进入管道清洁设置时间时，更新步骤时间到屏幕
    
    // 如果还有其他画面（如画面1）需要预置数据，可以继续添加
    // 例如：设置画面1中的某个状态文本
    // SetTextValue(1, 99, (uint8_t*)"系统就绪");
}

