//**************************************************************************************************
// @Module        Data Domain
// @Filename      DD_LIB.c
//--------------------------------------------------------------------------------------------------
// @Description   Implementation of the Data Domain functionality.
//--------------------------------------------------------------------------------------------------
// @Notes         The functions in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          05.08.2015
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// 17.12.2012     1.0.0    Semenov     First release.
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "DD_LIB.h"



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// The values of dimensions
#define DD_DIM_SCALAR                   (0U)
#define DD_DIM_VECTOR                   (1U)
#define DD_DIM_TABLE                    (2U)

#define BIT0MASK                        (0x01)
#define NO_INTERPOLATION_K_VALUE        (0)
#define UNSIGNED_TYPE_BIT_VALUE         (1)
#define SIZE_OF_BYTE_VALUE              (1)
#define SIZE_OF_WORD_VALUE              (2)

#define NO_INTERPOLATION                (0U)
#define LINEAR_INTERPOLATION            (1U)
#define POLYNOMAL_INTERPOLATION         (2U)



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************



//**************************************************************************************************
// Function Implementations
//**************************************************************************************************

//**************************************************************************************************
// @Function                                            DD_Update_Calibr_Addr()
//**************************************************************************************************
U8* DD_Update_Calibr_Addr (U8* AddrData)
{
  U8* Addr_temp = AddrData;
  #ifdef CALLIBRATION_TOOLS
    Addr_temp=(void*)CalRAM_Get_Address(AddrData);
  #endif
  return Addr_temp;
} // End of DD_Update_Calibr_Addr()



//**************************************************************************************************
// @Function                                            DD_Update_Axis_u8()
//**************************************************************************************************
U8 DD_Update_Axis_u8(const U8* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, 
                     U8* UpdResVal,const U8 Value, const U8 Interpolation_Type)
{
  U8* pVectorData = NULL;

  U16 uwMinVectorVal = 0;
  U8  ubMinVectorVal = 0;
  U8  ubMaxVectorVal = 0;
  U16 uwMaxVectorVal = 0;
  U16 uwTemp = 0;

  DD_STRUCTURED_WORD_TYPE wKI;
  wKI.word = 0;

  pVectorData=(void*)DD_Update_Calibr_Addr ((U8*)pCData);
  ubMinVectorVal = pVectorData[0];
  uwMinVectorVal = (U16)ubMinVectorVal;
  ubMaxVectorVal = pVectorData[pdCLastIdx];
  uwMaxVectorVal = (U16)ubMaxVectorVal;

  if (ubMaxVectorVal <= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum = (U8)pdCLastIdx;
    *UpdResVal = pVectorData[pdCLastIdx];
    return *NodeNum;
  }

  if (ubMinVectorVal >= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum=0;
    *UpdResVal = pVectorData[0];
    return *NodeNum;
  }

  for(uwTemp=0;uwTemp<pdCLastIdx;uwTemp++)
  {
    if(Value<pVectorData[uwTemp])
    {
      uwMinVectorVal=pVectorData[uwTemp-1];
      uwMaxVectorVal=pVectorData[uwTemp];
      break;
    }
  }

  wKI.byte.highbyte = uwTemp-1;
  ubMinVectorVal = pVectorData[wKI.byte.highbyte];
  uwMinVectorVal = (U16)ubMinVectorVal;

  ubMaxVectorVal = pVectorData[wKI.byte.highbyte + 1];
  uwMaxVectorVal = (U16)ubMaxVectorVal;

  if(Interpolation_Type==LINEAR_INTERPOLATION)
  {
    wKI.byte.lowbyte = (U8)(((U16)Value - uwMinVectorVal) * 256 / (uwMaxVectorVal - uwMinVectorVal));
  }
  else
  {
    wKI.byte.lowbyte=0;
  }

  *UpdResVal=Value;
  *IntrNodeCoef=wKI.byte.lowbyte;
  *NodeNum=wKI.byte.highbyte;
  return *NodeNum;
} // End of DD_Update_Axis_u8()



//**************************************************************************************************
// @Function                                            DD_Update_Axis_s8()
//**************************************************************************************************
S8 DD_Update_Axis_s8(const S8* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, 
                     S8* UpdResVal,const S8 Value, const U8 Interpolation_Type)
{
  S8* pVectorData = NULL;

  S16 swMinVectorVal = 0;
  S8  sbMinVectorVal = 0;
  S8  sbMaxVectorVal = 0;
  S16 swMaxVectorVal = 0;
  U16 uwTemp = 0;

  DD_STRUCTURED_WORD_TYPE wKI;
  wKI.word = 0;

  pVectorData=(void*)DD_Update_Calibr_Addr ((void*)pCData);
  sbMinVectorVal = pVectorData[0];
  swMinVectorVal = (S16)sbMinVectorVal;
  sbMaxVectorVal = pVectorData[pdCLastIdx];
  swMaxVectorVal = (S16)sbMaxVectorVal;

  if (sbMaxVectorVal <= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum = (U8)pdCLastIdx;
    *UpdResVal = pVectorData[pdCLastIdx];
    return *NodeNum;
  }

  if (sbMinVectorVal >= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum=0;
    *UpdResVal = pVectorData[0];
    return *NodeNum;
  }

  for(uwTemp=0;uwTemp<pdCLastIdx;uwTemp++)
  {
    if(Value<pVectorData[uwTemp])
    {
      swMinVectorVal=pVectorData[uwTemp-1];
      swMaxVectorVal=pVectorData[uwTemp];
      break;
    }
  }

  wKI.byte.highbyte = uwTemp-1;
  sbMinVectorVal = pVectorData[wKI.byte.highbyte];
  swMinVectorVal = (S16)sbMinVectorVal;

  sbMaxVectorVal = pVectorData[wKI.byte.highbyte + 1];
  swMaxVectorVal = (S16)sbMaxVectorVal;

  if(Interpolation_Type==LINEAR_INTERPOLATION)
  {
    wKI.byte.lowbyte = (U8)(((S16)Value - swMinVectorVal) * 256 / (swMaxVectorVal - swMinVectorVal));
  }
  else
  {
    wKI.byte.lowbyte=0;
  }

  *UpdResVal=Value;
  *IntrNodeCoef=wKI.byte.lowbyte;
  *NodeNum=wKI.byte.highbyte;
  return *NodeNum;
} // End of DD_Update_Axis_s8()



