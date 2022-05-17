//**************************************************************************************************
// @Module        CCP
// @Filename      CCPMonitor.c
//--------------------------------------------------------------------------------------------------
// @Description   This file contains functions for processing CCP in slave device.
//                Functions of CAN driver are used to transmit and receive CAN messages.
//
//                Abbreviations:
//                  CRO - Command Receive Object
//                  CRM - Command Return Message
//                  DAQ - Data Acquisition
//                  DTO - Data Transmission Object
//                  ECU - Electronic Control Unit
//                  MO  - Message Object
//                  MTA - Memory Transfer Address
//                  ODT - Object Descriptor Table
//                  RP  - Reference Page
//                  WP  - Work Page
//
//                Global (public) functions:
//                  _InitCCPMonitor()
//                  vProcessCCPCmd()
//                  _DAQprocessor()
//                  CCP_vSaveCalibrationData()
//
//                Local (private) functions:
//                  CCP_vInitGlobalVariables()
//                  CCP_vResetDAQList()
//                  CCP_vResetDAQ()
//                  CCP_vResetCCPMonitor()
//                  CCP_vFillPtrFromCANObj()
//                  CCP_vFillCANObjFromPtr()
//                  CCP_AddressRangeInSlaveDevIdArea()
//                  CCP_AddressRangeInDebugArea()
//                  CCP_AddressRangeInCalibrationArea()
//                  CCP_vSaveRecalcRomChecksum()
//
//                Local (private) functions: CCP commands:
//                  CCP_vProcessUnknownCMD()
//                  CCP_vProcessCMDConnect()
//                  CCP_vProcessCMDSetMTA()
//                  CCP_vProcessCMDDnload()
//                  CCP_vProcessCMDUpload()
//                  CCP_vProcessCMDTest()
//                  CCP_vProcessCMDStartStop()
//                  CCP_vProcessCMDDisconnect()
//                  CCP_vProcessCMDStartStopAll()
//                  CCP_vProcessCMDGetActiveCalPage()
//                  CCP_vProcessCMDSetSStatus()
//                  CCP_vProcessCMDGetSStatus()
//                  CCP_vProcessCMDBuildChksum()
//                  CCP_vProcessCMDShortUp()
//                  CCP_vProcessCMDClearMemory()
//                  CCP_vProcessCMDSelectCalPage()
//                  CCP_vProcessCMDGetSeed()
//                  CCP_vProcessCMDUnlock()
//                  CCP_vProcessCMDGetDAQSize()
//                  CCP_vProcessCMDSetDAQPtr()
//                  CCP_vProcessCMDWriteDAQ()
//                  CCP_vProcessCMDExchangeID()
//                  CCP_vProcessCMDProgram()
//                  CCP_vProcessCMDMove()
//                  CCP_vProcessCMDGetCCPVersion()
//                  CCP_vProcessCMDDiagService()
//                  CCP_vProcessCMDActionService()
//                  CCP_vProcessCMDProgram6()
//                  CCP_vProcessCMDDnload6()
//--------------------------------------------------------------------------------------------------
// @Notes         The functions in this file are processor-independent.
//--------------------------------------------------------------------------------------------------
// @Version       1.2.0
//--------------------------------------------------------------------------------------------------
// @Date          01.04.2020
//--------------------------------------------------------------------------------------------------
// @History       Version  Author    Comment
//                1.0.1    ASD       First release.
//                1.0.2    ASD       Debugging via CCP added.
//                1.0.4    ASD       Optimized for speed, deleted parameter of vProcessCCPCmd() to
//                                   adapt it for System Builder.
//                1.1.0    ASD       vProcessCCPCmd() and _DAQprocessor() put CRM and Data Acquisition
//                                   Messages into transmit buffer, respectively;
//                                   vProcessCCPCmd() reads CCP command from receive buffer and puts
//                                   CRM into transmit buffer;
//                                   vProcessCCPCmd() is split into separate functions.
//                1.1.1    ASD       In order to provide mutual independence of vProcessCCPCmd() and
//                                   _DAQprocessor(), they use common semaphore.
//                1.1.2    ASD       Added checking received address for legal address range to prevent
//                                   illegal data access. Added Can Calibration Protocol enable flag
//                                   to give an opportunity to turn CCP off.
//                1.1.3    ASD       Added CCP_vInitGlobalVariables() to make CCP module independent
//                                   on startup code.
//                1.1.4    ASD       Temporary variables for storing values of registers are cleaned
//                                   after power-on reset only.
//                1.1.5    ASD       Temporary variables for storing values of registers removed from
//                                   CCP module.
//                1.1.6    ASD       Added checking the current CCP command to be processed for
//                                   reiteration.
//                1.1.7    ASD       Added saving calibration data into flash ECU.
//                1.1.8    ASD       Added storing calibration data after disconnection.
//                1.1.9    ASD       Changing the global active page flag only if the calibration is active.
//                1.1.10   ASD       If the current CCP command equals the previous one, do not process it,
//                                   just repeat the previous answer to CCP master.
//                1.1.11   ASD       Added reading CCP slave device ID information. Added CCP connected flag.
//                1.1.12   ASD       Adapted for a lot of MISRA-C 2004 rules.
//                1.2.0    Sokolov      Added STM32 support
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "CCPMonitor.h"         // Native header
#include "Can_drv_cfg.h"		// TODO without was error, but it define in #include "CCPMonitor.h"
                                // get configuration and read parameters of calibration RAM and ROM
//#include "rom_crc32.h"        // To count flash checksum after saving calibration data
//#include "Flash.h"            // To get flash page size
//#include "flashmem.h"         // To write recalculated flash checksum into the flash
//#include "flashload.h"        // To execute external functions
//#include "UART_lib.h"

//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// Can Calibration Protocol enable flag
 volatile uint8 osCCPENABLE;

// Global active page flag: TRUE - Work page; FALSE - Reference page
// Referenced in MSE DA as well
uint8 bWrkPage;
uint8 osCOPYWPTORP;


//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// Defines for CCP Master
#if CCP_FOR_MASTER == 1
# define ETAS_PCMCIA_INCA54 // CCP Master is INCA v5.4 through ETAS PCMCIA
#endif
#if CCP_FOR_MASTER == 2
# define ELCAR_USB          // CCP Master is INCA through ELCAR USB
#endif
// NB: Otherwise CCP Master is INCA v5.3 through ETAS PCMCIA (default)

#define OFF                             (0)
#define ON                              (1)

// Defines for other CCP Configuration
#define CCP_MAIN_VER_IMPL               (0x02U) // Main Protocol version as implemented
#define CCP_RELEASE_VER_IMPL            (0x01U) // Release within version as implemented
#define CCP_SLAVE_DEV_ID_TYPE           (0x00U) // Data type qualifier of slave device ID
#define CCP_RES_PROT_MSK_VAL            (0x00U) // Resource Protection Mask Value

// Defines for CCP commands (1st CRO byte)
#define CCP_CMD_CONNECT                 (0x01U) // Connect
#define CCP_CMD_DISCONNECT              (0x07U) // Disconnect
#define CCP_CMD_SET_MTA                 (0x02U) // Set Memory Transfer Address
#define CCP_CMD_GET_CCP_VER             (0x1BU) // Get Implemented Version of CCP
#define CCP_CMD_EXCHANGE_ID             (0x17U) // Exchange Station Identifications
#define CCP_CMD_UPLOAD                  (0x04U) // Data Upload
#define CCP_CMD_SHORT_UPLD              (0x0FU) // Short Upload
#define CCP_CMD_DNLOAD                  (0x03U) // Data Download
#define CCP_CMD_DNLOAD_6                (0x23U) // Data Download 6 bytes
#define CCP_CMD_SELECT_CAL_PAGE         (0x11U) // Select Calibration Data Page
#define CCP_CMD_GET_ACTIVE_CAL_PAGE     (0x09U) // Get currently active Calibration Page
#define CCP_CMD_MOVE                    (0x19U) // Move memory block
#define CCP_CMD_GET_S_STATUS            (0x0DU) // Get Session Status
#define CCP_CMD_SET_S_STATUS            (0x0CU) // Set Session Status
#define CCP_CMD_BUILD_CHKSUM            (0x0EU) // Build Checksum
#define CCP_CMD_GET_DAQ_SIZE            (0x14U) // Get Size of DAQ list
#define CCP_CMD_SET_DAQ_PTR             (0x15U) // Set DAQ list pointer
#define CCP_CMD_WRITE_DAQ               (0x16U) // Write DAQ list entry
#define CCP_CMD_START_STOP              (0x06U) // Start / Stop Data transmission
#define CCP_CMD_START_STOP_ALL          (0x08U) // Start / Stop Synchronized Data transmission
#define CCP_CMD_ACTION_SERVICE          (0x21U) // Action Service

// Defines for CCP DTO IDs (1st DTO byte)
#define CCP_ID_DTO_CRM                  (0xFFU) // DTO contains a Command Return Message
#define CCP_ID_DTO_EVM                  (0xFEU) // DTO contains a Event Message
// NB: Other DTO are DAQ messages and its IDs are equal to numbers of appropriate ODT accordingly

