/*
 * MX28R.c
 *
 *  Created on: 4 nov. 2015
 *      Author: hanch_000
 */

#include "MX28R.h"
#include "string.h"

void thtlInit() {
  MX28R_RS485_Ptr = MX28R_RS485_Init(NULL);
  MX28R_DE_Ptr = MX28R_DE_Init(NULL);
  MX28R_RE_Ptr = MX28R_RE_Init(NULL);
  _lwevent_create(&lwevent_RS485, 0);
  _lwevent_create(&lwevent_setThrottle, 0);
}

void thtlGetChecksum(uint8_t* array) {
  uint8_t* ptr = array;
  uint8_t i = 0;
  uint16_t sum = 0;
  ptr += 2; //ID
  for (i = 0; i < (*(array + 3) + 1); i++) {
    sum += *(ptr++);
  }
  *ptr = ~(sum & 0xff);
}

uint8_t thtlSetGoalPosition(uint16_t pos, LDD_TDeviceData *ptr) {
  TxData[0] = 0xFF;
  TxData[1] = 0xFF;
  TxData[2] = 0x01;
  TxData[3] = 0x05;
  TxData[4] = 0x03;
  TxData[5] = 0x1E;
  TxData[6] = pos & 0xff;
  TxData[7] = (pos & 0xff00) >> 8;
  thtlGetChecksum(TxData); // data8
  MX28R_DE_SetVal(MX28R_DE_Ptr);
  MX28R_RE_SetVal(MX28R_RE_Ptr);
  return MX28R_RS485_SendBlock(ptr, TxData, 9U);
}

uint8_t MX28R_Read(uint8_t StartAddr, uint8_t Length, LDD_TDeviceData *ptr) {
  TxData[0] = 0xFF;
  TxData[1] = 0xFF;
  TxData[2] = 0x01;
  TxData[3] = 0x04;
  TxData[4] = 0x02;
  TxData[5] = StartAddr;
  TxData[6] = Length;
  thtlGetChecksum(TxData);
  MX28R_DE_SetVal(MX28R_DE_Ptr);
  MX28R_RE_SetVal(MX28R_RE_Ptr);
  return MX28R_RS485_SendBlock(ptr, TxData, 8);
}

uint8_t MX28R_Write(uint8_t StartAddr, uint8_t Value[], uint8_t Length, LDD_TDeviceData *ptr) {
  uint8_t i = 0;
  TxData[0] = 0xFF;
  TxData[1] = 0xFF;
  TxData[2] = 0x01;
  TxData[3] = Length + 3;
  TxData[4] = 0x03;
  TxData[5] = StartAddr;
  for (i = 0; i < Length; i++)
    TxData[6 + i] = Value[i];
  thtlGetChecksum(TxData);
  MX28R_DE_SetVal(MX28R_DE_Ptr);
  MX28R_RE_SetVal(MX28R_RE_Ptr);
  return MX28R_RS485_SendBlock(ptr, TxData, Length + 8);
}

uint16_t MX28_read_byte(uint8_t StartAddr)
{
	uint16_t ret;

	MX28R_Read(StartAddr, 2, MX28R_RS485_Ptr);
	ret = _lwevent_wait_ticks(&lwevent_setThrottle, 0x02, FALSE, 10);
	if(ret == LWEVENT_WAIT_TIMEOUT) {
		return ret;
	} else {
		_lwevent_clear(&lwevent_setThrottle, 0x02);
		ret = (response[3]) | (response[4]<<8);

		return ret;
	}
}

uint8_t MX28R_check_moving(void) {
	uint16_t speed;

	do {
		speed = MX28_read_byte(0x26);
	} while(speed == LWEVENT_WAIT_TIMEOUT);

	if(speed == 0) {
		return 0;
	} else {
		return 1;
	}
}