//**************************************************************************************************
// @Function                                            DD_Update_Axis_single()
//**************************************************************************************************
U8 DD_Update_Axis_single(const float* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, 
                         float* UpdResVal,const float Value, const U8 Interpolation_Type)
{
  float* pVectorData = NULL;
  float minVectorVal = 0;
  float maxVectorVal = 0;
  U16 temp = 0;
  DD_STRUCTURED_WORD_TYPE wKI;
  wKI.word = 0;

  pVectorData=(void*)DD_Update_Calibr_Addr ((void*)pCData);

  minVectorVal = pVectorData[0];

  maxVectorVal = pVectorData[pdCLastIdx];

  if (maxVectorVal <= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum = (U8)pdCLastIdx;
    *UpdResVal = pVectorData[pdCLastIdx];
    return *NodeNum;
  }

  if (minVectorVal >= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum=0;
    *UpdResVal = pVectorData[0];
    return *NodeNum;
  }

  for(temp=0;temp<pdCLastIdx;temp++)
  {
    if(Value<pVectorData[temp])
    {
      minVectorVal=pVectorData[temp-1];
      maxVectorVal=pVectorData[temp];
      break;
    }
  }

  wKI.byte.highbyte = temp-1;
  minVectorVal = pVectorData[wKI.byte.highbyte];

  maxVectorVal = pVectorData[wKI.byte.highbyte + 1];

  if(Interpolation_Type==LINEAR_INTERPOLATION)
  {
    wKI.byte.lowbyte = (U8)(((U32)Value - minVectorVal) * 256 / (maxVectorVal - minVectorVal));
  }
  else
  {
    wKI.byte.lowbyte=0;
  }

  *UpdResVal=Value;
  *IntrNodeCoef=wKI.byte.lowbyte;
  *NodeNum=wKI.byte.highbyte;
  return *NodeNum;
} // End of DD_Update_Axis_single()



//**************************************************************************************************
// @Function                                            DD_Update_Axis_single()
//**************************************************************************************************
U8 DD_Update_Axis_double(const double* pCData,const U16 pdCLastIdx, U8* NodeNum, 
                         U8* IntrNodeCoef, double* UpdResVal,const double Value, const U8 Interpolation_Type)
{
  double* pVectorData = NULL;
  double minVectorVal = 0;
  double maxVectorVal = 0;
  U16 temp = 0;
  DD_STRUCTURED_WORD_TYPE wKI;
  wKI.word = 0;

  pVectorData=(void*)DD_Update_Calibr_Addr ((void*)pCData);

  minVectorVal = pVectorData[0];

  maxVectorVal = pVectorData[pdCLastIdx];

  if (maxVectorVal <= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum = (U8)pdCLastIdx;
    *UpdResVal = pVectorData[pdCLastIdx];
    return *NodeNum;
  }

  if (minVectorVal >= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum=0;
    *UpdResVal = pVectorData[0];
    return *NodeNum;
  }

  for(temp=0;temp<pdCLastIdx;temp++)
  {
    if(Value<pVectorData[temp])
    {
      minVectorVal=pVectorData[temp-1];
      maxVectorVal=pVectorData[temp];
      break;
    }
  }

  wKI.byte.highbyte = temp-1;
  minVectorVal = pVectorData[wKI.byte.highbyte];

  maxVectorVal = pVectorData[wKI.byte.highbyte + 1];

  if(Interpolation_Type==LINEAR_INTERPOLATION)
  {
    wKI.byte.lowbyte = (U8)(((U32)Value - minVectorVal) * 256 / (maxVectorVal - minVectorVal));
  }
  else
  {
    wKI.byte.lowbyte=0;
  }

  *UpdResVal=Value;
  *IntrNodeCoef=wKI.byte.lowbyte;
  *NodeNum=wKI.byte.highbyte;
  return *NodeNum;
} // End of DD_Update_Axis_double()



//**************************************************************************************************
// @Function                                            DD_Update_Axis_u16()
//**************************************************************************************************
U16 DD_Update_Axis_u16(const U16* pCData,const U16 pdCLastIdx, U8* NodeNum, 
                       U8* IntrNodeCoef, U16* UpdResVal,const U16 Value, const U8 Interpolation_Type)
{
  U16* pVectorData = NULL;
  U16 uwMinVectorVal = 0;
  U16 uwMaxVectorVal = 0;
  U16 uwTemp = 0;
  DD_STRUCTURED_WORD_TYPE wKI;
  wKI.word = 0;

  pVectorData=(void*)DD_Update_Calibr_Addr ((void*)pCData);

  uwMinVectorVal = pVectorData[0];

  uwMaxVectorVal = pVectorData[pdCLastIdx];

  if (uwMaxVectorVal <= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum = (U8)pdCLastIdx;
    *UpdResVal = pVectorData[pdCLastIdx];
    return *NodeNum;
  }

  if (uwMinVectorVal >= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum=0;
    *UpdResVal = pVectorData[0];
    return *NodeNum;
  }

  for(uwTemp=0;uwTemp<pdCLastIdx;uwTemp++)
  {
    if(Value<pVectorData[uwTemp])
    {
      uwMinVectorVal=pVectorData[uwTemp-1];
      uwMaxVectorVal=pVectorData[uwTemp];
      break;
    }
  }

  wKI.byte.highbyte = uwTemp-1;
  uwMinVectorVal = pVectorData[wKI.byte.highbyte];

  uwMaxVectorVal = pVectorData[wKI.byte.highbyte + 1];

  if(Interpolation_Type==LINEAR_INTERPOLATION)
  {
    wKI.byte.lowbyte = (U8)(((U32)Value - uwMinVectorVal) * 256 / (uwMaxVectorVal - uwMinVectorVal));
  }
  else
  {
    wKI.byte.lowbyte=0;
  }

  *UpdResVal=Value;
  *IntrNodeCoef=wKI.byte.lowbyte;
  *NodeNum=wKI.byte.highbyte;
  return *NodeNum;
} // End of DD_Update_Axis_u16()



