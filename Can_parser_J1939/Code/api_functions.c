/*
 * -----------------------------------------------------------------------------
 * File Name    : api_functions.c
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

/* Includes ------------------------------------------------------------------*/

#include "model.h"

/* Definitions of global (public) variables ----------------------------------*/

float_t *ptrPositionVar_data;
float_t *ptrVar_data;
float_t *ptrVar1_data;
float_t *ptrSize_data;
uint32_t *ptrCollor_data;
uint32_t *ptrMapCollor_data;
uint32_t *ptrColorChange_data;
float_t Factor_data = 0.0F;
uint32_t Alpha_data = 0U;
uint32_t Red_data = 0U;
uint32_t Green_data = 0U;
uint32_t Blue_data = 0U;
float_t *PictPosMenuLvl_0_data;
int8_t *ptrBusDoorI_data;
float_t *ptrBusDoorH_data;
float_t *ptrScaleVar_data;
float_t *ptrScaleState_data;
uint8_t *Buffer_data;
uint8_t Index_data = 0U;
uint64_t Result_data = 0UL;
uint8_t *BufferSPNandFMI_data;
int8_t TestSendCAN_data = 0;
int8_t TestSendCAN1_data = 1;
int8_t TestSendCAN2_data = 0;
int8_t TestSendCAN3_data = 1;

/* Definitions of local (private) data types ---------------------------------*/

/* Definitions of local (private) constants ----------------------------------*/

/* Definitions of static global (private) variables --------------------------*/

/* Declarations of local (private) functions ---------------------------------*/

/* Definitions of global (public) functions ----------------------------------*/

double_t LinearScale(double_t argIn0, double_t argIn1, double_t argIn2, double_t argIn3, double_t argIn4)
{

    double_t argOut0 = 1;

    double_t Subtract_3A93B5B1;

    double_t Subtract_507D55B3;

    double_t Subtract_3FC81F03;

    double_t Divide_BBE5D394;

    double_t Multiply_09166A7A;

    double_t Max_E328E2B0;

    double_t Min_129354C6;

    double_t Saturation_37029211;

    Subtract_3A93B5B1 = ((double_t)((argIn0) - (argIn1)));

    Subtract_507D55B3 = ((double_t)((argIn4) - (argIn3)));

    Subtract_3FC81F03 = ((double_t)((argIn2) - (argIn1)));

    Divide_BBE5D394 = (double_t)(Subtract_507D55B3 / Subtract_3FC81F03);

    Multiply_09166A7A = (double_t)(Subtract_3A93B5B1 * Divide_BBE5D394);

    Max_E328E2B0 = (argIn4);

    if((argIn3) > Max_E328E2B0)

    {

        Max_E328E2B0 = (argIn3);

    }

    Min_129354C6 = (argIn4);

    if((argIn3) < Min_129354C6)

    {

        Min_129354C6 = (argIn3);

    }

    Saturation_37029211 = (((double_t)(Multiply_09166A7A + (argIn3))));

    if(Saturation_37029211 < Min_129354C6)

    {

        Saturation_37029211 = Min_129354C6;

    }

    else if(Saturation_37029211 > Max_E328E2B0)

    {

        Saturation_37029211 = Max_E328E2B0;

    }

    else

    {

        /* This code block intentionally left blank */

    }

    argOut0 = Saturation_37029211;

    return argOut0;

}

void LerpPtr_200ms(void *param0, float_t argIn0)
{

    ptrPositionVar_data = (float_t*) param0;

    *ptrPositionVar_data = (Lerp((*ptrPositionVar_data), (argIn0), ((int32_t) 200)));

}

void AlphaGradientLimitter(void *param0, double_t argIn0, int32_t argIn1)
{

    float_t Divide_6628E0BD;

    float_t Direct_Switch_C1B3E6B8;

    float_t Saturation_71CE1D94;

    ptrVar_data = (float_t*) param0;

    Divide_6628E0BD = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) (argIn1));

    if(0 == (((argIn0) != ((double_t) ((int8_t) 0)) )? 1 : 0))

    {

        Direct_Switch_C1B3E6B8 = ((float_t)(Divide_6628E0BD * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_C1B3E6B8 = Divide_6628E0BD;

    }

    Saturation_71CE1D94 = (((float_t)(Direct_Switch_C1B3E6B8 + (*ptrVar_data))));

    if(Saturation_71CE1D94 < ((float_t) 0.0F))

    {

        Saturation_71CE1D94 = ((float_t) 0.0F);

    }

    else if(Saturation_71CE1D94 > ((float_t) 1.0F))

    {

        Saturation_71CE1D94 = ((float_t) 1.0F);

    }

    else

    {

        /* This code block intentionally left blank */

    }

    *ptrVar_data = Saturation_71CE1D94;

}

float_t Lerp(float_t argIn0, float_t argIn1, int32_t argIn2)
{

    float_t argOut0 = 1;

    float_t Divide_960C6A30;

    float_t Subtract_C6AFD7AA;

    float_t Multiply_D97D6396;

    Divide_960C6A30 = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) (argIn2));

    Subtract_C6AFD7AA = ((float_t)((argIn1) - (argIn0)));

    Multiply_D97D6396 = (float_t)(Subtract_C6AFD7AA * Divide_960C6A30);

    argOut0 = (((float_t)((argIn0) + Multiply_D97D6396)));

    return argOut0;

}

int32_t If_1(int32_t argIn0)
{

    int32_t argOut0 = 1;

    argOut0 = (((argIn0) == ((int32_t) 1) )? 1 : 0);

    return argOut0;

}

void AlphaGradientLimitter250ms(void *param0, uint8_t argIn0)
{

    float_t Divide_DF0BF2E5;

    uint32_t Compare_775376C6;

    int8_t Or_5FE469FA;

    int8_t Not_8639A2D2;

    float_t Direct_Switch_B58F48FC;

    float_t Saturation_51662AE9;

    ptrVar1_data = (float_t*) param0;

    Divide_DF0BF2E5 = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) ((int32_t) 250));

    Compare_775376C6 = ((argIn0) != ((uint8_t) ((uint32_t) 0U)) )? 1U : 0U;

    Or_5FE469FA = ((0U != Compare_775376C6) || (0 != (IgnitionStartPict_GUI_data))) ? 1 : 0;

    Not_8639A2D2 = (0 == (IgnitionStartVideo_GUI_data) )? 1 : 0;

    if(0 == (((0 != Or_5FE469FA) && (0 != Not_8639A2D2)) ? 1 : 0))

    {

        Direct_Switch_B58F48FC = ((float_t)(Divide_DF0BF2E5 * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_B58F48FC = Divide_DF0BF2E5;

    }

    Saturation_51662AE9 = (((float_t)(Direct_Switch_B58F48FC + (*ptrVar1_data))));

    if(Saturation_51662AE9 < ((float_t) 0.0F))

    {

        Saturation_51662AE9 = ((float_t) 0.0F);

    }

    else if(Saturation_51662AE9 > ((float_t) 1.0F))

    {

        Saturation_51662AE9 = ((float_t) 1.0F);

    }

    else

    {

        /* This code block intentionally left blank */

    }

    *ptrVar1_data = Saturation_51662AE9;

}

void SizeNumbers(void *param0, double_t argIn0)
{

    float_t Divide_097EF568;

    float_t Direct_Switch_22495BE0;

    float_t Saturation_99B12930;

    ptrSize_data = (float_t*) param0;

    Divide_097EF568 = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) ((int32_t) 15));

    if(0 == (((argIn0) != ((double_t) ((int8_t) 0)) )? 1 : 0))

    {

        Direct_Switch_22495BE0 = ((float_t)(Divide_097EF568 * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_22495BE0 = Divide_097EF568;

    }

    Saturation_99B12930 = (((float_t)(Direct_Switch_22495BE0 + (*ptrSize_data))));

    if(Saturation_99B12930 < ((float_t) 34.0F))

    {

        Saturation_99B12930 = ((float_t) 34.0F);

    }

    else if(Saturation_99B12930 > ((float_t) 50.0F))

    {

        Saturation_99B12930 = ((float_t) 50.0F);

    }

    else

    {

        /* This code block intentionally left blank */

    }

    *ptrSize_data = Saturation_99B12930;

}

int32_t If_0(int32_t argIn0)
{

    int32_t argOut0 = 1;

    argOut0 = (((argIn0) == ((int32_t) 0) )? 1 : 0);

    return argOut0;

}

void BrightenessColorLimitter(void *param0, uint32_t argIn0, int32_t argIn1)
{

    float_t Divide_D9AECF01;

    uint32_t Multiply_A3457E23;

    int32_t Direct_Switch_77A53457;

    uint32_t And_C6FFBC3D;

    uint32_t Saturation_FE665159;

    uint32_t Shift____42516B68;

    uint32_t Shift____76BE6703;

    uint32_t Or_F99CE49D;

    uint32_t Shift____764A2FF9;

    uint32_t Or_77CD477B;

    ptrCollor_data = (uint32_t*) param0;

    Divide_D9AECF01 = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) (argIn1));

    Multiply_A3457E23 = (uint32_t)(Divide_D9AECF01 * ((float_t) 255.0F));

    if(0 == (((argIn0) != ((uint32_t) ((int8_t) 0)) )? 1 : 0))

    {

        Direct_Switch_77A53457 = ((int32_t)(((float_t) Multiply_A3457E23) * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_77A53457 = (((int32_t) Multiply_A3457E23));

    }

    And_C6FFBC3D = ((uint32_t) ((*ptrCollor_data) & ((uint32_t) 255U)));

    Saturation_FE665159 = (((uint32_t)(((uint32_t) Direct_Switch_77A53457) + And_C6FFBC3D)));

    if(Saturation_FE665159 < ((uint32_t) 0U))

    {

        Saturation_FE665159 = ((uint32_t) 0U);

    }

    else if(Saturation_FE665159 > ((uint32_t) 255U))

    {

        Saturation_FE665159 = ((uint32_t) 255U);

    }

    else

    {

        /* This code block intentionally left blank */

    }

    Shift____42516B68 = ((uint32_t) (Saturation_FE665159 << ((uint32_t) 0U)));

    Shift____76BE6703 = ((uint32_t) (Saturation_FE665159 << ((uint32_t) 8U)));

    Or_F99CE49D = ((uint32_t) (Shift____42516B68 | Shift____76BE6703));

    Shift____764A2FF9 = ((uint32_t) (Saturation_FE665159 << ((uint32_t) 16U)));

    Or_77CD477B = ((uint32_t) (Or_F99CE49D | Shift____764A2FF9));

    *ptrCollor_data = (((uint32_t) (Or_77CD477B | ((uint32_t) 4278190080U))));

}

void MapColor(void *param0, uint32_t argIn0, uint32_t argIn1, int32_t argIn2)
{

    float_t Divide_8B73BDC6;

    uint32_t Multiply_4A0F3BA2;

    uint32_t And_7C2D98F9;

    uint32_t And_B3376739;

    int32_t Direct_Switch_FD8CB7C5;

    uint32_t Shift____8E42C4F3;

    int32_t Saturation_36E5FA3D;

    uint32_t And_7576BE65;

    uint32_t And_971DF7A2;

    uint32_t And_C1970011;

    int32_t Compare_2E82C91A;

    uint32_t Direct_Switch_FFDB2322;

    uint32_t Shift____3C4B583E;

    uint32_t And_C5037235;

    float_t Divide_EA817EB2;

    uint32_t Multiply_805ADFBE;

    uint32_t And_FB6E2A60;

    uint32_t And_17E7BB31;

    int32_t Direct_Switch_43ADB09B;

    int32_t Saturation_70D623F9;

    uint32_t And_D683C11F;

    uint32_t And_96F86F50;

    int32_t Compare_31582744;

    uint32_t Direct_Switch_729759EA;

    uint32_t And_D3CE9607;

    uint32_t Or_A2C6BD7F;

    float_t Divide_9F596FD9;

    uint32_t Multiply_05F0B6D3;

    uint32_t And_6966E525;

    uint32_t And_9BF591E2;

    int32_t Direct_Switch_D70D7314;

    uint32_t Shift____6DACCA3A;

    int32_t Saturation_B9326894;

    uint32_t And_FE9120AB;

    uint32_t And_7B3E55DE;

    uint32_t And_BEF91232;

    int32_t Compare_912B4B57;

    uint32_t Direct_Switch_01C1C617;

    uint32_t Shift____B4819AED;

    uint32_t And_DD401375;

    uint32_t Or_5B611976;

    float_t Divide_2CFA492C;

    uint32_t Multiply_2F2AEBD4;

    uint32_t And_26A52271;

    uint32_t And_92F33B72;

    int32_t Direct_Switch_9819A3E8;

    uint32_t Shift____ED7F12EE;

    int32_t Saturation_B2433C1C;

    uint32_t And_37FC0A6C;

    uint32_t And_59667513;

    uint32_t And_61960BFC;

    int32_t Compare_A1722F24;

    uint32_t Direct_Switch_FA91CD58;

    uint32_t Shift____64C406EB;

    uint32_t And_68D2C473;

    ptrMapCollor_data = (uint32_t*) param0;

    Divide_8B73BDC6 = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) (argIn2));

    Multiply_4A0F3BA2 = (uint32_t)(Divide_8B73BDC6 * ((float_t) 255.0F));

    And_7C2D98F9 = ((uint32_t) ((argIn1) & ((uint32_t) 65280U)));

    And_B3376739 = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 65280U)));

    if(0 == ((And_7C2D98F9 > And_B3376739 )? 1 : 0))

    {

        Direct_Switch_FD8CB7C5 = ((int32_t)(((float_t) Multiply_4A0F3BA2) * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_FD8CB7C5 = (((int32_t) Multiply_4A0F3BA2));

    }

    Shift____8E42C4F3 = ((uint32_t) (And_B3376739 >> ((uint32_t) 8U)));

    Saturation_36E5FA3D = (((int32_t)(Direct_Switch_FD8CB7C5 + ((int32_t) Shift____8E42C4F3))));

    if(Saturation_36E5FA3D < (((int32_t) ((uint32_t) 0U))))

    {

        Saturation_36E5FA3D = (((int32_t) ((uint32_t) 0U)));

    }

    else if(Saturation_36E5FA3D > (((int32_t) ((uint32_t) 255U))))

    {

        Saturation_36E5FA3D = (((int32_t) ((uint32_t) 255U)));

    }

    else

    {

        /* This code block intentionally left blank */

    }

    And_7576BE65 = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 65280U)));

    And_971DF7A2 = ((uint32_t) ((argIn1) & ((uint32_t) 65280U)));

    And_C1970011 = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 65280U)));

    Compare_2E82C91A = (And_971DF7A2 != And_C1970011 )? 1 : 0;

    if(0U == (((0U != (argIn0)) && (0 != Compare_2E82C91A)) ? 1U : 0U))

    {

        Direct_Switch_FFDB2322 = (((uint32_t) (And_7576BE65 >> ((uint32_t) 8U))));

    }

    else

    {

        Direct_Switch_FFDB2322 = (((uint32_t) Saturation_36E5FA3D));

    }

    Shift____3C4B583E = ((uint32_t) (Direct_Switch_FFDB2322 << ((uint32_t) 8U)));

    And_C5037235 = ((uint32_t) (Shift____3C4B583E & ((uint32_t) 65280U)));

    Divide_EA817EB2 = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) (argIn2));

    Multiply_805ADFBE = (uint32_t)(Divide_EA817EB2 * ((float_t) 255.0F));

    And_FB6E2A60 = ((uint32_t) ((argIn1) & ((uint32_t) 255U)));

    And_17E7BB31 = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 255U)));

    if(0 == ((And_FB6E2A60 > And_17E7BB31 )? 1 : 0))

    {

        Direct_Switch_43ADB09B = ((int32_t)(((float_t) Multiply_805ADFBE) * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_43ADB09B = (((int32_t) Multiply_805ADFBE));

    }

    Saturation_70D623F9 = (((int32_t)(Direct_Switch_43ADB09B + ((int32_t) And_17E7BB31))));

    if(Saturation_70D623F9 < (((int32_t) ((uint32_t) 0U))))

    {

        Saturation_70D623F9 = (((int32_t) ((uint32_t) 0U)));

    }

    else if(Saturation_70D623F9 > (((int32_t) ((uint32_t) 255U))))

    {

        Saturation_70D623F9 = (((int32_t) ((uint32_t) 255U)));

    }

    else

    {

        /* This code block intentionally left blank */

    }

    And_D683C11F = ((uint32_t) ((argIn1) & ((uint32_t) 255U)));

    And_96F86F50 = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 255U)));

    Compare_31582744 = (And_D683C11F != And_96F86F50 )? 1 : 0;

    if(0U == (((0U != (argIn0)) && (0 != Compare_31582744)) ? 1U : 0U))

    {

        Direct_Switch_729759EA = (((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 255U))));

    }

    else

    {

        Direct_Switch_729759EA = (((uint32_t) Saturation_70D623F9));

    }

    And_D3CE9607 = ((uint32_t) (Direct_Switch_729759EA & ((uint32_t) 255U)));

    Or_A2C6BD7F = ((uint32_t) (And_D3CE9607 | And_C5037235));

    Divide_9F596FD9 = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) (argIn2));

    Multiply_05F0B6D3 = (uint32_t)(Divide_9F596FD9 * ((float_t) 255.0F));

    And_6966E525 = ((uint32_t) ((argIn1) & ((uint32_t) 16711680U)));

    And_9BF591E2 = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 16711680U)));

    if(0 == ((And_6966E525 > And_9BF591E2 )? 1 : 0))

    {

        Direct_Switch_D70D7314 = ((int32_t)(((float_t) Multiply_05F0B6D3) * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_D70D7314 = (((int32_t) Multiply_05F0B6D3));

    }

    Shift____6DACCA3A = ((uint32_t) (And_9BF591E2 >> ((uint32_t) 16U)));

    Saturation_B9326894 = (((int32_t)(Direct_Switch_D70D7314 + ((int32_t) Shift____6DACCA3A))));

    if(Saturation_B9326894 < (((int32_t) ((uint32_t) 0U))))

    {

        Saturation_B9326894 = (((int32_t) ((uint32_t) 0U)));

    }

    else if(Saturation_B9326894 > (((int32_t) ((uint32_t) 255U))))

    {

        Saturation_B9326894 = (((int32_t) ((uint32_t) 255U)));

    }

    else

    {

        /* This code block intentionally left blank */

    }

    And_FE9120AB = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 16711680U)));

    And_7B3E55DE = ((uint32_t) ((argIn1) & ((uint32_t) 16711680U)));

    And_BEF91232 = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 16711680U)));

    Compare_912B4B57 = (And_7B3E55DE != And_BEF91232 )? 1 : 0;

    if(0U == (((0U != (argIn0)) && (0 != Compare_912B4B57)) ? 1U : 0U))

    {

        Direct_Switch_01C1C617 = (((uint32_t) (And_FE9120AB >> ((uint32_t) 16U))));

    }

    else

    {

        Direct_Switch_01C1C617 = (((uint32_t) Saturation_B9326894));

    }

    Shift____B4819AED = ((uint32_t) (Direct_Switch_01C1C617 << ((uint32_t) 16U)));

    And_DD401375 = ((uint32_t) (Shift____B4819AED & ((uint32_t) 16711680U)));

    Or_5B611976 = ((uint32_t) (Or_A2C6BD7F | And_DD401375));

    Divide_2CFA492C = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) (argIn2));

    Multiply_2F2AEBD4 = (uint32_t)(Divide_2CFA492C * ((float_t) 255.0F));

    And_26A52271 = ((uint32_t) ((argIn1) & ((uint32_t) 4278190080U)));

    And_92F33B72 = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 4278190080U)));

    if(0 == ((And_26A52271 > And_92F33B72 )? 1 : 0))

    {

        Direct_Switch_9819A3E8 = ((int32_t)(((float_t) Multiply_2F2AEBD4) * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_9819A3E8 = (((int32_t) Multiply_2F2AEBD4));

    }

    Shift____ED7F12EE = ((uint32_t) (And_92F33B72 >> ((uint32_t) 24U)));

    Saturation_B2433C1C = (((int32_t)(Direct_Switch_9819A3E8 + ((int32_t) Shift____ED7F12EE))));

    if(Saturation_B2433C1C < (((int32_t) ((uint32_t) 0U))))

    {

        Saturation_B2433C1C = (((int32_t) ((uint32_t) 0U)));

    }

    else if(Saturation_B2433C1C > (((int32_t) ((uint32_t) 255U))))

    {

        Saturation_B2433C1C = (((int32_t) ((uint32_t) 255U)));

    }

    else

    {

        /* This code block intentionally left blank */

    }

    And_37FC0A6C = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 4278190080U)));

    And_59667513 = ((uint32_t) ((argIn1) & ((uint32_t) 4278190080U)));

    And_61960BFC = ((uint32_t) ((*ptrMapCollor_data) & ((uint32_t) 4278190080U)));

    Compare_A1722F24 = (And_59667513 != And_61960BFC )? 1 : 0;

    if(0U == (((0U != (argIn0)) && (0 != Compare_A1722F24)) ? 1U : 0U))

    {

        Direct_Switch_FA91CD58 = (((uint32_t) (And_37FC0A6C >> ((uint32_t) 24U))));

    }

    else

    {

        Direct_Switch_FA91CD58 = (((uint32_t) Saturation_B2433C1C));

    }

    Shift____64C406EB = ((uint32_t) (Direct_Switch_FA91CD58 << ((uint32_t) 24U)));

    And_68D2C473 = ((uint32_t) (Shift____64C406EB & ((uint32_t) 4278190080U)));

    *ptrMapCollor_data = (((uint32_t) (Or_5B611976 | And_68D2C473)));

}

void ColorChange(void *param0, double_t argIn0, double_t argIn1, double_t argIn2, uint32_t argIn3, uint32_t argIn4)
{

    float_t Min_BFAFCF2C;

    float_t Subtract_CC4030BB;

    float_t Subtract_5B3CEBBC;

    float_t Divide_AAAA80D6;

    float_t Direct_Switch_0A5AD389;

    uint32_t And_1C53EFF4;

    uint32_t And_6DA33089;

    int32_t Subtract_AEF492FD;

    float_t Multiply_2B4B0A2C;

    uint32_t Shift____D31874B4;

    uint32_t And_A7AD2886;

    uint32_t Shift____1E6309E1;

    uint32_t And_79FDABA1;

    int32_t Subtract_62E93ADF;

    float_t Multiply_C12BBEA7;

    uint32_t Shift____F651C977;

    uint32_t And_A1A7727B;

    uint32_t Shift____93CAB550;

    uint32_t And_5922243E;

    int32_t Subtract_5FD507A8;

    float_t Multiply_FE603058;

    uint32_t Shift____5B068849;

    uint32_t And_942B3062;

    uint32_t Shift____34BD5312;

    uint32_t And_415D5B81;

    int32_t Subtract_B4578DD4;

    float_t Multiply_BDED4D40;

    uint32_t Shift____006F5871;

    uint32_t Shift____1E733628;

    uint32_t Shift____B0E97AA0;

    uint32_t Shift____79CFC3DA;

    ptrColorChange_data = (uint32_t*) param0;

    Min_BFAFCF2C = (((float_t) (argIn0)));

    if((((float_t) (argIn2))) < Min_BFAFCF2C)

    {

        Min_BFAFCF2C = (((float_t) (argIn2)));

    }

    Subtract_CC4030BB = ((float_t)(Min_BFAFCF2C - ((float_t) (argIn1))));

    Subtract_5B3CEBBC = ((float_t)(((float_t) (argIn2)) - ((float_t) (argIn1))));

    Divide_AAAA80D6 = (float_t)(((float_t) 1.0F) / Subtract_5B3CEBBC);

    if(0U == ((Subtract_CC4030BB <= ((float_t) 0.01F) )? 1U : 0U))

    {

        Direct_Switch_0A5AD389 = ((float_t)(Subtract_CC4030BB * Divide_AAAA80D6));

    }

    else

    {

        Direct_Switch_0A5AD389 = ((float_t) 0.01F);

    }

    Factor_data = Direct_Switch_0A5AD389;

    And_1C53EFF4 = ((uint32_t) ((argIn4) & ((uint32_t) 255U)));

    And_6DA33089 = ((uint32_t) ((argIn3) & ((uint32_t) 255U)));

    Subtract_AEF492FD = ((int32_t)(((int32_t) And_1C53EFF4) - ((int32_t) And_6DA33089)));

    Multiply_2B4B0A2C = (float_t)((Factor_data) * ((float_t) Subtract_AEF492FD));

    Blue_data = ((uint32_t) (((int32_t)(((int32_t) Multiply_2B4B0A2C) + ((int32_t) And_6DA33089)))));

    Shift____D31874B4 = ((uint32_t) ((argIn4) >> ((uint32_t) 8U)));

    And_A7AD2886 = ((uint32_t) (Shift____D31874B4 & ((uint32_t) 255U)));

    Shift____1E6309E1 = ((uint32_t) ((argIn3) >> ((uint32_t) 8U)));

    And_79FDABA1 = ((uint32_t) (Shift____1E6309E1 & ((uint32_t) 255U)));

    Subtract_62E93ADF = ((int32_t)(((int32_t) And_A7AD2886) - ((int32_t) And_79FDABA1)));

    Multiply_C12BBEA7 = (float_t)((Factor_data) * ((float_t) Subtract_62E93ADF));

    Green_data = ((uint32_t) (((int32_t)(((int32_t) Multiply_C12BBEA7) + ((int32_t) And_79FDABA1)))));

    Shift____F651C977 = ((uint32_t) ((argIn4) >> ((uint32_t) 16U)));

    And_A1A7727B = ((uint32_t) (Shift____F651C977 & ((uint32_t) 255U)));

    Shift____93CAB550 = ((uint32_t) ((argIn3) >> ((uint32_t) 16U)));

    And_5922243E = ((uint32_t) (Shift____93CAB550 & ((uint32_t) 255U)));

    Subtract_5FD507A8 = ((int32_t)(((int32_t) And_A1A7727B) - ((int32_t) And_5922243E)));

    Multiply_FE603058 = (float_t)((Factor_data) * ((float_t) Subtract_5FD507A8));

    Red_data = ((uint32_t) (((int32_t)(((int32_t) Multiply_FE603058) + ((int32_t) And_5922243E)))));

    Shift____5B068849 = ((uint32_t) ((argIn4) >> ((uint32_t) 24U)));

    And_942B3062 = ((uint32_t) (Shift____5B068849 & ((uint32_t) 255U)));

    Shift____34BD5312 = ((uint32_t) ((argIn3) >> ((uint32_t) 24U)));

    And_415D5B81 = ((uint32_t) (Shift____34BD5312 & ((uint32_t) 255U)));

    Subtract_B4578DD4 = ((int32_t)(((int32_t) And_942B3062) - ((int32_t) And_415D5B81)));

    Multiply_BDED4D40 = (float_t)((Factor_data) * ((float_t) Subtract_B4578DD4));

    Alpha_data = ((uint32_t) (((int32_t)(((int32_t) Multiply_BDED4D40) + ((int32_t) And_415D5B81)))));

    Shift____006F5871 = ((uint32_t) ((Blue_data) << ((uint32_t) 0U)));

    Shift____1E733628 = ((uint32_t) ((Green_data) << ((uint32_t) 8U)));

    Shift____B0E97AA0 = ((uint32_t) ((Red_data) << ((uint32_t) 16U)));

    Shift____79CFC3DA = ((uint32_t) ((Alpha_data) << ((uint32_t) 24U)));

    *ptrColorChange_data = (((uint32_t)(Shift____006F5871 + Shift____1E733628 + Shift____B0E97AA0 + Shift____79CFC3DA)));

}

