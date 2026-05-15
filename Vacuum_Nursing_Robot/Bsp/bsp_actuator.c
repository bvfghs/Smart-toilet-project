#include "bsp_actuator.h"

/* 阀1 */
void Actuator_Valve1_On(void)  { HAL_GPIO_WritePin(valve_1_GPIO_Port, valve_1_Pin, GPIO_PIN_SET); }
void Actuator_Valve1_Off(void) { HAL_GPIO_WritePin(valve_1_GPIO_Port, valve_1_Pin, GPIO_PIN_RESET); }

/* 阀2 */
void Actuator_Valve2_On(void)  { HAL_GPIO_WritePin(valve_2_GPIO_Port, valve_2_Pin, GPIO_PIN_SET); }
void Actuator_Valve2_Off(void) { HAL_GPIO_WritePin(valve_2_GPIO_Port, valve_2_Pin, GPIO_PIN_RESET); }

/* 阀3 */
void Actuator_Valve3_On(void)  { HAL_GPIO_WritePin(valve_3_GPIO_Port, valve_3_Pin, GPIO_PIN_SET); }
void Actuator_Valve3_Off(void) { HAL_GPIO_WritePin(valve_3_GPIO_Port, valve_3_Pin, GPIO_PIN_RESET); }

/* 阀4-5 (共用一组) */
void Actuator_Valve4_5_On(void)  { HAL_GPIO_WritePin(valve_4_5_GPIO_Port, valve_4_5_Pin, GPIO_PIN_SET); }
void Actuator_Valve4_5_Off(void) { HAL_GPIO_WritePin(valve_4_5_GPIO_Port, valve_4_5_Pin, GPIO_PIN_RESET); }

/* 阀6 */
void Actuator_Valve6_On(void)  { HAL_GPIO_WritePin(valve_6_GPIO_Port, valve_6_Pin, GPIO_PIN_SET); }
void Actuator_Valve6_Off(void) { HAL_GPIO_WritePin(valve_6_GPIO_Port, valve_6_Pin, GPIO_PIN_RESET); }

/* 阀7 */
void Actuator_Valve7_On(void)  { HAL_GPIO_WritePin(valve_7_GPIO_Port, valve_7_Pin, GPIO_PIN_SET); }
void Actuator_Valve7_Off(void) { HAL_GPIO_WritePin(valve_7_GPIO_Port, valve_7_Pin, GPIO_PIN_RESET); }

/* 阀8 */
void Actuator_Valve8_On(void)  { HAL_GPIO_WritePin(valve_8_GPIO_Port, valve_8_Pin, GPIO_PIN_SET); }
void Actuator_Valve8_Off(void) { HAL_GPIO_WritePin(valve_8_GPIO_Port, valve_8_Pin, GPIO_PIN_RESET); }

/* 阀9 */
void Actuator_Valve9_On(void)  { HAL_GPIO_WritePin(valve_9_GPIO_Port, valve_9_Pin, GPIO_PIN_SET); }
void Actuator_Valve9_Off(void) { HAL_GPIO_WritePin(valve_9_GPIO_Port, valve_9_Pin, GPIO_PIN_RESET); }

/* 阀10 */
void Actuator_Valve10_On(void)  { HAL_GPIO_WritePin(valve_10_GPIO_Port, valve_10_Pin, GPIO_PIN_SET); }
void Actuator_Valve10_Off(void) { HAL_GPIO_WritePin(valve_10_GPIO_Port, valve_10_Pin, GPIO_PIN_RESET); }

/* 大RO泵 */
void Actuator_RO_Pump_On(void)  { HAL_GPIO_WritePin(RO_pump_GPIO_Port, RO_pump_Pin, GPIO_PIN_SET); }
void Actuator_RO_Pump_Off(void) { HAL_GPIO_WritePin(RO_pump_GPIO_Port, RO_pump_Pin, GPIO_PIN_RESET); }

