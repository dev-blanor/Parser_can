//**************************************************************************************************
// @Module        Calibration RAM (CalRAM)
// @Filename      CalRAM.c
//--------------------------------------------------------------------------------------------------
// @Description   This file contains functions for calibration RAM module.
//
//                Global (public) functions:
//                  CalRAM_Init()
//                  CalRAM_ReadSectorToRAM()
//                  CalRAM_WriteSectorToROM()
//                  CalRAM_WriteLastUsedRAMSectorToROM()
//                  CalRAM_GetSectorNumber()
//--------------------------------------------------------------------------------------------------
// @Notes         The functions in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.2.0
//--------------------------------------------------------------------------------------------------
// @Date          01.04.2020
//--------------------------------------------------------------------------------------------------
// @History       Version  Author       Comment
//                1.0.1    ASD          First release
//                1.0.2    ASD          All global variables except CalibrationRAM[] are initialized
//                                      in the CalRAM_Init() to make Calibration RAM module independent
//                                      on startup code
//                1.0.3    ASD          Added section for Calibration RAM
//                1.1.0    ASD          Added writing ROM facility
//                1.2.0    Sokolov      Added STM32 support
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "CalRAM.h" // Native header



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************


// Calibration RAM as two contiguous arrays, declared as uint16 type to achieve 16bit alignment.
// Does not need in the initialization
uint32 CalibrationRAM[CR_CAL_RAM_SIZE / 2];

uint32 PS_FLASHDATA_START_ID = APP_ROM_start;
uint32 PS_FLASHDATA_END_ID = APP_ROM_end;

uint32 data_segm_start = APP_RAM_start;
uint32 data_segm_end   = APP_RAM_end;

// Numbers of ROM sectors that have been copied into calibration RAM:
// e.g. SectID[i] = N => sector i of ROM has been copied into sector N of RAM;
//      SectID[i] = 0 => sector i has not been copied into RAM.
// NB: i = [1..CR_MAX_SECT_ROM]
uint8 SectID[CR_MAX_SECT_ROM + 1];

uint8  nCurSectCalRAM;  // Number of current free sector in calibration RAM

uint32  uwWPSTART;      // Work page start address
uint32  uwWPEND;        // Work page end address
uint32  uwRPSTART;      // Reference page start address
uint32  uwRPEND;        // Reference page end address
uint8*  pStartCalRAM;   // Pointer to the calibration RAM address



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// Numbers of calibration RAM sectors witch contain copies of ROM sectors:
// e.g. SectRamID[i] = N => sector i of RAM contain copy of sector N of ROM;
//      SectRamID[i] = 0 => sector i of RAM is free.
// NB: i = [1..CR_MAX_SECT_RAM]
static uint16  SectRamID[CR_MAX_SECT_RAM + 1];



//**************************************************************************************************
//==================================================================================================
// Global (public) functions
//==================================================================================================
//**************************************************************************************************

void CalRAM_Clean(void)
{
  uint16 DataRam_Size;
  uint32* pStartDataRAM; // Pointer to the calibration RAM address
  pStartDataRAM = &CalibrationRAM[0];
  DataRam_Size = CR_CAL_RAM_SIZE / 2;
  for (uint32 i = 0 ; i < DataRam_Size; i++)                                            // rf1
  {
    pStartDataRAM[i] = 0U;
  }
}