// Defines for CCP error codes (2nd DTO-CRM byte)
#define CCP_ERR_ACKNOWLEDGE             (0x00U) // Acknowledge (no error)
#define CCP_ERR_COLD_START_REQUEST      (0x20U) // Cold start request
#define CCP_ERR_UNKNOWN_COMMAND         (0x30U) // Unknown command
#define CCP_ERR_PARAM_OUT_RANGE         (0x32U) // Parameter(s) out of  range
#define CCP_ERR_ACCESS_DENIED           (0x33U) // Access denied
#define CCP_ERR_OVERLOAD                (0x34U) // Overload
#define CCP_ERR_RESOURCE_NOT_AVAIL      (0x36U) // Resource/function not available

// Defines for DAQ
#define CCP_DAQ_LIST_INIT_MAX_NUM       (5U)
#define CCP_DAQ_LIST_MAX_NUM            (3U) // Total number of DAQ lists [0..4]
#define CCP_DAQ_LIST_SIZE               (50U) // Number of ODT per DAQ list
#define CCP_ODT_SIZE                    (7U) // Number of Elements per ODT
// NB: DAQ structures (1 DAQ list with 20 ODTs with 7 elements each)

// Defines for Action Service
#define CCP_ACT_SRV_CALIBRATION 0x03

// Other CCP Defines
#define CCP_MAX_CMD_NUM                 (0x23U) // Last number of CCP command
#define CCP_CHKSUM_SIZE                 (2U) // Size of check sum is 2 bytes (last)
#define CCP_LAST_BYTE_OF_SIZE_MOVE      (5U) // Last byte of parameter "size of DB" in CMD MOVE
#define CCP_MAX_SENT_BYTES              (6U) // Max number of bytes which could be sent by 1 object (sending)
#define CCP_SS_CAL                      (0x01U) // Calibration data initialized, bit 0 of session status byte
#define CCP_SS_DAQ                      (0x02U) // DAQ list(s) initialize,  bit 1 of session status byte
#define CCP_MES_DATA_SIZE               (8U) // Size of data filed of Message Object



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

// For work with status byte in GET_S_STATUS � SET_S_STATUS commands
typedef union {
    struct {
    	uint8 bCAL     : 1; // Bit 0 - Calibration data initialized
        uint8 bDAQ     : 1; // Bit 1 - DAQ list(s) initialized
        uint8 bRESUME  : 1; // Bit 2 - Request to save DAQ setup during shutdown in ECU
        uint8          : 3; // Bit [3..5] - Reserved
        uint8 bSTORE   : 1; // Bit 6 - Request to save calibration data during shut-down in ECU
        uint8 bRUN     : 1; // Bit 7 - Session in progress
    } B;                 // Flags of 8-bit session status register
    uint8 REG;              // 8-bit session status register
} stCAN_SESSION_STATUS;

// Object Descriptor (OD): 1 element of the ODT
typedef struct {
    uint8* pubAddr;   // Address of DAQ element
    uint8  ubSize;    // Size of DAQ element in bytes {1, 2, 4}
    uint8  ubAddrExt; // Address extension of DAQ element
} stDAQ_ODT_Element_type;

// ODT type
typedef stDAQ_ODT_Element_type stODT_type[CCP_ODT_SIZE];

// DAQ list parameters
typedef struct {
    boolean blDAQIsRunning;             // If TRUE then DAQ process for the list is running
    boolean blPrepared;                 // If TRUE then the list is ready to start DAQ process
    uint16  usDAQRatePrescaler;            // Transmission rate prescaler
    uint16  usDAQRatePrescalerCtr;         // Counter for usDAQRatePrescaler
    uint8   ubDAQLastODTNum;               // Specifies which ODTs [0..LastODT] of this DAQ list should be transmitted
    uint8   ubDAQEventChannel;             // Number of event channel
    uint16  uwDAQCANID;                    // CAN ID for MO servicing this DAQ list
    uint8   ubCANMO;                       // Number of �� servicing this DAQ list
    //uint16  volatile __far* puwCANMOAR;    // Address of CAN MOAR register
    stODT_type ODTs[CCP_DAQ_LIST_SIZE]; // Every DAQ list contains 20 ODTs of 7 elements each
} stDAQ_LIST_PARAM;

// Constant parameters for initialization
typedef struct {
    uint8  ubCANMO;                    // Number of �� servicing this DAQ list
    //uint16 volatile __far* puwCANMOAR; // Address of CAN MOAR register
} stDAQ_LIST_CONST_PARAM;

typedef union	STRUCTURED_UNION_tag
{
		struct
		{
			uint8	byte[8];
		} bytes;
		uint64	frame;
} STRUCTURED_FRAME_TYPE;



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// Constant parameters for every DAQ list: �� and its MOAR
// (CAN_MOARxH aren't used as 11-bit standard ID is used)
static const stDAQ_LIST_CONST_PARAM DAQListsConsts[CCP_DAQ_LIST_INIT_MAX_NUM] = {{CCP_DAQ_0_MO_NUM/*, &CAN_MOAR10H.U*/},
                                                                                 {CCP_DAQ_1_MO_NUM/*, &CAN_MOAR11H.U*/},
                                                                                 {CCP_DAQ_2_MO_NUM/*, &CAN_MOAR12H.U*/},
                                                                                 {CCP_DAQ_3_MO_NUM/*, &CAN_MOAR13H.U*/},
                                                                                 {CCP_EMU_4_MO_NUM/*, &CAN_MOAR14H.U*/}};
static const uint8 ubDeviceId[] = CCP_SLAVE_DEV_ID;      // Slave device ID
static const uint8 ubDeviceIdLen = sizeof(ubDeviceId);   // Length of slave device ID in bytes
static const uint8 ubResAvMsk = CCP_SS_CAL | CCP_SS_DAQ; // Resource Availability Mask



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// Common semaphore for CCP global functions
static volatile sint16 semaphoreCCP;

// To work with status byte in GET_S_STATUS and SET_S_STATUS commands
static stCAN_SESSION_STATUS CANSessionStatus;

// Content of received MO
static stCAN_SWObj stCANObjRXContent;

// Content of transmit MO
static stCAN_SWObj stCANObjTXContent;

// Parameters of every DAQ list
static stDAQ_LIST_PARAM DAQLists[CCP_DAQ_LIST_MAX_NUM];

// Source pointer
static uint8* pubMTAPtr0;

// Destination pointer
static uint8*  pubMTAPtr1;

// Depends on the slave controller's organization, may identify a switchable memory bank or a memory segment
static uint8 ubMTAAddressExtension;

// Pointer to calibration page (RP or WP)
static uint8* pubCalPageAddr;

// DAQ list number
static uint8 ubDAQElemIdx;

// ODT number
static  uint8 ubDAQODTIdx;

// Element number within ODT
static  uint8 ubDAQListIdx;

// Request to save calibration data
static  boolean bSaveCalibDataRequest;

// Calibration active flag
static  boolean CCP_bCalibration;

// Local active page flag: TRUE - Work page; FALSE - Reference page
static  boolean CCP_bWrkPage;

// CCP connected flag: TRUE - connected; FALSE - disconnected
static  boolean CCP_bConnected;

// CCP disconnect request
static  boolean CCP_bDisconnectRequest;

// Element number within ODT
static  uint8 Inca_Type = 0;			//0 - 5.4, 1 - 7.2
//**************************************************************************************************
// Prototypes of local (private) functions
//**************************************************************************************************

static void CCP_vInitGlobalVariables(void);

static void CCP_vResetDAQList(const uint8 ubDAQListNum);

static void CCP_vResetDAQ(void);

static void CCP_vResetCCPMonitor(void);

static void CCP_vFillPtrFromCANObj(uint8** const pubPtr,
                                   const stCAN_SWObj* const CANObj,
                                   const uint8 ubCANLastByteOfAddr);

static void CCP_vFillCANObjFromPtr(stCAN_SWObj* const CANObj,
                                   uint8*const* const pubPtr,
                                   const uint8 ubCANLastByteOfAddr);


static boolean CCP_AddressRangeInSlaveDevIdArea(const uint32 ulAddrStart,
                                                const uint32 ulAddrEnd);

static boolean CCP_AddressRangeInDebugArea(const uint32 ulAddrStart,
                                           const uint32 ulAddrEnd);

static boolean CCP_AddressRangeInCalibrationArea(const uint32 ulAddrStart,
                                                 const uint32 ulAddrEnd);

//static void CCP_vSaveRecalcRomChecksum(void);

// CCP commands
static void CCP_vProcessUnknownCMD(void);
static void CCP_vProcessCMDConnect(void);
static void CCP_vProcessCMDSetMTA(void);
static void CCP_vProcessCMDDnload(void);
static void CCP_vProcessCMDUpload(void);
static void CCP_vProcessCMDTest(void);
static void CCP_vProcessCMDStartStop(void);
static void CCP_vProcessCMDDisconnect(void);
static void CCP_vProcessCMDStartStopAll(void);
static void CCP_vProcessCMDGetActiveCalPage(void);
static void CCP_vProcessCMDSetSStatus(void);
static void CCP_vProcessCMDGetSStatus(void);
static void CCP_vProcessCMDBuildChksum(void);
static void CCP_vProcessCMDShortUp(void);
static void CCP_vProcessCMDClearMemory(void);
static void CCP_vProcessCMDSelectCalPage(void);
static void CCP_vProcessCMDGetSeed(void);
static void CCP_vProcessCMDUnlock(void);
static void CCP_vProcessCMDGetDAQSize(void);
static void CCP_vProcessCMDSetDAQPtr(void);
static void CCP_vProcessCMDWriteDAQ(void);
static void CCP_vProcessCMDExchangeID(void);
static void CCP_vProcessCMDProgram(void);
static void CCP_vProcessCMDMove(void);
static void CCP_vProcessCMDGetCCPVersion(void);
static void CCP_vProcessCMDDiagService(void);
static void CCP_vProcessCMDActionService(void);
static void CCP_vProcessCMDProgram6(void);
static void CCP_vProcessCMDDnload6(void);

