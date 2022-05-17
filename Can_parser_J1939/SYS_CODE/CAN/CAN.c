//**************************************************************************************************
// @Module        CAN
// @Filename      CAN.c
//--------------------------------------------------------------------------------------------------
// @Description   This file contains functions for a CAN module.
//                Write and read operations are mutually independent.
//--------------------------------------------------------------------------------------------------
// @Notes         CAN driver for STM32 MCUs.
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          01.04.2020
//--------------------------------------------------------------------------------------------------
// @History       Version  Author    Comment
//                1.0.0    Sokolov   First release.
//
//**************************************************************************************************

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "CAN.h"
#include "CAN_lib.h"
#include "S32K144.h"
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
// Define type for the CAN debug counters
typedef volatile uint8 CAN_DBG_CNT;
// User can enable/disable the following CAN nodes

#define CAN_BUF_RX_SIZE  (30U)

// Size of the CAN transmit buffer in items
#define CAN_BUF_TX_SIZE  (70U)

// The total number of CAN nodes available
#define CAN_NODES_TOTAL  (2U)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
App_MulticanBasic g_MulticanBasic; /**< \brief Demo information */
//extern CAN_HandleTypeDef hcan1;
//extern CAN_HandleTypeDef hcan2;
//CAN_HandleTypeDef hcans[CAN_NODES_TOTAL];

/******************************************************************************/
/*------------------------------Local variables------------------------------*/

static stCIRCBUF Virtual_Circbuf0;
static stCIRCBUF Virtual_Circbuf1;
static stCIRCBUF_DATA Virtual_CircbufData0[CAN_BUF_TX_SIZE];
static stCIRCBUF_DATA Virtual_CircbufData1[CAN_BUF_TX_SIZE];
// Buffers for CAN receive and transmit items (frames) assigned to the corresponding CAN Nodes
static stCIRCBUF CAN_bufRx[CAN_NODES_TOTAL];
static stCIRCBUF CAN_bufTx[CAN_NODES_TOTAL];

// CAN receive and transmit buffers' data assigned to the corresponding CAN Nodes
static stCIRCBUF_DATA CAN_bufDataRx[CAN_NODES_TOTAL][CAN_BUF_RX_SIZE];
static stCIRCBUF_DATA CAN_bufDataTx[CAN_NODES_TOTAL][CAN_BUF_TX_SIZE];

// CAN receive and transmit buffer empty flags assigned to the corresponding CAN Nodes
static volatile boolean CAN_bufRxEmpty[CAN_NODES_TOTAL];
static volatile boolean CAN_bufTxEmpty[CAN_NODES_TOTAL];

// CAN receive and transmit buffer overflow counters assigned to the corresponding CAN Nodes
static uint16 CAN_bufRxOverflowCnt[CAN_NODES_TOTAL];
static uint16 CAN_bufTxOverflowCnt[CAN_NODES_TOTAL];

/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
// @Parameters    objNum - number of the message object.
//**************************************************************************************************
static void CAN_vTransmitToCANFromBuf(const enCAN_NODE_NUM nodeNum);
enCAN_ERR CAN_ReceiveMsg(const enCAN_NODE_NUM nodeNum,
        uint8* const pReceivedMsgNum, uint32* msgID,
        uint8* const pReceivedMsgData, uint8* msgDataLng);

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

const unsigned ID_CRO = 257;     // CRO (Command Receive Object) receive message
const unsigned ID_CRM = 258;    // CRM (Command Return Message) transmit message
const unsigned ID_EVT = 259;             // Event transmit message

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

//**************************************************************************************************
// @Function      void CAN_Init(void)
//--------------------------------------------------------------------------------------------------
// @Description   Initialization of CAN module
//--------------------------------------------------------------------------------------------------
// @Notes         This function is for STM32 MCUs CAN module.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    none.
//**************************************************************************************************
void CAN_Init(void)
{
    // Init virtual circbuf
    CIRCBUF_Init(&Virtual_Circbuf0, Virtual_CircbufData0, CAN_BUF_TX_SIZE);
    CIRCBUF_Init(&Virtual_Circbuf1, Virtual_CircbufData1, CAN_BUF_TX_SIZE);

    uint8_t nodeNum = 0;

    CAN0_Init();

    CIRCBUF_Init(&CAN_bufRx[nodeNum], CAN_bufDataRx[nodeNum], CAN_BUF_RX_SIZE);
    CIRCBUF_Init(&CAN_bufTx[nodeNum], CAN_bufDataTx[nodeNum], CAN_BUF_TX_SIZE);

    CAN_bufRxEmpty[nodeNum] = 0;
    CAN_bufTxEmpty[nodeNum] = 0;

    CAN_bufRxOverflowCnt[nodeNum] = 0U;
    CAN_bufTxOverflowCnt[nodeNum] = 0U;

    _InitCCPMonitor();
}

