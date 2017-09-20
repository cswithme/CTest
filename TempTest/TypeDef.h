/*
 * TypeDef.h
 *
 *  Created on: 2017-9-20
 *      Author: root
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

#pragma pack(push,1)
typedef struct _ST_GS_TPU_YPT_CVT_UDDATA_ {
	unsigned char ucRundate[4]; //运营日期	Date	4
	unsigned char ucTranType; //交易类型	参见“4.14 交易类型”	Byte	1
	unsigned char ucProductMainType; //车票主类型	参见“4.10 车票主类型”	Byte	1
	unsigned char ucProductType; //车票类型	参见“4.11 车票类型”	Byte	1
	unsigned char ucCardType; //票卡芯片类型	参见“4.16 票卡芯片类型”	Byte	1
	unsigned char ucCardLogicalNo[8]; //票卡逻辑号	BCD	10
	unsigned char ucCardPHNo[8]; //票卡CSN	票卡物理号,不足后补0x00	Block	8
	unsigned short usCardCount; //票计数器	Word	2
	unsigned char ucOperCode[10]; //操作员编号	仅用于BOM		Char	10
	unsigned long ulShiftInfo; //班次信息	仅用于BOM		Long	4
	unsigned char ucPSamDev[6]; //PSAM设备号	BCD	6
	unsigned char ucPSamNo[8]; //PSAM卡号	BCD	8
	unsigned long ulPSamUdSeq; //PSAM卡流水号	无PSAM卡流水号时为0	Long	4
	unsigned char ucTranDateTime[7]; //交易日期时间	Timestamp	7
	unsigned char ucPaymentCode; //支付方式	参见“4.17 支付方式”	Byte	1
	unsigned long ulBeforeValue; //卡交易金额/次数	交易时卡内余额/余次方式变化的值	Long	4
	unsigned long ulTranValue; //现金交易金额	充值或售票时，乘客实际支付的金额	Long	4
	unsigned long ulAfterValue; //交易后卡内余额/余次	交易后卡内的余额/余次	Long	4
	unsigned long ulDeposit; //押金	Long	4
	unsigned long ulFee; //手续费	Long	4
	unsigned short usDiscountValue; //优惠金额	全价票额与实际交易额的差值	Word	2
	unsigned char ucCurrStation[4]; //当前车站	节点编码	BCD	4
	unsigned char ucLastStation[4]; //上次使用车站	节点编码，交易代码为出站交易时，该字段填出站车站节点编码	BCD	4
	unsigned char ucLastDateTime[7];//上次使用时间	交易代码为出站交易时，该字段填出站时间	Timestamp	7
	unsigned char ucDeviceCode[4]; //终端设备标识	节点编码	BCD	4
	unsigned long ulSleSeq; //终端设备流水号	Long	4
	unsigned char ucPurseStartDate[4]; //	钱包起始日期	仅充值交易使用，表明周期票充值交易归属的周期开始日期，
	//	例如：为月票2010年7月充值为20100701。	其它交易填全0	Date	4
	unsigned char ucTestFlag; //测试交易标志	0x00-正常交易	0x01-测试交易	Byte	1
	unsigned char ucCityCode[2]; //城市代码 BCD 2
	unsigned char ucTAC[4]; //TAC	Block	4
	unsigned char ucReversed[8]; //[保留]	Block	8
} ST_GS_TPU_YPT_CVT_UDDATA;
#pragma pack(pop)
#endif /* TYPEDEF_H_ */
