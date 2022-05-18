#include <stdio.h>
#include <inttypes.h>
#include  "Code/model.h"
#include  "Code/dd_ref.h"
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int32_t API_Autogramma_CAN_Send(void* param0, uint32_t argIn0) { return 0; }
int64_t API_GetCurrentTime_ms(void) { return 0; }

uint32_t total = 3; //  оличество CAN сообщений

/*typedef enum описание типа переменных
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
} dd_type_storage;
*/

typedef struct can_multi {
	uint32_t id;
	uint16_t nbr_packets;
	uint16_t nbr_byte;
	uint32_t dm;
	struct array_lamp* array_lamp_status;
	struct can_param_multi* array_param_multi;
}can_multi_t;

struct array_lamp {
	uint8_t ProtectLampStatus;
	uint8_t AmberWarningLampStatus;
	uint8_t couRedStopLampStatent;
	uint8_t MalfunctionIndicatorLampStatus;
	uint8_t FlashProtectLamp;
	uint8_t FlashAmberWarningLamp;
	uint8_t FlashRedStopLamp;
	uint8_t FlashMalfuncIndicatorLamp;
};

struct can_param_multi {
	uint32_t spn;
	uint16_t fmi;
	uint16_t count;
};


struct can_param_multi array_param_mes1[] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
};

struct array_lamp array_lamp_mes1[] = {
		{0,0,0,0,0,0,0,0}
};

struct can_multi multi_1 =
{
	.id = 0x18FECAFF,
	.nbr_packets = 0,
	.nbr_byte = 0,
	.dm = 0,
	.array_lamp_status = array_lamp_mes1,
	.array_param_multi = array_param_mes1
};




struct can_param {
	uint8_t start_byte; 
	uint8_t start_bit;
	uint8_t bit_lenght;
	uint8_t type;
	uint8_t value_type;  // 0 - unsigned 1 - signed
	uint32_t adress;
	uint8_t dd_type;
	void *param;
};

typedef struct can_message {
	uint32_t id;
	uint32_t mes_in;
	uint32_t   mes_out;
	uint16_t cycle_time;
	uint16_t timeout_def;
	uint8_t def_value;
	uint16_t num_param;
	struct can_param* array_param;
//	size_t array_size;
}can_message_t;

struct can_param array_AIR1[] =
{
		{0,0,8,0,0,0,T_U16,&AirPres1_x1E_data},
		{1,24,8,0,0,0,T_U16,&AirPres2_x1E_data},
		{2,8,8,0,0,0,T_U16,&AirPres3_x1E_data}
};
struct can_param array_AIR1_id30[] =
{
		{0,0,8,0,0,0,0,&AirPres1_x30_data},
		{1,24,8,0,0,0,0,&AirPres2_x30_data},
		{2,8,8,0,0,0,0,&AirPres3_x30_data}
};
struct can_param array_AIR2[] =
{
		{0,0,16,0,0,0,T_U16,&AirPres1_xFE_data},
		{0,16,2,0,0,0,T_U8,&AirPres2_xFE_data},
		{0,18,6,0,0,0,T_U8,&Kneeling_SPN1736_x2F_data},
		{0,24,2,0,0,0,T_U8,&Kneeling_SPN1740_x2F_data},
		{0,26,2,0,0,0,T_U8,&Kneeling_SPN1733_x2F_data},
		{0,28,2,0,0,0,T_U8,&Kneeling_SPN1737_x2F_data},
		{0,30,2,0,0,0,T_U8,&Kneeling_SPN1754_x2F_data},
		{0,32,20,0,0,0,T_U32,&Kneeling_SPN1734_x2F_data}
};

struct can_message AIR1_id30 =
{
	.id = 0x18FEAE30,
	.mes_in = 0,
	.mes_out = 0,
	.cycle_time = 100,
	.timeout_def = 400,
	.def_value = 0,
	.num_param = 3,
	.array_param = array_AIR1_id30,
//	.array_size = ARRAY_SIZE(array_AIR1_id30)
};

struct can_message AIR1 =
{
	.id = 0x18FEAE1E,
	.mes_in = 0,
	.mes_out = 0,
	.cycle_time = 100,
	.timeout_def = 400,
	.def_value = 0,
	.num_param = 3,
	.array_param = array_AIR1,
//	.array_size = ARRAY_SIZE(array_AIR1)
};