// Table of pointers to functions processing CCP commands
static void (* const pvProcessCMDFunctions[CCP_MAX_CMD_NUM + 1U])(void) = {
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    CCP_vProcessCMDConnect,          // CMD code 0x01
    CCP_vProcessCMDSetMTA,           // CMD code 0x02
    #if (CCP_SUPPORT_LEVEL < 3)
    CCP_vProcessCMDDnload,           // CMD code 0x03
    CCP_vProcessCMDUpload,           // CMD code 0x04
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    #if (CCP_SUPPORT_LEVEL < 1)
    CCP_vProcessCMDTest,             // CMD code 0x05
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    CCP_vProcessCMDStartStop,        // CMD code 0x06
    CCP_vProcessCMDDisconnect,       // CMD code 0x07
    CCP_vProcessCMDStartStopAll,     // CMD code 0x08
    #if (CCP_SUPPORT_LEVEL < 3)
    CCP_vProcessCMDGetActiveCalPage, // CMD code 0x09
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    CCP_vProcessUnknownCMD,          // CMD code 0x0A, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x0B, not defined
    #if (CCP_SUPPORT_LEVEL < 2)
    CCP_vProcessCMDSetSStatus,       // CMD code 0x0C
    CCP_vProcessCMDGetSStatus,       // CMD code 0x0D
    CCP_vProcessCMDBuildChksum,      // CMD code 0x0E
    CCP_vProcessCMDShortUp,          // CMD code 0x0F
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    #if (CCP_SUPPORT_LEVEL < 1)
    CCP_vProcessCMDClearMemory,      // CMD code 0x10
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    #if (CCP_SUPPORT_LEVEL < 3)
    CCP_vProcessCMDSelectCalPage,    // CMD code 0x11
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    #if (CCP_SUPPORT_LEVEL < 1)
    CCP_vProcessCMDGetSeed,          // CMD code 0x12
    CCP_vProcessCMDUnlock,           // CMD code 0x13
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    CCP_vProcessCMDGetDAQSize,       // CMD code 0x14
    CCP_vProcessCMDSetDAQPtr,        // CMD code 0x15
    CCP_vProcessCMDWriteDAQ,         // CMD code 0x16
    CCP_vProcessCMDExchangeID,       // CMD code 0x17
    #if (CCP_SUPPORT_LEVEL < 3)
    CCP_vProcessCMDProgram,          // CMD code 0x18
    CCP_vProcessCMDMove,             // CMD code 0x19
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    CCP_vProcessUnknownCMD,          // CMD code 0x1A, not defined
    CCP_vProcessCMDGetCCPVersion,    // CMD code 0x1B
    CCP_vProcessUnknownCMD,          // CMD code 0x1C, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x1D, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x1E, not defined
    CCP_vProcessUnknownCMD,          // CMD code 0x1F, not defined
    #if (CCP_SUPPORT_LEVEL < 1)
    CCP_vProcessCMDDiagService,      // CMD code 0x20
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    #if (CCP_SUPPORT_LEVEL < 2)
    CCP_vProcessCMDActionService,    // CMD code 0x21
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    #if (CCP_SUPPORT_LEVEL < 1)
    CCP_vProcessCMDProgram6,         // CMD code 0x22
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
    #if (CCP_SUPPORT_LEVEL < 3)
    CCP_vProcessCMDDnload6           // CMD code 0x23
    #else
    CCP_vProcessUnknownCMD,          // CMD code 0x00, not defined
    #endif
};


//**************************************************************************************************
//==================================================================================================
// Global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      _InitCCPMonitor()
//--------------------------------------------------------------------------------------------------
// @Description   Initializes CAN [rf1], global variables [rf2], fills CRM [rf3], then initializes
//                Calibration RAM [rf4], resets CCP Monitor [rf5].
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//                Should be called in general initialization function.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
void _InitCCPMonitor(void)
{

    CCP_vInitGlobalVariables();                                                         // rf2

    stCANObjTXContent.data[0] = CCP_ID_DTO_CRM;                                         // rf3

    CalRAM_Init();                                                                      // rf4
    CalRAM_Clean();
    pubCalPageAddr = (uint8*)uwRPSTART;
    CCP_bWrkPage = 0;
    bWrkPage = 0;
    CCP_bCalibration = 1;
    CCP_bConnected = 0;
    CCP_bDisconnectRequest = 0;
    CCP_vResetCCPMonitor();
                                                                                        // rf5
} // end of _InitCCPMonitor()


//**************************************************************************************************

void API_CAN_Thread_HexFlash(uint32 const MsgId,
                             uint32 const Buffer8_Addr
                             )
{
  API_CAN_Thread_CCP(MsgId, Buffer8_Addr);
}



void API_CAN_Thread_CCP(uint32 const MsgId,
                        uint32 const Buffer8_Addr
                        ) // Action Call
{
  STRUCTURED_FRAME_TYPE pFrameData;

  // Close semaphore -> capture code
  semaphoreCCP++;
  // If code is free
  if (0 == semaphoreCCP)
  {
    // If CCP is enabled
    if (osCCPENABLE)
    {
      uint8 *pData=NULL;
      pData=(uint8*)Buffer8_Addr;
      for (uint8 cnt=0;cnt<8;cnt++)
      {
        pFrameData.bytes.byte[cnt]=pData[cnt];
      }
      
      if (pFrameData.frame != stCANObjRXContent.frame)
      {
        stCANObjRXContent.frame=pFrameData.frame;
        stCANObjRXContent.id = MsgId;
        stCANObjTXContent.data[1] = CCP_ERR_ACKNOWLEDGE;
        stCANObjTXContent.data[2] = stCANObjRXContent.data[1];
        stCANObjTXContent.data[3] = 0U;
        stCANObjTXContent.data[4] = 0U;
        stCANObjTXContent.data[5] = 0U;
        stCANObjTXContent.data[6] = 0U;
        stCANObjTXContent.data[7] = 0U;

        // Processes the current command and form the answer
        if (stCANObjRXContent.data[0] <= CCP_MAX_CMD_NUM)
        {
          pvProcessCMDFunctions[stCANObjRXContent.data[0]]();
        }
        else
        {
          CCP_vProcessUnknownCMD();
        }
      }

      // Send answer only if connected
      if (CCP_bConnected)
      {
        if(MsgId!=0x04)
        {
          CAN_TransmitMsg((enCAN_NODE_NUM)CAN_NODE_FOR_CCP,
                         CCP_CRM_MO_NUM,
                         ID_CRM,
                         stCANObjTXContent.data,
                         8);
        }
        else
        {
          CAN_TransmitMsg((enCAN_NODE_NUM)0,
                         MO_NODE0_OUT,
                         0x05,
                         stCANObjTXContent.data,
                         8);
        }
       
        if (CCP_bDisconnectRequest)
        {
          CCP_bDisconnectRequest = 0;
          CCP_bConnected = 0;
        }
      }
    } // end of if (osCCPENABLE)
  } // end of if (0 == semaphoreCCP)

  // Open semaphore -> free code
  semaphoreCCP--;
}


//**************************************************************************************************
// @Function      vProcessCCPCmd()
//--------------------------------------------------------------------------------------------------
// @Description   If CCP is enabled, reads one CCP command from CAN receive buffer.
//                Ignores the current command if it equals the previous one, otherwise processes
//  the current command, forms answer and puts it into the CAN transmit buffer.
//  This function is reentrant. Reentrance is provided by semaphoreCCP closing, check busy and opening.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//                Should be called from periodical time triggered level.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
void vProcessCCPCmd(void)
{
  // Close semaphore -> capture code
  semaphoreCCP++;
  // If code is free
  if (0 == semaphoreCCP)
  {
    // If CCP is enabled
    if (osCCPENABLE)
    {
      // Read one CCP command from CAN receive buffer
      uint8 msgNum;
      uint32 msgID;
      stCAN_SWObj stCMDData;
      uint8_t msgDlc;
      enCAN_ERR canErr = CAN_ReceiveMsg((enCAN_NODE_NUM)CCP_CAN_NODE_NUM,
                                        &msgNum,
                                        &msgID,
                                        stCMDData.data,
                                        &msgDlc);

      if (msgID == ID_CRO)
      {
        // Ignore the current command if it equals the previous one
        // if (*((U64*)&stCMDData.data) != *((U64*)&stCANObjRXContent.data))
        if (*((uint32*)&stCMDData.data) != *((uint32*)&stCANObjRXContent.data))
        {
          stCANObjRXContent = stCMDData;

          stCANObjTXContent.data[1] = CCP_ERR_ACKNOWLEDGE;
          stCANObjTXContent.data[2] = stCANObjRXContent.data[1];
          stCANObjTXContent.data[3] = 0U;
          stCANObjTXContent.data[4] = 0U;
          stCANObjTXContent.data[5] = 0U;
          stCANObjTXContent.data[6] = 0U;
          stCANObjTXContent.data[7] = 0U;

          // Processes the current command and form the answer
          if (stCANObjRXContent.data[0] <= CCP_MAX_CMD_NUM)
          {
              pvProcessCMDFunctions[stCANObjRXContent.data[0]]();
          }
          else
          {
              CCP_vProcessUnknownCMD();
          }
        }
        else
        {
          // Do nothing, just repeat the previous answer to CCP master
        }

        // Send answer only if connected
        if (CCP_bConnected)
        {
          CAN_TransmitMsg((enCAN_NODE_NUM)CAN_NODE_FOR_CCP,
                          CCP_CRM_MO_NUM,
                          ID_CRM,
                          stCANObjTXContent.data,
                          8);

          if (CCP_bDisconnectRequest)
          {
            CCP_bDisconnectRequest = 0;
            CCP_bConnected = 0;
          }
        }
      }
    } // end of if (osCCPENABLE)
  } // end of if (0 == semaphoreCCP)

  // Open semaphore -> free code
  semaphoreCCP--;
} // end of vProcessCCPCmd()