void MX28R_calibration(void) {
	uint16_t result, PP;
	//uint16_t PL;
	//uint8_t i = 0;
	/** table to record the load of the corresponding position */
	//uint16_t table_PP_PL[40][2];
	uint8_t torqueLimit[]={(uint8_t)THTL_TORQUE_LIMIT, (uint8_t)(THTL_TORQUE_LIMIT>>8)};
	uint8_t movingSpeed[]={(uint8_t)THTL_MOVING_SPEED, (uint8_t)(THTL_MOVING_SPEED>>8)};

	/**********************Set the torque limit and the moving speed********************/
	/* Set the Max Torque to the torqueLimit */
	MX28R_Write(0x0E, torqueLimit, 2, MX28R_RS485_Ptr);
	result = _lwevent_wait_ticks(&lwevent_setThrottle, 0x02, FALSE, 10);
	_lwevent_clear(&lwevent_setThrottle, 0x02);

	/* Set the Torque Limit to the torqueLimit */
	MX28R_Write(0x22, torqueLimit, 2, MX28R_RS485_Ptr);
	result = _lwevent_wait_ticks(&lwevent_setThrottle, 0x02, FALSE, 10);
	_lwevent_clear(&lwevent_setThrottle, 0x02);

	/* Set the moving speed to the movingSpeed */
	MX28R_Write(0x20, movingSpeed, 2, MX28R_RS485_Ptr);
	result = _lwevent_wait_ticks(&lwevent_setThrottle, 0x02, FALSE, 10);
	_lwevent_clear(&lwevent_setThrottle, 0x02);
	/*=================================================================================*/

	/***************************Get the 100% position***********************************/
	/* Initialize the table */
	//for(i=0;i<40;i++) {
	//	table_PP_PL[i][0] = 0;
	//	table_PP_PL[i][1] = 0;
	//}
	//i = 0;

	/* Set the position to END_POSITION */
	thtlSetGoalPosition(THTL_END_POSITION, MX28R_RS485_Ptr);
	result = _lwevent_wait_ticks(&lwevent_setThrottle, 0x02, FALSE, 10);
	_lwevent_clear(&lwevent_setThrottle, 0x02);

	/* Cycle till the end of the movement */
	do{
		/* During this move, get the present position and the load corresponding of each position and record them in a table */
		//do {
		//	result = MX28_read_byte(0x28);
		//} while(result == LWEVENT_WAIT_TIMEOUT);

		//PL = result;

		do {
			result = MX28_read_byte(0x24);
		} while(result == LWEVENT_WAIT_TIMEOUT);

		PP = result;

		//if(i < 40)
		//{
		//	table_PP_PL[i][0] = PP;
		//	table_PP_PL[i][1] = PL;
		//	i++;
		//}

		/* Wait 10 ticks = 50 Ms */
		_time_delay_ticks(10);
	} while(MX28R_check_moving());

	/* Get the position of 100% */
	//P100 = table_PP_PL[i-1][0];
	P100 = PP;
	/*=================================================================================*/

	/*****************************Get the 0% position***********************************/
	/* Initialize the table */
	//for(i=0;i<40;i++) {
	//	table_PP_PL[i][0] = 0;
	//	table_PP_PL[i][1] = 0;
	//}
	//i = 0;

	/* Return the position to INITIAL_POSITION*/
	thtlSetGoalPosition(THTL_INITIAL_POSITION, MX28R_RS485_Ptr);
	result = _lwevent_wait_ticks(&lwevent_setThrottle, 0x02, FALSE, 10);
	_lwevent_clear(&lwevent_setThrottle, 0x02);

	/* Cycle till the end of the movement */
	do{
		/* During this move, get the present position and the load corresponding of each position and record them in a table */
		//do {
		//	result = MX28_read_byte(0x28);
		//} while(result == LWEVENT_WAIT_TIMEOUT);

		//PL = result;

		do {
			result = MX28_read_byte(0x24);
		} while(result == LWEVENT_WAIT_TIMEOUT);

		PP = result;

		//if(i < 40)
		//{
		//	table_PP_PL[i][0] = PP;
		//	table_PP_PL[i][1] = PL;
		//	i++;
		//}

		/* Wait 10 ticks = 50 Ms */
		_time_delay_ticks(10);
	} while(MX28R_check_moving());

	/* Get the position of 0% */
	//P0 = table_PP_PL[i-1][0];
	P0 = PP;
	/*=================================================================================*/
}