struct can_message AIR2 =
{
	.id = 0x18FEAEFE,
	.mes_in = 0,
	.mes_out = 0,
	.cycle_time = 100,
	.timeout_def = 400,
	.def_value = 0,
	.num_param = 8,
	.array_param = array_AIR2,
//	.array_size = ARRAY_SIZE(array_AIR2)
};

typedef struct array_message
{
	struct can_message* can_message;

}array_message_t;

struct array_message array_message_total[] =
{
	&AIR1_id30,	&AIR1,	&AIR2
};

typedef struct can_message_tx
{
	uint32_t id;
	uint8_t can_buff_tx[8];
	uint8_t dlc;
}can_message_tx;

can_message_tx write_can_tx = { 0,{0,0,0,0,0,0,0,0},0 };

uint8_t total_buff[1000];
uint8_t test;

void Read_multi_to_array(uint8_t buff[], uint8_t count)
{
	if (count == 0)
	{
		multi_1.nbr_byte = (buff[2] << 8) | (buff[1]);
		multi_1.nbr_packets = buff[3];
		multi_1.dm = (buff[6] << 16) | (buff[5] << 8) | (buff[7]);
	}
	else
	{
		for (int i = 0; i < 7; i++)
		{

			test = i + 7 * ((int)buff[0] - 1);
			total_buff[i + 7 * ((int)buff[0] - 1)] = buff[i + 1];
		}
	}
	/*
	else if (count == 1)
	{


		multi_1.array_param_multi[0].spn = (buff[3]<<11) | (buff[4]<<3) | (buff[5]>>5);
		multi_1.array_param_multi[0].fmi = buff[5] & 0x1F;
		multi_1.array_param_multi[0].count = buff[6];
	//	printf("%X \n", multi_1.array_param_multi[0].spn);
	}
	else
	{
		multi_1.array_param_multi[count - 1].spn = buff[count];
	}
	*/


}

void Parse_array_multi()
{
	multi_1.array_lamp_status->ProtectLampStatus = total_buff[0] & 0x3;
	multi_1.array_lamp_status->AmberWarningLampStatus = (total_buff[0] >> 2) & 0x3;
	multi_1.array_lamp_status->couRedStopLampStatent = (total_buff[0] >> 4) & 0x3;
	multi_1.array_lamp_status->MalfunctionIndicatorLampStatus = (total_buff[0] >> 6) & 0x3;
	multi_1.array_lamp_status->FlashProtectLamp = total_buff[1] & 0x3;
	multi_1.array_lamp_status->FlashAmberWarningLamp = (total_buff[1] >> 2) & 0x3;
	multi_1.array_lamp_status->FlashRedStopLamp = (total_buff[1] >> 4) & 0x3;
	multi_1.array_lamp_status->FlashMalfuncIndicatorLamp = (total_buff[1] >> 6) & 0x3;

	for (int i = 0; i < ((int) (multi_1.nbr_byte - 2) )/4 ; i++)
	{
		multi_1.array_param_multi[i].spn = (total_buff[2+i*4] << 11) | (total_buff[3+i*4] << 3) | (total_buff[4+i*4] >> 5);
		multi_1.array_param_multi[i].fmi = total_buff[4+i*4] & 0x1F;
		multi_1.array_param_multi[i].count = total_buff[5+i*4];
		printf("%X ", multi_1.array_param_multi[i].spn);
		printf("%X ", multi_1.array_param_multi[i].fmi);
		printf("%X ", multi_1.array_param_multi[i].count);
	}
	printf("\n");

}
void J1939_Parser(can_message_t* can_rx, uint8_t can_rx_buf[])
{
	uint64_t value_res = 0; // результат значени€ из буфера
	for (int i = 0; i < can_rx->num_param; i++) // цикл прохода по параметрам CAN сообщени€ 
	{
		value_res = J1939_ReadValue(can_rx_buf, can_rx->array_param[i].start_bit, can_rx->array_param[i].bit_lenght); // считываем занчаение из буфера 

		switch (can_rx->array_param[i].dd_type) // выбор типа переменной дл€ релультата  
		{
		case T_U8:
		{
			*((uint8_t*)can_rx->array_param[i].param) = value_res;
			break;
		}
		case T_S8:
		{
			*((int8_t*)can_rx->array_param[i].param) = value_res;
			break;
		}
		case T_U16:
		{
			*((uint16_t*)can_rx->array_param[i].param) = value_res;
			break;
		}
		case T_S16:
		{
			*((int16_t*)can_rx->array_param[i].param) = value_res;
			break;
		}
		case T_U32:
		{
			*((uint32_t*)can_rx->array_param[i].param) = value_res;
			break;
		}
		case T_S32:
		{
			*((int32_t*)can_rx->array_param[i].param) = value_res;
			break;
		}
		case T_U64:
		{
			*((uint64_t*)can_rx->array_param[i].param) = value_res;
			break;
		}
		case T_S64:
		{
			*((int64_t*)can_rx->array_param[i].param) = value_res;
			break;
		}
		}
	}
}