//**************************************************************************************************
// @Function      CalRAM_Init()
//--------------------------------------------------------------------------------------------------
// @Description   Clears array of sectors id [rf1], sets number of current free sector of
//                calibration RAM on its first sector [rf2]. Initializes global variables [rf3]
//                (if defined).
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//--------------------------------------------------------------------------------------------------
// @Date          02.2008
//**************************************************************************************************
void CalRAM_Init(void)
{
  uint32 i = 0;                                                                         //
  for ( ; i < CR_MAX_SECT_ROM; i++)                                                     // rf1
  {                                                                                     //
    SectID[i] = 0U;                                                                     //
  }

  i = 0U;         
                                                                                        //
  for ( ; i <= CR_MAX_SECT_RAM; i++)                                                    // rf1
  {                                                                                     //
    SectRamID[i] = 0;                                                                   //
  }

  nCurSectCalRAM = 1U;                                                                  // rf2

  uwWPSTART = (uint32)&CalibrationRAM;
  uwWPEND   = (uint32)&CalibrationRAM[CR_CAL_RAM_SIZE / 2 - 1] + 4;

  uwRPSTART = (uint32)PS_FLASHDATA_START_ID;
  uwRPEND   = (uint32)PS_FLASHDATA_END_ID;
  
  pStartCalRAM = (uint8*)&CalibrationRAM[0];
} // end of CalRAM_Init()



//**************************************************************************************************
// @Function      CalRAM_ReadSectorToRAM()
//--------------------------------------------------------------------------------------------------
// @Description   Checks for correct ROM sector number and returns error code if number was not
//                correct [rf1] otherwise returns 0 [rf7]. Calculates start address of current free
//  sector of calibration RAM [rf2] and start address of ROM sector that must be read [rf3]. Reads
//  the whole sector from ROM into RAM [rf4]. Then stores sector ID number in RAM [rf5] and sets
//  next free sector in RAM [rf6].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue    0 - no error;
//                -1 - error: sector does not exist.
//--------------------------------------------------------------------------------------------------
// @Parameters    nSectCalROM - ROM sector number that must be read into RAM.
//--------------------------------------------------------------------------------------------------
// @Date          02.2008
//**************************************************************************************************
sint8 CalRAM_ReadSectorToRAM(uint32 nSectCalROM)
{
  if ((0 == nSectCalROM) || (nSectCalROM > CR_MAX_SECT_ROM))                            //
  {                                                                                     // rf1
    return -1;                                                                          //
  }

  uint8* pDST = (uint8*)uwWPSTART + ((uint32)(nCurSectCalRAM - 1) << CR_BIN_LOG);       // rf2
  const uint8* pSRC = (uint8*)uwRPSTART + ((uint32)(nSectCalROM - 1) << CR_BIN_LOG);    // rf3

  uint16 i = CR_SECT_SIZE;                                                              //
  while (i--)                                                                           // rf4
  {                                                                                     //
    *pDST++ = *pSRC++;                                                                  //
  }

  SectID[nSectCalROM] = nCurSectCalRAM;                                                 // rf5
  SectRamID[nCurSectCalRAM] = nSectCalROM;                                              //

  nCurSectCalRAM++;                                                                     // rf6

  return 0;                                                                             // rf7
} // end of CalRAM_ReadSectorToRAM()



//**************************************************************************************************
// @Function      CalRAM_WriteSectorToROM()
//--------------------------------------------------------------------------------------------------
// @Description   Checks for correct ROM sector number and returns error code if number was not
//                correct [rf1, rf2] otherwise returns 0 [rf7]. Calculates start address of ROM
//  sector that must be write from RAM [rf3] and start address of sector of calibration RAM where
//  ROM sector was stored [rf4]. Writes the whole sector from RAM into ROM [rf5]. Then clears
//  sector ID number in RAM [rf6].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue    0 - no error;
//                -1 - error: sector doesn't exist;
//                -2 - error: sector isn't in the calibration RAM;
//                -3 - error: cannot write sector to ROM.
//--------------------------------------------------------------------------------------------------
// @Parameters    nSectCalROM - ROM sector number that must be write from RAM.
//--------------------------------------------------------------------------------------------------
// @Date          02.2008
//**************************************************************************************************
sint8 CalRAM_WriteSectorToROM(uint8 nSectCalROM)
{
  if ((0 == nSectCalROM) || (nSectCalROM > CR_MAX_SECT_ROM))                                    //
  {                                                                                             // rf1
    return -1;                                                                                  //
  }
  if (0 == SectID[nSectCalROM])                                                                 //
  {                                                                                             // rf2
    return -2;                                                                                  //
  }

  // todo: FLASH operations removed
  // uint8* pDST = (uint8*)uwRPSTART + ((uint32)(nSectCalROM - 1) << CR_BIN_LOG);                  // rf3
  // const uint8* pSRC = (uint8*)uwWPSTART + ((uint32)(SectID[nSectCalROM] - 1)  << CR_BIN_LOG);   // rf4
  // if (FLASHMEM_Copy(pDST, pSRC, CR_SECT_SIZE) != FLASHMEM_ERR_OK)                               // rf5
  // {
  //   return -3;
  // }

  SectRamID[SectID[nSectCalROM]] = 0;                                                           // rf6
  SectID[nSectCalROM] = 0;                                                                      //

  return 0;                                                                                     // rf7
} // end of CalRAM_WriteSectorToROM()