//**************************************************************************************************
// @Function                                            DD_Update_Axis_s16()
//**************************************************************************************************
S16 DD_Update_Axis_s16(const S16* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, 
                       S16* UpdResVal,const S16 Value, const U8 Interpolation_Type)
{
  S16* pVectorData = NULL;
  S16 swMinVectorVal = 0;
  S16 swMaxVectorVal = 0;
  U16 uwTemp = 0;
  DD_STRUCTURED_WORD_TYPE wKI;
  wKI.word = 0;

  pVectorData=(void*)DD_Update_Calibr_Addr ((void*)pCData);

  swMinVectorVal = pVectorData[0];

  swMaxVectorVal = pVectorData[pdCLastIdx];

  if (swMaxVectorVal <= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum = (U8)pdCLastIdx;
    *UpdResVal = pVectorData[pdCLastIdx];
    return *NodeNum;
  }

  if (swMinVectorVal >= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum=0;
    *UpdResVal = pVectorData[0];
    return *NodeNum;
  }

  for(uwTemp=0;uwTemp<pdCLastIdx;uwTemp++)
  {
    if(Value<pVectorData[uwTemp])
    {
      swMinVectorVal=pVectorData[uwTemp-1];
      swMaxVectorVal=pVectorData[uwTemp];
      break;
    }
  }

  wKI.byte.highbyte = uwTemp-1;
  swMinVectorVal = pVectorData[wKI.byte.highbyte];

  swMaxVectorVal = pVectorData[wKI.byte.highbyte + 1];

  if(Interpolation_Type==LINEAR_INTERPOLATION)
  {
    wKI.byte.lowbyte = (U8)(((S32)Value - swMinVectorVal) * 256 / (swMaxVectorVal - swMinVectorVal));
  }
  else
  {
    wKI.byte.lowbyte=0;
  }

  *UpdResVal=Value;
  *IntrNodeCoef=wKI.byte.lowbyte;
  *NodeNum=wKI.byte.highbyte;
  return *NodeNum;
} // End of DD_Update_Axis_s16()



//**************************************************************************************************
// @Function                                            DD_Update_Axis_u32()
//**************************************************************************************************
U32 DD_Update_Axis_u32(const U32* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, 
                       U32* UpdResVal,const U32 Value, const U8 Interpolation_Type)
{
  U32* pVectorData = NULL;
  U32 uiMinVectorVal = 0;
  U32 uiMaxVectorVal = 0;
  U16 uwTemp = 0;
  DD_STRUCTURED_WORD_TYPE wKI;
  wKI.word = 0;

  pVectorData=(void*)DD_Update_Calibr_Addr ((void*)pCData);

  uiMinVectorVal = pVectorData[0];

  uiMaxVectorVal = pVectorData[pdCLastIdx];

  if (uiMaxVectorVal <= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum = (U8)pdCLastIdx;
    *UpdResVal = pVectorData[pdCLastIdx];
    return *NodeNum;
  }

  if (uiMinVectorVal >= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum=0;
    *UpdResVal = pVectorData[0];
    return *NodeNum;
  }

  for(uwTemp=0;uwTemp<pdCLastIdx;uwTemp++)
  {
    if(Value<pVectorData[uwTemp])
    {
      uiMinVectorVal=pVectorData[uwTemp-1];
      uiMaxVectorVal=pVectorData[uwTemp];
      break;
    }
  }

  wKI.byte.highbyte = uwTemp-1;
  uiMinVectorVal = pVectorData[wKI.byte.highbyte];

  uiMaxVectorVal = pVectorData[wKI.byte.highbyte + 1];

  if(Interpolation_Type==LINEAR_INTERPOLATION)
  {
    wKI.byte.lowbyte = (U8)((Value - uiMinVectorVal) * 256 / (uiMaxVectorVal - uiMinVectorVal));
  }
  else
  {
    wKI.byte.lowbyte=0;
  }

  *UpdResVal=Value;
  *IntrNodeCoef=wKI.byte.lowbyte;
  *NodeNum=wKI.byte.highbyte;
  return *NodeNum;
} // End of DD_Update_Axis_u32()



//**************************************************************************************************
// @Function                                            DD_Update_Axis_s32()
//**************************************************************************************************
S32 DD_Update_Axis_s32(const S32* pCData,const U16 pdCLastIdx, U8* NodeNum, U8* IntrNodeCoef, 
                       S32* UpdResVal,const S32 Value, const U8 Interpolation_Type)
{
  S32* pVectorData = NULL;
  S32 siMinVectorVal = 0;
  S32 siMaxVectorVal = 0;
  U16 uwTemp = 0;
  DD_STRUCTURED_WORD_TYPE wKI;
  wKI.word = 0;

  pVectorData=(void*)DD_Update_Calibr_Addr ((void*)pCData);

  siMinVectorVal = pVectorData[0];

  siMaxVectorVal = pVectorData[pdCLastIdx];

  if (siMaxVectorVal <= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum = (U8)pdCLastIdx;
    *UpdResVal = pVectorData[pdCLastIdx];
    return *NodeNum;
  }

  if (siMinVectorVal >= Value)
  {
    *IntrNodeCoef=0;
    *NodeNum=0;
    *UpdResVal = pVectorData[0];
    return *NodeNum;
  }

  for(uwTemp=0;uwTemp<pdCLastIdx;uwTemp++)
  {
    if(Value<pVectorData[uwTemp])
    {
      siMinVectorVal=pVectorData[uwTemp-1];
      siMaxVectorVal=pVectorData[uwTemp];
      break;
    }
  }

  wKI.byte.highbyte = uwTemp-1;
  siMinVectorVal = pVectorData[wKI.byte.highbyte];

  siMaxVectorVal = pVectorData[wKI.byte.highbyte + 1];

  if(Interpolation_Type==LINEAR_INTERPOLATION)
  {
    wKI.byte.lowbyte = (U8)((Value - siMinVectorVal) * 256 / (siMaxVectorVal - siMinVectorVal));
  }
  else
  {
    wKI.byte.lowbyte=0;
  }

  *UpdResVal=Value;
  *IntrNodeCoef=wKI.byte.lowbyte;
  *NodeNum=wKI.byte.highbyte;
  return *NodeNum;
} // End of DD_Update_Axis_s32()



//**************************************************************************************************
// @Function                                            DD_Read_single()
//**************************************************************************************************
float DD_Read_single(const float* AddrData)
{
  float*  pDataAddress = NULL;
  float  CurrentFuncVal;
  
  pDataAddress = (float*)AddrData;
  pDataAddress=(float*)DD_Update_Calibr_Addr ((U8*)pDataAddress);
  CurrentFuncVal=*pDataAddress;
  return CurrentFuncVal;
} // End of DD_Read_single()



//**************************************************************************************************
// @Function                                            DD_Read_double()
//**************************************************************************************************
double DD_Read_double(const double* AddrData)
{
  double*  pDataAddress = NULL;
  double  CurrentFuncVal;
  
  pDataAddress = (double*)AddrData;
  pDataAddress=(double*)DD_Update_Calibr_Addr ((U8*)pDataAddress);
  CurrentFuncVal=*pDataAddress;
  return CurrentFuncVal;
} // End of DD_Read_double()



//**************************************************************************************************
// @Function                                            DD_Read_u8()
//**************************************************************************************************
U8 DD_Read_u8(const U8* AddrData)
{
  U8*  pDataAddress = NULL;
  U8  CurrentFuncVal = 0;

  pDataAddress = (U8*)AddrData;
  pDataAddress=DD_Update_Calibr_Addr (pDataAddress);
  CurrentFuncVal=*pDataAddress;
  return CurrentFuncVal;
} // End of DD_Read_u8()



