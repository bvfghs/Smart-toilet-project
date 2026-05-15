#include "app_workflows.h"
#include "bsp_actuator.h"
#include "hmi_driver.h"      // 提供 SetButtonValue 等串口屏指令


/* ---------- 大便冲洗流程步骤定义（严格按顺序独立编写，无复用） ---------- */


// 步骤 01: 5s 等待
static void step_def_01_enter(void) { /* 等待：通常无设备动作 */ }
static void step_def_01_exit(void)  { /* 退出等待 */ }

// 步骤 02: 5s 强抽污
static void step_def_02_enter(void) { 
Actuator_Valve7_On();
	
}


static void step_def_02_exit(void)  { 
Actuator_Valve7_Off();
}

// 步骤 03: 15s 抽污
static void step_def_03_enter(void) { 
Actuator_VacuumFan_On(); 
Actuator_Anion_On();
}
static void step_def_03_exit(void)  {

}

// 步骤 04: 10s 下喷抽污
static void step_def_04_enter(void) { 
 Actuator_Valve2_On();
Actuator_Valve3_On();
	Actuator_RO_Pump_On();
}
static void step_def_04_exit(void)  {
Actuator_Valve2_Off();
Actuator_Valve3_Off();
	Actuator_RO_Pump_Off();
}

// 步骤 05: 10s 抽污
static void step_def_05_enter(void) { 

}
static void step_def_05_exit(void)  { 

}

// 步骤 06: 5s 下喷抽污
static void step_def_06_enter(void) {
Actuator_Valve2_On();
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
}
static void step_def_06_exit(void)  {
Actuator_Valve2_Off();
	Actuator_Valve3_Off();
	Actuator_RO_Pump_Off();
}

// 步骤 07: 5s 抽污
static void step_def_07_enter(void) { 

}
static void step_def_07_exit(void)  { 
Actuator_VacuumFan_Off();
Actuator_Anion_Off();
}

// 步骤 08: 5s 等待
static void step_def_08_enter(void) { 
/* 等待：无设备动作 */ 
}
static void step_def_08_exit(void)  {
/* 退出等待 */ 
}

// 步骤 09: 5s 抽污
static void step_def_09_enter(void) {
Actuator_VacuumFan_On();
Actuator_Anion_On();
}
static void step_def_09_exit(void)  {
Actuator_VacuumFan_Off();
Actuator_Anion_Off();
}

// 步骤 10: 5s 等待
static void step_def_10_enter(void) {
/* 等待：无设备动作 */
}
static void step_def_10_exit(void)  {
/* 退出等待 */ 
}

// 步骤 11: 15s 抽污
static void step_def_11_enter(void) {
Actuator_VacuumFan_On();
	Actuator_Anion_On();
}
static void step_def_11_exit(void)  {

}

// 步骤 12: 15s 中喷抽污
static void step_def_12_enter(void) {
Actuator_Valve1_On();
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
}
static void step_def_12_exit(void)  {
Actuator_Valve1_Off();
	Actuator_Valve3_Off();
	Actuator_RO_Pump_Off();
}

// 步骤 13: 10s 抽污
static void step_def_13_enter(void) {

}
static void step_def_13_exit(void)  {

}

// 步骤 14: 5s 中喷抽污
static void step_def_14_enter(void) {
Actuator_Valve1_On();
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
}
static void step_def_14_exit(void)  { 
Actuator_Valve1_Off();
	Actuator_Valve3_Off();
	Actuator_RO_Pump_Off();
}

// 步骤 15: 15s 抽污
static void step_def_15_enter(void) {

}
static void step_def_15_exit(void)  {
 
}

// 步骤 16: 10s 下喷抽污
static void step_def_16_enter(void) {
Actuator_Valve2_On();
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
}
static void step_def_16_exit(void)  { 
Actuator_Valve2_Off();
	Actuator_Valve3_Off();
	Actuator_RO_Pump_Off();
}

// 步骤 17: 10s 抽污
static void step_def_17_enter(void) {
 
}
static void step_def_17_exit(void)  {

}

