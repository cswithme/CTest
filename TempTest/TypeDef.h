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

typedef enum
{
	EM_TICKET_TRANS_RESULT_OK = 0,		//OK,预读OK,有效性检查OK
	EM_TICKET_TRANS_RESULT_EXPIRED = 1,		//车票过期
	EM_TICKET_TRANS_RESULT_OUTSIDE = 2,		//区段外车票
	EM_TICKET_TRANS_RESULT_INSUFFICIENT_BALANCE = 3,		//余额/余次不足
	EM_TICKET_TRANS_RESULT_OVERTIME = 4,		//超过滞留时间
	EM_TICKET_TRANS_RESULT_DATA_ERROR = 5,		//车票数据无效
	EM_TICKET_TRANS_RESULT_BKACKLIST = 6,		//黑名单车票
	EM_TICKET_TRANS_RESULT_RW_FAILTRUE = 7,		//车票读写失败
	EM_TICKET_TRANS_RESULT_TYPE_INVALID = 8,		//车票类型不能进行当前业务
	EM_TICKET_TRANS_RESULT_MULTI_TICKETS = 9,		//多张车票
	EM_TICKET_TRANS_RESULT_PLEASE_INPUT_CARD = 10, //请投入车票：用于AGM根据物理卡类型进行提示
	EM_TICKET_TRANS_RESULT_PLEASE_SWIPE_CARD = 11, //请刷卡：用于AGM根据物理卡类型进行提示
	EM_TICKET_TRANS_RESULT_CARD_MOVED = 12, //闪卡,请重新放卡
	EM_TICKET_TRANS_RESULT_OTHER_ERROR = 0xFF,		//其他错误
}EM_TICKET_TRANS_RESULT;

typedef enum
{
	EM_CARD_USED_WAY_WITHDRAW = 0x01, //出站投入(回收)
	EM_CARD_USED_WAY_NON_WITHDRAW = 0x02, //出站刷卡
	EM_CARD_USED_WAY_UNKNOWN = 0xFF, //未知
}EM_CARD_USED_WAY;

typedef struct _ST_POLLING_CARD_INFO_CSS_
{
	EM_TICKET_TRANS_RESULT emPollResult;	//寻卡结果
	EM_CARD_USED_WAY emCardUsedWay;			//卡片使用方式_出站刷卡或投入(回收),仅AG有效，TVM、BOM忽略
	int iCardPhyType;						//卡物理类型
	char szPhyCardNo[21];					//物理卡号
	int iAntennaMark;						//寻卡天线标志：	1：表示天线A寻到卡片；	2：表示天线B寻到卡片；4：表示天线C寻到卡片。
	unsigned int uiUdSeqKey;				//需要更新的UDSN 键值，由TPU 模块根据车票类型进行项目化实现，并传给数据存储模块直接保存
	unsigned int uiSamSeqKey;				//需要更新的UDSN 键值，由TPU 模块根据车票类型进行项目化实现，并传给数据存储模块直接保存
	unsigned char ucReverse[3];			//预留字段
}ST_TPU_POLLING_CARD_INFO;


#pragma pack(push, 1)
//cmd03 配置超时时间命令参数
typedef struct _ST_TIMEOUT_PARM_
{
	uint8_t authTimeOut; //乘客刷卡后没有进入闸机超时关门时间 例如0x06表示6秒，可以将其变为01~1E中的任意数字
	uint8_t reverse;	//保留
	uint8_t leaveAsideAlarmTimeout; //乘客在通道内停留几秒后催促报警。例如0x14表示20秒，可以将其变为01~1E中的任意数字
}ST_TIMEOUT_PARM;

//cmd04
typedef struct _ST_WORK_MODE_
{
    uint8_t flapForwardNormalOpen: 1;	//闸机正方向常开标志 1为正向常开
    uint8_t flapBackwardNormalOpen: 1;	//闸机反方向常开标志 1为反向常开
    uint8_t flapForwardDayMode: 1;		//闸机正方向开门日模式标志 1为正方向开门日模式
    uint8_t flapBackwardDayMode: 1;		//闸机反方向开门日模式标志 1为反方向开门日模式
    uint8_t flapForwardFreeTicket: 1;	//闸机正向免票标志 1为正向免票模式
    uint8_t flapBackwardFreeTicket: 1;	//闸机反向免票标志 1为反向免票模式
    uint8_t flapMaintainenceFlag: 1;	//闸机维护标志 1为维护模式
    uint8_t reserved0: 1;

    uint8_t	reserved1: 1;
    uint8_t	forbidChiledDetect: 1;			//儿童探测模式 1为不探测儿童
    uint8_t	tailDetectMod: 1;				//尾随距离探测模式。1为100mm尾随探测，0为150mm尾随探测
    uint8_t reserved2: 5;

    uint8_t reserved3: 8;

    uint8_t reserved4: 8;

    uint8_t reserved5: 8;
}ST_WORK_MODE; //4B

