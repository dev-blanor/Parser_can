//**************************************************************************************************
// @Module        Circular buffer (CIRCBUF)
// @Filename      circ_buffer.h
//--------------------------------------------------------------------------------------------------
// @Description   This file contains all defines, data structures and function prototypes for the
//                circular buffer.
//--------------------------------------------------------------------------------------------------
// @Notes         The constants in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.0.2
//--------------------------------------------------------------------------------------------------
// @Date          27.05.2020
//--------------------------------------------------------------------------------------------------
// @History       Version  Author    Comment
//                1.0.0    ASD       First release.
//                1.0.1    ASD       Adapted for a lot of MISRA-C 2004 rules.
//                1.0.2    Sokolov   Adapted for LIN.
//**************************************************************************************************

#ifndef CIRC_BUFFER_H
#define CIRC_BUFFER_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "types.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// Definition of common message object struct
typedef struct {
    uint32_t id;                // Message ID
    uint8_t direction;          // Exchange direction
    uint8_t length;             // Data length in bytes
    union {                     // Data
        uint8  data[8];           
        uint64 frame;
    };
} stCIRCBUF_MESSAGE;

// Definition of data structure of a circular buffer
typedef struct _stCircBufData {
    uint8_t messageNum;                 // Number of the Message Object
    stCIRCBUF_MESSAGE stMessageContent;
} stCIRCBUF_DATA;                       // Data structure of a circular buffer

//Definition of a structure of a circular buffer
typedef struct _CircBuf {
    stCIRCBUF_DATA* pstBufData;         // Pointer to a data of a circular buffer
    uint16         usCircBufSize;       // Size of a buffer in items
    uint16         usHead;              // Head of buffer, where data is prepended
    uint16         usTail;              // Tail of buffer, where data is removed from
} stCIRCBUF;                            // Circular buffer

// Definition of all errors for a circular buffer
typedef enum {
    CIRCBUF_NoErr           = 0x00, // No error occurred
    CIRCBUF_BufEmpty        = 0x01, // Buffer is empty
    CIRCBUF_BufOverflow     = 0x02, // Buffer overflow
    CIRCBUF_BufSizeTooSmall = 0x04, // Size of buffer is less than 1 item
    CIRCBUF_BufNotExist     = 0x08, // Buffer doesn't exist
    CIRCBUF_DataNotExist    = 0x10  // Data of buffer don't exist
} enCIRCBUF_ERR;                    // Error flags for register of all type of errors



//**************************************************************************************************
// Prototypes of global (public) functions
//**************************************************************************************************

extern enCIRCBUF_ERR CIRCBUF_Init(stCIRCBUF* pstThisCircBuf,
                                  const stCIRCBUF_DATA* pstThisArray,
                                  uint16 usThisSize);

extern enCIRCBUF_ERR CIRCBUF_PutData(const stCIRCBUF_DATA* pstCircBufData,
                                     stCIRCBUF* pstThisCircBuf);

extern enCIRCBUF_ERR CIRCBUF_GetData(stCIRCBUF_DATA* pstCircBufData,
                                     stCIRCBUF* pstThisCircBuf);

extern enCIRCBUF_ERR CIRCBUF_Purge(stCIRCBUF* pstThisCircBuf);

extern uint16 CIRCBUF_CountNumberOfItems(const stCIRCBUF* pstThisCircBuf);



#endif // #ifndef CIRC_BUFFER_H

//****************************************** end of file *******************************************
