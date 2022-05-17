//**************************************************************************************************
// @Module        CCP
// @Filename      CCPMonitor.h
//--------------------------------------------------------------------------------------------------
// @Description   Header file for CCP module functionality.
//                This file contains defines and function prototypes for CCP Monitor module.
//--------------------------------------------------------------------------------------------------
// @Notes         The constants in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.1.0
//--------------------------------------------------------------------------------------------------
// @Date          01.04.2020
//--------------------------------------------------------------------------------------------------
// @History       Version  Author       Comment
//                1.0.1    ASD          First release.
//                1.0.2    ASD          Debugging via CCP added.
//                1.0.5    ASD          Added declaration of CCP enable flag.
//                1.0.6    AsSD         Added independence on startup code.
//                1.0.7    ASD          Added saving calibration data into flash ECU.
//                1.1.0    Sokolov      Added STM32 support
//**************************************************************************************************

#ifndef CCP_MONITOR_H
#define CCP_MONITOR_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "can_drv.h"        // Define CAN functions      // ﬂ «¿ ŒÃ≈Õ“»À!!!!!!!!!!!
#include "CCP_cfg.h"        // Get configuration of CCP
#include "CalRAM.h"         // Define Calibration RAM functions;
#include "CAN.h"                                      // ﬂ «¿ ŒÃ≈Õ“»À!!!!!!!!!!!



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// CCP support 
// 0 - full support
// 1 - partial support, unused commands removed
// 2 - DAQ + calibration support
// 3 - DAQ support
#define CCP_SUPPORT_LEVEL                                               0

extern volatile uint8 osCCPENABLE;
extern uint8 osCOPYWPTORP;

extern const unsigned ID_CRO;                   // CRO (Command Receive Object) receive message
extern const unsigned ID_CRM;                   // CRM (Command Return Message) transmit message
extern const unsigned ID_EVT;
extern const unsigned ID_ISO_IN;                // CRO (Command Receive Object) receive message
extern const unsigned ID_ISO_OUT;               // CRO (Command Receive Object) receive message

//**************************************************************************************************
// Prototypes of global (public) functions
//**************************************************************************************************

extern void _InitCCPMonitor(void);
extern void API_CAN_Thread_CCP(uint32 const MsgId,
                               uint32 const Buffer8_Addr
                               );

extern void API_CAN_Thread_HexFlash();

extern void vProcessCCPCmd(void);
extern void _DAQprocessor(const uint32 uwEventChannel);

extern void CCP_vSaveCalibrationData(const boolean forceSave);



#endif // #ifndef CCP_MONITOR_H

//****************************************** end of file *******************************************