// 步骤 18: 5s 下喷抽污
static void step_def_18_enter(void) {
Actuator_Valve2_On();
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
}
static void step_def_18_exit(void)  {
Actuator_Valve2_Off();
	Actuator_Valve3_Off();
	Actuator_RO_Pump_Off();
}

// 步骤 19: 5s 抽污
static void step_def_19_enter(void) {
 
}
static void step_def_19_exit(void)  { 
Actuator_VacuumFan_Off();
	Actuator_Anion_Off();
}

// 步骤 20: 20s 等待
static void step_def_20_enter(void) {
/* 等待：无设备动作 */ 
}
static void step_def_20_exit(void)  {
/* 退出等待 */ 
}

// 步骤 21: 10min 暖风 (10分钟 = 600秒)
static void step_def_21_enter(void) {
 Actuator_HotFan_On();
Actuator_FanHot_On();
} // 暖风/加热风机
static void step_def_21_exit(void)  {
 Actuator_HotFan_Off();
	Actuator_FanHot_Off();
}

// 步骤 22: 5s 抽污
static void step_def_22_enter(void) {
Actuator_VacuumFan_On();
Actuator_Anion_On();
}
static void step_def_22_exit(void)  {
Actuator_VacuumFan_Off();
	Actuator_Anion_Off();
}

// 步骤数组（严格按顺序配置，最后以 duration=0 作为结束标记） const前缀，如果固定步骤时间时加上，程序写入FLASH，不占用RAM
static   FlowStep_t steps_defecate[] = {
    {   5, "等待",       step_def_01_enter, step_def_01_exit  },
    {   5, "强抽污",     step_def_02_enter, step_def_02_exit  },
    {  15, "抽污",       step_def_03_enter, step_def_03_exit  },
    {  10, "下喷抽污",   step_def_04_enter, step_def_04_exit  },
    {  10, "抽污",       step_def_05_enter, step_def_05_exit  },
    {   5, "下喷抽污",   step_def_06_enter, step_def_06_exit  },
    {   5, "抽污",       step_def_07_enter, step_def_07_exit  },
    {   5, "等待",       step_def_08_enter, step_def_08_exit  },
    {   5, "抽污",       step_def_09_enter, step_def_09_exit  },
    {   5, "等待",       step_def_10_enter, step_def_10_exit  },
    {  15, "抽污",       step_def_11_enter, step_def_11_exit  },
    {  15, "中喷抽污",   step_def_12_enter, step_def_12_exit  },
    {  10, "抽污",       step_def_13_enter, step_def_13_exit  },
    {   5, "中喷抽污",   step_def_14_enter, step_def_14_exit  },
    {  15, "抽污",       step_def_15_enter, step_def_15_exit  },
    {  10, "下喷抽污",   step_def_16_enter, step_def_16_exit  },
    {  10, "抽污",       step_def_17_enter, step_def_17_exit  },
    {   5, "下喷抽污",   step_def_18_enter, step_def_18_exit  },
    {   5, "抽污",       step_def_19_enter, step_def_19_exit  },
    {  20, "等待",       step_def_20_enter, step_def_20_exit  },
    { 600, "暖风",       step_def_21_enter, step_def_21_exit  },
    {   5, "抽污",       step_def_22_enter, step_def_22_exit  },
    {   0, NULL,         NULL,              NULL              } // ?? 流程终止标记，不可删除
};

void Flow_OnFinished_Defecate(void) {
    SetButtonValue(1, 5, 0);   // 流程结束复位HMI按钮（ID与值请按实际屏幕协议修改）
}

const FlowDef_t Flow_Defecate = {
    .name = "大便冲洗",
    .steps = steps_defecate,
    .on_finished = Flow_OnFinished_Defecate
};



/* ---------- 小便冲洗流程步骤定义 ---------- */
// 步骤顺序：等待5s → 强抽污5s → 抽污15s → 中喷抽污8s → 抽污10s → 中喷抽污5s → 抽污15s → 
// 下喷抽污10s → 抽污10s → 下喷抽污5s → 抽污5s → 等待20s → 暖风10min(600s) → 抽污5s