//**************************************************************************************************
// @Function      _DAQprocessor()
//--------------------------------------------------------------------------------------------------
// @Description   Executes DAQ process. Scans all ODT, collects requested data using pointed
//                addresses and puts it into transmit buffer. Starts from null ODT, and finishes by
//  ODT used in command START_STOP. If ODT element is not filled, just pass it.
//  This function is reentrant. Reentrance is provided by semaphore semaphoreCCP.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//                Should be called from periodical time triggered level.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    uwEventChannel - number of event channel.
//**************************************************************************************************
void _DAQprocessor(const uint32 uwEventChannel)
{
  // Close semaphore -> capture code
  semaphoreCCP++;

  // If code is free
  if (0 == semaphoreCCP)
  {
    static stCAN_SWObj stCANObjTXDaqContent;
    uint8 ubListIdx = 0U;
    stDAQ_LIST_PARAM * pstThisDAQList = DAQLists + ubListIdx;

    for ( ; ubListIdx < CCP_DAQ_LIST_MAX_NUM; ubListIdx++)
    {
      if ((uwEventChannel == pstThisDAQList->ubDAQEventChannel) &&  (pstThisDAQList->blDAQIsRunning))
      {
        if (pstThisDAQList->usDAQRatePrescalerCtr == pstThisDAQList->usDAQRatePrescaler)
        {
            uint8 ubDAQFirstODTNum = ubListIdx * CCP_DAQ_LIST_SIZE;
            uint8 ubODTidx = 0U;
            for ( ; ubODTidx <= pstThisDAQList->ubDAQLastODTNum; ubODTidx++)
            {
              stCANObjTXDaqContent.data[0] = ubODTidx + ubDAQFirstODTNum;

              uint8 ubElemIdx = 0U;
              uint8 ubDAQMsgIdx = 1U;
              stDAQ_ODT_Element_type * pstDAQ_ODT_ThisElement = *(pstThisDAQList->ODTs + ubODTidx) + ubElemIdx;
              for ( ; ubElemIdx < CCP_ODT_SIZE; ubElemIdx++)
              {
                uint8 ubThisElementSize = pstDAQ_ODT_ThisElement->ubSize;
                if ((ubThisElementSize) && (ubThisElementSize + ubDAQMsgIdx <= CCP_MES_DATA_SIZE))
                {
                  uint8 ubI=0;
                  for (ubI = 0; ubI < ubThisElementSize; ubI++)
                  {
                    stCANObjTXDaqContent.data[ubDAQMsgIdx] = *(pstDAQ_ODT_ThisElement->pubAddr + ubI);
                    ubDAQMsgIdx++;
                  }
                }
                pstDAQ_ODT_ThisElement++;
              }

              // Send DAQ to CCP master via CAN
              stCANObjTXDaqContent.id=pstThisDAQList->uwDAQCANID;
              CAN_TransmitMsg((enCAN_NODE_NUM)CAN_NODE_FOR_CCP,
                              pstThisDAQList->ubCANMO,
                              stCANObjTXDaqContent.id,
                              stCANObjTXDaqContent.data,
                              8);
          }

          pstThisDAQList->usDAQRatePrescalerCtr = 1U;
        }
        else
        {
          pstThisDAQList->usDAQRatePrescalerCtr++;
        }
      }

      pstThisDAQList++;
    }
  }

  // Open semaphore -> free code
  semaphoreCCP--;
}

//**************************************************************************************************
// @Function      CCP_vSaveCalibrationData()
//--------------------------------------------------------------------------------------------------
// @Description   Saves one last used sector of calibration data from RAM into ECU flash.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    forceSave:
//                  TRUE: do save right now regardless of request to save calibration data from CCP master;
//                  FALSE: save calibration data only if CCP master requested saving calibration data
//**************************************************************************************************
void CCP_vSaveCalibrationData(const boolean forceSave)
{
  // Close the semaphore -> capture the program code
  semaphoreCCP++;

  // If the program code is free
  if (0 == semaphoreCCP)
  {
    // If the calibration data storing is active
    if (forceSave || bSaveCalibDataRequest)
    {
      static boolean  savingCalibrationDataComplete = 0;

      // If the calibration data storing was not yet completed
      if (!savingCalibrationDataComplete)
      {
        // If it is impossible to store the calibration data anymore
        // (because of all the calibration data was stored or failed to write/erase flash)
        if (CalRAM_WriteLastUsedRAMSectorToROM() != 0)
        {
          savingCalibrationDataComplete = 1;
        }
      }
      else
      {
        bSaveCalibDataRequest = 0;
        savingCalibrationDataComplete = 0;
        osCOPYWPTORP=0;
      } // end of else of if (!savingCalibrationDataComplete)
    } // end of if (forceSave || bSaveCalibDataRequest)
  } // end of if (0 == semaphoreCCP)

  // Open the semaphore -> free the program code
  semaphoreCCP--;
} // end of CCP_vSaveCalibrationData()



//**************************************************************************************************
//==================================================================================================
// Local (private) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      CCP_vInitGlobalVariables()
//--------------------------------------------------------------------------------------------------
// @Description   Initializes global variables which require one-time initialization.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//                If copying initialized data from ROM to RAM and zeroing the uninitialized data area
//  are used in startup code, this function should not be called. Otherwise must be called once.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vInitGlobalVariables(void)
{
  // Enable CCP if it is set up by user
  #if (CCP_ON_INIT_ENABLED == ON)
  osCCPENABLE = 1U;
  #else
  osCCPENABLE = 0U;
  #endif // #if (CCP_ON_INIT_ENABLED == ON)

  // Initialize semaphore
  semaphoreCCP = -1;

  // Initialize stCANObjTXContent
  stCANObjTXContent.id = 0x00000000U;
  stCANObjTXContent.data[0] = 0x00U;
  stCANObjTXContent.data[1] = 0x00U;
  stCANObjTXContent.data[2] = 0x00U;
  stCANObjTXContent.data[3] = 0x00U;
  stCANObjTXContent.data[4] = 0x00U;
  stCANObjTXContent.data[5] = 0x00U;
  stCANObjTXContent.data[6] = 0x00U;
  stCANObjTXContent.data[7] = 0x00U;

  // Initialize stCANObjRXContent
  stCANObjRXContent.id = 0x00000000U;
  stCANObjRXContent.data[0] = 0x00U;
  stCANObjRXContent.data[1] = 0x00U;
  stCANObjRXContent.data[2] = 0x00U;
  stCANObjRXContent.data[3] = 0x00U;
  stCANObjRXContent.data[4] = 0x00U;
  stCANObjRXContent.data[5] = 0x00U;
  stCANObjRXContent.data[6] = 0x00U;
  stCANObjRXContent.data[7] = 0x00U;
} // end of CCP_vInitGlobalVariables()



//**************************************************************************************************
// @Function      CCP_vResetDAQList()
//--------------------------------------------------------------------------------------------------
// @Description   Zeros variables belong to DAQ list, that will be reseted.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    ubDAQListNum - number DAQ list, that have to be zeroed.
//**************************************************************************************************
static void CCP_vResetDAQList(const uint8 ubDAQListNum)
{
  stDAQ_LIST_PARAM * pstThisDAQList = DAQLists + ubDAQListNum;
  stDAQ_LIST_CONST_PARAM* pstThisDAQListConsts = (stDAQ_LIST_CONST_PARAM*)(DAQListsConsts + ubDAQListNum);

  pstThisDAQList->blDAQIsRunning = 0;
  pstThisDAQList->blPrepared = 0;
  pstThisDAQList->usDAQRatePrescaler = 0U;
  pstThisDAQList->usDAQRatePrescalerCtr = 0U;
  pstThisDAQList->ubDAQLastODTNum = 0U;
  pstThisDAQList->ubDAQEventChannel = 0U;
  pstThisDAQList->uwDAQCANID = 0U;
  pstThisDAQList->ubCANMO = pstThisDAQListConsts->ubCANMO;

  // Initialize ODTs
  for (ubDAQODTIdx = 0U; ubDAQODTIdx < CCP_DAQ_LIST_SIZE; ubDAQODTIdx++)
  {
    for (ubDAQElemIdx = 0U; ubDAQElemIdx < CCP_ODT_SIZE; ubDAQElemIdx++)
    {
      stDAQ_ODT_Element_type * pstDAQ_ODT_ThisElement =
          *(pstThisDAQList->ODTs + ubDAQODTIdx) + ubDAQElemIdx;
      pstDAQ_ODT_ThisElement->pubAddr = P_NULL;
      pstDAQ_ODT_ThisElement->ubSize = 0U;
      pstDAQ_ODT_ThisElement->ubAddrExt = 0U;
    } // end of for
  } // end of for
} // end of CCP_vResetDAQList()