int J1939_ReadValue(uint8_t buff[], uint8_t sb, uint8_t len)
{
	uint8_t start_byte = sb / 8;    // высчитывание стартового байта
	uint8_t start_bit = sb % 8;     // высчитываение стартового бита 
	uint64_t result = 0;            // результат считывани€ 
	uint8_t ctrl = 0;               // выбор 
	ctrl = (start_bit + len) % 8;   // подсчет 
	if (ctrl == 0)
	{
		ctrl = (start_bit + len) / 8;
	}
	else
	{
		ctrl = ((start_bit + len) / 8) + 1;
	}

	for (int i = 0; i < ctrl; i++)
	{
		if (i == 0)
		{
			result = result | (buff[start_byte] >> start_bit);
		}
		else
		{
			result = result | ((uint64_t)(buff[i + start_byte]) << (i * 8 - start_bit));
		}
	}
	result = result & (((uint64_t)1 << len) - 1);
	return result;
}


uint64_t J1939_WriteValue(const can_message_t* can_tx, uint8_t num_param)
{
	uint64_t var = 0; //*((uint8_t*)can_tx->array_param[num_param].param);
	uint16_t sb = can_tx->array_param[num_param].start_bit;
	uint32_t len = can_tx->array_param[num_param].bit_lenght;
	//sb = 0; len = 16; var = 0x1234;
	uint8_t start_byte = sb / 8;
	uint8_t start_bit = sb % 8;
	uint8_t offset_bit = 8 - (sb % 8);
	uint8_t num_byte = len / 8 + (len % 8 == 0 ? 0 : 1);
	uint8_t index = 0;
	uint64_t result = 0;
	//	uint8_t ctrl = 0;
	//	enum Type_param type_metric;
	//	ctrl = (start_bit + len) % 8; 
	uint64_t invert_value = 0;
	uint64_t mask = 0;

	switch (can_tx->array_param[num_param].dd_type)
	{
	case T_S8:
	{
		var = *((int8_t*)can_tx->array_param[num_param].param);
		break;
	}
	case T_U8:
	{
		var = *((uint8_t*)can_tx->array_param[num_param].param);
		break;
	}
	case T_S16:
	{
		var = *((int16_t*)can_tx->array_param[num_param].param);

		break;
	}
	case T_U16:
	{
		var = *((uint16_t*)can_tx->array_param[num_param].param);
		break;
	}
	case T_S32:
	{
		var = *((int32_t*)can_tx->array_param[num_param].param);

		break;
	}
	case T_U32:
	{
		var = *((uint32_t*)can_tx->array_param[num_param].param);
		break;
	}
	case T_S64:
	{
		var = *((int64_t*)can_tx->array_param[num_param].param);

		break;
	}
	case T_U64:
	{
		var = *((uint64_t*)can_tx->array_param[num_param].param);
		break;
	}


	default:
		break;
	}


	for (int i = 0; i < len; i++)
	{
		mask = mask | ((uint64_t)1 << i);
	}
	var = var & mask;

	
/*	//* дл€ 64 	
	invert_value = invert_value | (uint64_t)((var & ((uint64_t)0xFF << 0)) << 56);
	invert_value = invert_value | (uint64_t)((var & ((uint64_t)0xFF << 8))  << 40);
	invert_value = invert_value | (uint64_t)((var & ((uint64_t)0xFF << 16)) << 24);
	invert_value = invert_value | (uint64_t)((var & ((uint64_t)0xFF << 24)) << 8);
	invert_value = invert_value | (uint64_t)((var & ((uint64_t)0xFF << 32)) >> 8);
	invert_value = invert_value | (uint64_t)((var & ((uint64_t)0xFF << 40)) >> 24);
	invert_value = invert_value | (uint64_t)((var & ((uint64_t)0xFF << 48)) >> 40);
	invert_value = invert_value | (uint64_t)((var & ((uint64_t)0xFF << 56)) >> 56);

	ƒл€ 32 бит
	invert_value = invert_value | (var & (0xFF << 0)) << 24;
	invert_value = invert_value | (var & (0xFF << 24)) >> 24;
	invert_value = invert_value | (var & (0xFF << 8)) << 8;
	invert_value = invert_value | (var & (0xFF << 16)) >> 8;
*/
	


	for (int i = 0; i < 4; i++)
	{
		invert_value = invert_value | (var & ((uint64_t)0xFF << 24 - (i*8))) << ((i*16)+8);
		invert_value = invert_value | (var & ((uint64_t)0xFF << 32 + (i*8))) >> ((i*16)+8);
	}
	invert_value = invert_value >> (8*(8-num_byte));
	uint32_t invert_value_Lsb = invert_value;
	uint32_t invert_value_Msb = invert_value >> 32;
	printf("%X %X \n", (int)invert_value_Msb, (int)invert_value_Lsb);
	return invert_value;
}

