//**************************************************************************************************
// @Module        Circular buffer (CIRCBUF)
// @Filename      circ_buffer.c
//--------------------------------------------------------------------------------------------------
// @Description   This file contains functions for a circular buffer.
//                Write and read operations are mutually independent.
//
//                Global (public) functions:
//                  CIRCBUF_Init()
//                  CIRCBUF_PutData()
//                  CIRCBUF_GetData()
//                  CIRCBUF_Purge()
//                  CIRCBUF_CountNumberOfItems()
//--------------------------------------------------------------------------------------------------
// @Notes         The functions in this file are processor-independent.
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



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "circ_buffer.h" // Native header

//**************************************************************************************************
//==================================================================================================
// Global functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      CIRCBUF_Init()
//--------------------------------------------------------------------------------------------------
// @Description   Initializes a circular buffer. If the buffer or array of data for the buffer
//                are not available [rf1, rf3], returns corresponding error code [rf2, rf4].
//  If the size of the buffer is less than two item [rf5], returns error [rf6]. Otherwise initializes
//  pointer to data for the buffer [rf7] and sets initial values for the size [rf8], head [rf9]
//  and tail [rf10] of the buffer, and the function is completed without any error [rf11].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent. Size of the buffer must be more than one item,
//                an upper limit of stored items is less by one than size of the buffer.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   CIRCBUF_BufNotExist - buffer does not exist;
//                CIRCBUF_DataNotExist - data of buffer do not exist;
//                CIRCBUF_BufSizeTooSmall - size of buffer is less than 1 item;
//                CIRCBUF_NoErr - no error occurred.
//--------------------------------------------------------------------------------------------------
// @Parameters    pstThisCircBuf - pointer to a circular buffer;
//                pstThisArray - pointer to an array of data for the buffer;
//                usThisSize - size of the buffer in items.
//**************************************************************************************************
enCIRCBUF_ERR CIRCBUF_Init(stCIRCBUF* pstThisCircBuf,
                           const stCIRCBUF_DATA* pstThisArray,
                           uint16 usThisSize)
{
    if (0 == pstThisCircBuf)                                            // rf1
    {
        return CIRCBUF_BufNotExist;                                     // rf2
    }

    if (0 == pstThisArray)                                              // rf3
    {
        return CIRCBUF_DataNotExist;                                    // rf4
    }

    if (usThisSize < 2)                                                 // rf5
    {
        return CIRCBUF_BufSizeTooSmall;                                 // rf6
    }

    pstThisCircBuf->pstBufData = (stCIRCBUF_DATA*)pstThisArray;         // rf7
    pstThisCircBuf->usCircBufSize = usThisSize;                         // rf8
    pstThisCircBuf->usHead = 0U;                                        // rf9
    pstThisCircBuf->usTail = 0U;                                        // rf10

    return CIRCBUF_NoErr;                                               // rf11
} // end of CIRCBUF_Init()



//**************************************************************************************************
// @Function      CIRCBUF_PutData()
//--------------------------------------------------------------------------------------------------
// @Description   Puts one item into a circular buffer. If the item or the circular buffer are
//                not available [rf1, rf3], returns corresponding error code [rf2, rf4]. Checks free
//  space in the buffer [rf8] and returns corresponding error code if the buffer is full [rf9].
//  If free space is present, one item is put into head of the buffer [rf10], and the function is
//  completed without any error [rf12]. In order to provide mutual independence of the operations
//  CIRCBUF_PutData() and CIRCBUF_GetData(), all operations with the head of the buffer
//  (loopback [rf6, rf7] and writing the next item [rf10]) are carried out in the local variable [rf5].
//  The new value of the head will be set [rf11] only when data have been written into the buffer [rf10].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent. As the function contains global variable usHead,
//                it is not reentrant. That is why only transactional callings are allowed.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   CIRCBUF_BufNotExist - buffer does not exist;
//                CIRCBUF_DataNotExist - data of buffer do not exist;
//                CIRCBUF_BufOverflow - buffer overflow;
//                CIRCBUF_NoErr - no error occurred.
//--------------------------------------------------------------------------------------------------
// @Parameters    pstCircBufData - pointer to the item that must be put into
//                                 the buffer;
//                pstThisCircBuf - pointer to a circular buffer.
//**************************************************************************************************
enCIRCBUF_ERR CIRCBUF_PutData(const stCIRCBUF_DATA* pstCircBufData, stCIRCBUF* pstThisCircBuf)
{
    if (0 == pstCircBufData)                                            // rf1
    {
        return CIRCBUF_DataNotExist;                                    // rf2
    }

    if (0 == pstThisCircBuf)                                            // rf3
    {
        return CIRCBUF_BufNotExist;                                     // rf4
    }

    uint16 usHeadPlus = pstThisCircBuf->usHead + 1U;                    // rf5

    if (usHeadPlus == pstThisCircBuf->usCircBufSize)                    // rf6
    {
        usHeadPlus = 0U;                                                // rf7
    }

    if (usHeadPlus == pstThisCircBuf->usTail)                           // rf8
    {
        return CIRCBUF_BufOverflow;                                     // rf9
    }

    *(pstThisCircBuf->pstBufData + usHeadPlus) = *pstCircBufData;       // rf10

    pstThisCircBuf->usHead = usHeadPlus;                                // rf11

    return CIRCBUF_NoErr;                                               // rf12
} // end of CIRCBUF_PutData()



