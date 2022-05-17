//**************************************************************************************************
// @Module        CCP
// @Filename      CCP_cfg.h
//--------------------------------------------------------------------------------------------------
// @Description   This file contains configuration of the required functionality of the CCP module.
//--------------------------------------------------------------------------------------------------
// @Notes         The constants in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.0.4
//--------------------------------------------------------------------------------------------------
// @Date          20.06.2011
//--------------------------------------------------------------------------------------------------
// @History       Version  Author    Comment
//                1.0.1    ASD       First release.
//                1.0.2    ASD       Added address ranges for debugging via CCP.
//                1.0.3    ASD       Added independence on startup code.
//                1.0.4    ASD       Adapted for a lot of MISRA-C 2004 rules.
//**************************************************************************************************

#ifndef CCP_CFG_H
#define CCP_CFG_H



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// User can enable/disable CCP on initialization
#define CCP_ON_INIT_ENABLED     (ON)

// User can specify CAN node number used by CCP
// Temp
#define CCP_CAN_NODE_NUM        (0U)

// User can specify Message Object (MO) numbers used by CCP
#define CCP_CRM_MO_NUM          (8U)  // MO is used for CRM, transmit
#define CCP_EVM_MO_NUM          (9U)  // MO is used for Event Message, transmit
#define CCP_DAQ_0_MO_NUM        (10U) // MO is used for DAQ list 0, transmit
#define CCP_DAQ_1_MO_NUM        (11U) // MO is used for DAQ list 1, transmit
#define CCP_DAQ_2_MO_NUM        (12U) // MO is used for DAQ list 2, transmit
#define CCP_DAQ_3_MO_NUM        (13U) // MO is used for DAQ list 3, transmit
#define CCP_EMU_4_MO_NUM        (14U) // MO is used for DAQ list 4 (emulation), transmit

// User can choose type of CCP Master device from the following:
// 0 - CCP Master is INCA v5.3 through ETAS PCMCIA (default)
// 1 - CCP Master is INCA v5.4 through ETAS PCMCIA
// 2 - CCP Master is INCA through ELCAR USB
#define CCP_FOR_MASTER  (1)

// User can specify the Identifier of CCP Slave device:
#define CCP_SLAVE_DEV_ID  "M12"

// User can specify address ranges for debugging via CCP
#define CCP_DBGMEM1_LOW_LIM     APP_RAM_start // Lower limit of available memory1 for debugging
#define CCP_DBGMEM1_UPP_LIM     APP_RAM_end   // Upper limit of available memory1 for debugging

// Null pointer
#define P_NULL                  ((void*)(0))
#ifndef NULL_PTR
#define NULL_PTR                (0)
#endif

#endif // #ifndef CCP_CFG_H



//****************************************** end of file *******************************************