//**************************************************************************************************
// @Function      CCP_vResetDAQ()
//--------------------------------------------------------------------------------------------------
// @Description   Zeros the all variables belong to the all DAQ list.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vResetDAQ(void)
{
  // Initialize parameters of DAQ-lists
  for (ubDAQListIdx = 0U; ubDAQListIdx < CCP_DAQ_LIST_MAX_NUM; ubDAQListIdx++)
  {
    CCP_vResetDAQList(ubDAQListIdx);
  } // end of for

  ubDAQListIdx = 0U;
  ubDAQODTIdx = 0U;
  ubDAQElemIdx = 0U;
} // end of CCP_vResetDAQ()



//**************************************************************************************************
// @Function      CCP_vResetCCPMonitor()
//--------------------------------------------------------------------------------------------------
// @Description   Zeros the all variables belong to the all DAQ list.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vResetCCPMonitor(void)
{
  CCP_vResetDAQ();
  CANSessionStatus.REG = 0U;
  pubMTAPtr0 = (uint8*)P_NULL;
  pubMTAPtr1 = (uint8*)P_NULL;
  ubMTAAddressExtension = 0U;
  bSaveCalibDataRequest = 0;
  Inca_Type=0;
} // end of CCP_vResetCCPMonitor()



//**************************************************************************************************
// @Function      CCP_vFillPtrFromCANObj() and CCP_vFillCANObjFromPtr()
//--------------------------------------------------------------------------------------------------
// @Description   One function fills the pointer with address from CAN object (data bytes) and the
//                other conversely fills the CAN object from the pointer.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    pubPtr - pointer to pointer to byte. This is a reference to the memory address.
//                  This address have a reverse (Intel) format in pointer and a direct (Motorola)
//                  format in the CAN object. So a pointer to pointer must be sent to function to
//                  fill in the program variable (pointer) byte to byte (and vice versa);
//                CANObj - contains the data structure address with data bytes, the most significant
//                  byte first;
//                ubCANLastByteOfAddr - last byte of 4 data bytes for the address in the CAN object
//                  (different in different acknowledges).
//**************************************************************************************************
static void CCP_vFillPtrFromCANObj(uint8** const pubPtr,
                                   const stCAN_SWObj* const CANObj,
                                   const uint8 ubCANLastByteOfAddr)
{
  uint8 i = 0U;
  for ( ; i < 4; i++) // fill back to front
  {
    *((uint8*)pubPtr + i) = CANObj->data[ubCANLastByteOfAddr - i];
  } // end of for
} // end of CCP_vFillPtrFromCANObj()

static void CCP_vFillCANObjFromPtr(stCAN_SWObj* const CANObj,
                                   uint8*const* const pubPtr,
                                   const uint8 ubCANLastByteOfAddr)
{
  uint8 i = 0U;
  for ( ; i < 4; i++) // fill back to front
  {
    CANObj->data[ubCANLastByteOfAddr - i] = *((uint8*)pubPtr + i);
  } // end of for
} // end of CCP_vFillCANObjFromPtr()



//**************************************************************************************************
// @Function      CCP_AddressRangeInSlaveDevIdArea()
//--------------------------------------------------------------------------------------------------
// @Description   Checks if an address range belongs to the CCP Slave Device ID area.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   TRUE - the address range is in the Slave Device ID area;
//                FALSE - the address range is not in the Slave Device ID area.
//--------------------------------------------------------------------------------------------------
// @Parameters    ulAddrStart - start of the address range;
//                ulAddrEnd - end of the address range.
//**************************************************************************************************
static boolean CCP_AddressRangeInSlaveDevIdArea(const uint32 ulAddrStart,
                                                const uint32 ulAddrEnd)
{
  if (((uint32)&ubDeviceId <= ulAddrStart) && (ulAddrEnd <= ((uint32)&ubDeviceId + ubDeviceIdLen - 1U)))
  {
    return 1;
  }
  else
  {
    return 0;
  }
} // end of CCP_AddressRangeInSlaveDevIdArea()



//**************************************************************************************************
// @Function      CCP_AddressRangeInDebugArea()
//--------------------------------------------------------------------------------------------------
// @Description   Checks if an address range belongs to the CCP debug area.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   TRUE - the address range is in the debug area;
//                FALSE - the address range is not in the debug area.
//--------------------------------------------------------------------------------------------------
// @Parameters    ulAddrStart - start of the address range;
//                ulAddrEnd - end of the address range.
//**************************************************************************************************
static boolean CCP_AddressRangeInDebugArea(const uint32 ulAddrStart,
                                           const uint32 ulAddrEnd)
{
  if ((CCP_DBGMEM1_LOW_LIM <= ulAddrStart) && (ulAddrEnd <= CCP_DBGMEM1_UPP_LIM))
  {
    return 1;
  }
  else
  {
    return 0;
  }
} // end of CCP_AddressRangeInDebugArea()



//**************************************************************************************************
// @Function      CCP_AddressRangeInCalibrationArea()
//--------------------------------------------------------------------------------------------------
// @Description   Checks if an address range belongs to the CCP calibration area
//                (calibration ROM + calibration RAM).
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   TRUE - the address range is in the calibration area;
//                FALSE - the address range is not in the calibration area.
//--------------------------------------------------------------------------------------------------
// @Parameters    ulAddrStart - start of the address range;
//                ulAddrEnd - end of the address range.
//**************************************************************************************************
static boolean CCP_AddressRangeInCalibrationArea(const uint32 ulAddrStart,
                                                 const uint32 ulAddrEnd)
{
  if (((uwRPSTART <= ulAddrStart) && (ulAddrEnd <= uwRPEND))
  ||  ((uwWPSTART <= ulAddrStart) && (ulAddrEnd <= uwWPEND)))
  {
    return 1;
  }
  else
  {
    return 0;
  }
} // end of CCP_AddressRangeInCalibrationArea()



//**************************************************************************************************
//==================================================================================================
// Local (private) functions : CCP commands
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      CCP_vProcessUnknownCMD()
//--------------------------------------------------------------------------------------------------
// @Description   Sets unknown command error code in CRM. Used for reserved commands.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessUnknownCMD(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  stCANObjTXContent.data[1] = CCP_ERR_UNKNOWN_COMMAND;
} // end of CCP_vProcessUnknownCMD()



//**************************************************************************************************
// @Function      CCP_vProcessCMDConnect()
//--------------------------------------------------------------------------------------------------
// @Description   Just resets CCP monitor.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDConnect(void)
{
  if (!bSaveCalibDataRequest)
  {
    CCP_vResetCCPMonitor();
    CCP_bConnected = 1;
  }
  else
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
  }
} // end of CCP_vProcessCmdConnect()



//**************************************************************************************************
// @Function      CCP_vProcessCMDSetMTA()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDSetMTA(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  // For not to operate with pubMTAPtr0
  uint8* pubMTAPtrTmp;
  CCP_vFillPtrFromCANObj(&pubMTAPtrTmp, &stCANObjRXContent, 7u);
  // For arithmetical operations and comparisons
  uint32 uwAddress = (uint32)pubMTAPtrTmp;

  // Check received address for legal address range
  boolean addrRangeInCalibrationArea = CCP_AddressRangeInCalibrationArea(uwAddress, uwAddress);
  boolean addrRangeInDebugArea = CCP_AddressRangeInDebugArea(uwAddress, uwAddress);
  if (addrRangeInCalibrationArea || addrRangeInDebugArea)
  {
    // Address of the first byte to upload/download or calibration page
    if (0 == stCANObjRXContent.data[2]) // MTA0
    {
      CCP_vFillPtrFromCANObj((uint8**)&pubMTAPtr0, &stCANObjRXContent, 7U);
    }
    else if (1 == stCANObjRXContent.data[2]) // MTA1
    {
      CCP_vFillPtrFromCANObj((uint8**)&pubMTAPtr1, &stCANObjRXContent, 7U);
    }
    else
    {
      stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
      return;
    }

    ubMTAAddressExtension = stCANObjRXContent.data[3];
  } // end of if
  else // Address is illegal
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
  }
} // end of CCP_vProcessCMDSetMTA()