// 步骤 01: 5s 等待
static void step_uri_01_enter(void) {
    // TODO: 等待期间无设备动作，可空
}
static void step_uri_01_exit(void) {
    // TODO: 退出等待，无动作
}

// 步骤 02: 5s 强抽污
static void step_uri_02_enter(void) {
   Actuator_Valve7_On();
	// TODO: 打开强抽污阀（例如 Actuator_Valve7_On();）
}
static void step_uri_02_exit(void) {
	Actuator_Valve7_Off();
    // TODO: 关闭强抽污阀（例如 Actuator_Valve7_Off();）
}

// 步骤 03: 15s 抽污（真空泵+负离子）
static void step_uri_03_enter(void) {
  Actuator_VacuumFan_On(); 
	Actuator_Anion_On();
	// TODO: 打开抽污设备（例如 Actuator_VacuumFan_On(); Actuator_Anion_On();）
}
static void step_uri_03_exit(void) {
    // TODO: 此步骤结束时通常不关闭，后续步骤可能继续抽污；如需关闭请在此添加代码
}

// 步骤 04: 8s 中喷抽污（阀1+阀3+RO泵）
static void step_uri_04_enter(void) {
	Actuator_Valve1_On(); 
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
    // TODO: 打开中喷相关设备（例如 Actuator_Valve1_On(); Actuator_Valve3_On(); Actuator_RO_Pump_On();）
}
static void step_uri_04_exit(void) {
    Actuator_Valve1_Off();
	Actuator_Valve3_Off(); 
	Actuator_RO_Pump_Off();
	// TODO: 关闭中喷设备（例如 Actuator_Valve1_Off(); Actuator_Valve3_Off(); Actuator_RO_Pump_Off();）
}

// 步骤 05: 10s 抽污（仅抽污，不喷水）
static void step_uri_05_enter(void) {
    // TODO: 保持抽污（真空泵和负离子已在步骤03开启，无需重复操作）
}
static void step_uri_05_exit(void) {
    // TODO: 不关闭，继续抽污
}

// 步骤 06: 5s 中喷抽污
static void step_uri_06_enter(void) {
    Actuator_Valve1_On(); 
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
	// TODO: 打开中喷设备（同步骤04）
}
static void step_uri_06_exit(void) {
	  Actuator_Valve1_Off();
	Actuator_Valve3_Off(); 
	Actuator_RO_Pump_Off();
    // TODO: 关闭中喷设备
}

// 步骤 07: 15s 抽污
static void step_uri_07_enter(void) {
    // TODO: 保持抽污
}
static void step_uri_07_exit(void) {
    // TODO: 不关闭，继续抽污
}

// 步骤 08: 10s 下喷抽污（阀2+阀3+RO泵）
static void step_uri_08_enter(void) {
	Actuator_Valve2_On(); 
	Actuator_Valve3_On(); 
	Actuator_RO_Pump_On();
    // TODO: 打开下喷设备（例如 Actuator_Valve2_On(); Actuator_Valve3_On(); Actuator_RO_Pump_On();）
}
static void step_uri_08_exit(void) {
  Actuator_Valve2_Off();
	Actuator_Valve3_Off(); 
	Actuator_RO_Pump_Off();
	// TODO: 关闭下喷设备
}

// 步骤 09: 10s 抽污
static void step_uri_09_enter(void) {
    // TODO: 保持抽污
}
static void step_uri_09_exit(void) {
    // TODO: 不关闭
}

// 步骤 10: 5s 下喷抽污
static void step_uri_10_enter(void) {
	Actuator_Valve2_On(); 
	Actuator_Valve3_On(); 
	Actuator_RO_Pump_On();
    // TODO: 打开下喷设备
}
static void step_uri_10_exit(void) {
	 Actuator_Valve2_Off();
	Actuator_Valve3_Off(); 
	Actuator_RO_Pump_Off();
    // TODO: 关闭下喷设备
}

