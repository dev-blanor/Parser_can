//**************************************************************************************************
// @Module        Calibration RAM (CalRAM)
// @Filename      CalRAM_cfg.h
//--------------------------------------------------------------------------------------------------
// @Description   This file contains configuration of the required functionality of the Calibration
//                RAM module.
//
//                The Calibration RAM may be allocated for commercial and engineering ECU simultaneously
//                (as a rule, RAM size of commercial ECU is less than RAM size of engineering ECU).
//                The counting of the Calibration RAM sectors starts from the end RAM.

//                The following example shows the allocation of the Calibration RAM for commercial
//                ECU with 32k RAM and engineering ECU with 64k RAM:
//                 ____________________
//                |   CR_MAX_SECT_RAM  |<-- CALRAM_BEG_ADDR
//                |____________________|
//                |                    |
//                |                    |
//                |        ...         |
//                |                    |
//                |____________________|
//                |         65         |
//                |                    |
//                |====================|<-- End of commercial ECU RAM (e.g. 0x00E08000)
//                |         64         |
//                |____________________|
//                |                    |
//                |                    |
//                |        ...         |
//                |                    |
//                |____________________|
//                |         2          |<-- Calibration RAM sector
//                |____________________|
//                |         1          |
//                |____________________|<-- End of engineering ECU RAM (e.g. 0x00E10000) (CALRAM_END_ADDR)
//
//                As you can see, the Calibration RAM is divided into two contiguous parts:
//                - the first 64 Calibration RAM sectors are allocated for engineering ECU only;
//                - the rest of the sectors are allocated for engineering and commercial ECU.
//
//--------------------------------------------------------------------------------------------------
// @Notes:        The constants in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          18.06.2009
//--------------------------------------------------------------------------------------------------
// @History       Version  Author  Comment
//                1.0.0    ASD     First release
//**************************************************************************************************

#ifndef CAL_RAM_CFG_H
#define CAL_RAM_CFG_H



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// Enable/disable CalRAM module dependence on startup code:
// if defined, global variables will be initialized by startup code,
// if not defined, global variables will be initialized by CalRAM module itself
//#define CALRAM_STARTUP_CODE_INIT_GLOBAL

// User can define the size of the Calibration RAM in sectors
#define CR_MAX_SECT_RAM         (8) // min: 64, max: depends on free RAM  64x512-32768 bytes

// User can define the Calibration RAM sector size, in bytes
//#define CALRAM_SECT_SIZE (512)
//#define CALRAM_SECT_SIZE (256)

// User can define the Calibration RAM end address
//#define CALRAM_END_ADDR  (0x00E10000)
// #define CALRAM_END_ADDR  (0x90007FFF)

// The Calibration RAM size, in bytes
// #define CALRAM_SIZE      (CR_MAX_SECT_RAM * CA0x20006690LRAM_SECT_SIZE)

// Calibration RAM start address
// #define CALRAM_BEG_ADDR  (CALRAM_END_ADDR - CALRAM_SIZE)

#define APP_ROM_start				0x00070000
#define APP_ROM_end					0x0007FFFC
#define APP_RAM_start 				0x1FFF8000		//0x20000000
#define APP_RAM_end 				0x20007000		//0x20007FFF



#endif // #ifndef CAL_RAM_CFG_H

//************************************ end of file CalRAM_cfg.h ************************************