//**************************************************************************************************
// @Function      CCP_vProcessCMDDnload()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDDnload(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  if ((CCP_CMD_DNLOAD == stCANObjRXContent.data[0])
  &&  (CCP_MAX_SENT_BYTES <= stCANObjRXContent.data[2]))
  {
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
    return;
  } // end of if

  uint8 ubDataSize = stCANObjRXContent.data[2]; // for DNLOAD
  uint8 ubFirstBytePos = 3U; // for DNLOAD

  if (CCP_CMD_DNLOAD_6 == stCANObjRXContent.data[0])
  {
    ubDataSize = CCP_MAX_SENT_BYTES;
    ubFirstBytePos = 2U;
  } // end of if

  // For not to operate with pubMTAPtr0
  uint8* pubMTAPtrTmp = (uint8*)P_NULL;

  // For arithmetical operations and comparisons
  uint32 uwAddress = (uint32)pubMTAPtr0;

  if ((uwRPSTART <= uwAddress) && ((uwAddress + ubDataSize - 1U) <= uwRPEND)) // in calibration ROM
  {
    uint32 CurrSect = CalRAM_GetSectorNumber((uint8*)uwAddress);
    uint32 NextSect = CalRAM_GetSectorNumber((uint8*)(uwAddress + ubDataSize - 1U));

    // Copy sector which contains received address into RAM if it hadn't been copied before
    if (!SectID[CurrSect])
    {
      if (nCurSectCalRAM <= CR_MAX_SECT_RAM)
      {
        CalRAM_ReadSectorToRAM(CurrSect);
      }
      else
      {
        stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
      }
    } // end of if

    // Copy sector which contains end of address of data block into RAM if it has not been copied before
    if (!SectID[NextSect])
    {
      if (nCurSectCalRAM <= CR_MAX_SECT_RAM)
      {
        CalRAM_ReadSectorToRAM(NextSect);
      }
      else
      {
        stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
      }
    } // end of if

    if (stCANObjTXContent.data[1] != CCP_ERR_ACCESS_DENIED)
    {
      // Switch pointer into RAM
      uwAddress = uwWPSTART + (uwAddress - uwRPSTART) +(uint32)((uint32)SectID[CurrSect] << CR_BIN_LOG) - (uint32)((uint32)CurrSect << CR_BIN_LOG);
      pubMTAPtrTmp = (uint8*)uwAddress;
      
      uint8 ubI = 0U;
      for ( ; ubI < ubDataSize; ubI++) // write bytes that have been sent
      {
        *((uint8*)pubMTAPtrTmp) = stCANObjRXContent.data[ubI + ubFirstBytePos];
        pubMTAPtrTmp++;
      }
    } // end of if

    pubMTAPtr0 += ubDataSize;

    // Return imaginary address, in flash-WP
    CCP_vFillCANObjFromPtr(&stCANObjTXContent, &pubMTAPtr0, 7U); // address of the last downloaded byte

    stCANObjTXContent.data[3] = ubMTAAddressExtension;
  } // end of if
  else // not in calibration ROM, error: address invalid; received address in RAM is also assumed as invalid
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
  }
} // end of CCP_vProcessCMDDnload()



//**************************************************************************************************
// @Function      CCP_vProcessCMDUpload()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDUpload(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  // Check for correct parameter
  if (CCP_MAX_SENT_BYTES <= stCANObjRXContent.data[2])
  {
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
    return;
  }

  // For arithmetical operations and comparisons
  uint32 uwAddress = (uint32)pubMTAPtr0;

  // Check received addresses for legal address range
  boolean addrRangeInCalibrationArea = CCP_AddressRangeInCalibrationArea(uwAddress, uwAddress + stCANObjRXContent.data[2] - 1U);
  boolean addrRangeInDebugArea = CCP_AddressRangeInDebugArea(uwAddress, uwAddress + stCANObjRXContent.data[2] - 1U);
  boolean addrRangeInSlaveDevIdArea = CCP_AddressRangeInSlaveDevIdArea(uwAddress, uwAddress + stCANObjRXContent.data[2] - 1U);
  if (addrRangeInCalibrationArea || addrRangeInDebugArea || addrRangeInSlaveDevIdArea)
  {
    if (!CCP_bWrkPage) // Reference page active
    {
      if ((uwWPSTART <= uwAddress) && (uwAddress <= uwWPEND)) // In calibration RAM => upload with cheating
      {
        // Upload memory byte to byte into CAN object
        uint8 ubI = 0U;
        for ( ; ubI < stCANObjRXContent.data[2]; ubI++)
        {
          // Switch into ROM
          uwAddress = (uint32)pubMTAPtr0;

          // Get sector number
          uint8 CurrSect = CalRAM_GetSectorNumber((uint8*)uwAddress);

          stCANObjTXContent.data[ubI + 3U] = *((uint8*)uwAddress);
          pubMTAPtr0++;
        } // end of for
      } // end of if
      else // Not in calibration RAM
      {
        // Upload memory byte to byte into CAN object
        uint8 ubI=0;
        for (ubI = 0; ubI < stCANObjRXContent.data[2]; ubI++)
        {
            stCANObjTXContent.data[ubI + 3U] = *((uint8*)pubMTAPtr0);
            pubMTAPtr0++; // MTA0 must be incremented
        }
      }
    } // end of if
    else // Work page active
    {
      if ((uwRPSTART <= uwAddress) && (uwAddress <= uwRPEND)) // In calibration ROM => upload with cheating
      {
        // Upload memory byte to byte into CAN object
        uint8 ubI = 0U;
        for ( ; ubI < stCANObjRXContent.data[2]; ubI++)
        {
          uwAddress = (uint32)pubMTAPtr0;

          // Get sector number
          uint8 CurrSect = CalRAM_GetSectorNumber((uint8*)uwAddress);

          // Switch pointer into RAM if sector was read into RAM
          if (SectID[CurrSect])
          {
            uwAddress = uwWPSTART + (uwAddress - uwRPSTART) +
                        (uint32)((uint32)SectID[CurrSect] << CR_BIN_LOG) - (uint32)((uint32)CurrSect << CR_BIN_LOG);
          }

          stCANObjTXContent.data[ubI + 3] = *((uint8*)uwAddress);
          pubMTAPtr0++;
        } // end of for
      } // end of if
      else
      {
        // Upload memory byte to byte into CAN object
        uint8 ubI=0;
        for (ubI = 0; ubI < stCANObjRXContent.data[2]; ubI++)
        {
          stCANObjTXContent.data[ubI + 3U] = *((uint8*)pubMTAPtr0);
          pubMTAPtr0++; // MTA0 must be incremented
        }
      }
    } // end of else*/
  } // end of if
  else // Address is illegal
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
  }
} // end of CCP_vProcessCMDUpload()



//**************************************************************************************************
// @Function      CCP_vProcessCMDTest()
//--------------------------------------------------------------------------------------------------
// @Description   Command Test is reserved. Sets unknown command error code in CRM.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDTest(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
      return;
  }
  if(stCANObjRXContent.data[2]!=0)
  {
      stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
      return;
  }

  // todo: FLASH operations removed
  // DFlash(0,0,0);
  // Software_reset();
} // end of CCP_vProcessCMDTest()



//**************************************************************************************************
// @Function      CCP_vProcessCMDStartStop()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDStartStop(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  if ((stCANObjRXContent.data[2] < 3) // can be 0, 1 or 2
      || (stCANObjRXContent.data[3] < CCP_DAQ_LIST_MAX_NUM)
      || (stCANObjRXContent.data[4] < CCP_DAQ_LIST_SIZE))
  {
    stDAQ_LIST_PARAM * pstThisDAQList = DAQLists + stCANObjRXContent.data[3];

    pstThisDAQList->ubDAQLastODTNum = stCANObjRXContent.data[4];
    pstThisDAQList->ubDAQEventChannel = stCANObjRXContent.data[5];
    pstThisDAQList->usDAQRatePrescaler = stCANObjRXContent.data[6]; // most byte
    pstThisDAQList->usDAQRatePrescaler = (uint16)(pstThisDAQList->usDAQRatePrescaler << 8) +
                                         stCANObjRXContent.data[7]; // least byte
    pstThisDAQList->usDAQRatePrescalerCtr = 1U; // Start counting from 1

    switch (stCANObjRXContent.data[2])
    {
      case 2: // prepare
        pstThisDAQList->blPrepared = 1;
        break;

      case 1: // start
        if (pstThisDAQList->ODTs[0][0].pubAddr!=NULL)
        {pstThisDAQList->blDAQIsRunning = 1;}
        break;

      case 0: // stop
        pstThisDAQList->blDAQIsRunning = 0;
        break;

      default: // it does not need, the checking has already been
        stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
        break;
    } // end of switch
  }
  else // error
  {
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
  }
} // end of CCP_vProcessCMDStartStop()



//**************************************************************************************************
// @Function      CCP_vProcessCMDDisconnect()
//--------------------------------------------------------------------------------------------------
// @Description   Resets CCP Monitor.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDDisconnect(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  if (!bSaveCalibDataRequest)
  {
    CCP_vResetCCPMonitor();
    CCP_bDisconnectRequest = 1;
  }
  else
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
  }
} // end of CCP_vProcessCMDDisconnect()



//**************************************************************************************************
// @Function      CCP_vProcessCMDStartStopAll()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDStartStopAll(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
      return;
  }

  uint8 ubListIdx = 0U;
  stDAQ_LIST_PARAM * pstThisDAQList = DAQLists + ubListIdx;

  switch (stCANObjRXContent.data[2])
  {
    case 0: // Stop all
      for ( ; ubListIdx < CCP_DAQ_LIST_MAX_NUM; ubListIdx++)
      {
          if (pstThisDAQList->blDAQIsRunning) // If the list is started,
          {
              pstThisDAQList->blDAQIsRunning = 0; // stop it
          }
          pstThisDAQList++;
      }
      break;

    case 1: // start prepared
      for ( ; ubListIdx < CCP_DAQ_LIST_MAX_NUM; ubListIdx++)
      {
          if (pstThisDAQList->blPrepared) // If the list is prepared,
          {
              pstThisDAQList->blDAQIsRunning = 1; // start it
              pstThisDAQList->blPrepared = 0; // switch flag off
          } // end of if
          pstThisDAQList++;
      }
      break;

    default: // other - error
      stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
      break;
  } // end of switch
} // end of CCP_vProcessCMDStartStopAll()



//**************************************************************************************************
// @Function      CCP_vProcessCMDGetActiveCalPage()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDGetActiveCalPage(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }
    
  CCP_vFillCANObjFromPtr(&stCANObjTXContent, &pubCalPageAddr, 7U);
  stCANObjTXContent.data[3] = ubMTAAddressExtension;

} // end of CCP_vProcessCMDGetActiveCalPage()



