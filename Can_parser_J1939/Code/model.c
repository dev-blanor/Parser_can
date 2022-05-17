/*
 * -----------------------------------------------------------------------------
 * File Name    : model.c
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

/* Definitions of local (private) data types ---------------------------------*/

/* Definitions of local (private) constants ----------------------------------*/

/* Definitions of static global (private) variables --------------------------*/

/* Declarations of local (private) functions ---------------------------------*/

/* Definitions of global (public) functions ----------------------------------*/

void Execute(void)
{

    {
        /* / * Data dictionary * / */
    
        {
            /* / * Data dictionary\Variables Properties
common * / */
        
            {
                /* / * Data dictionary\Variables Properties
common\Units * / */
            
                /* // Время и дата */
                
                /* // Электрические величины */
                
                /* // Скорость */
                
                /* // Давление */
                
                /* // Проценты */
                
                /* // Углы */
                
                /* // Расстояние */
                
                /* // Крутящий момент */
                
                /* // Температура */
                
                /* // Идентификатор */
                
            }
            {
                /* / * Data dictionary\Variables Properties
common\Metrics * / */
            
                /* // Суффикс "_M" означает умножение на последующие число, в том числе и на дробные числа, например, 0.4 записывается как "_M04";
                // Суффикс "_D" означает деление на последующие число. */
                
                /* //Безразмерные */
                
                /* // Время и дата */
                
                /* // Электрические величины */
                
                /* // Скорость */
                
                /* // Давление */
                
                /* // Проценты */
                
                /* // Температура */
                
                /* // Расстояние */
                
                /* // Углы */
                
                /* // Идентификатор */
                
                /* // Крутящий момент */
                
                /* // Метрики с коэффициентом 1 для окончательной конвертации параметров. */
                
                /* // Время и дата */
                
                /* // Электрические величины */
                
                /* // Скорость */
                
                /* // Давление */
                
                /* // Проценты */
                
                /* // Температура */
                
                /* // Расстояние */
                
                /* // Углы */
                
                /* // Идентификатор */
                
                /* // Крутящий момент */
                
            }
        }
        {
            /* / * Data dictionary\CAN Variables
for CAN parser * / */
        
            /* // Общие параметры J1939
            У AUXIO настраиваемые параметры, поэтому возможны пересечения.
            PGN CCSI1 пересекается с CACI.
             */
            
            /* // Общие DM J1939
             */
            
            /* // A */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\AIR1, PGN=FEAE
Давление пневмосистем 123 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x30 */
                
                /* // SA = x1E */
                
                /* // SA = xFE */
                
                /* // SA = x21 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\AIR2_id1E
PGN FEDE
Давление пневмосистем 45 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\AMB
PGN: FEF5
AmbientConditions * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\ASC1
PGN=FE5A
Kneeling * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x2F */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\AT1T1I1, (??????)
PGN FE56
Уровень adBlue * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // SA = x3D
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DM01_0xXX
PGN FECA
SA XX * / */
            
                /* // Вспомогательные флаги и переменные */
                
                /* // Буфферы */
                
                /* // Целевые параметры */
                
                /* // SA: 0x00 */
                
                /* // SA: 0x3D */
                
                /* // SA: 0x49 */
                
                /* // SA: 0x50 */
                
                /* // SA: 0x03 */
                
                /* // SA: 0x5A */
                
                /* // SA: 0x0B */
                
                /* // SA: 0xEE */
                
                /* // SA: 0x2F
                 */
                
                /* // SA: 0xEE */
                
                /* // SA: 0xEF */
                
            }
            /* // B */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\BCH1
PGN FD15
Charge * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // Картинки */
                
            }
            /* // C */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\CCSS_id00
PGN FEED
SpeedLimit * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\CCSI1 (X) CACI
PGN FDE1
AirConditionerPump * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\CCVS1, _id00, _id17
PGN FEF1
ParkingBrake, Speed * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00 */
                
                /* // SA = x1E */
                
                /* // SA = x27 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\CM1_id1E
PGN: E000
Ремень безопасности * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            /* // Параметры КАМАЗ */
            
            /* // D */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\CBCU, PGN=FC1E
Запросы на открытие дверей * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xCC
                 */
                
                /* // SA = xCD
                 */
                
                /* // SA = xCE
                 */
                
                /* // SA = xCF
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\CBCU, PGN=FD1E
Статус открытия дверей * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xCC
                 */
                
                /* // SA = xCD
                 */
                
                /* // SA = xCE
                 */
                
                /* // SA = xCF
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\CBCU, PGN=FE1E
Неисправности дверей * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xCC
                 */
                
                /* // SA = xCD
                 */
                
                /* // SA = xCE
                 */
                
                /* // SA = xCF
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\CBCU, PGN FF37
Разрешение открытия дверей * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // Нужно нормальное описание. И еще рампа пересекается с запросом инвалида.
                 */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\AUXIO1,
PGN: FED9
Датчики (!!!) * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DC1
PGN FE4E
Doors, Ramp * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DC2
PGN FDA5
DoorsStatus * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DCAC_AI1_FDB0K
PGN F0D7
DC/AC Inverter * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DCDC1OS
PGN F113
DC/DC Converter * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DCDC1VC
PGN=F114(?)
Battery24V * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DD1,
PGN: FEFC
Омывающая жидкость * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // SA = x27
                 */
                
                /* // SA = x12
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DLCC1
PGN FD07
Сбой системы выхлопа * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x27
                 */
                
                /* // SA = x5A
                 */
                
                /* // SA = x00
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EPB1
PGN FF3C
Ручной тормоз * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x50
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PGN FFFE
Капот автобуса * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PGN FF07
Гармошка * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xE7
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\AUXIO4
PGN: A501
Joystic * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x4B
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DLCC2
PGN FD06
LampCmd * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DPFC1
PGN: FD7C * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DRC
PGN: FD70
Door, Ramp * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            /* // Параметры ПАЗ */
            
            /* // E */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EBC1, EBS
PGN: F001 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x0B
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EBC4
PGN: FEAC
Тормозные накладки * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x0B
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EBC5, EBC5_id0B
PGN FDC4
HillHoldMode, HaltBrake * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x0B
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EBS23
PGN FEC6
BrakePadState * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EEC1_id00
PGN F004
Тахометр * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EEC2
PGN F003
MotorController2 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EFL_P1_id00
PGN FEEF
Давление масла * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EVCU_Sys
PGN FF3F * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\DB
PGN: FF7D * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\EVCU_Buttons
PGN: FF6E * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\MISC_DB1, EVCU_DB
PGN: FF79 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // SA = x27
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\ERC, ERC1_id10, ERC1_id29
PGN F000
Ретардер * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x0F
                 */
                
                /* // SA = x10
                 */
                
                /* // SA = x29
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\ET1
PGN: FEEE
EngineTemp * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // SA = x27
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\ETC2
PGN: F005
Направление движения * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x03
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\ETC7_id03
PGN: FE4A
AKPP * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x03
                 */
                
                /* // Картинки */
                
            }
            /* // Параметры Аргентина и Лондон */
            
            /* // G */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\ISA_Status
PGN FF22 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x2B
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PROP_Body1,
PROP_Powertrain1
PGN FF01 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PROP_Powertrain2
PGN FF02 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\GPBAC/???\CM1
PGN: FE00 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            /* // Параметры Троллейбус */
            
            /* // L */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\LCMD,
PGN=FE41
Световые приборы * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\LD
PGN: FE40
Световые приборы * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PGN: 4031
MotorParam * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PTAD_EVSE1DCS1
PGN: FAB8
Сеть питания * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PTAD_AUXIO4_PS49
PGN: A531
Токоприемник * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PTAD_HVESSS1
PGN: F096
Главный контакт * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // SEE LONDON 
                HVESSS1
                PGN F096
                ChargeStatus
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PTAD_HSS1
PGN: FCC2
BatteryCapacity * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            /* // H */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PTAD_MG1II
PGN: FB6A
Изоляция * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PTAD_MG1IR2
PGN: FB73
RefVoltage * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xEF
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\PTAD_MG1IS1
PGN: FB74
TractionVoltage * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xEF
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\HVESSD1 (1/2)
PGN F090
TractionBatteryLvl * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\HVESSD2
PGN F091
BatteryCell * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\HVESSD3
PGN F092
BatteryCellTemp * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\HVESSD10
PGN F10C
IsolationTest * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\HVESSS1
PGN F096
ChargeStatus * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            /* // M */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\MG1IMT
PGN FB71
TempSensors * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\MG1IS1
PGN FB74
TrqMotor * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\MG1IT
PGN FB72
TempSensors * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            /* // Параметры МАЗ */
            
            /* // O */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\OEL
PGN FDCC
LightLampsCmd * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x21
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\OI_00, OI_5A 
PGN FEFF
Вода в топливе * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\OWW
PGN: FDCD
WiperWasher * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // SA = x1E
                 */
                
                /* // SA = x54
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Амперметр и рекуперация
PGN FF10 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xE1
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Климат
PGN FF50 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Климат
PGN FF51 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Климат
PGN FFE0 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Освещение салона
PGN FFFD * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            /* // R */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Климат
PGN FFE6 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Электросеть
PGN FF12 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xE1
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Акустика
PGN 0000 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xE1
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Тормозная систма
PGN FF39 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x13
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Гидропривод
PGN FE0A * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x2E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\RF_id10
PGN FEFB
Температура в трансмиссии * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x10
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\Тяговая батарея
PGN FF01 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xE1
                 */
                
                /* // Картинки */
                
            }
            /* // S */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\SERV
PGN FEC0
ServiceInformation * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\SHUTDN_id00
PGN FEE4
Работа ЭФУ * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x00
                 */
                
                /* // Картинки */
                
            }
            /* // T */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\TCO1
PGN=FE6С
ParkingBrake * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xEE
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\TD,
PGN FEE6 
Дата и время * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x5A
                 */
                
                /* // SA = xEE
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\TIRE1
PGN: FEF4
Давление 
в шинах * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x33
                 */
                
                /* // SA = x33
                 */
                
                /* // SA = x33
                 */
                
                /* // SA = x33
                 */
                
                /* // SA = x33
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\TRF1_id03
PGN FEF8
Температура в трансмиссии * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x03
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\TRF2_id03
PGN: FD95 * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x03
                 */
                
                /* // Картинки */
                
            }
            /* // V */
            
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\VDC1
PGN: FE4F
ESP * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x0B
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\VDHR
PGN FEС1
Пробег * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = xEE
                 */
                
                /* // SA = x5A
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\VEP1
PGN: FEF7
VehiclePower * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x27
                 */
                
                /* // SA = x1E
                 */
                
                /* // Это боротовое напряжение 24В? */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\VF
