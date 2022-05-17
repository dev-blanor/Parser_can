//**************************************************************************************************
// @Module        Calibration RAM (CalRAM)
// @Filename      CalRAM.h
//--------------------------------------------------------------------------------------------------
// @Description   Header file for calibration RAM module functionality.
//                This file contains all defines and function prototypes for calibration RAM module.
//--------------------------------------------------------------------------------------------------
// @Notes:        The constants in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.2.0
//--------------------------------------------------------------------------------------------------
// @Date          01.04.2020
//--------------------------------------------------------------------------------------------------
// @History       Version  Author       Comment
//                1.0.1    ASD          First release
//                1.0.2    ASD          Configurations for different targets added
//                1.0.3    ASD          Added independence on startup code
//                1.0.5    ASD          Calibration RAM size in sectors is taken away into "CalRAM_cfg.h"
//                1.1.0    ASD          Added writing ROM facility
//                1.2.0    Sokolov      Added STM32 support
//**************************************************************************************************

#ifndef CAL_RAM_H
#define CAL_RAM_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "types.h"
#include "CalRAM_cfg.h" // Get configuration of the Calibration RAM



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// Calibration RAM sector size, in bytes & ROM parameters
#define CR_SECT_SIZE    (512U)

// ROM size, in sectors
#define CR_MAX_SECT_ROM (uint32) 128

// Calibration RAM size, in bytes
#define CR_CAL_RAM_SIZE (CR_MAX_SECT_RAM * CR_SECT_SIZE)

// Additional defines that depend on RAM and ROM parameters
#define CR_BIN_LOG   (uint32)9          // 2^BIN_LOG = SECT_SIZE
#define CR_BIN_MASKA (uint32)0x1FF      // Number of '1's = BIN_LOG: 0x1FF = '111111111'bin



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// Numbers of the ROM sectors that have been copied into the calibration RAM:
// e.g. SectID[i] = N => sector i of ROM has been copied into sector N of RAM;
//      SectID[i] = 0 => sector i hasn't been copied into RAM.
// NB: i = [1..Maximum sectors in ROM]
extern uint8  SectID[];

extern uint8  nCurSectCalRAM; // Number of current free sector in calibration RAM

extern uint32 uwRPSTART;     // Start of the calibration ROM
extern uint32 uwRPEND;       // End of the calibration ROM
extern uint32  uwWPSTART;     // Start of the calibration RAM
extern uint32  uwWPEND;       // End of the calibration RAM
extern uint8*  pStartCalRAM;  // Pointer to the calibration RAM address
extern uint8 bWrkPage;
extern const uint8 cal_data_start;



/***************************************************************************************************/
// Prototypes of global (public) functions
/***************************************************************************************************/

void CalRAM_Init(void);
void CalRAM_Clean(void);
sint8 CalRAM_ReadSectorToRAM(uint32 nSectCalROM);
sint8 CalRAM_WriteSectorToROM(uint8 nSectCalROM);
sint8 CalRAM_WriteLastUsedRAMSectorToROM(void);
uint16 CalRAM_GetSectorNumber(const uint8* pCurAddress);
uint8* CalRAM_Get_Address( uint8* AddrData);



#endif // #ifndef CAL_RAM_H

//************************************** end of file CalRAM.h ***************************************/