//**************************************************************************************************
// @Function      CCP_vProcessCMDSetSStatus()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDSetSStatus(void)
{
  // Handle command only if connected
    if (!CCP_bConnected)
  {
    return;
  }

  CANSessionStatus.REG = stCANObjRXContent.data[2];

  if (CANSessionStatus.B.bRESUME)
  {
    CANSessionStatus.B.bRESUME = 0;
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
  } // end of if

  if (CANSessionStatus.B.bSTORE)
  {
    bSaveCalibDataRequest = 1;
    osCOPYWPTORP=1;
  } // end of if
} // end of CCP_vProcessCMDSetSStatus()



//**************************************************************************************************
// @Function      CCP_vProcessCMDGetSStatus()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDGetSStatus(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  stCANObjTXContent.data[3] = CANSessionStatus.REG;
  // data bytes in CAN object are already = 0 at the start of the switch
} // end of CCP_vProcessCMDGetSStatus()



//**************************************************************************************************
// @Function      CCP_vProcessCMDBuildChksum()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************

static void CCP_vProcessCMDBuildChksum(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  uint32 uwCheckSum32 = 0U; // Stores result of checksum
  uint32 uwCheckSumBytesNum = 0U; // Size (number of bytes) of memory block for which checksum
                                  // must be calculated

  // For not to operate with pubMTAPtr0
  uint8* pubMTAPtrTmp = (uint8*)P_NULL;

  uint32 uwAddress = 0U; // For arithmetical operations and comparisons
  CCP_vFillPtrFromCANObj((uint8**)&uwCheckSumBytesNum,
                         &stCANObjRXContent,
                         CCP_LAST_BYTE_OF_SIZE_MOVE);

  if (CCP_bWrkPage) // Work page active
  {
    uint32 uwI = 0U;
    for( ; uwI < uwCheckSumBytesNum; uwI++)
    {
      uwAddress = (uint32)pubMTAPtr0;

      uint16 CurrSect = CalRAM_GetSectorNumber((uint8*)uwAddress); // Get sector number

      if (SectID[CurrSect]) // Switch pointer into RAM if sector was read into RAM
      {
        uwAddress = uwWPSTART + uwAddress - uwRPSTART +
                    (uint32)((uint32)SectID[CurrSect] << CR_BIN_LOG) - (uint32)((uint32)CurrSect << CR_BIN_LOG);
      }

      pubMTAPtrTmp = (uint8*)uwAddress;

      if(Inca_Type) // INCA v.5.4 through ETAS PCMCIA
      {
        uwCheckSum32 += (uint32)(*((uint8*)pubMTAPtrTmp) << 8); // 1st is a MSB, 2nd- LSB
        pubMTAPtrTmp++;
        pubMTAPtr0++;
        uwI++;
      }

      uwCheckSum32 += *((uint8*)pubMTAPtrTmp);

      pubMTAPtr0++;
    } // end of for
  } // end of if
  else // Reference page active
  {
    uint32 uwI = 0;
    for (uwI = 0; uwI < uwCheckSumBytesNum; uwI++)
    {
      if(Inca_Type) // INCA v.5.4 through ETAS PCMCIA
      {
        uwCheckSum32 += (uint32)(*((uint8*)pubMTAPtr0) << 8); // 1st is a MSB, 2nd- LSB
        pubMTAPtr0++;
        uwI++;
      } // ETAS_PCMCIA_INCA54

      uwCheckSum32 += *((uint8*)pubMTAPtr0);
      pubMTAPtr0++;
    } // end of for
  } // end of else

  stCANObjTXContent.data[3] = CCP_CHKSUM_SIZE;

  CCP_vFillCANObjFromPtr(&stCANObjTXContent, (uint8**)&uwCheckSum32, 7U); // fill last 4 bytes
  // Move the last 2 bytes, witch have to be returned as check sum

  stCANObjTXContent.data[4] = stCANObjTXContent.data[6]; // the next to last byte
  stCANObjTXContent.data[5] = stCANObjTXContent.data[7]; // the last byte
} // end of CCP_vProcessCMDBuildChksum()





//**************************************************************************************************
// @Function      CCP_vProcessCMDShortUp()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDShortUp(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  // Check for correct parameter
  if (CCP_MAX_SENT_BYTES <= stCANObjRXContent.data[2])
  {
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
    return;
  }

  // For not to operate with pubMTAPtr0
  uint8* pubMTAPtrTmp;
  CCP_vFillPtrFromCANObj(&pubMTAPtrTmp, &stCANObjRXContent, 7U); // Address of the first byte to upload

  // For arithmetical operations and comparisons
  uint32 uwAddress = (uint32)pubMTAPtrTmp;

  // Check received addresses for legal address range
  boolean addrRangeInCalibrationArea = CCP_AddressRangeInCalibrationArea(uwAddress, uwAddress + stCANObjRXContent.data[2] - 1U);
  boolean addrRangeInDebugArea = CCP_AddressRangeInDebugArea(uwAddress, uwAddress + stCANObjRXContent.data[2] - 1U);
  boolean addrRangeInSlaveDevIdArea = CCP_AddressRangeInSlaveDevIdArea(uwAddress, uwAddress + stCANObjRXContent.data[2] - 1U);
  if (addrRangeInCalibrationArea || addrRangeInDebugArea || addrRangeInSlaveDevIdArea)
  {
    if (!CCP_bWrkPage) // Reference page active
    {
      #ifdef ELCAR_USB
      if ((uwWPSTART <= uwAddress) && (uwAddress <= uwWPEND)) // In calibration RAM => upload with cheating
      {
        // Upload memory byte to byte into CAN object
        uint8 ubI = 0U;
        for ( ; ubI < stCANObjRXContent.data[2]; ubI++)
        {
          // Switch into ROM
          uwAddress = ((uint32)pubMTAPtrTmp - uwWPSTART) + uwRPSTART;

          // Get sector number
          uint8 CurrSect = CalRAM_GetSectorNumber((uint8*)uwAddress);

          // Switch pointer into RAM if sector was read into RAM
          if (SectID[CurrSect])
          {
            uwAddress = uwWPSTART + (uwAddress - uwRPSTART) +
                        (uint32)((uint32)SectID[CurrSect] << CR_BIN_LOG) - (uint32)((uint32)CurrSect << CR_BIN_LOG);
          }

          pubMTAPtrTmp = (uint8*)uwAddress;
          stCANObjTXContent.data[ubI + 3U] = *((uint8*)(pubMTAPtrTmp + ubI));
        } // end of for
      } // end of if
      else // Not in calibration RAM
      {
      #endif // ELCAR_USB
        // Upload memory byte to byte into CAN object
        uint8 ubI=0;
        for (ubI = 0; ubI < stCANObjRXContent.data[2]; ubI++)
        {
          stCANObjTXContent.data[ubI + 3U] = *((uint8*)(pubMTAPtrTmp + ubI));
        }
      #ifdef ELCAR_USB
      }
      #endif // ELCAR_USB
    } // end of if
    else // Work page active
    {
      #ifndef ELCAR_USB // not ELCAR USB
      if ((uwRPSTART <= uwAddress) && (uwAddress <= uwRPEND)) // In calibration ROM => upload with cheating
      {
        // Upload memory byte to byte into CAN object
        uint8 ubI = 0U;
        for ( ; ubI < stCANObjRXContent.data[2]; ubI++)
        {
          uwAddress = (uint32)pubMTAPtrTmp;

          // Get sector number
          uint8 CurrSect = CalRAM_GetSectorNumber((uint8*)uwAddress);

          // Switch pointer into RAM if sector was read into RAM
          if (SectID[CurrSect])
          {
            uwAddress = uwWPSTART + (uwAddress - uwRPSTART) +
                        (uint32)((uint32)SectID[CurrSect] << CR_BIN_LOG) - (uint32)((uint32)CurrSect << CR_BIN_LOG);
          }

          pubMTAPtrTmp = (uint8*)uwAddress;
          stCANObjTXContent.data[ubI + 3U] = *((uint8*)(pubMTAPtrTmp + ubI));
        } // end of for
      } // end of if
      else // Not in calibration ROM
      {
      #endif // #ifndef ELCAR_USB
        // Upload memory byte to byte into CAN object
        uint8 ubI=0;
        for (ubI = 0; ubI < stCANObjRXContent.data[2]; ubI++)
        {
          stCANObjTXContent.data[ubI + 3U] = *((uint8*)(pubMTAPtrTmp + ubI));
        }
      #ifndef ELCAR_USB // not ELCAR USB
      }
      #endif // #ifndef ELCAR_USB
    }
  } // end of if
  else // Address is illegal
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
  } // end of else
} // end of CCP_vProcessCMDShortUp()



//**************************************************************************************************
// @Function      CCP_vProcessCMDClearMemory()
//--------------------------------------------------------------------------------------------------
// @Description   Command ClearMemory is reserved. Sets unknown command error code in CRM.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDClearMemory(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
      return;
  }

  stCANObjTXContent.data[1] = CCP_ERR_UNKNOWN_COMMAND;
} // end of CCP_vProcessCMDClearMemory()