//**************************************************************************************************
// @Function                                            DD_Read_s8()
//**************************************************************************************************
S8 DD_Read_s8(const S8* AddrData)
{
  S8*  pDataAddress = NULL;
  S8  CurrentFuncVal = 0;

  pDataAddress = (S8*)AddrData;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  CurrentFuncVal=*pDataAddress;
  return CurrentFuncVal;
} // End of DD_Read_s8()



//**************************************************************************************************
// @Function                                            DD_Read_u16()
//**************************************************************************************************
U16 DD_Read_u16(const U16* AddrData)
{
  U16*  pDataAddress = NULL;
  U16  CurrentFuncVal = 0;

  pDataAddress = (U16*)AddrData;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  CurrentFuncVal=*pDataAddress;
  return CurrentFuncVal;
} // End of DD_Read_u16()



//**************************************************************************************************
// @Function                                            DD_Read_s16()
//**************************************************************************************************
S16 DD_Read_s16(const S16* AddrData)
{
  S16*  pDataAddress = NULL;
  S16  CurrentFuncVal = 0;

  pDataAddress = (S16*)AddrData;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  // function value data array start address
  CurrentFuncVal=*pDataAddress;
  // get Fi value
  return CurrentFuncVal;
} // End of DD_Read_s16()



//**************************************************************************************************
// @Function                                            DD_Read_u32()
//**************************************************************************************************
U32 DD_Read_u32(const U32* AddrData)
{
  U32*  pDataAddress = NULL;
  U32  CurrentFuncVal = 0;

  pDataAddress = (U32*)AddrData;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  CurrentFuncVal=*pDataAddress;
  return CurrentFuncVal;
} // End of DD_Read_u32()



//**************************************************************************************************
// @Function                                            DD_Read_s32()
//**************************************************************************************************
S32 DD_Read_s32(const S32* AddrData)
{
  S32*  pDataAddress = NULL;
  S32  CurrentFuncVal = 0;

  pDataAddress = (S32*)AddrData;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  CurrentFuncVal=*pDataAddress;
  return CurrentFuncVal;
} // End of DD_Read_s32()



//**************************************************************************************************
// @Function                                            DD_1axis_Read_single()
//**************************************************************************************************
float DD_1axis_Read_single(const float* AddrData,const U8 NodeNum,const U8 IntrNodeCoef)
{
  float  sbCurrentFuncVal = 0;
  float  sbIncrementedFuncVal = 0;
  float* pDataAddress = NULL;

  pDataAddress = (float*)AddrData;
  pDataAddress += NodeNum;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  sbCurrentFuncVal = *pDataAddress;
  pDataAddress++;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  sbIncrementedFuncVal = *pDataAddress;

  if (IntrNodeCoef == NO_INTERPOLATION_K_VALUE)
  {
    return sbCurrentFuncVal;
  }
  else
  {
    return ((((sbIncrementedFuncVal - sbCurrentFuncVal)*IntrNodeCoef)/256)+sbCurrentFuncVal);
  }
} // End of DD_1axis_Read_single()



//**************************************************************************************************
// @Function                                            DD_1axis_Read_double()
//**************************************************************************************************
double DD_1axis_Read_double(const double* AddrData,const U8 NodeNum,const U8 IntrNodeCoef)
{
  double  sbCurrentFuncVal = 0;
  double  sbIncrementedFuncVal = 0;
  double* pDataAddress = NULL;

  pDataAddress = (double*)AddrData;
  pDataAddress += NodeNum;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  sbCurrentFuncVal = *pDataAddress;
  pDataAddress++;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  sbIncrementedFuncVal = *pDataAddress;

  if (IntrNodeCoef == NO_INTERPOLATION_K_VALUE)
  {
    return sbCurrentFuncVal;
  }
  else
  {
    return ((((sbIncrementedFuncVal - sbCurrentFuncVal)*IntrNodeCoef)/256)+sbCurrentFuncVal);
  }
} // End of DD_1axis_Read_double()



//**************************************************************************************************
// @Function                                            DD_1axis_Read_u8()
//**************************************************************************************************
U8 DD_1axis_Read_u8(const U8* AddrData,const U8 NodeNum,const U8 IntrNodeCoef)
{
  U8  ubCurrentFuncVal = 0;
  U8  ubIncrementedFuncVal = 0;
  U8* pDataAddress = NULL;

  pDataAddress = (U8*)AddrData;
  pDataAddress += NodeNum;
  pDataAddress=DD_Update_Calibr_Addr (pDataAddress);
  ubCurrentFuncVal = *pDataAddress;
  pDataAddress++;
  pDataAddress=DD_Update_Calibr_Addr (pDataAddress);
  ubIncrementedFuncVal = *pDataAddress;

  if (IntrNodeCoef == NO_INTERPOLATION_K_VALUE)
  {
    return ubCurrentFuncVal;
  }
  else
  {
    return ((((ubIncrementedFuncVal - ubCurrentFuncVal)*IntrNodeCoef)>>8)+ubCurrentFuncVal);
  }
} // End of DD_1axis_Read_u8()



//**************************************************************************************************
// @Function                                            DD_1axis_Read_s8()
//**************************************************************************************************
S8 DD_1axis_Read_s8(const S8* AddrData,const U8 NodeNum,const U8 IntrNodeCoef)
{
  S8  sbCurrentFuncVal = 0;
  S8  sbIncrementedFuncVal = 0;
  S8* pDataAddress = NULL;

  pDataAddress = (S8*)AddrData;
  pDataAddress += NodeNum;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  sbCurrentFuncVal = *pDataAddress;
  pDataAddress++;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);
  sbIncrementedFuncVal = *pDataAddress;

  if (IntrNodeCoef == NO_INTERPOLATION_K_VALUE)
  {
    return sbCurrentFuncVal;
  }
  else
  {
    return ((((sbIncrementedFuncVal - sbCurrentFuncVal)*IntrNodeCoef)>>8)+sbCurrentFuncVal);
  }
} // End of DD_1axis_Read_s8()