//**************************************************************************************************
// @Function      CalRAM_WriteLastUsedRAMSectorToROM()
//--------------------------------------------------------------------------------------------------
// @Description   See the function name.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue    0 - no error;
//                -1 - error: cannot write last used RAM sector to ROM.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//--------------------------------------------------------------------------------------------------
// @Date          09.2010
//**************************************************************************************************
sint8 CalRAM_WriteLastUsedRAMSectorToROM(void)
{
  uint8 sectorIdx = nCurSectCalRAM - 1;
  sint8 err = CalRAM_WriteSectorToROM(SectRamID[sectorIdx]);

  // If the sector was written into ROM successfully
  if (err == 0)
  {
    nCurSectCalRAM--;
    return 0;
  }

  return -1;
} // end of CalRAM_WriteLastUsedRAMSectorToROM()



//**************************************************************************************************
// @Function      CalRAM_GetSectorNumber()
//--------------------------------------------------------------------------------------------------
// @Description   Checks for correct address [rf1] and returns 0 if address was not correct (not in
//                calibration ROM) otherwise returns number of sector in ROM for current address in
//  ROM [rf4]. At first calculates sector number with the assumption that current address is the
//  address of the last byte of sector [rf2]. Then determines address is in the next sector if
//  address wasn't divisible by sector size [rf3].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   Number of sector in ROM.
//--------------------------------------------------------------------------------------------------
// @Parameters    pCurAddress - current address for which sector number in ROM must be calculated.
//--------------------------------------------------------------------------------------------------
// @Date          02.2008
//**************************************************************************************************
uint16 CalRAM_GetSectorNumber(const uint8* pCurAddress)
{
  uint16 nSector = 0;

  if ((pCurAddress >= (uint8*)uwRPSTART) &&                                                    // rf1
      (pCurAddress < ((uint8*)uwRPSTART + (CR_MAX_SECT_ROM << CR_BIN_LOG))))                   //
  {
    nSector = (uint16)((1 + pCurAddress - (uint8*)uwRPSTART) >> CR_BIN_LOG);                   // rf2

    if ((uint32)(1 + pCurAddress - (uint8*)uwRPSTART) & CR_BIN_MASKA)                          //
    {                                                                                          // rf3
      nSector++;                                                                               //
    }                                                                                          //
  } // end of if

  return nSector;                                                                              // rf4
} // end of CalRAM_GetSectorNumber()



uint8* CalRAM_Get_Address( uint8* AddrData)
{
  if (bWrkPage)
  {
    uint16 CurrSect = CalRAM_GetSectorNumber(AddrData);

    // Switch pointer into RAM if sector was read into RAM
    if (SectID[CurrSect])
    {
      AddrData = (uint8*)(uwWPSTART + ((uint32)AddrData - uwRPSTART) + 
                 (uint32)((uint32)SectID[CurrSect] << CR_BIN_LOG) - (uint32)((uint32)CurrSect << CR_BIN_LOG));
      return AddrData;
    }
  }
  
  return AddrData;
}



//************************************** end of file CalRAM.c **************************************
