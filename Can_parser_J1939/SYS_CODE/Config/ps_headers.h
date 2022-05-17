// *****************************************************************************
// @Module	ps_headers.h
// @Author	MSEpro Code Generator v.3.0.5742.21126 built at 21.09.2015 11:44:13
// @Description	Contains exports for paramset data definitions
// *****************************************************************************

#ifndef __MSE_PS_HEADERS_H__
#define __MSE_PS_HEADERS_H__

#include "ps_types.h"

extern	ROM	COMMONDIAGLISTITEM	XHUGE	*ROM	theCommonDiagList_data;

extern	ROM	COMMONDIAGLIST	XHUGE	theCommonDiagList_descr;

extern	ROM	PSHEADER	XHUGE	PSH_lnk_ptr;

extern	ROM	U32	XHUGE	PSRT_lnk_ptr[1];

#define	CV_cvInFlow_ET	0

#define	CV_cvMISL_CrkAccel	1

#define	CV_cvMISL_CrkSpd_Err	2

#define	CV_cvEngMod_CoolT	3

#define	CV_cvEngMod_Run_TimLine	4

#define	CV_cvEngMod_CrkIdx	5

#define	CV_cvEngMod_PedIdx	6

#define	CV_cvUOZ_AirT	7

#define	CV_cvUOZ_CoolT	8

#define	CV_cvUOZ_CrkSpd	9

#define	CV_cvUOZ_GBC	10

#define	CV_cvUOZ_Rev1_CrkSpd	11

#define	CV_cvUOZ_Rev1_GBC	12

#define	CV_cvUOZ_Strt_CrkSpd	13

#define	CV_cvAccPed	14

#define	CV_cvMkr_AirT	15

#define	CV_cvMkr_CoolT	16

#define	CV_cvMkri_AFR	17

#define	CV_cvMkri_Cf	18

#define	CV_cvMkri_CrkSpd	19

#define	CV_cvMkri_GBC	20

#define	CV_cvMkri_Run_TimLine	21

#define	CV_cvMkrRamp_CrkSpd	22

#define	CV_cvMkrRamp_Gear	23

#define	CV_cvMkrTar_CrkSpd	24

#define	CV_cvUOZ_Ref_Diff	25

#define	CV_cvInFlow_AirT	26

#define	CV_cvInFlow_CoolT	27

#define	CV_cvInFlow_CrkSpd	28

#define	CV_cvInFlow_Rev1_CoolT	29

#define	CV_cvSim_AccPed_Tim	30

#define	DATA_qMISL_IRegIn_Del	31

#define	DATA_qMISL_IRegRun_Del	32

#define	DATA_qMISL_DrvI_Cf	33

#define	DATA_qMISL_I_Cf	34

#define	DATA_qMISL_I_Mn	35

#define	DATA_qMISL_I_Mx	36

#define	DATA_qMISL_IZeroRamp_Del	37

#define	DATA_qMISL_IZeroRamp_dMe	38

#define	DATA_qMISL_Tar	39

#define	DATA_qMISL_Tar_Mx	40

#define	DATA_qMISL_TarIn	41

#define	DATA_qMISL_TarIn_Shift	42

#define	DATA_qMISL_TarOut_Shift	43

#define	DATA_qMISL_OnSet_Err	44

#define	DATA_qMISL_AirPD_Cf	45

#define	DATA_qMISL_DrvPD_Me	46

#define	DATA_qMISL_GearPD_Cf	47

#define	DATA_qMISL_IgnPD_Cf	48

#define	DATA_qMISL_PD_Me	49

#define	DATA_qMISL_ExtTarEn_Code	50

#define	DATA_qCoolT_Fan1_Pwr	51

#define	DATA_qCoolT_Fan1Lim_Mi	52

#define	DATA_qCoolT_Fan2_Pwr	53

#define	DATA_qCoolT_Fan2Lim_Mi	54

#define	DATA_qEngMode_FL_AccPed	55

#define	DATA_qEngMode_Map	56

#define	DATA_qEngMod_CutOff_Mi	57

#define	DATA_qEngMod_StrtFin	58

#define	DATA_qEngMod_StrtFin_Tim	59