// 步骤 11: 5s 抽污（最后关闭真空泵和负离子）
static void step_uri_11_enter(void) {
    // TODO: 保持抽污
}
static void step_uri_11_exit(void) {
	Actuator_VacuumFan_Off(); 
	Actuator_Anion_Off();
    // TODO: 关闭抽污设备（例如 Actuator_VacuumFan_Off(); Actuator_Anion_Off();）
}

// 步骤 12: 20s 等待
static void step_uri_12_enter(void) {
    // TODO: 等待，无动作
}
static void step_uri_12_exit(void) {
    // TODO: 无动作
}

// 步骤 13: 10min 暖风 (600秒)
static void step_uri_13_enter(void) {
    // TODO: 打开暖风机和加热（例如 Actuator_HotFan_On(); Actuator_FanHot_On();）
	Actuator_HotFan_On();
	Actuator_FanHot_On();
}
static void step_uri_13_exit(void) {
	Actuator_HotFan_Off(); 
	Actuator_FanHot_Off();
    // TODO: 关闭暖风设备（例如 Actuator_HotFan_Off(); Actuator_FanHot_Off();）
}

// 步骤 14: 5s 抽污（最后再次抽污）
static void step_uri_14_enter(void) {
	 Actuator_VacuumFan_On(); 
	Actuator_Anion_On();
    // TODO: 打开抽污设备（真空泵+负离子）
}
static void step_uri_14_exit(void) {
	 Actuator_VacuumFan_Off(); 
	Actuator_Anion_Off();
    // TODO: 关闭抽污设备
}

// 小便流程步骤数组（可写，以便动态修改时间）
static FlowStep_t steps_urinate[] = {
    {   5, "等待",         step_uri_01_enter, step_uri_01_exit },
    {   5, "强抽污",       step_uri_02_enter, step_uri_02_exit },
    {  15, "抽污",         step_uri_03_enter, step_uri_03_exit },
    {   8, "中喷抽污",     step_uri_04_enter, step_uri_04_exit },
    {  10, "抽污",         step_uri_05_enter, step_uri_05_exit },
    {   5, "中喷抽污",     step_uri_06_enter, step_uri_06_exit },
    {  15, "抽污",         step_uri_07_enter, step_uri_07_exit },
    {  10, "下喷抽污",     step_uri_08_enter, step_uri_08_exit },
    {  10, "抽污",         step_uri_09_enter, step_uri_09_exit },
    {   5, "下喷抽污",     step_uri_10_enter, step_uri_10_exit },
    {   5, "抽污",         step_uri_11_enter, step_uri_11_exit },
    {  20, "等待",         step_uri_12_enter, step_uri_12_exit },
    { 600, "暖风",         step_uri_13_enter, step_uri_13_exit },
    {   5, "抽污",         step_uri_14_enter, step_uri_14_exit },
    {   0, NULL,           NULL,              NULL }   // 结束标记
};

// 流程结束回调（复位启动按钮）
void Flow_OnFinished_Urinate(void) {
    // TODO: 根据实际屏幕控件ID复位启动按钮，例如：
     SetButtonValue(1, 6, 0);   // 画面1，控件6
}

// 小便流程定义
const FlowDef_t Flow_Urinate = {
    .name = "小便冲洗",
    .steps = steps_urinate,
    .on_finished = Flow_OnFinished_Urinate
};

/* ---------- 清洗工作流程步骤定义 ---------- */
// 步骤顺序：等待5s → 强抽污5s → 抽污15s → 中喷抽污15s → 抽污10s → 中喷抽污5s → 抽污15s → 
// 下喷抽污10s → 抽污10s → 下喷抽污5s → 抽污5s → 等待20s → 暖风10min(600s) → 抽污5s

// 步骤 01: 5s 等待
static void step_cln_01_enter(void) {
    // TODO: 等待，无设备动作
}
static void step_cln_01_exit(void) {
    // TODO: 无动作
}

