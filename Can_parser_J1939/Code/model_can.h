/*
 * -----------------------------------------------------------------------------
 * File Name    : model_can.h
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

#ifndef MODEL_CAN_H
#define MODEL_CAN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "model_types.h"

/* Definitions of global (public) data types ---------------------------------*/

/* Definitions of global (public) constants ----------------------------------*/

/* Declarations of global (public) variables ---------------------------------*/

/* Declarations of global (public) functions ---------------------------------*/

extern void AG_CAN_Open(uint8_t argIn0);

extern void AG_CAN_Close(uint8_t argIn0);

extern void AG_CAN_WriteMessage(uint8_t argIn0, uint32_t argIn1, void * argIn2, uint8_t argIn3);

extern void AG_CAN_ReadMessage(void *canBuffer, uint8_t canNode, uint32_t msgId, uint8_t msgLength);

extern void AG_CAN_ReadAsync(uint8_t canNode, uint32_t msgId, void *canBuffer, uint8_t msgLength);

extern void CAN_Read_Async(uint8_t argIn0, uint32_t argIn1, void * argIn2, uint8_t argIn3);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MODEL_CAN_H */

/* End of file ---------------------------------------------------------------*/

