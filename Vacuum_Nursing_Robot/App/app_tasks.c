#include "svc_scheduler.h"
#include "hmi.h"
#include "cmd_queue.h"
#include "hmi_driver.h"
#include "app_flow_manager.h"
#include "app_workflows.h"


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


