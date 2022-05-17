/*
 * -----------------------------------------------------------------------------
 * File Name    : dd_ref.h
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

#ifndef dd_ref_H
#define dd_ref_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "model.h"

typedef enum
{
    T_S8,
    T_U8,
    T_S16,
    T_U16,
    T_S32,
    T_U32,
    T_S64,
    T_U64,
    T_F32,
    T_F64,
    T_FILE,
    T_FUNCTION,
    T_UICOMPONENT
} dd_type;

typedef struct
{
    uint32_t hash_code;
    const void *data_ptr;
    const char *uuid;        // UUID в виде строкового литерала ("00000 - 0000 - 000...")
    dd_type type;            // тип переменной. Для массива - тип элемента массива
    unsigned long len;       // длина массива, если не массив - 0
    const char *format;      // формат метрики в том же виде что и для дисплея
    unsigned int multiplier; // числитель метрики
    unsigned int divider;    // знаменатель метрики
} dd_reference;

/* Definitions of global (public) constants ----------------------------------*/

/* Declarations of global (public) variables ---------------------------------*/

extern dd_reference DataReferencies[];

/* Declarations of global (public) functions ---------------------------------*/

uint32_t DD_Get_Data_Address(uint32_t hash_code);

int DD_Get_Hash_From_String(const char* value, const int length);

dd_reference *DD_Ref_GetByUUID(const uint32_t hash_code, const char *uuid);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef dd_ref_H */

/* End of file ---------------------------------------------------------------*/