//**************************************************************************************************
// @Function      CCP_vProcessCMDSelectCalPage()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDSelectCalPage(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  if (stCANObjRXContent.data[2]==1)
  {
    CCP_bWrkPage = 1;
    pubMTAPtr0 = (uint8*)uwWPSTART;
    // Change the global active page flag only if the calibration is active
    if (CCP_bCalibration)
    {
      bWrkPage = 1;
    }
  }
  else
  {
    if (pubMTAPtr0 == (uint8*)uwRPSTART) // ROM start address
    {
      CCP_bWrkPage = 0;

      // Change the global active page flag only if the calibration is active
      if (CCP_bCalibration)
      {
        bWrkPage = 0;
      }
    }
    else // no ROM start address
    {
      if (pubMTAPtr0 == (uint8*)uwWPSTART) // RAM start address
      {
        CCP_bWrkPage = 1;

        // Change the global active page flag only if the calibration is active
        if (CCP_bCalibration)
        {
          bWrkPage = 1;
        }
      } // end of if
      else // Error address
      {
        stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
        return;
      } // end of else
    } // end of else
  }
  
  pubCalPageAddr = pubMTAPtr0;
} // end of CCP_vProcessCMDSelectCalPage()



//**************************************************************************************************
// @Function      CCP_vProcessCMDGetSeed()
//--------------------------------------------------------------------------------------------------
// @Description   Command GetSeed is reserved. Sets unknown command error code in CRM.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDGetSeed(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }
  if(stCANObjRXContent.data[2]!=0)
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
    return;
  }

  stCANObjTXContent.data[1] = 0x02; //USER CODE
} // end of CCP_vProcessCMDGetSeed()



//**************************************************************************************************
// @Function      CCP_vProcessCMDUnlock()
//--------------------------------------------------------------------------------------------------
// @Description   Command Unlock is reserved. Sets unknown command error code in CRM.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDUnlock(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  stCANObjTXContent.data[1] = CCP_ERR_UNKNOWN_COMMAND;
} // end of CCP_vProcessCMDUnlock()



//**************************************************************************************************
// @Function      CCP_vProcessCMDGetDAQSize()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDGetDAQSize(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  if (stCANObjRXContent.data[2] < CCP_DAQ_LIST_MAX_NUM)
  {
    stDAQ_LIST_PARAM * pstThisDAQList = DAQLists + stCANObjRXContent.data[2];
    stCANObjTXContent.data[3] = CCP_DAQ_LIST_SIZE;  // number of ODTs in the list
    CCP_vFillPtrFromCANObj((uint8**)&(pstThisDAQList->uwDAQCANID), &stCANObjRXContent, 7U); // take ID to global var
    stCANObjTXContent.data[4] = stCANObjRXContent.data[2] * CCP_DAQ_LIST_SIZE;  // 1st ODT PID of the list

    // Prepare the new process resetting the list and the MO
    pstThisDAQList->blDAQIsRunning = 0; // stop current DAQ process

    // Assign a new CAN Identifier to the requested DAQ list
    pstThisDAQList->ubCANMO = DAQListsConsts[stCANObjRXContent.data[2]].ubCANMO;
    CAN_vSetTransmitMsgObjStdID(pstThisDAQList->ubCANMO, pstThisDAQList->uwDAQCANID);
  } // end of if
  else // other DAQ lists not available
  {
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
  } // end of else
} // end of CCP_vProcessCMDGetDAQSize()



//**************************************************************************************************
// @Function      CCP_vProcessCMDSetDAQPtr()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDSetDAQPtr(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  if ((stCANObjRXContent.data[2] < CCP_DAQ_LIST_MAX_NUM)
  ||  (stCANObjRXContent.data[3] < CCP_DAQ_LIST_SIZE)
  ||  (stCANObjRXContent.data[4] < CCP_ODT_SIZE))
  {
    ubDAQListIdx = stCANObjRXContent.data[2];
    ubDAQODTIdx  = stCANObjRXContent.data[3];
    ubDAQElemIdx = stCANObjRXContent.data[4];
  } // end of if
  else
  {
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
  } // end of else
} // end of CCP_vProcessCMDSetDAQPtr()



//**************************************************************************************************
// @Function      CCP_vProcessCMDWriteDAQ()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDWriteDAQ(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  if (4 < stCANObjRXContent.data[2]) // can be 1, 2 or 4
  {
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
    return;
  }

  // Get address of DAQ element
  uint8* pubDAQElemPtrTmp;
  CCP_vFillPtrFromCANObj(&pubDAQElemPtrTmp, &stCANObjRXContent, 7U);
  uint32 ulAddress = (uint32)pubDAQElemPtrTmp; // For arithmetical operations and comparisons

  // Check received addresses for legal address range
  boolean addrRangeInCalibrationArea = CCP_AddressRangeInCalibrationArea(ulAddress, ulAddress + stCANObjRXContent.data[2] - 1U);
  boolean addrRangeInDebugArea = CCP_AddressRangeInDebugArea(ulAddress, ulAddress + stCANObjRXContent.data[2] - 1U);
  
  if (addrRangeInCalibrationArea || addrRangeInDebugArea)
  {
    stDAQ_ODT_Element_type * pstDAQ_ODT_ThisElement =
    *((DAQLists + ubDAQListIdx)->ODTs + ubDAQODTIdx) + ubDAQElemIdx;
    CCP_vFillPtrFromCANObj((uint8**)&(pstDAQ_ODT_ThisElement->pubAddr), &stCANObjRXContent, 7U);
    pstDAQ_ODT_ThisElement->ubSize = stCANObjRXContent.data[2];
    pstDAQ_ODT_ThisElement->ubAddrExt = stCANObjRXContent.data[3];
  }
  else // Address is illegal
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
  }
} // end of CCP_vProcessCMDWriteDAQ()



//**************************************************************************************************
// @Function      CCP_vProcessCMDExchangeID()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDExchangeID(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  stCANObjTXContent.data[3] = ubDeviceIdLen;
  stCANObjTXContent.data[4] = CCP_SLAVE_DEV_ID_TYPE;
  stCANObjTXContent.data[5] = ubResAvMsk;
  stCANObjTXContent.data[6] = CCP_RES_PROT_MSK_VAL;

  Inca_Type=1; //set inca type =7.2
  // Set the MTA0 to the location from which the CCP master may
  // subsequently upload the requested ID using UPLOAD
  pubMTAPtr0 = (uint8*)ubDeviceId;
} // end of CCP_vProcessCMDExchangeID()



//**************************************************************************************************
// @Function      CCP_vProcessCMDProgram()
//--------------------------------------------------------------------------------------------------
// @Description   Command Program is reserved. Sets unknown command error code in CRM.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDProgram(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  stCANObjTXContent.data[1] = CCP_ERR_UNKNOWN_COMMAND;
} // end of CCP_vProcessCMDProgram()



//**************************************************************************************************
// @Function      CCP_vProcessCMDMove()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDMove(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  if ((pubMTAPtr0 == (uint8*)uwRPSTART) && (pubMTAPtr1 == (uint8*)uwWPSTART))
  {
    CalRAM_Init(); // Clean array without writing into RAM
  }
  else // It's not allowed to do other variants of copying except copy whole RP into WP
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
  }
} // end of CCP_vProcessCMDMove()



//**************************************************************************************************
// @Function      CCP_vProcessCMDGetCCPVersion()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDGetCCPVersion(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  stCANObjTXContent.data[3] = CCP_MAIN_VER_IMPL;
  stCANObjTXContent.data[4] = CCP_RELEASE_VER_IMPL;
} // end of CCP_vProcessCMDGetCCPVersion()



//**************************************************************************************************
// @Function      CCP_vProcessCMDDiagService()
//--------------------------------------------------------------------------------------------------
// @Description   Command DiagService is reserved. Sets unknown command error code in CRM.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDDiagService(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }
  if(stCANObjRXContent.data[2]!=0)
  {
    stCANObjTXContent.data[1] = CCP_ERR_ACCESS_DENIED;
    return;
  }
  
  // todo: FLASH operations removed
  // DFlash(0,0x5588,0);
} // end of CCP_vProcessCMDDiagService()



//**************************************************************************************************
// @Function      CCP_vProcessCMDActionService()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDActionService(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  uint16 serviceNum = (uint16)((uint16)stCANObjRXContent.data[3] << 8) |
                      stCANObjRXContent.data[2];
  if (CCP_ACT_SRV_CALIBRATION == serviceNum)
  {
    uint8 calibration = stCANObjRXContent.data[4];
    switch (calibration)
    {
      case ON:
        CCP_bCalibration = 1;
        break;

      case OFF:
        CCP_bCalibration = 0;
        break;

      default:
        // Unsupported parameter value
        stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
        break;
    } // end of switch
  }
  else // unsupported action service
  {
    stCANObjTXContent.data[1] = CCP_ERR_PARAM_OUT_RANGE;
  }
} // end of CCP_vProcessCMDActionService()



//**************************************************************************************************
// @Function      CCP_vProcessCMDProgram6()
//--------------------------------------------------------------------------------------------------
// @Description   Command Program6 is reserved. Sets unknown command error code in CRM.
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDProgram6(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  stCANObjTXContent.data[1] = CCP_ERR_UNKNOWN_COMMAND;
} // end of CCP_vProcessCMDProgram6()



//**************************************************************************************************
// @Function      CCP_vProcessCMDDnload6()
//--------------------------------------------------------------------------------------------------
// @Description
//--------------------------------------------------------------------------------------------------
// @Notes         This function is processor-independent.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
static void CCP_vProcessCMDDnload6(void)
{
  // Handle command only if connected
  if (!CCP_bConnected)
  {
    return;
  }

  CCP_vProcessCMDDnload();
} // end of CCP_vProcessCMDDnload6()



//****************************************** end of file *******************************************