void MX28R_set_task(uint32_t task_init_data) {
  uint8_t thtlSubBuffer = 0x0;
  uint16_t thtlOrder;
  boolean thtlNeedChange;
  uint8_t thtlRequestCounter = 0;
  int8_t Error;

  MX28R_calibration();
  thtlBuffer = 0xFF;

  while (1) {
    /*Set Throttle*/
    if (FinalThtl < 0)
      FinalThtl = 0;
    if (FinalThtl > 100)
      FinalThtl = 100;
    if (FinalThtl != thtlBuffer) {
      // requested throttle is different from actual one
      if (thtlBuffer > FinalThtl) {
        //request reduction of throttle, execute immediately
        thtlBuffer = FinalThtl;
        //Mark that throttle need to be changed
        thtlNeedChange = TRUE;
      } else {
        //request augmentation of throttle, execute by several steps
        thtlRequestCounter++;
        if (thtlRequestCounter == THTL_REQUEST_NUMBER_TO_EXECUTE) {
          //Every (THTL_REQUEST_NUMBER_TO_EXECUTE x 5) Ms will add (THTL_ADD_STEP)% to throttle
          thtlRequestCounter = 0;
          //Mark that throttle need to be changed
          thtlNeedChange = TRUE;
          //Make add to the throttle, until it's bigger than target throttle
          thtlBuffer += THTL_ADD_STEP;
          if (thtlBuffer > FinalThtl)
            thtlBuffer = FinalThtl;
        }
      }
      if (thtlNeedChange) {
        thtlNeedChange = FALSE;
        thtlOrder = thtlBuffer ? P0 + thtlBuffer * (P100-P0) / 100 : P0;
        thtlSetGoalPosition(thtlOrder, MX28R_RS485_Ptr);
        _lwevent_wait_ticks(&lwevent_RS485, 0x02, FALSE, 50);
        _lwevent_clear(&lwevent_RS485, 0x02);
        if (_lwevent_wait_ticks(&lwevent_setThrottle, 0x06, FALSE, 50) == LWEVENT_WAIT_TIMEOUT) {
          //time_out
          Error = 1;
        } else {
          if (lwevent_setThrottle.VALUE & 0x02) {
            //success
            Error = 0;
          } else {
            //Checksum error
            Error = 2;
          }
          _lwevent_clear(&lwevent_setThrottle, 0x06);
        }
      }
    }
    _time_delay_ticks(1); // 5 ms step
  }
}

void MX28R_check_task(uint32_t task_init_data) {
  /* Initialization */
  uint8_t counter = 0;
  uint8_t length = 0;
  uint8_t i = 0;
  uint16_t checksum = 0;
  uint8_t* res_ptr = response;
  thtlInit();

  MX28R_RS485_ReceiveBlock(MX28R_RS485_Ptr, res_ptr, 1U);
  while (1) {
    _lwevent_wait_ticks(&lwevent_RS485, 0x01, FALSE, 0);
    if (counter != 0xff) {   //header not detected, so find header
      if (*res_ptr == 0xff) {
        counter++;
        if (counter == 2)
          counter = 0xff;
      } else
        counter = 0;
    } else {   //header detected, save the data
      i++;                             //number of valid byte received
      if (i == 2) {
        length = *res_ptr;                              //get length
        checksum += (*res_ptr);  //checksum calculate starts from ID
        res_ptr++;                                    //move pointer
      } else if (i == 3 && (*res_ptr != 0)) {
        checksum += (*res_ptr);
        res_ptr++;
      } else if (i == (2 + length)) {   //verify checksum
        checksum = (~(checksum & 0xFF)) & 0xFF; //calculate checksum
        if (checksum != *res_ptr) {
          //checksum error
          checksum = 0;
          _lwevent_set(&lwevent_setThrottle, 4);
        } else {
          //operation succeed
          _lwevent_set(&lwevent_setThrottle, 2);
          checksum = 0;
        }
        /* Clear the value prepare to next receive*/
        i = 0;
        counter = 0;
        checksum = 0;
        res_ptr = response;
      } else {
        checksum += (*res_ptr);                   //checksum from ID
        res_ptr++;                                    //move pointer
      }
    }
    MX28R_RS485_ReceiveBlock(MX28R_RS485_Ptr, res_ptr, 1U);
    _lwevent_clear(&lwevent_RS485, 0x01);
  }
}

void MX28R_OnCharRcv() {
  _lwevent_set(&lwevent_RS485, 0x01);
}

void MX28R_OnCmdTxComplete() {
  _lwevent_set(&lwevent_RS485, 0x02);
  MX28R_DE_ClrVal(MX28R_DE_Ptr);
  MX28R_RE_ClrVal(MX28R_RE_Ptr);
}