/* 小RO泵 */
void Actuator_S_RO_Pump_On(void)  { HAL_GPIO_WritePin(S_RO_pump_GPIO_Port, S_RO_pump_Pin, GPIO_PIN_SET); }
void Actuator_S_RO_Pump_Off(void) { HAL_GPIO_WritePin(S_RO_pump_GPIO_Port, S_RO_pump_Pin, GPIO_PIN_RESET); }

/* 高转速微真空泵 */
void Actuator_H_VacuumFan_On(void)  { HAL_GPIO_WritePin(H_vacuum_fan_GPIO_Port, H_vacuum_fan_Pin, GPIO_PIN_SET); }
void Actuator_H_VacuumFan_Off(void) { HAL_GPIO_WritePin(H_vacuum_fan_GPIO_Port, H_vacuum_fan_Pin, GPIO_PIN_RESET); }

/* 强真空泵 */
void Actuator_VacuumFan_On(void)  { HAL_GPIO_WritePin(vacuum_fan_GPIO_Port, vacuum_fan_Pin, GPIO_PIN_SET); }
void Actuator_VacuumFan_Off(void) { HAL_GPIO_WritePin(vacuum_fan_GPIO_Port, vacuum_fan_Pin, GPIO_PIN_RESET); }

/* 室内循环风机 */
void Actuator_AirFan_On(void)  { HAL_GPIO_WritePin(air_fan_GPIO_Port, air_fan_Pin, GPIO_PIN_SET); }
void Actuator_AirFan_Off(void) { HAL_GPIO_WritePin(air_fan_GPIO_Port, air_fan_Pin, GPIO_PIN_RESET); }

/* 暖风机 */
void Actuator_HotFan_On(void)  { HAL_GPIO_WritePin(hot_fan_GPIO_Port, hot_fan_Pin, GPIO_PIN_SET); }
void Actuator_HotFan_Off(void) { HAL_GPIO_WritePin(hot_fan_GPIO_Port, hot_fan_Pin, GPIO_PIN_RESET); }

/* 暖风机加热 */
void Actuator_FanHot_On(void)  { HAL_GPIO_WritePin(fan_hot_GPIO_Port, fan_hot_Pin, GPIO_PIN_SET); }
void Actuator_FanHot_Off(void) { HAL_GPIO_WritePin(fan_hot_GPIO_Port, fan_hot_Pin, GPIO_PIN_RESET); }

/* 厚膜加热器 */
void Actuator_WaterHot_On(void)  { HAL_GPIO_WritePin(water_hot_GPIO_Port, water_hot_Pin, GPIO_PIN_SET); }
void Actuator_WaterHot_Off(void) { HAL_GPIO_WritePin(water_hot_GPIO_Port, water_hot_Pin, GPIO_PIN_RESET); }

/* 负离子发生器 */
void Actuator_Anion_On(void)  { HAL_GPIO_WritePin(anion_GPIO_Port, anion_Pin, GPIO_PIN_SET); }
void Actuator_Anion_Off(void) { HAL_GPIO_WritePin(anion_GPIO_Port, anion_Pin, GPIO_PIN_RESET); }

/* 全部关闭 */
void Actuator_AllOff(void) {
    Actuator_Valve1_Off();    Actuator_Valve2_Off();    Actuator_Valve3_Off();
    Actuator_Valve4_5_Off();  Actuator_Valve6_Off();    Actuator_Valve7_Off();
    Actuator_Valve8_Off();    Actuator_Valve9_Off();    Actuator_Valve10_Off();
    Actuator_RO_Pump_Off();   Actuator_S_RO_Pump_Off();
    Actuator_H_VacuumFan_Off(); Actuator_VacuumFan_Off();
    Actuator_AirFan_Off();    Actuator_HotFan_Off();    Actuator_FanHot_Off();
    Actuator_WaterHot_Off();  Actuator_Anion_Off();
}