#define	DATA_qEngMod_StrtIn	60

#define	DATA_qEngMod_Mn_AccPed	61

#define	DATA_qUOZ_BriefMn	62

#define	DATA_qUOZ_BriefMnTim_Law	63

#define	DATA_qUOZ_Mn_Map	64

#define	DATA_qUOZ_LimTab_Alf	65

#define	DATA_qUOZ_Map	66

#define	DATA_qUOZ_MISL_Map	67

#define	DATA_qUOZ_ST_Map	68

#define	DATA_qUOZ_Tab0_Map	69

#define	DATA_qUOZ_Tab1_Map	70

#define	DATA_qUOZ_AirTCooT_Shift	71

#define	DATA_qUOZ_TempCor_Cf	72

#define	DATA_qUOZ_TstFinal_Cor	73

#define	DATA_qUOZ_TstTabLim_Cor	74

#define	DATA_qMkri_AlfEff_Cf	75

#define	DATA_qMkri_pVGasLoss_Mi	76

#define	DATA_qMkri_Ref_Map	77

#define	DATA_qMkri_Ref_UOZ	78

#define	DATA_qMkri_UOZEff_Cf	79

#define	DATA_qMkri3_Flt_Cf	80

#define	DATA_qMkrLs_AirTCoolT_Shift	81

#define	DATA_qMkrLs_Flt_Cf	82

#define	DATA_qMkrLs_Map_Mi	83

#define	DATA_qMkrLs_Run_Shift	84

#define	DATA_qMkrCor_UOZ	85

#define	DATA_qMkrCor_EnOff_Num	86

#define	DATA_qMkrCor_FinFlt_Cf	87

#define	DATA_qMkrCor_AccPedGrd_Lim	88

#define	DATA_qMkrCor_IntReg_Time	89

#define	DATA_qMkrCor_GbcMxDis_Time	90

#define	DATA_qMkrCor_IntRegGBCMx_Cf	91

#define	DATA_qMkrCor_IntRegDis_Range	92

#define	DATA_qMkrCor_IntRegDis_Tim	93

#define	DATA_qMkrCor_IntRegErr_Cf	94

#define	DATA_qMkrTar_AccPedDrv_Me	95

#define	DATA_qMkrTar_AccPedIdle_Me	96

#define	DATA_qMkrMx_AFR	97

#define	DATA_qMkrMn_Pull_Mi	98

#define	DATA_qMkrDistr_MkrGBC_Cf	99

#define	DATA_qMkrDistr_SkFin_Err	100

#define	DATA_qMkrRamp_AirUpSh_dMi	101

#define	DATA_qMkrRamp_ZeroDwn_Me	102

#define	DATA_qMkrRamp_ZeroUp_Me	103

#define	DATA_qMkrRamp_Dir_Hys	104

#define	DATA_qMkrRamp_DirFlt_Cf	105

#define	DATA_qMkrRamp_MISL_dMi	106

#define	DATA_qMkrRamp_NegDwn_dMi	107

#define	DATA_qMkrRamp_NegUp_dMi	108

#define	DATA_qMkrRamp_PosDwn_dMi	109

#define	DATA_qMkrRamp_PosUp_dMi	110

#define	DATA_qMkrRamp_ZeroDwn_dMi	111

#define	DATA_qMkrRamp_ZeroUp_dMi	112

#define	DATA_qInFlow_TempMass_Cf	113

#define	DATA_qGBCTar_Flt_Cf	114

#define	DATA_qGBCTar_Atm_Mx	115

#define	DATA_qGBCTar_Mn_Map	116

#define	DATA_qPwrSys_Altern_Eff	117

#define	DATA_qSim_CrkSpd_Val	118

#define	DATA_qSim_IntMan_Cf	119

#define	DATA_qSim_Mod	120

#define	DATA_qSim_ExTq_Tar	121

#define	DATA_qSim_CoolT_Val	122

#define	DATA_qSim_AirT_Val	123

#define	DATA_qSim_BaroCf_Val	124

#define	DATA_qSim_DrvTrnGear_Val	125

#define	DATA_qCrkSpd_Flt_Coef	126

#define	DATA_qSim_AFR_Val	127

#define	DATA_qInFlow_ET_Map	128