void SetPictPosMenuLvl_0(void *param0, float_t argIn0)
{

    float_t Divide_F2D7DACB;

    float_t Multiply_8F0FBE60;

    float_t Direct_Switch_BE3F0E58;

    float_t Saturation_B0C8DDFF;

    PictPosMenuLvl_0_data = (float_t*) param0;

    Divide_F2D7DACB = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) ((int32_t) 400));

    Multiply_8F0FBE60 = (float_t)(Divide_F2D7DACB * ((float_t) 262.0F));

    if(0 == (((argIn0) != ((float_t) ((int8_t) 0)) )? 1 : 0))

    {

        Direct_Switch_BE3F0E58 = ((float_t)(Multiply_8F0FBE60 * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_BE3F0E58 = Multiply_8F0FBE60;

    }

    Saturation_B0C8DDFF = (((float_t)(Direct_Switch_BE3F0E58 + (*PictPosMenuLvl_0_data))));

    if(Saturation_B0C8DDFF < ((float_t) 212.0F))

    {

        Saturation_B0C8DDFF = ((float_t) 212.0F);

    }

    else if(Saturation_B0C8DDFF > ((float_t) 474.0F))

    {

        Saturation_B0C8DDFF = ((float_t) 474.0F);

    }

    else

    {

        /* This code block intentionally left blank */

    }

    *PictPosMenuLvl_0_data = Saturation_B0C8DDFF;

}

void BusDoorOpen(void *param0, void *param1, int32_t argIn0, int32_t argIn1, int32_t argIn2, int32_t argIn3, int32_t argIn4, double_t argIn5)
{

    float_t Divide_9DB39FD9;

    float_t Direct_Switch_55D896E7;

    float_t Direct_Switch_5F79E672;

    float_t Saturation_AD0632F1;

    float_t Direct_Switch_770EFDFC;

    float_t Direct_Switch_6F2E5EF5;

    float_t Direct_Switch_4AEF3338;

    float_t Direct_Switch_7974854E;

    ptrBusDoorI_data = (int8_t*) param0;

    ptrBusDoorH_data = (float_t*) param1;

    Divide_9DB39FD9 = (float_t)((float_t) (DeltaGlobalTimeCountMs_data) / (float_t) ((int32_t) 50));

    if(0 == (((0 != (argIn0)) || (0 != (argIn1))) ? 1 : 0))

    {

        Direct_Switch_55D896E7 = ((float_t)(Divide_9DB39FD9 * ((float_t) (-1.0F))));

    }

    else

    {

        Direct_Switch_55D896E7 = Divide_9DB39FD9;

    }

    if(0 == (argIn1))

    {

        Direct_Switch_5F79E672 = ((float_t) 10.0F);

    }

    else

    {

        Direct_Switch_5F79E672 = ((float_t) 11.0F);

    }

    Saturation_AD0632F1 = (((float_t)(Direct_Switch_55D896E7 + (*ptrBusDoorH_data))));

    if(Saturation_AD0632F1 < ((float_t) 0.0F))

    {

        Saturation_AD0632F1 = ((float_t) 0.0F);

    }

    else if(Saturation_AD0632F1 > Direct_Switch_5F79E672)

    {

        Saturation_AD0632F1 = Direct_Switch_5F79E672;

    }

    else

    {

        /* This code block intentionally left blank */

    }

    *ptrBusDoorH_data = Saturation_AD0632F1;

    if(0 == (argIn5))

    {

        Direct_Switch_770EFDFC = Saturation_AD0632F1;

    }

    else

    {

        Direct_Switch_770EFDFC = ((float_t) 15.0F);

    }

    if(0 == (argIn4))

    {

        Direct_Switch_6F2E5EF5 = Direct_Switch_770EFDFC;

    }

    else

    {

        Direct_Switch_6F2E5EF5 = ((float_t) 14.0F);

    }

    if(0 == (argIn3))

    {

        Direct_Switch_4AEF3338 = Direct_Switch_6F2E5EF5;

    }

    else

    {

        Direct_Switch_4AEF3338 = ((float_t) 13.0F);

    }

    if(0 == (argIn2))

    {

        Direct_Switch_7974854E = Direct_Switch_4AEF3338;

    }

    else

    {

        Direct_Switch_7974854E = ((float_t) 12.0F);

    }

    *ptrBusDoorI_data = ((int8_t) Direct_Switch_7974854E);

}

void IgnitionStartAnimationScale(void *param0, void *param1, int16_t argIn0, double_t argIn1)
{

    float_t Direct_Switch_E6820C90;

    float_t Function_Call_E181A094;

    float_t Saturation_399B93E8;

    double_t Sin_5A17B61C;

    ptrScaleVar_data = (float_t*) param0;

    ptrScaleState_data = (float_t*) param1;

    if(0.0F == (*ptrScaleState_data))

    {

        Direct_Switch_E6820C90 = (((float_t) (argIn1)));

    }

    else

    {

        Direct_Switch_E6820C90 = ((((float_t) (argIn0)) / 4.0F));

    }

    Function_Call_E181A094 = Lerp((*ptrScaleVar_data), Direct_Switch_E6820C90, ((int32_t) 30));

    Saturation_399B93E8 = Function_Call_E181A094;

    if(Saturation_399B93E8 < (((float_t) (argIn1))))

    {

        Saturation_399B93E8 = (((float_t) (argIn1)));

    }

    else if(Saturation_399B93E8 > ((((float_t) (argIn0)) / 4.0F)))

    {

        Saturation_399B93E8 = ((((float_t) (argIn0)) / 4.0F));

    }

    else

    {

        /* This code block intentionally left blank */

    }

    *ptrScaleVar_data = Saturation_399B93E8;

    if(Function_Call_E181A094 >= (((float_t) (argIn0)) / 4.0F))

    {
        *ptrScaleState_data = ((float_t) ((int8_t) 0));
    }

    if(Function_Call_E181A094 <= ((float_t) (argIn1)))

    {
        *ptrScaleState_data = ((float_t) ((int8_t) 1));
    }

    Sin_5A17B61C = sin((0));

}

uint64_t API_CAN_ReadValueFromBuffer(void *param0, uint8_t argIn0, uint8_t argIn1, uint8_t argIn2)
{

    uint64_t argOut0 = 1;

    uint8_t For_5CD2E422 = 0;

    uint8_t Add_4E26E5D1;

    uint8_t Divide_6477D251;

    uint8_t Direct_Switch_338B7140;

    uint64_t Shift____6ACE3BE6;

    uint64_t Subtract_4A7DCA83;

    Buffer_data = (uint8_t*) param0;

    Result_data = ((uint64_t) 0UL);

    Add_4E26E5D1 = ((uint8_t)((argIn1) + (argIn2)));

    Divide_6477D251 = (uint8_t)(Add_4E26E5D1 / ((uint8_t) 8U));

    if(0U == ((uint8_t) (Add_4E26E5D1 % ((uint8_t) 8U))))

    {

        Direct_Switch_338B7140 = Divide_6477D251;

    }

    else

    {

        Direct_Switch_338B7140 = (((uint8_t)(((uint8_t) 1U) + Divide_6477D251)));

    }

    for(For_5CD2E422 = 0U; For_5CD2E422 < Direct_Switch_338B7140; ++For_5CD2E422)

    {
        uint8_t Multiply_5F242C11;
        uint8_t Subtract_8C42B674;
        uint64_t Direct_Switch_B15E4199;
        /* Data dictionary\CAN Communication Functions
for CAN parser\API_CAN_ReadValueFromBuffer\Container */
        Index_data = For_5CD2E422;
        
        Multiply_5F242C11 = (uint8_t)(((int16_t) ((uint8_t) 8U)) * ((int16_t) (Index_data)));
        
        Subtract_8C42B674 = ((uint8_t)(Multiply_5F242C11 - ((argIn1))));
        
        if(0U == (Index_data))
        {
            Direct_Switch_B15E4199 = (((uint64_t) (((uint64_t) (Buffer_data[((int32_t) ((argIn0)))])) >> ((argIn1)))));
        }
        else
        {
            Direct_Switch_B15E4199 = (((uint64_t) (((uint64_t) (Buffer_data[((((uint8_t)((Index_data) + ((uint8_t) ((argIn0)))))))])) << Subtract_8C42B674)));
        }
        
        Result_data = (((uint64_t) (Direct_Switch_B15E4199 | (Result_data))));
        
    }

    Shift____6ACE3BE6 = ((uint64_t) (((uint64_t) ((uint8_t) 1U)) << (argIn2)));

    Subtract_4A7DCA83 = ((uint64_t)(Shift____6ACE3BE6 - ((uint64_t) ((uint8_t) 1U))));

    argOut0 = (((uint64_t) (Subtract_4A7DCA83 & (Result_data))));

    return argOut0;

}

void API_Write_2bit_data_to_buffer(void *param0, uint8_t argIn0, uint8_t argIn1, uint8_t argIn2)
{

    uint8_t Not_FF951AA5;

    uint8_t And_17F715F3;

    uint8_t And_EC4603BA;

    uint8_t Shift____2E595DED;

    Buffer_A_data = (uint8_t*) param0;

    Not_FF951AA5 = (uint8_t) ~(((uint8_t) (((uint8_t) 3U) << (argIn1))));

    And_17F715F3 = ((uint8_t) ((Buffer_A_data[(argIn0)]) & Not_FF951AA5));

    And_EC4603BA = ((uint8_t) ((argIn2) & ((uint8_t) 3U)));

    Shift____2E595DED = ((uint8_t) (And_EC4603BA << (argIn1)));

    Buffer_A_data[(argIn0)] = (((uint8_t) (And_17F715F3 | Shift____2E595DED)));

}

void API_Copy_To_Buffer(void *param0, void *param1, uint8_t argIn0, uint8_t argIn1, uint8_t argIn2)
{

    uint8_t For_073F0953 = 0;

    Buffer_A_data = (uint8_t*) param0;

    Buffer_B_data = (uint8_t*) param1;

    for(For_073F0953 = 0U; For_073F0953 < (argIn2); ++For_073F0953)

    {
        uint8_t Read_Parameter_00D27987;
        /* Data dictionary\CAN Communication Functions
for CAN parser\API_Copy_To_Buffer\Container */
        CAN_Message_Buffer_Index_data = For_073F0953;
        
        Read_Parameter_00D27987 = CAN_Message_Buffer_Index_data;
        
        Buffer_B_data[((((uint8_t)(((argIn1)) + Read_Parameter_00D27987))))] = (Buffer_A_data[((((uint8_t)(((uint8_t) ((argIn0))) + Read_Parameter_00D27987))))]);
        
    }

}

void API_ResetBuffer(void *param0)
{

    uint8_t For_9C9D0F32 = 0;

    uint8_t Read_Parameter_850A6940;

    Buffer_A_data = (uint8_t*) param0;

    Read_Parameter_850A6940 = CAN_Buffer_Length_data;

    for(For_9C9D0F32 = 0U; For_9C9D0F32 < Read_Parameter_850A6940; ++For_9C9D0F32)

    {
        /* Data dictionary\CAN Communication Functions
for CAN parser\API_ResetBuffer\Container */
        CAN_Message_Buffer_Index_data = For_9C9D0F32;
        
        Buffer_A_data[(CAN_Message_Buffer_Index_data)] = ((uint8_t) 255U);
        
    }

}

double_t API_CAN_WriteSPNandFMI(void *param0, double_t argIn0, double_t argIn1, double_t argIn2, double_t *argOut1)
{

    double_t argOut0 = 1;

    uint64_t Function_Call_270FCBCF;

    uint32_t Convert_Metric_2257F313;

    uint32_t And_6C781A2A;

    uint32_t Shift____9F34496B;

    uint32_t And_06B649A3;

    uint32_t Shift____400E19DB;

    BufferSPNandFMI_data = (uint8_t*) param0;

    Function_Call_270FCBCF = API_CAN_ReadValueFromBuffer(BufferSPNandFMI_data, (((uint8_t) (argIn0))), (((uint8_t) (argIn1))), (((uint8_t) (argIn2))));

    Convert_Metric_2257F313 = ((uint32_t) Function_Call_270FCBCF);

    And_6C781A2A = ((uint32_t) (((uint32_t) 14680064U) & Convert_Metric_2257F313));

    Shift____9F34496B = ((uint32_t) (And_6C781A2A >> ((uint32_t) 5U)));

    And_06B649A3 = ((uint32_t) (Convert_Metric_2257F313 & ((uint32_t) 65535U)));

    argOut0 = ((double_t) (((uint32_t) (Shift____9F34496B | And_06B649A3))));

    Shift____400E19DB = ((uint32_t) (Convert_Metric_2257F313 >> ((uint32_t) 16U)));

    *argOut1 = ((double_t) (((uint32_t) (Shift____400E19DB & ((uint32_t) 31U)))));

    return argOut0;

}

void API_CAN_Analyze(void *param0, uint32_t argIn0, uint32_t argIn1)
{

    uint32_t Shift____79F8B615;

    uint8_t For_C28514D6 = 0;

    uint8_t For_CEF3536B = 0;

    uint8_t For_1CA819A6 = 0;

    uint8_t For_8241BA6E = 0;

    uint8_t For_B1D387EF = 0;

    uint32_t For_3ADAE7D0 = 0;

    uint8_t For_BDF47141 = 0;

    uint8_t For_5F591C0A = 0;

    uint8_t For_B44C4EBC = 0;

    CAN_Delta_T_data = ((int32_t) (argIn1));

    CAN_InBox_ID_data = ((argIn0));

    CAN_InBox_SA_data = (((uint8_t) (argIn0)));

    Shift____79F8B615 = ((uint32_t) ((argIn0) >> ((uint8_t) 8U)));

    CAN_InBox_PGN_data = (((uint16_t) Shift____79F8B615));

    CAN_Buffer_data = (uint8_t*) param0;

    /* // Общие параметры J1939
     */

    /* // Общие DM J1939
     */

    /* // A */

    {
        /* / * API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419343920U))
        {
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Receive Message */
            
            Time_FEAE_x30_data = ((int32_t) 0);
            
            TimeOut_FEAE_x30_data = ((uint8_t) 0U);
            
            AirPres1_x30_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            AirPres2_x30_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            AirPres3_x30_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_BDC64A64;
            int32_t Add_5201F0FB;
            int32_t Saturation_9C0FF897;
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Increment Timer */
            
            Read_Parameter_BDC64A64 = Time_FEAE_x30_data;
            
            Add_5201F0FB = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_BDC64A64));
            
            Saturation_9C0FF897 = Add_5201F0FB;
            if(Saturation_9C0FF897 < Read_Parameter_BDC64A64)
            {
                Saturation_9C0FF897 = Read_Parameter_BDC64A64;
            }
            else if(Saturation_9C0FF897 > Add_5201F0FB)
            {
                Saturation_9C0FF897 = Add_5201F0FB;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEAE_x30_data = Saturation_9C0FF897;
            
        }
        
        if((Time_FEAE_x30_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Reset signals */
            
            TimeOut_FEAE_x30_data = ((uint8_t) 1U);
            
            AirPres1_x30_data = ((uint8_t) 0U);
            
            AirPres2_x30_data = ((uint8_t) 0U);
            
            AirPres3_x30_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419343902U))
        {
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Receive Message */
            
            Time_FEAE_x1E_data = ((int32_t) 0);
            
            TimeOut_FEAE_x1E_data = ((uint8_t) 0U);
            
            AirPres1_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            AirPres2_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            AirPres3_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_1D0E3DA9;
            int32_t Add_10C5DE0C;
            int32_t Saturation_490A4633;
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Increment Timer */
            
            Read_Parameter_1D0E3DA9 = Time_FEAE_x1E_data;
            
            Add_10C5DE0C = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_1D0E3DA9));
            
            Saturation_490A4633 = Add_10C5DE0C;
            if(Saturation_490A4633 < Read_Parameter_1D0E3DA9)
            {
                Saturation_490A4633 = Read_Parameter_1D0E3DA9;
            }
            else if(Saturation_490A4633 > Add_10C5DE0C)
            {
                Saturation_490A4633 = Add_10C5DE0C;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEAE_x1E_data = Saturation_490A4633;
            
        }
        
        if((Time_FEAE_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Reset signals */
            
            TimeOut_FEAE_x1E_data = ((uint8_t) 1U);
            
            AirPres1_x1E_data = ((uint8_t) 0U);
            
            AirPres2_x1E_data = ((uint8_t) 0U);
            
            AirPres3_x1E_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419344126U))
        {
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Receive Message */
            
            Time_FEAE_xFE_data = ((int32_t) 0);
            
            TimeOut_FEAE_xFE_data = ((uint8_t) 0U);
            
            AirPres1_xFE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            AirPres2_xFE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_78321E7D;
            int32_t Add_B00AD19E;
            int32_t Saturation_C0BF10B9;
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Increment Timer */
            
            Read_Parameter_78321E7D = Time_FEAE_xFE_data;
            
            Add_B00AD19E = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_78321E7D));
            
            Saturation_C0BF10B9 = Add_B00AD19E;
            if(Saturation_C0BF10B9 < Read_Parameter_78321E7D)
            {
                Saturation_C0BF10B9 = Read_Parameter_78321E7D;
            }
            else if(Saturation_C0BF10B9 > Add_B00AD19E)
            {
                Saturation_C0BF10B9 = Add_B00AD19E;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEAE_xFE_data = Saturation_C0BF10B9;
            
        }
        
        if((Time_FEAE_xFE_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Reset signals */
            
            TimeOut_FEAE_xFE_data = ((uint8_t) 1U);
            
            AirPres1_xFE_data = ((uint8_t) 0U);
            
            AirPres2_xFE_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419343905U))
        {
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Receive Message */
            
            Time_FEAE_x21_data = ((int32_t) 0);
            
            TimeOut_FEAE_x21_data = ((uint8_t) 0U);
            
            AirPres1_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            AirPres2_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_EDA1EB75;
            int32_t Add_A7B759D0;
            int32_t Saturation_9EBDCCAB;
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Increment Timer */
            
            Read_Parameter_EDA1EB75 = Time_FEAE_x21_data;
            
            Add_A7B759D0 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_EDA1EB75));
            
            Saturation_9EBDCCAB = Add_A7B759D0;
            if(Saturation_9EBDCCAB < Read_Parameter_EDA1EB75)
            {
                Saturation_9EBDCCAB = Read_Parameter_EDA1EB75;
            }
            else if(Saturation_9EBDCCAB > Add_A7B759D0)
            {
                Saturation_9EBDCCAB = Add_A7B759D0;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEAE_x21_data = Saturation_9EBDCCAB;
            
        }
        
        if((Time_FEAE_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AIR1, PGN=FEAE
Давление пневмосистем 123\Reset signals */
            
            TimeOut_FEAE_x21_data = ((uint8_t) 1U);
            
            AirPres1_x21_data = ((uint8_t) 0U);
            
            AirPres2_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\AIR2_id1E
PGN FEDE
Давление пневмосистем 4, 5 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419356190U))
        {
            /* API_CAN_Analyze\AIR2_id1E
PGN FEDE
Давление пневмосистем 4, 5\Receive Message */
            
            Time_FEDE_x1E_data = ((int32_t) 0);
            
            TimeOut_FEDE_x1E_data = ((uint8_t) 0U);
            
            AirPres5_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            AirPres4_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_4189B096;
            int32_t Add_814153F5;
            int32_t Saturation_6D7BAFDC;
            /* API_CAN_Analyze\AIR2_id1E
PGN FEDE
Давление пневмосистем 4, 5\Increment Timer */
            
            Read_Parameter_4189B096 = Time_FEDE_x1E_data;
            
            Add_814153F5 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_4189B096));
            
            Saturation_6D7BAFDC = Add_814153F5;
            if(Saturation_6D7BAFDC < Read_Parameter_4189B096)
            {
                Saturation_6D7BAFDC = Read_Parameter_4189B096;
            }
            else if(Saturation_6D7BAFDC > Add_814153F5)
            {
                Saturation_6D7BAFDC = Add_814153F5;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEDE_x1E_data = Saturation_6D7BAFDC;
            
        }
        
        if((Time_FEDE_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AIR2_id1E
PGN FEDE
Давление пневмосистем 4, 5\Reset signals */
            
            TimeOut_FEDE_x1E_data = ((uint8_t) 1U);
            
            AirPres4_x1E_data = ((uint8_t) 0U);
            
            AirPres5_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\AMB
PGN: FEF5
AmbientConditions * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419362081U))
        {
            /* API_CAN_Analyze\AMB
PGN: FEF5
AmbientConditions\Receive Message */
            
            Time_FEF5_x21_data = ((int32_t) 0);
            
            TimeOut_FEF5_x21_data = ((uint8_t) 0U);
            
            DriverRoomTemp_x21_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 8736))));
            
            AmbientTemp_x21_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 8736))));
            
            SalonTemp_x21_data = ((int32_t) (((int64_t) (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))))) * 32L));
            
        }
        else
        {
            int32_t Read_Parameter_557DD733;
            int32_t Add_6320DA08;
            int32_t Saturation_5109499B;
            /* API_CAN_Analyze\AMB
PGN: FEF5
AmbientConditions\Increment Timer */
            
            Read_Parameter_557DD733 = Time_FEF5_x21_data;
            
            Add_6320DA08 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_557DD733));
            
            Saturation_5109499B = Add_6320DA08;
            if(Saturation_5109499B < Read_Parameter_557DD733)
            {
                Saturation_5109499B = Read_Parameter_557DD733;
            }
            else if(Saturation_5109499B > Add_6320DA08)
            {
                Saturation_5109499B = Add_6320DA08;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF5_x21_data = Saturation_5109499B;
            
        }
        
        if((Time_FEF5_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AMB
PGN: FEF5
AmbientConditions\Reset signals */
            
            TimeOut_FEF5_x21_data = ((uint8_t) 1U);
            
            DriverRoomTemp_x21_data = ((int32_t) 0);
            
            AmbientTemp_x21_data = ((int32_t) 0);
            
            SalonTemp_x21_data = (((int32_t) 0) * 32);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419362138U))
        {
            /* API_CAN_Analyze\AMB
PGN: FEF5
AmbientConditions\Receive Message */
            
            Time_FEF5_x5A_data = ((int32_t) 0);
            
            TimeOut_FEF5_x5A_data = ((uint8_t) 0U);
            
            AmbientTemp_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 8736))));
            
        }
        else
        {
            int32_t Read_Parameter_CBED8249;
            int32_t Add_582DBAC1;
            int32_t Saturation_42F46717;
            /* API_CAN_Analyze\AMB
PGN: FEF5
AmbientConditions\Increment Timer */
            
            Read_Parameter_CBED8249 = Time_FEF5_x5A_data;
            
            Add_582DBAC1 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_CBED8249));
            
            Saturation_42F46717 = Add_582DBAC1;
            if(Saturation_42F46717 < Read_Parameter_CBED8249)
            {
                Saturation_42F46717 = Read_Parameter_CBED8249;
            }
            else if(Saturation_42F46717 > Add_582DBAC1)
            {
                Saturation_42F46717 = Add_582DBAC1;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF5_x5A_data = Saturation_42F46717;
            
        }
        
        if((Time_FEF5_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AMB
PGN: FEF5
AmbientConditions\Reset signals */
            
            TimeOut_FEF5_x5A_data = ((uint8_t) 1U);
            
            AmbientTemp_x5A_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\ASC1
PGN=FE5A
Kneeling * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217995823U))
        {
            /* API_CAN_Analyze\ASC1
PGN=FE5A
Kneeling\Receive Message */
            
            Time_FE5A_x2F_data = ((int32_t) 0);
            
            TimeOut_FE5A_x2F_data = ((uint8_t) 0U);
            
            Kneeling_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
            Kneeling_SPN1734_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
            Kneeling_SPN1733_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 4U))));
            
            Kneeling_SPN1736_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Kneeling_SPN1737_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Kneeling_SPN1738_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Kneeling_SPN1739_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Kneeling_SPN1740_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Kneeling_SPN1754_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Kneeling_SPN1755_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Kneeling_SPN1756_x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_2BB56965;
            int32_t Add_D6AA32D9;
            int32_t Saturation_E0DA0777;
            /* API_CAN_Analyze\ASC1
PGN=FE5A
Kneeling\Increment Timer */
            
            Read_Parameter_2BB56965 = Time_FE5A_x2F_data;
            
            Add_D6AA32D9 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_2BB56965));
            
            Saturation_E0DA0777 = Add_D6AA32D9;
            if(Saturation_E0DA0777 < Read_Parameter_2BB56965)
            {
                Saturation_E0DA0777 = Read_Parameter_2BB56965;
            }
            else if(Saturation_E0DA0777 > Add_D6AA32D9)
            {
                Saturation_E0DA0777 = Add_D6AA32D9;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE5A_x2F_data = Saturation_E0DA0777;
            
        }
        
        if((Time_FE5A_x2F_data) >= ((int32_t) 5000))
        {
            /* API_CAN_Analyze\ASC1
PGN=FE5A
Kneeling\Reset signals */
            
            TimeOut_FE5A_x2F_data = ((uint8_t) 1U);
            
            Kneeling_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1733_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1734_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1736_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1737_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1738_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1739_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1740_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1754_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1755_x2F_data = ((uint8_t) 0U);
            
            Kneeling_SPN1756_x2F_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\AT1T1I1, (??????)
PGN FE56
Уровень adBlue * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419321344U))
        {
            /* API_CAN_Analyze\AT1T1I1, (??????)
PGN FE56
Уровень adBlue\Receive Message */
            
            Time_FE56_x00_data = ((int32_t) 0);
            
            TimeOut_FE56_x00_data = ((uint8_t) 0U);
            
            AdBlueLvl_0x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_06A7EABA;
            int32_t Add_5D695559;
            int32_t Saturation_648BA070;
            /* API_CAN_Analyze\AT1T1I1, (??????)
PGN FE56
Уровень adBlue\Increment Timer */
            
            Read_Parameter_06A7EABA = Time_FE56_x00_data;
            
            Add_5D695559 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_06A7EABA));
            
            Saturation_648BA070 = Add_5D695559;
            if(Saturation_648BA070 < Read_Parameter_06A7EABA)
            {
                Saturation_648BA070 = Read_Parameter_06A7EABA;
            }
            else if(Saturation_648BA070 > Add_5D695559)
            {
                Saturation_648BA070 = Add_5D695559;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE56_x00_data = Saturation_648BA070;
            
        }
        
        if((Time_FE56_x00_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AT1T1I1, (??????)
PGN FE56
Уровень adBlue\Reset signals */
            
            TimeOut_FE56_x00_data = ((uint8_t) 1U);
            
            AdBlueLvl_0x00_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419321405U))
        {
            /* API_CAN_Analyze\AT1T1I1, (??????)
PGN FE56
Уровень adBlue\Receive Message */
            
            Time_FE56_x3D_data = ((int32_t) 0);
            
            TimeOut_FE56_x3D_data = ((uint8_t) 0U);
            
            AdBlueLvl_0x3D_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_22DC98B2;
            int32_t Add_C5BD74D6;
            int32_t Saturation_80C7E143;
            /* API_CAN_Analyze\AT1T1I1, (??????)
PGN FE56
Уровень adBlue\Increment Timer */
            
            Read_Parameter_22DC98B2 = Time_FE56_x3D_data;
            
            Add_C5BD74D6 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_22DC98B2));
            
            Saturation_80C7E143 = Add_C5BD74D6;
            if(Saturation_80C7E143 < Read_Parameter_22DC98B2)
            {
                Saturation_80C7E143 = Read_Parameter_22DC98B2;
            }
            else if(Saturation_80C7E143 > Add_C5BD74D6)
            {
                Saturation_80C7E143 = Add_C5BD74D6;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE56_x3D_data = Saturation_80C7E143;
            
        }
        
        if((Time_FE56_x3D_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AT1T1I1, (??????)
PGN FE56
Уровень adBlue\Reset signals */
            
            TimeOut_FE56_x3D_data = ((uint8_t) 1U);
            
            AdBlueLvl_0x3D_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX * / */
    
        if((CAN_InBox_PGN_data) == ((uint16_t) 65226U))
        {
            /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Receive Single Frame Message */
            
            for(For_C28514D6 = 0U; For_C28514D6 < ((uint8_t) 42U); ++For_C28514D6)
            {
                /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Receive Single Frame Message\Reset Buffer */
                DM1_Index_0xXX_data = For_C28514D6;
                
                DM1_Buffer_0xXX_data[(DM1_Index_0xXX_data)] = ((uint8_t) 0U);
                
            }
            
            API_Copy_To_Buffer(CAN_Buffer_data, DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 42U));
            
            DM1_ReadyFlag_0xXX_data = ((uint8_t) 1U);
            
            TotalDTC_0xXX_data = ((uint8_t) 1U);
            
        }
        
        if((CAN_InBox_PGN_data) == ((uint16_t) 60671U))
        {
            uint64_t Function_Call_349176B4;
            uint64_t Saturation_EC01CCD8;
            uint64_t Function_Call_29214204;
            uint64_t Saturation_7D5AC91B;
            int16_t Subtract_655CC28E;
            /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Get Ready to Receive Multi Frame Message */
            
            for(For_CEF3536B = 0U; For_CEF3536B < ((uint8_t) 42U); ++For_CEF3536B)
            {
                /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Get Ready to Receive Multi Frame Message\Reset Buffer */
                DM1_Index_0xXX_data = For_CEF3536B;
                
                DM1_Buffer_0xXX_data[(DM1_Index_0xXX_data)] = ((uint8_t) 0U);
                
            }
            
            DM1_Index_0xXX_data = ((uint8_t) 1U);
            
            Function_Call_349176B4 = API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 16U));
            
            Saturation_EC01CCD8 = Function_Call_349176B4;
            if(Saturation_EC01CCD8 < Function_Call_349176B4)
            {
                Saturation_EC01CCD8 = Function_Call_349176B4;
            }
            else if(Saturation_EC01CCD8 > (((uint64_t) ((uint8_t) 42U))))
            {
                Saturation_EC01CCD8 = (((uint64_t) ((uint8_t) 42U)));
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            DM1_ExpectedBytesCount_0xXX_data = ((uint8_t) Saturation_EC01CCD8);
            
            Function_Call_29214204 = API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U));
            
            Saturation_7D5AC91B = Function_Call_29214204;
            if(Saturation_7D5AC91B < Function_Call_29214204)
            {
                Saturation_7D5AC91B = Function_Call_29214204;
            }
            else if(Saturation_7D5AC91B > (((uint64_t) ((uint8_t) 6U))))
            {
                Saturation_7D5AC91B = (((uint64_t) ((uint8_t) 6U)));
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            DM1_ExpectedPartCount_0xXX_data = ((uint8_t) Saturation_7D5AC91B);
            
            Subtract_655CC28E = ((int16_t)(((int16_t) (DM1_ExpectedBytesCount_0xXX_data)) - ((int16_t) ((uint8_t) 2U))));
            
            TotalDTC_0xXX_data = ((uint8_t) ((int16_t)(Subtract_655CC28E / (int16_t) ((uint8_t) 4U))));
            
        }
        
        if((CAN_InBox_PGN_data) == ((uint16_t) 60415U))
        {
            /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Receive Multi Frame Message */
            
            if((DM1_ExpectedPartCount_0xXX_data) >= ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U)))))
            {
                uint8_t Read_Parameter_70540ED0;
                /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Receive Multi Frame Message\Container */
                
                if((DM1_Index_0xXX_data) == ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U)))))
                {
                    int8_t Subtract_B5FCD0D0;
                    uint16_t Multiply_E95E21D9;
                    int16_t Subtract_18AFE545;
                    int16_t Saturation_2520FD72;
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Receive Multi Frame Message\Container\Copy next part to local DM1 buffer */
                    
                    Subtract_B5FCD0D0 = ((int8_t)(((int8_t) (DM1_Index_0xXX_data)) - ((int8_t) ((uint8_t) 1U))));
                    
                    Multiply_E95E21D9 = (uint16_t)(((int16_t) Subtract_B5FCD0D0) * ((int16_t) ((uint8_t) 7U)));
                    
                    Subtract_18AFE545 = ((int16_t)(((int16_t) (DM1_ExpectedBytesCount_0xXX_data)) - ((int16_t) Multiply_E95E21D9)));
                    
                    Saturation_2520FD72 = Subtract_18AFE545;
                    if(Saturation_2520FD72 < Subtract_18AFE545)
                    {
                        Saturation_2520FD72 = Subtract_18AFE545;
                    }
                    else if(Saturation_2520FD72 > ((int16_t) 7))
                    {
                        Saturation_2520FD72 = ((int16_t) 7);
                    }
                    else
                    {
                        /* This code block intentionally left blank */
                    }
                    
                    API_Copy_To_Buffer(CAN_Buffer_data, DM1_Buffer_0xXX_data, ((uint8_t) 1U), (((uint8_t) Multiply_E95E21D9)), (((uint8_t) Saturation_2520FD72)));
                    
                }
                
                Read_Parameter_70540ED0 = DM1_Index_0xXX_data;
                
                DM1_ReadyFlag_0xXX_data = (((DM1_ExpectedPartCount_0xXX_data) == Read_Parameter_70540ED0 )? 1U : 0U);
                
                DM1_Index_0xXX_data = (((uint8_t)(Read_Parameter_70540ED0 + ((uint8_t) 1U))));
                
            }
            
        }
        
        if((DM1_ReadyFlag_0xXX_data) == ((uint8_t) ((uint16_t) 1U)))
        {
            uint8_t Add_946147A0;
            /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer */
            
            if((TotalDTC_0xXX_data) == ((uint8_t) 1U))
            {
                /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse single DTC */
                
                if(0U != (((CAN_InBox_SA_data) == ((uint8_t) 90U) )? 1U : 0U))
                {
                    double_t Function_Call_F10E2BAA_0;
                    double_t Function_Call_F10E2BAA_1;
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse single DTC\SA: 0x5A */
                    
                    /* // Total */
                    
                    DM1_DTC_Buffet_0x5A_data[((uint8_t) 0U)] = ((uint32_t) ((uint8_t) 1U));
                    
                    /* // SA */
                    
                    DM1_DTC_Buffet_0x5A_data[((uint8_t) 3U)] = ((uint32_t) (CAN_InBox_SA_data));
                    
                    /* // SPN */
                    
                    Function_Call_F10E2BAA_0 = API_CAN_WriteSPNandFMI(DM1_Buffer_0xXX_data, (((double_t) ((uint8_t) 2U))), (((double_t) ((uint8_t) 0U))), (((double_t) ((uint8_t) 24U))), &Function_Call_F10E2BAA_1);
                    
                    DM1_DTC_Buffet_0x5A_data[((uint8_t) 4U)] = ((uint32_t) Function_Call_F10E2BAA_0);
                    
                    DM1_DTC_Buffet_0x5A_data[((uint8_t) 5U)] = ((uint32_t) Function_Call_F10E2BAA_1);
                    
                    /* // FMI */
                    
                }
                else if(0U != (((CAN_InBox_SA_data) == ((uint8_t) 11U) )? 1U : 0U))
                {
                    double_t Function_Call_B71EA49C_0;
                    double_t Function_Call_B71EA49C_1;
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse single DTC\SA: 0x0B */
                    
                    /* // Total */
                    
                    DM1_DTC_Buffet_0x0B_data[((uint8_t) 0U)] = ((uint32_t) ((uint8_t) 1U));
                    
                    /* // SA */
                    
                    DM1_DTC_Buffet_0x0B_data[((uint8_t) 3U)] = ((uint32_t) (CAN_InBox_SA_data));
                    
                    /* // SPN */
                    
                    Function_Call_B71EA49C_0 = API_CAN_WriteSPNandFMI(DM1_Buffer_0xXX_data, (((double_t) ((uint8_t) 2U))), (((double_t) ((uint8_t) 0U))), (((double_t) ((uint8_t) 24U))), &Function_Call_B71EA49C_1);
                    
                    DM1_DTC_Buffet_0x0B_data[((uint8_t) 4U)] = ((uint32_t) Function_Call_B71EA49C_0);
                    
                    DM1_DTC_Buffet_0x0B_data[((uint8_t) 5U)] = ((uint32_t) Function_Call_B71EA49C_1);
                    
                    /* // FMI */
                    
                }
                else
                {
                    double_t Function_Call_E47D06F8_0;
                    double_t Function_Call_E47D06F8_1;
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse single DTC\SA: 0xXX */
                    
                    OtherSA_DTC_Flag_data = ((uint8_t) 1U);
                    
                    /* // Total */
                    
                    DM1_DTC_Buffer_0xXX_Lvl_1_data[((uint8_t) 0U)] = ((uint32_t) ((uint8_t) 1U));
                    
                    /* // SA */
                    
                    DM1_DTC_Buffer_0xXX_Lvl_1_data[((uint8_t) 3U)] = ((uint32_t) (CAN_InBox_SA_data));
                    
                    /* // SPN */
                    
                    Function_Call_E47D06F8_0 = API_CAN_WriteSPNandFMI(DM1_Buffer_0xXX_data, (((double_t) ((uint8_t) 2U))), (((double_t) ((uint8_t) 0U))), (((double_t) ((uint8_t) 24U))), &Function_Call_E47D06F8_1);
                    
                    DM1_DTC_Buffer_0xXX_Lvl_1_data[((uint8_t) 4U)] = ((uint32_t) Function_Call_E47D06F8_0);
                    
                    DM1_DTC_Buffer_0xXX_Lvl_1_data[((uint8_t) 5U)] = ((uint32_t) Function_Call_E47D06F8_1);
                    
                    /* // FMI */
                    
                }
                
            }
            else
            {
                /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse multi DTC */
                
                for(For_1CA819A6 = 0U; For_1CA819A6 < (TotalDTC_0xXX_data); ++For_1CA819A6)
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse multi DTC\Parse DTC codes */
                    DM1_Index_0xXX_data = For_1CA819A6;
                    
                    if(0U != (((CAN_InBox_SA_data) == ((uint8_t) 90U) )? 1U : 0U))
                    {
                        uint8_t Add_6B712429;
                        uint8_t Multiply_7F0038DD;
                        double_t Function_Call_CCA8738A_0;
                        double_t Function_Call_CCA8738A_1;
                        uint8_t Add_83E8BF1B;
                        uint8_t Multiply_8C775979;
                        uint8_t Add_A56253C2;
                        uint8_t Multiply_C4600115;
                        /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse multi DTC\Parse DTC codes\SA: 0x5A */
                        
                        /* // Total */
                        
                        DM1_DTC_Buffet_0x5A_data[((uint8_t) 0U)] = ((uint32_t) (TotalDTC_0xXX_data));
                        
                        /* // SA */
                        
                        Add_6B712429 = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        DM1_DTC_Buffet_0x5A_data[(((uint8_t)(((int16_t) Add_6B712429) * ((int16_t) ((uint8_t) 3U)))))] = ((uint32_t) (CAN_InBox_SA_data));
                        
                        Multiply_7F0038DD = (uint8_t)(((int16_t) (DM1_Index_0xXX_data)) * ((int16_t) ((uint8_t) 4U)));
                        
                        Function_Call_CCA8738A_0 = API_CAN_WriteSPNandFMI(DM1_Buffer_0xXX_data, (((double_t) (((uint8_t)(Multiply_7F0038DD + ((uint8_t) 2U)))))), (((double_t) ((uint8_t) 0U))), (((double_t) ((uint8_t) 24U))), &Function_Call_CCA8738A_1);
                        
                        Add_83E8BF1B = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        Multiply_8C775979 = (uint8_t)(((int16_t) Add_83E8BF1B) * ((int16_t) ((uint8_t) 3U)));
                        
                        DM1_DTC_Buffet_0x5A_data[((((uint8_t)(Multiply_8C775979 + ((uint8_t) 1U)))))] = ((uint32_t) Function_Call_CCA8738A_0);
                        
                        Add_A56253C2 = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        Multiply_C4600115 = (uint8_t)(((int16_t) Add_A56253C2) * ((int16_t) ((uint8_t) 3U)));
                        
                        DM1_DTC_Buffet_0x5A_data[((((uint8_t)(Multiply_C4600115 + ((uint8_t) 2U)))))] = ((uint32_t) Function_Call_CCA8738A_1);
                        
                        /* // SPN */
                        
                        /* // FMI */
                        
                    }
                    else if(0U != (((CAN_InBox_SA_data) == ((uint8_t) 11U) )? 1U : 0U))
                    {
                        uint8_t Add_264DD9AD;
                        uint8_t Multiply_51DA389B;
                        double_t Function_Call_DDF973BE_0;
                        double_t Function_Call_DDF973BE_1;
                        uint8_t Add_3B9CBE77;
                        uint8_t Multiply_7249536E;
                        uint8_t Add_8823C2A7;
                        uint8_t Multiply_2BC4E30F;
                        /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse multi DTC\Parse DTC codes\SA: 0x0B */
                        
                        /* // Total */
                        
                        DM1_DTC_Buffet_0x0B_data[((uint8_t) 0U)] = ((uint32_t) (TotalDTC_0xXX_data));
                        
                        /* // SA */
                        
                        Add_264DD9AD = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        DM1_DTC_Buffet_0x0B_data[(((uint8_t)(((int16_t) Add_264DD9AD) * ((int16_t) ((uint8_t) 3U)))))] = ((uint32_t) (CAN_InBox_SA_data));
                        
                        Multiply_51DA389B = (uint8_t)(((int16_t) (DM1_Index_0xXX_data)) * ((int16_t) ((uint8_t) 4U)));
                        
                        Function_Call_DDF973BE_0 = API_CAN_WriteSPNandFMI(DM1_Buffer_0xXX_data, (((double_t) (((uint8_t)(Multiply_51DA389B + ((uint8_t) 2U)))))), (((double_t) ((uint8_t) 0U))), (((double_t) ((uint8_t) 24U))), &Function_Call_DDF973BE_1);
                        
                        Add_3B9CBE77 = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        Multiply_7249536E = (uint8_t)(((int16_t) Add_3B9CBE77) * ((int16_t) ((uint8_t) 3U)));
                        
                        DM1_DTC_Buffet_0x0B_data[((((uint8_t)(Multiply_7249536E + ((uint8_t) 1U)))))] = ((uint32_t) Function_Call_DDF973BE_0);
                        
                        Add_8823C2A7 = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        Multiply_2BC4E30F = (uint8_t)(((int16_t) Add_8823C2A7) * ((int16_t) ((uint8_t) 3U)));
                        
                        DM1_DTC_Buffet_0x0B_data[((((uint8_t)(Multiply_2BC4E30F + ((uint8_t) 2U)))))] = ((uint32_t) Function_Call_DDF973BE_1);
                        
                        /* // SPN */
                        
                        /* // FMI */
                        
                    }
                    else
                    {
                        uint8_t Add_F6259584;
                        uint8_t Multiply_98F9DEB2;
                        double_t Function_Call_01F1F191_0;
                        double_t Function_Call_01F1F191_1;
                        uint8_t Add_4BABD36C;
                        uint8_t Multiply_EBCCFF89;
                        uint8_t Add_8AC2F91C;
                        uint8_t Multiply_A814BB8D;
                        /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Parse multi DTC\Parse DTC codes\SA: 0xXX */
                        
                        OtherSA_DTC_Flag_data = ((uint8_t) 1U);
                        
                        /* // Total */
                        
                        DM1_DTC_Buffer_0xXX_Lvl_1_data[((uint8_t) 0U)] = ((uint32_t) (TotalDTC_0xXX_data));
                        
                        /* // SA */
                        
                        Add_F6259584 = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        DM1_DTC_Buffer_0xXX_Lvl_1_data[(((uint8_t)(((int16_t) Add_F6259584) * ((int16_t) ((uint8_t) 3U)))))] = ((uint32_t) (CAN_InBox_SA_data));
                        
                        Multiply_98F9DEB2 = (uint8_t)(((int16_t) (DM1_Index_0xXX_data)) * ((int16_t) ((uint8_t) 4U)));
                        
                        Function_Call_01F1F191_0 = API_CAN_WriteSPNandFMI(DM1_Buffer_0xXX_data, (((double_t) (((uint8_t)(Multiply_98F9DEB2 + ((uint8_t) 2U)))))), (((double_t) ((uint8_t) 0U))), (((double_t) ((uint8_t) 24U))), &Function_Call_01F1F191_1);
                        
                        Add_4BABD36C = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        Multiply_EBCCFF89 = (uint8_t)(((int16_t) Add_4BABD36C) * ((int16_t) ((uint8_t) 3U)));
                        
                        DM1_DTC_Buffer_0xXX_Lvl_1_data[((((uint8_t)(Multiply_EBCCFF89 + ((uint8_t) 1U)))))] = ((uint32_t) Function_Call_01F1F191_0);
                        
                        Add_8AC2F91C = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        Multiply_A814BB8D = (uint8_t)(((int16_t) Add_8AC2F91C) * ((int16_t) ((uint8_t) 3U)));
                        
                        DM1_DTC_Buffer_0xXX_Lvl_1_data[((((uint8_t)(Multiply_A814BB8D + ((uint8_t) 2U)))))] = ((uint32_t) Function_Call_01F1F191_1);
                        
                        /* // SPN */
                        
                        /* // FMI */
                        
                    }
                    
                }
                
            }
            
            {
                /* / * API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs * / */
            
                if((CAN_InBox_SA_data) == ((uint8_t) 0U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps,
SPN and FMI
0x00 */
                    
                    for(For_8241BA6E = 0U; For_8241BA6E < (TotalDTC_0xXX_data); ++For_8241BA6E)
                    {
                        uint8_t Multiply_1C73C272;
                        double_t Function_Call_B0E26170_0;
                        double_t Function_Call_B0E26170_1;
                        uint8_t Compare_4EC0B100;
                        uint8_t Compare_BE9D51A9;
                        uint8_t Compare_DE234E7E;
                        uint8_t Compare_34E5879D;
                        uint8_t Or_31596511;
                        uint32_t Direct_Switch_9261BB00;
                        uint8_t Compare_23C3CFEB;
                        uint8_t Compare_440CC5F4;
                        uint8_t Compare_B58CB0D7;
                        uint8_t Compare_EB3E6344;
                        uint8_t Or_015A1A7E;
                        uint32_t Direct_Switch_099F1873;
                        uint8_t Compare_EDA6FFFD;
                        uint8_t Compare_37CF01F4;
                        uint8_t Compare_4505AAD9;
                        uint8_t Compare_7A749404;
                        uint8_t Or_3AA0939F;
                        uint32_t Direct_Switch_CA3A8B52;
                        /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps,
SPN and FMI
0x00\Parse DTC codes */
                        DM1_Index_0xXX_data = For_8241BA6E;
                        
                        Multiply_1C73C272 = (uint8_t)(((int16_t) (DM1_Index_0xXX_data)) * ((int16_t) ((uint8_t) 4U)));
                        
                        Function_Call_B0E26170_0 = API_CAN_WriteSPNandFMI(DM1_Buffer_0xXX_data, (((double_t) (((uint8_t)(Multiply_1C73C272 + ((uint8_t) 2U)))))), (((double_t) ((uint8_t) 0U))), (((double_t) ((uint8_t) 24U))), &Function_Call_B0E26170_1);
                        
                        Compare_4EC0B100 = (Function_Call_B0E26170_0 == ((double_t) ((uint8_t) 100U)) )? 1U : 0U;
                        
                        Compare_BE9D51A9 = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 1U)) )? 1U : 0U;
                        
                        Compare_DE234E7E = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 17U)) )? 1U : 0U;
                        
                        Compare_34E5879D = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 18U)) )? 1U : 0U;
                        
                        Or_31596511 = ((0U != Compare_BE9D51A9) || (0U != Compare_DE234E7E) || (0U != Compare_34E5879D)) ? 1U : 0U;
                        
                        if(0U == Compare_4EC0B100)
                        {
                            Direct_Switch_9261BB00 = (((uint32_t) ((uint8_t) 0U)));
                        }
                        else
                        {
                            Direct_Switch_9261BB00 = (((uint32_t) (((0U != Compare_4EC0B100) && (0U != Or_31596511)) ? 1U : 0U)));
                        }
                        
                        DM1_EngOilPresLow_0x00_data = ((uint8_t) Direct_Switch_9261BB00);
                        
                        Compare_23C3CFEB = (Function_Call_B0E26170_0 == ((double_t) ((uint8_t) 110U)) )? 1U : 0U;
                        
                        Compare_440CC5F4 = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 0U)) )? 1U : 0U;
                        
                        Compare_B58CB0D7 = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 15U)) )? 1U : 0U;
                        
                        Compare_EB3E6344 = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 16U)) )? 1U : 0U;
                        
                        Or_015A1A7E = ((0U != Compare_440CC5F4) || (0U != Compare_B58CB0D7) || (0U != Compare_EB3E6344)) ? 1U : 0U;
                        
                        if(0U == Compare_23C3CFEB)
                        {
                            Direct_Switch_099F1873 = (((uint32_t) ((uint8_t) 0U)));
                        }
                        else
                        {
                            Direct_Switch_099F1873 = (((uint32_t) (((0U != Compare_23C3CFEB) && (0U != Or_015A1A7E)) ? 1U : 0U)));
                        }
                        
                        DM1_CoolantTempError_0x00_data = ((uint8_t) Direct_Switch_099F1873);
                        
                        Compare_EDA6FFFD = (Function_Call_B0E26170_0 == ((double_t) ((uint8_t) 175U)) )? 1U : 0U;
                        
                        Compare_37CF01F4 = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 0U)) )? 1U : 0U;
                        
                        Compare_4505AAD9 = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 15U)) )? 1U : 0U;
                        
                        Compare_7A749404 = (Function_Call_B0E26170_1 == ((double_t) ((uint8_t) 16U)) )? 1U : 0U;
                        
                        Or_3AA0939F = ((0U != Compare_37CF01F4) || (0U != Compare_4505AAD9) || (0U != Compare_7A749404)) ? 1U : 0U;
                        
                        if(0U == Compare_EDA6FFFD)
                        {
                            Direct_Switch_CA3A8B52 = (((uint32_t) ((uint8_t) 0U)));
                        }
                        else
                        {
                            Direct_Switch_CA3A8B52 = (((uint32_t) (((0U != Compare_EDA6FFFD) && (0U != Or_3AA0939F)) ? 1U : 0U)));
                        }
                        
                        DM1_EngOilTempError_0x00_data = ((uint8_t) Direct_Switch_CA3A8B52);
                        
                        /* // SPN */
                        
                        /* // FMI */
                        
                    }
                    
                    DM1_EngWarning_0x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_EngError_0x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                    DM1_ExhaustError_0x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 3U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps,
