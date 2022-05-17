/*
 * -----------------------------------------------------------------------------
 * File Name    : api_functions.h
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

#ifndef API_FUNCTIONS_H
#define API_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "model_types.h"

/* Definitions of global (public) data types ---------------------------------*/

/* Definitions of global (public) constants ----------------------------------*/

/* Declarations of global (public) variables ---------------------------------*/

extern float_t *ptrPositionVar_data;
extern float_t *ptrVar_data;
extern float_t *ptrVar1_data;
extern float_t *ptrSize_data;
extern uint32_t *ptrCollor_data;
extern uint32_t *ptrMapCollor_data;
extern uint32_t *ptrColorChange_data;
extern float_t Factor_data;
extern uint32_t Alpha_data;
extern uint32_t Red_data;
extern uint32_t Green_data;
extern uint32_t Blue_data;
extern float_t *PictPosMenuLvl_0_data;
extern int8_t *ptrBusDoorI_data;
extern float_t *ptrBusDoorH_data;
extern float_t *ptrScaleVar_data;
extern float_t *ptrScaleState_data;
extern uint8_t *Buffer_data;
extern uint8_t Index_data;
extern uint64_t Result_data;
extern uint8_t *BufferSPNandFMI_data;
extern int8_t TestSendCAN_data;
extern int8_t TestSendCAN1_data;
extern int8_t TestSendCAN2_data;
extern int8_t TestSendCAN3_data;

/* Declarations of global (public) functions ---------------------------------*/

extern double_t LinearScale(double_t argIn0, double_t argIn1, double_t argIn2, double_t argIn3, double_t argIn4);

extern void LerpPtr_200ms(void *param0, float_t argIn0);

extern void AlphaGradientLimitter(void *param0, double_t argIn0, int32_t argIn1);

extern float_t Lerp(float_t argIn0, float_t argIn1, int32_t argIn2);

extern int32_t If_1(int32_t argIn0);

extern void AlphaGradientLimitter250ms(void *param0, uint8_t argIn0);

extern void SizeNumbers(void *param0, double_t argIn0);

extern int32_t If_0(int32_t argIn0);

extern void BrightenessColorLimitter(void *param0, uint32_t argIn0, int32_t argIn1);

extern uint8_t API_GetDigitalPin(uint8_t argIn0);

extern void MapColor(void *param0, uint32_t argIn0, uint32_t argIn1, int32_t argIn2);

extern void ColorChange(void *param0, double_t argIn0, double_t argIn1, double_t argIn2, uint32_t argIn3, uint32_t argIn4);

extern void SetPictPosMenuLvl_0(void *param0, float_t argIn0);

extern void BusDoorOpen(void *param0, void *param1, int32_t argIn0, int32_t argIn1, int32_t argIn2, int32_t argIn3, int32_t argIn4, double_t argIn5);

extern void IgnitionStartAnimationScale(void *param0, void *param1, int16_t argIn0, double_t argIn1);

extern uint64_t API_CAN_ReadValueFromBuffer(void *param0, uint8_t argIn0, uint8_t argIn1, uint8_t argIn2);

extern void API_Write_2bit_data_to_buffer(void *param0, uint8_t argIn0, uint8_t argIn1, uint8_t argIn2);

extern void API_Copy_To_Buffer(void *param0, void *param1, uint8_t argIn0, uint8_t argIn1, uint8_t argIn2);

extern void API_ResetBuffer(void *param0);

extern int32_t API_Autogramma_CAN_Send(void *param0, uint32_t argIn0);

extern double_t API_CAN_WriteSPNandFMI(void *param0, double_t argIn0, double_t argIn1, double_t argIn2, double_t *argOut1);

extern void API_CAN_Analyze(void *param0, uint32_t argIn0, uint32_t argIn1);

extern int64_t API_GetCurrentTime_ms(void);

extern void API_FilterData(void);

extern void API_Send_Msg_FFAA(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef API_FUNCTIONS_H */

/* End of file ---------------------------------------------------------------*/