//**************************************************************************************************
// @Function      CAN_vTransmitToCANFromBuf
//--------------------------------------------------------------------------------------------------
// @Description   check circullar buffer and if new message existing send it to CAN
//--------------------------------------------------------------------------------------------------
// @Notes         This function is for STM32 MCUs CAN module.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    nodeNum - numbver of operating node.
//**************************************************************************************************
static void CAN_vTransmitToCANFromBuf(const enCAN_NODE_NUM nodeNum)
{
    stCIRCBUF_DATA stCANObjTXData;
    if (((CAN0->RAMn[0] & 0xF000000) >> 24) != 12)      // if CAN0->MB0 is not active
    {
        enCIRCBUF_ERR bufErr = CIRCBUF_GetData(&stCANObjTXData, &CAN_bufTx[nodeNum]);
        if (CIRCBUF_BufEmpty != bufErr)
        {
            uint8_t msgData[8];
            uint32_t CAN_ID = stCANObjTXData.stMessageContent.id;
            uint8_t DLC = stCANObjTXData.stMessageContent.length;
            uint8 i = 0U;
            for (; i < stCANObjTXData.stMessageContent.length; i++)
            {
                msgData[i] = stCANObjTXData.stMessageContent.data[i];
            }

            CAN0_Write(CAN_ID, DLC, msgData);

        } else
        {
            CAN_bufTxEmpty[nodeNum] = 1;
        }
    }
} // end of CAN_vTransmitToCANFromBuf()

//**************************************************************************************************
// @Function      CAN_TransmitMsg
//--------------------------------------------------------------------------------------------------
// @Description   transmit to can line msg
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    nodeNum - numbver of operating node.
//                transmitMsgNum - number of Message object
//                msgID - message identificator to send
//                pTransmitMsgData - pointer to message data
//                msgDataLng - data length
//**************************************************************************************************
enCAN_ERR CAN_TransmitMsg(const enCAN_NODE_NUM nodeNum,
        const uint8 transmitMsgNum, const uint32 msgID,
        const uint8* const pTransmitMsgData, const uint8 msgDataLng)
{

    enCIRCBUF_ERR bufErr;
    stCIRCBUF_DATA canObjTransmitData;

    // Fill the message data
    uint8 dataIdx = 0U;

    canObjTransmitData.stMessageContent.id = msgID;

    for (; dataIdx < msgDataLng; dataIdx++)
    {
        canObjTransmitData.stMessageContent.data[dataIdx] =
                pTransmitMsgData[dataIdx];
    }
    canObjTransmitData.stMessageContent.length = msgDataLng;

    // Set the message number
    canObjTransmitData.messageNum = transmitMsgNum;

    // Write the message to the CAN transmit buffer
    bufErr = CIRCBUF_PutData(&canObjTransmitData, &CAN_bufTx[nodeNum]);
    CAN_vTransmitToCANFromBuf(nodeNum);

    if (CIRCBUF_BufOverflow == bufErr)
    {
        CAN_bufTxOverflowCnt[nodeNum]++;
        return CAN_TX_BUF_FULL;
    } else
    {
        return CAN_NO_ERR;
    }
} // end of CAN_TransmitMsg()

//**************************************************************************************************
// @Function      CAN_vSetTransmitMsgObjStdID
//--------------------------------------------------------------------------------------------------
// @Description   configure message object and message ID of MO
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    objNum - message object number
//                canId - ID to MO below
//**************************************************************************************************
void CAN_vSetTransmitMsgObjStdID(const uint8 objNum, const uint16 canId)
{

} // end of CAN_vSetTransmitMsgObjStdID()

