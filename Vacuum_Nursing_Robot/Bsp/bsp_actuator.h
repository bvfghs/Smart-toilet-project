#ifndef __BSP_ACTUATOR_H
#define __BSP_ACTUATOR_H

#include "main.h"   // 提供引脚宏

/* ========== 阀类 ========== */
void Actuator_Valve1_On(void);
void Actuator_Valve1_Off(void);

void Actuator_Valve2_On(void);
void Actuator_Valve2_Off(void);

void Actuator_Valve3_On(void);
void Actuator_Valve3_Off(void);

void Actuator_Valve4_5_On(void);
void Actuator_Valve4_5_Off(void);

void Actuator_Valve6_On(void);
void Actuator_Valve6_Off(void);

void Actuator_Valve7_On(void);
void Actuator_Valve7_Off(void);

void Actuator_Valve8_On(void);
void Actuator_Valve8_Off(void);

void Actuator_Valve9_On(void);
void Actuator_Valve9_Off(void);

void Actuator_Valve10_On(void);
void Actuator_Valve10_Off(void);

/* ========== 泵与风机 ========== */
void Actuator_RO_Pump_On(void);
void Actuator_RO_Pump_Off(void);

void Actuator_S_RO_Pump_On(void);
void Actuator_S_RO_Pump_Off(void);

void Actuator_H_VacuumFan_On(void);
void Actuator_H_VacuumFan_Off(void);

void Actuator_VacuumFan_On(void);
void Actuator_VacuumFan_Off(void);

void Actuator_AirFan_On(void);
void Actuator_AirFan_Off(void);

void Actuator_HotFan_On(void);
void Actuator_HotFan_Off(void);

/* ========== 加热 / 离子 ========== */
void Actuator_FanHot_On(void);
void Actuator_FanHot_Off(void);

void Actuator_WaterHot_On(void);
void Actuator_WaterHot_Off(void);

void Actuator_Anion_On(void);
void Actuator_Anion_Off(void);

/* ========== 全局控制 ========== */
void Actuator_AllOff(void);   // 关闭所有执行器

#endif
