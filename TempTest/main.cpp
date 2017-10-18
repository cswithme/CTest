#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "TypeDef.h"

/*egit*/
#pragma pack(push,1)
typedef struct _ST_GS_TPU_YPT_SJT_UDDATA_ {
	unsigned char ucRundate[4]; //运营日期	Date	4
	unsigned char ucTranType; //交易类型	参见“4.14 交易类型”	Byte	1
	unsigned char ucProductMainType; //车票主类型	参见“4.10 车票主类型”	Byte	1
	unsigned char ucProductType; //车票类型	参见“4.11 车票类型”	Byte	1
	unsigned char ucCardType; //票卡芯片类型	参见“4.16 票卡芯片类型”	Byte	1
	unsigned char ucCardLogicalNo[8]; //票卡逻辑号	BCD	10，实际数据返回8字节
	unsigned char ucCardPHNo[8]; //票卡CSN	票卡物理号,不足后补0x00	Block	8
	unsigned short usCardCount; //票计数器	Word	2
	unsigned char ucOperCode[10]; //操作员编号	仅用于BOM		Char	10
	unsigned long ulShiftInfo; //班次信息	仅用于BOM		Long	4
	unsigned char ucPSamNo[8]; //PSAM卡号	BCD	8
	unsigned long ulPSamUdSeq; //PSAM卡流水号	无PSAM卡流水号时为0	Long	4
	unsigned char ucTranDateTime[7]; //交易日期时间	Timestamp	7
	unsigned char ucPaymentCode; //支付方式	参见“4.17 支付方式”	Byte	1
	unsigned long ulBeforeValue; //交易前票值	可为负值	计次票为次数	Long	4
	unsigned long ulTranTimes; //交易次数	非计次票为0	Long	4
	unsigned long ulTranValue; //交易金额	非计值票为0	Long	4
	unsigned short usDiscountValue; //优惠金额	全价票额与实际交易额的差值	Word	2
	unsigned char ucCurrStation[4]; //当前车站	节点编码	BCD	4
	unsigned char ucLastStation[4]; //上次使用车站	节点编码，交易代码为出站交易时，该字段填出站车站节点编码	BCD	4
	unsigned char ucLastDateTime[7];//上次使用时间	交易代码为出站交易时，该字段填出站时间	Timestamp	7
	unsigned char ucDeviceCode[4]; //终端设备标识	节点编码	BCD	4
	unsigned long ulSleSeq; //终端设备流水号	Long	4
	unsigned char ucTestFlag; //测试交易标志	0x00-正常交易	0x01-测试交易	Byte	1
	unsigned char ucTAC[4]; //TAC	Block	4
	unsigned char ucReversed[8]; //[保留]	Block	8
} ST_GS_TPU_YPT_SJT_UDDATA;
#pragma pack(pop)

int main()
{
	puts("Test Begin!");

	unsigned char szTemp[]= {0x20, 0x17, 0x10, 0x17, 0x08, 0x07, 0x71, 0x02, 0x07, 0x17, 0x07, 0x18, 0x01, 0x01, 0x40, 0x18, 0xB3, 0x2E, 0xE3, 0x44, 0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x05, 0x32, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 0x05, 0x00, 0x00, 0x00, 0x20, 0x17, 0x10, 0x17, 0x15, 0x48, 0x47, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x39, 0x00, 0x00, 0x02, 0x39, 0x20, 0x17, 0x10, 0x17, 0x15, 0x48, 0x47, 0x02, 0x39, 0x06, 0x02, 0xD5, 0x0F, 0x00, 0x00, 0x20, 0x17, 0x07, 0x18, 0x05, 0x32, 0x00, 0x60, 0xA4, 0x84, 0x8B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	printf("sizeof ST_GS_TPU_YPT_SJT_UDDATA[%u]\n",sizeof(ST_GS_TPU_YPT_SJT_UDDATA));
	printf("sizeof szTemp[%u]\n",sizeof(szTemp));

	ST_GS_TPU_YPT_SJT_UDDATA *pstUd = (ST_GS_TPU_YPT_SJT_UDDATA *)szTemp;
	printf("ulTranValue[%lu]\n,ulBeforeValue[%lu]",pstUd->ulTranValue, pstUd->ulBeforeValue);



//	unsigned char ucTemp[200] ={0X20, 0X17, 0X09, 0X20, 0X08, 0X07, 0X71, 0X02, 0X07, 0X17, 0X07, 0X18, 0X01, 0X01, 0X40, 0X18, 0XB3, 0X2E, 0XE3, 0X44, 0000, 0000, 0000, 0000, 0X30, 0000, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0X30, 0000, 0000, 0000, 0000, 0X05, 0X32, 0000, 0000, 0000, 0X18, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0X19, 0X1A, 0000, 0000, 0000, 0X20, 0X17, 0X09, 0X20, 0X15, 0X18, 0X04, 0X02, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0XB8, 0X0B, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0X02, 0X31, 0000, 0000, 0X02, 0X31, 0X20, 0X17, 0X09, 0X20, 0X15, 0X18, 0X04, 0X02, 0X31, 0X06, 0X01, 0XE2, 0X11, 0000, 0000, 0X20, 0X17, 0X07, 0X18, 0X05, 0X32, 0000, 0X8B, 0X86, 0XAA, 0XAB, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000};
//	ST_GS_TPU_YPT_CVT_UDDATA *pstUdData = (ST_GS_TPU_YPT_CVT_UDDATA *)ucTemp;
//
//	printf("sizeof ST_GS_TPU_YPT_CVT_UDDATA is %u\n",sizeof(ST_GS_TPU_YPT_CVT_UDDATA));
	puts("Test end!");
	return 0;

}

void func()
{

}


