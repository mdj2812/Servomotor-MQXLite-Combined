/*
 * MX28R.h
 *
 *  Created on: 4 nov. 2015
 *      Author: hanch_000
 */

#ifndef SOURCES_MX28R_H_
#define SOURCES_MX28R_H_

//Every (THTL_REQUEST_NUMBER_TO_EXECUTE x 5) Ms will add (THTL_ADD_STEP)% to throttle
#define THTL_REQUEST_NUMBER_TO_EXECUTE  10
#define THTL_ADD_STEP                   2

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

LDD_TDeviceData* MX28R_RS485_Ptr;
LDD_TDeviceData* MX28R_DE_Ptr;
LDD_TDeviceData* MX28R_RE_Ptr;
LWEVENT_STRUCT lwevent_RS485;
LWEVENT_STRUCT lwevent_setThrottle;
uint8_t TxData[20];

void thtlInit();

void thtlGetChecksum(uint8_t* array);

uint8_t thtlSetGoalPosition(uint16_t pos,LDD_TDeviceData *ptr);

uint8_t MX28R_Write(uint8_t StartAddr, uint8_t Value[], uint8_t Length,LDD_TDeviceData *ptr);

void MX28R_set_task(uint32_t task_init_data);

void MX28R_check_task(uint32_t task_init_data);

void MX28R_OnCharRcv();

void MX28R_OnCmdTxComplete();

#endif /* SOURCES_MX28R_H_ */