//**************************************************************************************************
// @Function      CAN_ReceiveMsg
//--------------------------------------------------------------------------------------------------
// @Description   Receiving CAN message data from circular buffer.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    nodeNum - numbver of operating node.
//                pReceivedMsgNum - number of Message object
//                msgID - message identificator to send
//                pReceivedMsgData - pointer to message data
//                msgDataLng - data length
//**************************************************************************************************
enCAN_ERR CAN_ReceiveMsg(const enCAN_NODE_NUM nodeNum,
        uint8* const pReceivedMsgNum, uint32* msgID,
        uint8* const pReceivedMsgData, uint8* msgDataLng)
{
    stCIRCBUF_DATA canObjReceiveData;

    // Read the message from the CAN receive buffer
    enCIRCBUF_ERR bufErr = CIRCBUF_GetData(&canObjReceiveData,
            &CAN_bufRx[nodeNum]);

    if (CIRCBUF_BufEmpty != bufErr)
    {
        // Store the message data
        *msgDataLng = canObjReceiveData.stMessageContent.length;

        for (uint8 dataIdx = 0; dataIdx < *msgDataLng; dataIdx++)
        {
            pReceivedMsgData[dataIdx] =
                    canObjReceiveData.stMessageContent.data[dataIdx];
        }

        // Store the message number
        *pReceivedMsgNum = canObjReceiveData.messageNum;
        *msgID = canObjReceiveData.stMessageContent.id;
        return CAN_NO_ERR;
    } else
    {
        return CAN_RX_BUF_EMPTY;
    }
} // end of CAN_ReceiveMsg()

//**************************************************************************************************
// @Function      HAL_CAN_RxFifo0MsgPendingCallback
//--------------------------------------------------------------------------------------------------
// @Description   CAN receiving callback funtion.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is for STM32 MCUs CAN module.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    hcan - HAL CAN handler.
//**************************************************************************************************
void HAL_CAN_RxFifo0MsgPendingCallback(uint32_t hcan)
{
//  CAN_RxHeaderTypeDef msgHeader;
    uint32_t RxID = 0;
    uint8_t RxLENGTH = 0;
    uint8_t msgData[8];

//  HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &msgHeader, msgData);
    CAN0_Read(&RxID, &RxLENGTH, msgData);

    stCIRCBUF_DATA CANObjRXData;
    CANObjRXData.messageNum = 0;

    CANObjRXData.stMessageContent.id = RxID;

//  if (msgHeader.IDE == CAN_ID_EXT)
//  {
//    CANObjRXData.stMessageContent.id = msgHeader.ExtId;
//  }
//  else
//  {
//    CANObjRXData.stMessageContent.id = msgHeader.StdId;
//  }

    CANObjRXData.stMessageContent.length = (uint8_t) RxLENGTH;

    uint8 i = 0U;
    for (; i < CANObjRXData.stMessageContent.length; i++)
    {
        CANObjRXData.stMessageContent.data[i] = msgData[i];
    }

    // Put MO data and MO number into the CAN receive buffer
    uint8_t nodeNum = 0;

//  for (uint8_t i = 0; i < CAN_NODES_TOTAL; i++)
//  {
//    if (hcan->Instance == hcans[i].Instance)
//    {
//      nodeNum = i;
//      break;
//    }
//  }
    enCIRCBUF_ERR bufErr = CIRCBUF_PutData(&CANObjRXData, &CAN_bufRx[nodeNum]);
    if (CIRCBUF_BufOverflow == bufErr)
    {
        CAN_bufRxOverflowCnt[nodeNum]++;
    }
}

//**************************************************************************************************
// @Function      HAL_CAN_TxMailbox0CompleteCallback
//                HAL_CAN_TxMailbox1CompleteCallback
//                HAL_CAN_TxMailbox2CompleteCallback
//--------------------------------------------------------------------------------------------------
// @Description   CAN transmitting callback functions.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is for STM32 MCUs CAN module.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    hcan - HAL CAN handler.
//**************************************************************************************************
void CAN_TxCompleteCallback(uint32_t hcan)
{
    uint8_t nodeNum = 0;

//  for (uint8_t i = 0; i < CAN_NODES_TOTAL; i++)
//  {
//    if (hcan->Instance == hcans[i].Instance)
//    {
//      nodeNum = i;
//      break;
//    }
//  }

    CAN_vTransmitToCANFromBuf((enCAN_NODE_NUM) nodeNum);
}

void HAL_CAN_TxMailbox0CompleteCallback(uint32_t hcan)
{
    CAN_TxCompleteCallback(hcan);
}

void HAL_CAN_TxMailbox1CompleteCallback(uint32_t hcan)
{
    CAN_TxCompleteCallback(hcan);
}

void HAL_CAN_TxMailbox2CompleteCallback(uint32_t hcan)
{
    CAN_TxCompleteCallback(hcan);
}

