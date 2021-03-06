// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xgcd.h"

extern XGcd_Config XGcd_ConfigTable[];

XGcd_Config *XGcd_LookupConfig(u16 DeviceId) {
	XGcd_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XGCD_NUM_INSTANCES; Index++) {
		if (XGcd_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XGcd_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XGcd_Initialize(XGcd *InstancePtr, u16 DeviceId) {
	XGcd_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XGcd_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XGcd_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