SPN and FMI
0x03 */
                    
                    for(For_B1D387EF = 0U; For_B1D387EF < (TotalDTC_0xXX_data); ++For_B1D387EF)
                    {
                        uint8_t Multiply_B9FB02C7;
                        double_t Function_Call_1EF562B8_0;
                        double_t Function_Call_1EF562B8_1;
                        uint8_t Compare_B802CE92;
                        uint8_t Compare_31A37DB3;
                        uint32_t Direct_Switch_62A7D797;
                        /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps,
SPN and FMI
0x03\Parse DTC codes */
                        DM1_Index_0xXX_data = For_B1D387EF;
                        
                        Multiply_B9FB02C7 = (uint8_t)(((int16_t) (DM1_Index_0xXX_data)) * ((int16_t) ((uint8_t) 4U)));
                        
                        Function_Call_1EF562B8_0 = API_CAN_WriteSPNandFMI(DM1_Buffer_0xXX_data, (((double_t) (((uint8_t)(Multiply_B9FB02C7 + ((uint8_t) 2U)))))), (((double_t) ((uint8_t) 0U))), (((double_t) ((uint8_t) 24U))), &Function_Call_1EF562B8_1);
                        
                        Compare_B802CE92 = (Function_Call_1EF562B8_0 == ((double_t) ((uint8_t) 177U)) )? 1U : 0U;
                        
                        Compare_31A37DB3 = (Function_Call_1EF562B8_1 == ((double_t) ((uint8_t) 0U)) )? 1U : 0U;
                        
                        if(0U == Compare_B802CE92)
                        {
                            Direct_Switch_62A7D797 = (((uint32_t) ((uint8_t) 0U)));
                        }
                        else
                        {
                            Direct_Switch_62A7D797 = (((uint32_t) (((0U != Compare_B802CE92) && (0U != Compare_31A37DB3)) ? 1U : 0U)));
                        }
                        
                        DM1_TransTempError_0x03_data = ((uint8_t) Direct_Switch_62A7D797);
                        
                        /* // SPN */
                        
                        /* // FMI */
                        
                    }
                    
                    DM1_TransWarning_0x03_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
                    
                    DM1_TransError_0x03_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 11U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0x0B */
                    
                    DM1_StopError_0x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                    DM1_StopFlash_0x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                    DM1_Warning_0x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_WarningFlash_0x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 47U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0x2F */
                    
                    DM1_SuspenError987_0x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
                    
                    DM1_SuspenWarning_0x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_SuspenError623_0x2F_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 61U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0x3D */
                    
                    DM1_ExhaustError_0x3D_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_EngWarning_0x3D_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 73U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0x49 */
                    
                    DM1_HVBatWarning_0x49_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_HVBatError_0x49_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 80U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0x50 */
                    
                    DM1_ParkingBrakeWarning_0x50_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_ParkingBrakeError_0x50_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 90U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0x5A */
                    
                    DM1_StopError_0x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                    DM1_StopFlash_0x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                    DM1_Warning_0x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_WarningFlash_0x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 188U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0xBC */
                    
                    DM1_BatteryHVError_0xBC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 238U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0xEE */
                    
                    DM1_TachWarning_0xEE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_TachError_0xEE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                }
                
                if((CAN_InBox_SA_data) == ((uint8_t) 239U))
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Lamps and FMIs of SPNs\Lamps
0xEF */
                    
                    DM1_MotorWarnig_0xEF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
                    
                    DM1_MotorError_0xEF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(DM1_Buffer_0xXX_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
                    
                }
                
            }
            if((OtherSA_DTC_Flag_data) != 0U)
            {
                /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy pre buf other SA of DTC */
                
                OtherSA_DTC_Flag_data = ((uint8_t) 0U);
                
                for(For_3ADAE7D0 = 0U; For_3ADAE7D0 < (DM1_DTC_Buffer_0xXX_Lvl_1_data[((uint32_t) 0U)]); ++For_3ADAE7D0)
                {
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy pre buf other SA of DTC\Compare 1 */
                    DM1_Index_0xXX_data = (uint8_t) For_3ADAE7D0;
                    
                    NewDTC_Flag_data = ((uint8_t) 1U);
                    
                    for(For_BDF47141 = 0U; For_BDF47141 < ((uint8_t) 10U); ++For_BDF47141)
                    {
                        uint8_t Add_982F9F39;
                        uint8_t Multiply_7C33B389;
                        uint8_t Add_7D1AB754;
                        uint8_t Multiply_9A0562F7;
                        uint32_t Compare_C39895B0;
                        uint32_t Compare_62C674B4;
                        uint32_t Compare_51E7E07D;
                        uint32_t And_5137761C;
                        /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy pre buf other SA of DTC\Compare 1\Compare 2 */
                        
                        Add_982F9F39 = ((uint8_t)((DM1_indexFor_data) + ((uint8_t) 1U)));
                        
                        Multiply_7C33B389 = (uint8_t)(((int16_t) Add_982F9F39) * ((int16_t) ((uint8_t) 3U)));
                        
                        Add_7D1AB754 = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        Multiply_9A0562F7 = (uint8_t)(((int16_t) Add_7D1AB754) * ((int16_t) ((uint8_t) 3U)));
                        
                        Compare_C39895B0 = ((DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_7C33B389 + ((uint8_t) 0U)))))]) == (DM1_DTC_Buffer_0xXX_Lvl_1_data[((((uint8_t)(Multiply_9A0562F7 + ((uint8_t) 0U)))))]) )? 1U : 0U;
                        
                        Compare_62C674B4 = ((DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_7C33B389 + ((uint8_t) 1U)))))]) == (DM1_DTC_Buffer_0xXX_Lvl_1_data[((((uint8_t)(Multiply_9A0562F7 + ((uint8_t) 1U)))))]) )? 1U : 0U;
                        
                        Compare_51E7E07D = ((DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_7C33B389 + ((uint8_t) 2U)))))]) == (DM1_DTC_Buffer_0xXX_Lvl_1_data[((((uint8_t)(Multiply_9A0562F7 + ((uint8_t) 2U)))))]) )? 1U : 0U;
                        
                        And_5137761C = ((0U != Compare_C39895B0) && (0U != Compare_62C674B4) && (0U != Compare_51E7E07D)) ? 1U : 0U;
                        
                        if(And_5137761C != 0U)
                        {
                            /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy pre buf other SA of DTC\Compare 1\Compare 2\Есть дубликат */
                            
                            NewDTC_Flag_data = ((uint8_t) 0U);
                            
                        }
                        
                        /* // SA */
                        
                        /* // SPN */
                        
                        /* // FMI */
                        
                        /* // SA */
                        
                        /* // SPN */
                        
                        /* // FMI */
                        
                    }
                    
                    if((NewDTC_Flag_data) == ((uint8_t) 1U))
                    {
                        uint8_t Add_B27C04DC;
                        uint8_t Multiply_183DA3E5;
                        uint8_t Add_18D02482;
                        uint8_t Multiply_061EDFC0;
                        uint32_t Add_DFE4C557;
                        uint32_t Direct_Switch_71C0BB63;
                        /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy pre buf other SA of DTC\Compare 1\Container */
                        
                        VarTest_CopyDTC_0xXX_data = ((uint8_t) 1U);
                        
                        Add_B27C04DC = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                        
                        Multiply_183DA3E5 = (uint8_t)(((int16_t) Add_B27C04DC) * ((int16_t) ((uint8_t) 3U)));
                        
                        Add_18D02482 = ((uint8_t)((PointDTC_lvl_2_data) + ((uint8_t) 1U)));
                        
                        Multiply_061EDFC0 = (uint8_t)(((int16_t) Add_18D02482) * ((int16_t) ((uint8_t) 3U)));
                        
                        DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_061EDFC0 + ((uint8_t) 0U)))))] = (DM1_DTC_Buffer_0xXX_Lvl_1_data[((((uint8_t)(Multiply_183DA3E5 + ((uint8_t) 0U)))))]);
                        
                        DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_061EDFC0 + ((uint8_t) 1U)))))] = (DM1_DTC_Buffer_0xXX_Lvl_1_data[((((uint8_t)(Multiply_183DA3E5 + ((uint8_t) 1U)))))]);
                        
                        DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_061EDFC0 + ((uint8_t) 2U)))))] = (DM1_DTC_Buffer_0xXX_Lvl_1_data[((((uint8_t)(Multiply_183DA3E5 + ((uint8_t) 2U)))))]);
                        
                        /* // SA */
                        
                        /* // SPN */
                        
                        /* // FMI */
                        
                        Add_DFE4C557 = ((uint32_t)(((uint32_t) (PointDTC_lvl_2_data)) + ((uint32_t) ((uint8_t) 1U))));
                        
                        if(0U == ((Add_DFE4C557 > ((uint32_t) ((uint8_t) 9U)) )? 1U : 0U))
                        {
                            Direct_Switch_71C0BB63 = Add_DFE4C557;
                        }
                        else
                        {
                            Direct_Switch_71C0BB63 = (((uint32_t) ((uint8_t) 0U)));
                        }
                        
                        PointDTC_lvl_2_data = ((uint8_t) Direct_Switch_71C0BB63);
                        
                    }
                    
                }
                
                DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 0U)] = ((uint32_t) ((uint8_t) 0U));
                
                for(For_5F591C0A = 0U; For_5F591C0A < ((uint8_t) 10U); ++For_5F591C0A)
                {
                    uint8_t Add_94317249;
                    uint8_t Multiply_857E9D27;
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy pre buf other SA of DTC\Count DTC from SA 0xXX */
                    
                    Add_94317249 = ((uint8_t)((DM1_indexFor_data) + ((uint8_t) 1U)));
                    
                    Multiply_857E9D27 = (uint8_t)(((int16_t) Add_94317249) * ((int16_t) ((uint8_t) 3U)));
                    
                    if(((uint8_t) 0U) != ((uint8_t) (((uint32_t)((DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_857E9D27 + ((uint8_t) 1U)))))]) + (DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_857E9D27 + ((uint8_t) 2U)))))]) + (DM1_DTC_Buffer_0xXX_Lvl_2_data[Multiply_857E9D27]))))))
                    {
                        uint32_t Add_9C83E095;
                        uint32_t Direct_Switch_5433B580;
                        /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy pre buf other SA of DTC\Count DTC from SA 0xXX\Increment */
                        
                        Add_9C83E095 = ((uint32_t)((DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 0U)]) + ((uint32_t) ((uint8_t) 1U))));
                        
                        if(0U == ((Add_9C83E095 > ((uint32_t) ((uint8_t) 10U)) )? 1U : 0U))
                        {
                            Direct_Switch_5433B580 = Add_9C83E095;
                        }
                        else
                        {
                            Direct_Switch_5433B580 = (((uint32_t) ((uint8_t) 10U)));
                        }
                        
                        DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 0U)] = Direct_Switch_5433B580;
                        
                    }
                    
                    /* // SA */
                    
                    /* // SPN */
                    
                    /* // FMI */
                    
                }
                
            }
            
            DM1_DTC_Buffet_0x5A_data[((uint8_t) 2U)] = ((uint32_t) ((uint8_t) 0U));
            
            DM1_DTC_Buffet_0x0B_data[((uint8_t) 2U)] = ((uint32_t) ((uint8_t) 0U));
            
            DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 2U)] = ((uint32_t) ((uint8_t) 0U));
            
            Add_946147A0 = ((uint8_t)(((uint8_t) (DM1_DTC_Buffet_0x5A_data[((uint8_t) 0U)])) + ((uint8_t) (DM1_DTC_Buffet_0x0B_data[((uint8_t) 0U)])) + ((uint8_t) (DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 0U)]))));
            
            DM1_DTC_Buffet_Common_data[((uint8_t) 0U)] = ((uint32_t) Add_946147A0);
            
            for(For_B44C4EBC = 0U; For_B44C4EBC < Add_946147A0; ++For_B44C4EBC)
            {
                /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy to common buf */
                DM1_Index_0xXX_data = For_B44C4EBC;
                
                if(0U != (((DM1_DTC_Buffet_0x5A_data[((uint8_t) 0U)]) > (DM1_DTC_Buffet_0x5A_data[((uint8_t) 2U)]) )? 1U : 0U))
                {
                    uint8_t Add_0ECE98E3;
                    uint8_t Multiply_3B6CC9A5;
                    uint8_t Add_E474B944;
                    uint8_t Multiply_D69220B4;
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy to common buf\Copy from 0x5A to common buf */
                    
                    Add_0ECE98E3 = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                    
                    Multiply_3B6CC9A5 = (uint8_t)(((int16_t) Add_0ECE98E3) * ((int16_t) ((uint8_t) 3U)));
                    
                    Add_E474B944 = ((uint8_t)(((uint8_t) (DM1_DTC_Buffet_0x5A_data[((uint8_t) 2U)])) + ((uint8_t) 1U)));
                    
                    Multiply_D69220B4 = (uint8_t)(((int16_t) Add_E474B944) * ((int16_t) ((uint8_t) 3U)));
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_3B6CC9A5 + ((uint8_t) 0U)))))] = (DM1_DTC_Buffet_0x5A_data[((((uint8_t)(Multiply_D69220B4 + ((uint8_t) 0U)))))]);
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_3B6CC9A5 + ((uint8_t) 1U)))))] = (DM1_DTC_Buffet_0x5A_data[((((uint8_t)(Multiply_D69220B4 + ((uint8_t) 1U)))))]);
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_3B6CC9A5 + ((uint8_t) 2U)))))] = (DM1_DTC_Buffet_0x5A_data[((((uint8_t)(Multiply_D69220B4 + ((uint8_t) 2U)))))]);
                    
                    /* // SA */
                    
                    /* // SPN */
                    
                    /* // FMI */
                    
                    DM1_DTC_Buffet_0x5A_data[((uint8_t) 2U)] = ((uint32_t) (((uint8_t)(((uint8_t) (DM1_DTC_Buffet_0x5A_data[((uint8_t) 2U)])) + ((uint8_t) 1U)))));
                    
                }
                else if(0U != (((DM1_DTC_Buffet_0x0B_data[((uint8_t) 0U)]) > (DM1_DTC_Buffet_0x0B_data[((uint8_t) 2U)]) )? 1U : 0U))
                {
                    uint8_t Add_9B47165F;
                    uint8_t Multiply_0AC12F0A;
                    uint8_t Add_B8B84813;
                    uint8_t Multiply_496F0169;
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy to common buf\Copy from 0x0B to common buf */
                    
                    Add_9B47165F = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                    
                    Multiply_0AC12F0A = (uint8_t)(((int16_t) Add_9B47165F) * ((int16_t) ((uint8_t) 3U)));
                    
                    Add_B8B84813 = ((uint8_t)(((uint8_t) (DM1_DTC_Buffet_0x0B_data[((uint8_t) 2U)])) + ((uint8_t) 1U)));
                    
                    Multiply_496F0169 = (uint8_t)(((int16_t) Add_B8B84813) * ((int16_t) ((uint8_t) 3U)));
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_0AC12F0A + ((uint8_t) 0U)))))] = (DM1_DTC_Buffet_0x0B_data[((((uint8_t)(Multiply_496F0169 + ((uint8_t) 0U)))))]);
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_0AC12F0A + ((uint8_t) 1U)))))] = (DM1_DTC_Buffet_0x0B_data[((((uint8_t)(Multiply_496F0169 + ((uint8_t) 1U)))))]);
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_0AC12F0A + ((uint8_t) 2U)))))] = (DM1_DTC_Buffet_0x0B_data[((((uint8_t)(Multiply_496F0169 + ((uint8_t) 2U)))))]);
                    
                    /* // SA */
                    
                    /* // SPN */
                    
                    /* // FMI */
                    
                    DM1_DTC_Buffet_0x0B_data[((uint8_t) 2U)] = ((uint32_t) (((uint8_t)(((uint8_t) (DM1_DTC_Buffet_0x0B_data[((uint8_t) 2U)])) + ((uint8_t) 1U)))));
                    
                }
                else if(0U != (((DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 0U)]) > (DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 2U)]) )? 1U : 0U))
                {
                    uint8_t Add_B7A68709;
                    uint8_t Multiply_B925972E;
                    uint8_t Add_43F4A155;
                    uint8_t Multiply_36EF4B53;
                    /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Parse local DM1 buffer\Copy to common buf\Copy from 0xXX to common buf */
                    
                    Add_B7A68709 = ((uint8_t)((DM1_Index_0xXX_data) + ((uint8_t) 1U)));
                    
                    Multiply_B925972E = (uint8_t)(((int16_t) Add_B7A68709) * ((int16_t) ((uint8_t) 3U)));
                    
                    Add_43F4A155 = ((uint8_t)(((uint8_t) (DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 2U)])) + ((uint8_t) 1U)));
                    
                    Multiply_36EF4B53 = (uint8_t)(((int16_t) Add_43F4A155) * ((int16_t) ((uint8_t) 3U)));
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_B925972E + ((uint8_t) 0U)))))] = (DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_36EF4B53 + ((uint8_t) 0U)))))]);
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_B925972E + ((uint8_t) 1U)))))] = (DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_36EF4B53 + ((uint8_t) 1U)))))]);
                    
                    DM1_DTC_Buffet_Common_data[((((uint8_t)(Multiply_B925972E + ((uint8_t) 2U)))))] = (DM1_DTC_Buffer_0xXX_Lvl_2_data[((((uint8_t)(Multiply_36EF4B53 + ((uint8_t) 2U)))))]);
                    
                    /* // SA */
                    
                    /* // SPN */
                    
                    /* // FMI */
                    
                    DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 2U)] = ((uint32_t) (((uint8_t)(((uint8_t) (DM1_DTC_Buffer_0xXX_Lvl_2_data[((uint8_t) 2U)])) + ((uint8_t) 1U)))));
                    
                }
                else
                {
                    /* This code block intentionally left blank */
                }
                
            }
            
            CycleTime_DM01_0xXX_data = ((int32_t) 0);
            
            NoCANMessagesFlag1_data = ((uint8_t) 0U);
            
        }
        else
        {
            int32_t Read_Parameter_4515FCF9;
            int32_t Add_F302292A;
            int32_t Saturation_702C5F8C;
            /* API_CAN_Analyze\DM01_0xXX
PGN FECA
SA XX\Increment Timer */
            
            Read_Parameter_4515FCF9 = CycleTime_DM01_0xXX_data;
            
            Add_F302292A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_4515FCF9));
            
            Saturation_702C5F8C = Add_F302292A;
            if(Saturation_702C5F8C < Read_Parameter_4515FCF9)
            {
                Saturation_702C5F8C = Read_Parameter_4515FCF9;
            }
            else if(Saturation_702C5F8C > Add_F302292A)
            {
                Saturation_702C5F8C = Add_F302292A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            CycleTime_DM01_0xXX_data = Saturation_702C5F8C;
            
        }
        
        DM1_ReadyFlag_0xXX_data = ((uint8_t) 0U);
        
    }

    /* // B */

    {
        /* / * API_CAN_Analyze\BCH1
PGN FD15
Charge * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419239258U))
        {
            /* API_CAN_Analyze\BCH1
PGN FD15
Charge\Receive Message */
            
            Time_FD15_x5A_data = ((int32_t) 0);
            
            TimeOut_FD15_x5A_data = ((uint8_t) 0U);
            
            ChargeConnectorHV_0x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            ChargeStateHV_0x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_175D7CB9;
            int32_t Add_D8FA759F;
            int32_t Saturation_7737C7CF;
            /* API_CAN_Analyze\BCH1
PGN FD15
Charge\Increment Timer */
            
            Read_Parameter_175D7CB9 = Time_FD15_x5A_data;
            
            Add_D8FA759F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_175D7CB9));
            
            Saturation_7737C7CF = Add_D8FA759F;
            if(Saturation_7737C7CF < Read_Parameter_175D7CB9)
            {
                Saturation_7737C7CF = Read_Parameter_175D7CB9;
            }
            else if(Saturation_7737C7CF > Add_D8FA759F)
            {
                Saturation_7737C7CF = Add_D8FA759F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD15_x5A_data = Saturation_7737C7CF;
            
        }
        
        if((Time_FD15_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\BCH1
PGN FD15
Charge\Reset signals */
            
            TimeOut_FD15_x5A_data = ((uint8_t) 1U);
            
            ChargeStateHV_0x00_data = ((uint8_t) 0U);
            
            ChargeConnectorHV_0x00_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // C */

    {
        /* / * API_CAN_Analyze\CCSS_id00
PGN FEED
SpeedLimit * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419360000U))
        {
            /* API_CAN_Analyze\CCSS_id00
PGN FEED
SpeedLimit\Receive Message */
            
            Time_FEED_x00_data = ((int32_t) 0);
            
            TimeOut_FEED_x00_data = ((uint8_t) 0U);
            
            SpeedLimit_0x00_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_6C7F10BA;
            int32_t Add_698B3377;
            int32_t Saturation_EB009AAF;
            /* API_CAN_Analyze\CCSS_id00
PGN FEED
SpeedLimit\Increment Timer */
            
            Read_Parameter_6C7F10BA = Time_FEED_x00_data;
            
            Add_698B3377 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_6C7F10BA));
            
            Saturation_EB009AAF = Add_698B3377;
            if(Saturation_EB009AAF < Read_Parameter_6C7F10BA)
            {
                Saturation_EB009AAF = Read_Parameter_6C7F10BA;
            }
            else if(Saturation_EB009AAF > Add_698B3377)
            {
                Saturation_EB009AAF = Add_698B3377;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEED_x00_data = Saturation_EB009AAF;
            
        }
        
        if((Time_FEED_x00_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CCSS_id00
PGN FEED
SpeedLimit\Reset signals */
            
            TimeOut_FEED_x00_data = ((uint8_t) 1U);
            
            SpeedLimit_0x00_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\CCSI1 (X) CACI
PGN FDE1
AirConditionerPump * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419291482U))
        {
            /* API_CAN_Analyze\CCSI1 (X) CACI
PGN FDE1
AirConditionerPump\Receive Message */
            
            Time_FDE1_x5A_data = ((int32_t) 0);
            
            TimeOut_FDE1_x5A_data = ((uint8_t) 0U);
            
            ClimateCondComp_0x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_1D997550;
            int32_t Add_F3D195EB;
            int32_t Saturation_6DEBE8AA;
            /* API_CAN_Analyze\CCSI1 (X) CACI
PGN FDE1
AirConditionerPump\Increment Timer */
            
            Read_Parameter_1D997550 = Time_FDE1_x5A_data;
            
            Add_F3D195EB = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_1D997550));
            
            Saturation_6DEBE8AA = Add_F3D195EB;
            if(Saturation_6DEBE8AA < Read_Parameter_1D997550)
            {
                Saturation_6DEBE8AA = Read_Parameter_1D997550;
            }
            else if(Saturation_6DEBE8AA > Add_F3D195EB)
            {
                Saturation_6DEBE8AA = Add_F3D195EB;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FDE1_x5A_data = Saturation_6DEBE8AA;
            
        }
        
        if((Time_FDE1_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CCSI1 (X) CACI
PGN FDE1
AirConditionerPump\Reset signals */
            
            TimeOut_FDE1_x5A_data = ((uint8_t) 1U);
            
            ClimateCondComp_0x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419361054U))
        {
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Receive Message */
            
            Time_FEF1_x1E_data = ((int32_t) 0);
            
            TimeOut_FEF1_x1E_data = ((uint8_t) 0U);
            
            ParkingBrake_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_355D9E7D;
            int32_t Add_5BACCB1C;
            int32_t Saturation_22F7FAF7;
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Increment Timer */
            
            Read_Parameter_355D9E7D = Time_FEF1_x1E_data;
            
            Add_5BACCB1C = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_355D9E7D));
            
            Saturation_22F7FAF7 = Add_5BACCB1C;
            if(Saturation_22F7FAF7 < Read_Parameter_355D9E7D)
            {
                Saturation_22F7FAF7 = Read_Parameter_355D9E7D;
            }
            else if(Saturation_22F7FAF7 > Add_5BACCB1C)
            {
                Saturation_22F7FAF7 = Add_5BACCB1C;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF1_x1E_data = Saturation_22F7FAF7;
            
        }
        
        if((Time_FEF1_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Reset signals */
            
            TimeOut_FEF1_x27_data = ((uint8_t) 1U);
            
            ParkingBrake_x1E_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419361063U))
        {
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Receive Message */
            
            Time_FEF1_x27_data = ((int32_t) 0);
            
            TimeOut_FEF1_x27_data = ((uint8_t) 0U);
            
            ParkingBrake_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            SpeedBusWheelOrigin_x27_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            PedalBrake_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_1F336731;
            int32_t Add_3097FBF1;
            int32_t Saturation_720B472A;
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Increment Timer */
            
            Read_Parameter_1F336731 = Time_FEF1_x27_data;
            
            Add_3097FBF1 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_1F336731));
            
            Saturation_720B472A = Add_3097FBF1;
            if(Saturation_720B472A < Read_Parameter_1F336731)
            {
                Saturation_720B472A = Read_Parameter_1F336731;
            }
            else if(Saturation_720B472A > Add_3097FBF1)
            {
                Saturation_720B472A = Add_3097FBF1;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF1_x27_data = Saturation_720B472A;
            
        }
        
        if((Time_FEF1_x27_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Reset signals */
            
            TimeOut_FEF1_x27_data = ((uint8_t) 1U);
            
            ParkingBrake_x27_data = ((uint8_t) 0U);
            
            SpeedBusWheelOrigin_x27_data = ((int32_t) 0);
            
            PedalBrake_x27_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419361024U))
        {
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Receive Message */
            
            Time_FEF1_x00_data = ((int32_t) 0);
            
            TimeOut_FEF1_x00_data = ((uint8_t) 0U);
            
            ParkingBrake_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            SpeedBusWheel_x00_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            CruiseControlActive_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            CruiseControlSwitch_x0_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            PedalBrake_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_E0DEBF35;
            int32_t Add_223E6690;
            int32_t Saturation_B7991749;
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Increment Timer */
            
            Read_Parameter_E0DEBF35 = Time_FEF1_x00_data;
            
            Add_223E6690 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_E0DEBF35));
            
            Saturation_B7991749 = Add_223E6690;
            if(Saturation_B7991749 < Read_Parameter_E0DEBF35)
            {
                Saturation_B7991749 = Read_Parameter_E0DEBF35;
            }
            else if(Saturation_B7991749 > Add_223E6690)
            {
                Saturation_B7991749 = Add_223E6690;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF1_x00_data = Saturation_B7991749;
            
        }
        
        if((Time_FEF1_x00_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed\Reset signals */
            
            TimeOut_FEF1_x00_data = ((uint8_t) 1U);
            
            ParkingBrake_x00_data = ((uint8_t) 0U);
            
            SpeedBusWheel_x00_data = ((int32_t) 0);
            
            PedalBrake_x00_data = ((uint8_t) 0U);
            
            CruiseControlActive_x00_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\CM1_id1E
PGN: E000
Ремень безопасности * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 417333278U))
        {
            /* API_CAN_Analyze\CM1_id1E
PGN: E000
Ремень безопасности\Receive Message */
            
            Time_E000_x1E_data = ((int32_t) 0);
            
            TimeOut_E000_x1E_data = ((uint8_t) 0U);
            
            DriverBelt_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_1F597FE3;
            int32_t Add_A00F2336;
            int32_t Saturation_9B35A8AC;
            /* API_CAN_Analyze\CM1_id1E
PGN: E000
Ремень безопасности\Increment Timer */
            
            Read_Parameter_1F597FE3 = Time_E000_x1E_data;
            
            Add_A00F2336 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_1F597FE3));
            
            Saturation_9B35A8AC = Add_A00F2336;
            if(Saturation_9B35A8AC < Read_Parameter_1F597FE3)
            {
                Saturation_9B35A8AC = Read_Parameter_1F597FE3;
            }
            else if(Saturation_9B35A8AC > Add_A00F2336)
            {
                Saturation_9B35A8AC = Add_A00F2336;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_E000_x1E_data = Saturation_9B35A8AC;
            
        }
        
        if((Time_E000_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CM1_id1E
PGN: E000
Ремень безопасности\Reset signals */
            
            TimeOut_E000_x1E_data = ((uint8_t) 1U);
            
            DriverBelt_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // Параметры КАМАЗ */

    /* // D */

    {
        /* / * API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419176140U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Receive Message */
            
            Time_FC1E_xCC_data = ((int32_t) 0);
            
            TimeOut_FC1E_xCC_data = ((uint8_t) 0U);
            
            Door1Req_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door1EmCoverIn_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door1EmToggleIn_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Door1EmCoverOut_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door1EmToggleOut_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_7E906233;
            int32_t Add_3EB7BF36;
            int32_t Saturation_C26B5A45;
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Increment Timer */
            
            Read_Parameter_7E906233 = Time_FC1E_xCC_data;
            
            Add_3EB7BF36 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_7E906233));
            
            Saturation_C26B5A45 = Add_3EB7BF36;
            if(Saturation_C26B5A45 < Read_Parameter_7E906233)
            {
                Saturation_C26B5A45 = Read_Parameter_7E906233;
            }
            else if(Saturation_C26B5A45 > Add_3EB7BF36)
            {
                Saturation_C26B5A45 = Add_3EB7BF36;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FC1E_xCC_data = Saturation_C26B5A45;
            
        }
        
        if((Time_FC1E_xCC_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Reset signals */
            
            TimeOut_FC1E_xCC_data = ((uint8_t) 1U);
            
            Door1Req_xCC_data = ((uint8_t) 0U);
            
            Door1EmCoverIn_xCC_data = ((uint8_t) 0U);
            
            Door1EmToggleIn_xCC_data = ((uint8_t) 0U);
            
            Door1EmCoverOut_xCC_data = ((uint8_t) 0U);
            
            Door1EmToggleOut_xCC_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419176141U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Receive Message */
            
            Time_FC1E_xCD_data = ((int32_t) 0);
            
            TimeOut_FC1E_xCD_data = ((uint8_t) 0U);
            
            Door2Req_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door2EmCoverIn_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door2EmToggleIn_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Door2EmCoverOut_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door2EmToggleOut_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door2Ramp_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door2ReqDis_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_FA4C5681;
            int32_t Add_F7F3BE92;
            int32_t Saturation_C2161E4D;
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Increment Timer */
            
            Read_Parameter_FA4C5681 = Time_FC1E_xCD_data;
            
            Add_F7F3BE92 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_FA4C5681));
            
            Saturation_C2161E4D = Add_F7F3BE92;
            if(Saturation_C2161E4D < Read_Parameter_FA4C5681)
            {
                Saturation_C2161E4D = Read_Parameter_FA4C5681;
            }
            else if(Saturation_C2161E4D > Add_F7F3BE92)
            {
                Saturation_C2161E4D = Add_F7F3BE92;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FC1E_xCD_data = Saturation_C2161E4D;
            
        }
        
        if((Time_FC1E_xCD_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Reset signals */
            
            TimeOut_FC1E_xCD_data = ((uint8_t) 1U);
            
            Door2Req_xCD_data = ((uint8_t) 0U);
            
            Door2EmCoverIn_xCD_data = ((uint8_t) 0U);
            
            Door2EmToggleIn_xCD_data = ((uint8_t) 0U);
            
            Door2EmCoverOut_xCD_data = ((uint8_t) 0U);
            
            Door2EmToggleOut_xCD_data = ((uint8_t) 0U);
            
            Door2Ramp_xCD_data = ((uint8_t) 0U);
            
            Door2ReqDis_xCD_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419176142U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Receive Message */
            
            Time_FC1E_xCE_data = ((int32_t) 0);
            
            TimeOut_FC1E_xCE_data = ((uint8_t) 0U);
            
            Door3Req_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door3EmCoverIn_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door3EmToggleIn_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Door3EmCoverOut_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door3EmToggleOut_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            AirPres4_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_51AAE65E;
            int32_t Add_1A4FC052;
            int32_t Saturation_ECBAFE3E;
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Increment Timer */
            
            Read_Parameter_51AAE65E = Time_FC1E_xCE_data;
            
            Add_1A4FC052 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_51AAE65E));
            
            Saturation_ECBAFE3E = Add_1A4FC052;
            if(Saturation_ECBAFE3E < Read_Parameter_51AAE65E)
            {
                Saturation_ECBAFE3E = Read_Parameter_51AAE65E;
            }
            else if(Saturation_ECBAFE3E > Add_1A4FC052)
            {
                Saturation_ECBAFE3E = Add_1A4FC052;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FC1E_xCE_data = Saturation_ECBAFE3E;
            
        }
        
        if((Time_FC1E_xCE_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Reset signals */
            
            TimeOut_FC1E_xCE_data = ((uint8_t) 1U);
            
            Door3Req_xCE_data = ((uint8_t) 0U);
            
            Door3EmCoverIn_xCE_data = ((uint8_t) 0U);
            
            Door3EmToggleIn_xCE_data = ((uint8_t) 0U);
            
            Door3EmCoverOut_xCE_data = ((uint8_t) 0U);
            
            Door3EmToggleOut_xCE_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419176143U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Receive Message */
            
            Time_FC1E_xCF_data = ((int32_t) 0);
            
            TimeOut_FC1E_xCF_data = ((uint8_t) 0U);
            
            Door4Req_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door4EmCoverIn_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door4EmToggleIn_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Door4EmCoverOut_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door4EmToggleOut_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_CEDC8C2F;
            int32_t Add_A9FABEBA;
            int32_t Saturation_2FF8BB3F;
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Increment Timer */
            
            Read_Parameter_CEDC8C2F = Time_FC1E_xCF_data;
            
            Add_A9FABEBA = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_CEDC8C2F));
            
            Saturation_2FF8BB3F = Add_A9FABEBA;
            if(Saturation_2FF8BB3F < Read_Parameter_CEDC8C2F)
            {
                Saturation_2FF8BB3F = Read_Parameter_CEDC8C2F;
            }
            else if(Saturation_2FF8BB3F > Add_A9FABEBA)
            {
                Saturation_2FF8BB3F = Add_A9FABEBA;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FC1E_xCF_data = Saturation_2FF8BB3F;
            
        }
        
        if((Time_FC1E_xCF_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FC1E
Запросы на открытие дверей\Reset signals */
            
            TimeOut_FC1E_xCF_data = ((uint8_t) 1U);
            
            Door4Req_xCF_data = ((uint8_t) 0U);
            
            Door4EmCoverIn_xCF_data = ((uint8_t) 0U);
            
            Door4EmToggleIn_xCF_data = ((uint8_t) 0U);
            
            Door4EmCoverOut_xCF_data = ((uint8_t) 0U);
            
            Door4EmToggleOut_xCF_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419241676U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Receive Message */
            
            Time_FD1E_xCC_data = ((int32_t) 0);
            
            TimeOut_FD1E_xCC_data = ((uint8_t) 0U);
            
            Door1Jam1_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Door1Jam2_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door1Jam3_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door1Jam4_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door1Break_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door1Opened_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door1Clousing_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door1Opening_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_A15C0739;
            int32_t Add_B1CD2FB5;
            int32_t Saturation_6C9CC498;
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Increment Timer */
            
            Read_Parameter_A15C0739 = Time_FD1E_xCC_data;
            
            Add_B1CD2FB5 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_A15C0739));
            
            Saturation_6C9CC498 = Add_B1CD2FB5;
            if(Saturation_6C9CC498 < Read_Parameter_A15C0739)
            {
                Saturation_6C9CC498 = Read_Parameter_A15C0739;
            }
            else if(Saturation_6C9CC498 > Add_B1CD2FB5)
            {
                Saturation_6C9CC498 = Add_B1CD2FB5;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD1E_xCC_data = Saturation_6C9CC498;
            
        }
        
        if((Time_FD1E_xCC_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Reset signals */
            
            TimeOut_FD1E_xCC_data = ((uint8_t) 1U);
            
            Door1Jam1_xCC_data = ((uint8_t) 0U);
            
            Door1Jam2_xCC_data = ((uint8_t) 0U);
            
            Door1Jam3_xCC_data = ((uint8_t) 0U);
            
            Door1Jam4_xCC_data = ((uint8_t) 0U);
            
            Door1Break_xCC_data = ((uint8_t) 0U);
            
            Door1Opened_xCC_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419241677U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Receive Message */
            
            Time_FD1E_xCD_data = ((int32_t) 0);
            
            TimeOut_FD1E_xCD_data = ((uint8_t) 0U);
            
            Door2Jam1_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Door2Jam2_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door2Jam3_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door2Jam4_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door2Break_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door2Opened_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door2Clousing_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door2Opening_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_871AB0EE;
            int32_t Add_6AD2E733;
            int32_t Saturation_D9AC7435;
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Increment Timer */
            
            Read_Parameter_871AB0EE = Time_FD1E_xCD_data;
            
            Add_6AD2E733 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_871AB0EE));
            
            Saturation_D9AC7435 = Add_6AD2E733;
            if(Saturation_D9AC7435 < Read_Parameter_871AB0EE)
            {
                Saturation_D9AC7435 = Read_Parameter_871AB0EE;
            }
            else if(Saturation_D9AC7435 > Add_6AD2E733)
            {
                Saturation_D9AC7435 = Add_6AD2E733;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD1E_xCD_data = Saturation_D9AC7435;
            
        }
        
        if((Time_FD1E_xCD_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Reset signals */
            
            TimeOut_FD1E_xCD_data = ((uint8_t) 1U);
            
            Door2Jam1_xCD_data = ((uint8_t) 0U);
            
            Door2Jam2_xCD_data = ((uint8_t) 0U);
            
            Door2Jam3_xCD_data = ((uint8_t) 0U);
            
            Door2Jam4_xCD_data = ((uint8_t) 0U);
            
            Door2Break_xCD_data = ((uint8_t) 0U);
            
            Door2Opened_xCD_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419241678U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Receive Message */
            
            Time_FD1E_xCE_data = ((int32_t) 0);
            
            TimeOut_FD1E_xCE_data = ((uint8_t) 0U);
            
            Door3Jam1_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Door3Jam2_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door3Jam3_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door3Jam4_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door3Break_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door3Opened_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door3Clousing_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door3Opening_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_4A29F1BE;
            int32_t Add_B3C940C3;
            int32_t Saturation_5348A466;
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Increment Timer */
            
            Read_Parameter_4A29F1BE = Time_FD1E_xCC_data;
            
            Add_B3C940C3 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_4A29F1BE));
            
            Saturation_5348A466 = Add_B3C940C3;
            if(Saturation_5348A466 < Read_Parameter_4A29F1BE)
            {
                Saturation_5348A466 = Read_Parameter_4A29F1BE;
            }
            else if(Saturation_5348A466 > Add_B3C940C3)
            {
                Saturation_5348A466 = Add_B3C940C3;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD1E_xCC_data = Saturation_5348A466;
            
        }
        
        if((Time_FD1E_xCE_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Reset signals */
            
            TimeOut_FD1E_xCE_data = ((uint8_t) 1U);
            
            Door3Jam1_xCE_data = ((uint8_t) 0U);
            
            Door3Jam2_xCE_data = ((uint8_t) 0U);
            
            Door3Jam3_xCE_data = ((uint8_t) 0U);
            
            Door3Jam4_xCE_data = ((uint8_t) 0U);
            
            Door3Break_xCE_data = ((uint8_t) 0U);
            
            Door3Opened_xCE_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419241679U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Receive Message */
            
            Time_FD1E_xCF_data = ((int32_t) 0);
            
            TimeOut_FD1E_xCF_data = ((uint8_t) 0U);
            
            Door4Jam1_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            Door4Jam2_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door4Jam3_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door4Jam4_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door4Break_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door4Opened_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door4Clousing_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door4Opening_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_37994689;
            int32_t Add_F45D5B96;
            int32_t Saturation_6A0C52A1;
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Increment Timer */
            
            Read_Parameter_37994689 = Time_FD1E_xCF_data;
            
            Add_F45D5B96 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_37994689));
            
            Saturation_6A0C52A1 = Add_F45D5B96;
            if(Saturation_6A0C52A1 < Read_Parameter_37994689)
            {
                Saturation_6A0C52A1 = Read_Parameter_37994689;
            }
            else if(Saturation_6A0C52A1 > Add_F45D5B96)
            {
                Saturation_6A0C52A1 = Add_F45D5B96;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD1E_xCF_data = Saturation_6A0C52A1;
            
        }
        
        if((Time_FD1E_xCF_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FD1E
Статус открытия дверей\Reset signals */
            
            TimeOut_FD1E_xCF_data = ((uint8_t) 1U);
            
            Door4Jam1_xCF_data = ((uint8_t) 0U);
            
            Door4Jam2_xCF_data = ((uint8_t) 0U);
            
            Door4Jam3_xCF_data = ((uint8_t) 0U);
            
            Door4Jam4_xCF_data = ((uint8_t) 0U);
            
            Door4Break_xCF_data = ((uint8_t) 0U);
            
            Door4Opened_xCF_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419307212U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Receive Message */
            
            Time_FE1E_xCC_data = ((int32_t) 0);
            
            TimeOut_FE1E_xCC_data = ((uint8_t) 0U);
            
            Door1Error1_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door1Error2_xCC_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_EFF66B54;
            int32_t Add_66EF115B;
            int32_t Saturation_570E2ABE;
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Increment Timer */
            
            Read_Parameter_EFF66B54 = Time_FE1E_xCC_data;
            
            Add_66EF115B = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_EFF66B54));
            
            Saturation_570E2ABE = Add_66EF115B;
            if(Saturation_570E2ABE < Read_Parameter_EFF66B54)
            {
                Saturation_570E2ABE = Read_Parameter_EFF66B54;
            }
            else if(Saturation_570E2ABE > Add_66EF115B)
            {
                Saturation_570E2ABE = Add_66EF115B;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE1E_xCC_data = Saturation_570E2ABE;
            
        }
        
        if((Time_FE1E_xCC_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Reset signals */
            
            TimeOut_FE1E_xCC_data = ((uint8_t) 1U);
            
            Door1Error1_xCC_data = ((uint8_t) 0U);
            
            Door1Error2_xCC_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419307213U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Receive Message */
            
            Time_FE1E_xCD_data = ((int32_t) 0);
            
            TimeOut_FE1E_xCD_data = ((uint8_t) 0U);
            
            Door2Error1_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door2Error2_xCD_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_5AA10F45;
            int32_t Add_5E209E30;
            int32_t Saturation_CD9C5F78;
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Increment Timer */
            
            Read_Parameter_5AA10F45 = Time_FE1E_xCD_data;
            
            Add_5E209E30 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_5AA10F45));
            
            Saturation_CD9C5F78 = Add_5E209E30;
            if(Saturation_CD9C5F78 < Read_Parameter_5AA10F45)
            {
                Saturation_CD9C5F78 = Read_Parameter_5AA10F45;
            }
            else if(Saturation_CD9C5F78 > Add_5E209E30)
            {
                Saturation_CD9C5F78 = Add_5E209E30;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE1E_xCD_data = Saturation_CD9C5F78;
            
        }
        
        if((Time_FE1E_xCD_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Reset signals */
            
            TimeOut_FE1E_xCD_data = ((uint8_t) 1U);
            
            Door2Error1_xCD_data = ((uint8_t) 0U);
            
            Door2Error2_xCD_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419307214U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Receive Message */
            
            Time_FE1E_xCE_data = ((int32_t) 0);
            
            TimeOut_FE1E_xCE_data = ((uint8_t) 0U);
            
            Door3Error1_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door3Error2_xCE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_939E963A;
            int32_t Add_B5D12555;
            int32_t Saturation_4013F660;
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Increment Timer */
            
            Read_Parameter_939E963A = Time_FE1E_xCE_data;
            
            Add_B5D12555 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_939E963A));
            
            Saturation_4013F660 = Add_B5D12555;
            if(Saturation_4013F660 < Read_Parameter_939E963A)
            {
                Saturation_4013F660 = Read_Parameter_939E963A;
            }
            else if(Saturation_4013F660 > Add_B5D12555)
            {
                Saturation_4013F660 = Add_B5D12555;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE1E_xCE_data = Saturation_4013F660;
            
        }
        
        if((Time_FE1E_xCE_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Reset signals */
            
            TimeOut_FE1E_xCE_data = ((uint8_t) 1U);
            
            Door3Error1_xCE_data = ((uint8_t) 0U);
            
            Door3Error2_xCE_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419307215U))
        {
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Receive Message */
            
            Time_FE1E_xCF_data = ((int32_t) 0);
            
            TimeOut_FE1E_xCF_data = ((uint8_t) 0U);
            
            Door4Error1_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door4Error2_xCF_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_A855F2AD;
            int32_t Add_5CAA80E6;
            int32_t Saturation_31BE8081;
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Increment Timer */
            
            Read_Parameter_A855F2AD = Time_FE1E_xCF_data;
            
            Add_5CAA80E6 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_A855F2AD));
            
            Saturation_31BE8081 = Add_5CAA80E6;
            if(Saturation_31BE8081 < Read_Parameter_A855F2AD)
            {
                Saturation_31BE8081 = Read_Parameter_A855F2AD;
            }
            else if(Saturation_31BE8081 > Add_5CAA80E6)
            {
                Saturation_31BE8081 = Add_5CAA80E6;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE1E_xCF_data = Saturation_31BE8081;
            
        }
        
        if((Time_FE1E_xCF_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN=FE1E
Неисправности дверей\Reset signals */
            
            TimeOut_FE1E_xCF_data = ((uint8_t) 1U);
            
            Door4Error1_xCF_data = ((uint8_t) 0U);
            
            Door4Error2_xCF_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\CBCU, PGN FF37
Разрешение открытия дверей * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419378974U))
        {
            /* API_CAN_Analyze\CBCU, PGN FF37
Разрешение открытия дверей\Receive Message */
            
            Time_FF37_x1E_data = ((int32_t) 0);
            
            TimeOut_FF37_x1E_data = ((uint8_t) 0U);
            
            RampRequest_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            DoorsAllow_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            DoorsLock_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            Door2PasReq_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            EngHatch_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_FEE04E30;
            int32_t Add_247F2180;
            int32_t Saturation_4EB65565;
            /* API_CAN_Analyze\CBCU, PGN FF37
Разрешение открытия дверей\Increment Timer */
            
            Read_Parameter_FEE04E30 = Time_FF37_x1E_data;
            
            Add_247F2180 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_FEE04E30));
            
            Saturation_4EB65565 = Add_247F2180;
            if(Saturation_4EB65565 < Read_Parameter_FEE04E30)
            {
                Saturation_4EB65565 = Read_Parameter_FEE04E30;
            }
            else if(Saturation_4EB65565 > Add_247F2180)
            {
                Saturation_4EB65565 = Add_247F2180;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF37_x1E_data = Saturation_4EB65565;
            
        }
        
        if((Time_FF37_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\CBCU, PGN FF37
Разрешение открытия дверей\Reset signals */
            
            TimeOut_FF37_x1E_data = ((uint8_t) 1U);
            
            RampRequest_x1E_data = ((uint8_t) 0U);
            
            DoorsAllow_x1E_data = ((uint8_t) 0U);
            
            DoorsLock_x1E_data = ((uint8_t) 0U);
            
            Door2PasReq_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\AUXIO1,
PGN: FED9
Датчики (!!!) * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419354910U))
        {
            /* API_CAN_Analyze\AUXIO1,
PGN: FED9
Датчики (!!!)\Receive Message */
            
            Time_FED9_x1E_data = ((int32_t) 0);
            
            TimeOut_FED9_x1E_data = ((uint8_t) 0U);
            
            GURFluidLow_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            BusStop_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            MirrorHeat_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Battery24VDis_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            FilterAirClogged_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            WiperMode_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            FlightIndicator_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_D6BDBE37;
            int32_t Add_457C6243;
            int32_t Saturation_3AC5FB20;
            /* API_CAN_Analyze\AUXIO1,
PGN: FED9
Датчики (!!!)\Increment Timer */
            
            Read_Parameter_D6BDBE37 = Time_FED9_x1E_data;
            
            Add_457C6243 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_D6BDBE37));
            
            Saturation_3AC5FB20 = Add_457C6243;
            if(Saturation_3AC5FB20 < Read_Parameter_D6BDBE37)
            {
                Saturation_3AC5FB20 = Read_Parameter_D6BDBE37;
            }
            else if(Saturation_3AC5FB20 > Add_457C6243)
            {
                Saturation_3AC5FB20 = Add_457C6243;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FED9_x1E_data = Saturation_3AC5FB20;
            
        }
        
        if((Time_FED9_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AUXIO1,
PGN: FED9
Датчики (!!!)\Reset signals */
            
            TimeOut_FED9_x1E_data = ((uint8_t) 1U);
            
            GURFluidLow_x1E_data = ((uint8_t) 0U);
            
            BusStop_x1E_data = ((uint8_t) 0U);
            
            MirrorHeat_x1E_data = ((uint8_t) 0U);
            
            Battery24VDis_x1E_data = ((uint8_t) 0U);
            
            FilterAirClogged_x1E_data = ((uint8_t) 0U);
            
            WiperMode_x1E_data = ((uint8_t) 0U);
            
            FlightIndicator_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DC1
PGN FE4E
Doors, Ramp * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419319329U))
        {
            /* API_CAN_Analyze\DC1
PGN FE4E
Doors, Ramp\Receive Message */
            
            Time_FE4E_x21_data = ((int32_t) 0);
            
            TimeOut_FE4E_x21_data = ((uint8_t) 0U);
            
            RampPosState_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            DoorsPosState_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_BFB62837;
            int32_t Add_DD5319D7;
            int32_t Saturation_6223DC38;
            /* API_CAN_Analyze\DC1
PGN FE4E
Doors, Ramp\Increment Timer */
            
            Read_Parameter_BFB62837 = Time_FE4E_x21_data;
            
            Add_DD5319D7 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_BFB62837));
            
            Saturation_6223DC38 = Add_DD5319D7;
            if(Saturation_6223DC38 < Read_Parameter_BFB62837)
            {
                Saturation_6223DC38 = Read_Parameter_BFB62837;
            }
            else if(Saturation_6223DC38 > Add_DD5319D7)
            {
                Saturation_6223DC38 = Add_DD5319D7;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE4E_x21_data = Saturation_6223DC38;
            
        }
        
        if((Time_FE4E_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DC1
PGN FE4E
Doors, Ramp\Reset signals */
            
            TimeOut_FE4E_x21_data = ((uint8_t) 1U);
            
            RampPosState_x21_data = ((uint8_t) 0U);
            
            DoorsPosState_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DC2
PGN FDA5
DoorsStatus * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419276065U))
        {
            /* API_CAN_Analyze\DC2
PGN FDA5
DoorsStatus\Receive Message */
            
            Time_FDA5_x21_data = ((int32_t) 0);
            
            TimeOut_FDA5x21_data = ((uint8_t) 0U);
            
            Door1State_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door2State_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Door3State_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_9326426E;
            int32_t Add_A3E6E245;
            int32_t Saturation_924328BB;
            /* API_CAN_Analyze\DC2
PGN FDA5
DoorsStatus\Increment Timer */
            
            Read_Parameter_9326426E = Time_FDA5_x21_data;
            
            Add_A3E6E245 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_9326426E));
            
            Saturation_924328BB = Add_A3E6E245;
            if(Saturation_924328BB < Read_Parameter_9326426E)
            {
                Saturation_924328BB = Read_Parameter_9326426E;
            }
            else if(Saturation_924328BB > Add_A3E6E245)
            {
                Saturation_924328BB = Add_A3E6E245;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FDA5_x21_data = Saturation_924328BB;
            
        }
        
        if((Time_FDA5_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DC2
PGN FDA5
DoorsStatus\Reset signals */
            
            TimeOut_FDA5x21_data = ((uint8_t) 1U);
            
            Door1State_x21_data = ((uint8_t) 0U);
            
            Door2State_x21_data = ((uint8_t) 0U);
            
            Door3State_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DCAC_AI1_FDB0K
PGN F0D7
DC/AC Inverter * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 418436954U))
        {
            /* API_CAN_Analyze\DCAC_AI1_FDB0K
PGN F0D7
DC/AC Inverter\Receive Message */
            
            Time_F0D7x5A_data = ((int32_t) 0);
            
            TimeOut_F0D7x5A_data = ((uint8_t) 0U);
            
            DCACInverterFB_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 3U))));
            
        }
        else
        {
            int32_t Read_Parameter_C65B744C;
            int32_t Add_97730EA3;
            int32_t Saturation_7F1461EE;
            /* API_CAN_Analyze\DCAC_AI1_FDB0K
PGN F0D7
DC/AC Inverter\Increment Timer */
            
            Read_Parameter_C65B744C = Time_F0D7x5A_data;
            
            Add_97730EA3 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_C65B744C));
            
            Saturation_7F1461EE = Add_97730EA3;
            if(Saturation_7F1461EE < Read_Parameter_C65B744C)
            {
                Saturation_7F1461EE = Read_Parameter_C65B744C;
            }
            else if(Saturation_7F1461EE > Add_97730EA3)
            {
                Saturation_7F1461EE = Add_97730EA3;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F0D7x5A_data = Saturation_7F1461EE;
            
        }
        
        if((Time_F0D7x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DCAC_AI1_FDB0K
PGN F0D7
DC/AC Inverter\Reset signals */
            
            TimeOut_F0D7x5A_data = ((uint8_t) 1U);
            
            DCACInverterFB_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DCDC1OS
PGN F113
DC/DC Converter * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217125722U))
        {
            /* API_CAN_Analyze\DCDC1OS
PGN F113
DC/DC Converter\Receive Message */
            
            Time_F113x5A_data = ((int32_t) 0);
            
            TimeOut_F113x5A_data = ((uint8_t) 0U);
            
            DCDCConverter_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_CF947338;
            int32_t Add_575D6F37;
            int32_t Saturation_CFDEC942;
            /* API_CAN_Analyze\DCDC1OS
PGN F113
DC/DC Converter\Increment Timer */
            
            Read_Parameter_CF947338 = Time_F113x5A_data;
            
            Add_575D6F37 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_CF947338));
            
            Saturation_CFDEC942 = Add_575D6F37;
            if(Saturation_CFDEC942 < Read_Parameter_CF947338)
            {
                Saturation_CFDEC942 = Read_Parameter_CF947338;
            }
            else if(Saturation_CFDEC942 > Add_575D6F37)
            {
                Saturation_CFDEC942 = Add_575D6F37;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F113x5A_data = Saturation_CFDEC942;
            
        }
        
        if((Time_F113x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DCDC1OS
PGN F113
DC/DC Converter\Reset signals */
            
            TimeOut_F113x5A_data = ((uint8_t) 1U);
            
            DCDCConverter_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DCDC1VC
PGN=F114(?)
Battery24V * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217125978U))
        {
            /* API_CAN_Analyze\DCDC1VC
PGN=F114(?)
Battery24V\Receive Message */
            
            Time_F114_x5A_data = ((int32_t) 0);
            
            TimeOut_F114_x5A_data = ((uint8_t) 0U);
            
            LVBatteryLvlV_x5A_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            LVBatteryLvlA_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 32127))));
            
        }
        else
        {
            int32_t Read_Parameter_C42C07C5;
            int32_t Add_3AA2CB9E;
            int32_t Saturation_89346777;
            /* API_CAN_Analyze\DCDC1VC
PGN=F114(?)
Battery24V\Increment Timer */
            
            Read_Parameter_C42C07C5 = Time_F114_x5A_data;
            
            Add_3AA2CB9E = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_C42C07C5));
            
            Saturation_89346777 = Add_3AA2CB9E;
            if(Saturation_89346777 < Read_Parameter_C42C07C5)
            {
                Saturation_89346777 = Read_Parameter_C42C07C5;
            }
            else if(Saturation_89346777 > Add_3AA2CB9E)
            {
                Saturation_89346777 = Add_3AA2CB9E;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F114_x5A_data = Saturation_89346777;
            
        }
        
        if((Time_F114_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DCDC1VC
PGN=F114(?)
Battery24V\Reset signals */
            
            TimeOut_F114_x5A_data = ((uint8_t) 1U);
            
            LVBatteryLvlV_x5A_data = ((uint16_t) 0U);
            
            LVBatteryLvlA_x5A_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419363870U))
        {
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Receive Message */
            
            Time_FEFC_x1E_data = ((int32_t) 0);
            
            TimeOut_FEFC_x1E_data = ((uint8_t) 0U);
            
            WasherLvl_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            FuelLvl_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_2744F0AC;
            int32_t Add_736587D7;
            int32_t Saturation_205167F9;
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Increment Timer */
            
            Read_Parameter_2744F0AC = Time_FEFC_x1E_data;
            
            Add_736587D7 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_2744F0AC));
            
            Saturation_205167F9 = Add_736587D7;
            if(Saturation_205167F9 < Read_Parameter_2744F0AC)
            {
                Saturation_205167F9 = Read_Parameter_2744F0AC;
            }
            else if(Saturation_205167F9 > Add_736587D7)
            {
                Saturation_205167F9 = Add_736587D7;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEFC_x1E_data = Saturation_205167F9;
            
        }
        
        if((Time_FEFC_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Reset signals */
            
            TimeOut_FEFC_x1E_data = ((uint8_t) 1U);
            
            WasherLvl_x1E_data = ((uint8_t) 0U);
            
            FuelLvl_x1E_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419363879U))
        {
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Receive Message */
            
            Time_FEFC_x27_data = ((int32_t) 0);
            
            TimeOut_FEFC_x27_data = ((uint8_t) 0U);
            
            FuelLvl_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_0DA3AF1B;
            int32_t Add_549F0A23;
            int32_t Saturation_75EC72D7;
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Increment Timer */
            
            Read_Parameter_0DA3AF1B = Time_FEFC_x27_data;
            
            Add_549F0A23 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_0DA3AF1B));
            
            Saturation_75EC72D7 = Add_549F0A23;
            if(Saturation_75EC72D7 < Read_Parameter_0DA3AF1B)
            {
                Saturation_75EC72D7 = Read_Parameter_0DA3AF1B;
            }
            else if(Saturation_75EC72D7 > Add_549F0A23)
            {
                Saturation_75EC72D7 = Add_549F0A23;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEFC_x27_data = Saturation_75EC72D7;
            
        }
        
        if((Time_FEFC_x27_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Reset signals */
            
            TimeOut_FEFC_x27_data = ((uint8_t) 1U);
            
            FuelLvl_x27_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419363858U))
        {
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Receive Message */
            
            Time_FEFC_x12_data = ((int32_t) 0);
            
            TimeOut_FEFC_x12_data = ((uint8_t) 0U);
            
            FuelLvl_x12_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_64AB6216;
            int32_t Add_3707617E;
            int32_t Saturation_A2E7C79E;
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Increment Timer */
            
            Read_Parameter_64AB6216 = Time_FEFC_x12_data;
            
            Add_3707617E = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_64AB6216));
            
            Saturation_A2E7C79E = Add_3707617E;
            if(Saturation_A2E7C79E < Read_Parameter_64AB6216)
            {
                Saturation_A2E7C79E = Read_Parameter_64AB6216;
            }
            else if(Saturation_A2E7C79E > Add_3707617E)
            {
                Saturation_A2E7C79E = Add_3707617E;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEFC_x12_data = Saturation_A2E7C79E;
            
        }
        
        if((Time_FEFC_x12_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DD1,
PGN: FEFC
Fuel, Washer\Reset signals */
            
            TimeOut_FEFC_x12_data = ((uint8_t) 1U);
            
            FuelLvl_x12_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419235623U))
        {
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Receive Message */
            
            Time_FD07_x27_data = ((int32_t) 0);
            
            TimeOut_FD07_x27_data = ((uint8_t) 0U);
            
            EngProtectCmd_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            EngWarningCmd_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            EngErrorCmd_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            EngBrakeCmd_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            EngOilPressLowCmd_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            EngCoolantTempHighCmd_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_96B4A7EC;
            int32_t Add_CEEA3832;
            int32_t Saturation_085E605D;
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Increment Timer */
            
            Read_Parameter_96B4A7EC = Time_FD07_x27_data;
            
            Add_CEEA3832 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_96B4A7EC));
            
            Saturation_085E605D = Add_CEEA3832;
            if(Saturation_085E605D < Read_Parameter_96B4A7EC)
            {
                Saturation_085E605D = Read_Parameter_96B4A7EC;
            }
            else if(Saturation_085E605D > Add_CEEA3832)
            {
                Saturation_085E605D = Add_CEEA3832;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD07_x27_data = Saturation_085E605D;
            
        }
        
        if((Time_FD07_x27_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Reset signals */
            
            TimeOut_FD07_x27_data = ((uint8_t) 1U);
            
            EngProtectCmd_x27_data = ((uint8_t) 0U);
            
            EngWarningCmd_x27_data = ((uint8_t) 0U);
            
            EngErrorCmd_x27_data = ((uint8_t) 0U);
            
            EngBrakeCmd_x27_data = ((uint8_t) 0U);
            
            EngOilPressLowCmd_x27_data = ((uint8_t) 0U);
            
            EngCoolantTempHighCmd_x27_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419235674U))
        {
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Receive Message */
            
            Time_FD07_x5A_data = ((int32_t) 0);
            
            TimeOut_FD07_x5A_data = ((uint8_t) 0U);
            
            EngWarningCmd_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            EngCoolantTempHighCmd_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_1B29478D;
            int32_t Add_A44EDA15;
            int32_t Saturation_969E3D8A;
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Increment Timer */
            
            Read_Parameter_1B29478D = Time_FD07_x5A_data;
            
            Add_A44EDA15 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_1B29478D));
            
            Saturation_969E3D8A = Add_A44EDA15;
            if(Saturation_969E3D8A < Read_Parameter_1B29478D)
            {
                Saturation_969E3D8A = Read_Parameter_1B29478D;
            }
            else if(Saturation_969E3D8A > Add_A44EDA15)
            {
                Saturation_969E3D8A = Add_A44EDA15;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD07_x5A_data = Saturation_969E3D8A;
            
        }
        
        if((Time_FD07_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Reset signals */
            
            TimeOut_FD07_x27_data = ((uint8_t) 1U);
            
            EngWarningCmd_x5A_data = ((uint8_t) 0U);
            
            EngCoolantTempHighCmd_x5A_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419235584U))
        {
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Receive Message */
            
            Time_FD07_x00_data = ((int32_t) 0);
            
            TimeOut_FD07_x00_data = ((uint8_t) 0U);
            
            OBDCmd_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_7288ECCD;
            int32_t Add_DD501860;
            int32_t Saturation_7C664CA3;
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Increment Timer */
            
            Read_Parameter_7288ECCD = Time_FD07_x00_data;
            
            Add_DD501860 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_7288ECCD));
            
            Saturation_7C664CA3 = Add_DD501860;
            if(Saturation_7C664CA3 < Read_Parameter_7288ECCD)
            {
                Saturation_7C664CA3 = Read_Parameter_7288ECCD;
            }
            else if(Saturation_7C664CA3 > Add_DD501860)
            {
                Saturation_7C664CA3 = Add_DD501860;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD07_x00_data = Saturation_7C664CA3;
            
        }
        
        if((Time_FD07_x00_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DLCC1
PGN FD07
Сбой системы выхлопа\Reset signals */
            
            TimeOut_FD07_x00_data = ((uint8_t) 1U);
            
            OBDCmd_x00_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EPB1
PGN FF3C
Ручной тормоз * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419380304U))
        {
            /* API_CAN_Analyze\EPB1
PGN FF3C
Ручной тормоз\Receive Message */
            
            Time_FF3C_x50_data = ((int32_t) 0);
            
            TimeOut_FF3C_x50_data = ((uint8_t) 0U);
            
            ParkingBrakeDis_x50_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
            ParkingBrakeWarning_x50_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            ParkingBrakeError_x50_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            ParkingBrakeError32_x50_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_7B727AB7;
            int32_t Add_EC33863F;
            int32_t Saturation_017E2D54;
            /* API_CAN_Analyze\EPB1
PGN FF3C
Ручной тормоз\Increment Timer */
            
            Read_Parameter_7B727AB7 = Time_FF3C_x50_data;
            
            Add_EC33863F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_7B727AB7));
            
            Saturation_017E2D54 = Add_EC33863F;
            if(Saturation_017E2D54 < Read_Parameter_7B727AB7)
            {
                Saturation_017E2D54 = Read_Parameter_7B727AB7;
            }
            else if(Saturation_017E2D54 > Add_EC33863F)
            {
                Saturation_017E2D54 = Add_EC33863F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF3C_x50_data = Saturation_017E2D54;
            
        }
        
        if((Time_FF3C_x50_data) >= ((int32_t) 1000))
        {
            /* API_CAN_Analyze\EPB1
PGN FF3C
Ручной тормоз\Reset signals */
            
            TimeOut_FF3C_x50_data = ((uint8_t) 1U);
            
            ParkingBrakeDis_x50_data = ((uint8_t) 0U);
            
            ParkingBrakeWarning_x50_data = ((uint8_t) 0U);
            
            ParkingBrakeError_x50_data = ((uint8_t) 0U);
            
            ParkingBrakeError32_x50_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PGN FFFE
Капот автобуса * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 436207134U))
        {
            /* API_CAN_Analyze\PGN FFFE
Капот автобуса\Receive Message */
            
            Time_FFFE_x1E_data = ((int32_t) 0);
            
            TimeOut_FFFE_x1E_data = ((uint8_t) 0U);
            
            BusHood_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_6508949E;
            int32_t Add_0DF0A79A;
            int32_t Saturation_1C7B3A0D;
            /* API_CAN_Analyze\PGN FFFE
Капот автобуса\Increment Timer */
            
            Read_Parameter_6508949E = Time_FFFE_x1E_data;
            
            Add_0DF0A79A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_6508949E));
            
            Saturation_1C7B3A0D = Add_0DF0A79A;
            if(Saturation_1C7B3A0D < Read_Parameter_6508949E)
            {
                Saturation_1C7B3A0D = Read_Parameter_6508949E;
            }
            else if(Saturation_1C7B3A0D > Add_0DF0A79A)
            {
                Saturation_1C7B3A0D = Add_0DF0A79A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FFFE_x1E_data = Saturation_1C7B3A0D;
            
        }
        
        if((Time_FFFE_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PGN FFFE
Капот автобуса\Reset signals */
            
            TimeOut_FFFE_x1E_data = ((uint8_t) 1U);
            
            BusHood_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PGN FF07
Гармошка * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419366887U))
        {
            /* API_CAN_Analyze\PGN FF07
Гармошка\Receive Message */
            
            Time_FF07_xE7_data = ((int32_t) 0);
            
            TimeOut_FF07_xE7_data = ((uint8_t) 0U);
            
            SwingAngle_xE7_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int16_t) 125))));
            
            SwingError_xE7_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            SwingWarning_xE7_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            SwingSong_xE7_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_5B152AC1;
            int32_t Add_DE29ED00;
            int32_t Saturation_F4412854;
            /* API_CAN_Analyze\PGN FF07
Гармошка\Increment Timer */
            
            Read_Parameter_5B152AC1 = Time_FF07_xE7_data;
            
            Add_DE29ED00 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_5B152AC1));
            
            Saturation_F4412854 = Add_DE29ED00;
            if(Saturation_F4412854 < Read_Parameter_5B152AC1)
            {
                Saturation_F4412854 = Read_Parameter_5B152AC1;
            }
            else if(Saturation_F4412854 > Add_DE29ED00)
            {
                Saturation_F4412854 = Add_DE29ED00;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF07_xE7_data = Saturation_F4412854;
            
        }
        
        if((Time_FF07_xE7_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PGN FF07
Гармошка\Reset signals */
            
            TimeOut_FF07_xE7_data = ((uint8_t) 1U);
            
            SwingAngle_xE7_data = ((int16_t) 0);
            
            SwingError_xE7_data = ((uint8_t) 0U);
            
            SwingWarning_xE7_data = ((uint8_t) 0U);
            
            SwingSong_xE7_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\AUXIO4
PGN: A501
Joystic * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 413466955U))
        {
            /* API_CAN_Analyze\AUXIO4
PGN: A501
Joystic\Receive Message */
            
            Time_A501_x4B_data = ((int32_t) 0);
            
            TimeOut_A501_x4B_data = ((uint8_t) 0U);
            
            JoystickMode_x4B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            JoystickCancel_x4B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            JoystickUp_x4B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            JoystickOk_x4B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            JoystickDown_x4B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_60C4F974;
            int32_t Add_A98A9C79;
            int32_t Saturation_4A8F0532;
            /* API_CAN_Analyze\AUXIO4
PGN: A501
Joystic\Increment Timer */
            
            Read_Parameter_60C4F974 = Time_A501_x4B_data;
            
            Add_A98A9C79 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_60C4F974));
            
            Saturation_4A8F0532 = Add_A98A9C79;
            if(Saturation_4A8F0532 < Read_Parameter_60C4F974)
            {
                Saturation_4A8F0532 = Read_Parameter_60C4F974;
            }
            else if(Saturation_4A8F0532 > Add_A98A9C79)
            {
                Saturation_4A8F0532 = Add_A98A9C79;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_A501_x4B_data = Saturation_4A8F0532;
            
        }
        
        if((Time_A501_x4B_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AUXIO4
PGN: A501
Joystic\Reset signals */
            
            TimeOut_A501_x4B_data = ((uint8_t) 1U);
            
            JoystickMode_x4B_data = ((uint8_t) 0U);
            
            JoystickCancel_x4B_data = ((uint8_t) 0U);
            
            JoystickUp_x4B_data = ((uint8_t) 0U);
            
            JoystickOk_x4B_data = ((uint8_t) 0U);
            
            JoystickDown_x4B_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DLCC2
PGN FD06
Bat24V, Fuel * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419235418U))
        {
            /* API_CAN_Analyze\DLCC2
PGN FD06
Bat24V, Fuel\Receive Message */
            
            Time_FD06_x5A_data = ((int32_t) 0);
            
            TimeOut_FD06_x5A_data = ((uint8_t) 0U);
            
            LVBatteryLowVCmd_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            FuelLowCmd_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_081D05EE;
            int32_t Add_7F7B1D8B;
            int32_t Saturation_1FE8087B;
            /* API_CAN_Analyze\DLCC2
PGN FD06
Bat24V, Fuel\Increment Timer */
            
            Read_Parameter_081D05EE = Time_FD06_x5A_data;
            
            Add_7F7B1D8B = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_081D05EE));
            
            Saturation_1FE8087B = Add_7F7B1D8B;
            if(Saturation_1FE8087B < Read_Parameter_081D05EE)
            {
                Saturation_1FE8087B = Read_Parameter_081D05EE;
            }
            else if(Saturation_1FE8087B > Add_7F7B1D8B)
            {
                Saturation_1FE8087B = Add_7F7B1D8B;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD06_x5A_data = Saturation_1FE8087B;
            
        }
        
        if((Time_FD06_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DLCC2
PGN FD06
Bat24V, Fuel\Reset signals */
            
            TimeOut_FD06_x5A_data = ((uint8_t) 1U);
            
            LVBatteryLowVCmd_x5A_data = ((uint8_t) 0U);
            
            FuelLowCmd_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DPFC1
PGN: FD7C * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419265536U))
        {
            /* API_CAN_Analyze\DPFC1
PGN: FD7C\Receive Message */
            
            Time_FD7C_x00_data = ((int32_t) 0);
            
            TimeOut_FD7C_x00_data = ((uint8_t) 0U);
            
            OBDTempHighCmd_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 2U), ((uint8_t) 3U))));
            
        }
        else
        {
            int32_t Read_Parameter_F4CC32CE;
            int32_t Add_9513D340;
            int32_t Saturation_F69886BE;
            /* API_CAN_Analyze\DPFC1
PGN: FD7C\Increment Timer */
            
            Read_Parameter_F4CC32CE = Time_FD7C_x00_data;
            
            Add_9513D340 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_F4CC32CE));
            
            Saturation_F69886BE = Add_9513D340;
            if(Saturation_F69886BE < Read_Parameter_F4CC32CE)
            {
                Saturation_F69886BE = Read_Parameter_F4CC32CE;
            }
            else if(Saturation_F69886BE > Add_9513D340)
            {
                Saturation_F69886BE = Add_9513D340;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD7C_x00_data = Saturation_F69886BE;
            
        }
        
        if((Time_FD7C_x00_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DPFC1
PGN: FD7C\Reset signals */
            
            TimeOut_FD7C_x00_data = ((uint8_t) 1U);
            
            OBDTempHighCmd_x00_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DRC
PGN: FD70
Door, Ramp * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419262497U))
        {
            /* API_CAN_Analyze\DRC
PGN: FD70
Door, Ramp\Receive Message */
            
            Time_FD70_x21_data = ((int32_t) 0);
            
            TimeOut_FD70_x21_data = ((uint8_t) 0U);
            
            Ramp1RetractState_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            Ramp1ActiveState_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Ramp1MoveState_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_152EE970;
            int32_t Add_951E417D;
            int32_t Saturation_6405BFB9;
            /* API_CAN_Analyze\DRC
PGN: FD70
Door, Ramp\Increment Timer */
            
            Read_Parameter_152EE970 = Time_FD70_x21_data;
            
            Add_951E417D = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_152EE970));
            
            Saturation_6405BFB9 = Add_951E417D;
            if(Saturation_6405BFB9 < Read_Parameter_152EE970)
            {
                Saturation_6405BFB9 = Read_Parameter_152EE970;
            }
            else if(Saturation_6405BFB9 > Add_951E417D)
            {
                Saturation_6405BFB9 = Add_951E417D;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD70_x21_data = Saturation_6405BFB9;
            
        }
        
        if((Time_FD70_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DRC
PGN: FD70
Door, Ramp\Reset signals */
            
            TimeOut_FD70_x21_data = ((uint8_t) 1U);
            
            Ramp1RetractState_x21_data = ((uint8_t) 0U);
            
            Ramp1ActiveState_x21_data = ((uint8_t) 0U);
            
            Ramp1MoveState_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // Параметры ПАЗ */

    /* // E */

    {
        /* / * API_CAN_Analyze\EBC1, EBS
PGN: F001 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 418382091U))
        {
            /* API_CAN_Analyze\EBC1, EBS
PGN: F001\Receive Message */
            
            Time_F001_x0B_data = ((int32_t) 0);
            
            TimeOut_F001_x0B_data = ((uint8_t) 0U);
            
            ASREng_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            ASRBrake_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            ABS_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            ABSOffSwitch_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            ASROff_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            HillHold_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            EBSError_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            EBSWarning_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            ATC_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_E41215BF;
            int32_t Add_1491FBED;
            int32_t Saturation_E2F4E9B7;
            /* API_CAN_Analyze\EBC1, EBS
PGN: F001\Increment Timer */
            
            Read_Parameter_E41215BF = Time_F001_x0B_data;
            
            Add_1491FBED = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_E41215BF));
            
            Saturation_E2F4E9B7 = Add_1491FBED;
            if(Saturation_E2F4E9B7 < Read_Parameter_E41215BF)
            {
                Saturation_E2F4E9B7 = Read_Parameter_E41215BF;
            }
            else if(Saturation_E2F4E9B7 > Add_1491FBED)
            {
                Saturation_E2F4E9B7 = Add_1491FBED;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F001_x0B_data = Saturation_E2F4E9B7;
            
        }
        
        if((Time_F001_x0B_data) >= ((int32_t) 1000))
        {
            /* API_CAN_Analyze\EBC1, EBS
PGN: F001\Reset signals */
            
            TimeOut_F001_x0B_data = ((uint8_t) 1U);
            
            ASREng_x0B_data = ((uint8_t) 0U);
            
            ASRBrake_x0B_data = ((uint8_t) 0U);
            
            ABS_x0B_data = ((uint8_t) 0U);
            
            ABSOffSwitch_x0B_data = ((uint8_t) 0U);
            
            ASROff_x0B_data = ((uint8_t) 0U);
            
            HillHold_x0B_data = ((uint8_t) 0U);
            
            EBSError_x0B_data = ((uint8_t) 0U);
            
            EBSWarning_x0B_data = ((uint8_t) 0U);
            
            ATC_x0B_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EBC4
PGN: FEAC
Brake pad * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 486452235U))
        {
            /* API_CAN_Analyze\EBC4
PGN: FEAC
Brake pad\Receive Message */
            
            Time_FEAC_x0B_data = ((int32_t) 0);
            
            TimeOut_FEAC_x0B_data = ((uint8_t) 0U);
            
            BrakePadLA1_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            BrakePadRA1_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            BrakePadLA2_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            BrakePadRA2_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            BrakePadLA3_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            BrakePadRA3_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_5541D08B;
            int32_t Add_E9855E15;
            int32_t Saturation_130BA181;
            /* API_CAN_Analyze\EBC4
PGN: FEAC
Brake pad\Increment Timer */
            
            Read_Parameter_5541D08B = Time_FEAC_x0B_data;
            
            Add_E9855E15 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_5541D08B));
            
            Saturation_130BA181 = Add_E9855E15;
            if(Saturation_130BA181 < Read_Parameter_5541D08B)
            {
                Saturation_130BA181 = Read_Parameter_5541D08B;
            }
            else if(Saturation_130BA181 > Add_E9855E15)
            {
                Saturation_130BA181 = Add_E9855E15;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEAC_x0B_data = Saturation_130BA181;
            
        }
        
        if((Time_FEAC_x0B_data) >= ((int32_t) 20000))
        {
            /* API_CAN_Analyze\EBC4
PGN: FEAC
Brake pad\Reset signals */
            
            TimeOut_FEAC_x0B_data = ((uint8_t) 1U);
            
            BrakePadLA1_x0B_data = ((uint8_t) 0U);
            
            BrakePadRA1_x0B_data = ((uint8_t) 0U);
            
            BrakePadLA2_x0B_data = ((uint8_t) 0U);
            
            BrakePadRA2_x0B_data = ((uint8_t) 0U);
            
            BrakePadLA3_x0B_data = ((uint8_t) 0U);
            
            BrakePadRA3_x0B_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EBC5, EBC5_id0B
PGN FDC4
HillStartAid, Doorbell * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419283979U))
        {
            /* API_CAN_Analyze\EBC5, EBC5_id0B
PGN FDC4
HillStartAid, Doorbell\Receive Message */
            
            Time_FDC4_x0B_data = ((int32_t) 0);
            
            TimeOut_FDC4_x0B_data = ((uint8_t) 0U);
            
            HaltBrake_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 3U))));
            
            HillHoldMode_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 5U), ((uint8_t) 3U))));
            
        }
        else
        {
            int32_t Read_Parameter_C3006B6C;
            int32_t Add_A4428C7D;
            int32_t Saturation_DD3D6F8A;
            /* API_CAN_Analyze\EBC5, EBC5_id0B
PGN FDC4
HillStartAid, Doorbell\Increment Timer */
            
            Read_Parameter_C3006B6C = Time_FDC4_x0B_data;
            
            Add_A4428C7D = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_C3006B6C));
            
            Saturation_DD3D6F8A = Add_A4428C7D;
            if(Saturation_DD3D6F8A < Read_Parameter_C3006B6C)
            {
                Saturation_DD3D6F8A = Read_Parameter_C3006B6C;
            }
            else if(Saturation_DD3D6F8A > Add_A4428C7D)
            {
                Saturation_DD3D6F8A = Add_A4428C7D;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FDC4_x0B_data = Saturation_DD3D6F8A;
            
        }
        
        if((Time_FDC4_x0B_data) >= ((int32_t) 400))
        {
            /* API_CAN_Analyze\EBC5, EBC5_id0B
PGN FDC4
HillStartAid, Doorbell\Reset signals */
            
            TimeOut_FDC4_x0B_data = ((uint8_t) 1U);
            
            HaltBrake_x0B_data = ((uint8_t) 0U);
            
            HillHoldMode_x0B_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EBS23
PGN FEC6
BrakePadState * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419350106U))
        {
            /* API_CAN_Analyze\EBS23
PGN FEC6
BrakePadState\Receive Message */
            
            Time_FEC6_x5A_data = ((int32_t) 0);
            
            TimeOut_FEC6_x5A_data = ((uint8_t) 0U);
            
            BrakePadState_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_90400EFD;
            int32_t Add_40BEEDAA;
            int32_t Saturation_B9EEE897;
            /* API_CAN_Analyze\EBS23
PGN FEC6
BrakePadState\Increment Timer */
            
            Read_Parameter_90400EFD = Time_FEC6_x5A_data;
            
            Add_40BEEDAA = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_90400EFD));
            
            Saturation_B9EEE897 = Add_40BEEDAA;
            if(Saturation_B9EEE897 < Read_Parameter_90400EFD)
            {
                Saturation_B9EEE897 = Read_Parameter_90400EFD;
            }
            else if(Saturation_B9EEE897 > Add_40BEEDAA)
            {
                Saturation_B9EEE897 = Add_40BEEDAA;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEC6_x5A_data = Saturation_B9EEE897;
            
        }
        
        if((Time_FEC6_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\EBS23
PGN FEC6
BrakePadState\Reset signals */
            
            TimeOut_FEC6_x5A_data = ((uint8_t) 1U);
            
            BrakePadState_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EEC1_id00
PGN F004
Тахометр * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217056256U))
        {
            /* API_CAN_Analyze\EEC1_id00
PGN F004
Тахометр\Receive Message */
            
            Time_F004_x00_data = ((int32_t) 0);
            
            TimeOut_F004_x00_data = ((uint8_t) 0U);
            
            EngSpeedOrigin_x00_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_8D4D7411;
            int32_t Add_459C3C78;
            int32_t Saturation_D11F3CBE;
            /* API_CAN_Analyze\EEC1_id00
PGN F004
Тахометр\Increment Timer */
            
            Read_Parameter_8D4D7411 = Time_F004_x00_data;
            
            Add_459C3C78 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_8D4D7411));
            
            Saturation_D11F3CBE = Add_459C3C78;
            if(Saturation_D11F3CBE < Read_Parameter_8D4D7411)
            {
                Saturation_D11F3CBE = Read_Parameter_8D4D7411;
            }
            else if(Saturation_D11F3CBE > Add_459C3C78)
            {
                Saturation_D11F3CBE = Add_459C3C78;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F004_x00_data = Saturation_D11F3CBE;
            
        }
        
        if((Time_F004_x00_data) >= ((int32_t) 200))
        {
            /* API_CAN_Analyze\EEC1_id00
PGN F004
Тахометр\Reset signals */
            
            TimeOut_F004_x00_data = ((uint8_t) 1U);
            
            EngSpeedOrigin_x00_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EEC2
PGN F003
MotorController2 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217056000U))
        {
            /* API_CAN_Analyze\EEC2
PGN F003
MotorController2\Receive Message */
            
            Time_F003_x00_data = ((int32_t) 0);
            
            TimeOut_F003_x00_data = ((uint8_t) 0U);
            
            AccelPedalPos1_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            AccelLimitState_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_B676A713;
            int32_t Add_19901A4A;
            int32_t Saturation_2D7870D1;
            /* API_CAN_Analyze\EEC2
PGN F003
MotorController2\Increment Timer */
            
            Read_Parameter_B676A713 = Time_F003_x00_data;
            
            Add_19901A4A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_B676A713));
            
            Saturation_2D7870D1 = Add_19901A4A;
            if(Saturation_2D7870D1 < Read_Parameter_B676A713)
            {
                Saturation_2D7870D1 = Read_Parameter_B676A713;
            }
            else if(Saturation_2D7870D1 > Add_19901A4A)
            {
                Saturation_2D7870D1 = Add_19901A4A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F003_x00_data = Saturation_2D7870D1;
            
        }
        
        if((Time_F003_x00_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\EEC2
PGN F003
MotorController2\Reset signals */
            
            TimeOut_F003_x00_data = ((uint8_t) 1U);
            
            AccelPedalPos1_x00_data = ((uint8_t) 0U);
            
            AccelLimitState_x00_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EFL_P1_id00
PGN FEEF
Давление масла * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419360512U))
        {
            /* API_CAN_Analyze\EFL_P1_id00
PGN FEEF
Давление масла\Receive Message */
            
            Time_FEEF_x00_data = ((int32_t) 0);
            
            TimeOut_FEEF_x00_data = ((uint8_t) 0U);
            
            EngOilPres_x00_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_24A290D3;
            int32_t Add_10FB8FA8;
            int32_t Saturation_1591EC01;
            /* API_CAN_Analyze\EFL_P1_id00
PGN FEEF
Давление масла\Increment Timer */
            
            Read_Parameter_24A290D3 = Time_FEEF_x00_data;
            
            Add_10FB8FA8 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_24A290D3));
            
            Saturation_1591EC01 = Add_10FB8FA8;
            if(Saturation_1591EC01 < Read_Parameter_24A290D3)
            {
                Saturation_1591EC01 = Read_Parameter_24A290D3;
            }
            else if(Saturation_1591EC01 > Add_10FB8FA8)
            {
                Saturation_1591EC01 = Add_10FB8FA8;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEEF_x00_data = Saturation_1591EC01;
            
        }
        
        if((Time_FEEF_x00_data) >= ((int32_t) 400))
        {
            /* API_CAN_Analyze\EFL_P1_id00
PGN FEEF
Давление масла\Reset signals */
            
            TimeOut_FEEF_x00_data = ((uint8_t) 1U);
            
            EngOilPres_x00_data = ((uint16_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419360542U))
        {
            /* API_CAN_Analyze\EFL_P1_id00
PGN FEEF
Давление масла\Receive Message */
            
            Time_FEEF_x1E_data = ((int32_t) 0);
            
            TimeOut_FEEF_x1E_data = ((uint8_t) 0U);
            
            EngClntLvl_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_25D911D3;
            int32_t Add_920CE84C;
            int32_t Saturation_D0DEEF20;
            /* API_CAN_Analyze\EFL_P1_id00
PGN FEEF
Давление масла\Increment Timer */
            
            Read_Parameter_25D911D3 = Time_FEEF_x1E_data;
            
            Add_920CE84C = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_25D911D3));
            
            Saturation_D0DEEF20 = Add_920CE84C;
            if(Saturation_D0DEEF20 < Read_Parameter_25D911D3)
            {
                Saturation_D0DEEF20 = Read_Parameter_25D911D3;
            }
            else if(Saturation_D0DEEF20 > Add_920CE84C)
            {
                Saturation_D0DEEF20 = Add_920CE84C;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEEF_x1E_data = Saturation_D0DEEF20;
            
        }
        
        if((Time_FEEF_x1E_data) >= ((int32_t) 400))
        {
            /* API_CAN_Analyze\EFL_P1_id00
PGN FEEF
Давление масла\Reset signals */
            
            TimeOut_FEEF_x1E_data = ((uint8_t) 1U);
            
            EngClntLvl_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EVCU_Sys
PGN FF3F * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 218054433U))
        {
            /* API_CAN_Analyze\EVCU_Sys
PGN FF3F\Receive Message */
            
            Time_FF3F_x21_data = ((int32_t) 0);
            
            TimeOut_FF3F_x21_data = ((uint8_t) 0U);
            
            AirPres4_0C_FF3F_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 1U))));
            
            AirPres3_0C_FF3F_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 5U), ((uint8_t) 1U))));
            
            CoolantLow_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 1U))));
            
        }
        else
        {
            int32_t Read_Parameter_78BD610E;
            int32_t Add_7B7CCAE3;
            int32_t Saturation_BC5E90EA;
            /* API_CAN_Analyze\EVCU_Sys
PGN FF3F\Increment Timer */
            
            Read_Parameter_78BD610E = Time_FF3F_x21_data;
            
            Add_7B7CCAE3 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_78BD610E));
            
            Saturation_BC5E90EA = Add_7B7CCAE3;
            if(Saturation_BC5E90EA < Read_Parameter_78BD610E)
            {
                Saturation_BC5E90EA = Read_Parameter_78BD610E;
            }
            else if(Saturation_BC5E90EA > Add_7B7CCAE3)
            {
                Saturation_BC5E90EA = Add_7B7CCAE3;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF3F_x21_data = Saturation_BC5E90EA;
            
        }
        
        if((Time_FF3F_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\EVCU_Sys
PGN FF3F\Reset signals */
            
            TimeOut_FF3F_x21_data = ((uint8_t) 1U);
            
            AirPres4_0C_FF3F_x21_data = ((uint8_t) 0U);
            
            AirPres3_0C_FF3F_x21_data = ((uint8_t) 0U);
            
            CoolantLow_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\DB
PGN: FF7D * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 218070305U))
        {
            /* API_CAN_Analyze\DB
PGN: FF7D\Receive Message */
            
            Time_FF7D_x21_data = ((int32_t) 0);
            
            TimeOut_FF7D_x21_data = ((uint8_t) 0U);
            
            WasherLvl_FF7D_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            WindshelHeat_FF7D_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 1U), ((uint8_t) 1U))));
            
            WindSideHeat_FF7D_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 1U))));
            
            SalonLight_FF7D_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 3U))));
            
            BusHatchBack_FF7D_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 1U))));
            
            BusHatchFront_FF7D_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 5U), ((uint8_t) 1U))));
            
            Hammer1_FF7D_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 1U))));
            
            Hammer2_FF7D_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 1U), ((uint8_t) 1U))));
            
            Hammer3_FF7D_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 1U))));
            
            Hammer4_FF7D_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 3U), ((uint8_t) 1U))));
            
            Hammer5_FF7D_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 4U), ((uint8_t) 1U))));
            
            Extinguisher1_FF7D_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 5U), ((uint8_t) 1U))));
            
            Extinguisher2_FF7D_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 6U), ((uint8_t) 1U))));
            
        }
        else
        {
            int32_t Read_Parameter_7D8C8454;
            int32_t Add_128BF46A;
            int32_t Saturation_FAF612F6;
            /* API_CAN_Analyze\DB
PGN: FF7D\Increment Timer */
            
            Read_Parameter_7D8C8454 = Time_FF7D_x21_data;
            
            Add_128BF46A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_7D8C8454));
            
            Saturation_FAF612F6 = Add_128BF46A;
            if(Saturation_FAF612F6 < Read_Parameter_7D8C8454)
            {
                Saturation_FAF612F6 = Read_Parameter_7D8C8454;
            }
            else if(Saturation_FAF612F6 > Add_128BF46A)
            {
                Saturation_FAF612F6 = Add_128BF46A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF7D_x21_data = Saturation_FAF612F6;
            
        }
        
        if((Time_FF7D_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\DB
PGN: FF7D\Reset signals */
            
            TimeOut_FF7D_x21_data = ((uint8_t) 1U);
            
            WasherLvl_FF7D_x21_data = ((uint8_t) 0U);
            
            WindshelHeat_FF7D_x21_data = ((uint8_t) 0U);
            
            WindSideHeat_FF7D_x21_data = ((uint8_t) 0U);
            
            SalonLight_FF7D_x21_data = ((uint8_t) 0U);
            
            BusHatchBack_FF7D_x21_data = ((uint8_t) 0U);
            
            BusHatchFront_FF7D_x21_data = ((uint8_t) 0U);
            
            FilterAirClogged_FF7D_x1E_data = ((uint8_t) 0U);
            
            Generator1Error_FF7D_x1E_data = ((uint8_t) 0U);
            
            Generator2Error_FF7D_x1E_data = ((uint8_t) 0U);
            
            Hammer1_FF7D_x1E_data = ((uint8_t) 0U);
            
            Hammer2_FF7D_x1E_data = ((uint8_t) 0U);
            
            Hammer3_FF7D_x1E_data = ((uint8_t) 0U);
            
            Hammer4_FF7D_x1E_data = ((uint8_t) 0U);
            
            Hammer5_FF7D_x1E_data = ((uint8_t) 0U);
            
            Extinguisher1_FF7D_x1E_data = ((uint8_t) 0U);
            
            Extinguisher2_FF7D_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\EVCU_Buttons
PGN: FF6E * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 218066465U))
        {
            /* API_CAN_Analyze\EVCU_Buttons
PGN: FF6E\Receive Message */
            
            Time_FF6E_x21_data = ((int32_t) 0);
            
            TimeOut_FF6E_x21_data = ((uint8_t) 0U);
            
            KneelingAuto_FF6E_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_E895EDA3;
            int32_t Add_AF1ECB30;
            int32_t Saturation_8C843C5C;
            /* API_CAN_Analyze\EVCU_Buttons
PGN: FF6E\Increment Timer */
            
            Read_Parameter_E895EDA3 = Time_FF6E_x21_data;
            
            Add_AF1ECB30 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_E895EDA3));
            
            Saturation_8C843C5C = Add_AF1ECB30;
            if(Saturation_8C843C5C < Read_Parameter_E895EDA3)
            {
                Saturation_8C843C5C = Read_Parameter_E895EDA3;
            }
            else if(Saturation_8C843C5C > Add_AF1ECB30)
            {
                Saturation_8C843C5C = Add_AF1ECB30;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF6E_x21_data = Saturation_8C843C5C;
            
        }
        
        if((Time_FF6E_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\EVCU_Buttons
PGN: FF6E\Reset signals */
            
            TimeOut_FF6E_x21_data = ((uint8_t) 1U);
            
            KneelingAuto_FF6E_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\MISC_DB1, EVCU_DB
PGN: FF79 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 218069281U))
        {
            /* API_CAN_Analyze\MISC_DB1, EVCU_DB
PGN: FF79\Receive Message */
            
            Time_FF79_x21_data = ((int32_t) 0);
            
            TimeOut_FF79_x21_data = ((uint8_t) 0U);
            
            SalonHeatBack_FF79_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            SalonHeatFront_FF79_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            SalonHeatFront_FF79_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            Door1State_FF79_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 0U), ((uint8_t) 3U))));
            
            Door2State_FF79_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 3U), ((uint8_t) 3U))));
            
            RampReq_FF79_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_3B75066D;
            int32_t Add_2CCBA590;
            int32_t Saturation_A4EAE9F3;
            /* API_CAN_Analyze\MISC_DB1, EVCU_DB
PGN: FF79\Increment Timer */
            
            Read_Parameter_3B75066D = Time_FF79_x21_data;
            
            Add_2CCBA590 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_3B75066D));
            
            Saturation_A4EAE9F3 = Add_2CCBA590;
            if(Saturation_A4EAE9F3 < Read_Parameter_3B75066D)
            {
                Saturation_A4EAE9F3 = Read_Parameter_3B75066D;
            }
            else if(Saturation_A4EAE9F3 > Add_2CCBA590)
            {
                Saturation_A4EAE9F3 = Add_2CCBA590;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF79_x21_data = Saturation_A4EAE9F3;
            
        }
        
        if((Time_FF79_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\MISC_DB1, EVCU_DB
PGN: FF79\Reset signals */
            
            TimeOut_FF79_x21_data = ((uint8_t) 1U);
            
            SalonHeatBack_FF79_x21_data = ((uint8_t) 0U);
            
            SalonHeatFront_FF79_x21_data = ((uint8_t) 0U);
            
            FlightIndicator_FF79_x21_data = ((uint8_t) 0U);
            
            Door1State_FF79_x21_data = ((uint8_t) 0U);
            
            Door2State_FF79_x21_data = ((uint8_t) 0U);
            
            RampReq_FF79_x21_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 218069287U))
        {
            /* API_CAN_Analyze\MISC_DB1, EVCU_DB
PGN: FF79\Receive Message */
            
            Time_FF79_x27_data = ((int32_t) 0);
            
            TimeOut_FF79_x27_data = ((uint8_t) 0U);
            
            KeySmart_FF79_x27_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_61D3D2B5;
            int32_t Add_3BE8FD95;
            int32_t Saturation_3D873D98;
            /* API_CAN_Analyze\MISC_DB1, EVCU_DB
PGN: FF79\Increment Timer */
            
            Read_Parameter_61D3D2B5 = Time_FF79_x27_data;
            
            Add_3BE8FD95 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_61D3D2B5));
            
            Saturation_3D873D98 = Add_3BE8FD95;
            if(Saturation_3D873D98 < Read_Parameter_61D3D2B5)
            {
                Saturation_3D873D98 = Read_Parameter_61D3D2B5;
            }
            else if(Saturation_3D873D98 > Add_3BE8FD95)
            {
                Saturation_3D873D98 = Add_3BE8FD95;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF79_x27_data = Saturation_3D873D98;
            
        }
        
        if((Time_FF79_x27_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\MISC_DB1, EVCU_DB
PGN: FF79\Reset signals */
            
            TimeOut_FF79_x27_data = ((uint8_t) 1U);
            
            KeySmart_FF79_x27_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 418381839U))
        {
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Receive Message */
            
            Time_F000_x0F_data = ((int32_t) 0);
            
            TimeOut_F000_x0F_data = ((uint8_t) 0U);
            
            RetarderTrq_x0F_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 125))));
            
        }
        else
        {
            int32_t Read_Parameter_3A7A670D;
            int32_t Add_6D48F944;
            int32_t Saturation_03AB1A46;
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Increment Timer */
            
            Read_Parameter_3A7A670D = Time_F000_x0F_data;
            
            Add_6D48F944 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_3A7A670D));
            
            Saturation_03AB1A46 = Add_6D48F944;
            if(Saturation_03AB1A46 < Read_Parameter_3A7A670D)
            {
                Saturation_03AB1A46 = Read_Parameter_3A7A670D;
            }
            else if(Saturation_03AB1A46 > Add_6D48F944)
            {
                Saturation_03AB1A46 = Add_6D48F944;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F000_x0F_data = Saturation_03AB1A46;
            
        }
        
        if((Time_F000_x0F_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Reset signals */
            
            TimeOut_F000_x0F_data = ((uint8_t) 1U);
            
            RetarderTrq_x0F_data = ((int32_t) 0);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 418381840U))
        {
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Receive Message */
            
            Time_F000_x10_data = ((int32_t) 0);
            
            TimeOut_F000_x10_data = ((uint8_t) 0U);
            
            RetarderTrq_x10_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 125))));
            
            Retarder_x10_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_792DB3C3;
            int32_t Add_37934D40;
            int32_t Saturation_8F7D42D6;
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Increment Timer */
            
            Read_Parameter_792DB3C3 = Time_F000_x10_data;
            
            Add_37934D40 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_792DB3C3));
            
            Saturation_8F7D42D6 = Add_37934D40;
            if(Saturation_8F7D42D6 < Read_Parameter_792DB3C3)
            {
                Saturation_8F7D42D6 = Read_Parameter_792DB3C3;
            }
            else if(Saturation_8F7D42D6 > Add_37934D40)
            {
                Saturation_8F7D42D6 = Add_37934D40;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F000_x10_data = Saturation_8F7D42D6;
            
        }
        
        if((Time_F000_x10_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Reset signals */
            
            TimeOut_F000_x10_data = ((uint8_t) 1U);
            
            RetarderTrq_x10_data = ((int32_t) 0);
            
            Retarder_x10_data = ((uint8_t) 1U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 418381865U))
        {
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Receive Message */
            
            Time_F000_x29_data = ((int32_t) 0);
            
            TimeOut_F000_x29_data = ((uint8_t) 0U);
            
            RetarderTrq_x29_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 125))));
            
        }
        else
        {
            int32_t Read_Parameter_636B0528;
            int32_t Add_F0516053;
            int32_t Saturation_92B3A033;
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Increment Timer */
            
            Read_Parameter_636B0528 = Time_F000_x29_data;
            
            Add_F0516053 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_636B0528));
            
            Saturation_92B3A033 = Add_F0516053;
            if(Saturation_92B3A033 < Read_Parameter_636B0528)
            {
                Saturation_92B3A033 = Read_Parameter_636B0528;
            }
            else if(Saturation_92B3A033 > Add_F0516053)
            {
                Saturation_92B3A033 = Add_F0516053;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F000_x29_data = Saturation_92B3A033;
            
        }
        
        if((Time_F000_x29_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер\Reset signals */
            
            TimeOut_F000_x29_data = ((uint8_t) 1U);
            
            RetarderTrq_x29_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\ET1
PGN: FEEE
EngineTemp * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419360256U))
        {
            /* API_CAN_Analyze\ET1
PGN: FEEE
EngineTemp\Receive Message */
            
            Time_FEEE_x00_data = ((int32_t) 0);
            
            TimeOut_FEEE_x00_data = ((uint8_t) 0U);
            
            EngClntTemp_x00_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
        }
        else
        {
            int32_t Read_Parameter_409187D0;
            int32_t Add_F9A7D54A;
            int32_t Saturation_BC3CEA81;
            /* API_CAN_Analyze\ET1
PGN: FEEE
EngineTemp\Increment Timer */
            
            Read_Parameter_409187D0 = Time_FEEE_x00_data;
            
            Add_F9A7D54A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_409187D0));
            
            Saturation_BC3CEA81 = Add_F9A7D54A;
            if(Saturation_BC3CEA81 < Read_Parameter_409187D0)
            {
                Saturation_BC3CEA81 = Read_Parameter_409187D0;
            }
            else if(Saturation_BC3CEA81 > Add_F9A7D54A)
            {
                Saturation_BC3CEA81 = Add_F9A7D54A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEEE_x00_data = Saturation_BC3CEA81;
            
        }
        
        if((Time_FEEE_x00_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\ET1
PGN: FEEE
EngineTemp\Reset signals */
            
            TimeOut_FEEE_x00_data = ((uint8_t) 1U);
            
            EngClntTemp_x00_data = ((int32_t) 0);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419360295U))
        {
            /* API_CAN_Analyze\ET1
PGN: FEEE
EngineTemp\Receive Message */
            
            Time_FEEE_x27_data = ((int32_t) 0);
            
            TimeOut_FEEE_x27_data = ((uint8_t) 0U);
            
            EngClntTemp_x27_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
        }
        else
        {
            int32_t Read_Parameter_98FB0E41;
            int32_t Add_C7BE8796;
            int32_t Saturation_8BD91449;
            /* API_CAN_Analyze\ET1
PGN: FEEE
EngineTemp\Increment Timer */
            
            Read_Parameter_98FB0E41 = Time_FEEE_x27_data;
            
            Add_C7BE8796 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_98FB0E41));
            
            Saturation_8BD91449 = Add_C7BE8796;
            if(Saturation_8BD91449 < Read_Parameter_98FB0E41)
            {
                Saturation_8BD91449 = Read_Parameter_98FB0E41;
            }
            else if(Saturation_8BD91449 > Add_C7BE8796)
            {
                Saturation_8BD91449 = Add_C7BE8796;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEEE_x27_data = Saturation_8BD91449;
            
        }
        
        if((Time_FEEE_x27_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\ET1
PGN: FEEE
EngineTemp\Reset signals */
            
            TimeOut_FEEE_x27_data = ((uint8_t) 1U);
            
            EngClntTemp_x27_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\ETC2
PGN: F005
Направление движения * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 418383107U))
        {
            /* API_CAN_Analyze\ETC2
PGN: F005
Направление движения\Receive Message */
            
            Time_F005_x03_data = ((int32_t) 0);
            
            TimeOut_F005_x03_data = ((uint8_t) 0U);
            
            DriveGear_x03_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            DriveRange_x03_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_A159B01D;
            int32_t Add_83314992;
            int32_t Saturation_465573EF;
            /* API_CAN_Analyze\ETC2
PGN: F005
Направление движения\Increment Timer */
            
            Read_Parameter_A159B01D = Time_F005_x03_data;
            
            Add_83314992 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_A159B01D));
            
            Saturation_465573EF = Add_83314992;
            if(Saturation_465573EF < Read_Parameter_A159B01D)
            {
                Saturation_465573EF = Read_Parameter_A159B01D;
            }
            else if(Saturation_465573EF > Add_83314992)
            {
                Saturation_465573EF = Add_83314992;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F005_x03_data = Saturation_465573EF;
            
        }
        
        if((Time_F005_x03_data) >= ((int32_t) 400))
        {
            /* API_CAN_Analyze\ETC2
PGN: F005
Направление движения\Reset signals */
            
            TimeOut_F005_x03_data = ((uint8_t) 1U);
            
            DriveGear_x03_data = ((uint8_t) 0U);
            
            DriveRange_x03_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\ETC7_id03
PGN: FE4A
AKPP * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419318275U))
        {
            /* API_CAN_Analyze\ETC7_id03
PGN: FE4A
AKPP\Receive Message */
            
            Time_FE4A_x03_data = ((int32_t) 0);
            
            TimeOut_FE4A_x03_data = ((uint8_t) 0U);
            
            TransInhibit_x03_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            TransWarning_x03_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_AE3A19BB;
            int32_t Add_DDB4700B;
            int32_t Saturation_66F5C3D6;
            /* API_CAN_Analyze\ETC7_id03
PGN: FE4A
AKPP\Increment Timer */
            
            Read_Parameter_AE3A19BB = Time_FE4A_x03_data;
            
            Add_DDB4700B = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_AE3A19BB));
            
            Saturation_66F5C3D6 = Add_DDB4700B;
            if(Saturation_66F5C3D6 < Read_Parameter_AE3A19BB)
            {
                Saturation_66F5C3D6 = Read_Parameter_AE3A19BB;
            }
            else if(Saturation_66F5C3D6 > Add_DDB4700B)
            {
                Saturation_66F5C3D6 = Add_DDB4700B;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE4A_x03_data = Saturation_66F5C3D6;
            
        }
        
        if((Time_FE4A_x03_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\ETC7_id03
PGN: FE4A
AKPP\Reset signals */
            
            TimeOut_FE4A_x03_data = ((uint8_t) 1U);
            
            TransInhibit_x03_data = ((uint8_t) 0U);
            
            TransWarning_x03_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // Параметры Аргентина и Лондон */

    /* // G */

    {
        /* / * API_CAN_Analyze\ISA_Status
PGN FF22 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419373611U))
        {
            /* API_CAN_Analyze\ISA_Status
PGN FF22\Receive Message */
            
            Time_FF22_x2B_data = ((int32_t) 0);
            
            TimeOut_FF22_x2B_data = ((uint8_t) 0U);
            
            SpeedLim_FF22_x2B_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            SpeedLimState_FF22_x2B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_3301EEAC;
            int32_t Add_96CA6E0B;
            int32_t Saturation_9F6E9435;
            /* API_CAN_Analyze\ISA_Status
PGN FF22\Increment Timer */
            
            Read_Parameter_3301EEAC = Time_FF79_x21_data;
            
            Add_96CA6E0B = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_3301EEAC));
            
            Saturation_9F6E9435 = Add_96CA6E0B;
            if(Saturation_9F6E9435 < Read_Parameter_3301EEAC)
            {
                Saturation_9F6E9435 = Read_Parameter_3301EEAC;
            }
            else if(Saturation_9F6E9435 > Add_96CA6E0B)
            {
                Saturation_9F6E9435 = Add_96CA6E0B;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF79_x21_data = Saturation_9F6E9435;
            
        }
        
        if((Time_FF22_x2B_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\ISA_Status
PGN FF22\Reset signals */
            
            TimeOut_FF22_x2B_data = ((uint8_t) 1U);
            
            SpeedLim_FF22_x2B_data = ((int32_t) 0);
            
            SpeedLimState_FF22_x2B_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PROP_Body1,
PROP_Powertrain1
PGN FF01 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419365153U))
        {
            /* API_CAN_Analyze\PROP_Body1,
PROP_Powertrain1
PGN FF01\Receive Message */
            
            Time_FF01_x21_data = ((int32_t) 0);
            
            TimeOut_FF01_x21_data = ((uint8_t) 0U);
            
            PassangerReq_FF01_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            RampReq_FF01_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            ServDoor1Open_FF01_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            ServDoor2Open_FF01_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            DriverInSeat_FF01_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_5B078C9A;
            int32_t Add_59996EA3;
            int32_t Saturation_F078558A;
            /* API_CAN_Analyze\PROP_Body1,
PROP_Powertrain1
PGN FF01\Increment Timer */
            
            Read_Parameter_5B078C9A = Time_FF01_x21_data;
            
            Add_59996EA3 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_5B078C9A));
            
            Saturation_F078558A = Add_59996EA3;
            if(Saturation_F078558A < Read_Parameter_5B078C9A)
            {
                Saturation_F078558A = Read_Parameter_5B078C9A;
            }
            else if(Saturation_F078558A > Add_59996EA3)
            {
                Saturation_F078558A = Add_59996EA3;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF01_x21_data = Saturation_F078558A;
            
        }
        
        if((Time_FF01_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PROP_Body1,
PROP_Powertrain1
PGN FF01\Reset signals */
            
            TimeOut_FF01_x21_data = ((uint8_t) 1U);
            
            PassangerReq_FF01_x21_data = ((uint8_t) 0U);
            
            RampReq_FF01_x21_data = ((uint8_t) 0U);
            
            ServDoor1Open_FF01_x21_data = ((uint8_t) 0U);
            
            ServDoor2Open_FF01_x21_data = ((uint8_t) 0U);
            
            DriverInSeat_FF01_x21_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419365210U))
        {
            /* API_CAN_Analyze\PROP_Body1,
PROP_Powertrain1
PGN FF01\Receive Message */
            
            Time_FF01_x5A_data = ((int32_t) 0);
            
            TimeOut_FF01_x5A_data = ((uint8_t) 0U);
            
            ChargeTime_FF01_x21_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            Consumption_FF01_x21_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            ConsumptionAverage_FF01_x21_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            Joystic_FF01_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_4E2037DE;
            int32_t Add_6DCF9463;
            int32_t Saturation_2FFA8A8D;
            /* API_CAN_Analyze\PROP_Body1,
PROP_Powertrain1
PGN FF01\Increment Timer */
            
            Read_Parameter_4E2037DE = Time_FF01_x5A_data;
            
            Add_6DCF9463 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_4E2037DE));
            
            Saturation_2FFA8A8D = Add_6DCF9463;
            if(Saturation_2FFA8A8D < Read_Parameter_4E2037DE)
            {
                Saturation_2FFA8A8D = Read_Parameter_4E2037DE;
            }
            else if(Saturation_2FFA8A8D > Add_6DCF9463)
            {
                Saturation_2FFA8A8D = Add_6DCF9463;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF01_x5A_data = Saturation_2FFA8A8D;
            
        }
        
        if((Time_FF01_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PROP_Body1,
PROP_Powertrain1
PGN FF01\Reset signals */
            
            TimeOut_FF01_x5A_data = ((uint8_t) 1U);
            
            ChargeTime_FF01_x21_data = ((int16_t) 0);
            
            Consumption_FF01_x21_data = ((uint16_t) 0U);
            
            ConsumptionAverage_FF01_x21_data = ((uint16_t) 0U);
            
            Joystic_FF01_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PROP_Powertrain2
PGN FF02 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419365466U))
        {
            /* API_CAN_Analyze\PROP_Powertrain2
PGN FF02\Receive Message */
            
            Time_FF01_x21_data = ((int32_t) 0);
            
            TimeOut_FF01_x21_data = ((uint8_t) 0U);
            
            HVBatteryTempState_FF02_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            MotorTempState_FF02_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_61F7A516;
            int32_t Add_5B949F1D;
            int32_t Saturation_CB067E4F;
            /* API_CAN_Analyze\PROP_Powertrain2
PGN FF02\Increment Timer */
            
            Read_Parameter_61F7A516 = Time_FF02_x5A_data;
            
            Add_5B949F1D = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_61F7A516));
            
            Saturation_CB067E4F = Add_5B949F1D;
            if(Saturation_CB067E4F < Read_Parameter_61F7A516)
            {
                Saturation_CB067E4F = Read_Parameter_61F7A516;
            }
            else if(Saturation_CB067E4F > Add_5B949F1D)
            {
                Saturation_CB067E4F = Add_5B949F1D;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF02_x5A_data = Saturation_CB067E4F;
            
        }
        
        if((Time_FF02_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PROP_Powertrain2
PGN FF02\Reset signals */
            
            TimeOut_FF02_x5A_data = ((uint8_t) 1U);
            
            HVBatteryTempState_FF02_x5A_data = ((uint8_t) 0U);
            
            MotorTempState_FF02_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\GPBAC/???\CM1
PGN: FE00 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419299361U))
        {
            /* API_CAN_Analyze\GPBAC/???\CM1
PGN: FE00\Receive Message */
            
            Time_FE00_x21_data = ((int32_t) 0);
            
            TimeOut_FE00_x21_data = ((uint8_t) 0U);
            
            AuxHeatClntPumpReq_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            AuxHeatModeReq_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_C91FFA67;
            int32_t Add_F5285875;
            int32_t Saturation_11A16E15;
            /* API_CAN_Analyze\GPBAC/???\CM1
PGN: FE00\Increment Timer */
            
            Read_Parameter_C91FFA67 = Time_FE00_x21_data;
            
            Add_F5285875 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_C91FFA67));
            
            Saturation_11A16E15 = Add_F5285875;
            if(Saturation_11A16E15 < Read_Parameter_C91FFA67)
            {
                Saturation_11A16E15 = Read_Parameter_C91FFA67;
            }
            else if(Saturation_11A16E15 > Add_F5285875)
            {
                Saturation_11A16E15 = Add_F5285875;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE00_x21_data = Saturation_11A16E15;
            
        }
        
        if((Time_FE00_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\GPBAC/???\CM1
PGN: FE00\Reset signals */
            
            TimeOut_FE00_x21_data = ((uint8_t) 1U);
            
            AuxHeatClntPumpReq_x21_data = ((uint8_t) 0U);
            
            AuxHeatModeReq_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // Параметры Троллейбус */

    /* // L */

    {
        /* / * API_CAN_Analyze\LCMD,
PGN=FE41
Световые приборы * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217989409U))
        {
            /* API_CAN_Analyze\LCMD,
PGN=FE41
Световые приборы\Receive Message */
            
            Time_FE41_x21_data = ((int32_t) 0);
            
            TimeOut_FE41_x21_data = ((uint8_t) 0U);
            
            LowBeamCmd_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            HighBeamCmd_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            FogFrontCmd_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            TurnRightCmd_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            TurnLeftCmd_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            SideLightCmd_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            FogRearCmd_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_FEC9A6A2;
            int32_t Add_C4477A42;
            int32_t Saturation_733CD640;
            /* API_CAN_Analyze\LCMD,
PGN=FE41
Световые приборы\Increment Timer */
            
            Read_Parameter_FEC9A6A2 = Time_FE41_x21_data;
            
            Add_C4477A42 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_FEC9A6A2));
            
            Saturation_733CD640 = Add_C4477A42;
            if(Saturation_733CD640 < Read_Parameter_FEC9A6A2)
            {
                Saturation_733CD640 = Read_Parameter_FEC9A6A2;
            }
            else if(Saturation_733CD640 > Add_C4477A42)
            {
                Saturation_733CD640 = Add_C4477A42;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE41_x21_data = Saturation_733CD640;
            
        }
        
        if((Time_FE41_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\LCMD,
PGN=FE41
Световые приборы\Reset signals */
            
            TimeOut_FE41_x21_data = ((uint8_t) 1U);
            
            LowBeamCmd_x21_data = ((uint8_t) 0U);
            
            HighBeamCmd_x21_data = ((uint8_t) 0U);
            
            FogFrontCmd_x21_data = ((uint8_t) 0U);
            
            TurnRightCmd_x21_data = ((uint8_t) 0U);
            
            TurnLeftCmd_x21_data = ((uint8_t) 0U);
            
            SideLightCmd_x21_data = ((uint8_t) 0U);
            
            FogRearCmd_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\LD
PGN: FE40
Световые приборы * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217989153U))
        {
            /* API_CAN_Analyze\LD
PGN: FE40
Световые приборы\Receive Message */
            
            Time_FE40_x21_data = ((int32_t) 0);
            
            TimeOut_FE40_x21_data = ((uint8_t) 0U);
            
            RunLightFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            LowBeamFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            HighBeamFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            FogFrontFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            TurnRightFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            TurnLeftFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            SideLightFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            FogRearFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            OEM1Opt1FB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_380029E8;
            int32_t Add_9EC27789;
            int32_t Saturation_F5E6B22F;
            /* API_CAN_Analyze\LD
PGN: FE40
Световые приборы\Increment Timer */
            
            Read_Parameter_380029E8 = Time_FE40_x21_data;
            
            Add_9EC27789 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_380029E8));
            
            Saturation_F5E6B22F = Add_9EC27789;
            if(Saturation_F5E6B22F < Read_Parameter_380029E8)
            {
                Saturation_F5E6B22F = Read_Parameter_380029E8;
            }
            else if(Saturation_F5E6B22F > Add_9EC27789)
            {
                Saturation_F5E6B22F = Add_9EC27789;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE40_x21_data = Saturation_F5E6B22F;
            
        }
        
        if((Time_FE40_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\LD
PGN: FE40
Световые приборы\Reset signals */
            
            TimeOut_FE40_x21_data = ((uint8_t) 1U);
            
            RunLightFB_x21_data = ((uint8_t) 0U);
            
            LowBeamFB_x21_data = ((uint8_t) 0U);
            
            HighBeamFB_x21_data = ((uint8_t) 0U);
            
            FogFrontFB_x21_data = ((uint8_t) 0U);
            
            TurnRightFB_x21_data = ((uint8_t) 0U);
            
            TurnLeftFB_x21_data = ((uint8_t) 0U);
            
            SideLightFB_x21_data = ((uint8_t) 0U);
            
            FogRearFB_x21_data = ((uint8_t) 0U);
            
            OEM1Opt1FB_x21_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419315742U))
        {
            /* API_CAN_Analyze\LD
PGN: FE40
Световые приборы\Receive Message */
            
            Time_FE40_x1E_data = ((int32_t) 0);
            
            TimeOut_FE40_x1E_data = ((uint8_t) 0U);
            
            RunLightFB_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            LowBeamFB_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            HighBeamFB_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            FogFrontFB_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            TurnRightFB_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            TurnLeftFB_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            SideLightFB_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            FogRearFB_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_7C4F6B6F;
            int32_t Add_5707C9C0;
            int32_t Saturation_211299F2;
            /* API_CAN_Analyze\LD
PGN: FE40
Световые приборы\Increment Timer */
            
            Read_Parameter_7C4F6B6F = Time_FE40_x1E_data;
            
            Add_5707C9C0 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_7C4F6B6F));
            
            Saturation_211299F2 = Add_5707C9C0;
            if(Saturation_211299F2 < Read_Parameter_7C4F6B6F)
            {
                Saturation_211299F2 = Read_Parameter_7C4F6B6F;
            }
            else if(Saturation_211299F2 > Add_5707C9C0)
            {
                Saturation_211299F2 = Add_5707C9C0;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE40_x1E_data = Saturation_211299F2;
            
        }
        
        if((Time_FE40_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\LD
PGN: FE40
Световые приборы\Reset signals */
            
            TimeOut_FE40_x1E_data = ((uint8_t) 1U);
            
            RunLightFB_x1E_data = ((uint8_t) 0U);
            
            LowBeamFB_x1E_data = ((uint8_t) 0U);
            
            HighBeamFB_x1E_data = ((uint8_t) 0U);
            
            FogFrontFB_x1E_data = ((uint8_t) 0U);
            
            TurnRightFB_x1E_data = ((uint8_t) 0U);
            
            TurnLeftFB_x1E_data = ((uint8_t) 0U);
            
            SideLightFB_x1E_data = ((uint8_t) 0U);
            
            FogRearFB_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\AUXIO5
PGN: 4031
MotorParam * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 406860122U))
        {
            /* API_CAN_Analyze\AUXIO5
PGN: 4031
MotorParam\Receive Message */
            
            Time_4031_x5A_data = ((int32_t) 0);
            
            TimeOut_4031_x5A_data = ((uint8_t) 0U);
            
            HVNetPol_4031_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            DriveTrqCur_4031_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 1024))));
            
            ReadyDrive_4031_x5A_data = ((uint16_t) ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 16U)))));
            
            DriveTrqCurReq_4031_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 1024))));
            
        }
        else
        {
            int32_t Read_Parameter_B94EFEAB;
            int32_t Add_A000D13A;
            int32_t Saturation_2C4E09BB;
            /* API_CAN_Analyze\AUXIO5
PGN: 4031
MotorParam\Increment Timer */
            
            Read_Parameter_B94EFEAB = Time_4031_x5A_data;
            
            Add_A000D13A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_B94EFEAB));
            
            Saturation_2C4E09BB = Add_A000D13A;
            if(Saturation_2C4E09BB < Read_Parameter_B94EFEAB)
            {
                Saturation_2C4E09BB = Read_Parameter_B94EFEAB;
            }
            else if(Saturation_2C4E09BB > Add_A000D13A)
            {
                Saturation_2C4E09BB = Add_A000D13A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_4031_x5A_data = Saturation_2C4E09BB;
            
        }
        
        if((Time_4031_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\AUXIO5
PGN: 4031
MotorParam\Reset signals */
            
            TimeOut_4031_x5A_data = ((uint8_t) 1U);
            
            HVNetPol_4031_x5A_data = ((uint8_t) 0U);
            
            DriveTrqCur_4031_x5A_data = ((int32_t) 0);
            
            ReadyDrive_4031_x5A_data = ((uint16_t) 0U);
            
            DriveTrqCurReq_4031_x5A_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PTAD_EVSE1DCS1
PGN: FAB8
Сеть питания * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419084378U))
        {
            /* API_CAN_Analyze\PTAD_EVSE1DCS1
PGN: FAB8
Сеть питания\Receive Message */
            
            Time_FAB8_x5A_data = ((int32_t) 0);
            
            TimeOut_FAB8_x5A_data = ((uint8_t) 0U);
            
            HVBatCharge_FAB8_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
            HVNetV_FAB8_x5A_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            HVNetCur_FAB8_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 32000))));
            
        }
        else
        {
            int32_t Read_Parameter_A896EE0F;
            int32_t Add_43D6F440;
            int32_t Saturation_B659D46F;
            /* API_CAN_Analyze\PTAD_EVSE1DCS1
PGN: FAB8
Сеть питания\Increment Timer */
            
            Read_Parameter_A896EE0F = Time_FAB8_x5A_data;
            
            Add_43D6F440 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_A896EE0F));
            
            Saturation_B659D46F = Add_43D6F440;
            if(Saturation_B659D46F < Read_Parameter_A896EE0F)
            {
                Saturation_B659D46F = Read_Parameter_A896EE0F;
            }
            else if(Saturation_B659D46F > Add_43D6F440)
            {
                Saturation_B659D46F = Add_43D6F440;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FAB8_x5A_data = Saturation_B659D46F;
            
        }
        
        if((Time_FAB8_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PTAD_EVSE1DCS1
PGN: FAB8
Сеть питания\Reset signals */
            
            TimeOut_FAB8_x5A_data = ((uint8_t) 1U);
            
            HVBatCharge_FAB8_x5A_data = ((uint8_t) 0U);
            
            HVNetV_FAB8_x5A_data = ((int32_t) 0);
            
            HVNetCur_FAB8_x5A_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PTAD_AUXIO4_PS49
PGN: A531
Токоприемник * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 413479258U))
        {
            /* API_CAN_Analyze\PTAD_AUXIO4_PS49
PGN: A531
Токоприемник\Receive Message */
            
            Time_A531_x5A_data = ((int32_t) 0);
            
            TimeOut_A531_x5A_data = ((uint8_t) 0U);
            
            HVNetConLeft_A531_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            HVNetConRight_A531_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            HVNetConError_A531_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_97255D1A;
            int32_t Add_D47B2C49;
            int32_t Saturation_53E98F68;
            /* API_CAN_Analyze\PTAD_AUXIO4_PS49
PGN: A531
Токоприемник\Increment Timer */
            
            Read_Parameter_97255D1A = Time_A531_x5A_data;
            
            Add_D47B2C49 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_97255D1A));
            
            Saturation_53E98F68 = Add_D47B2C49;
            if(Saturation_53E98F68 < Read_Parameter_97255D1A)
            {
                Saturation_53E98F68 = Read_Parameter_97255D1A;
            }
            else if(Saturation_53E98F68 > Add_D47B2C49)
            {
                Saturation_53E98F68 = Add_D47B2C49;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_A531_x5A_data = Saturation_53E98F68;
            
        }
        
        if((Time_A531_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PTAD_AUXIO4_PS49
PGN: A531
Токоприемник\Reset signals */
            
            TimeOut_A531_x5A_data = ((uint8_t) 1U);
            
            HVNetConLeft_A531_x5A_data = ((uint8_t) 0U);
            
            HVNetConRight_A531_x5A_data = ((uint8_t) 0U);
            
            HVNetConError_A531_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PTAD_HVESSS1
PGN: F096
Главный контакт * / */
    
        /* // SEE LONDON 
        HVESSS1
        PGN F096
        ChargeStatus
         */
        
    }

    {
        /* / * API_CAN_Analyze\PTAD_HSS1
PGN: FCC2
BatteryCapacity * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419218010U))
        {
            /* API_CAN_Analyze\PTAD_HSS1
PGN: FCC2
BatteryCapacity\Receive Message */
            
            Time_FCC2_x5A_data = ((int32_t) 0);
            
            TimeOut_FCC2_x5A_data = ((uint8_t) 0U);
            
            EDBrake_FCC2_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            HVBatCharge_FCC2_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TripMode_FCC2_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
            ChargeCable_FCC2_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_9C384920;
            int32_t Add_BCE7492E;
            int32_t Saturation_41330145;
            /* API_CAN_Analyze\PTAD_HSS1
PGN: FCC2
BatteryCapacity\Increment Timer */
            
            Read_Parameter_9C384920 = Time_FCC2_x5A_data;
            
            Add_BCE7492E = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_9C384920));
            
            Saturation_41330145 = Add_BCE7492E;
            if(Saturation_41330145 < Read_Parameter_9C384920)
            {
                Saturation_41330145 = Read_Parameter_9C384920;
            }
            else if(Saturation_41330145 > Add_BCE7492E)
            {
                Saturation_41330145 = Add_BCE7492E;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FCC2_x5A_data = Saturation_41330145;
            
        }
        
        if((Time_FCC2_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PTAD_HSS1
PGN: FCC2
BatteryCapacity\Reset signals */
            
            TimeOut_FCC2_x5A_data = ((uint8_t) 1U);
            
            EDBrake_FCC2_x5A_data = ((uint8_t) 0U);
            
            HVBatCharge_FCC2_x5A_data = ((uint8_t) 0U);
            
            TripMode_FCC2_x5A_data = ((uint8_t) 0U);
            
            ChargeCable_FCC2_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // H */

    {
        /* / * API_CAN_Analyze\PTAD_MG1II
PGN: FB6A
Изоляция * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419129946U))
        {
            /* API_CAN_Analyze\PTAD_MG1II
PGN: FB6A
Изоляция\Receive Message */
            
            Time_FB6A_x5A_data = ((int32_t) 0);
            
            TimeOut_FB6A_x5A_data = ((uint8_t) 0U);
            
            HVIsolationSt2_FB6A_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
            HVIsolationSt1_FB6A_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_71142814;
            int32_t Add_AE7AE30F;
            int32_t Saturation_0A6E7A03;
            /* API_CAN_Analyze\PTAD_MG1II
PGN: FB6A
Изоляция\Increment Timer */
            
            Read_Parameter_71142814 = Time_FB6A_x5A_data;
            
            Add_AE7AE30F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_71142814));
            
            Saturation_0A6E7A03 = Add_AE7AE30F;
            if(Saturation_0A6E7A03 < Read_Parameter_71142814)
            {
                Saturation_0A6E7A03 = Read_Parameter_71142814;
            }
            else if(Saturation_0A6E7A03 > Add_AE7AE30F)
            {
                Saturation_0A6E7A03 = Add_AE7AE30F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FB6A_x5A_data = Saturation_0A6E7A03;
            
        }
        
        if((Time_FB6A_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PTAD_MG1II
PGN: FB6A
Изоляция\Reset signals */
            
            TimeOut_FB6A_x5A_data = ((uint8_t) 1U);
            
            HVIsolationSt1_FB6A_x5A_data = ((uint8_t) 0U);
            
            HVIsolationSt2_FB6A_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PTAD_MG1IR2
PGN: FB73
RefVoltage * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217805807U))
        {
            /* API_CAN_Analyze\PTAD_MG1IR2
PGN: FB73
RefVoltage\Receive Message */
            
            Time_FB73_xEF_data = ((int32_t) 0);
            
            TimeOut_FB73_xEF_data = ((uint8_t) 0U);
            
            DriveRefV_FB73_xEF_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_989A7995;
            int32_t Add_D14ED8BA;
            int32_t Saturation_03C9DA38;
            /* API_CAN_Analyze\PTAD_MG1IR2
PGN: FB73
RefVoltage\Increment Timer */
            
            Read_Parameter_989A7995 = Time_FB73_xEF_data;
            
            Add_D14ED8BA = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_989A7995));
            
            Saturation_03C9DA38 = Add_D14ED8BA;
            if(Saturation_03C9DA38 < Read_Parameter_989A7995)
            {
                Saturation_03C9DA38 = Read_Parameter_989A7995;
            }
            else if(Saturation_03C9DA38 > Add_D14ED8BA)
            {
                Saturation_03C9DA38 = Add_D14ED8BA;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FB73_xEF_data = Saturation_03C9DA38;
            
        }
        
        if((Time_FB73_xEF_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PTAD_MG1IR2
PGN: FB73
RefVoltage\Reset signals */
            
            TimeOut_FB73_xEF_data = ((uint8_t) 1U);
            
            DriveRefV_FB73_xEF_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\PTAD_MG1IS1
PGN: FB74
TractionVoltage * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217806063U))
        {
            /* API_CAN_Analyze\PTAD_MG1IS1
PGN: FB74
TractionVoltage\Receive Message */
            
            Time_FB74_xEF_data = ((int32_t) 0);
            
            TimeOut_FB74_xEF_data = ((uint8_t) 0U);
            
            DriveV_FB74_xEF_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 4U), ((uint8_t) 12U)))) - ((int32_t) 2000))));
            
        }
        else
        {
            int32_t Read_Parameter_D30AC60E;
            int32_t Add_C49629E4;
            int32_t Saturation_3C714F5F;
            /* API_CAN_Analyze\PTAD_MG1IS1
PGN: FB74
TractionVoltage\Increment Timer */
            
            Read_Parameter_D30AC60E = Time_FB74_xEF_data;
            
            Add_C49629E4 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_D30AC60E));
            
            Saturation_3C714F5F = Add_C49629E4;
            if(Saturation_3C714F5F < Read_Parameter_D30AC60E)
            {
                Saturation_3C714F5F = Read_Parameter_D30AC60E;
            }
            else if(Saturation_3C714F5F > Add_C49629E4)
            {
                Saturation_3C714F5F = Add_C49629E4;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FB74_xEF_data = Saturation_3C714F5F;
            
        }
        
        if((Time_FB74_xEF_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\PTAD_MG1IS1
PGN: FB74
TractionVoltage\Reset signals */
            
            TimeOut_FB74_xEF_data = ((uint8_t) 1U);
            
            DriveV_FB74_xEF_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\HVESSD1 (1/2)
PGN F090
TractionBatteryLvl * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217092186U))
        {
            /* API_CAN_Analyze\HVESSD1 (1/2)
PGN F090
TractionBatteryLvl\Receive Message */
            
            Time_F090_x5A_data = ((int32_t) 0);
            
            TimeOut_F090_x5A_data = ((uint8_t) 0U);
            
            HVBatteryV_x5A_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_4E1D4DAA;
            int32_t Add_0DC5D4DF;
            int32_t Saturation_4EFA8CAE;
            /* API_CAN_Analyze\HVESSD1 (1/2)
PGN F090
TractionBatteryLvl\Increment Timer */
            
            Read_Parameter_4E1D4DAA = Time_F090_x5A_data;
            
            Add_0DC5D4DF = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_4E1D4DAA));
            
            Saturation_4EFA8CAE = Add_0DC5D4DF;
            if(Saturation_4EFA8CAE < Read_Parameter_4E1D4DAA)
            {
                Saturation_4EFA8CAE = Read_Parameter_4E1D4DAA;
            }
            else if(Saturation_4EFA8CAE > Add_0DC5D4DF)
            {
                Saturation_4EFA8CAE = Add_0DC5D4DF;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F090_x5A_data = Saturation_4EFA8CAE;
            
        }
        
        if((Time_F090_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\HVESSD1 (1/2)
PGN F090
TractionBatteryLvl\Reset signals */
            
            TimeOut_F090_x5A_data = ((uint8_t) 1U);
            
            HVBatteryV_x5A_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\HVESSD2
PGN F091
BatteryCell * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217092442U))
        {
            /* API_CAN_Analyze\HVESSD2
PGN F091
BatteryCell\Receive Message */
            
            Time_F091_x5A_data = ((int32_t) 0);
            
            TimeOut_F091_x5A_data = ((uint8_t) 0U);
            
            HVCharge_x5A_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            HVCellHighestV_x5A_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
            HVCellLowestV_x5A_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_EA2B58EA;
            int32_t Add_4AC90AF4;
            int32_t Saturation_897AC8ED;
            /* API_CAN_Analyze\HVESSD2
PGN F091
BatteryCell\Increment Timer */
            
            Read_Parameter_EA2B58EA = Time_F091_x5A_data;
            
            Add_4AC90AF4 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_EA2B58EA));
            
            Saturation_897AC8ED = Add_4AC90AF4;
            if(Saturation_897AC8ED < Read_Parameter_EA2B58EA)
            {
                Saturation_897AC8ED = Read_Parameter_EA2B58EA;
            }
            else if(Saturation_897AC8ED > Add_4AC90AF4)
            {
                Saturation_897AC8ED = Add_4AC90AF4;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F091_x5A_data = Saturation_897AC8ED;
            
        }
        
        if((Time_F091_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\HVESSD2
PGN F091
BatteryCell\Reset signals */
            
            TimeOut_F091_x5A_data = ((uint8_t) 1U);
            
            HVCharge_x5A_data = ((uint16_t) 0U);
            
            HVCellHighestV_x5A_data = ((uint16_t) 0U);
            
            HVCellLowestV_x5A_data = ((uint16_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\HVESSD3
PGN F092
BatteryCellTemp * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217092698U))
        {
            /* API_CAN_Analyze\HVESSD3
PGN F092
BatteryCellTemp\Receive Message */
            
            Time_F092_x5A_data = ((int32_t) 0);
            
            TimeOut_F092_x5A_data = ((uint8_t) 0U);
            
            HVCellHighestT_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 8736))));
            
            HVCellLowestT_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 8736))));
            
        }
        else
        {
            int32_t Read_Parameter_12B3A2BA;
            int32_t Add_6F156483;
            int32_t Saturation_88543582;
            /* API_CAN_Analyze\HVESSD3
PGN F092
BatteryCellTemp\Increment Timer */
            
            Read_Parameter_12B3A2BA = Time_F092_x5A_data;
            
            Add_6F156483 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_12B3A2BA));
            
            Saturation_88543582 = Add_6F156483;
            if(Saturation_88543582 < Read_Parameter_12B3A2BA)
            {
                Saturation_88543582 = Read_Parameter_12B3A2BA;
            }
            else if(Saturation_88543582 > Add_6F156483)
            {
                Saturation_88543582 = Add_6F156483;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F092_x5A_data = Saturation_88543582;
            
        }
        
        if((Time_F092_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\HVESSD3
PGN F092
BatteryCellTemp\Reset signals */
            
            TimeOut_F092_x5A_data = ((uint8_t) 1U);
            
            HVCellHighestT_x5A_data = ((int32_t) 0);
            
            HVCellLowestT_x5A_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\HVESSD10
PGN F10C
IsolationTest * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217123930U))
        {
            /* API_CAN_Analyze\HVESSD10
PGN F10C
IsolationTest\Receive Message */
            
            Time_F10C_x5A_data = ((int32_t) 0);
            
            TimeOut_F10C_x5A_data = ((uint8_t) 0U);
            
            HVIsolationRes_x5A_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_4399D4C8;
            int32_t Add_004A2FF1;
            int32_t Saturation_10E8F8BC;
            /* API_CAN_Analyze\HVESSD10
PGN F10C
IsolationTest\Increment Timer */
            
            Read_Parameter_4399D4C8 = Time_F10C_x5A_data;
            
            Add_004A2FF1 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_4399D4C8));
            
            Saturation_10E8F8BC = Add_004A2FF1;
            if(Saturation_10E8F8BC < Read_Parameter_4399D4C8)
            {
                Saturation_10E8F8BC = Read_Parameter_4399D4C8;
            }
            else if(Saturation_10E8F8BC > Add_004A2FF1)
            {
                Saturation_10E8F8BC = Add_004A2FF1;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F10C_x5A_data = Saturation_10E8F8BC;
            
        }
        
        if((Time_F10C_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\HVESSD10
PGN F10C
IsolationTest\Reset signals */
            
            TimeOut_F10C_x5A_data = ((uint8_t) 1U);
            
            HVIsolationRes_x5A_data = ((uint16_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\HVESSS1
PGN F096
ChargeStatus * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217093722U))
        {
            /* API_CAN_Analyze\HVESSS1
PGN F096
ChargeStatus\Receive Message */
            
            Time_F096_x5A_data = ((int32_t) 0);
            
            TimeOut_F096_x5A_data = ((uint8_t) 0U);
            
            HVCon_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            HVConPreCharge_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            HVIsolationTest_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 4U))));
            
            HVBatConOff_F096_x5A_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_88E47564;
            int32_t Add_2BCA558F;
            int32_t Saturation_464E0266;
            /* API_CAN_Analyze\HVESSS1
PGN F096
ChargeStatus\Increment Timer */
            
            Read_Parameter_88E47564 = Time_F096_x5A_data;
            
            Add_2BCA558F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_88E47564));
            
            Saturation_464E0266 = Add_2BCA558F;
            if(Saturation_464E0266 < Read_Parameter_88E47564)
            {
                Saturation_464E0266 = Read_Parameter_88E47564;
            }
            else if(Saturation_464E0266 > Add_2BCA558F)
            {
                Saturation_464E0266 = Add_2BCA558F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_F096_x5A_data = Saturation_464E0266;
            
        }
        
        if((Time_F096_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\HVESSS1
PGN F096
ChargeStatus\Reset signals */
            
            TimeOut_F096_x5A_data = ((uint8_t) 1U);
            
            HVCon_x5A_data = ((uint8_t) 0U);
            
            HVConPreCharge_x5A_data = ((uint8_t) 0U);
            
            HVIsolationTest_x5A_data = ((uint8_t) 0U);
            
            HVBatConOff_F096_x5A_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // Параметры Белес такие же как у КАМАЗа */

    /* // M */

    {
        /* / * API_CAN_Analyze\MG1IMT
PGN FB71
EngTempSensors * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419131738U))
        {
            /* API_CAN_Analyze\MG1IMT
PGN FB71
EngTempSensors\Receive Message */
            
            Time_FB71_x5A_data = ((int32_t) 0);
            
            TimeOut_FB71_x5A_data = ((uint8_t) 0U);
            
            EngSensTemp1_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
            EngSensTemp2_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
            EngSensTemp3_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
            EngSensTemp4_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
        }
        else
        {
            int32_t Read_Parameter_20AFF141;
            int32_t Add_A0D0ADF0;
            int32_t Saturation_4BB8E497;
            /* API_CAN_Analyze\MG1IMT
PGN FB71
EngTempSensors\Increment Timer */
            
            Read_Parameter_20AFF141 = Time_FB71_x5A_data;
            
            Add_A0D0ADF0 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_20AFF141));
            
            Saturation_4BB8E497 = Add_A0D0ADF0;
            if(Saturation_4BB8E497 < Read_Parameter_20AFF141)
            {
                Saturation_4BB8E497 = Read_Parameter_20AFF141;
            }
            else if(Saturation_4BB8E497 > Add_A0D0ADF0)
            {
                Saturation_4BB8E497 = Add_A0D0ADF0;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FB71_x5A_data = Saturation_4BB8E497;
            
        }
        
        if((Time_FB71_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\MG1IMT
PGN FB71
EngTempSensors\Reset signals */
            
            TimeOut_FB71_x5A_data = ((uint8_t) 1U);
            
            EngSensTemp1_x5A_data = ((int32_t) 0);
            
            EngSensTemp2_x5A_data = ((int32_t) 0);
            
            EngSensTemp3_x5A_data = ((int32_t) 0);
            
            EngSensTemp4_x5A_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\MG1IS1
PGN FB74
TrqMotor * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217805914U))
        {
            /* API_CAN_Analyze\MG1IS1
PGN FB74
TrqMotor\Receive Message */
            
            Time_FB74_x5A_data = ((int32_t) 0);
            
            TimeOut_FB74_x5A_data = ((uint8_t) 0U);
            
            MotorTrq_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 12U)))) - ((int32_t) 2000))));
            
        }
        else
        {
            int32_t Read_Parameter_FFC361CF;
            int32_t Add_C9C31ACA;
            int32_t Saturation_6F64CD82;
            /* API_CAN_Analyze\MG1IS1
PGN FB74
TrqMotor\Increment Timer */
            
            Read_Parameter_FFC361CF = Time_FB74_x5A_data;
            
            Add_C9C31ACA = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_FFC361CF));
            
            Saturation_6F64CD82 = Add_C9C31ACA;
            if(Saturation_6F64CD82 < Read_Parameter_FFC361CF)
            {
                Saturation_6F64CD82 = Read_Parameter_FFC361CF;
            }
            else if(Saturation_6F64CD82 > Add_C9C31ACA)
            {
                Saturation_6F64CD82 = Add_C9C31ACA;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FB74_x5A_data = Saturation_6F64CD82;
            
        }
        
        if((Time_FB74_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\MG1IS1
PGN FB74
TrqMotor\Reset signals */
            
            TimeOut_FB74_x5A_data = ((uint8_t) 1U);
            
            MotorTrq_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\MG1IT
PGN FB72
InvTempSensors * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419131994U))
        {
            /* API_CAN_Analyze\MG1IT
PGN FB72
InvTempSensors\Receive Message */
            
            Time_FB72_x5A_data = ((int32_t) 0);
            
            TimeOut_FB72_x5A_data = ((uint8_t) 0U);
            
            InvSensTemp1_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
            InvSensTemp2_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
            InvSensTemp3_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
            InvSensTemp4_x5A_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
        }
        else
        {
            int32_t Read_Parameter_425D400D;
            int32_t Add_E409F2E2;
            int32_t Saturation_8BDFAB90;
            /* API_CAN_Analyze\MG1IT
PGN FB72
InvTempSensors\Increment Timer */
            
            Read_Parameter_425D400D = Time_FB72_x5A_data;
            
            Add_E409F2E2 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_425D400D));
            
            Saturation_8BDFAB90 = Add_E409F2E2;
            if(Saturation_8BDFAB90 < Read_Parameter_425D400D)
            {
                Saturation_8BDFAB90 = Read_Parameter_425D400D;
            }
            else if(Saturation_8BDFAB90 > Add_E409F2E2)
            {
                Saturation_8BDFAB90 = Add_E409F2E2;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FB72_x5A_data = Saturation_8BDFAB90;
            
        }
        
        if((Time_FB72_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\MG1IT
PGN FB72
InvTempSensors\Reset signals */
            
            TimeOut_FB72_x5A_data = ((uint8_t) 1U);
            
            InvSensTemp1_x5A_data = ((int32_t) 0);
            
            InvSensTemp2_x5A_data = ((int32_t) 0);
            
            InvSensTemp3_x5A_data = ((int32_t) 0);
            
            InvSensTemp4_x5A_data = ((int32_t) 0);
            
        }
        
    }

    /* // Параметры МАЗ */

    /* // O */

    {
        /* / * API_CAN_Analyze\OEL
PGN FDCC
LightLampsCmd * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 217959457U))
        {
            /* API_CAN_Analyze\OEL
PGN FDCC
LightLampsCmd\Receive Message */
            
            Time_FDCC_x21_data = ((int32_t) 0);
            
            TimeOut_FDCC_x21_data = ((uint8_t) 0U);
            
            LSMain_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 4U))));
            
            LSTurn_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
            LSHazard_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            FogFrontFB_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_AF96D297;
            int32_t Add_07FE3916;
            int32_t Saturation_1403AD3D;
            /* API_CAN_Analyze\OEL
PGN FDCC
LightLampsCmd\Increment Timer */
            
            Read_Parameter_AF96D297 = Time_FDCC_x21_data;
            
            Add_07FE3916 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_AF96D297));
            
            Saturation_1403AD3D = Add_07FE3916;
            if(Saturation_1403AD3D < Read_Parameter_AF96D297)
            {
                Saturation_1403AD3D = Read_Parameter_AF96D297;
            }
            else if(Saturation_1403AD3D > Add_07FE3916)
            {
                Saturation_1403AD3D = Add_07FE3916;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FDCC_x21_data = Saturation_1403AD3D;
            
        }
        
        if((Time_FDCC_x21_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\OEL
PGN FDCC
LightLampsCmd\Reset signals */
            
            TimeOut_FDCC_x21_data = ((uint8_t) 1U);
            
            LSMain_x21_data = ((uint8_t) 0U);
            
            LSTurn_x21_data = ((uint8_t) 0U);
            
            LSHazard_x21_data = ((uint8_t) 0U);
            
            LSBeam_x21_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\OI_00, OI_5A 
PGN FEFF
Вода в топливе * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419364608U))
        {
            /* API_CAN_Analyze\OI_00, OI_5A 
PGN FEFF
Вода в топливе\Receive Message */
            
            Time_FEFF_x00_data = ((int32_t) 0);
            
            TimeOut_FEFF_x00_data = ((uint8_t) 0U);
            
            WaterInFuel_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_EBD66790;
            int32_t Add_21537001;
            int32_t Saturation_2D9B9EBD;
            /* API_CAN_Analyze\OI_00, OI_5A 
PGN FEFF
Вода в топливе\Increment Timer */
            
            Read_Parameter_EBD66790 = Time_FEFF_x00_data;
            
            Add_21537001 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_EBD66790));
            
            Saturation_2D9B9EBD = Add_21537001;
            if(Saturation_2D9B9EBD < Read_Parameter_EBD66790)
            {
                Saturation_2D9B9EBD = Read_Parameter_EBD66790;
            }
            else if(Saturation_2D9B9EBD > Add_21537001)
            {
                Saturation_2D9B9EBD = Add_21537001;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEFF_x00_data = Saturation_2D9B9EBD;
            
        }
        
        if((Time_FEFF_x00_data) >= ((int32_t) 40000))
        {
            /* API_CAN_Analyze\OI_00, OI_5A 
PGN FEFF
Вода в топливе\Reset signals */
            
            TimeOut_FEFF_x00_data = ((uint8_t) 1U);
            
            WaterInFuel_x00_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419364698U))
        {
            /* API_CAN_Analyze\OI_00, OI_5A 
PGN FEFF
Вода в топливе\Receive Message */
            
            Time_FEFF_x5A_data = ((int32_t) 0);
            
            TimeOut_FEFF_x5A_data = ((uint8_t) 0U);
            
            PwrReserve_x5A_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_A61EFF61;
            int32_t Add_B785EEC4;
            int32_t Saturation_FFD70A26;
            /* API_CAN_Analyze\OI_00, OI_5A 
PGN FEFF
Вода в топливе\Increment Timer */
            
            Read_Parameter_A61EFF61 = Time_FEFF_x5A_data;
            
            Add_B785EEC4 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_A61EFF61));
            
            Saturation_FFD70A26 = Add_B785EEC4;
            if(Saturation_FFD70A26 < Read_Parameter_A61EFF61)
            {
                Saturation_FFD70A26 = Read_Parameter_A61EFF61;
            }
            else if(Saturation_FFD70A26 > Add_B785EEC4)
            {
                Saturation_FFD70A26 = Add_B785EEC4;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEFF_x5A_data = Saturation_FFD70A26;
            
        }
        
        if((Time_FEFF_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\OI_00, OI_5A 
PGN FEFF
Вода в топливе\Reset signals */
            
            TimeOut_FEFF_x5A_data = ((uint8_t) 1U);
            
            PwrReserve_x5A_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419286305U))
        {
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Receive Message */
            
            Time_FDCD_x21_data = ((int32_t) 0);
            
            TimeOut_FDCD_x21_data = ((uint8_t) 0U);
            
            WiperCtrl_x21_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_C6E9DDA2;
            int32_t Add_0DC24377;
            int32_t Saturation_D8655E54;
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Increment Timer */
            
            Read_Parameter_C6E9DDA2 = Time_FDCD_x21_data;
            
            Add_0DC24377 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_C6E9DDA2));
            
            Saturation_D8655E54 = Add_0DC24377;
            if(Saturation_D8655E54 < Read_Parameter_C6E9DDA2)
            {
                Saturation_D8655E54 = Read_Parameter_C6E9DDA2;
            }
            else if(Saturation_D8655E54 > Add_0DC24377)
            {
                Saturation_D8655E54 = Add_0DC24377;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FDCD_x21_data = Saturation_D8655E54;
            
        }
        
        if((Time_FDCD_x21_data) >= ((int32_t) 2000))
        {
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Reset signals */
            
            TimeOut_FDCD_x21_data = ((uint8_t) 1U);
            
            WiperCtrl_x21_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419286302U))
        {
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Receive Message */
            
            Time_FDCD_x1E_data = ((int32_t) 0);
            
            TimeOut_FDCD_x1E_data = ((uint8_t) 0U);
            
            WiperCtrl_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_E74B4C97;
            int32_t Add_4EF918AD;
            int32_t Saturation_C5175C12;
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Increment Timer */
            
            Read_Parameter_E74B4C97 = Time_FDCD_x1E_data;
            
            Add_4EF918AD = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_E74B4C97));
            
            Saturation_C5175C12 = Add_4EF918AD;
            if(Saturation_C5175C12 < Read_Parameter_E74B4C97)
            {
                Saturation_C5175C12 = Read_Parameter_E74B4C97;
            }
            else if(Saturation_C5175C12 > Add_4EF918AD)
            {
                Saturation_C5175C12 = Add_4EF918AD;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FDCD_x1E_data = Saturation_C5175C12;
            
        }
        
        if((Time_FDCD_x1E_data) >= ((int32_t) 2000))
        {
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Reset signals */
            
            TimeOut_FDCD_x1E_data = ((uint8_t) 1U);
            
            WiperCtrl_x1E_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419286356U))
        {
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Receive Message */
            
            Time_FDCD_x54_data = ((int32_t) 0);
            
            TimeOut_FDCD_x54_data = ((uint8_t) 0U);
            
            WiperSwitch_x54_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 4U))));
            
        }
        else
        {
            int32_t Read_Parameter_106C6121;
            int32_t Add_1126FF19;
            int32_t Saturation_9D503C88;
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Increment Timer */
            
            Read_Parameter_106C6121 = Time_FDCD_x54_data;
            
            Add_1126FF19 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_106C6121));
            
            Saturation_9D503C88 = Add_1126FF19;
            if(Saturation_9D503C88 < Read_Parameter_106C6121)
            {
                Saturation_9D503C88 = Read_Parameter_106C6121;
            }
            else if(Saturation_9D503C88 > Add_1126FF19)
            {
                Saturation_9D503C88 = Add_1126FF19;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FDCD_x54_data = Saturation_9D503C88;
            
        }
        
        if((Time_FDCD_x54_data) >= ((int32_t) 2000))
        {
            /* API_CAN_Analyze\OWW
PGN: FDCD
WiperWasher\Reset signals */
            
            TimeOut_FDCD_x54_data = ((uint8_t) 1U);
            
            WiperSwitch_x54_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Амперметр и рекуперация
PGN FF10 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419369185U))
        {
            /* API_CAN_Analyze\Амперметр и рекуперация
PGN FF10\Receive Message */
            
            Time_FF10_xE1_data = ((int32_t) 0);
            
            TimeOut_FF10_xE1_data = ((uint8_t) 0U);
            
            AmmeterForward_E1_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_FC5B50D4;
            int32_t Add_4B425327;
            int32_t Saturation_3A64DAAD;
            /* API_CAN_Analyze\Амперметр и рекуперация
PGN FF10\Increment Timer */
            
            Read_Parameter_FC5B50D4 = Time_FF10_xE1_data;
            
            Add_4B425327 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_FC5B50D4));
            
            Saturation_3A64DAAD = Add_4B425327;
            if(Saturation_3A64DAAD < Read_Parameter_FC5B50D4)
            {
                Saturation_3A64DAAD = Read_Parameter_FC5B50D4;
            }
            else if(Saturation_3A64DAAD > Add_4B425327)
            {
                Saturation_3A64DAAD = Add_4B425327;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF10_xE1_data = Saturation_3A64DAAD;
            
        }
        
        if((Time_FF10_xE1_data) >= ((int32_t) 1000))
        {
            /* API_CAN_Analyze\Амперметр и рекуперация
PGN FF10\Reset signals */
            
            TimeOut_FF10_xE1_data = ((uint8_t) 1U);
            
            AmmeterForward_E1_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Климат
PGN FF50 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419385374U))
        {
            /* API_CAN_Analyze\Климат
PGN FF50\Receive Message */
            
            Time_FF50_x1E_data = ((int32_t) 0);
            
            TimeOut_FF50_x1E_data = ((uint8_t) 0U);
            
            LowBeamAuto_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            ClimateSalonPump_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            ClimateSalonHeaterMode_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            ClimateSalonFlame_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 6U), ((uint8_t) 2U))));
            
            KneelingAuto_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            GlassHeating_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            ClimateDriverGlassFrontHeating_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            ClimateDriverFan_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            ClimateDriverChairHeating_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_C90B2539;
            int32_t Add_8E6D4FA1;
            int32_t Saturation_98607526;
            /* API_CAN_Analyze\Климат
PGN FF50\Increment Timer */
            
            Read_Parameter_C90B2539 = Time_FF50_x1E_data;
            
            Add_8E6D4FA1 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_C90B2539));
            
            Saturation_98607526 = Add_8E6D4FA1;
            if(Saturation_98607526 < Read_Parameter_C90B2539)
            {
                Saturation_98607526 = Read_Parameter_C90B2539;
            }
            else if(Saturation_98607526 > Add_8E6D4FA1)
            {
                Saturation_98607526 = Add_8E6D4FA1;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF50_x1E_data = Saturation_98607526;
            
        }
        
        if((Time_FF50_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\Климат
PGN FF50\Reset signals */
            
            TimeOut_FF50_x1E_data = ((uint8_t) 1U);
            
            LowBeamAuto_x1E_data = ((uint8_t) 0U);
            
            ClimateSalonPump_x1E_data = ((uint8_t) 0U);
            
            ClimateSalonHeaterMode_x1E_data = ((uint8_t) 0U);
            
            ClimateSalonFlame_x1E_data = ((uint8_t) 0U);
            
            KneelingAuto_x1E_data = ((uint8_t) 0U);
            
            GlassHeating_x1E_data = ((uint8_t) 0U);
            
            ClimateDriverGlassFrontHeating_x1E_data = ((uint8_t) 0U);
            
            ClimateDriverFan_x1E_data = ((uint8_t) 0U);
            
            ClimateDriverChairHeating_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Климат
PGN FF51 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419385630U))
        {
            /* API_CAN_Analyze\Климат
PGN FF51\Receive Message */
            
            Time_FF51_x1E_data = ((int32_t) 0);
            
            TimeOut_FF51_x1E_data = ((uint8_t) 0U);
            
            ClimateSalonFrontHeatingSB40_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            ClimateSalonFrontHeatingSB42_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            ClimateSalonFrontHeatingError_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 4U))));
            
            ClimateDriverHeatingSpeedOne_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            ClimateDriverHeatingSpeedTwo_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            ClimateDriverHeatingSpeedError_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_AFA9A70E;
            int32_t Add_9EACE03F;
            int32_t Saturation_680497E0;
            /* API_CAN_Analyze\Климат
PGN FF51\Increment Timer */
            
            Read_Parameter_AFA9A70E = Time_FF51_x1E_data;
            
            Add_9EACE03F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_AFA9A70E));
            
            Saturation_680497E0 = Add_9EACE03F;
            if(Saturation_680497E0 < Read_Parameter_AFA9A70E)
            {
                Saturation_680497E0 = Read_Parameter_AFA9A70E;
            }
            else if(Saturation_680497E0 > Add_9EACE03F)
            {
                Saturation_680497E0 = Add_9EACE03F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF51_x1E_data = Saturation_680497E0;
            
        }
        
        if((Time_FF51_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\Климат
PGN FF51\Reset signals */
            
            TimeOut_FF51_x1E_data = ((uint8_t) 1U);
            
            ClimateSalonFrontHeatingSB40_x1E_data = ((uint8_t) 0U);
            
            ClimateSalonFrontHeatingSB42_x1E_data = ((uint8_t) 0U);
            
            ClimateSalonFrontHeatingError_x1E_data = ((uint8_t) 0U);
            
            ClimateDriverHeatingSpeedOne_x1E_data = ((uint8_t) 0U);
            
            ClimateDriverHeatingSpeedTwo_x1E_data = ((uint8_t) 0U);
            
            ClimateDriverHeatingSpeedError_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Климат
PGN FFE0 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419422233U))
        {
            /* API_CAN_Analyze\Климат
PGN FFE0\Receive Message */
            
            Time_FFE0_x19_data = ((int32_t) 0);
            
            TimeOut_FFE0_x19_data = ((uint8_t) 0U);
            
            ClimateSalon_x19_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 4U))));
            
            ClimateSalonHeatingError_x19_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            ClimateSalonTemp_x19_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_05AD57D3;
            int32_t Add_8F8D566F;
            int32_t Saturation_AA5DA25A;
            /* API_CAN_Analyze\Климат
PGN FFE0\Increment Timer */
            
            Read_Parameter_05AD57D3 = Time_FFE0_x19_data;
            
            Add_8F8D566F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_05AD57D3));
            
            Saturation_AA5DA25A = Add_8F8D566F;
            if(Saturation_AA5DA25A < Read_Parameter_05AD57D3)
            {
                Saturation_AA5DA25A = Read_Parameter_05AD57D3;
            }
            else if(Saturation_AA5DA25A > Add_8F8D566F)
            {
                Saturation_AA5DA25A = Add_8F8D566F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FFE0_x19_data = Saturation_AA5DA25A;
            
        }
        
        if((Time_FFE0_x19_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\Климат
PGN FFE0\Reset signals */
            
            TimeOut_FFE0_x19_data = ((uint8_t) 1U);
            
            ClimateSalon_x19_data = ((uint8_t) 0U);
            
            ClimateSalonHeatingError_x19_data = ((uint8_t) 0U);
            
            ClimateSalonTemp_x19_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Освещение салона
PGN FFFD * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 436206878U))
        {
            /* API_CAN_Analyze\Освещение салона
PGN FFFD\Receive Message */
            
            Time_FFFD_x1E_data = ((int32_t) 0);
            
            TimeOut_FFFD_x1E_data = ((uint8_t) 0U);
            
            SalonLight_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_A8174DE3;
            int32_t Add_394F22FD;
            int32_t Saturation_72DAD5AC;
            /* API_CAN_Analyze\Освещение салона
PGN FFFD\Increment Timer */
            
            Read_Parameter_A8174DE3 = Time_FFFD_x1E_data;
            
            Add_394F22FD = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_A8174DE3));
            
            Saturation_72DAD5AC = Add_394F22FD;
            if(Saturation_72DAD5AC < Read_Parameter_A8174DE3)
            {
                Saturation_72DAD5AC = Read_Parameter_A8174DE3;
            }
            else if(Saturation_72DAD5AC > Add_394F22FD)
            {
                Saturation_72DAD5AC = Add_394F22FD;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FFFD_x1E_data = Saturation_72DAD5AC;
            
        }
        
        if((Time_FFFD_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\Освещение салона
PGN FFFD\Reset signals */
            
            TimeOut_FFFD_x1E_data = ((uint8_t) 1U);
            
            SalonLight_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // R */

    {
        /* / * API_CAN_Analyze\Климат
PGN FFE6 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419423769U))
        {
            /* API_CAN_Analyze\Климат
PGN FFE6\Receive Message */
            
            Time_FFE6_x19_data = ((int32_t) 0);
            
            TimeOut_FFE6_x19_data = ((uint8_t) 0U);
            
            ClimateSalonHeatingSpeedOne_x19_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
            ClimateSalonHeatingSpeedTwo_x19_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_5BE2E855;
            int32_t Add_2F796C1C;
            int32_t Saturation_24E7242C;
            /* API_CAN_Analyze\Климат
PGN FFE6\Increment Timer */
            
            Read_Parameter_5BE2E855 = Time_FFE6_x19_data;
            
            Add_2F796C1C = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_5BE2E855));
            
            Saturation_24E7242C = Add_2F796C1C;
            if(Saturation_24E7242C < Read_Parameter_5BE2E855)
            {
                Saturation_24E7242C = Read_Parameter_5BE2E855;
            }
            else if(Saturation_24E7242C > Add_2F796C1C)
            {
                Saturation_24E7242C = Add_2F796C1C;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FFE6_x19_data = Saturation_24E7242C;
            
        }
        
        if((Time_FFE6_x19_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\Климат
PGN FFE6\Reset signals */
            
            TimeOut_FFE6_x19_data = ((uint8_t) 1U);
            
            ClimateSalonHeatingSpeedOne_x19_data = ((uint8_t) 0U);
            
            ClimateSalonHeatingSpeedTwo_x19_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Электросеть
PGN FF12 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419369697U))
        {
            /* API_CAN_Analyze\Электросеть
PGN FF12\Receive Message */
            
            Time_FF12_xE1_data = ((int32_t) 0);
            
            TimeOut_FF12_xE1_data = ((uint8_t) 0U);
            
            DriveModeNotN_xE1_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            BatteryHV_xE1_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 0U), ((uint8_t) 1U))));
            
            ChargeConnectorHV_xE1_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 7U), ((uint8_t) 1U))));
            
            IsolationTestHVOne_xE1_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 1U))));
            
            IsolationTestHVTwo_xE1_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 6U), ((uint8_t) 1U))));
            
            BatteryHVTempError_xE1_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 6U), ((uint8_t) 1U))));
            
            BatteryHVCoolantFluid_xE1_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 2U), ((uint8_t) 1U))));
            
            MileageReserve_xE1_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            CurrentHV_xE1_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_544E363C;
            int32_t Add_4F4E549A;
            int32_t Saturation_BD7E2FD6;
            /* API_CAN_Analyze\Электросеть
PGN FF12\Increment Timer */
            
            Read_Parameter_544E363C = Time_FF12_xE1_data;
            
            Add_4F4E549A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_544E363C));
            
            Saturation_BD7E2FD6 = Add_4F4E549A;
            if(Saturation_BD7E2FD6 < Read_Parameter_544E363C)
            {
                Saturation_BD7E2FD6 = Read_Parameter_544E363C;
            }
            else if(Saturation_BD7E2FD6 > Add_4F4E549A)
            {
                Saturation_BD7E2FD6 = Add_4F4E549A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF12_xE1_data = Saturation_BD7E2FD6;
            
        }
        
        if((Time_FF12_xE1_data) >= ((int32_t) 250))
        {
            /* API_CAN_Analyze\Электросеть
PGN FF12\Reset signals */
            
            TimeOut_FF12_xE1_data = ((uint8_t) 1U);
            
            DriveModeNotN_xE1_data = ((uint8_t) 0U);
            
            BatteryHV_xE1_data = ((uint8_t) 0U);
            
            ChargeConnectorHV_xE1_data = ((uint8_t) 0U);
            
            IsolationTestHVOne_xE1_data = ((uint8_t) 0U);
            
            IsolationTestHVTwo_xE1_data = ((uint8_t) 0U);
            
            BatteryHVTempError_xE1_data = ((uint8_t) 0U);
            
            BatteryHVCoolantFluid_xE1_data = ((uint8_t) 0U);
            
            MileageReserve_xE1_data = ((int32_t) 0);
            
            CurrentHV_xE1_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Акустика
PGN 0000 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 769U))
        {
            /* API_CAN_Analyze\Акустика
PGN 0000\Receive Message */
            
            Time_0000_x01_data = ((int32_t) 0);
            
            TimeOut_0000_x01_data = ((uint8_t) 0U);
            
            QuietBusSong_x01_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_C5283346;
            int32_t Add_4E8E9105;
            int32_t Saturation_6E33E4F3;
            /* API_CAN_Analyze\Акустика
PGN 0000\Increment Timer */
            
            Read_Parameter_C5283346 = Time_0000_x01_data;
            
            Add_4E8E9105 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_C5283346));
            
            Saturation_6E33E4F3 = Add_4E8E9105;
            if(Saturation_6E33E4F3 < Read_Parameter_C5283346)
            {
                Saturation_6E33E4F3 = Read_Parameter_C5283346;
            }
            else if(Saturation_6E33E4F3 > Add_4E8E9105)
            {
                Saturation_6E33E4F3 = Add_4E8E9105;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_0000_x01_data = Saturation_6E33E4F3;
            
        }
        
        if((Time_0000_x01_data) >= ((int32_t) 400))
        {
            /* API_CAN_Analyze\Акустика
PGN 0000\Reset signals */
            
            TimeOut_0000_x01_data = ((uint8_t) 1U);
            
            QuietBusSong_x01_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Тормозная систма
PGN FF39 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419379475U))
        {
            /* API_CAN_Analyze\Тормозная систма
PGN FF39\Receive Message */
            
            Time_0000_x01_data = ((int32_t) 0);
            
            TimeOut_0000_x01_data = ((uint8_t) 0U);
            
            QuietBusSong_x01_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_A26B3C81;
            int32_t Add_251B6B8F;
            int32_t Saturation_54A66461;
            /* API_CAN_Analyze\Тормозная систма
PGN FF39\Increment Timer */
            
            Read_Parameter_A26B3C81 = Time_0000_x01_data;
            
            Add_251B6B8F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_A26B3C81));
            
            Saturation_54A66461 = Add_251B6B8F;
            if(Saturation_54A66461 < Read_Parameter_A26B3C81)
            {
                Saturation_54A66461 = Read_Parameter_A26B3C81;
            }
            else if(Saturation_54A66461 > Add_251B6B8F)
            {
                Saturation_54A66461 = Add_251B6B8F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_0000_x01_data = Saturation_54A66461;
            
        }
        
        if((Time_0000_x01_data) >= ((int32_t) 400))
        {
            /* API_CAN_Analyze\Тормозная систма
PGN FF39\Reset signals */
            
            TimeOut_0000_x01_data = ((uint8_t) 1U);
            
            QuietBusSong_x01_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Гидропривод
PGN FE0A * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419379475U))
        {
            /* API_CAN_Analyze\Гидропривод
PGN FE0A\Receive Message */
            
            Time_FE0A_x2E_data = ((int32_t) 0);
            
            TimeOut_FE0A_x2E_data = ((uint8_t) 0U);
            
            HydroFanError_x2E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_0993BD07;
            int32_t Add_73835E58;
            int32_t Saturation_4A8CD08D;
            /* API_CAN_Analyze\Гидропривод
PGN FE0A\Increment Timer */
            
            Read_Parameter_0993BD07 = Time_FE0A_x2E_data;
            
            Add_73835E58 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_0993BD07));
            
            Saturation_4A8CD08D = Add_73835E58;
            if(Saturation_4A8CD08D < Read_Parameter_0993BD07)
            {
                Saturation_4A8CD08D = Read_Parameter_0993BD07;
            }
            else if(Saturation_4A8CD08D > Add_73835E58)
            {
                Saturation_4A8CD08D = Add_73835E58;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE0A_x2E_data = Saturation_4A8CD08D;
            
        }
        
        if((Time_FE0A_x2E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\Гидропривод
PGN FE0A\Reset signals */
            
            TimeOut_FE0A_x2E_data = ((uint8_t) 1U);
            
            HydroFanError_x2E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\RF_id10
PGN FEFB
Температура в трансмиссии * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419363600U))
        {
            /* API_CAN_Analyze\RF_id10
PGN FEFB
Температура в трансмиссии\Receive Message */
            
            Time_FEFB_x10_data = ((int32_t) 0);
            
            TimeOut_FEFB_x10_data = ((uint8_t) 0U);
            
            RetarderOilTemp_x10_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int32_t) 40))));
            
        }
        else
        {
            int32_t Read_Parameter_42D37052;
            int32_t Add_4F25F7AF;
            int32_t Saturation_50E7C611;
            /* API_CAN_Analyze\RF_id10
PGN FEFB
Температура в трансмиссии\Increment Timer */
            
            Read_Parameter_42D37052 = Time_FEFB_x10_data;
            
            Add_4F25F7AF = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_42D37052));
            
            Saturation_50E7C611 = Add_4F25F7AF;
            if(Saturation_50E7C611 < Read_Parameter_42D37052)
            {
                Saturation_50E7C611 = Read_Parameter_42D37052;
            }
            else if(Saturation_50E7C611 > Add_4F25F7AF)
            {
                Saturation_50E7C611 = Add_4F25F7AF;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEFB_x10_data = Saturation_50E7C611;
            
        }
        
        if((Time_FEFB_x10_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\RF_id10
PGN FEFB
Температура в трансмиссии\Reset signals */
            
            TimeOut_FEFB_x10_data = ((uint8_t) 1U);
            
            RetarderOilTemp_x10_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\Тяговая батарея
PGN FF01 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419365345U))
        {
            /* API_CAN_Analyze\Тяговая батарея
PGN FF01\Receive Message */
            
            Time_FF01_xE1_data = ((int32_t) 0);
            
            TimeOut_FF01_xE1_data = ((uint8_t) 0U);
            
            BatteryHVAmmeterBack_FF01_xE1_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 10000))));
            
            BatteryHVoltage_FF01_xE1_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_61C6C341;
            int32_t Add_382EEB55;
            int32_t Saturation_04647431;
            /* API_CAN_Analyze\Тяговая батарея
PGN FF01\Increment Timer */
            
            Read_Parameter_61C6C341 = Time_FF01_xE1_data;
            
            Add_382EEB55 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_61C6C341));
            
            Saturation_04647431 = Add_382EEB55;
            if(Saturation_04647431 < Read_Parameter_61C6C341)
            {
                Saturation_04647431 = Read_Parameter_61C6C341;
            }
            else if(Saturation_04647431 > Add_382EEB55)
            {
                Saturation_04647431 = Add_382EEB55;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FF01_xE1_data = Saturation_04647431;
            
        }
        
        if((Time_FF01_xE1_data) >= ((int32_t) 250))
        {
            /* API_CAN_Analyze\Тяговая батарея
PGN FF01\Reset signals */
            
            TimeOut_FF01_xE1_data = ((uint8_t) 1U);
            
            BatteryHVAmmeterBack_FF01_xE1_data = ((int32_t) 0);
            
            BatteryHVoltage_FF01_xE1_data = ((int32_t) 0);
            
        }
        
    }

    /* // S */

    {
        /* / * API_CAN_Analyze\SERV
PGN FEC0
ServiceInformation * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419348570U))
        {
            /* API_CAN_Analyze\SERV
PGN FEC0
ServiceInformation\Receive Message */
            
            Time_FEC0_x5A_data = ((int32_t) 0);
            
            TimeOut_FEC0_x5A_data = ((uint8_t) 0U);
            
            ServDevID911_x5A_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            ServDist_x5A_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int16_t) 32127))));
            
            ServDevID912_x5A_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            ServCal_x5A_data = (((int8_t)(((int8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int8_t) 125))));
            
            ServDevID913_x5A_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            ServTime_x5A_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int16_t) 32127))));
            
        }
        else
        {
            int32_t Read_Parameter_47E4B0D6;
            int32_t Add_7678C20F;
            int32_t Saturation_F822E8D6;
            /* API_CAN_Analyze\SERV
PGN FEC0
ServiceInformation\Increment Timer */
            
            Read_Parameter_47E4B0D6 = Time_FEC0_x5A_data;
            
            Add_7678C20F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_47E4B0D6));
            
            Saturation_F822E8D6 = Add_7678C20F;
            if(Saturation_F822E8D6 < Read_Parameter_47E4B0D6)
            {
                Saturation_F822E8D6 = Read_Parameter_47E4B0D6;
            }
            else if(Saturation_F822E8D6 > Add_7678C20F)
            {
                Saturation_F822E8D6 = Add_7678C20F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEC0_x5A_data = Saturation_F822E8D6;
            
        }
        
        if((Time_FEC0_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\SERV
PGN FEC0
ServiceInformation\Reset signals */
            
            TimeOut_FEC0_x5A_data = ((uint8_t) 1U);
            
            ServDevID911_x5A_data = ((uint16_t) 0U);
            
            ServDist_x5A_data = ((int16_t) 0);
            
            ServDevID912_x5A_data = ((uint16_t) 0U);
            
            ServCal_x5A_data = ((int8_t) 0);
            
            ServDevID913_x5A_data = ((uint16_t) 0U);
            
            ServTime_x5A_data = ((int16_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\SHUTDN_id00
PGN FEE4
Работа ЭФУ * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419357696U))
        {
            /* API_CAN_Analyze\SHUTDN_id00
PGN FEE4
Работа ЭФУ\Receive Message */
            
            Time_FEE4_x00_data = ((int32_t) 0);
            
            TimeOut_FEE4_x00_data = ((uint8_t) 0U);
            
            EFU_x00_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_22F0C35E;
            int32_t Add_D7B8D309;
            int32_t Saturation_119337D1;
            /* API_CAN_Analyze\SHUTDN_id00
PGN FEE4
Работа ЭФУ\Increment Timer */
            
            Read_Parameter_22F0C35E = Time_FEE4_x00_data;
            
            Add_D7B8D309 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_22F0C35E));
            
            Saturation_119337D1 = Add_D7B8D309;
            if(Saturation_119337D1 < Read_Parameter_22F0C35E)
            {
                Saturation_119337D1 = Read_Parameter_22F0C35E;
            }
            else if(Saturation_119337D1 > Add_D7B8D309)
            {
                Saturation_119337D1 = Add_D7B8D309;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEE4_x00_data = Saturation_119337D1;
            
        }
        
        if((Time_FEE4_x00_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\SHUTDN_id00
PGN FEE4
Работа ЭФУ\Reset signals */
            
            TimeOut_FEE4_x00_data = ((uint8_t) 1U);
            
            EFU_x00_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // T */

    {
        /* / * API_CAN_Analyze\TCO1
PGN=FE6С
SpeedTach * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 218000622U))
        {
            uint64_t Function_Call_E752C916;
            /* API_CAN_Analyze\TCO1
PGN=FE6С
SpeedTach\Receive Message */
            
            Function_Call_E752C916 = API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 16U));
            
            SpeedBusTachOrig_xEE_data = ((int32_t) Function_Call_E752C916);
            
            Time_FE6C_xEE_data = ((int32_t) 0);
            
            TimeOut_FE6C_xEE_data = ((uint8_t) 0U);
            
            TachSystemEvent_xEE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            TachHandlingInformation_xEE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
            TachographPerformance_xEE_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_2171D204;
            int32_t Add_0C019E37;
            int32_t Saturation_859A5534;
            /* API_CAN_Analyze\TCO1
PGN=FE6С
SpeedTach\Increment Timer */
            
            Read_Parameter_2171D204 = Time_FE6C_xEE_data;
            
            Add_0C019E37 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_2171D204));
            
            Saturation_859A5534 = Add_0C019E37;
            if(Saturation_859A5534 < Read_Parameter_2171D204)
            {
                Saturation_859A5534 = Read_Parameter_2171D204;
            }
            else if(Saturation_859A5534 > Add_0C019E37)
            {
                Saturation_859A5534 = Add_0C019E37;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE6C_xEE_data = Saturation_859A5534;
            
        }
        
        if((Time_FE6C_xEE_data) >= ((int32_t) 250))
        {
            /* API_CAN_Analyze\TCO1
PGN=FE6С
SpeedTach\Reset signals */
            
            TimeOut_FE6C_xEE_data = ((uint8_t) 1U);
            
            SpeedBusTachOrig_xEE_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\TD,
PGN FEE6 
Дата и время * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419358446U))
        {
            /* API_CAN_Analyze\TD,
PGN FEE6 
Дата и время\Receive Message */
            
            Time_FEE6_xEE_data = ((int32_t) 0);
            
            TimeOut_FEE6_xEE_data = ((uint8_t) 0U);
            
            TDSec_xEE_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDMin_xEE_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDHour_xEE_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDMounth_xEE_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDDay_xEE_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDYear_xEE_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 8U)))) + ((int16_t) 1985))));
            
            TDMinOff_xEE_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int16_t) 125))));
            
            TDHourOff_xEE_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int16_t) 125))));
            
        }
        else
        {
            int32_t Read_Parameter_F664CA14;
            int32_t Add_84652F98;
            int32_t Saturation_A2839580;
            /* API_CAN_Analyze\TD,
PGN FEE6 
Дата и время\Increment Timer */
            
            Read_Parameter_F664CA14 = Time_FEE6_xEE_data;
            
            Add_84652F98 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_F664CA14));
            
            Saturation_A2839580 = Add_84652F98;
            if(Saturation_A2839580 < Read_Parameter_F664CA14)
            {
                Saturation_A2839580 = Read_Parameter_F664CA14;
            }
            else if(Saturation_A2839580 > Add_84652F98)
            {
                Saturation_A2839580 = Add_84652F98;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEE6_xEE_data = Saturation_A2839580;
            
        }
        
        if((Time_FEE6_xEE_data) >= ((int32_t) 5000))
        {
            /* API_CAN_Analyze\TD,
PGN FEE6 
Дата и время\Reset signals */
            
            TimeOut_FEE6_xEE_data = ((uint8_t) 1U);
            
            TDSec_xEE_data = ((int16_t) 0);
            
            TDMin_xEE_data = ((int16_t) 0);
            
            TDHour_xEE_data = ((int16_t) 0);
            
            TDMounth_xEE_data = ((int16_t) 0);
            
            TDDay_xEE_data = ((int16_t) 0);
            
            TDYear_xEE_data = ((int16_t) 0);
            
            TDMinOff_xEE_data = ((int16_t) 0);
            
            TDHourOff_xEE_data = ((int16_t) 0);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419358298U))
        {
            /* API_CAN_Analyze\TD,
PGN FEE6 
Дата и время\Receive Message */
            
            Time_FEE6_x5A_data = ((int32_t) 0);
            
            TimeOut_FEE6_x5A_data = ((uint8_t) 0U);
            
            TDSec_x5A_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDMin_x5A_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDHour_x5A_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDMounth_x5A_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 3U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDDay_x5A_data = ((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            TDYear_x5A_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 5U), ((uint8_t) 0U), ((uint8_t) 8U)))) + ((int16_t) 1985))));
            
            TDMinOff_x5A_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 6U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int16_t) 125))));
            
            TDHourOff_x5A_data = (((int16_t)(((int16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 0U), ((uint8_t) 8U)))) - ((int16_t) 125))));
            
        }
        else
        {
            int32_t Read_Parameter_E0B5FFE3;
            int32_t Add_455B6624;
            int32_t Saturation_7DA42F8A;
            /* API_CAN_Analyze\TD,
PGN FEE6 
Дата и время\Increment Timer */
            
            Read_Parameter_E0B5FFE3 = Time_FEE6_x5A_data;
            
            Add_455B6624 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_E0B5FFE3));
            
            Saturation_7DA42F8A = Add_455B6624;
            if(Saturation_7DA42F8A < Read_Parameter_E0B5FFE3)
            {
                Saturation_7DA42F8A = Read_Parameter_E0B5FFE3;
            }
            else if(Saturation_7DA42F8A > Add_455B6624)
            {
                Saturation_7DA42F8A = Add_455B6624;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEE6_x5A_data = Saturation_7DA42F8A;
            
        }
        
        if((Time_FEE6_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\TD,
PGN FEE6 
Дата и время\Reset signals */
            
            TimeOut_FEE6_x5A_data = ((uint8_t) 1U);
            
            TDSec_x5A_data = ((int16_t) 0);
            
            TDMin_x5A_data = ((int16_t) 0);
            
            TDHour_x5A_data = ((int16_t) 0);
            
            TDMounth_x5A_data = ((int16_t) 0);
            
            TDDay_x5A_data = ((int16_t) 0);
            
            TDYear_x5A_data = ((int16_t) 0);
            
            TDMinOff_x5A_data = ((int16_t) 0);
            
            TDHourOff_x5A_data = ((int16_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419361843U))
        {
            /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message */
            
            Time_FEF4_x33_data = ((int32_t) 0);
            
            TimeOut_FEF4_x33_data = ((uint8_t) 0U);
            
            TireID_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
            if((TireID_x33_data) == ((uint16_t) 0U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 00 */
                
                TirePres00_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp00_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow00_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold00_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 1U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 01 */
                
                TirePres01_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp01_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow01_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold01_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 16U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 10 */
                
                TirePres10_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp10_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow10_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold10_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 18U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 12 */
                
                TirePres12_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp12_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow12_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold12_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 17U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 11 */
                
                TirePres11_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp11_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow11_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold11_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 19U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 13 */
                
                TirePres13_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp13_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow13_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold13_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 32U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 20 */
                
                TirePres20_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp20_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow20_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold20_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 34U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 22 */
                
                TirePres22_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp22_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow22_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold22_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 33U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 21 */
                
                TirePres21_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp21_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow21_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold21_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
            if((TireID_x33_data) == ((uint16_t) 35U))
            {
                /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Receive Message\Колесо 23 */
                
                TirePres23_x33_data = ((uint16_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 8U))));
                
                TireTemp23_x33_data = (((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 4000))));
                
                TirePresLow23_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 2U), ((uint8_t) 2U))));
                
                TirePresThreshold23_x33_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 7U), ((uint8_t) 5U), ((uint8_t) 3U))));
                
            }
            
        }
        else
        {
            int32_t Read_Parameter_B1F8AD3C;
            int32_t Add_19B92958;
            int32_t Saturation_13254777;
            /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Increment Timer */
            
            Read_Parameter_B1F8AD3C = Time_FEF4_x33_data;
            
            Add_19B92958 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_B1F8AD3C));
            
            Saturation_13254777 = Add_19B92958;
            if(Saturation_13254777 < Read_Parameter_B1F8AD3C)
            {
                Saturation_13254777 = Read_Parameter_B1F8AD3C;
            }
            else if(Saturation_13254777 > Add_19B92958)
            {
                Saturation_13254777 = Add_19B92958;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF4_x33_data = Saturation_13254777;
            
        }
        
        if((Time_FEF4_x33_data) >= ((int32_t) 10000))
        {
            /* API_CAN_Analyze\TIRE1
PGN: FEF4
Давление 
в шинах\Reset signals */
            
            TimeOut_FEF4_x33_data = ((uint8_t) 1U);
            
            TirePres00_x33_data = ((uint16_t) 0U);
            
            TireTemp00_x33_data = ((int32_t) 0);
            
            TirePresLow00_x33_data = ((uint8_t) 0U);
            
            TirePres01_x33_data = ((uint16_t) 0U);
            
            TireTemp01_x33_data = ((int32_t) 0);
            
            TirePresLow01_x33_data = ((uint8_t) 0U);
            
            TirePres10_x33_data = ((uint16_t) 0U);
            
            TireTemp10_x33_data = ((int32_t) 0);
            
            TirePresLow10_x33_data = ((uint8_t) 0U);
            
            TirePres11_x33_data = ((uint16_t) 0U);
            
            TireTemp11_x33_data = ((int32_t) 0);
            
            TirePresLow11_x33_data = ((uint8_t) 0U);
            
            TirePres12_x33_data = ((uint16_t) 0U);
            
            TireTemp12_x33_data = ((int32_t) 0);
            
            TirePresLow12_x33_data = ((uint8_t) 0U);
            
            TirePres13_x33_data = ((uint16_t) 0U);
            
            TireTemp13_x33_data = ((int32_t) 0);
            
            TirePresLow13_x33_data = ((uint8_t) 0U);
            
            TirePres20_x33_data = ((uint16_t) 0U);
            
            TireTemp20_x33_data = ((int32_t) 0);
            
            TirePresLow20_x33_data = ((uint8_t) 0U);
            
            TirePres21_x33_data = ((uint16_t) 0U);
            
            TireTemp21_x33_data = ((int32_t) 0);
            
            TirePresLow21_x33_data = ((uint8_t) 0U);
            
            TirePres22_x33_data = ((uint16_t) 0U);
            
            TireTemp22_x33_data = ((int32_t) 0);
            
            TirePresLow22_x33_data = ((uint8_t) 0U);
            
            TirePres23_x33_data = ((uint16_t) 0U);
            
            TireTemp23_x33_data = ((int32_t) 0);
            
            TirePresLow23_x33_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\TRF1_id03
PGN FEF8
Температура в трансмиссии * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419362819U))
        {
            /* API_CAN_Analyze\TRF1_id03
PGN FEF8
Температура в трансмиссии\Receive Message */
            
            Time_FEF8_x03_data = ((int32_t) 0);
            
            TimeOut_FEF8_x03_data = ((uint8_t) 0U);
            
            TransOilTemp_x03_data = ((((int32_t)(((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 16U)))) - ((int32_t) 8736)))) / 32);
            
        }
        else
        {
            int32_t Read_Parameter_B5C79A1A;
            int32_t Add_902466A8;
            int32_t Saturation_85234522;
            /* API_CAN_Analyze\TRF1_id03
PGN FEF8
Температура в трансмиссии\Increment Timer */
            
            Read_Parameter_B5C79A1A = Time_FEF8_x03_data;
            
            Add_902466A8 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_B5C79A1A));
            
            Saturation_85234522 = Add_902466A8;
            if(Saturation_85234522 < Read_Parameter_B5C79A1A)
            {
                Saturation_85234522 = Read_Parameter_B5C79A1A;
            }
            else if(Saturation_85234522 > Add_902466A8)
            {
                Saturation_85234522 = Add_902466A8;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF8_x03_data = Saturation_85234522;
            
        }
        
        if((Time_FEF8_x03_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\TRF1_id03
PGN FEF8
Температура в трансмиссии\Reset signals */
            
            TimeOut_FEF8_x03_data = ((uint8_t) 1U);
            
            TransOilTemp_x03_data = (((int32_t) 0) / 32);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\TRF2_id03
PGN: FD95 * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419271939U))
        {
            /* API_CAN_Analyze\TRF2_id03
PGN: FD95\Receive Message */
            
            Time_FD95_x03_data = ((int32_t) 0);
            
            TimeOut_FD95_x03_data = ((uint8_t) 0U);
            
            TranOilTempHigh_x03_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 4U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_EBA61F82;
            int32_t Add_76A8634F;
            int32_t Saturation_336DA80C;
            /* API_CAN_Analyze\TRF2_id03
PGN: FD95\Increment Timer */
            
            Read_Parameter_EBA61F82 = Time_FD95_x03_data;
            
            Add_76A8634F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_EBA61F82));
            
            Saturation_336DA80C = Add_76A8634F;
            if(Saturation_336DA80C < Read_Parameter_EBA61F82)
            {
                Saturation_336DA80C = Read_Parameter_EBA61F82;
            }
            else if(Saturation_336DA80C > Add_76A8634F)
            {
                Saturation_336DA80C = Add_76A8634F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FD95_x03_data = Saturation_336DA80C;
            
        }
        
        if((Time_FD95_x03_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\TRF2_id03
PGN: FD95\Reset signals */
            
            TimeOut_FD95_x03_data = ((uint8_t) 1U);
            
            TranOilTempHigh_x03_data = ((uint8_t) 0U);
            
        }
        
    }

    /* // V */

    {
        /* / * API_CAN_Analyze\VDC1
PGN: FE4F
ESP * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419319563U))
        {
            /* API_CAN_Analyze\VDC1
PGN: FE4F
ESP\Receive Message */
            
            Time_FE4F_x0B_data = ((int32_t) 0);
            
            TimeOut_FE4F_x0B_data = ((uint8_t) 0U);
            
            ESP_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 2U))));
            
            ESPError_x0B_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 2U), ((uint8_t) 2U))));
            
        }
        else
        {
            int32_t Read_Parameter_55FF2BBC;
            int32_t Add_331A5D17;
            int32_t Saturation_9416C768;
            /* API_CAN_Analyze\VDC1
PGN: FE4F
ESP\Increment Timer */
            
            Read_Parameter_55FF2BBC = Time_FE4F_x0B_data;
            
            Add_331A5D17 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_55FF2BBC));
            
            Saturation_9416C768 = Add_331A5D17;
            if(Saturation_9416C768 < Read_Parameter_55FF2BBC)
            {
                Saturation_9416C768 = Read_Parameter_55FF2BBC;
            }
            else if(Saturation_9416C768 > Add_331A5D17)
            {
                Saturation_9416C768 = Add_331A5D17;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE4F_x0B_data = Saturation_9416C768;
            
        }
        
        if((Time_FE4F_x0B_data) >= ((int32_t) 400))
        {
            /* API_CAN_Analyze\VDC1
PGN: FE4F
ESP\Reset signals */
            
            TimeOut_FE4F_x0B_data = ((uint8_t) 1U);
            
            ESP_x0B_data = ((uint8_t) 0U);
            
            ESPError_x0B_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\VDHR
PGN FEС1
Пробег * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419348974U))
        {
            /* API_CAN_Analyze\VDHR
PGN FEС1
Пробег\Receive Message */
            
            Time_FEC1_xEE_data = ((int32_t) 0);
            
            TimeOut_FEC1_xEE_data = ((uint8_t) 0U);
            
            MileageTotal_xEE_data = ((int64_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 32U))));
            
            MileageTrip_xEE_data = ((int64_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 32U))));
            
        }
        else
        {
            int32_t Read_Parameter_E6DD4DB4;
            int32_t Add_262BD53F;
            int32_t Saturation_D0932241;
            /* API_CAN_Analyze\VDHR
PGN FEС1
Пробег\Increment Timer */
            
            Read_Parameter_E6DD4DB4 = Time_FEC1_xEE_data;
            
            Add_262BD53F = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_E6DD4DB4));
            
            Saturation_D0932241 = Add_262BD53F;
            if(Saturation_D0932241 < Read_Parameter_E6DD4DB4)
            {
                Saturation_D0932241 = Read_Parameter_E6DD4DB4;
            }
            else if(Saturation_D0932241 > Add_262BD53F)
            {
                Saturation_D0932241 = Add_262BD53F;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEC1_xEE_data = Saturation_D0932241;
            
        }
        
        if((Time_FEC1_xEE_data) >= ((int32_t) 5000))
        {
            /* API_CAN_Analyze\VDHR
PGN FEС1
Пробег\Reset signals */
            
            TimeOut_FEC1_xEE_data = ((uint8_t) 1U);
            
            MileageTotal_xEE_data = ((int64_t) 0L);
            
            MileageTrip_xEE_data = ((int64_t) 0L);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419348826U))
        {
            /* API_CAN_Analyze\VDHR
PGN FEС1
Пробег\Receive Message */
            
            Time_FEC1_x5A_data = ((int32_t) 0);
            
            TimeOut_FEC1_x5A_data = ((uint8_t) 0U);
            
            MileageTotal_x5A_data = ((int64_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 32U))));
            
            MileageTrip_x5A_data = ((int64_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 32U))));
            
        }
        else
        {
            int32_t Read_Parameter_D3C998E5;
            int32_t Add_5C899E94;
            int32_t Saturation_960C7649;
            /* API_CAN_Analyze\VDHR
PGN FEС1
Пробег\Increment Timer */
            
            Read_Parameter_D3C998E5 = Time_FEC1_x5A_data;
            
            Add_5C899E94 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_D3C998E5));
            
            Saturation_960C7649 = Add_5C899E94;
            if(Saturation_960C7649 < Read_Parameter_D3C998E5)
            {
                Saturation_960C7649 = Read_Parameter_D3C998E5;
            }
            else if(Saturation_960C7649 > Add_5C899E94)
            {
                Saturation_960C7649 = Add_5C899E94;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEC1_x5A_data = Saturation_960C7649;
            
        }
        
        if((Time_FEC1_x5A_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\VDHR
PGN FEС1
Пробег\Reset signals */
            
            TimeOut_FEC1_x5A_data = ((uint8_t) 1U);
            
            MileageTotal_x5A_data = ((int64_t) 0L);
            
            MileageTrip_x5A_data = ((int64_t) 0L);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\VEP1
PGN: FEF7
VehiclePower * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419362599U))
        {
            /* API_CAN_Analyze\VEP1
PGN: FEF7
VehiclePower\Receive Message */
            
            Time_FEF7_x27_data = ((int32_t) 0);
            
            TimeOut_FEF7_x27_data = ((uint8_t) 0U);
            
            LVBatteryV_x27_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_5E3E700F;
            int32_t Add_1CFDD88A;
            int32_t Saturation_D8907D66;
            /* API_CAN_Analyze\VEP1
PGN: FEF7
VehiclePower\Increment Timer */
            
            Read_Parameter_5E3E700F = Time_FEF7_x27_data;
            
            Add_1CFDD88A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_5E3E700F));
            
            Saturation_D8907D66 = Add_1CFDD88A;
            if(Saturation_D8907D66 < Read_Parameter_5E3E700F)
            {
                Saturation_D8907D66 = Read_Parameter_5E3E700F;
            }
            else if(Saturation_D8907D66 > Add_1CFDD88A)
            {
                Saturation_D8907D66 = Add_1CFDD88A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF7_x27_data = Saturation_D8907D66;
            
        }
        
        if((Time_FEF7_x27_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\VEP1
PGN: FEF7
VehiclePower\Reset signals */
            
            TimeOut_FEF7_x27_data = ((uint8_t) 1U);
            
            LVBatteryV_x27_data = ((int32_t) 0);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 419362590U))
        {
            /* API_CAN_Analyze\VEP1
PGN: FEF7
VehiclePower\Receive Message */
            
            Time_FEF7_x1E_data = ((int32_t) 0);
            
            TimeOut_FEF7_x1E_data = ((uint8_t) 0U);
            
            LVBatteryV_x1E_data = ((int32_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 4U), ((uint8_t) 0U), ((uint8_t) 16U))));
            
        }
        else
        {
            int32_t Read_Parameter_D3658C01;
            int32_t Add_B1734949;
            int32_t Saturation_A2CED32D;
            /* API_CAN_Analyze\VEP1
PGN: FEF7
VehiclePower\Increment Timer */
            
            Read_Parameter_D3658C01 = Time_FEF7_x1E_data;
            
            Add_B1734949 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_D3658C01));
            
            Saturation_A2CED32D = Add_B1734949;
            if(Saturation_A2CED32D < Read_Parameter_D3658C01)
            {
                Saturation_A2CED32D = Read_Parameter_D3658C01;
            }
            else if(Saturation_A2CED32D > Add_B1734949)
            {
                Saturation_A2CED32D = Add_B1734949;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FEF7_x1E_data = Saturation_A2CED32D;
            
        }
        
        if((Time_FEF7_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\VEP1
PGN: FEF7
VehiclePower\Reset signals */
            
            TimeOut_FEF7_x1E_data = ((uint8_t) 1U);
            
            LVBatteryV_x1E_data = ((int32_t) 0);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\VF
PGN FE68
OilHydrosistem * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 419325982U))
        {
            /* API_CAN_Analyze\VF
PGN FE68
OilHydrosistem\Receive Message */
            
            Time_FE68_x1E_data = ((int32_t) 0);
            
            TimeOut_FE68_x1E_data = ((uint8_t) 0U);
            
            HydraulicOil_x1E_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 2U), ((uint8_t) 0U), ((uint8_t) 8U))));
            
        }
        else
        {
            int32_t Read_Parameter_C529A680;
            int32_t Add_253ED587;
            int32_t Saturation_75D1E698;
            /* API_CAN_Analyze\VF
PGN FE68
OilHydrosistem\Increment Timer */
            
            Read_Parameter_C529A680 = Time_FE68_x1E_data;
            
            Add_253ED587 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_C529A680));
            
            Saturation_75D1E698 = Add_253ED587;
            if(Saturation_75D1E698 < Read_Parameter_C529A680)
            {
                Saturation_75D1E698 = Read_Parameter_C529A680;
            }
            else if(Saturation_75D1E698 > Add_253ED587)
            {
                Saturation_75D1E698 = Add_253ED587;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_FE68_x1E_data = Saturation_75D1E698;
            
        }
        
        if((Time_FE68_x1E_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\VF
PGN FE68
OilHydrosistem\Reset signals */
            
            TimeOut_FE68_x1E_data = ((uint8_t) 1U);
            
            HydraulicOil_x1E_data = ((uint8_t) 0U);
            
        }
        
    }

    {
        /* / * API_CAN_Analyze\VT21
PGN E7FF
Зажигание * / */
    
        if((CAN_InBox_ID_data) == ((uint32_t) 417857332U))
        {
            /* API_CAN_Analyze\VT21
PGN E7FF
Зажигание\Receive Message */
            
            Time_18_E7FF_x34_data = ((int32_t) 0);
            
            TimeOut_18_E7FF_x34_data = ((uint8_t) 0U);
            
            Ignition_18_E7FF_x34_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 3U))));
            
        }
        else
        {
            int32_t Read_Parameter_25741DA8;
            int32_t Add_A7636F56;
            int32_t Saturation_3691ED40;
            /* API_CAN_Analyze\VT21
PGN E7FF
Зажигание\Increment Timer */
            
            Read_Parameter_25741DA8 = Time_18_E7FF_x34_data;
            
            Add_A7636F56 = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_25741DA8));
            
            Saturation_3691ED40 = Add_A7636F56;
            if(Saturation_3691ED40 < Read_Parameter_25741DA8)
            {
                Saturation_3691ED40 = Read_Parameter_25741DA8;
            }
            else if(Saturation_3691ED40 > Add_A7636F56)
            {
                Saturation_3691ED40 = Add_A7636F56;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_18_E7FF_x34_data = Saturation_3691ED40;
            
        }
        
        if((Time_18_E7FF_x34_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\VT21
PGN E7FF
Зажигание\Reset signals */
            
            TimeOut_18_E7FF_x34_data = ((uint8_t) 1U);
            
            Ignition_18_E7FF_x34_data = ((uint8_t) 0U);
            
        }
        
        if((CAN_InBox_ID_data) == ((uint32_t) 216530740U))
        {
            /* API_CAN_Analyze\VT21
PGN E7FF
Зажигание\Receive Message */
            
            Time_0C_E7FF_x34_data = ((int32_t) 0);
            
            TimeOut_0C_E7FF_x34_data = ((uint8_t) 0U);
            
            Ignition_0C_E7FF_x34_data = ((uint8_t) (API_CAN_ReadValueFromBuffer(CAN_Buffer_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 3U))));
            
        }
        else
        {
            int32_t Read_Parameter_DD36A0AD;
            int32_t Add_085EC70A;
            int32_t Saturation_7B208DE5;
            /* API_CAN_Analyze\VT21
PGN E7FF
Зажигание\Increment Timer */
            
            Read_Parameter_DD36A0AD = Time_0C_E7FF_x34_data;
            
            Add_085EC70A = ((int32_t)((CAN_Delta_T_data) + Read_Parameter_DD36A0AD));
            
            Saturation_7B208DE5 = Add_085EC70A;
            if(Saturation_7B208DE5 < Read_Parameter_DD36A0AD)
            {
                Saturation_7B208DE5 = Read_Parameter_DD36A0AD;
            }
            else if(Saturation_7B208DE5 > Add_085EC70A)
            {
                Saturation_7B208DE5 = Add_085EC70A;
            }
            else
            {
                /* This code block intentionally left blank */
            }
            
            Time_0C_E7FF_x34_data = Saturation_7B208DE5;
            
        }
        
        if((Time_0C_E7FF_x34_data) >= ((int32_t) 4000))
        {
            /* API_CAN_Analyze\VT21
PGN E7FF
Зажигание\Reset signals */
            
            TimeOut_0C_E7FF_x34_data = ((uint8_t) 1U);
            
            Ignition_0C_E7FF_x34_data = ((uint8_t) 0U);
            
        }
        
    }

}