//**************************************************************************************************
// @Function                                            DD_1axis_Read_u16()
//**************************************************************************************************
U16 DD_1axis_Read_u16(const U16* AddrData,const U8 NodeNum,const U8 IntrNodeCoef)
{
  U16  uwCurrentFuncVal = 0;
  U16  uwIncrementedFuncVal = 0;
  U16* pDataAddress = NULL;

  pDataAddress = (U16*)AddrData;

  pDataAddress += NodeNum;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);

  uwCurrentFuncVal = *pDataAddress;
  pDataAddress++;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);

  uwIncrementedFuncVal = *pDataAddress;

  if (IntrNodeCoef == NO_INTERPOLATION_K_VALUE)
  {
    return uwCurrentFuncVal;
  }
  else
  {
    return ((((uwIncrementedFuncVal - uwCurrentFuncVal)*IntrNodeCoef)>>8)+uwCurrentFuncVal);
  }
} // End of DD_1axis_Read_u16()



//**************************************************************************************************
// @Function                                            DD_1axis_Read_s16()
//**************************************************************************************************
S16 DD_1axis_Read_s16(const S16* AddrData,const U8 NodeNum,const U8 IntrNodeCoef)
{
  S16  swCurrentFuncVal = 0;
  S16  swIncrementedFuncVal = 0;
  S16* pDataAddress = NULL;

  pDataAddress = (S16*)AddrData;

  pDataAddress += NodeNum;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);

  swCurrentFuncVal = *pDataAddress;
  pDataAddress++;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);

  swIncrementedFuncVal = *pDataAddress;

  if (IntrNodeCoef == NO_INTERPOLATION_K_VALUE)
  {
    return swCurrentFuncVal;
  }
  else
  {
    return ((((swIncrementedFuncVal - swCurrentFuncVal)*IntrNodeCoef)>>8)+swCurrentFuncVal);
  }
} // End of DD_1axis_Read_s16()



//**************************************************************************************************
// @Function                                            DD_1axis_Read_u32()
//**************************************************************************************************
U32 DD_1axis_Read_u32(const U32* AddrData,const U8 NodeNum,const U8 IntrNodeCoef)
{
  U32  uiCurrentFuncVal = 0;
  U32  uiIncrementedFuncVal = 0;
  U32* pDataAddress = NULL;

  pDataAddress = (U32*)AddrData;

  pDataAddress += NodeNum;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);

  uiCurrentFuncVal = *pDataAddress;
  pDataAddress++;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);

  uiIncrementedFuncVal = *pDataAddress;

  if (IntrNodeCoef == NO_INTERPOLATION_K_VALUE)
  {
    return uiCurrentFuncVal;
  }
  else
  {
    return ((((uiIncrementedFuncVal - uiCurrentFuncVal)*IntrNodeCoef)>>8)+uiCurrentFuncVal);
  }
} // End of DD_1axis_Read_u32()



//**************************************************************************************************
// @Function                                            DD_1axis_Read_s32()
//**************************************************************************************************
S32 DD_1axis_Read_s32(const S32* AddrData,const U8 NodeNum,const U8 IntrNodeCoef)
{
  S32  siCurrentFuncVal = 0;
  S32  siIncrementedFuncVal = 0;
  S32* pDataAddress = NULL;

  pDataAddress = (S32*)AddrData;

  pDataAddress += NodeNum;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);

  siCurrentFuncVal = *pDataAddress;
  pDataAddress++;
  pDataAddress=(void*)DD_Update_Calibr_Addr ((void*)pDataAddress);

  siIncrementedFuncVal = *pDataAddress;

  if (IntrNodeCoef == NO_INTERPOLATION_K_VALUE)
  {
    return siCurrentFuncVal;
  }
  else
  {
    return ((((siIncrementedFuncVal - siCurrentFuncVal)*IntrNodeCoef)>>8)+siCurrentFuncVal);
  }
} // End of DD_1axis_Read_s32()



//**************************************************************************************************
// @Function                                            DD_2axis_Read_single()
//**************************************************************************************************
float DD_2axis_Read_single(const float* AddrData,
                           const U16 sizeX,
                           const U8 NodeNumX,
                           const U8 NodeNumY,
                           const U8 IntrNodeCoefX,
                           const U8 IntrNodeCoefY
                           )
{
  float uwCurrentFunc00 = 0;
  float uwCurrentFunc10 = 0;
  float uwCurrentFunc01 = 0;
  float uwCurrentFunc11 = 0;
  float uiF1 = 0;
  float uiF2 = 0;

  float*     pDataAddress = NULL;
  float*     pDataAddr = NULL;

  pDataAddress = (float*)AddrData;

  pDataAddress += (NodeNumX + sizeX * (U16)NodeNumY);
  pDataAddress=(void*)DD_Update_Calibr_Addr((void*)pDataAddress);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  uwCurrentFunc00 = DD_Read_single((void*)pDataAddr);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  uwCurrentFunc10 = DD_Read_single((void*)pDataAddr);
  pDataAddress+=sizeX;
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  uwCurrentFunc01 = DD_Read_single((void*)pDataAddr);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  uwCurrentFunc11 = DD_Read_single((void*)pDataAddr);

  if (IntrNodeCoefX == NO_INTERPOLATION_K_VALUE)
  {
    uiF2 = uwCurrentFunc01;
    uiF1 = uwCurrentFunc00;
  }
  else
  {
    uiF1 = (uwCurrentFunc10 - uwCurrentFunc00) * IntrNodeCoefX / 256 + uwCurrentFunc00;
    uiF2 = (uwCurrentFunc11 - uwCurrentFunc01) * IntrNodeCoefX / 256 + uwCurrentFunc01;
  }

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    return uiF1;
  }
  else
  {
    return (uiF2 - uiF1) * IntrNodeCoefY / 256 + uiF1;
  }
} // End of DD_2axis_Read_single()



//**************************************************************************************************
// @Function                                            DD_2axis_Read_double()
//**************************************************************************************************
double DD_2axis_Read_double(const double* AddrData,
                           const U16 sizeX,
                           const U8 NodeNumX,
                           const U8 NodeNumY,
                           const U8 IntrNodeCoefX,
                           const U8 IntrNodeCoefY
                           )
{
  double uwCurrentFunc00 = 0;
  double uwCurrentFunc10 = 0;
  double uwCurrentFunc01 = 0;
  double uwCurrentFunc11 = 0;
  double uiF1 = 0;
  double uiF2 = 0;

  double*     pDataAddress = NULL;
  double*     pDataAddr = NULL;

  pDataAddress = (double*)AddrData;

  pDataAddress += (NodeNumX + sizeX * (U16)NodeNumY);
  pDataAddress=(void*)DD_Update_Calibr_Addr((void*)pDataAddress);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  uwCurrentFunc00 = DD_Read_double((void*)pDataAddr);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  uwCurrentFunc10 = DD_Read_double((void*)pDataAddr);
  pDataAddress+=sizeX;
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  uwCurrentFunc01 = DD_Read_double((void*)pDataAddr);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  uwCurrentFunc11 = DD_Read_double((void*)pDataAddr);

  if (IntrNodeCoefX == NO_INTERPOLATION_K_VALUE)
  {
    uiF2 = uwCurrentFunc01;
    uiF1 = uwCurrentFunc00;
  }
  else
  {
    uiF1 = (uwCurrentFunc10 - uwCurrentFunc00) * IntrNodeCoefX / 256 + uwCurrentFunc00;
    uiF2 = (uwCurrentFunc11 - uwCurrentFunc01) * IntrNodeCoefX / 256 + uwCurrentFunc01;
  }

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    return uiF1;
  }
  else
  {
    return (uiF2 - uiF1) * IntrNodeCoefY / 256 + uiF1;
  }
} // End of DD_2axis_Read_double()