PGN FE68
OilHydrosistem * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // SA = x1E
                 */
                
                /* // Картинки */
                
            }
            {
                /* / * Data dictionary\CAN Variables
for CAN parser\VT21
PGN E7FF
Зажигание * / */
            
                /* // Счетчики времени и таймауты */
                
                /* // P = 18; SA = x34
                 */
                
                /* // P = 0C; SA = x34
                 */
                
                /* // Картинки */
                
            }
        }
        {
            /* / * Data dictionary\Variables
for GUI * / */
        
            {
                /* / * Data dictionary\Variables
for GUI\Общие параметры * / */
            
                /* Джойстик */
                
                /* Цвета */
                
                /* Время */
                
                /* Состояние анимации */
                
                /* Подсветка дисплея */
                
                {
                    /* / * Data dictionary\Variables
for GUI\Общие параметры\Update ColorBlue from ColorBlue1 * / */
                
                    /* Иначе при оптимизации он удаляет синий цвет. Нужно испавить! */
                    
                    ColorBlue1_data = (ColorBlue_data);
                    
                    ColorBlue_data = (ColorBlue1_data);
                    
                }
            }
            {
                /* / * Data dictionary\Variables
for GUI\АКПП
(1) * / */
            
                /* Режим вождения */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Состояние дверей на центральном автобусе * / */
            
                /* Номер двери */
                
                /* Преобразованные из CAN */
                
                /* Индекс анимации */
                
                /* Вспомогательная переменная типа float для индекса */
                
                /* 1-1 */
                
                /* 1-2 */
                
                /* 2
                 */
                
                /* 3
                 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Центральные пиктограммы.
Линия 1
(2 - 10) * / */
            
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* 2 */
                
                /* 3 */
                
                /* 4 */
                
                /* 5 */
                
                /* 6 */
                
                /* 7 */
                
                /* 8 */
                
                /* 9 */
                
                /* 10 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Центральные пиктограммы.
Линия 2
(11 - 18) * / */
            
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* 11 */
                
                /* 12 */
                
                /* 13 */
                
                /* 14 */
                
                /* 15 */
                
                /* 16 */
                
                /* 17 */
                
                /* 18 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Центральные пиктограммы.
Линия 3
(19 - 28) * / */
            
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* 19 */
                
                /* 20
                 */
                
                /* 21
                 */
                
                /* 22 */
                
                /* 23 */
                
                /* 24 */
                
                /* 25 */
                
                /* 26 */
                
                /* 27 */
                
                /* 28 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Центральные пиктограммы.
Линия 4
(29 - 30) * / */
            
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* 29 */
                
                /* 30 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Центральные пиктограммы.
Линия 5
(31- 42) * / */
            
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* 31 */
                
                /* 32 */
                
                /* 33 */
                
                /* 34 */
                
                /* 35 */
                
                /* 36 */
                
                /* 37 */
                
                /* 38 */
                
                /* 39 */
                
                /* 40 */
                
                /* 41 */
                
                /* 42 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Центральные пиктограммы.
Климат
(43 - 50) * / */
            
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* 43 */
                
                /* 44 */
                
                /* 45 */
                
                /* 46 */
                
                /* 47 */
                
                /* 48 */
                
                /* 49 */
                
                /* 50 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Пневмосистема
(51 - 52) * / */
            
                /* Первый контур */
                
                /* Второй контур */
                
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* Текст */
                
                /* Фильтр */
                
                /* 51 */
                
                /* 52 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Аккумуляторы
(53 - 54) * / */
            
                /* BatteryHV */
                
                /* BatteryLV */
                
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* Текст */
                
                /* Фильтр */
                
                /* 53 */
                
                /* 54 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Пиктограммы спидометра
(55 - 67) * / */
            
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* 55 */
                
                /* 56 */
                
                /* 57 */
                
                /* 58 */
                
                /* 59 */
                
                /* 60 */
                
                /* 61 */
                
                /* 62 */
                
                /* 63 */
                
                /* 64 */
                
                /* 65 */
                
                /* 66 */
                
                /* 67 */
                
            }
            {
                /* / * Data dictionary\Variables
for GUI\Пиктограммы тахометра и амперметра
(68 - 80) * / */
            
                /* Номер элемета */
                
                /* Преобразованные из CAN */
                
                /* Прозрачность */
                
                /* Цвет */
                
                /* 68 */
                
                /* 69 */
                
                /* 70 */
                
                /* 71 */
                
                /* 72 */
                
                /* 73 */
                
                /* 74 */
                
                /* 75 */
                
                /* 76 */
                
                /* 77 */
                
                /* 78 */
                
                /* 79 */
                
                /* 80 */
                
            }
        }
    }

    {
        /* / * UI and contol * / */
    
        {
            /* / * UI and contol\Files * / */
        
            /* Шрифт для текста
             */
            
            /* Фоны
             */
            
            /* Пиктограммы основного экрана
             */
            
            {
                /* / * UI and contol\Files\Спидометр * / */
            
                /* 55 */
                
                /* 61 */
                
                /* 62 */
                
                /* 63 */
                
                /* 56 */
                
                /* 64 */
                
                /* 57 */
                
                /* 65 */
                
                /* 66 */
                
                /* 58 */
                
                /* 67 */
                
                /* 59 */
                
                /* 60 */
                
            }
            {
                /* / * UI and contol\Files\Центральные
пиктограммы * / */
            
                /* 1
                строка */
                
                /* 2 */
                
                /* 31 */
                
                /* 3 */
                
                /* 4 */
                
                /* 20
                 */
                
                /* 32 */
                
                /* 33 */
                
                /* 5 */
                
                /* 21
                 */
                
                /* 34 */
                
                /* 6 */
                
                /* 22 */
                
                /* 35 */
                
                /* 7 */
                
                /* 8 */
                
                /* 23 */
                
                /* 36 */
                
                /* 9 */
                
                /* 10 */
                
                /* 24 */
                
                /* 37 */
                
                /* 38 */
                
                /* 11 */
                
                /* 39 */
                
                /* 12 */
                
                /* 13 */
                
                /* 25-26 */
                
                /* 14 */
                
                /* 40 */
                
                /* 15 */
                
                /* 27 */
                
                /* 41 */
                
                /* 16 */
                
                /* 3
                строка */
                
                /* 19 */
                
                /* 28 */
                
                /* 5
                строка */
                
                /* 2
                строка */
                
                /* 42 */
                
                /* 17 */
                
                /* 29
                 */
                
                /* 18 */
                
                /* 4
                строка */
                
                /* 30 */
                
            }
            {
                /* / * UI and contol\Files\Тахометр и амперметр * / */
            
                /* 68 */
                
                /* 78 */
                
                /* 69 */
                
                /* 70 */
                
                /* 79 */
                
                /* 71 */
                
                /* 72 */
                
                /* 80 */
                
                /* 73 */
                
                /* 74 */
                
                /* 75 */
                
                /* 76 */
                
                /* 77 */
                
            }
            {
                /* / * UI and contol\Files\Климат * / */
            
                /* 43 */
                
                /* 49 */
                
                /* 50 */
                
                /* 44 */
                
                /* 45 */
                
                /* 46 */
                
                /* 47 */
                
                /* 48 */
                
            }
            {
                /* / * UI and contol\Files\Аккумуляторы * / */
            
                /* 51 */
                
                /* 52 */
                
            }
            /* Меню
             */
            
            {
                /* / * UI and contol\Files\Сервис * / */
            
                /* Основные пиктограммы вкладки сервиса
                 */
                
                /* Подвеска */
                
                /* Электроцепи */
                
                /* Диагностика CAN - шин */
                
                /* Рулевое управление */
                
                /* Настройка систем автобуса */
                
                /* Тяговое оборудование */
                
                /* Светотехника */
                
            }
            /* 
            
             */
            
            /* 
            
             */
            
        }
        {
            /* / * UI and contol\Controller * / */
        
            {
                /* / * UI and contol\Controller\Обновление времени и состояний.
Запускать в самом начале! * / */
            
                int64_t Mod_A512208C;
                int64_t Mod_89CE2043;
                int64_t Mod_660373E0;
                
                {
                    /* / * UI and contol\Controller\Обновление времени и состояний.
Запускать в самом начале!\Получение времени из комбинации приборов * / */
                
                    GlobalTimeCountMs_data = (API_GetCurrentTime_ms());
                    
                }
                {
                    /* / * UI and contol\Controller\Обновление времени и состояний.
Запускать в самом начале!\Получение времени из симулятора автограммы * / */
                
                    double_t Digital_Clock_6D0E59F6;
                    double_t Compare_5E18DDAF;
                    
                    Digital_Clock_6D0E59F6 = 0;
                    
                    Compare_5E18DDAF = (Digital_Clock_6D0E59F6 >= ((double_t) ((int32_t) 100)) )? 1 : 0;
                    
                    if(Compare_5E18DDAF != 0)
                    {
                        double_t Digital_Clock_99373B91;
                        /* UI and contol\Controller\Обновление времени и состояний.
Запускать в самом начале!\Получение времени из симулятора автограммы\Update GlobalTimeCountMs */
                        
                        Digital_Clock_99373B91 = 0;
                        
                        GlobalTimeCountMs_data = ((int64_t)(Digital_Clock_99373B91 * ((double_t) ((int64_t) 1000L))));
                        
                    }
                    
                }
                DeltaGlobalTimeCountMs_data = (((int32_t)(((int32_t) (GlobalTimeCountMs_data)) - ((int32_t) (OldGlobalTimeCountMs_data)))));
                
                OldGlobalTimeCountMs_data = (GlobalTimeCountMs_data);
                
                Mod_A512208C = (int64_t) ((GlobalTimeCountMs_data) % ((int64_t) 1000L));
                
                Blink_1Hz_data = ((int32_t) ((Mod_A512208C >= ((int64_t) 500L) )? 1 : 0));
                
                Mod_89CE2043 = (int64_t) ((GlobalTimeCountMs_data) % ((int64_t) 500L));
                
                Blink_2Hz_data = ((int32_t) ((Mod_89CE2043 >= ((int64_t) 250L) )? 1 : 0));
                
                Mod_660373E0 = (int64_t) ((GlobalTimeCountMs_data) % ((int64_t) 400L));
                
                Blink_2500mHz_data = ((int32_t) ((Mod_660373E0 >= ((int64_t) 200L) )? 1 : 0));
                
            }
            {
                /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами. * / */
            
                API_FilterData();
                
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Ключ зажигания * / */
                
                    uint8_t Read_Parameter_1F33F055;
                    uint8_t Compare_EBBA7B72;
                    uint8_t Compare_0B9258BA;
                    uint8_t Compare_F816769A;
                    
                    Read_Parameter_1F33F055 = Ignition_0C_E7FF_x34_data;
                    
                    Compare_EBBA7B72 = (Read_Parameter_1F33F055 == ((uint8_t) 1U) )? 1U : 0U;
                    
                    Compare_0B9258BA = (Read_Parameter_1F33F055 == ((uint8_t) 2U) )? 1U : 0U;
                    
                    Compare_F816769A = (Read_Parameter_1F33F055 == ((uint8_t) 3U) )? 1U : 0U;
                    
                    Ignition_GUI_data = ((int8_t) (((0U != Compare_EBBA7B72) || (0U != Compare_0B9258BA) || (0U != Compare_F816769A)) ? 1U : 0U));
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Спидометр.
Стрелка и цифры * / */
                
                    int32_t Read_Parameter_CF76E175;
                    
                    Read_Parameter_CF76E175 = Speedometer_Filter_GUI_data;
                    
                    SpeedometerArrow_Angle_GUI_data = ((float_t) (LinearScale(((((double_t) Read_Parameter_CF76E175) / 256)), ((((double_t) ((int32_t) 0)) / 256)), ((((double_t) ((int32_t) 30720)) / 256)), (((double_t) ((float_t) 0.0F))), (((double_t) ((float_t) 192.0F))))));
                    
                    SpeedometerGlow_Angle_GUI_data = ((float_t) (LinearScale(((((double_t) Read_Parameter_CF76E175) / 256)), ((((double_t) ((int32_t) 0)) / 256)), ((((double_t) ((int32_t) 30720)) / 256)), (((double_t) ((float_t) 90.0F))), (((double_t) ((float_t) 282.0F))))));
                    
                    ColorChange(&SpeedometerGlow_Color_GUI_data, ((((double_t) (Speedometer_Filter_GUI_data)) / 256)), ((((double_t) ((int32_t) 17920)) / 256)), ((((double_t) ((int32_t) 23040)) / 256)), (ColorWhite_data), (ColorRed_data));
                    
                    SpeedometerArrow_Color_GUI_data = (ColorRed_data);
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10) * / */
                
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиция 2
Не пристегнут ремень безопасности * / */
                    
                        uint8_t Compare_C3172E41;
                        uint8_t Compare_4F32870D;
                        uint8_t Compare_EAC303EE;
                        uint8_t Compare_7B9137AD;
                        uint8_t Or_6887FC28;
                        uint8_t Direct_Switch_BDC48E72;
                        uint8_t Direct_Switch_2FA0686D;
                        uint8_t Compare_7F02F667;
                        uint8_t Compare_244D9596;
                        uint8_t Or_8AE28EB1;
                        
                        SpeedBusTachKph_xEE_data = ((SpeedBusTachOrig_xEE_data) / 256);
                        
                        Compare_C3172E41 = ((TripSeatBeltFlag_data) == ((uint8_t) 0U) )? 1U : 0U;
                        
                        Compare_4F32870D = ((DriverBelt_x1E_data) == ((uint8_t) 0U) )? 1U : 0U;
                        
                        if((((0U != Compare_C3172E41) && (0U != Compare_4F32870D)) ? 1U : 0U) == ((uint8_t) 0U))
                        {
                            /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиция 2
Не пристегнут ремень безопасности\Начало отсчета расстония езды без ремня */
                            
                            TripSeatBeltStart_data = (MileageTotal_xEE_data);
                            
                            TripSeatBeltFlag_data = ((uint8_t) 1U);
                            
                        }
                        else
                        {
                            /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиция 2
Не пристегнут ремень безопасности\Обнуление расстония езды без ремня */
                            
                            TripSeatBeltStart_data = (MileageTotal_xEE_data);
                            
                            TripSeatBeltFlag_data = ((uint8_t) 0U);
                            
                        }
                        
                        Compare_EAC303EE = ((SpeedBusTachKph_xEE_data) > ((int32_t) 20) )? 1U : 0U;
                        
                        Compare_7B9137AD = ((TripSeatBeltDelta_data) > ((int64_t) 20L) )? 1U : 0U;
                        
                        Or_6887FC28 = ((0U != Compare_EAC303EE) || (0U != Compare_7B9137AD)) ? 1U : 0U;
                        
                        if(0U == Compare_4F32870D)
                        {
                            Direct_Switch_BDC48E72 = ((uint8_t) 0U);
                        }
                        else
                        {
                            Direct_Switch_BDC48E72 = Compare_4F32870D;
                        }
                        
                        if(0U == (((0U != Compare_4F32870D) && (0U != Or_6887FC28)) ? 1U : 0U))
                        {
                            Direct_Switch_2FA0686D = Direct_Switch_BDC48E72;
                        }
                        else
                        {
                            Direct_Switch_2FA0686D = ((uint8_t)((Blink_1Hz_data) * ((int32_t) Compare_4F32870D)));
                        }
                        
                        SeatBelt_GUI_data = ((int8_t) Direct_Switch_2FA0686D);
                        
                        TripSeatBeltDelta_data = (((int64_t)((MileageTotal_xEE_data) - (TripSeatBeltStart_data))));
                        
                        Compare_7F02F667 = ((TimeOut_FEC1_xEE_data) == ((uint8_t) 1U) )? 1U : 0U;
                        
                        Compare_244D9596 = ((SpeedBusTachOrig_xEE_data) == (((int32_t) 0) * 256) )? 1U : 0U;
                        
                        Or_8AE28EB1 = ((0U != Compare_7F02F667) || (0U != Compare_244D9596)) ? 1U : 0U;
                        
                        if(Or_8AE28EB1 != 0U)
                        {
                            /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиция 2
Не пристегнут ремень безопасности\Обнуление расстония езды без ремня */
                            
                            TripSeatBeltStart_data = (MileageTotal_xEE_data);
                            
                        }
                        
                    }
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиция 3
Неисправность тахографа * / */
                    
                        int32_t Function_Call_FC8374B2;
                        int32_t Function_Call_E31FD648;
                        int32_t Function_Call_69669F56;
                        int32_t Function_Call_0DD20503;
                        uint8_t Or_52AE4923;
                        uint8_t Or_12C7BCBB;
                        uint32_t Direct_Switch_66FD098B;
                        
                        Function_Call_FC8374B2 = If_1((((int32_t) (DM1_TachWarning_0xEE_data))));
                        
                        Function_Call_E31FD648 = If_1((((int32_t) (TachSystemEvent_xEE_data))));
                        
                        Function_Call_69669F56 = If_1((((int32_t) (TachHandlingInformation_xEE_data))));
                        
                        Function_Call_0DD20503 = If_1((((int32_t) (TachographPerformance_xEE_data))));
                        
                        Or_52AE4923 = ((0 != Function_Call_FC8374B2) || (0 != Function_Call_E31FD648) || (0 != Function_Call_69669F56) || (0 != Function_Call_0DD20503)) ? 1U : 0U;
                        
                        Or_12C7BCBB = ((0U != (DM1_TachError_0xEE_data)) || (0U != (TimeOut_FE6C_xEE_data))) ? 1U : 0U;
                        
                        Tachograph_GUI_data = ((int8_t) (((0U != Or_52AE4923) || (0U != Or_12C7BCBB)) ? 1U : 0U));
                        
                        if(0U == Or_12C7BCBB)
                        {
                            Direct_Switch_66FD098B = (ColorAmber_data);
                        }
                        else
                        {
                            Direct_Switch_66FD098B = (ColorRed_data);
                        }
                        
                        Tachograph_Color_GUI_data = Direct_Switch_66FD098B;
                        
                    }
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиция 4
Износ тормозных накладок * / */
                    
                        uint8_t Compare_03B958A0;
                        uint8_t Compare_F002E568;
                        uint8_t Compare_5CB3105A;
                        uint8_t Compare_D0F536E0;
                        uint8_t Compare_9EFD84CB;
                        uint8_t Compare_72D60825;
                        uint8_t Compare_8AD82E7E;
                        uint8_t Compare_F63E650D;
                        uint8_t Compare_3901B06B;
                        uint8_t Compare_07AD4275;
                        
                        Compare_03B958A0 = ((BrakePadLA1_x0B_data) < ((uint8_t) 25U) )? 1U : 0U;
                        
                        Compare_F002E568 = ((BrakePadLA1_x0B_data) > ((uint8_t) 250U) )? 1U : 0U;
                        
                        Compare_5CB3105A = ((BrakePadRA1_x0B_data) < ((uint8_t) 25U) )? 1U : 0U;
                        
                        Compare_D0F536E0 = ((BrakePadRA1_x0B_data) > ((uint8_t) 250U) )? 1U : 0U;
                        
                        Compare_9EFD84CB = ((TimeOut_FEAC_x0B_data) == ((uint8_t) 1U) )? 1U : 0U;
                        
                        BrakePadWear1_GUI_data = ((int8_t) (((0U != Compare_03B958A0) || (0U != Compare_F002E568) || (0U != Compare_5CB3105A) || (0U != Compare_D0F536E0) || (0U != Compare_9EFD84CB)) ? 1U : 0U));
                        
                        Compare_72D60825 = ((BrakePadLA2_x0B_data) < ((uint8_t) 25U) )? 1U : 0U;
                        
                        Compare_8AD82E7E = ((BrakePadLA2_x0B_data) > ((uint8_t) 250U) )? 1U : 0U;
                        
                        Compare_F63E650D = ((BrakePadRA2_x0B_data) < ((uint8_t) 25U) )? 1U : 0U;
                        
                        Compare_3901B06B = ((BrakePadRA2_x0B_data) > ((uint8_t) 250U) )? 1U : 0U;
                        
                        Compare_07AD4275 = ((TimeOut_FEAC_x0B_data) == ((uint8_t) 1U) )? 1U : 0U;
                        
                        BrakePadWear2_GUI_data = ((int8_t) (((0U != Compare_72D60825) || (0U != Compare_8AD82E7E) || (0U != Compare_F63E650D) || (0U != Compare_3901B06B) || (0U != Compare_07AD4275)) ? 1U : 0U));
                        
                        BrakePadWear_GUI_data = ((int8_t) (((0 != (BrakePadWear1_GUI_data)) || (0 != (BrakePadWear2_GUI_data))) ? 1U : 0U));
                        
                    }
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиция 7
Стояночный тормоз * / */
                    
                        int32_t Function_Call_D6D28ADA;
                        uint8_t And_333BA7AA;
                        int32_t Function_Call_F0AE2940;
                        int32_t Function_Call_68AA4D25;
                        uint8_t Or_17F3262C;
                        int32_t Function_Call_A021727B;
                        int32_t Function_Call_7A15F840;
                        int32_t Function_Call_512F183C;
                        uint8_t Or_DF746F3C;
                        uint8_t Direct_Switch_AA35FC94;
                        uint32_t Direct_Switch_48CDBCC0;
                        
                        Function_Call_D6D28ADA = If_1((((int32_t) (ParkingBrake_x1E_data))));
                        
                        And_333BA7AA = ((0 != (Ignition_GUI_data)) && (0 != Function_Call_D6D28ADA)) ? 1U : 0U;
                        
                        Function_Call_F0AE2940 = If_1((((int32_t) (DM1_ParkingBrakeWarning_0x50_data))));
                        
                        Function_Call_68AA4D25 = If_1((((int32_t) (ParkingBrakeWarning_x50_data))));
                        
                        Or_17F3262C = ((0 != Function_Call_F0AE2940) || (0 != Function_Call_68AA4D25)) ? 1U : 0U;
                        
                        Function_Call_A021727B = If_1((((int32_t) (DM1_ParkingBrakeError_0x50_data))));
                        
                        Function_Call_7A15F840 = If_1((((int32_t) (ParkingBrakeError_x50_data))));
                        
                        Function_Call_512F183C = If_1((((int32_t) (TimeOut_FF3C_x50_data))));
                        
                        Or_DF746F3C = ((0 != Function_Call_A021727B) || (0 != Function_Call_7A15F840) || (0 != Function_Call_512F183C)) ? 1U : 0U;
                        
                        if(0U == Or_DF746F3C)
                        {
                            Direct_Switch_AA35FC94 = (((0U != And_333BA7AA) || (0U != Or_17F3262C)) ? 1U : 0U);
                        }
                        else
                        {
                            Direct_Switch_AA35FC94 = ((uint8_t)(((int32_t) Or_DF746F3C) * (Blink_1Hz_data)));
                        }
                        
                        ParkingBrakeError_GUI_data = ((int8_t) Direct_Switch_AA35FC94);
                        
                        if(0U == Or_DF746F3C)
                        {
                            Direct_Switch_48CDBCC0 = (ColorAmber_data);
                        }
                        else
                        {
                            Direct_Switch_48CDBCC0 = (ColorRed_data);
                        }
                        
                        ParkingBrakeError_Color_GUI_data = Direct_Switch_48CDBCC0;
                        
                    }
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиции 8 - 10
Низкое давление в контурах 3 - 5 * / */
                    
                        if((TimeOut_FEAE_x1E_data) == ((uint8_t) 0U))
                        {
                            /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиции 8 - 10
Низкое давление в контурах 3 - 5\Main SA: x1E */
                            
                            if((AirPres3_x1E_data) < ((uint8_t) 69U))
                            {
                                /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиции 8 - 10
Низкое давление в контурах 3 - 5\Main SA: x1E\Low pressure in 3 circuit */
                                
                                AirPressure_3_GUI_data = ((int8_t) ((uint8_t) 1U));
                                
                            }
                            
                            if((AirPres3_x1E_data) >= ((uint8_t) 71U))
                            {
                                /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиции 8 - 10
Низкое давление в контурах 3 - 5\Main SA: x1E\Normal pressure in 3 circuit */
                                
                                AirPressure_3_GUI_data = ((int8_t) ((uint8_t) 0U));
                                
                            }
                            
                            AirPressure_4_GUI_data = ((int8_t) (If_1((((int32_t) (AirPres4_x1E_data))))));
                            
                            AirPressure_5_GUI_data = (((AirPres5_x1E_data) == ((uint8_t) 0U) )? 1 : 0);
                            
                        }
                        else
                        {
                            /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиции 8 - 10
Низкое давление в контурах 3 - 5\Second SA: x30 */
                            
                            if((AirPres3_x30_data) < ((uint8_t) 69U))
                            {
                                /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиции 8 - 10
Низкое давление в контурах 3 - 5\Second SA: x30\Low pressure in 3 circuit */
                                
                                AirPressure_3_GUI_data = ((int8_t) ((uint8_t) 1U));
                                
                            }
                            
                            if((AirPres3_x30_data) >= ((uint8_t) 71U))
                            {
                                /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 1
(2 - 10)\Позиции 8 - 10
Низкое давление в контурах 3 - 5\Second SA: x30\Normal pressure in 3 circuit */
                                
                                AirPressure_3_GUI_data = ((int8_t) ((uint8_t) 0U));
                                
                            }
                            
                            AirPressure_4_GUI_data = ((int8_t) (If_1((((int32_t) (AirPres4_xCE_data))))));
                            
                        }
                        
                    }
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Состояние дверей на центральном автобусе * / */
                
                    int32_t Function_Call_D0FFE484;
                    int32_t Function_Call_41281EC2;
                    int32_t Function_Call_47A42533;
                    int32_t Function_Call_2D868F39;
                    int32_t Function_Call_FE9E4EFF;
                    int32_t Function_Call_A886EF3B;
                    int32_t Function_Call_88D91434;
                    int32_t Function_Call_8D20970F;
                    int32_t Function_Call_D32F8AAC;
                    int32_t Function_Call_9A93A3BB;
                    int32_t Function_Call_36DADFFB;
                    int32_t Function_Call_C38B012A;
                    int32_t Function_Call_EA9F054B;
                    uint8_t Read_Parameter_2A437C73;
                    int32_t Function_Call_9EE28F05;
                    uint8_t And_68E9987E;
                    int32_t Function_Call_DFA59EAB;
                    int32_t Function_Call_85BAE3B5;
                    uint8_t Read_Parameter_47E9A600;
                    int32_t Function_Call_6F6EFA65;
                    uint8_t And_34D2D263;
                    int32_t Function_Call_DF6E0F59;
                    int32_t Function_Call_520DC82C;
                    uint8_t Read_Parameter_D6F266FA;
                    int32_t Function_Call_D7B58CE9;
                    uint8_t And_17658C0B;
                    int32_t Function_Call_F4B4C68C;
                    int32_t Function_Call_DFDE9D77;
                    int32_t Function_Call_F950467F;
                    int32_t Function_Call_F71046DD;
                    int32_t Function_Call_E19DDA60;
                    int32_t Function_Call_E051DCA1;
                    int32_t Function_Call_9581D421;
                    int32_t Function_Call_59B82CA1;
                    int32_t Function_Call_A6D1FDDB;
                    int32_t Function_Call_1D948CD4;
                    int32_t Function_Call_2D200807;
                    int32_t Function_Call_A799A34F;
                    int32_t Function_Call_1ABB324D;
                    int32_t Function_Call_242FD5E8;
                    uint8_t Read_Parameter_1FA6D871;
                    int32_t Function_Call_92AE59A5;
                    uint8_t And_62DB6D25;
                    int32_t Function_Call_AEA43FE1;
                    
                    /* Номер двери */
                    
                    /* Номер двери */
                    
                    /* 1-1 */
                    
                    DoorOpening1_1_GUI_data = ((int8_t) (If_1((((int32_t) (Door1Opening_xCC_data))))));
                    
                    DoorOpen1_1_GUI_data = ((int8_t) (If_1((((int32_t) (Door1Opened_xCC_data))))));
                    
                    /* 2 */
                    
                    DoorOpening2_GUI_data = ((int8_t) (If_1((((int32_t) (Door2Opening_xCD_data))))));
                    
                    DoorOpen2_GUI_data = ((int8_t) (If_1((((int32_t) (Door2Opened_xCD_data))))));
                    
                    Function_Call_D0FFE484 = If_1((((int32_t) (Door1Error1_xCC_data))));
                    
                    Function_Call_41281EC2 = If_1((((int32_t) (Door1Error2_xCC_data))));
                    
                    DoorError1_1_GUI_data = ((int8_t) (((0 != Function_Call_D0FFE484) || (0 != Function_Call_41281EC2)) ? 1U : 0U));
                    
                    Function_Call_47A42533 = If_1((((int32_t) (Door2Error1_xCD_data))));
                    
                    Function_Call_2D868F39 = If_1((((int32_t) (Door2Error2_xCD_data))));
                    
                    DoorError2_GUI_data = ((int8_t) (((0 != Function_Call_47A42533) || (0 != Function_Call_2D868F39)) ? 1U : 0U));
                    
                    Function_Call_FE9E4EFF = If_1((((int32_t) (Door1Jam1_xCC_data))));
                    
                    Function_Call_A886EF3B = If_1((((int32_t) (Door1Jam2_xCC_data))));
                    
                    Function_Call_88D91434 = If_1((((int32_t) (Door1Jam3_xCC_data))));
                    
                    Function_Call_8D20970F = If_1((((int32_t) (Door1Jam4_xCC_data))));
                    
                    DoorJam1_1_GUI_data = ((int8_t) (((0 != Function_Call_FE9E4EFF) || (0 != Function_Call_A886EF3B) || (0 != Function_Call_88D91434) || (0 != Function_Call_8D20970F)) ? 1U : 0U));
                    
                    Function_Call_D32F8AAC = If_1((((int32_t) (Door2Jam1_xCD_data))));
                    
                    Function_Call_9A93A3BB = If_1((((int32_t) (Door2Jam2_xCD_data))));
                    
                    Function_Call_36DADFFB = If_1((((int32_t) (Door2Jam3_xCD_data))));
                    
                    Function_Call_C38B012A = If_1((((int32_t) (Door2Jam4_xCD_data))));
                    
                    DoorJam2_GUI_data = ((int8_t) (((0 != Function_Call_D32F8AAC) || (0 != Function_Call_9A93A3BB) || (0 != Function_Call_36DADFFB) || (0 != Function_Call_C38B012A)) ? 1U : 0U));
                    
                    DoorUnauthorized_1_1_GUI_data = ((int8_t) (If_1((((int32_t) (Door1Break_xCC_data))))));
                    
                    DoorUnauthorized_2_GUI_data = ((int8_t) (If_1((((int32_t) (Door2Break_xCD_data))))));
                    
                    Function_Call_EA9F054B = If_1((((int32_t) (Door1Req_xCC_data))));
                    
                    Read_Parameter_2A437C73 = Door1Opened_xCC_data;
                    
                    Function_Call_9EE28F05 = If_0((((int32_t) Read_Parameter_2A437C73)));
                    
                    And_68E9987E = ((0 != Function_Call_EA9F054B) && (0 != Function_Call_9EE28F05)) ? 1U : 0U;
                    
                    if(And_68E9987E != 0U)
                    {
                        DoorRequest_1_1_GUI_data = ((int8_t) 1);
                    }
                    
                    Function_Call_DFA59EAB = If_1((((int32_t) Read_Parameter_2A437C73)));
                    
                    if(Function_Call_DFA59EAB != 0)
                    {
                        DoorRequest_1_1_GUI_data = ((int8_t) 0);
                    }
                    
                    Function_Call_85BAE3B5 = If_1((((int32_t) (Door2Req_xCD_data))));
                    
                    Read_Parameter_47E9A600 = Door2Opened_xCD_data;
                    
                    Function_Call_6F6EFA65 = If_0((((int32_t) Read_Parameter_47E9A600)));
                    
                    And_34D2D263 = ((0 != Function_Call_85BAE3B5) && (0 != Function_Call_6F6EFA65)) ? 1U : 0U;
                    
                    if(And_34D2D263 != 0U)
                    {
                        DoorRequest_2_GUI_data = ((int8_t) 1);
                    }
                    
                    Function_Call_DF6E0F59 = If_1((((int32_t) Read_Parameter_47E9A600)));
                    
                    if(Function_Call_DF6E0F59 != 0)
                    {
                        DoorRequest_2_GUI_data = ((int8_t) 0);
                    }
                    
                    DoorRamp_2_GUI_data = ((int8_t) (If_1((((int32_t) (Door2Ramp_xCD_data))))));
                    
                    /* 1-2 */
                    
                    DoorOpening1_2_GUI_data = ((int8_t) (If_1((((int32_t) (Door1Opening_xCC_data))))));
                    
                    DoorOpen1_2_GUI_data = ((int8_t) (If_1((((int32_t) (Door1Opened_xCC_data))))));
                    
                    Function_Call_520DC82C = If_1((((int32_t) (Door1Req_xCC_data))));
                    
                    Read_Parameter_D6F266FA = Door1Opened_xCC_data;
                    
                    Function_Call_D7B58CE9 = If_0((((int32_t) Read_Parameter_D6F266FA)));
                    
                    And_17658C0B = ((0 != Function_Call_520DC82C) && (0 != Function_Call_D7B58CE9)) ? 1U : 0U;
                    
                    if(And_17658C0B != 0U)
                    {
                        DoorRequest_1_2_GUI_data = ((int8_t) 1);
                    }
                    
                    Function_Call_F4B4C68C = If_1((((int32_t) Read_Parameter_D6F266FA)));
                    
                    if(Function_Call_F4B4C68C != 0)
                    {
                        DoorRequest_1_2_GUI_data = ((int8_t) 0);
                    }
                    
                    /* 3 */
                    
                    DoorOpening3_GUI_data = ((int8_t) (If_1((((int32_t) (Door3Opening_xCE_data))))));
                    
                    DoorOpen3_GUI_data = ((int8_t) (If_1((((int32_t) (Door3Opened_xCE_data))))));
                    
                    Function_Call_DFDE9D77 = If_1((((int32_t) (Door1Error1_xCC_data))));
                    
                    Function_Call_F950467F = If_1((((int32_t) (Door1Error2_xCC_data))));
                    
                    DoorError1_2_GUI_data = ((int8_t) (((0 != Function_Call_DFDE9D77) || (0 != Function_Call_F950467F)) ? 1U : 0U));
                    
                    Function_Call_F71046DD = If_1((((int32_t) (Door3Error1_xCE_data))));
                    
                    Function_Call_E19DDA60 = If_1((((int32_t) (Door3Error2_xCE_data))));
                    
                    DoorError3_GUI_data = ((int8_t) (((0 != Function_Call_F71046DD) || (0 != Function_Call_E19DDA60)) ? 1U : 0U));
                    
                    Function_Call_E051DCA1 = If_1((((int32_t) (Door1Jam1_xCC_data))));
                    
                    Function_Call_9581D421 = If_1((((int32_t) (Door1Jam2_xCC_data))));
                    
                    Function_Call_59B82CA1 = If_1((((int32_t) (Door1Jam3_xCC_data))));
                    
                    Function_Call_A6D1FDDB = If_1((((int32_t) (Door1Jam4_xCC_data))));
                    
                    DoorJam1_2_GUI_data = ((int8_t) (((0 != Function_Call_E051DCA1) || (0 != Function_Call_9581D421) || (0 != Function_Call_59B82CA1) || (0 != Function_Call_A6D1FDDB)) ? 1U : 0U));
                    
                    Function_Call_1D948CD4 = If_1((((int32_t) (Door3Jam1_xCE_data))));
                    
                    Function_Call_2D200807 = If_1((((int32_t) (Door3Jam2_xCE_data))));
                    
                    Function_Call_A799A34F = If_1((((int32_t) (Door3Jam3_xCE_data))));
                    
                    Function_Call_1ABB324D = If_1((((int32_t) (Door3Jam4_xCE_data))));
                    
                    DoorJam3_GUI_data = ((int8_t) (((0 != Function_Call_1D948CD4) || (0 != Function_Call_2D200807) || (0 != Function_Call_A799A34F) || (0 != Function_Call_1ABB324D)) ? 1U : 0U));
                    
                    DoorUnauthorized_1_2_GUI_data = ((int8_t) (If_1((((int32_t) (Door1Break_xCC_data))))));
                    
                    DoorUnauthorized_3_GUI_data = ((int8_t) (If_1((((int32_t) (Door3Break_xCE_data))))));
                    
                    Function_Call_242FD5E8 = If_1((((int32_t) (Door3Req_xCE_data))));
                    
                    Read_Parameter_1FA6D871 = Door3Opened_xCE_data;
                    
                    Function_Call_92AE59A5 = If_0((((int32_t) Read_Parameter_1FA6D871)));
                    
                    And_62DB6D25 = ((0 != Function_Call_242FD5E8) && (0 != Function_Call_92AE59A5)) ? 1U : 0U;
                    
                    if(And_62DB6D25 != 0U)
                    {
                        DoorRequest_3_GUI_data = ((int8_t) 1);
                    }
                    
                    Function_Call_AEA43FE1 = If_1((((int32_t) Read_Parameter_1FA6D871)));
                    
                    if(Function_Call_AEA43FE1 != 0)
                    {
                        DoorRequest_3_GUI_data = ((int8_t) 0);
                    }
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Амперметр.
Стрелка и цифры * / */
                
                    int32_t Read_Parameter_042DF848;
                    int32_t Read_Parameter_16B0A2FE;
                    
                    Read_Parameter_042DF848 = AmmeterForward_Filter_GUI_data;
                    
                    AmmeterArrow_Angle_GUI_data = ((float_t) (LinearScale(((((double_t) Read_Parameter_042DF848) * 2)), ((((double_t) ((int32_t) 0)) * 2)), ((((double_t) ((int32_t) 500)) * 2)), (((double_t) ((float_t) (-90.0F)))), (((double_t) ((float_t) (-180.0F)))))));
                    
                    AmmeterForwardGlow_Angle_GUI_data = ((float_t) (LinearScale(((((double_t) Read_Parameter_042DF848) * 2)), ((((double_t) ((int32_t) 0)) * 2)), ((((double_t) ((int32_t) 500)) * 2)), (((double_t) ((float_t) 0.0F))), (((double_t) ((float_t) (-90.0F)))))));
                    
                    Read_Parameter_16B0A2FE = AmmeterBack_Filter_GUI_data;
                    
                    if(Read_Parameter_042DF848 <= ((int32_t) 0))
                    {
                        {
                            AmmeterBackGlow_Angle_GUI_data = ((float_t) (LinearScale(((((double_t) Read_Parameter_16B0A2FE) / 10)), ((((double_t) ((int32_t) 0)) / 10)), ((((double_t) ((int32_t) (-10000))) / 10)), (((double_t) ((float_t) 0.0F))), (((double_t) ((float_t) 90.0F))))));
                        }
                        {
                            AmmeterArrow_Angle_GUI_data = ((float_t) (LinearScale(((((double_t) Read_Parameter_16B0A2FE) / 10)), ((((double_t) ((int32_t) 0)) / 10)), ((((double_t) ((int32_t) (-10000))) / 10)), (((double_t) ((float_t) (-90.0F)))), (((double_t) ((float_t) 0.0F))))));
                        }
                    }
                    else
                    {
                        AmmeterBackGlow_Angle_GUI_data = ((float_t) 0.0F);
                    }
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 2
(11 - 18) * / */
                
                    LightFar_GUI_data = ((int8_t) (If_1((((int32_t) (HighBeamFB_x1E_data))))));
                    
                    LightNear_GUI_data = ((int8_t) (If_1((((int32_t) (LowBeamFB_x1E_data))))));
                    
                    LightNearAuto_GUI_data = ((int8_t) (If_1((((int32_t) (LowBeamAuto_x1E_data))))));
                    
                    LightSide_GUI_data = ((int8_t) (If_1((((int32_t) (SideLightFB_x1E_data))))));
                    
                    LightLeft_GUI_data = ((int8_t) (If_1((((int32_t) (TurnLeftFB_x1E_data))))));
                    
                    LightRight_GUI_data = ((int8_t) (If_1((((int32_t) (TurnRightFB_x1E_data))))));
                    
                    LightFogFront_GUI_data = ((int8_t) (If_1((((int32_t) (FogFrontFB_x1E_data))))));
                    
                    LightFogBack_GUI_data = ((int8_t) (If_1((((int32_t) (FogRearFB_x1E_data))))));
                    
                    LightDaytime_GUI_data = ((int8_t) (If_1((((int32_t) (RunLightFB_x1E_data))))));
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Заряд.
Стрелка и цифры * / */
                
                    int32_t Read_Parameter_0EA0AE01;
                    
                    Read_Parameter_0EA0AE01 = ChargeReserve_Filter_GUI_data;
                    
                    ChargeReserve_Angle_GUI_data = ((float_t) (LinearScale((((double_t) Read_Parameter_0EA0AE01)), (((double_t) ((int32_t) 0))), (((double_t) ((int32_t) 100))), (((double_t) ((float_t) 0.0F))), (((double_t) ((float_t) 360.0F))))));
                    
                    ChargeReserveGlow_Angle_GUI_data = ((float_t) (LinearScale((((double_t) Read_Parameter_0EA0AE01)), (((double_t) ((int32_t) 0))), (((double_t) ((int32_t) 100))), (((double_t) ((float_t) 90.0F))), (((double_t) ((float_t) 450.0F))))));
                    
                    ChargeReserve_Angle_GUI_data = ((float_t) (LinearScale((((double_t) Read_Parameter_0EA0AE01)), (((double_t) ((int32_t) 0))), (((double_t) ((int32_t) 100))), (((double_t) ((float_t) 0.0F))), (((double_t) ((float_t) 360.0F))))));
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 3
(19 - 28) * / */
                
                    uint8_t Read_Parameter_6F1DAAF5;
                    
                    /* Номер элемета */
                    
                    /* 19 */
                    
                    ClimateSalonPump_GUI_data = ((int8_t) (If_1((((int32_t) (ClimateSalonPump_x1E_data))))));
                    
                    /* 20
                     */
                    
                    Read_Parameter_6F1DAAF5 = ClimateSalonPump_x1E_data;
                    
                    ClimateSalonHeaterModeMain_GUI_data = ((int8_t) ((Read_Parameter_6F1DAAF5 == ((uint8_t) 1U) )? 1U : 0U));
                    
                    ClimateSalonHeaterModeEco_GUI_data = ((int8_t) ((Read_Parameter_6F1DAAF5 == ((uint8_t) 2U) )? 1U : 0U));
                    
                    ClimateSalonPreHeating_GUI_data = ((int8_t) ((Read_Parameter_6F1DAAF5 == ((uint8_t) 3U) )? 1U : 0U));
                    
                    /* 21
                     */
                    
                    ClimateSalonFlame_GUI_data = ((int8_t) (If_1((((int32_t) (ClimateSalonFlame_x1E_data))))));
                    
                    /* 22 */
                    
                    ClimateSalonCoolantFluid_GUI_data = ((int8_t) (((EngClntLvl_x1E_data) < ((uint8_t) 125U) )? 1U : 0U));
                    
                    /* 23 */
                    
                    GURFluid_GUI_data = ((int8_t) (If_1((((int32_t) (GURFluidLow_x1E_data))))));
                    
                    /* 24 */
                    
                    MotorHatch_GUI_data = ((int8_t) (If_1((((int32_t) (BusHood_x1E_data))))));
                    
                    /* 25 */
                    
                    AirSuspensionError_GUI_data = ((int8_t) (If_1((((int32_t) (DM1_SuspenWarning_0x2F_data))))));
                    
                    /* 26 */
                    
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 3
(19 - 28)\Позиция 26
Положение пневматической системы * / */
                    
                        int32_t Function_Call_00022948;
                        int32_t Function_Call_1F4918C6;
                        int32_t Function_Call_AF258C9A;
                        int32_t Function_Call_B2D484C8;
                        int32_t Function_Call_8A895F6A;
                        int32_t Function_Call_D4D9A343;
                        uint8_t And_F3D7FB21;
                        uint8_t Compare_126C5963;
                        uint8_t Compare_757BA4C9;
                        uint8_t Or_779AD4B8;
                        uint8_t And_695275E2;
                        int32_t Function_Call_65B9E4D2;
                        int32_t Function_Call_0BE79A48;
                        uint8_t Or_06E992A5;
                        uint8_t And_6582A7F2;
                        int32_t Multiply_A5CCDB29;
                        uint8_t Compare_33E9DB05;
                        uint8_t Compare_66FDDD40;
                        uint8_t Compare_726B097C;
                        uint8_t Compare_C0B5B837;
                        uint8_t Or_E602D9EC;
                        int32_t Function_Call_BC78F86F;
                        int32_t Function_Call_787AF3D0;
                        int32_t Function_Call_2997AD53;
                        int32_t Function_Call_326BE1C2;
                        int32_t Function_Call_9EA801BF;
                        int32_t Function_Call_5BBDAAFA;
                        uint8_t And_146ECE02;
                        uint8_t Compare_20A62708;
                        uint8_t Compare_3C5EDF81;
                        uint8_t Or_7F579753;
                        uint8_t And_0E04AD0F;
                        int32_t Function_Call_7BF699C2;
                        int32_t Function_Call_DD2F69F7;
                        uint8_t Or_48A7F220;
                        uint8_t And_CEE58EB2;
                        int32_t Multiply_D1832A9E;
                        
                        Function_Call_00022948 = If_0((((int32_t) (Kneeling_SPN1739_x2F_data))));
                        
                        Function_Call_1F4918C6 = If_0((((int32_t) (Kneeling_SPN1756_x2F_data))));
                        
                        Function_Call_AF258C9A = If_0((((int32_t) (Kneeling_SPN1736_x2F_data))));
                        
                        Function_Call_B2D484C8 = If_0((((int32_t) (Kneeling_SPN1737_x2F_data))));
                        
                        Function_Call_8A895F6A = If_0((((int32_t) (Kneeling_SPN1754_x2F_data))));
                        
                        Function_Call_D4D9A343 = If_0((((int32_t) (Kneeling_SPN1738_x2F_data))));
                        
                        And_F3D7FB21 = ((0 != Function_Call_00022948) && (0 != Function_Call_1F4918C6) && (0 != Function_Call_AF258C9A) && (0 != Function_Call_B2D484C8) && (0 != Function_Call_8A895F6A) && (0 != Function_Call_D4D9A343)) ? 1U : 0U;
                        
                        Compare_126C5963 = ((Kneeling_SPN1733_x2F_data) == ((uint8_t) 6U) )? 1U : 0U;
                        
                        Compare_757BA4C9 = ((Kneeling_SPN1734_x2F_data) == ((uint8_t) 6U) )? 1U : 0U;
                        
                        Or_779AD4B8 = ((0U != Compare_126C5963) || (0U != Compare_757BA4C9)) ? 1U : 0U;
                        
                        And_695275E2 = ((0U != And_F3D7FB21) && (0U != Or_779AD4B8)) ? 1U : 0U;
                        
                        Function_Call_65B9E4D2 = If_1((((int32_t) (Kneeling_SPN1739_x2F_data))));
                        
                        Function_Call_0BE79A48 = If_1((((int32_t) (Kneeling_SPN1756_x2F_data))));
                        
                        Or_06E992A5 = ((0 != Function_Call_65B9E4D2) || (0 != Function_Call_0BE79A48)) ? 1U : 0U;
                        
                        And_6582A7F2 = ((0U != Or_779AD4B8) && (0U != Or_06E992A5)) ? 1U : 0U;
                        
                        Multiply_A5CCDB29 = (int32_t)(((int32_t) And_6582A7F2) * (Blink_1Hz_data));
                        
                        TransportPositionUp_GUI_data = ((int8_t) (((0U != And_695275E2) || (0 != Multiply_A5CCDB29)) ? 1U : 0U));
                        
                        Compare_33E9DB05 = ((Kneeling_SPN1733_x2F_data) == ((uint8_t) 0U) )? 1U : 0U;
                        
                        Compare_66FDDD40 = ((Kneeling_SPN1734_x2F_data) == ((uint8_t) 0U) )? 1U : 0U;
                        
                        Compare_726B097C = ((Kneeling_SPN1733_x2F_data) == ((uint8_t) 14U) )? 1U : 0U;
                        
                        Compare_C0B5B837 = ((Kneeling_SPN1734_x2F_data) == ((uint8_t) 14U) )? 1U : 0U;
                        
                        Or_E602D9EC = ((0U != Compare_33E9DB05) || (0U != Compare_66FDDD40) || (0U != Compare_726B097C) || (0U != Compare_C0B5B837)) ? 1U : 0U;
                        
                        TransportPosition_GUI_data = ((int8_t) ((int32_t)(((int32_t) Or_E602D9EC) * (Blink_2Hz_data))));
                        
                        Function_Call_BC78F86F = If_0((((int32_t) (Kneeling_SPN1740_x2F_data))));
                        
                        Function_Call_787AF3D0 = If_0((((int32_t) (Kneeling_SPN1755_x2F_data))));
                        
                        Function_Call_2997AD53 = If_0((((int32_t) (Kneeling_SPN1736_x2F_data))));
                        
                        Function_Call_326BE1C2 = If_0((((int32_t) (Kneeling_SPN1737_x2F_data))));
                        
                        Function_Call_9EA801BF = If_0((((int32_t) (Kneeling_SPN1754_x2F_data))));
                        
                        Function_Call_5BBDAAFA = If_0((((int32_t) (Kneeling_SPN1738_x2F_data))));
                        
                        And_146ECE02 = ((0 != Function_Call_BC78F86F) && (0 != Function_Call_787AF3D0) && (0 != Function_Call_2997AD53) && (0 != Function_Call_326BE1C2) && (0 != Function_Call_9EA801BF) && (0 != Function_Call_5BBDAAFA)) ? 1U : 0U;
                        
                        Compare_20A62708 = ((Kneeling_SPN1733_x2F_data) == ((uint8_t) 7U) )? 1U : 0U;
                        
                        Compare_3C5EDF81 = ((Kneeling_SPN1734_x2F_data) == ((uint8_t) 7U) )? 1U : 0U;
                        
                        Or_7F579753 = ((0U != Compare_20A62708) || (0U != Compare_3C5EDF81)) ? 1U : 0U;
                        
                        And_0E04AD0F = ((0U != And_146ECE02) && (0U != Or_7F579753)) ? 1U : 0U;
                        
                        Function_Call_7BF699C2 = If_1((((int32_t) (Kneeling_SPN1740_x2F_data))));
                        
                        Function_Call_DD2F69F7 = If_1((((int32_t) (Kneeling_SPN1755_x2F_data))));
                        
                        Or_48A7F220 = ((0 != Function_Call_7BF699C2) || (0 != Function_Call_DD2F69F7)) ? 1U : 0U;
                        
                        And_CEE58EB2 = ((0U != Or_7F579753) && (0U != Or_48A7F220)) ? 1U : 0U;
                        
                        Multiply_D1832A9E = (int32_t)(((int32_t) And_CEE58EB2) * (Blink_1Hz_data));
                        
                        TransportPositionDown_GUI_data = ((int8_t) (((0U != And_0E04AD0F) || (0 != Multiply_D1832A9E)) ? 1U : 0U));
                        
                    }
                    /* 27 */
                    
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 3
(19 - 28)\Позиция 27
Книлинг * / */
                    
                        uint8_t Read_Parameter_BD9420BF;
                        uint8_t Compare_ECA07EA5;
                        uint8_t Compare_527CB814;
                        uint8_t Or_3E9117B7;
                        int32_t Multiply_47E539EE;
                        uint8_t Compare_1E88DAEF;
                        
                        Read_Parameter_BD9420BF = Kneeling_x2F_data;
                        
                        Compare_ECA07EA5 = (Read_Parameter_BD9420BF == ((uint8_t) 1U) )? 1U : 0U;
                        
                        Compare_527CB814 = (Read_Parameter_BD9420BF == ((uint8_t) 3U) )? 1U : 0U;
                        
                        Or_3E9117B7 = ((0U != Compare_ECA07EA5) || (0U != Compare_527CB814)) ? 1U : 0U;
                        
                        Multiply_47E539EE = (int32_t)(((int32_t) Or_3E9117B7) * (Blink_1Hz_data));
                        
                        Compare_1E88DAEF = (Read_Parameter_BD9420BF == ((uint8_t) 2U) )? 1U : 0U;
                        
                        Kneeling_GUI_data = ((int8_t) (((0 != Multiply_47E539EE) || (0U != Compare_1E88DAEF)) ? 1U : 0U));
                        
                        KneelingAuto_GUI_data = ((int8_t) (If_1((((int32_t) (KneelingAuto_x1E_data))))));
                        
                    }
                    /* 28 */
                    
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 3
(19 - 28)\Позиция 28
Низкое давление в шинах * / */
                    
                        int32_t Function_Call_B72C3A91;
                        int32_t Function_Call_ABFE7F4E;
                        int32_t Function_Call_0AE9B1C1;
                        int32_t Function_Call_7873E7D9;
                        int32_t Function_Call_75E547E5;
                        int32_t Function_Call_AEB3B280;
                        
                        Function_Call_B72C3A91 = If_1((((int32_t) (TirePresLow00_x33_data))));
                        
                        Function_Call_ABFE7F4E = If_1((((int32_t) (TirePresLow01_x33_data))));
                        
                        Function_Call_0AE9B1C1 = If_1((((int32_t) (TirePresLow10_x33_data))));
                        
                        Function_Call_7873E7D9 = If_1((((int32_t) (TirePresLow11_x33_data))));
                        
                        Function_Call_75E547E5 = If_1((((int32_t) (TirePresLow12_x33_data))));
                        
                        Function_Call_AEB3B280 = If_1((((int32_t) (TirePresLow13_x33_data))));
                        
                        TirePressure_GUI_data = ((int8_t) (((0 != Function_Call_B72C3A91) || (0 != Function_Call_ABFE7F4E) || (0 != Function_Call_0AE9B1C1) || (0 != Function_Call_7873E7D9) || (0 != Function_Call_75E547E5) || (0 != Function_Call_AEB3B280)) ? 1U : 0U));
                        
                    }
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Шкалы давления в пневмоситстемах 1 и 2 * / */
                
                    float_t Read_Parameter_746E7349;
                    int8_t Compare_5FB41786;
                    uint32_t Read_Parameter_6AA727E7;
                    uint32_t Read_Parameter_42C6185A;
                    uint32_t Direct_Switch_6D31543F;
                    int8_t Compare_CCEB4953;
                    int8_t Not_9A53443B;
                    uint32_t Direct_Switch_A3BF4FF3;
                    int8_t Compare_AE85EDA8;
                    uint32_t Direct_Switch_978D42D0;
                    uint32_t Direct_Switch_D1157701;
                    uint32_t Direct_Switch_99F79506;
                    uint32_t Direct_Switch_B892856C;
                    uint32_t Direct_Switch_AAA42F7E;
                    uint32_t Direct_Switch_0C04A061;
                    int8_t Compare_8DC5F4C2;
                    int8_t Compare_1CB2A3DF;
                    uint32_t Direct_Switch_E8C2C158;
                    uint32_t Direct_Switch_5D4F345A;
                    float_t Read_Parameter_D3F691D4;
                    int8_t Compare_F993C54B;
                    uint32_t Read_Parameter_E1951BE5;
                    uint32_t Read_Parameter_95187F75;
                    uint32_t Direct_Switch_6D61BCC8;
                    int8_t Compare_B1285A18;
                    int8_t Not_7B876212;
                    uint32_t Direct_Switch_E4006068;
                    int8_t Compare_9143C970;
                    uint32_t Direct_Switch_EACC6D0B;
                    uint32_t Direct_Switch_339DB328;
                    uint32_t Direct_Switch_5D199A29;
                    uint32_t Direct_Switch_D18F0816;
                    uint32_t Direct_Switch_9C441E98;
                    uint32_t Direct_Switch_5741867A;
                    int8_t Compare_38031A35;
                    int8_t Compare_5EB08F80;
                    uint32_t Direct_Switch_346FB117;
                    uint32_t Direct_Switch_28AFAB7F;
                    
                    Read_Parameter_746E7349 = AirPress1_Filter_GUI_data;
                    
                    Compare_5FB41786 = (Read_Parameter_746E7349 > ((float_t) 1.0F) )? 1 : 0;
                    
                    Read_Parameter_6AA727E7 = ColorWhite_data;
                    
                    Read_Parameter_42C6185A = ColorGray_data;
                    
                    if(0 == Compare_5FB41786)
                    {
                        Direct_Switch_6D31543F = Read_Parameter_42C6185A;
                    }
                    else
                    {
                        Direct_Switch_6D31543F = Read_Parameter_6AA727E7;
                    }
                    
                    Compare_CCEB4953 = (Read_Parameter_746E7349 > ((float_t) 4.0F) )? 1 : 0;
                    
                    Not_9A53443B = (0 == Compare_CCEB4953 )? 1 : 0;
                    
                    if(0 == (((0 != Compare_5FB41786) && (0 != Not_9A53443B)) ? 1 : 0))
                    {
                        Direct_Switch_A3BF4FF3 = Direct_Switch_6D31543F;
                    }
                    else
                    {
                        Direct_Switch_A3BF4FF3 = (ColorYellow_data);
                    }
                    
                    AirPress1_Scale1_Color_GUI_data = Direct_Switch_A3BF4FF3;
                    
                    Compare_AE85EDA8 = (Read_Parameter_746E7349 > ((float_t) 2.0F) )? 1 : 0;
                    
                    if(0 == Compare_AE85EDA8)
                    {
                        Direct_Switch_978D42D0 = Read_Parameter_42C6185A;
                    }
                    else
                    {
                        Direct_Switch_978D42D0 = Read_Parameter_6AA727E7;
                    }
                    
                    if(0 == (((0 != Compare_AE85EDA8) && (0 != Not_9A53443B)) ? 1 : 0))
                    {
                        Direct_Switch_D1157701 = Direct_Switch_978D42D0;
                    }
                    else
                    {
                        Direct_Switch_D1157701 = (ColorYellow_data);
                    }
                    
                    AirPress1_Scale2_Color_GUI_data = Direct_Switch_D1157701;
                    
                    if(0 == ((Read_Parameter_746E7349 > ((float_t) 6.0F) )? 1 : 0))
                    {
                        Direct_Switch_99F79506 = Read_Parameter_42C6185A;
                    }
                    else
                    {
                        Direct_Switch_99F79506 = Read_Parameter_6AA727E7;
                    }
                    
                    AirPress1_Scale4_Color_GUI_data = Direct_Switch_99F79506;
                    
                    if(0 == ((Read_Parameter_746E7349 > ((float_t) 8.0F) )? 1 : 0))
                    {
                        Direct_Switch_B892856C = Read_Parameter_42C6185A;
                    }
                    else
                    {
                        Direct_Switch_B892856C = Read_Parameter_6AA727E7;
                    }
                    
                    AirPress1_Scale5_Color_GUI_data = Direct_Switch_B892856C;
                    
                    if(0 == ((Read_Parameter_746E7349 > ((float_t) 10.0F) )? 1 : 0))
                    {
                        Direct_Switch_AAA42F7E = Read_Parameter_42C6185A;
                    }
                    else
                    {
                        Direct_Switch_AAA42F7E = (ColorYellow_data);
                    }
                    
                    AirPress1_Scale6_Color_GUI_data = Direct_Switch_AAA42F7E;
                    
                    if(0 == ((Read_Parameter_746E7349 > ((float_t) 12.0F) )? 1 : 0))
                    {
                        Direct_Switch_0C04A061 = Read_Parameter_42C6185A;
                    }
                    else
                    {
                        Direct_Switch_0C04A061 = (ColorRed_data);
                    }
                    
                    AirPress1_Scale7_Color_GUI_data = Direct_Switch_0C04A061;
                    
                    Compare_8DC5F4C2 = (Read_Parameter_746E7349 < ((float_t) 5.5F) )? 1 : 0;
                    
                    Compare_1CB2A3DF = (Read_Parameter_746E7349 > ((float_t) 8.8F) )? 1 : 0;
                    
                    if(0 == (((0 != Compare_8DC5F4C2) || (0 != Compare_1CB2A3DF)) ? 1 : 0))
                    {
                        Direct_Switch_E8C2C158 = (ColorGray_data);
                    }
                    else
                    {
                        Direct_Switch_E8C2C158 = (ColorRed_data);
                    }
                    
                    AirPress1_Color_GUI_data = Direct_Switch_E8C2C158;
                    
                    if(0 == Compare_CCEB4953)
                    {
                        Direct_Switch_5D4F345A = Read_Parameter_42C6185A;
                    }
                    else
                    {
                        Direct_Switch_5D4F345A = Read_Parameter_6AA727E7;
                    }
                    
                    AirPress1_Scale3_Color_GUI_data = Direct_Switch_5D4F345A;
                    
                    Read_Parameter_D3F691D4 = AirPress2_Filter_GUI_data;
                    
                    Compare_F993C54B = (Read_Parameter_D3F691D4 > ((float_t) 1.0F) )? 1 : 0;
                    
                    Read_Parameter_E1951BE5 = ColorWhite_data;
                    
                    Read_Parameter_95187F75 = ColorGray_data;
                    
                    if(0 == Compare_F993C54B)
                    {
                        Direct_Switch_6D61BCC8 = Read_Parameter_95187F75;
                    }
                    else
                    {
                        Direct_Switch_6D61BCC8 = Read_Parameter_E1951BE5;
                    }
                    
                    Compare_B1285A18 = (Read_Parameter_D3F691D4 > ((float_t) 4.0F) )? 1 : 0;
                    
                    Not_7B876212 = (0 == Compare_B1285A18 )? 1 : 0;
                    
                    if(0 == (((0 != Compare_F993C54B) && (0 != Not_7B876212)) ? 1 : 0))
                    {
                        Direct_Switch_E4006068 = Direct_Switch_6D61BCC8;
                    }
                    else
                    {
                        Direct_Switch_E4006068 = (ColorYellow_data);
                    }
                    
                    AirPress2_Scale1_Color_GUI_data = Direct_Switch_E4006068;
                    
                    Compare_9143C970 = (Read_Parameter_D3F691D4 > ((float_t) 2.0F) )? 1 : 0;
                    
                    if(0 == Compare_9143C970)
                    {
                        Direct_Switch_EACC6D0B = Read_Parameter_95187F75;
                    }
                    else
                    {
                        Direct_Switch_EACC6D0B = Read_Parameter_E1951BE5;
                    }
                    
                    if(0 == (((0 != Compare_9143C970) && (0 != Not_7B876212)) ? 1 : 0))
                    {
                        Direct_Switch_339DB328 = Direct_Switch_EACC6D0B;
                    }
                    else
                    {
                        Direct_Switch_339DB328 = (ColorYellow_data);
                    }
                    
                    AirPress2_Scale2_Color_GUI_data = Direct_Switch_339DB328;
                    
                    if(0 == ((Read_Parameter_D3F691D4 > ((float_t) 6.0F) )? 1 : 0))
                    {
                        Direct_Switch_5D199A29 = Read_Parameter_95187F75;
                    }
                    else
                    {
                        Direct_Switch_5D199A29 = Read_Parameter_E1951BE5;
                    }
                    
                    AirPress2_Scale4_Color_GUI_data = Direct_Switch_5D199A29;
                    
                    if(0 == ((Read_Parameter_D3F691D4 > ((float_t) 8.0F) )? 1 : 0))
                    {
                        Direct_Switch_D18F0816 = Read_Parameter_95187F75;
                    }
                    else
                    {
                        Direct_Switch_D18F0816 = Read_Parameter_E1951BE5;
                    }
                    
                    AirPress2_Scale5_Color_GUI_data = Direct_Switch_D18F0816;
                    
                    if(0 == ((Read_Parameter_D3F691D4 > ((float_t) 10.0F) )? 1 : 0))
                    {
                        Direct_Switch_9C441E98 = Read_Parameter_95187F75;
                    }
                    else
                    {
                        Direct_Switch_9C441E98 = (ColorYellow_data);
                    }
                    
                    AirPress2_Scale6_Color_GUI_data = Direct_Switch_9C441E98;
                    
                    if(0 == ((Read_Parameter_D3F691D4 > ((float_t) 12.0F) )? 1 : 0))
                    {
                        Direct_Switch_5741867A = Read_Parameter_95187F75;
                    }
                    else
                    {
                        Direct_Switch_5741867A = (ColorRed_data);
                    }
                    
                    AirPress2_Scale7_Color_GUI_data = Direct_Switch_5741867A;
                    
                    Compare_38031A35 = (Read_Parameter_D3F691D4 < ((float_t) 5.5F) )? 1 : 0;
                    
                    Compare_5EB08F80 = (Read_Parameter_D3F691D4 > ((float_t) 8.8F) )? 1 : 0;
                    
                    if(0 == (((0 != Compare_38031A35) || (0 != Compare_5EB08F80)) ? 1 : 0))
                    {
                        Direct_Switch_346FB117 = (ColorGray_data);
                    }
                    else
                    {
                        Direct_Switch_346FB117 = (ColorRed_data);
                    }
                    
                    AirPress2_Color_GUI_data = Direct_Switch_346FB117;
                    
                    if(0 == Compare_B1285A18)
                    {
                        Direct_Switch_28AFAB7F = Read_Parameter_95187F75;
                    }
                    else
                    {
                        Direct_Switch_28AFAB7F = Read_Parameter_E1951BE5;
                    }
                    
                    AirPress2_Scale3_Color_GUI_data = Direct_Switch_28AFAB7F;
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 4
(29 - 30) * / */
                
                    int32_t Function_Call_8EF07C2F;
                    int32_t Function_Call_B1E9943E;
                    int32_t Function_Call_9D985051;
                    uint8_t Compare_BEE1E535;
                    uint8_t Compare_1D52DF3E;
                    uint8_t Compare_5ECBB530;
                    uint8_t Compare_191B0D59;
                    uint8_t Direct_Switch_A71F9C3B;
                    uint8_t Compare_93AA95C1;
                    int32_t Function_Call_B5524530;
                    int32_t Function_Call_6C8D31D5;
                    int32_t Function_Call_4B0AD179;
                    int32_t Function_Call_0A2A2562;
                    uint8_t And_F37C6902;
                    uint32_t Direct_Switch_CCF38017;
                    
                    /* Номер элемета */
                    
                    /* 29 */
                    
                    Function_Call_8EF07C2F = If_1((((int32_t) (HaltBrake_x0B_data))));
                    
                    Function_Call_B1E9943E = If_1((((int32_t) (EBSError_x0B_data))));
                    
                    Function_Call_9D985051 = If_1((((int32_t) (EBSWarning_x0B_data))));
                    
                    Compare_BEE1E535 = ((AirPres1_x30_data) > ((uint8_t) 100U) )? 1U : 0U;
                    
                    Compare_1D52DF3E = ((AirPres2_x30_data) > ((uint8_t) 100U) )? 1U : 0U;
                    
                    Compare_5ECBB530 = ((AirPres1_xFE_data) > ((uint8_t) 100U) )? 1U : 0U;
                    
                    Compare_191B0D59 = ((AirPres2_xFE_data) > ((uint8_t) 100U) )? 1U : 0U;
                    
                    if(0U == (TimeOut_FEAE_x1E_data))
                    {
                        Direct_Switch_A71F9C3B = (((0U != Compare_5ECBB530) && (0U != Compare_191B0D59)) ? 1U : 0U);
                    }
                    else
                    {
                        Direct_Switch_A71F9C3B = (((0U != Compare_BEE1E535) && (0U != Compare_1D52DF3E)) ? 1U : 0U);
                    }
                    
                    Compare_93AA95C1 = ((Speedometer_Text_GUI_data) == ((int32_t) 0) )? 1U : 0U;
                    
                    Function_Call_B5524530 = If_1((((int32_t) (Door1Opened_xCC_data))));
                    
                    Function_Call_6C8D31D5 = If_1((((int32_t) (Door2Opened_xCD_data))));
                    
                    Function_Call_4B0AD179 = If_1((((int32_t) (Door3Opened_xCE_data))));
                    
                    Function_Call_0A2A2562 = If_0((((int32_t) (HaltBrake_x0B_data))));
                    
                    And_F37C6902 = ((0 != Function_Call_B1E9943E) && (0 != Function_Call_9D985051) && (0U != Direct_Switch_A71F9C3B) && (0U != Compare_93AA95C1) && (0 != Function_Call_B5524530) && (0 != Function_Call_6C8D31D5) && (0 != Function_Call_4B0AD179) && (0 != Function_Call_0A2A2562)) ? 1U : 0U;
                    
                    DoorBrake_GUI_data = ((int8_t) (((0 != Function_Call_8EF07C2F) || (0U != And_F37C6902)) ? 1U : 0U));
                    
                    if(0U == And_F37C6902)
                    {
                        Direct_Switch_CCF38017 = (ColorAmber_data);
                    }
                    else
                    {
                        Direct_Switch_CCF38017 = (ColorRed_data);
                    }
                    
                    DoorBrake_Color_GUI_data = Direct_Switch_CCF38017;
                    
                    /* 30 */
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Шкалы напряжения аккумуляторов * / */
                
                    int32_t Read_Parameter_179AC1E5;
                    int8_t Compare_1103D693;
                    uint32_t Read_Parameter_DF67D59D;
                    uint32_t Read_Parameter_6C6A86C1;
                    uint32_t Direct_Switch_CD03E943;
                    int8_t Compare_6DE896A5;
                    int8_t Not_D14DAEAB;
                    uint32_t Direct_Switch_4D5989F1;
                    int8_t Compare_8716474B;
                    uint32_t Direct_Switch_186265EC;
                    uint32_t Direct_Switch_F3BB0808;
                    uint32_t Direct_Switch_D155D7B3;
                    uint32_t Direct_Switch_4A421514;
                    uint32_t Direct_Switch_753D8711;
                    uint32_t Direct_Switch_8EC843A3;
                    int8_t Compare_A173A4AD;
                    int8_t Compare_1557D27F;
                    uint32_t Direct_Switch_5732422F;
                    uint32_t Direct_Switch_B3066801;
                    int32_t Read_Parameter_A1FD2A0A;
                    int8_t Compare_445CD506;
                    uint32_t Read_Parameter_DD1FF32D;
                    uint32_t Read_Parameter_64A980DE;
                    uint32_t Direct_Switch_96A1ED1A;
                    int8_t Compare_681B414B;
                    int8_t Not_0CCD2074;
                    uint32_t Direct_Switch_BE7B22FE;
                    int8_t Compare_3ED73781;
                    uint32_t Direct_Switch_AF79BE3D;
                    uint32_t Direct_Switch_68A166F2;
                    uint32_t Direct_Switch_BF881806;
                    uint32_t Direct_Switch_A3B75BA3;
                    uint32_t Direct_Switch_346B8806;
                    uint32_t Direct_Switch_5FAA9F50;
                    int8_t Compare_F3FB4928;
                    int8_t Compare_EAF56AA8;
                    uint32_t Direct_Switch_0405C273;
                    uint32_t Direct_Switch_B5121A08;
                    
                    Read_Parameter_179AC1E5 = BatteryHV_Filter_GUI_data;
                    
                    Compare_1103D693 = (Read_Parameter_179AC1E5 > ((int32_t) 6300) )? 1 : 0;
                    
                    Read_Parameter_DF67D59D = ColorWhite_data;
                    
                    Read_Parameter_6C6A86C1 = ColorGray_data;
                    
                    if(0 == Compare_1103D693)
                    {
                        Direct_Switch_CD03E943 = Read_Parameter_6C6A86C1;
                    }
                    else
                    {
                        Direct_Switch_CD03E943 = Read_Parameter_DF67D59D;
                    }
                    
                    Compare_6DE896A5 = (Read_Parameter_179AC1E5 > ((int32_t) 6900) )? 1 : 0;
                    
                    Not_D14DAEAB = (0 == Compare_6DE896A5 )? 1 : 0;
                    
                    if(0 == (((0 != Compare_1103D693) && (0 != Not_D14DAEAB)) ? 1 : 0))
                    {
                        Direct_Switch_4D5989F1 = Direct_Switch_CD03E943;
                    }
                    else
                    {
                        Direct_Switch_4D5989F1 = (ColorYellow_data);
                    }
                    
                    BatteryHV_Scale1_Color_GUI_data = Direct_Switch_4D5989F1;
                    
                    Compare_8716474B = (Read_Parameter_179AC1E5 > ((int32_t) 6600) )? 1 : 0;
                    
                    if(0 == Compare_8716474B)
                    {
                        Direct_Switch_186265EC = Read_Parameter_6C6A86C1;
                    }
                    else
                    {
                        Direct_Switch_186265EC = Read_Parameter_DF67D59D;
                    }
                    
                    if(0 == (((0 != Compare_8716474B) && (0 != Not_D14DAEAB)) ? 1 : 0))
                    {
                        Direct_Switch_F3BB0808 = Direct_Switch_186265EC;
                    }
                    else
                    {
                        Direct_Switch_F3BB0808 = (ColorYellow_data);
                    }
                    
                    BatteryHV_Scale2_Color_GUI_data = Direct_Switch_F3BB0808;
                    
                    if(0 == ((Read_Parameter_179AC1E5 > ((int32_t) 7200) )? 1 : 0))
                    {
                        Direct_Switch_D155D7B3 = Read_Parameter_6C6A86C1;
                    }
                    else
                    {
                        Direct_Switch_D155D7B3 = Read_Parameter_DF67D59D;
                    }
                    
                    BatteryHV_Scale4_Color_GUI_data = Direct_Switch_D155D7B3;
                    
                    if(0 == ((Read_Parameter_179AC1E5 > ((int32_t) 7500) )? 1 : 0))
                    {
                        Direct_Switch_4A421514 = Read_Parameter_6C6A86C1;
                    }
                    else
                    {
                        Direct_Switch_4A421514 = Read_Parameter_DF67D59D;
                    }
                    
                    BatteryHV_Scale5_Color_GUI_data = Direct_Switch_4A421514;
                    
                    if(0 == ((Read_Parameter_179AC1E5 > ((int32_t) 7700) )? 1 : 0))
                    {
                        Direct_Switch_753D8711 = Read_Parameter_6C6A86C1;
                    }
                    else
                    {
                        Direct_Switch_753D8711 = (ColorYellow_data);
                    }
                    
                    BatteryHV_Scale6_Color_GUI_data = Direct_Switch_753D8711;
                    
                    if(0 == ((Read_Parameter_179AC1E5 > ((int32_t) 7900) )? 1 : 0))
                    {
                        Direct_Switch_8EC843A3 = Read_Parameter_6C6A86C1;
                    }
                    else
                    {
                        Direct_Switch_8EC843A3 = (ColorRed_data);
                    }
                    
                    BatteryHV_Scale7_Color_GUI_data = Direct_Switch_8EC843A3;
                    
                    Compare_A173A4AD = (Read_Parameter_179AC1E5 < ((int32_t) 6900) )? 1 : 0;
                    
                    Compare_1557D27F = (Read_Parameter_179AC1E5 > ((int32_t) 7900) )? 1 : 0;
                    
                    if(0 == (((0 != Compare_A173A4AD) || (0 != Compare_1557D27F)) ? 1 : 0))
                    {
                        Direct_Switch_5732422F = (ColorGray_data);
                    }
                    else
                    {
                        Direct_Switch_5732422F = (ColorRed_data);
                    }
                    
                    BatteryHV_Color_GUI_data = Direct_Switch_5732422F;
                    
                    if(0 == Compare_6DE896A5)
                    {
                        Direct_Switch_B3066801 = Read_Parameter_6C6A86C1;
                    }
                    else
                    {
                        Direct_Switch_B3066801 = Read_Parameter_DF67D59D;
                    }
                    
                    BatteryHV_Scale3_Color_GUI_data = Direct_Switch_B3066801;
                    
                    Read_Parameter_A1FD2A0A = BatteryLV_Filter_GUI_data;
                    
                    Compare_445CD506 = (Read_Parameter_A1FD2A0A > ((int32_t) 80) )? 1 : 0;
                    
                    Read_Parameter_DD1FF32D = ColorWhite_data;
                    
                    Read_Parameter_64A980DE = ColorGray_data;
                    
                    if(0 == Compare_445CD506)
                    {
                        Direct_Switch_96A1ED1A = Read_Parameter_64A980DE;
                    }
                    else
                    {
                        Direct_Switch_96A1ED1A = Read_Parameter_DD1FF32D;
                    }
                    
                    Compare_681B414B = (Read_Parameter_A1FD2A0A > ((int32_t) 240) )? 1 : 0;
                    
                    Not_0CCD2074 = (0 == Compare_681B414B )? 1 : 0;
                    
                    if(0 == (((0 != Compare_445CD506) && (0 != Not_0CCD2074)) ? 1 : 0))
                    {
                        Direct_Switch_BE7B22FE = Direct_Switch_96A1ED1A;
                    }
                    else
                    {
                        Direct_Switch_BE7B22FE = (ColorYellow_data);
                    }
                    
                    BatteryLV_Scale1_Color_GUI_data = Direct_Switch_BE7B22FE;
                    
                    Compare_3ED73781 = (Read_Parameter_A1FD2A0A > ((int32_t) 160) )? 1 : 0;
                    
                    if(0 == Compare_3ED73781)
                    {
                        Direct_Switch_AF79BE3D = Read_Parameter_64A980DE;
                    }
                    else
                    {
                        Direct_Switch_AF79BE3D = Read_Parameter_DD1FF32D;
                    }
                    
                    if(0 == (((0 != Compare_3ED73781) && (0 != Not_0CCD2074)) ? 1 : 0))
                    {
                        Direct_Switch_68A166F2 = Direct_Switch_AF79BE3D;
                    }
                    else
                    {
                        Direct_Switch_68A166F2 = (ColorYellow_data);
                    }
                    
                    BatteryLV_Scale2_Color_GUI_data = Direct_Switch_68A166F2;
                    
                    if(0 == ((Read_Parameter_A1FD2A0A > ((int32_t) 320) )? 1 : 0))
                    {
                        Direct_Switch_BF881806 = Read_Parameter_64A980DE;
                    }
                    else
                    {
                        Direct_Switch_BF881806 = Read_Parameter_DD1FF32D;
                    }
                    
                    BatteryLV_Scale4_Color_GUI_data = Direct_Switch_BF881806;
                    
                    if(0 == ((Read_Parameter_A1FD2A0A > ((int32_t) 400) )? 1 : 0))
                    {
                        Direct_Switch_A3B75BA3 = Read_Parameter_64A980DE;
                    }
                    else
                    {
                        Direct_Switch_A3B75BA3 = Read_Parameter_DD1FF32D;
                    }
                    
                    BatteryLV_Scale5_Color_GUI_data = Direct_Switch_A3B75BA3;
                    
                    if(0 == ((Read_Parameter_A1FD2A0A > ((int32_t) 480) )? 1 : 0))
                    {
                        Direct_Switch_346B8806 = Read_Parameter_64A980DE;
                    }
                    else
                    {
                        Direct_Switch_346B8806 = (ColorYellow_data);
                    }
                    
                    BatteryLV_Scale6_Color_GUI_data = Direct_Switch_346B8806;
                    
                    if(0 == ((Read_Parameter_A1FD2A0A > ((int32_t) 520) )? 1 : 0))
                    {
                        Direct_Switch_5FAA9F50 = Read_Parameter_64A980DE;
                    }
                    else
                    {
                        Direct_Switch_5FAA9F50 = (ColorRed_data);
                    }
                    
                    BatteryLV_Scale7_Color_GUI_data = Direct_Switch_5FAA9F50;
                    
                    Compare_F3FB4928 = (Read_Parameter_A1FD2A0A < ((int32_t) 200) )? 1 : 0;
                    
                    Compare_EAF56AA8 = (Read_Parameter_A1FD2A0A > ((int32_t) 540) )? 1 : 0;
                    
                    if(0 == (((0 != Compare_F3FB4928) || (0 != Compare_EAF56AA8)) ? 1 : 0))
                    {
                        Direct_Switch_0405C273 = (ColorGray_data);
                    }
                    else
                    {
                        Direct_Switch_0405C273 = (ColorRed_data);
                    }
                    
                    BatteryLV_Color_GUI_data = Direct_Switch_0405C273;
                    
                    if(0 == Compare_681B414B)
                    {
                        Direct_Switch_B5121A08 = Read_Parameter_64A980DE;
                    }
                    else
                    {
                        Direct_Switch_B5121A08 = Read_Parameter_DD1FF32D;
                    }
                    
                    BatteryLV_Scale3_Color_GUI_data = Direct_Switch_B5121A08;
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 5
(31- 42) * / */
                
                    uint8_t Read_Parameter_6163AD24;
                    int32_t Function_Call_8481C325;
                    int32_t Function_Call_999DDDE1;
                    uint8_t Or_08FB0700;
                    int32_t Function_Call_5ECB0E80;
                    uint8_t Not_64983108;
                    uint8_t Read_Parameter_3F65F4B1;
                    
                    /* Номер элемета */
                    
                    /* 31 */
                    
                    FlightIndicator_GUI_data = ((int8_t) (If_1((((int32_t) (FlightIndicator_x1E_data))))));
                    
                    /* 32 */
                    
                    Read_Parameter_6163AD24 = SalonLight_x1E_data;
                    
                    SalonLightPer50_GUI_data = ((int8_t) (If_1((((int32_t) Read_Parameter_6163AD24)))));
                    
                    SalonLightPer100_GUI_data = ((int8_t) ((Read_Parameter_6163AD24 == ((uint8_t) 2U) )? 1U : 0U));
                    
                    /* 33 */
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                    /* 34 */
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                    /* 35 */
                    
                    Function_Call_8481C325 = If_1((((int32_t) (Door2ReqDis_xCD_data))));
                    
                    Function_Call_999DDDE1 = If_1((((int32_t) (RampRequest_x1E_data))));
                    
                    Or_08FB0700 = ((0 != Function_Call_8481C325) || (0 != Function_Call_999DDDE1)) ? 1U : 0U;
                    
                    Function_Call_5ECB0E80 = If_1((((int32_t) (Door2Ramp_xCD_data))));
                    
                    Not_64983108 = (0 == Function_Call_5ECB0E80 )? 1U : 0U;
                    
                    DisabledRequest_GUI_data = ((int8_t) (((0U != Or_08FB0700) && (0U != Not_64983108)) ? 1U : 0U));
                    
                    Ramp_GUI_data = ((int8_t) Function_Call_5ECB0E80);
                    
                    /* 36 */
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                    /* 37 */
                    
                    MirrorHeating_GUI_data = ((int8_t) (If_1((((int32_t) (MirrorHeat_x1E_data))))));
                    
                    /* 38 */
                    
                    GlassHeating_GUI_data = ((int8_t) (If_1((((int32_t) (GlassHeating_x1E_data))))));
                    
                    /* 40 */
                    
                    Read_Parameter_3F65F4B1 = WiperCtrl_x1E_data;
                    
                    WindshieldFitful_GUI_data = ((int8_t) ((Read_Parameter_3F65F4B1 == ((uint8_t) 1U) )? 1U : 0U));
                    
                    WindshieldSpeedOne_GUI_data = ((int8_t) ((Read_Parameter_3F65F4B1 == ((uint8_t) 2U) )? 1U : 0U));
                    
                    WindshieldSpeedTwo_GUI_data = ((int8_t) ((Read_Parameter_3F65F4B1 == ((uint8_t) 3U) )? 1U : 0U));
                    
                    WindshieldAuto_GUI_data = ((int8_t) (((WiperSwitch_x54_data) == ((uint8_t) 3U) )? 1U : 0U));
                    
                    /* 41 */
                    
                    WasherFluid_GUI_data = ((int8_t) (((WasherLvl_x1E_data) < ((uint8_t) 62U) )? 1U : 0U));
                    
                    /* 42 */
                    
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Линия 5
(31- 42)\Позиция 42
Критический угол складывания узла сочленения * / */
                    
                        int32_t Function_Call_F7EB68A1;
                        uint8_t Compare_ACC29087;
                        uint8_t Compare_D2465C8D;
                        uint8_t And_3814CA03;
                        uint8_t Compare_CBBC2F35;
                        uint8_t Compare_5D104055;
                        uint8_t And_6F946E99;
                        int32_t Function_Call_4CFF0D91;
                        uint32_t Direct_Switch_96E73DB1;
                        
                        Function_Call_F7EB68A1 = If_1((((int32_t) (SwingError_xE7_data))));
                        
                        Compare_ACC29087 = ((SwingAngle_xE7_data) > ((int16_t) 78) )? 1U : 0U;
                        
                        Compare_D2465C8D = ((DriveGear_x03_data) >= ((uint8_t) 124U) )? 1U : 0U;
                        
                        And_3814CA03 = ((0U != Compare_ACC29087) && (0U != Compare_D2465C8D)) ? 1U : 0U;
                        
                        Compare_CBBC2F35 = ((SwingAngle_xE7_data) > ((int16_t) 90) )? 1U : 0U;
                        
                        Compare_5D104055 = ((DriveGear_x03_data) >= ((uint8_t) 126U) )? 1U : 0U;
                        
                        And_6F946E99 = ((0U != Compare_CBBC2F35) && (0U != Compare_5D104055)) ? 1U : 0U;
                        
                        Function_Call_4CFF0D91 = If_1((((int32_t) (SwingWarning_xE7_data))));
                        
                        AngleOfRotation_GUI_data = ((int8_t) (((0 != Function_Call_F7EB68A1) || (0U != And_3814CA03) || (0U != And_6F946E99) || (0 != Function_Call_4CFF0D91)) ? 1U : 0U));
                        
                        if(0 == Function_Call_4CFF0D91)
                        {
                            Direct_Switch_96E73DB1 = (ColorRed_data);
                        }
                        else
                        {
                            Direct_Switch_96E73DB1 = (ColorAmber_data);
                        }
                        
                        AngleOfRotation_Color_GUI_data = Direct_Switch_96E73DB1;
                        
                    }
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Климат
(43 - 50) * / */
                
                    uint8_t Read_Parameter_4F908118;
                    int32_t Function_Call_1F9BB8EA;
                    uint32_t Direct_Switch_75060482;
                    uint8_t Read_Parameter_BD0AE1FB;
                    
                    /* Номер элемета */
                    
                    /* 43 */
                    
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Климат
(43 - 50)\Позиция 43
Фронтальный отопитель * / */
                    
                        int32_t Function_Call_94A7CAA0;
                        int32_t Function_Call_6E0A72F2;
                        int32_t Function_Call_D0E4DBD1;
                        uint8_t Or_C27251B4;
                        uint8_t Direct_Switch_DD36CDBB;
                        uint32_t Direct_Switch_BFB5F99E;
                        
                        Function_Call_94A7CAA0 = If_1((((int32_t) (ClimateSalonFrontHeatingSB40_x1E_data))));
                        
                        Function_Call_6E0A72F2 = If_1((((int32_t) (ClimateSalonFrontHeatingSB42_x1E_data))));
                        
                        Function_Call_D0E4DBD1 = If_1((((int32_t) (ClimateSalonFrontHeatingError_x1E_data))));
                        
                        Or_C27251B4 = ((0 != Function_Call_94A7CAA0) || (0 != Function_Call_6E0A72F2) || (0 != Function_Call_D0E4DBD1)) ? 1U : 0U;
                        
                        if(0U == Or_C27251B4)
                        {
                            Direct_Switch_DD36CDBB = (ClimateDriverGlassFrontHeating_x1E_data);
                        }
                        else
                        {
                            Direct_Switch_DD36CDBB = ((uint8_t) 0U);
                        }
                        
                        ClimateDriverGlassFrontHeatingSpeedOne_GUI_data = ((int8_t) (If_1((((int32_t) Direct_Switch_DD36CDBB)))));
                        
                        ClimateDriverGlassFrontHeatingSpeedTwo_GUI_data = ((int8_t) ((Direct_Switch_DD36CDBB == ((uint8_t) 2U) )? 1U : 0U));
                        
                        ClimateDriverGlassFrontHeatingSpeedThree_GUI_data = ((int8_t) ((Direct_Switch_DD36CDBB == ((uint8_t) 3U) )? 1U : 0U));
                        
                        if(0 == Function_Call_D0E4DBD1)
                        {
                            Direct_Switch_BFB5F99E = (ColorAmber_data);
                        }
                        else
                        {
                            Direct_Switch_BFB5F99E = (ColorRed_data);
                        }
                        
                        ClimateDriverGlassFrontHeating_Color_GUI_data = Direct_Switch_BFB5F99E;
                        
                        ClimateDriverGlassFrontHeating_GUI_data = ((int8_t) Or_C27251B4);
                        
                    }
                    /* 45 */
                    
                    Read_Parameter_4F908118 = ClimateDriverFan_x1E_data;
                    
                    ClimateDriverFanOut_GUI_data = ((int8_t) (If_1((((int32_t) Read_Parameter_4F908118)))));
                    
                    ClimateDriverFanIn_GUI_data = ((int8_t) ((Read_Parameter_4F908118 == ((uint8_t) 2U) )? 1U : 0U));
                    
                    /* 46 */
                    
                    Function_Call_1F9BB8EA = If_1((((int32_t) (ClimateDriverChairHeating_x1E_data))));
                    
                    ClimateDriverChairHeating_GUI_data = ((int8_t) Function_Call_1F9BB8EA);
                    
                    if(0 == Function_Call_1F9BB8EA)
                    {
                        Direct_Switch_75060482 = (ColorRed_data);
                    }
                    else
                    {
                        Direct_Switch_75060482 = (ColorYellow_data);
                    }
                    
                    ClimateDriverChairHeating_Color_GUI_data = Direct_Switch_75060482;
                    
                    /* 47 */
                    
                    {
                        /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Центральные пиктограммы.
Климат
(43 - 50)\Позиция 47
Отопитель кабины водителя * / */
                    
                        ClimateDriverHeatingSpeedOne_GUI_data = ((int8_t) (If_1((((int32_t) (ClimateDriverHeatingSpeedOne_x1E_data))))));
                        
                        ClimateDriverHeatingSpeedTwo_GUI_data = ((int8_t) (If_1((((int32_t) (ClimateDriverHeatingSpeedTwo_x1E_data))))));
                        
                        ClimateDriverHeatingError_GUI_data = ((int8_t) (If_1((((int32_t) (ClimateDriverHeatingSpeedError_x1E_data))))));
                        
                    }
                    /* 49 */
                    
                    Read_Parameter_BD0AE1FB = ClimateSalon_x19_data;
                    
                    ClimateSalonConditioner_GUI_data = ((int8_t) ((Read_Parameter_BD0AE1FB == ((uint8_t) 2U) )? 1U : 0U));
                    
                    ClimateSalonAuto_GUI_data = ((int8_t) ((Read_Parameter_BD0AE1FB == ((uint8_t) 5U) )? 1U : 0U));
                    
                    /* 50 */
                    
                    ClimateSalonHeatingSpeedOne_GUI_data = ((int8_t) (If_1((((int32_t) (ClimateSalonHeatingSpeedOne_x19_data))))));
                    
                    ClimateSalonHeatingSpeedTwo_GUI_data = ((int8_t) (If_1((((int32_t) (ClimateSalonHeatingSpeedTwo_x19_data))))));
                    
                    ClimateSalonHeatingError_GUI_data = ((int8_t) (((ClimateSalonHeatingError_x19_data) == ((uint8_t) 129U) )? 1U : 0U));
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Пневмосистема
(51 - 52) * / */
                
                    if((TimeOut_FEAE_x1E_data) == ((uint8_t) 0U))
                    {
                        uint8_t Compare_133BFC23;
                        uint8_t Compare_2C122AE4;
                        uint8_t And_E96869E3;
                        uint32_t Direct_Switch_245C3327;
                        uint8_t Compare_9DA634B6;
                        uint8_t Compare_4109A4FB;
                        uint8_t And_AB4C76B9;
                        uint32_t Direct_Switch_1C91BE0F;
                        /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Пневмосистема
(51 - 52)\Main SA: x1E */
                        
                        /* Номер элемета */
                        
                        /* 51 */
                        
                        if((AirPres1_x1E_data) < ((uint8_t) 69U))
                        {
                            AirPress1Error_GUI_data = ((int8_t) ((uint8_t) 1U));
                        }
                        
                        Compare_133BFC23 = (((uint8_t) 69U) > ((uint8_t) 81U) )? 1U : 0U;
                        
                        Compare_2C122AE4 = (((uint8_t) 69U) < ((uint8_t) 109U) )? 1U : 0U;
                        
                        And_E96869E3 = ((0U != Compare_133BFC23) && (0U != Compare_2C122AE4)) ? 1U : 0U;
                        
                        if(And_E96869E3 != 0U)
                        {
                            AirPress1Error_GUI_data = ((int8_t) ((uint8_t) 0U));
                        }
                        
                        if(((uint8_t) 69U) > ((uint8_t) 110U))
                        {
                            AirPress1Error_GUI_data = ((int8_t) ((uint8_t) 1U));
                        }
                        
                        if(0 == (AirPress1Error_GUI_data))
                        {
                            Direct_Switch_245C3327 = (ColorGray_data);
                        }
                        else
                        {
                            Direct_Switch_245C3327 = (ColorRed_data);
                        }
                        
                        AirPress1_Color_GUI_data = Direct_Switch_245C3327;
                        
                        /* 52 */
                        
                        if((AirPres2_x1E_data) < ((uint8_t) 69U))
                        {
                            AirPress2Error_GUI_data = ((int8_t) ((uint8_t) 1U));
                        }
                        
                        Compare_9DA634B6 = (((uint8_t) 69U) > ((uint8_t) 81U) )? 1U : 0U;
                        
                        Compare_4109A4FB = (((uint8_t) 69U) < ((uint8_t) 109U) )? 1U : 0U;
                        
                        And_AB4C76B9 = ((0U != Compare_9DA634B6) && (0U != Compare_4109A4FB)) ? 1U : 0U;
                        
                        if(And_AB4C76B9 != 0U)
                        {
                            AirPress2Error_GUI_data = ((int8_t) ((uint8_t) 0U));
                        }
                        
                        if(((uint8_t) 69U) > ((uint8_t) 110U))
                        {
                            AirPress2Error_GUI_data = ((int8_t) ((uint8_t) 1U));
                        }
                        
                        if(0 == (AirPress2Error_GUI_data))
                        {
                            Direct_Switch_1C91BE0F = (ColorGray_data);
                        }
                        else
                        {
                            Direct_Switch_1C91BE0F = (ColorRed_data);
                        }
                        
                        AirPress2_Color_GUI_data = Direct_Switch_1C91BE0F;
                        
                    }
                    else
                    {
                        uint8_t Compare_B0807E06;
                        uint8_t Compare_6157C089;
                        uint8_t And_D0F9067C;
                        uint32_t Direct_Switch_67EABB30;
                        uint8_t Compare_7CD69F43;
                        uint8_t Compare_320B66D2;
                        uint8_t And_6A339DC1;
                        uint32_t Direct_Switch_C4C49995;
                        /* UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Пневмосистема
(51 - 52)\Second SA: x30 */
                        
                        /* Номер элемета */
                        
                        /* 51 */
                        
                        if((AirPres1_x30_data) < ((uint8_t) 69U))
                        {
                            AirPress1Error_GUI_data = ((int8_t) ((uint8_t) 1U));
                        }
                        
                        Compare_B0807E06 = (((uint8_t) 69U) > ((uint8_t) 81U) )? 1U : 0U;
                        
                        Compare_6157C089 = (((uint8_t) 69U) < ((uint8_t) 109U) )? 1U : 0U;
                        
                        And_D0F9067C = ((0U != Compare_B0807E06) && (0U != Compare_6157C089)) ? 1U : 0U;
                        
                        if(And_D0F9067C != 0U)
                        {
                            AirPress1Error_GUI_data = ((int8_t) ((uint8_t) 0U));
                        }
                        
                        if(((uint8_t) 69U) > ((uint8_t) 110U))
                        {
                            AirPress1Error_GUI_data = ((int8_t) ((uint8_t) 1U));
                        }
                        
                        if(0 == (AirPress1Error_GUI_data))
                        {
                            Direct_Switch_67EABB30 = (ColorGray_data);
                        }
                        else
                        {
                            Direct_Switch_67EABB30 = (ColorRed_data);
                        }
                        
                        AirPress1_Color_GUI_data = Direct_Switch_67EABB30;
                        
                        /* 52 */
                        
                        if((AirPres2_x30_data) < ((uint8_t) 69U))
                        {
                            AirPress2Error_GUI_data = ((int8_t) ((uint8_t) 1U));
                        }
                        
                        Compare_7CD69F43 = (((uint8_t) 69U) > ((uint8_t) 81U) )? 1U : 0U;
                        
                        Compare_320B66D2 = (((uint8_t) 69U) < ((uint8_t) 109U) )? 1U : 0U;
                        
                        And_6A339DC1 = ((0U != Compare_7CD69F43) && (0U != Compare_320B66D2)) ? 1U : 0U;
                        
                        if(And_6A339DC1 != 0U)
                        {
                            AirPress2Error_GUI_data = ((int8_t) ((uint8_t) 0U));
                        }
                        
                        if(((uint8_t) 69U) > ((uint8_t) 110U))
                        {
                            AirPress2Error_GUI_data = ((int8_t) ((uint8_t) 1U));
                        }
                        
                        if(0 == (AirPress2Error_GUI_data))
                        {
                            Direct_Switch_C4C49995 = (ColorGray_data);
                        }
                        else
                        {
                            Direct_Switch_C4C49995 = (ColorRed_data);
                        }
                        
                        AirPress2_Color_GUI_data = Direct_Switch_C4C49995;
                        
                    }
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Аккумуляторы
(53 - 54) * / */
                
                    int32_t Function_Call_84575429;
                    int32_t Function_Call_AD0F6415;
                    uint8_t Not_DA09C571;
                    int32_t Function_Call_6F077FED;
                    uint8_t Compare_741135C6;
                    
                    /* Номер элемета */
                    
                    /* 53 */
                    
                    Function_Call_84575429 = If_1((((int32_t) (BatteryHV_xE1_data))));
                    
                    Function_Call_AD0F6415 = If_1((((int32_t) (DM1_BatteryHVError_0xBC_data))));
                    
                    Not_DA09C571 = (0 == Function_Call_AD0F6415 )? 1U : 0U;
                    
                    BatteryHV_GUI_data = ((int8_t) (((0 != Function_Call_84575429) && (0U != Not_DA09C571)) ? 1U : 0U));
                    
                    BatteryHVError_GUI_data = ((int8_t) Function_Call_AD0F6415);
                    
                    /* 54 */
                    
                    Function_Call_6F077FED = If_1((((int32_t) (Battery24VDis_x1E_data))));
                    
                    Compare_741135C6 = ((LVBatteryV_x1E_data) < ((int32_t) 440) )? 1U : 0U;
                    
                    BatteryLVError_GUI_data = ((int8_t) (((0 != Function_Call_6F077FED) || (0U != Compare_741135C6)) ? 1U : 0U));
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Пиктограммы спидометра
(55 - 67) * / */
                
                    uint8_t Compare_E25315C1;
                    uint8_t Compare_28089BBC;
                    uint8_t Compare_AD4A8D85;
                    int32_t Function_Call_220E6811;
                    int32_t Function_Call_3AD21701;
                    uint8_t And_421D065D;
                    double_t Multiply_F982592B;
                    int32_t Function_Call_4BFBA4EF;
                    uint8_t And_085D157E;
                    int32_t Function_Call_1C7270D4;
                    int32_t Function_Call_3802BDE3;
                    uint8_t Read_Parameter_32C66840;
                    int32_t Function_Call_0176219F;
                    uint8_t Compare_82CFF27C;
                    int32_t Function_Call_191547BA;
                    int32_t Function_Call_2C4719EF;
                    uint8_t Read_Parameter_917407A3;
                    uint32_t Direct_Switch_5B37F234;
                    int32_t Function_Call_D212012F;
                    
                    /* Номер элемета */
                    
                    /* 55 */
                    
                    CruiseControl_GUI_data = ((int8_t) (If_1((((int32_t) (CruiseControlActive_x00_data))))));
                    
                    LIM_GUI_data = ((int8_t) (((Speedometer_Text_GUI_data) >= (SpeedLimit_0x00_data) )? 1U : 0U));
                    
                    /* 57 */
                    
                    Compare_E25315C1 = ((RetarderTrq_x0F_data) < ((int32_t) 0) )? 1U : 0U;
                    
                    Compare_28089BBC = ((RetarderTrq_x0F_data) < ((int32_t) 0) )? 1U : 0U;
                    
                    Compare_AD4A8D85 = ((RetarderTrq_x0F_data) < ((int32_t) 0) )? 1U : 0U;
                    
                    Retarder_GUI_data = ((int8_t) (((0U != Compare_E25315C1) || (0U != Compare_28089BBC) || (0U != Compare_AD4A8D85)) ? 1U : 0U));
                    
                    /* 58 */
                    
                    Function_Call_220E6811 = If_1((((int32_t) (ESP_x0B_data))));
                    
                    Function_Call_3AD21701 = If_1((((int32_t) (ESPError_x0B_data))));
                    
                    And_421D065D = ((0 != Function_Call_220E6811) && (0 != Function_Call_3AD21701)) ? 1U : 0U;
                    
                    Multiply_F982592B = (double_t)(((double_t) And_421D065D) * ((double_t) (Blink_2Hz_data)));
                    
                    Function_Call_4BFBA4EF = If_0((((int32_t) (ESPError_x0B_data))));
                    
                    And_085D157E = ((0 != Function_Call_220E6811) && (0 != Function_Call_4BFBA4EF)) ? 1U : 0U;
                    
                    ESP_GUI_data = ((int8_t) (((0 != Multiply_F982592B) || (0U != And_085D157E) || (0U != (TimeOut_FE4F_x0B_data))) ? 1U : 0U));
                    
                    Function_Call_1C7270D4 = If_1((((int32_t) (ASROff_x0B_data))));
                    
                    ESPOff_GUI_data = ((int8_t) (((0U != And_085D157E) && (0 != Function_Call_1C7270D4)) ? 1U : 0U));
                    
                    /* 65 */
                    
                    HelperSoundQuietBus_GUI_data = ((int8_t) (If_0((((int32_t) (QuietBusSong_x01_data))))));
                    
                    /* 66 */
                    
                    Function_Call_3802BDE3 = If_1((((int32_t) (HillHold_x0B_data))));
                    
                    Read_Parameter_32C66840 = HillHoldMode_x0B_data;
                    
                    Function_Call_0176219F = If_1((((int32_t) Read_Parameter_32C66840)));
                    
                    Compare_82CFF27C = (Read_Parameter_32C66840 == ((uint8_t) 2U) )? 1U : 0U;
                    
                    HillStartAid_GUI_data = ((int8_t) (((0 != Function_Call_3802BDE3) || (0 != Function_Call_0176219F) || (0U != Compare_82CFF27C)) ? 1U : 0U));
                    
                    /* 67 */
                    
                    Function_Call_191547BA = If_1((((int32_t) (EBSError_x0B_data))));
                    
                    Function_Call_2C4719EF = If_1((((int32_t) (EBSWarning_x0B_data))));
                    
                    Read_Parameter_917407A3 = TimeOut_F001_x0B_data;
                    
                    EBS_GUI_data = ((int8_t) (((0 != Function_Call_191547BA) || (0 != Function_Call_2C4719EF) || (0U != Read_Parameter_917407A3)) ? 1U : 0U));
                    
                    if(0 == Function_Call_191547BA)
                    {
                        Direct_Switch_5B37F234 = (ColorYellow_data);
                    }
                    else
                    {
                        Direct_Switch_5B37F234 = (ColorRed_data);
                    }
                    
                    EBS_Color_GUI_data = Direct_Switch_5B37F234;
                    
                    Function_Call_D212012F = If_1((((int32_t) (ABSOffSwitch_x0B_data))));
                    
                    ABS_GUI_data = ((int8_t) (((0U != Read_Parameter_917407A3) || (0 != Function_Call_D212012F)) ? 1U : 0U));
                    
                }
                {
                    /* / * UI and contol\Controller\Алгоритм конвертации параметров из Can'а в параметры управления объектами.\Пиктограммы тахометра и амперметра
(68 - 80) * / */
                
                    int32_t Function_Call_CEF33D1A;
                    int32_t Function_Call_1054EDBD;
                    uint8_t And_072E3D76;
                    int32_t Function_Call_6B2D816A;
                    int32_t Function_Call_02BBBA05;
                    uint32_t Direct_Switch_CA5B54F9;
                    uint32_t Direct_Switch_AA9EC4B8;
                    int32_t Function_Call_BA0B20B7;
                    int32_t Function_Call_BCC96813;
                    uint32_t Direct_Switch_992EDFB0;
                    int32_t Function_Call_672C67B7;
                    int32_t Function_Call_0A2FDCD0;
                    uint8_t And_E03073C2;
                    int32_t Function_Call_3A70EF3B;
                    int32_t Function_Call_8AF2B800;
                    
                    /* Номер элемета */
                    
                    /* 68 */
                    
                    ChargeConnector_GUI_data = ((int8_t) (If_1((((int32_t) (ChargeConnectorHV_xE1_data))))));
                    
                    /* 69 */
                    
                    /* 70 */
                    
                    Function_Call_CEF33D1A = If_0((((int32_t) (IsolationTestHVOne_xE1_data))));
                    
                    Function_Call_1054EDBD = If_0((((int32_t) (IsolationTestHVTwo_xE1_data))));
                    
                    And_072E3D76 = ((0 != Function_Call_CEF33D1A) && (0 != Function_Call_1054EDBD)) ? 1U : 0U;
                    
                    Function_Call_6B2D816A = If_1((((int32_t) (IsolationTestHVOne_xE1_data))));
                    
                    Function_Call_02BBBA05 = If_1((((int32_t) (IsolationTestHVTwo_xE1_data))));
                    
                    ChargeConnector_GUI_data = ((int8_t) (((0U != And_072E3D76) || (0 != Function_Call_6B2D816A) || (0 != Function_Call_02BBBA05)) ? 1U : 0U));
                    
                    if(0 == Function_Call_6B2D816A)
                    {
                        Direct_Switch_CA5B54F9 = (ColorGreen_data);
                    }
                    else
                    {
                        Direct_Switch_CA5B54F9 = (ColorYellow_data);
                    }
                    
                    if(0 == Function_Call_02BBBA05)
                    {
                        Direct_Switch_AA9EC4B8 = Direct_Switch_CA5B54F9;
                    }
                    else
                    {
                        Direct_Switch_AA9EC4B8 = (ColorRed_data);
                    }
                    
                    ChargeConnector_Color_GUI_data = Direct_Switch_AA9EC4B8;
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                    /* 71 */
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                    /* 72 */
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                    /* 73 */
                    
                    Function_Call_BA0B20B7 = If_1((((int32_t) (DM1_MotorWarnig_0xEF_data))));
                    
                    Function_Call_BCC96813 = If_1((((int32_t) (DM1_MotorError_0xEF_data))));
                    
                    MotorError_GUI_data = ((int8_t) (((0 != Function_Call_BA0B20B7) || (0 != Function_Call_BCC96813)) ? 1U : 0U));
                    
                    if(0 == Function_Call_BCC96813)
                    {
                        Direct_Switch_992EDFB0 = (ColorYellow_data);
                    }
                    else
                    {
                        Direct_Switch_992EDFB0 = (ColorRed_data);
                    }
                    
                    MotorError_Color_GUI_data = Direct_Switch_992EDFB0;
                    
                    /* 74 */
                    
                    BatteryHVTempSystem_GUI_data = ((int8_t) (If_1((((int32_t) (BatteryHVTempError_xE1_data))))));
                    
                    /* 75 */
                    
                    BatteryHVCoolantFluid_GUI_data = ((int8_t) (If_1((((int32_t) (BatteryHVCoolantFluid_xE1_data))))));
                    
                    /* 76 */
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                    /* 77 */
                    
                    Function_Call_672C67B7 = If_1((((int32_t) (DM1_ExhaustError_0x00_data))));
                    
                    Function_Call_0A2FDCD0 = If_1((((int32_t) (BatteryHVCoolantFluid_xE1_data))));
                    
                    And_E03073C2 = ((0U != (TimeOut_FE56_x00_data)) && (0U != (TimeOut_FE56_x3D_data))) ? 1U : 0U;
                    
                    Function_Call_3A70EF3B = If_0((((((int32_t) (AdBlueLvl_0x00_data)) * 2) / 5)));
                    
                    Function_Call_8AF2B800 = If_0((((((int32_t) (AdBlueLvl_0x3D_data)) * 2) / 5)));
                    
                    BatteryHVCoolantFluid_GUI_data = ((int8_t) (((0 != Function_Call_672C67B7) || (0 != Function_Call_0A2FDCD0) || (0U != And_E03073C2) || (0 != Function_Call_3A70EF3B) || (0 != Function_Call_8AF2B800)) ? 1U : 0U));
                    
                    /* 78 */
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                    /* 79 */
                    
                    DriveFanHydraulicError_GUI_data = ((int8_t) (If_1((((int32_t) (HydroFanError_x2E_data))))));
                    
                    /* 80 */
                    
                    /* Недостаточно данных или пересекается с другим параметром */
                    
                }
            }
            {
                /* / * UI and contol\Controller\Управление анимацие и подсветкой экрана от состояния ключа зажигания * / */
            
                double_t Digital_Clock_80420204;
                double_t Compare_97D4B72A;
                int32_t Function_Call_6031E0DA;
                int32_t Function_Call_1F337D85;
                int64_t Subtract_748922CB;
                uint32_t Compare_6D01BCD3;
                int32_t Function_Call_7FEC44A1;
                double_t And_EEF7026C;
                
                Digital_Clock_80420204 = 0;
                
                Compare_97D4B72A = (Digital_Clock_80420204 >= ((double_t) ((int32_t) 100)) )? 1 : 0;
                
                if(Compare_97D4B72A != 0)
                {
                    IgnitionStartVideo_GUI_data = ((int8_t) 0);
                }
                
                IgnitionDelta_GUI_data = (((int8_t)((Ignition_GUI_data) - (IgnitionOld_GUI_data))));
                
                IgnitionOld_GUI_data = (Ignition_GUI_data);
                
                Function_Call_6031E0DA = If_1((((int32_t) (IgnitionDelta_GUI_data))));
                
                if(Function_Call_6031E0DA != 0)
                {
                    IgnitionStartVideo_GUI_data = ((int8_t) 1);
                }
                
                IgnitionStartVideoDelta_GUI_data = (((int8_t)((IgnitionStartVideo_GUI_data) - (IgnitionStartVideoOld_GUI_data))));
                
                IgnitionStartVideoOld_GUI_data = (IgnitionStartVideo_GUI_data);
                
                if((IgnitionStartVideoDelta_GUI_data) == ((int8_t) (-1)))
                {
                    {
                        IgnitionStartPict_GUI_data = ((int8_t) 1);
                    }
                    {
                        IgnitionTimeStart_GUI_data = ((int32_t) (GlobalTimeCountMs_data));
                    }
                }
                
                IgnitionTimeCount_GUI_data = ((int32_t) (((int64_t)((GlobalTimeCountMs_data) - ((int64_t) (IgnitionTimeStart_GUI_data))))));
                
                if((IgnitionTimeCount_GUI_data) >= ((int32_t) ((int64_t) 3000L)))
                {
                    IgnitionStartPict_GUI_data = ((int8_t) 0);
                }
                
                Function_Call_1F337D85 = If_1((((int32_t) (Ignition_GUI_data))));
                
                if(Function_Call_1F337D85 != 0)
                {
                    TFT_Brightness_GUI_data = ((uint32_t) ((uint8_t) 248U));
                }
                
                if((IgnitionDelta_GUI_data) == ((int8_t) (-1)))
                {
                    {
                        IgnitionTimeOff_GUI_data = ((int32_t) (GlobalTimeCountMs_data));
                    }
                    {
                        TFT_Brightness_GUI_data = ((uint32_t) ((uint8_t) 100U));
                    }
                }
                
                Subtract_748922CB = ((int64_t)((GlobalTimeCountMs_data) - ((int64_t) (IgnitionTimeOff_GUI_data))));
                
                Compare_6D01BCD3 = (Subtract_748922CB >= ((int64_t) 6000L) )? 1U : 0U;
                
                Function_Call_7FEC44A1 = If_0((((int32_t) (Ignition_GUI_data))));
                
                And_EEF7026C = ((0U != Compare_6D01BCD3) && (0 != Function_Call_7FEC44A1)) ? 1 : 0;
                
                if(And_EEF7026C != 0)
                {
                    TFT_Brightness_GUI_data = ((uint32_t) ((int8_t) 0));
                }
                
            }
            {
                /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм * / */
            
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Центральные пиктограммы.
Линия 1
(2 - 10) * / */
                
                    /* Номер элемета */
                    
                    /* 2 */
                    
                    AlphaGradientLimitter250ms(&DriverLeaveChair_AlphaPict_GUI_data, (((uint8_t) (DriverLeaveChair_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&SeatBelt_AlphaPict_GUI_data, (((uint8_t) (SeatBelt_GUI_data))));
                    
                    /* 3 */
                    
                    AlphaGradientLimitter250ms(&Tachograph_AlphaPict_GUI_data, (((uint8_t) (Tachograph_GUI_data))));
                    
                    /* 4 */
                    
                    AlphaGradientLimitter250ms(&BrakePadWear_AlphaPict_GUI_data, (((uint8_t) (BrakePadWear_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&BrakePadWear1_AlphaPict_GUI_data, (((uint8_t) (BrakePadWear1_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&BrakePadWear2_AlphaPict_GUI_data, (((uint8_t) (BrakePadWear2_GUI_data))));
                    
                    /* 5 */
                    
                    AlphaGradientLimitter250ms(&BrakeSystemError_AlphaPict_GUI_data, (((uint8_t) (BrakeSystemError_GUI_data))));
                    
                    /* 6 */
                    
                    AlphaGradientLimitter250ms(&Stop_AlphaPict_GUI_data, (((uint8_t) (Stop_GUI_data))));
                    
                    /* 7 */
                    
                    AlphaGradientLimitter250ms(&ParkingBrakeError_AlphaPict_GUI_data, (((uint8_t) (Blink_1Hz_data))));
                    
                    /* 8 */
                    
                    AlphaGradientLimitter250ms(&AirPressure_3_AlphaPict_GUI_data, (((uint8_t) (AirPressure_3_GUI_data))));
                    
                    /* 9 */
                    
                    AlphaGradientLimitter250ms(&AirPressure_4_AlphaPict_GUI_data, (((uint8_t) (AirPressure_4_GUI_data))));
                    
                    /* 10 */
                    
                    AlphaGradientLimitter250ms(&AirPressure_5_AlphaPict_GUI_data, (((uint8_t) (AirPressure_5_GUI_data))));
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Пневмосистема
(51 - 52) * / */
                
                    /* 51 */
                    
                    /* Изменяется только цвет */
                    
                    /* 52 */
                    
                    /* Изменяется только цвет */
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Центральные пиктограммы.
Линия 2
(11 - 18) * / */
                
                    /* Номер элемета */
                    
                    /* 11 */
                    
                    AlphaGradientLimitter250ms(&LightFar_AlphaPict_GUI_data, (((uint8_t) (LightFar_GUI_data))));
                    
                    /* 12 */
                    
                    AlphaGradientLimitter250ms(&LightNear_AlphaPict_GUI_data, (((uint8_t) (LightNear_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&LightNearAuto_AlphaPict_GUI_data, (((uint8_t) (LightNearAuto_GUI_data))));
                    
                    /* 13 */
                    
                    AlphaGradientLimitter250ms(&LightSide_AlphaPict_GUI_data, (((uint8_t) (LightSide_GUI_data))));
                    
                    /* 14 */
                    
                    AlphaGradientLimitter250ms(&LightLeft_AlphaPict_GUI_data, (((uint8_t) (LightLeft_GUI_data))));
                    
                    /* 15 */
                    
                    AlphaGradientLimitter250ms(&LightRight_AlphaPict_GUI_data, (((uint8_t) (LightRight_GUI_data))));
                    
                    /* 16 */
                    
                    AlphaGradientLimitter250ms(&LightFogFront_AlphaPict_GUI_data, (((uint8_t) (LightFogFront_GUI_data))));
                    
                    /* 17 */
                    
                    AlphaGradientLimitter250ms(&LightFogBack_AlphaPict_GUI_data, (((uint8_t) (LightFogBack_GUI_data))));
                    
                    /* 18 */
                    
                    AlphaGradientLimitter250ms(&LightDaytime_AlphaPict_GUI_data, (((uint8_t) (LightDaytime_GUI_data))));
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Аккумуляторы
(53 - 54) * / */
                
                    /* Номер элемета */
                    
                    /* 53 */
                    
                    AlphaGradientLimitter250ms(&BatteryHV_AlphaPict_GUI_data, (((uint8_t) (BatteryHV_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&BatteryHVError_AlphaPict_GUI_data, (((uint8_t) (BatteryHVError_GUI_data))));
                    
                    /* 54 */
                    
                    AlphaGradientLimitter250ms(&BatteryLV_AlphaPict_GUI_data, (((uint8_t) (BatteryLV_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&BatteryLVError_AlphaPict_GUI_data, (((uint8_t) (BatteryLVError_GUI_data))));
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Центральные пиктограммы.
Линия 3
(19 - 28) * / */
                
                    /* Номер элемета */
                    
                    /* 19 */
                    
                    AlphaGradientLimitter250ms(&ClimateSalonPump_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonPump_GUI_data))));
                    
                    /* 20
                     */
                    
                    AlphaGradientLimitter250ms(&ClimateSalonHeaterModeMain_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonHeaterModeMain_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateSalonHeaterModeEco_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonHeaterModeEco_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateSalonPreHeating_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonPreHeating_GUI_data))));
                    
                    /* 21
                     */
                    
                    AlphaGradientLimitter250ms(&ClimateSalonFlame_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonFlame_GUI_data))));
                    
                    /* 22 */
                    
                    AlphaGradientLimitter250ms(&ClimateSalonCoolantFluid_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonCoolantFluid_GUI_data))));
                    
                    /* 23 */
                    
                    AlphaGradientLimitter250ms(&GUROverheat_AlphaPict_GUI_data, (((uint8_t) (GUROverheat_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&GURFluid_AlphaPict_GUI_data, (((uint8_t) (GURFluid_GUI_data))));
                    
                    /* 24 */
                    
                    AlphaGradientLimitter250ms(&BusReady_AlphaPict_GUI_data, (((uint8_t) (BusReady_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&BusBan_AlphaPict_GUI_data, (((uint8_t) (BusBan_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&MotorHatch_AlphaPict_GUI_data, (((uint8_t) (MotorHatch_GUI_data))));
                    
                    /* 25 */
                    
                    AlphaGradientLimitter250ms(&AirSuspensionError_AlphaPict_GUI_data, (((uint8_t) (AirSuspensionError_GUI_data))));
                    
                    /* 26 */
                    
                    AlphaGradientLimitter250ms(&TransportPositionUp_AlphaPict_GUI_data, (((uint8_t) (TransportPositionUp_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&TransportPosition_AlphaPict_GUI_data, (((uint8_t) (TransportPosition_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&TransportPositionDown_AlphaPict_GUI_data, (((uint8_t) (TransportPositionDown_GUI_data))));
                    
                    /* 27 */
                    
                    AlphaGradientLimitter250ms(&Kneeling_AlphaPict_GUI_data, (((uint8_t) (Kneeling_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&KneelingAuto_AlphaPict_GUI_data, (((uint8_t) (KneelingAuto_GUI_data))));
                    
                    /* 28 */
                    
                    AlphaGradientLimitter250ms(&TirePressure_AlphaPict_GUI_data, (((uint8_t) (TirePressure_GUI_data))));
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Пиктограммы спидометра
(55 - 67) * / */
                
                    /* Номер элемета */
                    
                    /* 55 */
                    
                    AlphaGradientLimitter250ms(&CruiseControl_AlphaPict_GUI_data, (((uint8_t) (CruiseControl_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&LIM_AlphaPict_GUI_data, (((uint8_t) (LIM_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&CruiseControlAdaptive_AlphaPict_GUI_data, (((uint8_t) (CruiseControlAdaptive_GUI_data))));
                    
                    /* 56 */
                    
                    AlphaGradientLimitter250ms(&InstructorPedal_AlphaPict_GUI_data, (((uint8_t) (InstructorPedal_GUI_data))));
                    
                    /* 57 */
                    
                    AlphaGradientLimitter250ms(&Retarder_AlphaPict_GUI_data, (((uint8_t) (Retarder_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&RecuperationOff_AlphaPict_GUI_data, (((uint8_t) (RecuperationOff_GUI_data))));
                    
                    /* 58 */
                    
                    AlphaGradientLimitter250ms(&ESP_AlphaPict_GUI_data, (((uint8_t) (ESP_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ESPOff_AlphaPict_GUI_data, (((uint8_t) (ESPOff_GUI_data))));
                    
                    /* 59 */
                    
                    AlphaGradientLimitter250ms(&HelperDistanceCritical_AlphaPict_GUI_data, (((uint8_t) (HelperDistanceCritical_GUI_data))));
                    
                    /* 60 */
                    
                    AlphaGradientLimitter250ms(&HelperLaneKeeping_AlphaPict_GUI_data, (((uint8_t) (HelperLaneKeeping_GUI_data))));
                    
                    /* 61 */
                    
                    AlphaGradientLimitter250ms(&HelperBlindSpot_AlphaPict_GUI_data, (((uint8_t) (HelperBlindSpot_GUI_data))));
                    
                    /* 62 */
                    
                    AlphaGradientLimitter250ms(&HelperLane_AlphaPict_GUI_data, (((uint8_t) (HelperLane_GUI_data))));
                    
                    /* 63 */
                    
                    AlphaGradientLimitter250ms(&HelperParking_AlphaPict_GUI_data, (((uint8_t) (HelperParking_GUI_data))));
                    
                    /* 64 */
                    
                    AlphaGradientLimitter250ms(&HelperHindrance_AlphaPict_GUI_data, (((uint8_t) (HelperHindrance_GUI_data))));
                    
                    /* 65 */
                    
                    AlphaGradientLimitter250ms(&HelperSoundQuietBus_AlphaPict_GUI_data, (((uint8_t) (HelperSoundQuietBus_GUI_data))));
                    
                    /* 66 */
                    
                    AlphaGradientLimitter250ms(&HillStartAid_AlphaPict_GUI_data, (((uint8_t) (HillStartAid_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&StopBrake_AlphaPict_GUI_data, (((uint8_t) (StopBrake_GUI_data))));
                    
                    /* 67 */
                    
                    AlphaGradientLimitter250ms(&EBS_AlphaPict_GUI_data, (((uint8_t) (EBS_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ABS_AlphaPict_GUI_data, (((uint8_t) (ABS_GUI_data))));
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Центральные пиктограммы.
Линия 4
(29 - 30) * / */
                
                    /* Номер элемета */
                    
                    /* 29 */
                    
                    AlphaGradientLimitter250ms(&DoorBrake_AlphaPict_GUI_data, (((uint8_t) (DoorBrake_GUI_data))));
                    
                    /* 30 */
                    
                    AlphaGradientLimitter250ms(&Immobilizer_AlphaPict_GUI_data, (((uint8_t) (Immobilizer_GUI_data))));
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Пиктограммы тахометра и амперметра
(68 - 80) * / */
                
                    /* Номер элемета */
                    
                    /* 68 */
                    
                    AlphaGradientLimitter250ms(&ChargeConnector_AlphaPict_GUI_data, (((uint8_t) (ChargeConnector_GUI_data))));
                    
                    /* 69 */
                    
                    AlphaGradientLimitter250ms(&IsolationError_AlphaPict_GUI_data, (((uint8_t) (IsolationError_GUI_data))));
                    
                    /* 70 */
                    
                    AlphaGradientLimitter250ms(&BrakeCompressorOverheating_AlphaPict_GUI_data, (((uint8_t) (BrakeCompressorOverheating_GUI_data))));
                    
                    /* 71 */
                    
                    AlphaGradientLimitter250ms(&BrakeCompressorError_AlphaPict_GUI_data, (((uint8_t) (BrakeCompressorError_GUI_data))));
                    
                    /* 72 */
                    
                    AlphaGradientLimitter250ms(&AirFilterClogged_AlphaPict_GUI_data, (((uint8_t) (AirFilterClogged_GUI_data))));
                    
                    /* 73 */
                    
                    AlphaGradientLimitter250ms(&MotorError_AlphaPict_GUI_data, (((uint8_t) (MotorError_GUI_data))));
                    
                    /* 74 */
                    
                    AlphaGradientLimitter250ms(&BatteryHVTempSystem_AlphaPict_GUI_data, (((uint8_t) (BatteryHVTempSystem_GUI_data))));
                    
                    /* 75 */
                    
                    AlphaGradientLimitter250ms(&BatteryHVCoolantFluid_AlphaPict_GUI_data, (((uint8_t) (BatteryHVCoolantFluid_GUI_data))));
                    
                    /* 76 */
                    
                    AlphaGradientLimitter250ms(&BatteryHVHeating_AlphaPict_GUI_data, (((uint8_t) (BatteryHVHeating_GUI_data))));
                    
                    /* 77 */
                    
                    AlphaGradientLimitter250ms(&BatteryHVConverterOff_AlphaPict_GUI_data, (((uint8_t) (BatteryHVConverterOff_GUI_data))));
                    
                    /* 78 */
                    
                    AlphaGradientLimitter250ms(&BatteryHVConverterOutCurrentHigh_AlphaPict_GUI_data, (((uint8_t) (BatteryHVConverterOutCurrentHigh_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ExhaustSystem_AlphaPict_GUI_data, (((uint8_t) (ExhaustSystem_GUI_data))));
                    
                    /* 79 */
                    
                    AlphaGradientLimitter250ms(&BatteryHVConverterOutVoltageHigh_AlphaPict_GUI_data, (((uint8_t) (BatteryHVConverterOutVoltageHigh_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&DriveFanHydraulicError_AlphaPict_GUI_data, (((uint8_t) (DriveFanHydraulicError_GUI_data))));
                    
                    /* 80 */
                    
                    AlphaGradientLimitter250ms(&BatteryHVConverterOverheating_AlphaPict_GUI_data, (((uint8_t) (BatteryHVConverterOverheating_GUI_data))));
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Центральные пиктограммы.
Линия 5
(31- 42) * / */
                
                    /* Номер элемета */
                    
                    /* 31 */
                    
                    AlphaGradientLimitter250ms(&FlightIndicator_AlphaPict_GUI_data, (((uint8_t) (FlightIndicator_GUI_data))));
                    
                    /* 32 */
                    
                    AlphaGradientLimitter250ms(&SalonLightPer100_AlphaPict_GUI_data, (((uint8_t) (SalonLightPer100_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&SalonLightPer50_AlphaPict_GUI_data, (((uint8_t) (SalonLightPer50_GUI_data))));
                    
                    /* 33 */
                    
                    AlphaGradientLimitter250ms(&DriverLight_AlphaPict_GUI_data, (((uint8_t) (DriverLight_GUI_data))));
                    
                    /* 34 */
                    
                    AlphaGradientLimitter250ms(&ExternalLightError_AlphaPict_GUI_data, (((uint8_t) (ExternalLightError_GUI_data))));
                    
                    /* 35 */
                    
                    AlphaGradientLimitter250ms(&DisabledRequest_AlphaPict_GUI_data, (((uint8_t) (DisabledRequest_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&Ramp_AlphaPict_GUI_data, (((uint8_t) (Ramp_GUI_data))));
                    
                    /* 36 */
                    
                    AlphaGradientLimitter250ms(&Beacon_AlphaPict_GUI_data, (((uint8_t) (Beacon_GUI_data))));
                    
                    /* 37 */
                    
                    AlphaGradientLimitter250ms(&MirrorHeating_AlphaPict_GUI_data, (((uint8_t) (MirrorHeating_GUI_data))));
                    
                    /* 38 */
                    
                    AlphaGradientLimitter250ms(&GlassHeating_AlphaPict_GUI_data, (((uint8_t) (GlassHeating_GUI_data))));
                    
                    /* 39 */
                    
                    AlphaGradientLimitter250ms(&WiperHeating_AlphaPict_GUI_data, (((uint8_t) (WiperHeating_GUI_data))));
                    
                    /* 40 */
                    
                    AlphaGradientLimitter250ms(&WindshieldAuto_AlphaPict_GUI_data, (((uint8_t) (WindshieldAuto_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&WindshieldFitful_AlphaPict_GUI_data, (((uint8_t) (WindshieldFitful_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&WindshieldSpeedOne_AlphaPict_GUI_data, (((uint8_t) (WindshieldSpeedOne_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&WindshieldSpeedTwo_AlphaPict_GUI_data, (((uint8_t) (WindshieldSpeedTwo_GUI_data))));
                    
                    /* 41 */
                    
                    AlphaGradientLimitter250ms(&WasherFluid_AlphaPict_GUI_data, (((uint8_t) (WasherFluid_GUI_data))));
                    
                    /* 42 */
                    
                    AlphaGradientLimitter250ms(&AngleOfRotation_AlphaPict_GUI_data, (((uint8_t) (AngleOfRotation_GUI_data))));
                    
                }
                {
                    /* / * UI and contol\Controller\Плавное изменения прозрачности у пиктограмм\Центральные пиктограммы.
Климат
(43 - 50) * / */
                
                    /* Номер элемета */
                    
                    /* 43 */
                    
                    AlphaGradientLimitter250ms(&ClimateDriverGlassFrontHeating_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverGlassFrontHeating_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverGlassFrontHeatingSpeedOne_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverGlassFrontHeatingSpeedOne_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverGlassFrontHeatingSpeedTwo_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverGlassFrontHeatingSpeedTwo_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverGlassFrontHeatingSpeedThree_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverGlassFrontHeatingSpeedThree_GUI_data))));
                    
                    /* 44 */
                    
                    AlphaGradientLimitter250ms(&ClimateDriverConditioner_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverConditioner_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverConditionerError_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverConditionerError_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverAuto_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverAuto_GUI_data))));
                    
                    /* 45 */
                    
                    AlphaGradientLimitter250ms(&ClimateDriverFanOut_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverFanOut_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverFanIn_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverFanIn_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverAirCircuit_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverAirCircuit_GUI_data))));
                    
                    /* 46 */
                    
                    AlphaGradientLimitter250ms(&ClimateDriverChairHeating_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverChairHeating_GUI_data))));
                    
                    /* 47 */
                    
                    AlphaGradientLimitter250ms(&ClimateDriverHeatingSpeedOne_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverHeatingSpeedOne_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverHeatingSpeedTwo_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverHeatingSpeedTwo_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverHeatingError_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverHeatingError_GUI_data))));
                    
                    /* 48 */
                    
                    AlphaGradientLimitter250ms(&ClimateDriverAirSupplyUp_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverAirSupplyUp_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverAirSupplyDown_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverAirSupplyDown_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverAirSupplyUpAndDown_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverAirSupplyUpAndDown_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateDriverAirSupplyDownAndGlass_AlphaPict_GUI_data, (((uint8_t) (ClimateDriverAirSupplyDownAndGlass_GUI_data))));
                    
                    /* 49 */
                    
                    AlphaGradientLimitter250ms(&ClimateSalonConditioner_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonConditioner_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateSalonConditionerError_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonConditionerError_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateSalonAuto_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonAuto_GUI_data))));
                    
                    /* 50 */
                    
                    AlphaGradientLimitter250ms(&ClimateSalonHeatingSpeedOne_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonHeatingSpeedOne_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateSalonHeatingSpeedTwo_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonHeatingSpeedTwo_GUI_data))));
                    
                    AlphaGradientLimitter250ms(&ClimateSalonHeatingError_AlphaPict_GUI_data, (((uint8_t) (ClimateSalonHeatingError_GUI_data))));
                    
                }
            }
            {
                /* / * UI and contol\Controller\Текст * / */
            
                float_t Direct_Switch_63299BB4;
                int8_t Read_Parameter_B3CE53D4;
                float_t Direct_Switch_FC92F2B6;
                float_t Direct_Switch_EE978AC9;
                float_t Direct_Switch_61E8C35D;
                int32_t Direct_Switch_B3910113;
                int32_t Direct_Switch_EF8643DD;
                int32_t Direct_Switch_324128C5;
                int32_t Direct_Switch_A1558C0F;
                int32_t Direct_Switch_8262B4E2;
                int32_t Direct_Switch_6FBC567C;
                
                if(0U == (TimeOut_FEAE_x1E_data))
                {
                    Direct_Switch_63299BB4 = (((((float_t) (AirPres1_x1E_data)) * 2.0F) / 25.0F));
                }
                else
                {
                    Direct_Switch_63299BB4 = (((((float_t) (AirPres1_x30_data)) * 2.0F) / 25.0F));
                }
                
                Read_Parameter_B3CE53D4 = IgnitionStartPict_GUI_data;
                
                if(0 == Read_Parameter_B3CE53D4)
                {
                    Direct_Switch_FC92F2B6 = Direct_Switch_63299BB4;
                }
                else
                {
                    Direct_Switch_FC92F2B6 = ((float_t) 14.0F);
                }
                
                AirPress1_Text_GUI_data = Direct_Switch_FC92F2B6;
                
                if(0U == (TimeOut_FEAE_x1E_data))
                {
                    Direct_Switch_EE978AC9 = (((((float_t) (AirPres2_x1E_data)) * 2.0F) / 25.0F));
                }
                else
                {
                    Direct_Switch_EE978AC9 = (((((float_t) (AirPres2_x30_data)) * 2.0F) / 25.0F));
                }
                
                if(0 == Read_Parameter_B3CE53D4)
                {
                    Direct_Switch_61E8C35D = Direct_Switch_EE978AC9;
                }
                else
                {
                    Direct_Switch_61E8C35D = ((float_t) 14.0F);
                }
                
                AirPress2_Text_GUI_data = Direct_Switch_61E8C35D;
                
                if(0 == Read_Parameter_B3CE53D4)
                {
                    Direct_Switch_B3910113 = (((SpeedBusTachOrig_xEE_data) / 256));
                }
                else
                {
                    Direct_Switch_B3910113 = ((((int32_t) 30720) / 256));
                }
                
                Speedometer_Text_GUI_data = Direct_Switch_B3910113;
                
                if(0 == Read_Parameter_B3CE53D4)
                {
                    Direct_Switch_EF8643DD = (AmmeterForward_E1_data);
                }
                else
                {
                    Direct_Switch_EF8643DD = ((int32_t) 500);
                }
                
                AmmeterForward_Text_GUI_data = Direct_Switch_EF8643DD;
                
                if(0 == Read_Parameter_B3CE53D4)
                {
                    Direct_Switch_324128C5 = ((int32_t) 0);
                }
                else
                {
                    Direct_Switch_324128C5 = ((int32_t) 100);
                }
                
                ChargeReserve_Text_GUI_data = Direct_Switch_324128C5;
                
                if(0 == Read_Parameter_B3CE53D4)
                {
                    Direct_Switch_A1558C0F = (BatteryHVoltage_FF01_xE1_data);
                }
                else
                {
                    Direct_Switch_A1558C0F = ((int32_t) 8000);
                }
                
                BatteryHV_Text_GUI_data = Direct_Switch_A1558C0F;
                
                if(0 == Read_Parameter_B3CE53D4)
                {
                    Direct_Switch_8262B4E2 = (LVBatteryV_x1E_data);
                }
                else
                {
                    Direct_Switch_8262B4E2 = ((int32_t) 560);
                }
                
                BatteryLV_Text_GUI_data = Direct_Switch_8262B4E2;
                
                if(0 == Read_Parameter_B3CE53D4)
                {
                    Direct_Switch_6FBC567C = (MileageReserve_xE1_data);
                }
                else
                {
                    Direct_Switch_6FBC567C = ((int32_t) 250);
                }
                
                MileageReserve_Text_GUI_data = Direct_Switch_6FBC567C;
                
            }
            {
                /* / * UI and contol\Controller\Состояние дверей на центральном автобусе * / */
            
                /* Номер двери */
                
                /* 1-1 */
                
                BusDoorOpen(&DoorIndex_1_1_GUI_data, &DoorIndexHelp_1_1_GUI_data, (((int32_t) (DoorOpening1_1_GUI_data))), (((int32_t) (DoorOpen1_1_GUI_data))), (((int32_t) (DoorError1_1_GUI_data))), (((int32_t) (DoorJam1_1_GUI_data))), (((int32_t) (DoorUnauthorized_1_1_GUI_data))), (((double_t) (DoorRequest_1_1_GUI_data))));
                
                /* 1-2 */
                
                BusDoorOpen(&DoorIndex_1_2_GUI_data, &DoorIndexHelp_1_2_GUI_data, (((int32_t) (DoorOpening1_2_GUI_data))), (((int32_t) (DoorOpen1_2_GUI_data))), (((int32_t) (DoorError1_2_GUI_data))), (((int32_t) (DoorJam1_2_GUI_data))), (((int32_t) (DoorUnauthorized_1_2_GUI_data))), (((double_t) (DoorRequest_1_2_GUI_data))));
                
                /* 2 */
                
                BusDoorOpen(&DoorIndex_2_GUI_data, &DoorIndexHelp_2_GUI_data, (((int32_t) (DoorOpening2_GUI_data))), (((int32_t) (DoorOpen2_GUI_data))), (((int32_t) (DoorError2_GUI_data))), (((int32_t) (DoorJam2_GUI_data))), (((int32_t) (DoorUnauthorized_2_GUI_data))), (((double_t) (DoorRequest_2_GUI_data))));
                
                /* 3 */
                
                BusDoorOpen(&DoorIndex_3_GUI_data, &DoorIndexHelp_3_GUI_data, (((int32_t) (DoorOpening3_GUI_data))), (((int32_t) (DoorOpen3_GUI_data))), (((int32_t) (DoorError3_GUI_data))), (((int32_t) (DoorJam3_GUI_data))), (((int32_t) (DoorUnauthorized_3_GUI_data))), (((double_t) (DoorRequest_3_GUI_data))));
                
            }
        }
        {
            /* / * UI and contol\Draw * / */
        
            /* Фон */
            
            /* Пиктограммы */
            
            /* Сегменты, стрелки
            и текст */
            
            /* Рендер */
            
        }
    }

    {
        /* / * Virtual CAN bus * / */
    
        double_t Call_Once_3693EDA6;
        
        Call_Once_3693EDA6 = 0;
        
    }

}

/* Definitions of local (private) functions ----------------------------------*/

/* End of file ---------------------------------------------------------------*/

