//**************************************************************************************************
// @Module        Data Domain
// @Filename      DD_LIB.h
//--------------------------------------------------------------------------------------------------
// @Description   Interface of the Data Domain module.
//--------------------------------------------------------------------------------------------------
// @Notes         The constants in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          05/08/2015
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
//                1.0.0    Semenov     First release.
//**************************************************************************************************



//**************************************************************************************************
// Includes
//**************************************************************************************************

#include "stdint.h"
#include "types.h"
#include "DD_LIB_cfg.h"

#ifdef CALLIBRATION_TOOLS
#include "CCPMonitor.h"
#include "CalRAM.h"
#endif



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

typedef union DD_STRUCTURED_WORD_UNION_tag
{
  struct
  {
    U8  lowbyte;
    U8  highbyte;
  } byte;
  U16 word;
} DD_STRUCTURED_WORD_TYPE;

typedef union DD_STRUCTURED_DWORD_UNION_tag
{
  struct
  {
    U8  byte0;
    U8  byte1;
    U8  byte2;
    U8  byte3;
  } dwbyte;
  struct
  {
    U16 lowword;
    U16 highword;
  } wrd;
  U32 dblword;
} DD_STRUCTURED_DWORD_TYPE;



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

#ifndef NULL
#define NULL    (0)
#endif

#ifndef DD_LIB_H
#define DD_LIB_H
#endif



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

// Функция замены адреса в том случае, если данные, расположенные по этому адресу
// находятся в активной рабочей странице
extern U8* DD_Update_Calibr_Addr (U8* AddrData);


// Функции обновления осей, вычисляют коэффициент интерполяции
// Аргументы:   pCData - указатель на массив с данными оси
//              pdCLastIdx - индекс последнего узла
//              NodeNum - указатель на номер узла
//              IntrNodeCoef - указатель на значение коэффициента интерполяции
//              UpdResVal - указатель на результирующее значение оси
//              Value - значение оси
//              Interpolation_Type - тип интерполяции
extern U8 DD_Update_Axis_single(const float* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, float* UpdResVal,const float Value, const U8 Interpolation_Type);
extern U8 DD_Update_Axis_double(const double* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, double* UpdResVal,const double Value, const U8 Interpolation_Type);
extern U8 DD_Update_Axis_u8(const U8* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, U8* UpdResVal,const U8 Value, const U8 Interpolation_Type);
extern S8 DD_Update_Axis_s8(const S8* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, S8* UpdResVal,const S8 Value, const U8 Interpolation_Type);
extern U16 DD_Update_Axis_u16(const U16* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, U16* UpdResVal,const U16 Value, const U8 Interpolation_Type);
extern S16 DD_Update_Axis_s16(const S16* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, S16* UpdResVal,const S16 Value, const U8 Interpolation_Type);
extern U32 DD_Update_Axis_u32(const U32* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, U32* UpdResVal,const U32 Value, const U8 Interpolation_Type);
extern S32 DD_Update_Axis_s32(const S32* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, S32* UpdResVal,const S32 Value, const U8 Interpolation_Type);



// Функции чтения значения переменной. Учитывают, находятся ли данные в 
// активной рабочей странице
// Аргументы:   AddrData - адрес данных
extern float DD_Read_single(const float* AddrData);
extern double DD_Read_double(const double* AddrData);
extern U8 DD_Read_u8(const U8* AddrData);
extern S8 DD_Read_s8(const S8* AddrData);
extern U16 DD_Read_u16(const U16* AddrData);
extern S16 DD_Read_s16(const S16* AddrData);
extern U32 DD_Read_u32(const U32* AddrData);
extern S32 DD_Read_s32(const S32* AddrData);



