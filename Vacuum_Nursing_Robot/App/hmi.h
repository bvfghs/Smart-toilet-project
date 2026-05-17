#ifndef __HMI_H_
#define __HMI_H_

#define uchar    unsigned char
#define uint8    unsigned char
#define uint16   unsigned short int
#define uint32   unsigned long
#define int16    short int
#define int32    long
	
#include "main.h"
#include "hmi_driver.h"
#include "cmd_queue.h"
#include "cmd_process.h"
#include "app_flow_manager.h"
#include "app_workflows.h"

extern void  SendChar(uint8_t t);
extern void UpdateUI(void);                                                                 //更新UI数据
extern uint8  cmd_buffer[];  
extern uint8_t uart_rx_buf;
extern uint16_t g_current_screen_id;   //让其他文件可以读取当前的屏幕ID
void SetScreen1Idle(void);//用于将显示当前工作状态的控件恢复为空闲状态
#endif