// 步骤 02: 5s 强抽污
static void step_cln_02_enter(void) {
	Actuator_Valve7_On();
    // TODO: 打开强抽污阀（例如 Actuator_Valve7_On();）
}
static void step_cln_02_exit(void) {
	Actuator_Valve7_Off();
    // TODO: 关闭强抽污阀（例如 Actuator_Valve7_Off();）
}

// 步骤 03: 15s 抽污（真空泵+负离子）
static void step_cln_03_enter(void) {
	Actuator_VacuumFan_On(); 
	Actuator_Anion_On();
    // TODO: 打开抽污设备（例如 Actuator_VacuumFan_On(); Actuator_Anion_On();）
}
static void step_cln_03_exit(void) {
    // TODO: 此步骤结束时通常不关闭，后续步骤可能继续抽污
}

// 步骤 04: 15s 中喷抽污（阀1+阀3+RO泵）
static void step_cln_04_enter(void) {
	Actuator_Valve1_On(); 
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
    // TODO: 打开中喷设备（例如 Actuator_Valve1_On(); Actuator_Valve3_On(); Actuator_RO_Pump_On();）
}
static void step_cln_04_exit(void) {
	Actuator_Valve1_Off(); 
	Actuator_Valve3_Off();
	Actuator_RO_Pump_Off();
    // TODO: 关闭中喷设备
}

// 步骤 05: 10s 抽污
static void step_cln_05_enter(void) {
	
    // TODO: 保持抽污（真空泵和负离子已在步骤03开启）
}
static void step_cln_05_exit(void) {
    // TODO: 不关闭
}

// 步骤 06: 5s 中喷抽污
static void step_cln_06_enter(void) {
		Actuator_Valve1_On(); 
	Actuator_Valve3_On();
	Actuator_RO_Pump_On();
    // TODO: 打开中喷设备
}
static void step_cln_06_exit(void) {
	Actuator_Valve1_Off(); 
	Actuator_Valve3_Off();
	Actuator_RO_Pump_Off();
    // TODO: 关闭中喷设备
}

// 步骤 07: 15s 抽污
static void step_cln_07_enter(void) {
    // TODO: 保持抽污
}
static void step_cln_07_exit(void) {
    // TODO: 不关闭
}

// 步骤 08: 10s 下喷抽污（阀2+阀3+RO泵）
static void step_cln_08_enter(void) {
	Actuator_Valve2_On();
	Actuator_Valve3_On(); 
	Actuator_RO_Pump_On();
    // TODO: 打开下喷设备（例如 Actuator_Valve2_On(); Actuator_Valve3_On(); Actuator_RO_Pump_On();）
}
static void step_cln_08_exit(void) {
	Actuator_Valve2_Off();
	Actuator_Valve3_Off(); 
	Actuator_RO_Pump_Off();
    // TODO: 关闭下喷设备
}

// 步骤 09: 10s 抽污
static void step_cln_09_enter(void) {
    // TODO: 保持抽污
}
static void step_cln_09_exit(void) {
    // TODO: 不关闭
}

// 步骤 10: 5s 下喷抽污
static void step_cln_10_enter(void) {
		Actuator_Valve2_On();
	Actuator_Valve3_On(); 
	Actuator_RO_Pump_On();
    // TODO: 打开下喷设备
}
static void step_cln_10_exit(void) {
		Actuator_Valve2_Off();
	Actuator_Valve3_Off(); 
	Actuator_RO_Pump_Off();
    // TODO: 关闭下喷设备
}

// 步骤 11: 5s 抽污（最后关闭真空泵和负离子）
static void step_cln_11_enter(void) {
    // TODO: 保持抽污
}
static void step_cln_11_exit(void) {
	Actuator_VacuumFan_Off();
	Actuator_Anion_Off();
    // TODO: 关闭抽污设备（例如 Actuator_VacuumFan_Off(); Actuator_Anion_Off();）
}

