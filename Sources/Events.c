/* ###################################################################
 **     Filename    : Events.c
 **     Project     : MX28R_Dev
 **     Processor   : MK64FN1M0VLQ12
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2017-03-08, 14:59, # CodeGen: 0
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Contents    :
 **         Cpu_OnNMI - void Cpu_OnNMI(void);
 **
 ** ###################################################################*/
/*!
 ** @file Events.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup Events_module Events module documentation
 **  @{
 */
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "MX28R.h"
/*
 ** ===================================================================
 **     Event       :  Cpu_OnNMI (module Events)
 **
 **     Component   :  Cpu [MK64FN1M0LQ12]
 */
/*!
 **     @brief
 **         This event is called when the Non maskable interrupt had
 **         occurred. This event is automatically enabled when the [NMI
 **         interrupt] property is set to 'Enabled'.
 */
/* ===================================================================*/
void Cpu_OnNMI(void) {
  /* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  MX28R_RS485_OnBlockReceived (module Events)
 **
 **     Component   :  MX28R_RS485 [Serial_LDD]
 */
/*!
 **     @brief
 **         This event is called when the requested number of data is
 **         moved to the input buffer.
 **     @param
 **         UserDataPtr     - Pointer to the user or
 **                           RTOS specific data. This pointer is passed
 **                           as the parameter of Init method.
 */
/* ===================================================================*/
void MX28R_RS485_OnBlockReceived(LDD_TUserData *UserDataPtr) {
  MX28R_OnCharRcv();
}

/*
 ** ===================================================================
 **     Event       :  MX28R_RS485_OnTxComplete (module Events)
 **
 **     Component   :  MX28R_RS485 [Serial_LDD]
 */
/*!
 **     @brief
 **         This event indicates that the transmitter is finished
 **         transmitting all data, preamble, and break characters and is
 **         idle. It can be used to determine when it is safe to switch
 **         a line driver (e.g. in RS-485 applications).
 **         The event is available only when both [Interrupt
 **         service/event] and [Transmitter] properties are enabled.
 **     @param
 **         UserDataPtr     - Pointer to the user or
 **                           RTOS specific data. This pointer is passed
 **                           as the parameter of Init method.
 */
/* ===================================================================*/
void MX28R_RS485_OnTxComplete(LDD_TUserData *UserDataPtr) {
  MX28R_OnCmdTxComplete();
}

/* END Events */

#ifdef __cplusplus
} /* extern "C" */
#endif 

/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
