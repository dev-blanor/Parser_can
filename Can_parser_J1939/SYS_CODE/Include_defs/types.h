//**************************************************************************************************
// @Filename      types.h
//--------------------------------------------------------------------------------------------------
// @Description   
//--------------------------------------------------------------------------------------------------
// @Notes:        The constants in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          25.03.2020
//--------------------------------------------------------------------------------------------------
// @History       Version  Author    Comment
//                1.0.0    Sokolov   First release.
//**************************************************************************************************

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

#define MSEPRO_COMMON_LIST_IS_DISABLED
#define __need_NULL
#define UNALIGNED
#define NEAR
#define XHUGE
#define __bit char



typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;
typedef int64_t sint64;
typedef int32_t sint32;
typedef int16_t sint16;
typedef int8_t sint8;

typedef unsigned char  boolean;

typedef signed char S8;
typedef unsigned char U8;
typedef signed short S16;
typedef unsigned short U16;
typedef signed int S32;
typedef unsigned int U32;
typedef float F32;
typedef double F64;



#endif // #ifndef TYPES_H

//************************************ end of file types.h ************************************
