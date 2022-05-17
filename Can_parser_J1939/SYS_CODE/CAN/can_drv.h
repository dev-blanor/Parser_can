//**************************************************************************************************
// @Module        CAN driver
// @Filename      can_drv.h
//--------------------------------------------------------------------------------------------------
// @Description   This file contains all function prototypes and macros for the MultiCAN module.
//--------------------------------------------------------------------------------------------------
// @Notes         This file contains defines, specific to Infineon C166 processor family.
//--------------------------------------------------------------------------------------------------
// @Version       2.1.0
//--------------------------------------------------------------------------------------------------
// @Date          20.05.2012
//--------------------------------------------------------------------------------------------------
// @History       Version  Author    Comment
//                1.0.1    ASD       First release.
//                2.0.0    ASD       Refactoring. Adapted to use more than one CAN node.
//                2.1.0    ASD       Added reading CAN Node status.
//**************************************************************************************************

//#ifndef CAN_DRV_H
//#define CAN_DRV_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

/*#include "stm32f1xx_hal.h"*/  #include "S32K144.h"
#include "types.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// Enumeration for the number of a CAN Node
typedef enum {
    CAN_NODE_FIRST = 0,
    CAN_NODE_0 = 0,
    CAN_NODE_1 = 1,
    CAN_NODE_LAST = 1
} enCAN_NODE_NUM;



// Definition of a structure for the CAN data (software message object)
// The field MOCfg contains:
// - Data Length Code (DLC)
// - Identifier Extension bit (IDE) - if 0 standard frame, else 1 extended frame
// - Message Direction (DIR) - if 0 receive object, else 1 transmit object
// - Acceptance Mask bit (MIDE) - if 0 receives both, else 1 receives matching IDE
//    7     6     5     4     3     2     1     0
// |-----------------------------------------------|
// |     | MIDE |IDE | DIR |          DLC          |
// |-----------------------------------------------|
typedef struct {
    uint32 id;       // Standard (11-bit) / extended (29-bit) identifier
    uint8 dlc;       // Standard (11-bit) / extended (29-bit) identifier
    union {
    	uint8  data[8];  // 8 bytes containing the data of a frame
    	uint64 frame;
    };

} stCAN_SWObj;

// Definition of the all errors of the CAN Driver
typedef enum {
    CAN_NO_ERR,       // No error occurred
    CAN_RX_BUF_EMPTY, // No data to receive because of empty receive buffer
    CAN_TX_BUF_FULL,  // Cannot transmit data because of full transmit buffer
    CAN_BUS_OFF,      // CAN Node is in the bus-off state
} enCAN_ERR;



//**************************************************************************************************
// Prototypes of global (public) functions
 //**************************************************************************************************

extern void CAN_vInit(void);

extern void CAN_vSetTransmitMsgObjStdID(const uint8 objNum,
                                        const uint16 canId);

extern enCAN_ERR CAN_ReceiveMsg	(const enCAN_NODE_NUM nodeNum,
                                 uint8* const pReceivedMsgNum,
                                 uint32* msgID,
                                 uint8* const pReceivedMsgData,
                                 uint8* msgDataLng);

extern enCAN_ERR CAN_TransmitMsg(const enCAN_NODE_NUM nodeNum,
                                 const uint8 transmitMsgNum,
                                 const uint32 msgID,
                                 const uint8* const pTransmitMsgData,
                                 const uint8 msgDataLng);



//#endif // #ifndef CAN_DRV_H           // Я закоментил потомучто не нашел if

//****************************************** end of file *******************************************