//**************************************************************************************************
// @Function      CIRCBUF_GetData()
//--------------------------------------------------------------------------------------------------
// @Description   Gets and removes one item from a circular buffer. If the item or the buffer
//                are not available [rf1, rf3], returns corresponding error code [rf2, rf4].
//  Checks data presence in the buffer [rf5] and returns corresponding error code if the buffer
//  is empty [rf6]. If unread data is present, the oldest item is taken out from the tail of the
//  buffer and written into variable [rf10], and the function is completed without any error [rf12].
//  In order to provide mutual independence of the operations CIRCBUF_PutData() and CIRCBUF_GetData(),
//  all operation with the tail of the buffer (loopback [rf8, rf9] and reading the next item [rf10])
//  are carried out in the local variable [rf7]. The new value of the tail will be set [rf11] only when
//  corresponding item of the buffer have been released [rf10].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent. As the function contains global variable usTail,
//                it is not reentrant. That is why only transactional callings are allowed.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   CIRCBUF_BufNotExist - buffer does not exist;
//                CIRCBUF_DataNotExist - data of buffer do not exist;
//                CIRCBUF_BufEmpty - buffer is empty;
//                CIRCBUF_NoErr - no error occurred.
//--------------------------------------------------------------------------------------------------
// @Parameters    pstCircBufData - pointer to the variable where data that
//                                 extracted from the buffer will be stored;
//                pstThisCircBuf - pointer to a circular buffer.
//**************************************************************************************************
enCIRCBUF_ERR CIRCBUF_GetData(stCIRCBUF_DATA* pstCircBufData,
                              stCIRCBUF* pstThisCircBuf)
{
    if (0 == pstCircBufData)                                            // rf1
    {
        return CIRCBUF_DataNotExist;                                    // rf2
    }

    if (0 == pstThisCircBuf)                                            // rf3
    {
        return CIRCBUF_BufNotExist;                                     // rf4
    }

    if (pstThisCircBuf->usTail == pstThisCircBuf->usHead)               // rf5
    {
        return CIRCBUF_BufEmpty;                                        // rf6
    }

    uint16 usTailPlus = pstThisCircBuf->usTail + 1U;                    // rf7

    if (usTailPlus == pstThisCircBuf->usCircBufSize)                    // rf8
    {
        usTailPlus = 0U;                                                // rf9
    }

    *pstCircBufData = *(pstThisCircBuf->pstBufData + usTailPlus);       // rf10

    pstThisCircBuf->usTail = usTailPlus;                                // rf11
    return CIRCBUF_NoErr;                                               // rf12
} // end of CIRCBUF_GetData()



//**************************************************************************************************
// @Function      CIRCBUF_Purge()
//--------------------------------------------------------------------------------------------------
// @Description   Cleans a circular buffer. If the buffer is not available [rf1], returns
//                corresponding error code [rf2]. Otherwise cleans the buffer [rf3], and the function
//                is completed without any error [rf4].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   CIRCBUF_BufNotExist - buffer does not exist;
//                CIRCBUF_NoErr - no error occurred.
//--------------------------------------------------------------------------------------------------
// @Parameters    pstThisCircBuf - pointer to a circular buffer.
//**************************************************************************************************
enCIRCBUF_ERR CIRCBUF_Purge(stCIRCBUF* pstThisCircBuf)
{
    if (0 == pstThisCircBuf)                                            // rf1
    {
        return CIRCBUF_BufNotExist;                                     // rf2
    }

    pstThisCircBuf->usTail = pstThisCircBuf->usHead;                    // rf3

    return CIRCBUF_NoErr;                                               // rf4
} // end of CIRCBUF_Purge()



//**************************************************************************************************
// @Function      CIRCBUF_CountNumberOfItems()
//--------------------------------------------------------------------------------------------------
// @Description   Calculates the number of busy elements in a circular buffer. In order to provide
//                signal-safety from the operations CIRCBUF_PutData() and CIRCBUF_GetData(), the head
//  and tail difference is assigned to the signed local variable [rf3]. If loopback occurred and the
//  tail has not reached the end of the buffer yet [rf4], the head and tail difference is negative,
//  so the difference and the size are summed up [rf5] to calculate the number of busy elements
//  correctly. The function returns the number of busy elements in the circular buffer [rf6] or 0 [rf2]
//  if the buffer is not available [rf1].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   0 - buffer does not exist or empty;
//                [1..65534] - number of busy elements in a circular buffer.
//--------------------------------------------------------------------------------------------------
// @Parameters    pstThisCircBuf - pointer to a circular buffer.
//**************************************************************************************************
uint16 CIRCBUF_CountNumberOfItems(const stCIRCBUF* pstThisCircBuf)
{
    if (0 == pstThisCircBuf)                                            // rf1
    {
        return 0U;                                                      // rf2
    }

    sint32 swNumElem = (sint32)(pstThisCircBuf->usHead - pstThisCircBuf->usTail); // rf3

    if (swNumElem < 0)                                                  // rf4
    {
        swNumElem += pstThisCircBuf->usCircBufSize;                     // rf5
    }

    return (uint16)swNumElem;                                           // rf6
} // end of CIRCBUF_CountNumberOfItems()



//****************************************** end of file *******************************************