void J1939_Write(array_message_t *array_mes_can, uint64_t id_can)
{
	uint64_t res = 0;
	uint64_t mask = 0;
	for (int i = 0; i < total; i++)
	{
		if (id_can == array_mes_can->can_message[i].id )
		{
			write_can_tx.id = array_mes_can->can_message[i].id;
			for (int j = 0; j < array_mes_can->can_message[i].num_param; j++)
			{
				mask = 0;
				for (int g = 0; g < array_mes_can->can_message[i].array_param[j].bit_lenght+ array_mes_can->can_message[i].array_param[j].start_bit ; g++)
				{
					mask = mask | ((uint64_t)1 << g);
				}
				res = res | (((J1939_WriteValue(&array_mes_can->can_message[i], j)) << array_mes_can->can_message[i].array_param[j].start_bit) & mask);	
			}	 
		}
	}
	uint32_t invert_value_Lsb = res;
	uint32_t invert_value_Msb = res >> 32;
	for (int i =7; i>=0;i-- )
	{
		write_can_tx.can_buff_tx[i] = res >> i*8;
		write_can_tx.dlc = 8;
		printf("%X ", (int)write_can_tx.can_buff_tx[i]);
	}
	printf("\n");
	printf("%X %X \n", (int)invert_value_Msb, (int)invert_value_Lsb);
}


void main()
{	
	
	uint8_t buff_rx[8] = { 0x39,0x30,0x11,0x22,0x33,0x44,0x55,0x66 };

	uint8_t buff_multi[][8] = { {0x20,0x0A,0x00,0x02,0xFF,0xCA,0xFE,0x00},
								{0x01,0x11,0xFF,0x61,0x00,0x03,0x01,0x7f},
								{0x02,0x02,0x09,0x02,0xFF,0xFF,0xFF,0xFF}};


	
	
	for (int i=0; i < (int) buff_multi[0][3]+1; i++)
	{
		Read_multi_to_array(buff_multi[i],i);

	}

	for (int i = 0; i < 60; i++)
	{
		printf("%X ", total_buff[i]);
	}

	Parse_array_multi();
	uint8_t buff_tx[8]; 
/*	J1939_Parser(&AIR1_id30, buff_rx); // „тение буфера и запись в указанную структуру 
	printf("%X :: %d\n", (int)AirPres1_x30_data, (int)AirPres1_x30_data);
	printf("%X :: %d\n", (int)AirPres2_x30_data, (int)AirPres2_x30_data);
	printf("%X :: %d\n", (int)AirPres3_x30_data, (int)AirPres3_x30_data);


	J1939_Write(array_message_total, 0x18FEAEFE); // «апись в буфер CAN сообщени€ с указанным id
	*/
	return  0;
}

/**********************************************************************************************************/