void API_FilterData(void)
{

    Speedometer_Filter_GUI_data = ((int32_t) ((Lerp(((((float_t) (Speedometer_Filter_GUI_data)) / 256.0F)), (((float_t) (Speedometer_Text_GUI_data))), ((int32_t) 300))) * 256.0F));

    AmmeterForward_Filter_GUI_data = ((int32_t) ((Lerp(((((float_t) (AmmeterForward_Filter_GUI_data)) * 2.0F)), ((((float_t) (AmmeterForward_Text_GUI_data)) * 2.0F)), ((int32_t) 300))) / 2.0F));

    AmmeterBack_Filter_GUI_data = ((int32_t) ((Lerp(((((float_t) (AmmeterBack_Filter_GUI_data)) / 10.0F)), ((((float_t) (BatteryHVAmmeterBack_FF01_xE1_data)) / 10.0F)), ((int32_t) 300))) * 10.0F));

    MileageReserve_Filter_GUI_data = ((int32_t) (Lerp((((float_t) (MileageReserve_Filter_GUI_data))), (((float_t) (MileageReserve_Text_GUI_data))), ((int32_t) 300))));

    ChargeReserve_Filter_GUI_data = ((int32_t) (Lerp((((float_t) (ChargeReserve_Filter_GUI_data))), (((float_t) (ChargeReserve_Text_GUI_data))), ((int32_t) 300))));

    AirPress1_Filter_GUI_data = (Lerp(((AirPress1_Filter_GUI_data)), ((AirPress1_Text_GUI_data)), ((int32_t) 300)));

    AirPress2_Filter_GUI_data = (Lerp(((AirPress2_Filter_GUI_data)), ((AirPress2_Text_GUI_data)), ((int32_t) 300)));

    BatteryHV_Filter_GUI_data = ((int32_t) ((Lerp(((((float_t) (BatteryHV_Filter_GUI_data)) / 10.0F)), ((((float_t) (BatteryHV_Text_GUI_data)) / 10.0F)), ((int32_t) 300))) * 10.0F));

    BatteryLV_Filter_GUI_data = ((int32_t) ((Lerp(((((float_t) (BatteryLV_Filter_GUI_data)) / 20.0F)), ((((float_t) (BatteryLV_Text_GUI_data)) / 20.0F)), ((int32_t) 300))) * 20.0F));

}

