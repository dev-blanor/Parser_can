//**************************************************************************************************
// @Module        CAN module implementations
// @Filename      CAN.h
//--------------------------------------------------------------------------------------------------
// @Description   This file contains all defines, data structures and function prototypes for the
//                CAN.
//--------------------------------------------------------------------------------------------------
// @Notes         
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          14.04.2015
//--------------------------------------------------------------------------------------------------
// @History       Version  Author    Comment
//                1.0.0    Sokolov   First release.
//
//**************************************************************************************************

#ifndef CAN_H
#define CAN_H

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <types.h>
#include <stdio.h>
//#include "Configuration.h"
//#include <Multican/Can/IfxMultican_Can.h>
//#include "ConfigurationIsr.h"
//#include "machine/cint.h"
#include "Can_drv_cfg.h"
#include "circ_buffer.h"
#include "CCPMonitor.h"
//*#include "stm32f1xx_hal.h"   // Я закоментил
//#include "S32K144.h"
//#include "CAN_lib.h"
//#include "GPT_drv.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Asc information */
#define CAN_MO_TX_TOTAL  (255U)

typedef struct
{
  uint32_t msgObjId;
} CAN_MsgObj;

typedef struct
{
  struct
  {
    CAN_MsgObj canDstMsgObj[3]; /**< \brief CAN Destination Message object */
    CAN_MsgObj canSrcMsgObj[CAN_MO_TX_TOTAL]; /**< \brief CAN Source Message object */
    uint32 MO_ID[CAN_MO_TX_TOTAL];
  }drivers;
} App_MulticanBasic;



/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/



/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

extern void CAN_Init(void);

extern uint16 API_CAN_Receive_Msg(const enCAN_NODE_NUM nodeNum,
		uint32 ReceivedMsgDataPtr,
		uint32* msgID,
		uint16* RBufLen);

extern enCAN_ERR API_CAN_Transmit_Msg(const enCAN_NODE_NUM nodeNum,
                                          const uint32 msgID,
                                          uint32 TransmitMsgDataPtr,
                                          const uint8 msgDataLng);

extern uint8 API_CAN_Transmit8_Msg(uint8 nodeNum,
                                       uint32 msgID,
                                       uint8 msgDataLng,
                                       uint8  TransmitMsgDataB0,
                                       uint8  TransmitMsgDataB1,
                                       uint8  TransmitMsgDataB2,
                                       uint8  TransmitMsgDataB3,
                                       uint8  TransmitMsgDataB4,
                                       uint8  TransmitMsgDataB5,
                                       uint8  TransmitMsgDataB6,
                                       uint8  TransmitMsgDataB7);

extern void API_CAN_Reverce8_Data(const uint32 AddrSrc);



#endif // #ifndef CAN_H
