/*
 * TypeDef.h
 *
 *  Created on: 2017-9-20
 *      Author: root
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

#include <stdint.h>

enum struct IobCzGateErrorCode : uint8_t
{
	success = 0,			//成功
	initFail = 2,			//设备连接初始化失败
	commandFail = 3,		//设备命令执行失败
	invalidParam = 4,		//设备命令参数非法
	notInitialized = 5,		//设备尚未初始化
};

enum class ES_COLOR
{
	red = 1,
	blue = 2,
	green = 3,
};

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

typedef struct _ST_HM_ABNORMAL_AND_STATUS_INFO_
{
	//D0
	unsigned char bitIsResetSend :1;							//0——非复位完成后发送,1——复位完成后发送
	unsigned char bitElectricMachineryFault:1;					//1——电机升降故障（不可恢复）
	unsigned char bitTicketTravelingFault:1;					//1——走票故障（不可恢复）
	unsigned char bitElectromagnetFault:1;						//1——电磁铁到位异常（不可恢复）
	unsigned char bitRadioSensorFault:1;						//1——对射传感器故障（可恢复）
	unsigned char bitInvalidTicketBoxFault:1;					//1——废票箱异常（可恢复）
	unsigned char bitTicketBoxReadyAbnormal :1;					//1——发票箱就绪异常（可恢复）
	unsigned char bitDeviceStatus :1;							//0——设备无故障,1——设备故障

	//D1
	unsigned char bitTicketBox1LiftInPlace :1;					//1——票箱1升降到位
	unsigned char bitTicketBox1ReadId :1;						//1——票箱1电子ID读到
	unsigned char bitTicketBox1CoverPlateInPlace :1;			//1——票箱1盖板到位
	unsigned char bitTicketBox1AvailableSale :1;				//1——票箱1可发票
	unsigned char bitTicketBox2LiftInPlace :1;					//1——票箱2升降到位
	unsigned char bitTicketBox2ReadId :1;						//1——票箱2电子ID读到
	unsigned char bitTicketBox2CoverPlateInPlace :1;			//1——票箱2盖板到位
	unsigned char bitTicketBox2AvailableSale :1;				//1——票箱2可发票

	//D2
	unsigned char bitReserved1 :1;								//预留
	unsigned char bitElectricMachineryEnableBit :1;				//1——电机使能位
	unsigned char bitSaleTicketEnableBit :1;					//1——发票使能位
	unsigned char bitTemporaryHaveTicket :1;					//1——暂存有票
	unsigned char bitReadCardAreaHaveTicket :1;					//1——读卡区有票
	unsigned char bitTicketBox1IsWorkBox :1;					//1——票箱1为工作票箱
	unsigned char bitTicketBox2IsWorkBox :1;					//1——票箱2为工作票箱
	unsigned char bitCompleteMachineNoPlace :1;					//1——整个机构不到位,0——整个机构到位

	//D3
	unsigned char bitTicketBox1OpenUpperCover :1;				//1——票箱1盖板打开
	unsigned char bitTicketBox1UpperLimitSensorHaveSignal :1;	//1——票箱1上限传感器有信号
	unsigned char bitTicketBox1MicroSwitchHaveSignal :1;		//1——票箱1微动开关有信号
	unsigned char bitTicketBox1EndSensorHaveSignal :1;			//1——票箱1将完传感器有信号
	unsigned char bitTicketBox1CountSensorHaveSignal :1;		//1——票箱1计数传感器有信号
	unsigned char bitTicketBox1LowerLimitSensorHaveSignal :1;	//1——票箱1下限传感器有信号
	unsigned char bitTicketBox1ToggleSwitchPosition :1;			//1——票箱1拨动开关在下位,0——票箱1拨动开关在上位
	unsigned char bitReserved2 :1;								//预留

	//D4
	unsigned char ucTicketBox1ElectromagnetSwitchCount;			//票箱1计数磁性开关计数值

	//D5
	unsigned char bitTicketBox2OpenUpperCover :1;				//1——票箱2盖板打开
	unsigned char bitTicketBox2UpperLimitSensorHaveSignal :1;	//1——票箱2上限传感器有信号
	unsigned char bitTicketBox2MicroSwitchHaveSignal :1;		//1——票箱2微动开关有信号
	unsigned char bitTicketBox2EndSensorHaveSignal :1;			//1——票箱2将完传感器有信号
	unsigned char bitTicketBox2CountSensorHaveSignal :1;		//1——票箱2计数传感器有信号
	unsigned char bitTicketBox2LowerLimitSensorHaveSignal :1;	//1——票箱2下限传感器有信号
	unsigned char bitTicketBox2ToggleSwitchPosition :1;			//1——票箱2拨动开关在下位,0——票箱1拨动开关在上位
	unsigned char bitReserved3 :1;								//预留

	//D6
	unsigned char ucTicketBox2ElectromagnetSwitchCount;			//票箱2计数磁性开关计数值

	//D7
	unsigned char bitReserved4 :1;								//预留
	unsigned char bitInvalidTicketBoxReadId :1;					//1——废票箱电子ID读到
	unsigned char bitInvalidTicketBoxCoverPlateInPlace :1;		//1——废票箱盖板到位
	unsigned char bitInvalidTicketBoxNotFull :1;				//1——废票箱未满
	unsigned char bitReserved5 :1;								//预留
	unsigned char bitReserved6 :1;								//预留
	unsigned char bitTurningPlateElectromagneticInPlace :1;		//1——废票翻板电磁铁到位
	unsigned char bitReserved7 :1;								//预留

	//D8
	unsigned char bitINFS1 :1;								//1——1号INFS遮挡
	unsigned char bitINFS2 :1;								//1——2号INFS遮挡
	unsigned char bitINFS3 :1;								//1——3号INFS遮挡
	unsigned char bitINFS4 :1;								//1——4号INFS遮挡
	unsigned char bitINFS5 :1;								//1——5号INFS遮挡
	unsigned char bitINFS6 :1;								//1——6号INFS遮挡
	unsigned char bitTicketBox1IsEmpty :1;					//1——票箱1空,0——票箱1不空或未就绪而无法判断
	unsigned char bitTicketBox2IsEmpty :1;					//1——票箱2空,0——票箱1不空或未就绪而无法判断

	//D9
	unsigned char bitTicketBox1ScratchTicketFault :1;		//1——票箱1刮票故障
	unsigned char bitTicketBox2ScratchTicketFault :1;		//1——票箱2刮票故障
	unsigned char bitTemporaryStorageAreaOnTicketFault :1;		//1——暂存区上票故障
	unsigned char bitReadCardAreaOnTicketFault :1;			//1——读卡区上票故障
	unsigned char bitReadCardAreaOutTicketFault :1;			//1——读卡区出票故障
	unsigned char bitReadCardAreaRefundTicketFault :1;		//1——读卡区退票故障
	unsigned char bitReserved8 :1;								//预留
	unsigned char bitReserved9 :1;								//预留

	//D10	走票故障位置代码
	unsigned char ucTicketTravelingFaultCode;				//走票故障位置代码

	//D11
	unsigned char bitTicketBox1ElectricMachineryDropFault :1;		//1——票箱1电机下降故障
	unsigned char bitTicketBox1ElectricMachineryRiseFault :1;		//1——票箱1电机上升故障
	unsigned char bitTicketBox2ElectricMachineryDropFault :1;		//1——票箱2电机下降故障
	unsigned char bitTicketBox2ElectricMachineryRiseFault :1;		//1——票箱2电机上升故障
	unsigned char bitReserved10 :1;								//预留
	unsigned char bitReserved11 :1;								//预留
	unsigned char bitReserved12 :1;								//预留
	unsigned char bitReserved13 :1;								//预留

}ST_HM_ABNORMAL_AND_STATUS_INFO;
#endif /* TYPEDEF_H_ */