//**************************************************************************************************
// @Function                                            DD_2axis_Read_u8()
//**************************************************************************************************
U8 DD_2axis_Read_u8(const U8* AddrData,
                    const U16 sizeX,
                    const U8 NodeNumX,
                    const U8 NodeNumY,
                    const U8 IntrNodeCoefX,
                    const U8 IntrNodeCoefY
                    )
{
  U8 ubCurrentFunc00 = 0;
  U8 ubCurrentFunc10 = 0;
  U8 ubCurrentFunc01 = 0;
  U8 ubCurrentFunc11 = 0;
  U16 uwF1 = 0;
  U16 uwF2 = 0;

  U8*     pDataAddress = NULL;
  U8*     pDataAddr = NULL;

  pDataAddress = (U8*)AddrData;

  pDataAddress += (NodeNumX + sizeX * (U16)NodeNumY );
  pDataAddress=DD_Update_Calibr_Addr(pDataAddress);

  pDataAddr = DD_Update_Calibr_Addr(pDataAddress);
  ubCurrentFunc00 = DD_Read_u8((void*)pDataAddr);
  
  pDataAddr = DD_Update_Calibr_Addr(pDataAddress+1);
  ubCurrentFunc10 = DD_Read_u8((void*)pDataAddr);
  pDataAddress+=sizeX;
  
  pDataAddr = DD_Update_Calibr_Addr(pDataAddress);
  ubCurrentFunc01 = DD_Read_u8((void*)pDataAddr);

  pDataAddr = DD_Update_Calibr_Addr(pDataAddress+1);
  ubCurrentFunc11 = DD_Read_u8((void*)pDataAddr);

  if (IntrNodeCoefX == NO_INTERPOLATION_K_VALUE)
  {
    uwF2 = ubCurrentFunc01;
    uwF1 = ubCurrentFunc00;
  }
  else
  {
    uwF1 = (ubCurrentFunc10 - ubCurrentFunc00) * IntrNodeCoefX / 256 + ubCurrentFunc00;
    uwF2 = (ubCurrentFunc11 - ubCurrentFunc01) * IntrNodeCoefX / 256 + ubCurrentFunc01;
  }

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    return uwF1;
  }
  else
  {
    return (uwF2 - uwF1) * IntrNodeCoefY / 256 + uwF1;
  }
} // End of DD_2axis_Read_u8()



//**************************************************************************************************
// @Function                                            DD_2axis_Read_s8()
//**************************************************************************************************
S8 DD_2axis_Read_s8(const S8* AddrData,
                    const U16 sizeX,
                    const U8 NodeNumX,
                    const U8 NodeNumY,
                    const U8 IntrNodeCoefX,
                    const U8 IntrNodeCoefY
                    )
{
  S8 sbCurrentFunc00 = 0;
  S8 sbCurrentFunc01 = 0;
  S8 sbCurrentFunc10 = 0;
  S8 sbCurrentFunc11 = 0;
  S16 swF1 = 0;
  S16 swF2 = 0;

  S8*     pDataAddress = NULL;
  S8*     pDataAddr = NULL;

  pDataAddress = (S8*)AddrData;

  pDataAddress += (NodeNumX + sizeX * (U16)NodeNumY);
  pDataAddress=(void*)DD_Update_Calibr_Addr((void*)pDataAddress);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  sbCurrentFunc00 = DD_Read_s8((void*)pDataAddr);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  sbCurrentFunc10 = DD_Read_s8((void*)pDataAddr);
  pDataAddress+=sizeX;
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  sbCurrentFunc01 = DD_Read_s8((void*)pDataAddr);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  sbCurrentFunc11 = DD_Read_s8(pDataAddr);

  if (IntrNodeCoefX == NO_INTERPOLATION_K_VALUE)
  {
    swF2 = sbCurrentFunc01;
    swF1 = sbCurrentFunc00;
  }
  else
  {
    swF1 = (sbCurrentFunc10 - sbCurrentFunc00) * IntrNodeCoefX / 256 + sbCurrentFunc00;
    swF2 = (sbCurrentFunc11 - sbCurrentFunc01) * IntrNodeCoefX / 256 + sbCurrentFunc01;
  }

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    return swF1;
  }
  else
  {
    return (swF2 - swF1) * IntrNodeCoefY / 256 + swF1;
  }
} // End of DD_2axis_Read_s8()



//**************************************************************************************************
// @Function                                            DD_2axis_Read_u16()
//**************************************************************************************************
U16 DD_2axis_Read_u16(const U16* AddrData,
                    const U16 sizeX,
                    const U8 NodeNumX,
                    const U8 NodeNumY,
                    const U8 IntrNodeCoefX,
                    const U8 IntrNodeCoefY
                    )
{
  U16 uwCurrentFunc00 = 0;
  U16 uwCurrentFunc10 = 0;
  U16 uwCurrentFunc01 = 0;
  U16 uwCurrentFunc11 = 0;
  U32 uiF1 = 0;
  U32 uiF2 = 0;

  U16*     pDataAddress = NULL;
  U16*     pDataAddr = NULL;

  pDataAddress = (U16*)AddrData;

  pDataAddress += (NodeNumX + sizeX * (U16)NodeNumY);
  pDataAddress=(void*)DD_Update_Calibr_Addr((void*)pDataAddress);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  uwCurrentFunc00 = DD_Read_u16((void*)pDataAddr);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  uwCurrentFunc10 = DD_Read_u16((void*)pDataAddr);
  pDataAddress+=sizeX;
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  uwCurrentFunc01 = DD_Read_u16((void*)pDataAddr);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  uwCurrentFunc11 = DD_Read_u16(pDataAddr);

  if (IntrNodeCoefX == NO_INTERPOLATION_K_VALUE)
  {
    uiF2 = uwCurrentFunc01;
    uiF1 = uwCurrentFunc00;
  }
  else
  {
    uiF1 = (uwCurrentFunc10 - uwCurrentFunc00) * IntrNodeCoefX / 256 + uwCurrentFunc00;
    uiF2 = (uwCurrentFunc11 - uwCurrentFunc01) * IntrNodeCoefX / 256 + uwCurrentFunc01;
  }

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    return uiF1;
  }
  else
  {
    return (uiF2 - uiF1) * IntrNodeCoefY / 256 + uiF1;
  }
} // End of DD_2axis_Read_u8()



