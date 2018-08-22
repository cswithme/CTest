/****************
*File:EXDATA.h
*Time:20180815 145800
*Note:
*		1.以//@开头的行为标注,不可删除
*		2.建议使用单行注释
****************/
#ifndef _H_EXDATA_
#define _H_EXDATA_
#include "AFCDataPackComm.h"
#ifdef __cplusplus
extern "C"  {
#endif
//@BYTESEQ=BO_MOTO
//1 :not 4 bytes , 4:4 bytes
//@4BYTE=1
//0:定长 1：变长
//@LENTYPE=0

#include "CzBasiType.h"
#include "AFCEX.h"

typedef struct PrjFileTran_t
{
	/** 交易类型编码  Len:2 */
	TransactionType_t	TransactionType;

	/** 交易序列号  Len:4 */
	SN_t	UDSN;

	/** 交易运营日  Len:2 */
	Date2_t	BusinessDay;

	/** 交易时间  Len:4 */
	TimeStamp_t	TransactionDateTime;

	/** 服务提供商，线路运营商  Len:2 */
	ServiceProviderID_t	TransactionServiceProvider;

	LineID_t LineID;//add 20180606

	/** 交易车站：发售指定车站使用的预赋值单程票时，为该指定车站，其它为当前车站  Len:2 */
	StationID_t	StationID;

	/** 交易设备  Len:4 */
	DeviceID_t	DeviceID;

	/** 交易时设备所处的运行模式  Len:2 */
	OperationMode_t	OperationMode;

	/** PSAM/ISAM卡号,用来计算TAC  Len:8 */
	SAMID_t	SAMID;

	/** 语言选项,用于客显的默认语言  Len:1 */
	Language_t	LanguageBit;

	/** 容器编号，票箱ID  Len:4 */
	ContainerID_t	ContainerID;

	/** 操作员  Len:4 */
	StaffID_t	Operator;

	/** BOM班次信息  Len:1 */
	BOMShiftID_t	BOMShiftID;

	/** 票卡物理号  Len:8 */
	TicketPhyID_t	CardPhysicalNO;

	/** 票卡逻辑号  Len:8 */
	TicketLogicalID_t	CardLogicNO;

	/** 车票类型  Len:2 */
	TicketType_t	TicketType;

	/** 测试票标志  Len:1 */
	TestFlag_t	TestFlag;

	/** 票卡是否回收  Len:1 */
	Boolean_t	RecycleFlag;

	/** 交易后票卡的状态标志  Len:1 */
	TicketStatusFlag_t	TicketStatusFlag;

	/** 锁卡原因，用于锁卡交易 解锁原因，用于解锁交易  Len:1 */
	BlockCode_t	BlockorUnBlockCode;

	/** 票卡使用次数  Len:4 */
	OperationSN_t	OperationSN;

	/** 票卡结构版本号  Len:2 */
	LayoutVersionID_t	CardLayoutVersionNumber;

	/** 初始化日期  Len:2 */
	Date2_t	InitDate;

	/** 初始化批次  Len:1 */
	BatchCode_t	InitBatchCode;

	/** 储值票卡封面印刷类型  Len:2 */
	MediaType_t	MediaType;

	/** 车票计费方式  Len:1 */
	ChargingMode_t	ChargingMode;

	/** 车票有效期模式  Len:1 */
	ValidDateType_t	DurationMode;

	/** 有效期允许延期标志  Len:1 */
	ActiveFlag_t	DurationExtension;

	/** 车票有效期开始日期  Len:2 */
	Date2_t	CSCStartDate;

	/** 车票有效期结束日期  Len:2 */
	Date2_t	CSCEndDate;

	/** 车票有效期单位  Len:1 */
	DurationType_t	CSCDurationUnit;

	/** 车票有效期天数  Len:2 */
	Duration_t	CSCDuration;

	/** 持卡人类型  Len:1 */
	PassengerTypeID_t	PersonType;

	/** 持卡人姓名  Len:20 */
	Name_t	Name;

	/** 持卡人性别  Len:1 */
	Gender_t	Gender;

	/** 持卡人证件类型  Len:1 */
	PersonIDType_t	CertificateType;

	/** 持卡人证件号码  Len:18 */
	PersonIDSN_t	PersonID;

	/** 优惠审核（年审）日期  Len:2 */
	Date2_t	CheckDate;

	/** 优惠期，即优惠截止使用日期  Len:2 */
	Date2_t	FavourEndDate;

	/** 工号  Len:4 */
	StaffID_t	StaffID;

	/** 员工身份类型  Len:1 */
	//StaffType_t	StaffType;

	/** 所属部门  Len:4 */
	DepartmentID_t	DepartmentID;

	/** 乘车权限定义  Len:1 */
	AuthorityType_t	TravelRights;

	/** 当日最大乘车次数  Len:2 */
	MultiRideNumber_t	AllowedUses;

	/** 限制车站编号  Len:1 */
	SegmentID_t	AllowedStationID;

	/** 限制区域编号  Len:1 */
	ZoneID_t	ZoneID;

	/** 最大乘车里程等级  Len:1 */
	//FareRate_t	MaxFareRate;

	/** 操作权限  Len:4 */
	StaffBitmap_t	StaffOperationRights;

	/*进站线路*/
	LineID_t EntryLineID;//zxw201806

	/*进站车站*/
	StationID_t EntryStationID;//zxw201806
	
	/*进站时间*/
	TimeStamp_t Entrytime;//zxw201806

	/** 更新类型，用于更新交易  Len:1 */
	RenewFlag_t	SurchargeStatus;

	/** 拒绝出入站原因，用于进出站交易  Len:1 */
	RejectCode_t	EntryExitRejectCode;

	/** 用于退票退卡，表示原因  Len:1 */
	RefundReasonCode_t	RefundReason;

	//用于说明乘客事务处理原因
	PenaltyCode_t PenaltyCode;//zxw2018

	/** 本次交易钱包号  Len:1 */
	TicketFareTypeID_t	TicketWalletOrder;

	/** CPU卡电子钱包交易序列号，针对储值票  Len:4 */
	ePurseSN_t	ePurseTransactionSN;

	/** 交易前余额/次数  Len:4 */
	ValueCent_t	TicketValueBefore;

	/** 后台查询到的交易前账户余额/次数，用于退款时  Len:4 */
	ValueCent_t	AccountBalance;

	/** 确认余额：操作员确认的计程账户余额/非计程账户的等效余额，退票时即退款金额  Len:4 */
	ValueCent_t	OperatorConfirmedValue;

	//应收金额
	ValueCent_t	AmoutReceivable; //zxw2018
	/** 预收金额/用户插入的金额  Len:4 */
	ValueCent_t	InsertValue;

	/** 交易手续费  Len:4 */
	ValueCent_t	Poundage;

	/** 收取或退回的押金/工本费 售卡+票：收取的押金/工本费； 退卡：允许退押金/工本费时，所退的押金/工本费；其它应为0  Len:4 */
	ValueCent_t	CardDepositValue;

	/** 折旧费，用于退卡，最大等于押金/工本费  Len:4 */
	ValueCent_t	DepreciationValue;

	/** 找零金额(TVM和BOM复用该项目)应等于：预收金额-交易金额-押金/工本费-手续费  Len:4 */
	ValueCent_t	ChangeAmount;

	/** 交易金额 其中：出站时，计程票应等于计费（发生尾程优惠时会不等），其它票为0退款（退票和或退卡）时应等于：确认余额+押金/工本费-折旧-手续费 售票时应等于：预收金额-押金/工本费-手续费-找零金额 更新时应等于：加上罚款（如果有）的更新费用  Len:4 */
	ValueCent_t	TransactionValue;

	/** 钱包增减金额/次数  Len:4 */
	ValueCent_t	WalletChangeValue;

	/** 交易后余额/次数，应等于：交易前余额/次数-钱包增减金额/次数  Len:4 */
	ValueCent_t	RemainingValue;

	/** 累计充值金额，用于储值票充值  Len:4 */
	ValueCent_t	AccumulativeLoadedValue;

	/** 支付方式  Len:1 */
	PaymentMeans_t	Paymentmeans;

	/** 费率等级，针对单程票  Len:1 */
	FareRate_t	FareTier;

	/** 售票、充值和更新时付给乘客的收据/回单编号  Len:4 */
	ReceiptNumber_t	ReceiptNumber;

	/** 交易信息有效性验证码  Len:4 */
	TAC_t	TAC;

	/** 行结尾符：0x0d0a  Len:2 */
	U16_t	EndOfRecord;

}PrjFileTran_t;

typedef struct CurrencyCodeQty_t
{
	/** 币种代码  Len:1*/
	CurrencyCode_t  Currencycode;
	/** 币种数量  Len:2*/
	MiddleQuantity_t  Number;

}CurrencyCodeQty_t;

typedef struct PrjFileOper_t
{

	/** 操作交易类型编码  Len:2 */
	TransactionType_t	TransactionType;

	/** 序列号  Len:4 */
	SN_t	UDSN;

	/** 运营日  Len:2 */
	Date2_t	BusinessDay;

	/** 发生的时间  Len:4 */
	TimeStamp_t	TransactionDateTime;

	/** 设备类型  Len:1 */
	DeviceType_t	DeviceType;

	/** 设备编号  Len:4 */
	DeviceID_t	DeviceID;

	/** 操作员  Len:4 */
	StaffID_t	Operator;

	/** 班次  Len:1 */
	BOMShiftID_t	BOMShiftID;

	/** 钱票箱更换操作共同数据*/
	/** 钱票箱编号  Len:4*/
	ContainerID_t  ContainerID; 

	/** 操作类型  Len:1*/
	BoxOperationType_t  BoxOperationType;
	
	/** 钱票箱类型  Len:1*/
	BoxType_t  BoxType;
	
	/** 钱票箱位置（顺序号）  Len:1*/
	U8_t BoxLocationID;
	
	/** 安装时间  Len:4*/
	TimeStamp_t  TimeStamp;

	/** 币种总金额  Len:4*/
	ValueCent_t  TotalAmount;

	/** 循环体数量  Len:2*/
	MiddleQuantity_t  CurCount;
	//@LENNAME=CurCount.data.data
	CurrencyCodeQty_t  *CurrencyCodeQty;

	/** 车票类型  Len:2*/
	TicketType_t  TicketType;

	/** 安装时票卡数量  Len:4*/
	Quantity_t  InstallAmount;
	
	/** 当前票卡数量  Len:4*/
	Quantity_t  CurrentAmount;
	
	/** 行结尾符：0x0d0a  Len:2 */
	U16_t	EndOfRecord;

}PrjFileOper_t;

typedef struct PrjFileAudit_t
{



}PrjFileAudit_t;

typedef struct PrjFileFTP_t
{
}PrjFileFTP_t;

typedef struct PrjFileFTPDiff_t
{
}PrjFileFTPDiff_t;

typedef struct PrjFileBalance_t
{
}PrjFileBalance_t;

typedef struct PrjFileEvent_t
{

	/** 运营日  Len:2 */
	Date2_t	BusinessDay;

	/** 发生的时间  Len:4 */
	TimeStamp_t	TransactionDateTime;

	/** 设备编号  Len:4 */
	DeviceID_t	DeviceID;

	/** 事件编号  Len:2 */
	EventID_t	EventID;

	/** 事件名称  Len:6 */
	block_t	EventName[6];

	/** 事件值  Len:4 */
	EventValue_t	EventValue;

	/** 事件的严重等级  Len:1 */
	EquipmentStatusID_t	EquipmentStatusID;

	/** 预留字段  Len:7 */
	block_t	Reserved[7];

	/** 行结尾符：0x0d0a  Len:2 */
	U16_t	EndOfRecord;

}PrjFileEvent_t;

typedef struct PrjFileTvmBalance_t
{
	/** 设备类型  Len:1 */
	DeviceType_t  DeviceType;
	/** 设备编码  Len:1 */
	DeviceID_t  DeviceID;
	/** 硬币找零箱1 ID  Len:1 */
	U32_t  Coin1ID; 
	/** 硬币找零箱1 金额  Len:1 */
	ValueCent_t  Coin1Value;
	/** 硬币找零箱2 ID  Len:1 */
	U32_t  Coin2ID; 
	/** 硬币找零箱2 金额  Len:1 */
	ValueCent_t  Coin2Value;
	/** 硬币找零箱3 ID  Len:1 */
	U32_t  Coin3ID; 
	/** 硬币找零箱3 金额  Len:1 */
	ValueCent_t  Coin3Value;
	/** 硬币循环找零箱1 ID  Len:4 */
	U32_t  CoinCircle1ID; 
	/** 硬币循环找零箱1 金额  Len:4 */
	ValueCent_t  CoinCircle1Value;
	/** 硬币循环找零箱2 ID  Len:4 */
	U32_t  CoinCircle2ID; 
	/** 硬币循环找零箱2 金额  Len:4 */
	ValueCent_t  CoinCircle2Value;
	/** 硬币循环找零箱3 ID  Len:4 */
	U32_t  CoinCircle3ID; 
	/** 硬币循环找零箱3 金额  Len:4 */
	ValueCent_t  CoinCircle3Value;
	/** 硬币循环找零箱4 ID  Len:4 */
	U32_t  CoinCircle4ID; 
	/** 硬币循环找零箱4 金额  Len:4 */
	ValueCent_t  CoinCircle4Value;
	/** 硬币循环找零箱5 ID  Len:4 */
	U32_t  CoinCircle5ID; 
	/** 硬币循环找零箱5 金额  Len:4 */
	ValueCent_t  CoinCircle5Value;
	/** 硬币回收箱 ID  Len:4 */
	U32_t  CoinRecoverID; 
	/** 硬币回收箱 金额  Len:4 */
	ValueCent_t  CoinRecoverValue;
	/** 纸币钱箱  ID  Len:4 */
	U32_t  PaperRecoverID; 
	/** 纸币钱箱  金额  Len:4 */
	ValueCent_t  PaperRecoverValue;
	/** 票箱1 ID  Len:4 */
	U32_t  TicketBox1ID; 
	/** 票箱1 数量  Len:4 */
	Quantity_t  Quantity1;
	/** 票箱2 ID  Len:4 */
	U32_t  TicketBox2ID; 
	/** 票箱2 数量  Len:4 */
	Quantity_t  Quantity2;
	/** 保留  Len:4 */
	block_t Rest[5];

}PrjFileTvmBalance_t;

typedef struct PrjFileBomAgBalance_t
{
	/** 设备类型  Len:1 */
	DeviceType_t  DeviceType;
	/** 节点标识码  Len:1 */
	DeviceID_t  DeviceID;
	/** 票箱1 ID  Len:1 */
	U32_t  TicketBox1ID; 
	/** 票箱1 数量  Len:1 */
	Quantity_t  Quantity1;
	/** 票箱2 ID  Len:1 */
	U32_t  TicketBox2ID; 
	/** 票箱2 数量  Len:1 */
	Quantity_t  Quantity2;
	/** 保留  Len:1 */
	block_t Rest[2];

}PrjFileBomAgBalance_t;

typedef struct PrjFileHeader_t
{
	//@MSGTYPE=(&value->FileHeaderTag.data.data);
	FileType_t FileHeaderTag;
	DeviceID_t DeviceID;
	Date2_t BusinessDay;
	TimeStamp_t FileCreationTime;
	SN_t FileSN;
	VersionID_t FileFormatVersionID;
}PrjFileHeader_t;

typedef struct PrjFileBody_t
{

	Quantity_t RecordCount;

	//@SWITCH=*(uint16_t *)adp->pMsgType
	union
	{
		//@CASE=0x1000
		//@LENNAME=RecordCount.data.data
		PrjFileTran_t* PrjFileTran_val;
		//@CASE=0x1200
		//@LENNAME=RecordCount.data.data
		PrjFileOper_t* PrjFileOper_val;
		//@CASE=0x2002
		//@LENNAME=RecordCount.data.data
		PrjFileAudit_t* PrjFileAudit_val;
		//@CASE=0x2003
		//@LENNAME=RecordCount.data.data
		PrjFileEvent_t* PrjFileEvent_val;
		//@CASE=0x2004
		//@LENNAME=RecordCount.data.data
		PrjFileBalance_t* PrjFileBalance_val;
		//@CASE=0x2006
		//@LENNAME=RecordCount.data.data
		PrjFileFTP_t* PrjFileFTP_val;
		//@CASE=0x2007
		//@LENNAME=RecordCount.data.data
		PrjFileFTPDiff_t* PrjFileFTPDiff_val;
		//@CASE=0x2008
		//@LENNAME=RecordCount.data.data
		PrjFileTvmBalance_t* PrjFileTvmBalance_val;
		//@CASE=0x2009
		//@LENNAME=RecordCount.data.data
		PrjFileBomAgBalance_t* PrjFileBomAgBalance_val;
	}body_u;

}PrjFileBody_t;

typedef struct PrjFileTail_t
{
	MD5_t Security_Certificate;
}PrjFileTail_t;

typedef struct PrjFile_t
{
	PrjFileHeader_t PrjFileHeader;
	PrjFileBody_t PrjFileBody;
	PrjFileTail_t PrjFileTail;
}PrjFile_t;

typedef struct FilesAll_t
{
	uint16_t Type;
	uint16_t Len;

	//@SWITCH=value->Type
	union
	{
		//@CASE=0x1000
		//@LENNAME=Len
		PrjFileTran_t* PrjFileTran_val;
		//@CASE=0x1200
		//@LENNAME=Len
		PrjFileOper_t* PrjFileOper_val;
		//@CASE=0x2002
		//@LENNAME=Len
		PrjFileAudit_t* PrjFileAudit_val;
		//@CASE=0x2003
		//@LENNAME=Len
		PrjFileEvent_t* PrjFileEvent_val;
		//@CASE=0x2004
		//@LENNAME=Len
		PrjFileBalance_t* PrjFileBalance_val;
		//@CASE=0x2006
		//@LENNAME=Len
		PrjFileFTP_t* PrjFileFTP_val;
		//@CASE=0x2007
		//@LENNAME=Len
		PrjFileFTPDiff_t* PrjFileFTPDiff_val;
	}body_u;

}FilesAll_t;

int adp_PrjFileTran_t(ADP* adp,PrjFileTran_t* value);
int adp_CurrencyCodeQty_t(ADP* adp,CurrencyCodeQty_t* value);
int adp_PrjFileOper_t(ADP* adp,PrjFileOper_t* value);
int adp_PrjFileAudit_t(ADP* adp,PrjFileAudit_t* value);
int adp_PrjFileFTP_t(ADP* adp,PrjFileFTP_t* value);
int adp_PrjFileFTPDiff_t(ADP* adp,PrjFileFTPDiff_t* value);
int adp_PrjFileBalance_t(ADP* adp,PrjFileBalance_t* value);
int adp_PrjFileEvent_t(ADP* adp,PrjFileEvent_t* value);
int adp_PrjFileTvmBalance_t(ADP* adp,PrjFileTvmBalance_t* value);
int adp_PrjFileBomAgBalance_t(ADP* adp,PrjFileBomAgBalance_t* value);
int adp_PrjFileHeader_t(ADP* adp,PrjFileHeader_t* value);
int adp_PrjFileBody_t(ADP* adp,PrjFileBody_t* value);
int adp_PrjFileTail_t(ADP* adp,PrjFileTail_t* value);
int adp_PrjFile_t(ADP* adp,PrjFile_t* value);
int adp_FilesAll_t(ADP* adp,FilesAll_t* value);
#ifdef __cplusplus
}
#endif
#endif
