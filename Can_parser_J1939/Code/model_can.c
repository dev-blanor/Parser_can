/*
 * -----------------------------------------------------------------------------
 * File Name    : model_can.c
 * Generated at : 25.04.2022 11:23:31 UTC
 * -----------------------------------------------------------------------------
 * Project      : MAZ_Bus_Receiver
 * Branch       : master
 * Commited at  : 25.04.2022 10:17:46 UTC
 * Commited by  : bca19489-c3a0-47a6-b790-73cf8804e421
 * Commit Id    : c3d3d6ed-f7f9-47ac-b4b8-194c34fc0cdc
 * -----------------------------------------------------------------------------
 * Tool version: 1.0.0.0 built at 22.04.2022 10:45:39 UTC
 * -----------------------------------------------------------------------------
 */

/* Includes ------------------------------------------------------------------*/

#include "model.h"

/* Definitions of global (public) variables ----------------------------------*/

/* Definitions of local (private) data types ---------------------------------*/

/* Definitions of local (private) constants ----------------------------------*/

/* Definitions of static global (private) variables --------------------------*/

/* Declarations of local (private) functions ---------------------------------*/

/* Definitions of global (public) functions ----------------------------------*/

void AG_CAN_ReadMessage(void *canBuffer, uint8_t canNode, uint32_t msgId, uint8_t msgLength)
{

    AG_CAN_ReadAsync(canNode, msgId, canBuffer, msgLength);

}

void AG_CAN_ReadAsync(uint8_t canNode, uint32_t msgId, void *canBuffer, uint8_t msgLength)
{

    if(0 == canNode)

    {

        CAN_Read_Async(canNode, msgId, canBuffer, msgLength);

    }

}

void CAN_Read_Async(uint8_t argIn0, uint32_t argIn1, void * argIn2, uint8_t argIn3)
{

    memcpy(CAN_Buffer_data, argIn2, argIn3 > 8 ? 8 : argIn3);

    CAN_InBox_ID_data = (argIn1);

    CAN_Delta_T_data = ((int32_t) 100);

    API_CAN_Analyze(CAN_Buffer_data, ((CAN_InBox_ID_data)), (((uint32_t) (CAN_Delta_T_data))));

}

/* Definitions of local (private) functions ----------------------------------*/

/* End of file ---------------------------------------------------------------*/

