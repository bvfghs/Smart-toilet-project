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
extern void  SendChar(uint8_t t);
extern void UpdateUI(void);                                                                 //更新UI数据
extern uint8  cmd_buffer[];  
extern uint8_t uart_rx_buf;


#endif