void API_Send_Msg_FFAA(void)
{

    {
        /* / * API_Send_Msg_FFAA\Двери * / */
    
        int32_t Function_Call_428BAA04;
        
        API_ResetBuffer(CAN_Sending_Buffer_FFAA_data);
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 2U), ((uint8_t) 4U), (GearMode_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 3U), ((uint8_t) 0U), (WiperMode_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 2U), ((uint8_t) 0U), (DoorsOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 2U), ((uint8_t) 2U), (HeaterMode_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 0U), (Door1ExtOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 0U), (Door1IntOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 2U), (Door2ExtOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 2U), (Door2IntOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 4U), (Door3ExtOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 4U), (Door3IntOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 6U), (Door4ExtOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 6U), (Door4IntOpeningByPassenger_data));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 3U), ((uint8_t) 2U), (KneelingAuto_data));
        
        Function_Call_428BAA04 = API_Autogramma_CAN_Send(CAN_Sending_Buffer_FFAA_data, ((uint32_t) 419408468U));
        
    }

    {
        /* / * API_Send_Msg_FFAA\Пробег * / */
    
        int32_t Function_Call_EB6E4BF9;
        
        DailyMileageRest_data = ((uint8_t) 0U);
        
        API_ResetBuffer(CAN_Sending_Buffer_FFAA_data);
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 1U));
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 0U), ((uint8_t) 1U));
        
        Function_Call_EB6E4BF9 = API_Autogramma_CAN_Send(CAN_Sending_Buffer_FFAA_data, ((uint32_t) 484371991U));
        
    }

    {
        /* / * API_Send_Msg_FFAA\Тест 1 * / */
    
        int8_t Not_643C75D6;
        int32_t Function_Call_819E9522;
        
        DailyMileageRest_data = ((uint8_t) 0U);
        
        API_ResetBuffer(CAN_Sending_Buffer_FFAA_data);
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 0U));
        
        Not_643C75D6 = (0 == (TestSendCAN_data) )? 1 : 0;
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 0U), (((uint8_t) Not_643C75D6)));
        
        TestSendCAN_data = Not_643C75D6;
        
        Function_Call_819E9522 = API_Autogramma_CAN_Send(CAN_Sending_Buffer_FFAA_data, ((uint32_t) 1U));
        
    }

    {
        /* / * API_Send_Msg_FFAA\Тест 2 * / */
    
        int8_t Not_C50AB997;
        int32_t Function_Call_5E48B37B;
        
        API_ResetBuffer(CAN_Sending_Buffer_FFAA_data);
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 1U));
        
        Not_C50AB997 = (0 == (TestSendCAN1_data) )? 1 : 0;
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 0U), (((uint8_t) Not_C50AB997)));
        
        TestSendCAN1_data = Not_C50AB997;
        
        Function_Call_5E48B37B = API_Autogramma_CAN_Send(CAN_Sending_Buffer_FFAA_data, ((uint32_t) 2U));
        
    }

    {
        /* / * API_Send_Msg_FFAA\Тест 3 * / */
    
        int8_t Not_15C8DD16;
        int32_t Function_Call_6FEFDE15;
        
        DailyMileageRest_data = ((uint8_t) 0U);
        
        API_ResetBuffer(CAN_Sending_Buffer_FFAA_data);
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 0U));
        
        Not_15C8DD16 = (0 == (TestSendCAN2_data) )? 1 : 0;
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 0U), (((uint8_t) Not_15C8DD16)));
        
        TestSendCAN2_data = Not_15C8DD16;
        
        Function_Call_6FEFDE15 = API_Autogramma_CAN_Send(CAN_Sending_Buffer_FFAA_data, ((uint32_t) 3U));
        
    }

    {
        /* / * API_Send_Msg_FFAA\Тест 4 * / */
    
        int8_t Not_DC9D4A6C;
        int32_t Function_Call_320F3967;
        
        API_ResetBuffer(CAN_Sending_Buffer_FFAA_data);
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 0U), ((uint8_t) 0U), ((uint8_t) 1U));
        
        Not_DC9D4A6C = (0 == (TestSendCAN3_data) )? 1 : 0;
        
        API_Write_2bit_data_to_buffer(CAN_Sending_Buffer_FFAA_data, ((uint8_t) 1U), ((uint8_t) 0U), (((uint8_t) Not_DC9D4A6C)));
        
        TestSendCAN3_data = Not_DC9D4A6C;
        
        Function_Call_320F3967 = API_Autogramma_CAN_Send(CAN_Sending_Buffer_FFAA_data, ((uint32_t) 4U));
        
    }

}

/* Definitions of local (private) functions ----------------------------------*/

/* End of file ---------------------------------------------------------------*/