typedef struct _ST_KABA_ALARM_STATUS
{
    uint8_t forwardIntrusion:1;      //BYTE5.0正方向闯闸标志, flap not open。1为正方向闯闸，0为正方向不闯闸。
    uint8_t backwardIntrusion:1;      //BYTE5.1反方向闯闸标志, flap not open。1为反方向闯闸，0为反方向不闯闸。
    uint8_t forwardTailing:1;      //BYTE5.2正方向尾随标志。1为正方向尾随，0为正方向不尾随。
    uint8_t backwardTailing:1;     //BYTE5.3反方向尾随标志。1为反方向尾随，0为反方向不尾随。
    uint8_t forwardInverseIntrusion:1;     //BYTE5.4正方向反闯标志, flap open, 。1为正方向反闯，0为正方向不反闯。
    uint8_t backwardInverseIntrusion:1;      //BYTE5.5反方向反闯标志,flap open,。1为反方向反闯，0为反方向不反闯。
    uint8_t masterMaintenanceFlapClose:1;  //BYTE5.6主维护门开关标志。1为主维护门开，0为主维护门关。
    uint8_t slaveMaintenanceFlapClose:1;  //BYTE5.7从维护门开关标志。1为从维护门开，0为从维护门关。

    uint8_t gateFireWarningFlap:1;//BYTE6.0闸机火警标志。1为闸机火警，0为闸机不火警。
    uint8_t manInGateTooLongWaring:1;//BYTE6.1乘客长时间停留闸机报警标志。1为报警，0为不报警。
    uint8_t reserved6_2_7:6;//BYTE6.2~ BYTE6.7保留。

    uint8_t reserved7;

    uint8_t reserved8;
}ST_KABA_ALARM_STATUS;

typedef struct _ST_KABA_CZ_SENSOR_STATUS_
{
    ////BYTE9
    uint8_t optocouplerS9:1; //光耦S9            IOB-IN1
    uint8_t optocouplerS10:1;//光耦S10           IOB-IN2
    uint8_t optocouplerT1:1;//光耦T1            IOB-IN3
    uint8_t optocouplerT2:1;//光耦T2            IOB-IN4
    uint8_t optocouplerS11:1;//光耦S11           IOB-IN5
    uint8_t optocouplerS12:1;//光耦S12           IOB-IN6
    uint8_t masterSideMaintenanceDoorSwitch:1;//主侧维护门开关     IOB-IN7
    uint8_t slaveSideMaintenanceDoorSwitch:1;//从侧维护门开关     IOB-IN8

    //BYTE10：表示IOB I9~I16输入状态。1为对应位有输入，0为对应位无输入。
    uint8_t optocouplerS1:1;//光耦S1            IOB-IN9
    uint8_t optocouplerS2:1;//光耦S2            IOB-IN10
    uint8_t optocouplerS3:1;//光耦S3            IOB-IN11
    uint8_t optocouplerS4:1;//光耦S4            IOB-IN12
    uint8_t optocouplerS5:1;//光耦S5            IOB-IN13
    uint8_t optocouplerS6:1;//光耦S6            IOB-IN14
    uint8_t optocouplerS7:1;//光耦S7            IOB-IN15
    uint8_t optocouplerS8:1;//光耦S8            IOB-IN16

    uint8_t reserved11; //BYTE11：表示ETS22 I1~I8输入状态。1为对应位有输入，0为对应位无输入。
}ST_KABA_CZ_SENSOR_STATUS;



typedef struct _ST_KABA_STATUS_
{
    ST_WORK_MODE stWorkMode;//1-4
    ST_KABA_ALARM_STATUS stAlarmStatus;//5-8
    ST_KABA_CZ_SENSOR_STATUS stSensorStatus;//9-11
    uint8_t reserved12;
    ST_TIMEOUT_PARM stTimeoutParm; //13-15
    uint8_t reserved16;
}ST_KABA_STATUS;

#pragma pack(pop)
#endif /* TYPEDEF_H_ */