//**************************************************************************************************
// @Function      API_CAN_Receive_Msg
//--------------------------------------------------------------------------------------------------
// @Description   receiving CAN message data from circular buffer.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    nodeNum - numbver of operating node
//                ReceivedMsgDataPtr - pointer to message data
//                msgID - message identificator to send
//                RBufLen - data length
//**************************************************************************************************
uint16 API_CAN_Receive_Msg(const enCAN_NODE_NUM nodeNum,
        uint32 ReceivedMsgDataPtr, uint32* msgID, uint16* RBufLen)
{
    uint8 msgNum;
    uint8* const pReceivedMsgData = (uint8*) ReceivedMsgDataPtr;

    uint8 msgDataLng = 0;
    enCAN_ERR canErr = CAN_ReceiveMsg(nodeNum, &msgNum, msgID, pReceivedMsgData,
            &msgDataLng);
    if (canErr == CAN_RX_BUF_EMPTY)
    {
        *msgID = 0;
    }
    *RBufLen = CIRCBUF_CountNumberOfItems(&CAN_bufRx[nodeNum]);
    return msgDataLng;
}

//**************************************************************************************************
// @Function      API_CAN_Transmit8_Msg
//--------------------------------------------------------------------------------------------------
// @Description   transmit to can line msg
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    nodeNum - numbver of operating node
//                msgID - message identificator to send
//                msgDataLng - data
//                TransmitMsgDataBx - data bytes
//**************************************************************************************************
uint8 API_CAN_Transmit8_Msg(uint8 nodeNum, uint32 msgID, uint8 msgDataLng,
        uint8 TransmitMsgDataB0, uint8 TransmitMsgDataB1,
        uint8 TransmitMsgDataB2, uint8 TransmitMsgDataB3,
        uint8 TransmitMsgDataB4, uint8 TransmitMsgDataB5,
        uint8 TransmitMsgDataB6, uint8 TransmitMsgDataB7)
{
    uint8 CANMONum = 0;
    static stCAN_SWObj stCANObjTXContent;

    stCANObjTXContent.data[0] = TransmitMsgDataB0;
    stCANObjTXContent.data[1] = TransmitMsgDataB1;
    stCANObjTXContent.data[2] = TransmitMsgDataB2;
    stCANObjTXContent.data[3] = TransmitMsgDataB3;
    stCANObjTXContent.data[4] = TransmitMsgDataB4;
    stCANObjTXContent.data[5] = TransmitMsgDataB5;
    stCANObjTXContent.data[6] = TransmitMsgDataB6;
    stCANObjTXContent.data[7] = TransmitMsgDataB7;
    enCAN_ERR canErr = CAN_TransmitMsg((enCAN_NODE_NUM) nodeNum, CANMONum,
            msgID, stCANObjTXContent.data, msgDataLng);
    return canErr;
}

void API_CAN_Reverce8_Data(const uint32 AddrSrc)
{
    uint8* pSource;
    uint8 tempBuf = 0;

    pSource = (uint8*) AddrSrc;

    for (uint8 DLC_Cnt = 0; DLC_Cnt < 4; DLC_Cnt++)
    {
        tempBuf = pSource[DLC_Cnt];
        pSource[DLC_Cnt] = pSource[7 - DLC_Cnt];
        pSource[7 - DLC_Cnt] = tempBuf;
    }
}

//**************************************************************************************************
// @Function      API_CAN_Transmit_Msg
//--------------------------------------------------------------------------------------------------
// @Description   transmit to can line msg
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   none.
//--------------------------------------------------------------------------------------------------
// @Parameters    nodeNum - numbver of operating node
//                msgID - message identificator to send
//                TransmitMsgDataPtr - pointer to message data
//                msgDataLng - data length
//**************************************************************************************************
enCAN_ERR API_CAN_Transmit_Msg(const enCAN_NODE_NUM nodeNum, const uint32 msgID,
        uint32 TransmitMsgDataPtr, const uint8 msgDataLng)
{
    uint8 dataIdx = 0;
    uint8 CANMONum = 0U;
    stCAN_SWObj stCANObjTXContent;

    const uint8* const pTransmitMsgData = (uint8*) TransmitMsgDataPtr;

    for (; dataIdx < msgDataLng; dataIdx++)
    {
        stCANObjTXContent.data[dataIdx] = pTransmitMsgData[dataIdx];
    }
    enCAN_ERR canErr = CAN_TransmitMsg(nodeNum, CANMONum, msgID,
            stCANObjTXContent.data, msgDataLng);
    return canErr;
}

//**************************************************************************************************
