// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XGCD_H
#define XGCD_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xgcd_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XGcd_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XGcd;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XGcd_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XGcd_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XGcd_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XGcd_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XGcd_Initialize(XGcd *InstancePtr, u16 DeviceId);
XGcd_Config* XGcd_LookupConfig(u16 DeviceId);
int XGcd_CfgInitialize(XGcd *InstancePtr, XGcd_Config *ConfigPtr);
#else
int XGcd_Initialize(XGcd *InstancePtr, const char* InstanceName);
int XGcd_Release(XGcd *InstancePtr);
#endif

void XGcd_Start(XGcd *InstancePtr);
u32 XGcd_IsDone(XGcd *InstancePtr);
u32 XGcd_IsIdle(XGcd *InstancePtr);
u32 XGcd_IsReady(XGcd *InstancePtr);
void XGcd_EnableAutoRestart(XGcd *InstancePtr);
void XGcd_DisableAutoRestart(XGcd *InstancePtr);

void XGcd_Set_a(XGcd *InstancePtr, u32 Data);
u32 XGcd_Get_a(XGcd *InstancePtr);
void XGcd_Set_b(XGcd *InstancePtr, u32 Data);
u32 XGcd_Get_b(XGcd *InstancePtr);
u32 XGcd_Get_c(XGcd *InstancePtr);
u32 XGcd_Get_c_vld(XGcd *InstancePtr);

void XGcd_InterruptGlobalEnable(XGcd *InstancePtr);
void XGcd_InterruptGlobalDisable(XGcd *InstancePtr);
void XGcd_InterruptEnable(XGcd *InstancePtr, u32 Mask);
void XGcd_InterruptDisable(XGcd *InstancePtr, u32 Mask);
void XGcd_InterruptClear(XGcd *InstancePtr, u32 Mask);
u32 XGcd_InterruptGetEnabled(XGcd *InstancePtr);
u32 XGcd_InterruptGetStatus(XGcd *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