#define	DATA_qSim_AccPed	129

#define	DATA_qSim_AccPed_Mod	130

#define	DATA_qSim_AccPed_Tim	131

#define	DATA_qSim_GBC_Val	132

#define	DATA_qSim_InMan_Mod	133

#define	DATA_qSim_ExTq_Mod	134

#define	DATA_qMkrTar_AccPedAir_dMe	135

#define	DATA_qMkrRamp_AirDwnSh_dMi	136

#define	DATA_qMkrTar_AccPedAir_dMeCf	137

#define	DATA_qAccPed1_Coef	138

#define	DATA_qAccPed1_Mn_ADC	139

#define	DATA_CAN_OutBoxEml_StrtMode	140

#define	DATA_CAN_OutBoxEml_Tim	141

#define	DATA_CAN_OutBoxEml_Id	142

#define	DATA_CAN_OutBoxEml_Byte0	143

#define	DATA_CAN_OutBoxEml_Byte1	144

#define	DATA_CAN_OutBoxEml_Byte2	145

#define	DATA_CAN_OutBoxEml_Byte3	146

#define	DATA_CAN_OutBoxEml_Byte4	147

#define	DATA_CAN_OutBoxEml_Byte5	148

#define	DATA_CAN_OutBoxEml_Byte6	149

#define	DATA_CAN_OutBoxEml_Byte7	150

#define	DATA_qFRQ_activestate	151

#define	DATA_qFRQ_filtdown	152

#define	DATA_qFRQ_filtup	153

#define	DATA_Task100ms_Delay	154

#define	DATA_Task10ms_Delay	155

#define	DATA_Task1ms_Delay	156

#define	DATA_Task100us_Delay	157

#define	DATA_PWM_TimeMachine	158

#define	DATA_UPwr_Flt_Cf	159

#define	DATA_UPwr_R_Cf	160

#define	DATA_Cx411_PWMPer_m	161

#define	DATA_Cx411_PWMPer_k	162

#define	DATA_Cx411_PWMCfg_m	163

#define	DATA_Cx411_PWMCfg_k	164

#define	DATA_Cx411_PWM_m	165

#define	DATA_Cx411_PWM_k	166

#define	DATA_Cx411_APWM_m	167

#define	DATA_Cx411_APWM_k	168

#define	DATA_UPwr_m	169

#define	DATA_UPwr_k	170

#define	DATA_UPwr_OvrVolt	171

#define	DATA_UPwr_UnderVolt	172

#define	DATA_Cx41_Ctrl_k	173

#define	DATA_Cx41_Ctrl_m	174

#define	DATA_DI_Volt	175

#define	DATA_DI_R_Cf	176

#define	DATA_DI_Flt_Cf	177

#define	DATA_UR_Flt_Cf	178

#define	DATA_UR_R_Cf	179

#define	DATA_Cx42_Ctrl_k	180

#define	DATA_Cx42_Ctrl_m	181

#define	DATA_Cx427_Ctrl_k	182

#define	DATA_Cx427_Ctrl_m	183

#define	DATA_Cx428_Ctrl_k	184

#define	DATA_Cx428_Ctrl_m	185

#define	DATA_Cx430_Ctrl_k	186

#define	DATA_Cx430_Ctrl_m	187

#define	DATA_Cx431_Ctrl_k	188

#define	DATA_Cx431_Ctrl_m	189

#define	DATA_Cx433_Ctrl_k	190

#define	DATA_Cx433_Ctrl_m	191

#define	DATA_Cx434_Ctrl_k	192

#define	DATA_Cx434_Ctrl_m	193

#define	DATA_Cx311_Ctrl_k	194

#define	DATA_Cx311_Ctrl_m	195

#define	DATA_Cx312_Ctrl_k	196

#define	DATA_Cx312_Ctrl_m	197

#define	DATA_Cx325_Ctrl_k	198

#define	DATA_Cx325_Ctrl_m	199

#define	DATA_Cx326_Ctrl_k	200

#define	DATA_Cx326_Ctrl_m	201

#define	DATA_Cx328_Ctrl_k	202

#define	DATA_Cx328_Ctrl_m	203

