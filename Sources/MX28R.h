/*
 * MX28R.h
 *
 *  Created on: 4 nov. 2015
 *      Author: hanch_000
 */

#ifndef SOURCES_MX28R_H_
#define SOURCES_MX28R_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
//Every (THTL_REQUEST_NUMBER_TO_EXECUTE x 5) Ms will add (THTL_ADD_STEP)% to throttle
#define THTL_REQUEST_NUMBER_TO_EXECUTE  10
#define THTL_ADD_STEP                   2

// Torque limit of the motor
#define THTL_TORQUE_MAX 		(uint16_t)(0x0180)
#define THTL_TORQUE_MIN 		(uint16_t)(0x0080)
// Moving speed of the motor
#define THTL_MOVING_SPEED 		(uint16_t)(0x0200)
// Minimal moving speed of the motor
#define THTL_SPEED_MIN	 		(uint16_t)(0x0070)

// Positions
#define THTL_CW_ANGLE_LIMIT		(uint16_t)(0x0500)
#define THTL_CCW_ANGLE_LIMIT	(uint16_t)(0x1000)
#define THTL_INITIAL_POSITION	(uint16_t)(0x0600)
#define THTL_END_POSITION		(uint16_t)(0x0900)

#define RESPONSE_BUFFER_SEIZE	(uint8_t)(20)

#define MX28R_TIMEOUT_ERROR		(int32_t)(-1)
#define MX28R_LENGTH_ERROR		(int32_t)(-2)

/*******************************************************************************
 * Variables
 ******************************************************************************/
LDD_TDeviceData* MX28R_RS485_Ptr;
LDD_TDeviceData* MX28R_DE_Ptr;
LDD_TDeviceData* MX28R_RE_Ptr;
LWEVENT_STRUCT lwevent_RS485;
LWEVENT_STRUCT lwevent_setThrottle;
uint8_t TxData[20];

uint8_t response[RESPONSE_BUFFER_SEIZE];

/** 0% and 100% positions */
uint16_t P0, P100;

uint8_t FinalThtl;
int8_t thtlBuffer;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* In*/
void thtlInit();

void thtlGetChecksum(uint8_t* array);

uint8_t thtlSetGoalPosition(uint16_t pos,LDD_TDeviceData *ptr);

uint8_t MX28R_Read(uint8_t StartAddr, uint8_t Length, LDD_TDeviceData *ptr);

uint8_t MX28R_Write(uint8_t StartAddr, uint8_t Value[], uint8_t Length, LDD_TDeviceData *ptr);

uint8_t MX28R_Reset(LDD_TDeviceData *ptr);

int32_t MX28_read_byte(uint8_t StartAddr);

uint16_t MX28R_get_speed(void);

uint16_t MX28R_get_position(void);

//uint16_t MX28R_get_load(void);

void MX28R_calibration(void);

void MX28R_set_task(uint32_t task_init_data);

void MX28R_check_task(uint32_t task_init_data);

void MX28R_OnCharRcv();

void MX28R_OnCmdTxComplete();

#endif /* SOURCES_MX28R_H_ */