//**************************************************************************************************
// @Function                                            DD_2axis_Read_s16()
//**************************************************************************************************
S16 DD_2axis_Read_s16(const S16* AddrData,
                    const U16 sizeX,
                    const U8 NodeNumX,
                    const U8 NodeNumY,
                    const U8 IntrNodeCoefX,
                    const U8 IntrNodeCoefY
                    )
{
  S16 swCurrentFunc00 = 0;
  S16 swCurrentFunc01 = 0;
  S16 swCurrentFunc10 = 0;
  S16 swCurrentFunc11 = 0;
  S32 siF1 = 0;
  S32 siF2 = 0;

  S16*     pDataAddress = NULL;
  S16*     pDataAddr = NULL;

  pDataAddress = (S16*)AddrData;

  pDataAddress += (NodeNumX + sizeX * (U16)NodeNumY);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  swCurrentFunc00 = DD_Read_s16(pDataAddr);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  swCurrentFunc10 = DD_Read_s16(pDataAddr);
  pDataAddress+=sizeX;
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  swCurrentFunc01 = DD_Read_s16(pDataAddr);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  swCurrentFunc11 = DD_Read_s16(pDataAddr);

  if (IntrNodeCoefX == NO_INTERPOLATION_K_VALUE)
  {
    siF2 = swCurrentFunc01;
    siF1 = swCurrentFunc00;
  }
  else
  {
    siF1 = (swCurrentFunc10 - swCurrentFunc00) * IntrNodeCoefX / 256 + swCurrentFunc00;
    siF2 = (swCurrentFunc11 - swCurrentFunc01) * IntrNodeCoefX / 256 + swCurrentFunc01;
  }

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    return siF1;
  }
  else
  {
    return (siF2 - siF1) * IntrNodeCoefY / 256 + siF1;
  }
} // End of DD_2axis_Read_s8()



//**************************************************************************************************
// @Function                                            DD_2axis_Read_u32()
//**************************************************************************************************
U32 DD_2axis_Read_u32(const U32* AddrData,
                    const U16 sizeX,
                    const U8 NodeNumX,
                    const U8 NodeNumY,
                    const U8 IntrNodeCoefX,
                    const U8 IntrNodeCoefY
                    )
{
  U32 uiCurrentFunc00 = 0;
  U32 uiCurrentFunc10 = 0;
  U32 uiCurrentFunc01 = 0;
  U32 uiCurrentFunc11 = 0;
  U32 uiF1 = 0;
  U32 uiF2 = 0;

  U32*     pDataAddress = NULL;
  U32*     pDataAddr = NULL;

  pDataAddress = (U32*)AddrData;

  pDataAddress += (NodeNumX + sizeX * (U16)NodeNumY);
  pDataAddress=(void*)DD_Update_Calibr_Addr((void*)pDataAddress);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  uiCurrentFunc00 = DD_Read_u32((void*)pDataAddr);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  uiCurrentFunc10 = DD_Read_u32((void*)pDataAddr);
  pDataAddress+=sizeX;
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  uiCurrentFunc01 = DD_Read_u32((void*)pDataAddr);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  uiCurrentFunc11 = DD_Read_u32(pDataAddr);

  if (IntrNodeCoefX == NO_INTERPOLATION_K_VALUE)
  {
    uiF2 = uiCurrentFunc01;
    uiF1 = uiCurrentFunc00;
  }
  else
  {
    uiF1 = (uiCurrentFunc10 - uiCurrentFunc00) * IntrNodeCoefX / 256 + uiCurrentFunc00;
    uiF2 = (uiCurrentFunc11 - uiCurrentFunc01) * IntrNodeCoefX / 256 + uiCurrentFunc01;
  }

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    return uiF1;
  }
  else
  {
    return (uiF2 - uiF1) * IntrNodeCoefY / 256 + uiF1;
  }
} // End of DD_2axis_Read_u8()



//**************************************************************************************************
// @Function                                            DD_2axis_Read_s32()
//**************************************************************************************************
S32 DD_2axis_Read_s32(const S32* AddrData,
                    const U16 sizeX,
                    const U8 NodeNumX,
                    const U8 NodeNumY,
                    const U8 IntrNodeCoefX,
                    const U8 IntrNodeCoefY
                    )
{
  S32 siCurrentFunc00 = 0;
  S32 siCurrentFunc01 = 0;
  S32 siCurrentFunc10 = 0;
  S32 siCurrentFunc11 = 0;
  S32 siF1 = 0;
  S32 siF2 = 0;

  S32*     pDataAddress = NULL;
  S32*     pDataAddr = NULL;

  pDataAddress = (S32*)AddrData;

  pDataAddress += (NodeNumX + sizeX * (U16)NodeNumY);
  pDataAddress=(void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  siCurrentFunc00 = DD_Read_s32((void*)pDataAddr);
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  siCurrentFunc10 = DD_Read_s32((void*)pDataAddr);
  pDataAddress+=sizeX;
  
  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)pDataAddress);
  siCurrentFunc01 = DD_Read_s32((void*)pDataAddr);

  pDataAddr = (void*)DD_Update_Calibr_Addr((void*)(pDataAddress+1));
  siCurrentFunc11 = DD_Read_s32(pDataAddr);

  if (IntrNodeCoefX == NO_INTERPOLATION_K_VALUE)
  {
    siF2 = siCurrentFunc01;
    siF1 = siCurrentFunc00;
  }
  else
  {
    siF1 = (siCurrentFunc10 - siCurrentFunc00) * IntrNodeCoefX / 256 + siCurrentFunc00;
    siF2 = (siCurrentFunc11 - siCurrentFunc01) * IntrNodeCoefX / 256 + siCurrentFunc01;
  }

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    return siF1;
  }
  else
  {
    return (siF2 - siF1) * IntrNodeCoefY / 256 + siF1;
  }
} // End of DD_2axis_InverseXRead_s16_s16_s16()