// Функции вычисления значения табличной функции одной оси координат
// Аргументы:   AddrData - указатель на данные
//              NodeNum - номер узла
//              IntrNodeCoef - значение коэффициента интерполяции
extern float DD_1axis_Read_single(const float* AddrData,const U8 NodeNum,const U8 IntrNodeCoef);
extern double DD_1axis_Read_double(const double* AddrData,const U8 NodeNum,const U8 IntrNodeCoef);
extern U8 DD_1axis_Read_u8(const U8* AddrData,const U8 NodeNum,const U8 IntrNodeCoef);
extern S8 DD_1axis_Read_s8(const S8* AddrData,const U8 NodeNum,const U8 IntrNodeCoef);
extern U16 DD_1axis_Read_u16(const U16* AddrData,const U8 NodeNum,const U8 IntrNodeCoef);
extern S16 DD_1axis_Read_s16(const S16* AddrData,const U8 NodeNum,const U8 IntrNodeCoef);
extern U32 DD_1axis_Read_u32(const U32* AddrData,const U8 NodeNum,const U8 IntrNodeCoef);
extern S32 DD_1axis_Read_s32(const S32* AddrData,const U8 NodeNum,const U8 IntrNodeCoef);


 
// Функции вычисления значения табличной функции двух осей координат
// Аргументы:   AddrData - указатель на данные
//              sizeX - размерность по оси x
//              NodeNumX - номер узла по оси x
//              NodeNumY - номер узла по оси y
//              IntrNodeCoefX - значение коэффициента интерполяции по оси x
//              IntrNodeCoefY - значение коэффициента интерполяции по оси y
extern float DD_2axis_Read_single(const float* AddrData,const U16 sizeX,const U8 NodeNumX,const U8 NodeNumY,const U8 IntrNodeCoefX,const U8 IntrNodeCoefY);
extern double DD_2axis_Read_double(const double* AddrData,const U16 sizeX,const U8 NodeNumX,const U8 NodeNumY,const U8 IntrNodeCoefX,const U8 IntrNodeCoefY);
extern U8 DD_2axis_Read_u8(const U8* AddrData,const U16 sizeX,const U8 NodeNumX,const U8 NodeNumY,const U8 IntrNodeCoefX,const U8 IntrNodeCoefY);
extern S8 DD_2axis_Read_s8(const S8* AddrData,const U16 sizeX,const U8 NodeNumX,const U8 NodeNumY,const U8 IntrNodeCoefX,const U8 IntrNodeCoefY);
extern U16 DD_2axis_Read_u16(const U16* AddrData,const U16 sizeX,const U8 NodeNumX,const U8 NodeNumY,const U8 IntrNodeCoefX,const U8 IntrNodeCoefY);
extern S16 DD_2axis_Read_s16(const S16* AddrData,const U16 sizeX,const U8 NodeNumX,const U8 NodeNumY,const U8 IntrNodeCoefX,const U8 IntrNodeCoefY);
extern U32 DD_2axis_Read_u32(const U32* AddrData,const U16 sizeX,const U8 NodeNumX,const U8 NodeNumY,const U8 IntrNodeCoefX,const U8 IntrNodeCoefY);
extern S32 DD_2axis_Read_s32(const S32* AddrData,const U16 sizeX,const U8 NodeNumX,const U8 NodeNumY,const U8 IntrNodeCoefX,const U8 IntrNodeCoefY);



// Функция обратного вычисления значения оси x
// Аргументы:   pData - указатель на данные
//              sizeX - размерность по оси x
//              sizeY - размерность по оси y
//              NodeNumY - номер узла по оси y
//              IntrNodeCoefY - значение коэффициента интерполяции по оси y
//              pAxisX - указатель на значения оси x
//              Value - значение функции, для которого выполняется расчет
extern S16 DD_2axis_InverseYRead_s16_s16_s16(const S16* pData,const U16 sizeX,const U16 sizeY,const U8 NodeNumY,const U8 IntrNodeCoefY,const S16* pAxisX,const S16 Value);



// Функция обратного вычисления значения оси y
// Аргументы:   pData - указатель на данные
//              sizeX - размерность по оси y
//              sizeY - размерность по оси x
//              NodeNumX - номер узла по оси x
//              IntrNodeCoefX - значение коэффициента интерполяции по оси x
//              pAxisY - указатель на значения оси y
//              Value - значение функции, для которого выполняется расчет
extern S16 DD_2axis_InverseXRead_s16_s16_s16(const S16* pData,const U16 sizeX,const U16 sizeY,const U8 NodeNumX,const U8 IntrNodeCoefX,const S16* pAxisY,const S16 Value);