#define	DATA_Cx329_Ctrl_k	204

#define	DATA_Cx329_Ctrl_m	205

#define	DATA_Cx331_Ctrl_k	206

#define	DATA_Cx331_Ctrl_m	207

#define	DATA_Cx332_Ctrl_k	208

#define	DATA_Cx332_Ctrl_m	209

#define	DATA_Cx43_APWM_k	210

#define	DATA_Cx43_APWM_m	211

#define	DATA_Cx43_PWM_k	212

#define	DATA_Cx43_PWM_m	213

#define	DATA_Cx43_PWMCfg_k	214

#define	DATA_Cx43_PWMCfg_m	215

#define	DATA_Cx43_PWMPer_k	216

#define	DATA_Cx43_PWMPer_m	217

#define	DATA_Cx47_APWM_k	218

#define	DATA_Cx47_APWM_m	219

#define	DATA_Cx47_PWM_k	220

#define	DATA_Cx47_PWM_m	221

#define	DATA_Cx47_PWMCfg_k	222

#define	DATA_Cx47_PWMCfg_m	223

#define	DATA_Cx47_PWMPer_k	224

#define	DATA_Cx47_PWMPer_m	225

#define	DATA_Cx49_APWM_k	226

#define	DATA_Cx49_APWM_m	227

#define	DATA_Cx49_PWM_k	228

#define	DATA_Cx49_PWM_m	229

#define	DATA_Cx49_PWMCfg_k	230

#define	DATA_Cx49_PWMCfg_m	231

#define	DATA_Cx49_PWMPer_k	232

#define	DATA_Cx49_PWMPer_m	233

#define	DATA_Cx31_APWM_k	234

#define	DATA_Cx31_APWM_m	235

#define	DATA_Cx31_PWM_k	236

#define	DATA_Cx31_PWM_m	237

#define	DATA_Cx31_PWMCfg_k	238

#define	DATA_Cx31_PWMCfg_m	239

#define	DATA_Cx31_PWMPer_k	240

#define	DATA_Cx31_PWMPer_m	241

#define	DATA_Cx33_APWM_k	242

#define	DATA_Cx33_APWM_m	243

#define	DATA_Cx33_PWM_k	244

#define	DATA_Cx33_PWM_m	245

#define	DATA_Cx33_PWMCfg_k	246

#define	DATA_Cx33_PWMCfg_m	247

#define	DATA_Cx33_PWMPer_k	248

#define	DATA_Cx33_PWMPer_m	249

#define	DATA_Cx35_APWM_k	250

#define	DATA_Cx35_APWM_m	251

#define	DATA_Cx35_PWM_k	252

#define	DATA_Cx35_PWM_m	253

#define	DATA_Cx35_PWMCfg_k	254

#define	DATA_Cx35_PWMCfg_m	255

#define	DATA_Cx35_PWMPer_k	256

#define	DATA_Cx35_PWMPer_m	257

#define	DATA_Cx39_APWM_k	258

#define	DATA_Cx39_APWM_m	259

#define	DATA_Cx39_PWM_k	260

#define	DATA_Cx39_PWM_m	261

#define	DATA_Cx39_PWMCfg_k	262

#define	DATA_Cx39_PWMCfg_m	263

#define	DATA_Cx39_PWMPer_k	264

#define	DATA_Cx39_PWMPer_m	265

#define	DATA_Cx225_CtrlG_k	266

#define	DATA_Cx225_CtrlG_m	267

#define	DATA_Cx210_UR_k	268

#define	DATA_Cx210_UR_m	269

#define	DATA_LIB_2PowN	270

#define	DATA_PWM_LR_C	271

#define	DATA_PWM_UpdCfg_C	272

#define	DATA_PWMReg_D_Coeff_C	273

#define	DATA_PWMReg_I_Coeff_C	274

#define	DATA_PWMReg_I_Lim_C	275

#define	DATA_PWMReg_Lim_C	276

#define	DATA_PWMReg_P_Coeff_C	277

#define	DATA_PWMReg_Pr_Flt_C	278

#define	DATA_PWM_Per_Ini	279

#define	DATA_CANC_SupvCode_Ini	280

#endif // __MSE_PS_HEADERS_H__