// 步骤 12: 20s 等待
static void step_cln_12_enter(void) {
    // TODO: 等待，无动作
}
static void step_cln_12_exit(void) {
    // TODO: 无动作
}

// 步骤 13: 10min 暖风 (600秒)
static void step_cln_13_enter(void) {
	Actuator_HotFan_On();
	Actuator_FanHot_On();
    // TODO: 打开暖风机和加热（例如 Actuator_HotFan_On(); Actuator_FanHot_On();）
}
static void step_cln_13_exit(void) {
		Actuator_HotFan_Off();
	Actuator_FanHot_Off();
    // TODO: 关闭暖风设备
}

// 步骤 14: 5s 抽污
static void step_cln_14_enter(void) {
		Actuator_VacuumFan_On();
	Actuator_Anion_On();
    // TODO: 打开抽污设备（真空泵+负离子）
}
static void step_cln_14_exit(void) {
	Actuator_VacuumFan_Off();
	Actuator_Anion_Off();
    // TODO: 关闭抽污设备
}

// 清洗流程步骤数组（可写，以便动态修改时间）
static FlowStep_t steps_clean[] = {
    {   5, "等待",         step_cln_01_enter, step_cln_01_exit },
    {   5, "强抽污",       step_cln_02_enter, step_cln_02_exit },
    {  15, "抽污",         step_cln_03_enter, step_cln_03_exit },
    {  15, "中喷抽污",     step_cln_04_enter, step_cln_04_exit },
    {  10, "抽污",         step_cln_05_enter, step_cln_05_exit },
    {   5, "中喷抽污",     step_cln_06_enter, step_cln_06_exit },
    {  15, "抽污",         step_cln_07_enter, step_cln_07_exit },
    {  10, "下喷抽污",     step_cln_08_enter, step_cln_08_exit },
    {  10, "抽污",         step_cln_09_enter, step_cln_09_exit },
    {   5, "下喷抽污",     step_cln_10_enter, step_cln_10_exit },
    {   5, "抽污",         step_cln_11_enter, step_cln_11_exit },
    {  20, "等待",         step_cln_12_enter, step_cln_12_exit },
    { 600, "暖风",         step_cln_13_enter, step_cln_13_exit },
    {   5, "抽污",         step_cln_14_enter, step_cln_14_exit },
    {   0, NULL,           NULL,              NULL }   // 结束标记
};

// 流程结束回调（复位启动按钮）
void Flow_OnFinished_Clean(void) {
    // TODO: 根据实际屏幕控件ID复位启动按钮，例如：
    // SetButtonValue(1, 7, 0);   // 画面1，控件7
}

// 清洗流程定义
const FlowDef_t Flow_Clean = {
    .name = "清洗",
    .steps = steps_clean,
    .on_finished = Flow_OnFinished_Clean
};

/* ---------- 干燥工作流程步骤定义 ---------- */
// 步骤顺序：等待5s → 暖风10min(600s) → 抽污5s

// 步骤 01: 5s 等待
static void step_dry_01_enter(void) {
    // TODO: 等待，无设备动作
}
static void step_dry_01_exit(void) {
    // TODO: 无动作
}

// 步骤 02: 10min 暖风 (600秒)
static void step_dry_02_enter(void) {
    // TODO: 打开暖风机和加热（例如 Actuator_HotFan_On(); Actuator_FanHot_On();）
}
static void step_dry_02_exit(void) {
    // TODO: 关闭暖风设备（例如 Actuator_HotFan_Off(); Actuator_FanHot_Off();）
}

// 步骤 03: 5s 抽污
static void step_dry_03_enter(void) {
    // TODO: 打开抽污设备（例如 Actuator_VacuumFan_On(); Actuator_Anion_On();）
}
static void step_dry_03_exit(void) {
    // TODO: 关闭抽污设备（例如 Actuator_VacuumFan_Off(); Actuator_Anion_Off();）
}