//**************************************************************************************************
// @Function                                            DD_2axis_InverseYRead_s16_s16_s16()
//**************************************************************************************************
S16 DD_2axis_InverseYRead_s16_s16_s16(const S16* pData,
                                const U16 sizeX,
                                const U16 sizeY,
                                const U8 NodeNumX,
                                const U8 IntrNodeCoefX,
                                const S16* pAxisY,
                                const S16 Value
                                )
{
  S16 swCurrentFunc00 = 0;
  S16 swCurrentFunc01 = 0;
  S16 swCalculatedVal_Start=0;
  S16 swCalculatedVal_End=0;

  U16 uwTemp=0;
  U8 KIY=0;

  S16*     pDataAddress = NULL;
  S16*     pDataAddr = NULL;
  S16*     pCAxis = NULL;

  pDataAddress = (S16*)pData;
  pDataAddress += NodeNumX;
  pCAxis=(void*)DD_Update_Calibr_Addr((void*)pAxisY);
  pDataAddr = pDataAddress;

  swCurrentFunc00 = DD_Read_s16(pDataAddr);
  swCurrentFunc01 = DD_Read_s16(pDataAddr+1);
  swCalculatedVal_Start=(swCurrentFunc01 - swCurrentFunc00) * IntrNodeCoefX / 256 + swCurrentFunc00;
  if (swCalculatedVal_Start >= Value)
  {
    return pCAxis[0];
  }
  
  swCalculatedVal_End=swCalculatedVal_Start;
  pDataAddr+=(sizeX*(sizeY-1));
  swCurrentFunc00 = DD_Read_s16(pDataAddr);
  swCurrentFunc01 = DD_Read_s16(pDataAddr+1);
  swCalculatedVal_Start=(swCurrentFunc01 - swCurrentFunc00) * IntrNodeCoefX / 256 + swCurrentFunc00;

  if (swCalculatedVal_Start <= Value)
  {
    return pCAxis[sizeY-1];
  }

  pDataAddr = pDataAddress;

  for(uwTemp=0;((Value>=swCalculatedVal_End)&&(uwTemp<sizeY));uwTemp++)
  {
    pDataAddr += sizeX;
    swCurrentFunc00 = DD_Read_s16(pDataAddr);
    swCurrentFunc01 = DD_Read_s16(pDataAddr+1);
    swCalculatedVal_End=(swCurrentFunc01 - swCurrentFunc00) * IntrNodeCoefX / 256 + swCurrentFunc00;
  }
  
  if(uwTemp==sizeY)
  {
    return pCAxis[sizeY];
  }

  pDataAddress = pDataAddr-sizeX;
  pDataAddr=pDataAddress;
  swCurrentFunc00 = DD_Read_s16(pDataAddr);
  swCurrentFunc01 = DD_Read_s16(pDataAddr+1);
  swCalculatedVal_Start=(swCurrentFunc01 - swCurrentFunc00) * IntrNodeCoefX / 256 + swCurrentFunc00;

  KIY = (U8)(((S32)Value - swCalculatedVal_Start) * 256 / (swCalculatedVal_End - swCalculatedVal_Start));
  if(KIY==0)
  {
    return pCAxis[uwTemp-1];
  }
  else
  {
    return ((((S32)pCAxis[uwTemp]-pCAxis[uwTemp-1])*KIY/256)+pCAxis[uwTemp-1]);
  }
} // End of DD_2axis_InverseYRead_s16_s16_s16()



//**************************************************************************************************
// @Function                                            DD_2axis_InverseXRead_s16_s16_s16()
//**************************************************************************************************
S16 DD_2axis_InverseXRead_s16_s16_s16(const S16* pData,
                                      const U16 sizeX,
                                      const U16 sizeY,
                                      const U8 NodeNumY,
                                      const U8 IntrNodeCoefY,
                                      const S16* pAxisX,
                                      const S16 Value
                                      )
{
  S16 swCurrentFunc00 = 0;
  S16 swCurrentFunc01 = 0;
  S16 swCurrentFunc10 = 0;
  S16 swCurrentFunc11 = 0;
  U16 uwTemp=0;
  U8 KIX=0;

  S16*     pDataAddress = NULL;
  S16*     pDataAddr = NULL;
  S16*     pCAxis = NULL;

  pDataAddress = (S16*)pData;
  pDataAddress += (NodeNumY*sizeX);
  pCAxis=(void*)DD_Update_Calibr_Addr((void*)pAxisX);

  pDataAddr = pDataAddress;
  swCurrentFunc00 = DD_Read_s16(pDataAddr);
  for(uwTemp=0;(swCurrentFunc00<Value)&(uwTemp<sizeX);uwTemp++)
  {
    pDataAddr++;
    swCurrentFunc00 = DD_Read_s16(pDataAddr);
    pDataAddress=pDataAddr+sizeX;
    swCurrentFunc01 = DD_Read_s16(pDataAddress);
    swCurrentFunc00=(swCurrentFunc01 - swCurrentFunc00) * IntrNodeCoefY / 256 + swCurrentFunc00;
  }
  if(uwTemp==sizeX)
  {
    return pCAxis[sizeX];
  }

  pDataAddr--;
  pDataAddress = pDataAddr;

  swCurrentFunc00 = DD_Read_s16(pDataAddr);
  
  pDataAddr++;
  swCurrentFunc10 = DD_Read_s16(pDataAddr);
  
  pDataAddr = pDataAddress + sizeX;
  swCurrentFunc01 = DD_Read_s16(pDataAddr);

  pDataAddr++;
  swCurrentFunc11 = DD_Read_s16(pDataAddr);

  if (IntrNodeCoefY == NO_INTERPOLATION_K_VALUE)
  {
    KIX = (U8)(((S32)Value - swCurrentFunc00) * 256 / (swCurrentFunc10 - swCurrentFunc00));
    if(KIX==0)
    {
      return pCAxis[uwTemp];
    }
    else
    {
      return ((((S32)pCAxis[uwTemp]-pCAxis[uwTemp-1])*KIX/256)+pCAxis[uwTemp-1]);
    }
  }
  else
  {
    swCurrentFunc00= (swCurrentFunc01 - swCurrentFunc00) * IntrNodeCoefY / 256 + swCurrentFunc00;
    swCurrentFunc01 = (swCurrentFunc11 - swCurrentFunc10) * IntrNodeCoefY / 256 + swCurrentFunc10;
    KIX = (U8)(((S32)Value - swCurrentFunc00) * 256 / (swCurrentFunc01 - swCurrentFunc00));
    if(KIX==0)
    {
      return pCAxis[uwTemp];
    }
    else
    {
      return ((((S32)pCAxis[uwTemp]-pCAxis[uwTemp-1])*KIX/256)+pCAxis[uwTemp-1]);
    }
  }
} // End of DD_2axis_InverseXRead_s16_s16_s16()