// 干燥流程步骤数组（可写，以便动态修改时间）
static FlowStep_t steps_dry[] = {
    {   5, "等待",         step_dry_01_enter, step_dry_01_exit },
    { 600, "暖风",         step_dry_02_enter, step_dry_02_exit },
    {   5, "抽污",         step_dry_03_enter, step_dry_03_exit },
    {   0, NULL,           NULL,              NULL }   // 结束标记
};

// 流程结束回调（复位启动按钮）
void Flow_OnFinished_Dry(void) {
    // TODO: 根据实际屏幕控件ID复位启动按钮，例如：
    // SetButtonValue(1, 8, 0);   // 画面1，控件8
}

// 干燥流程定义
const FlowDef_t Flow_Dry = {
    .name = "干燥",
    .steps = steps_dry,
    .on_finished = Flow_OnFinished_Dry
};

/* ---------- 清洁空气工作流程步骤定义 ---------- */
// 步骤顺序：等待5s → 清洁空气60s

// 步骤 01: 5s 等待
static void step_air_01_enter(void) {
    // TODO: 等待，无设备动作
}
static void step_air_01_exit(void) {
    // TODO: 无动作
}

// 步骤 02: 60s 清洁空气
static void step_air_02_enter(void) {
	Actuator_Anion_On();
	Actuator_AirFan_On();
    // TODO: 打开清洁空气设备（例如负离子发生器、空气净化相关设备）
    // 示例：Actuator_Anion_On(); Actuator_AirFan_On(); 等
}
static void step_air_02_exit(void) {
	Actuator_Anion_Off();
	Actuator_AirFan_Off();
    // TODO: 关闭清洁空气设备（例如 Actuator_Anion_Off(); Actuator_AirFan_Off();）
}

// 清洁空气流程步骤数组（可写，以便动态修改时间）
static FlowStep_t steps_clean_air[] = {
    {   5, "等待",          step_air_01_enter, step_air_01_exit },
    {  60, "清洁空气",      step_air_02_enter, step_air_02_exit },
    {   0, NULL,            NULL,              NULL }   // 结束标记
};

// 流程结束回调（复位启动按钮）
void Flow_OnFinished_CleanAir(void) {
    // TODO: 根据实际屏幕控件ID复位启动按钮，例如：
    // SetButtonValue(1, 9, 0);   // 画面1，控件9
}

// 清洁空气流程定义
const FlowDef_t Flow_CleanAir = {
    .name = "清洁空气",
    .steps = steps_clean_air,
    .on_finished = Flow_OnFinished_CleanAir
};

/* ---------- 通用函数实现 ---------- */

// 通用：设置某个流程的某一步时长
bool Flow_SetStepDuration(const FlowDef_t* flow, uint8_t step_idx, uint32_t seconds) {
    FlowStep_t* steps = NULL;
    uint8_t step_cnt = 0;

    if (flow == &Flow_Defecate) {
        steps = steps_defecate;
        step_cnt = 22;   // 有效步骤数（目前只写了大便流程，其他步骤需要修改）
    } else if (flow == &Flow_Urinate) {
        steps = steps_urinate;
        step_cnt = 2;
    } else if (flow == &Flow_Clean) {
        steps = steps_clean;
        step_cnt = 1;
    } else {
        return false;   // 未知流程
    }

    if (step_idx >= step_cnt) return false;
    if (seconds == 0) seconds = 1;   // 避免时长为0
    steps[step_idx].duration_sec = seconds;
    return true;
}

// 通用：获取某个流程某一步的当前时长
uint32_t Flow_GetStepDuration(const FlowDef_t* flow, uint8_t step_idx) {
    FlowStep_t* steps = NULL;
    uint8_t step_cnt = 0;

    if (flow == &Flow_Defecate) {
        steps = steps_defecate;
        step_cnt = 22;
    } else if (flow == &Flow_Urinate) {
        steps = steps_urinate;
        step_cnt = 2;
    } else if (flow == &Flow_Clean) {
        steps = steps_clean;
        step_cnt = 1;
    } else {
        return 0;
    }

    if (step_idx >= step_cnt) return 0;
    return steps[step_idx].duration_sec;
}
