/****************
*File:CzPara.h
*Time:20180802 162222
*Note:
*		1.以//@开头的行为标注,不可删除
*		2.建议使用单行注释
****************/
#ifndef _H_CzPara_
#define _H_CzPara_
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


/**
 * 	ACC服务商参数
 * 	*/ 
typedef struct PARA_ACC_EOD_Server_t
{ 

	/** 服务商数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** 服务商代码 Len:2 */ 
	ServiceProviderID_t Code; 

	/** 服务商中文名称 Len:64 */ 
	LongName_t CnLongName; 

	/** 服务商中文简称 Len:20 */ 
	Name_t CnName; 

	/** 服务商英文名称 Len:64 */ 
	LongName_t EnLongName; 

	/** 服务商英文简称 Len:20 */ 
	Name_t EnName; 

	/** 服务商角色代码 Len:1 */ 
	ServiceProviderRoleCode_t RoleCode; 

}PARA_ACC_EOD_Server_t; 

/**
 * 	线路车站参数项定义（detail）
 * 	*/ 
typedef struct PARA_LINE_STATION_DETAIL_t
{ 
	/** 车站编码 Len:2 */ 
	StationID_t StaionID; 

	/** 车站全局编码 Len:2 */ 
	StationGlobalID_t StationGlobalID; 

	/** 车站序号 Len:1 */ 
	U8_t Seq; 

	/** 车站级别 Len:1 */ 
	StationLevel_t Level; 

	/** 车站分类 Len:1 */ 
	StationType_t Type; 

}PARA_LINE_STATION_DETAIL_t; 

/**
 * 	线路车站参数项定义
 * 	*/ 
typedef struct PARA_LINE_STATION_t
{ 
	/** 线路编码 Len:1 */ 
	LineID_t LineID; 

	/** 线路中车站数量 Len:1 */ 
	SmallQuantity_t StaQty; 

	//@LENNAME=StaQty.data.data
	PARA_LINE_STATION_DETAIL_t *PARA_LINE_STATION_DETAIL;

}PARA_LINE_STATION_t; 

/**
 * 	线路扩展参数项定义
 * 	*/ 
typedef struct PARA_LINE_EXT_t
{ 
	/** 线路编码 Len:1 */ 
	LineID_t LineID; 

	/** 线路中文名称 Len:64 */ 
	LongName_t CnLongName; 

	/** 线路中文简称 Len:20 */ 
	Name_t CnName; 

	/** 线路英文名称 Len:64 */ 
	LongName_t EnLongName; 

	/** 线路英文简称 Len:20 */ 
	Name_t EnName; 

}PARA_LINE_EXT_t; 

/**
 * 	车站扩展参数项定义
 * 	*/ 
typedef struct PARA_STATION_EXT_t
{ 

	/** 车站编码 Len:2 */ 
	StationID_t StationID; 

	/** 车站中文名称 Len:64 */ 
	LongName_t CnLongName; 

	/** 车站中文简称 Len:20 */ 
	Name_t CnName; 

	/** 车站英文名称 Len:64 */ 
	LongName_t EnLongName; 

	/** 车站英文简称 Len:20 */ 
	Name_t EnName; 

}PARA_STATION_EXT_t; 

/**
 * 	区域参数项定义(detail)
 * 	*/ 
typedef struct PARA_ZONE_DETAIL_t
{ 
	/** 区域车站编码 Len:2 */ 
	StationID_t StationID; 

}PARA_ZONE_DETAIL_t;

/**
 * 	区域参数项定义
 * 	*/ 
typedef struct PARA_ZONE_t
{ 

	/** 区域代码 Len:1 */ 
	ZoneID_t ZoneID; 

	/** 区域名称 Len:20 */ 
	Name_t ZoneName; 

	/** 区域中车站数量 Len:1 */ 
	SmallQuantity_t StaQty; 

	//@LENNAME=StaQty.data.data
	PARA_ZONE_DETAIL_t *PARA_ZONE_DETAIL;

}PARA_ZONE_t; 

/**
 * 	区段参数项定义
 * 	*/ 
typedef struct PARA_SEGMENT_t
{ 

	/** 区段代码 Len:1 */ 
	SegmentID_t Code; 

	/** 区段名称 Len:20 */ 
	Name_t Name; 

	/** 区段车站编码1 Len:2 */ 
	StationID_t Sta1; 

	/** 区段车站编码2 Len:2 */ 
	StationID_t Sta2; 

}PARA_SEGMENT_t; 

/**
 * 	换乘车站参数项定义
 * 	*/ 
typedef struct PARA_TRANSFER_STATION_t
{ 

	/** 换乘车站数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 换乘车站编码 Len:1 */ 
	TransferStationID_t Sta; 

}PARA_TRANSFER_STATION_t; 

/**
 * 	 ACC网络拓扑图参数
 * 	 */ 
typedef struct PARA_ACC_EOD_NetworkTopo_t
{ 

	/** 线路数量 Len:1 */ 
	SmallQuantity_t LioneQty;
	//@LENNAME=LioneQty.data.data
	PARA_LINE_STATION_t *PARA_LINE_STATION;

	/** 线路数量 Len:1 */ 
	SmallQuantity_t LineQty; 
	//@LENNAME=LineQty.data.data
	PARA_LINE_EXT_t *PARA_LINE_EXT;

	/** 车站数量 Len:2 */ 
	MiddleQuantity_t StaQty; 
	//@LENNAME=StaQty.data.data
	PARA_STATION_EXT_t *PARA_STATION_EXT;

	/** 区域数量 Len:1 */ 
	SmallQuantity_t ZoneQty; 
	//@LENNAME=ZoneQty.data.data
	PARA_ZONE_t *PARA_ZONE;

	/** 区段数量 Len:1 */ 
	SmallQuantity_t Qty; 
	//@LENNAME=Qty.data.data
	PARA_SEGMENT_t *PARA_SEGMENT;

}PARA_ACC_EOD_NetworkTopo_t; 



/**
 * 	工作日历属性
 * 	*/ 
typedef struct PARA_DURATION_t
{ 

	/** 工作日历天数 Len:2 */ 
	Duration_t Qty; 

	/** 工作日历开始日期 Len:2 */ 
	Date2_t Sta; 

	/** 工作日历结束日期 Len:2 */ 
	Date2_t End; 

}PARA_DURATION_t; 

/**
 * 	特殊日期/节假日属性
 * 	*/ 
typedef struct PARA_SPECIAL_DATE_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** 非工作日日期 Len:2 */ 
	Date2_t Date; 

	/** 非工作日日期类型 Len:1 */ 
	SpecialDateType_t Type; 

}PARA_SPECIAL_DATE_t; 

/**
 * 	时间段属性
 * 	*/ 
typedef struct PARA_TIME_ZONE_t
{ 

	/** 循环体数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 时间段代码 Len:1 */ 
	U8_t Code; 

	/** 适用日期类型 Len:1 */ 
	SpecialDateType_t Type; 

	/** 时间段类型 Len:1 */ 
	TimeZoneType_t ZoneType; 

	/** 时间段开始时间 Len:2 */ 
	TimeIntervalID_t Sta; 

	/** 时间段结束时间 Len:2 */ 
	TimeIntervalID_t End; 

}PARA_TIME_ZONE_t; 

/**
 * 	运营日属性（包括基准日期时间）
 * 	*/ 
typedef struct PARA_RUN_DATE_t
{ 

	/** 本地时区差值 Len:4 */ 
	UTCTime_t DiffTime; 

	/** 基准时间 Len:4 */ 
	BaseTime_t BaseTime; 

	/** 循环体数量 Len:2 */ 
	Duration_t Qty; 

	/** 非运营日日期 Len:2 */ 
	Date2_t Date; 

}PARA_RUN_DATE_t; 

/**
 * 	运营时间属性
 * 	*/ 
typedef struct PARA_RUN_TIME_t
{ 

	/** 运营日开始时间 Len:4 */ 
	Second_t Sta; 

	/** 运营日结束时间 Len:4 */ 
	Second_t End; 

}PARA_RUN_TIME_t; 

/**
 * 	数据上传时间属性
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_UP_t
{ 

	/** 交易数据上传时间 Len:2 */ 
	TimeIntervalID_t TranUpTime; 

	/** 事件数据上传时间 Len:2 */ 
	TimeIntervalID_t EventUpTime; 

	/** 审计数据上传时间 Len:2 */ 
	TimeIntervalID_t AuditUpTime; 

	/** 客流统计数据上传时间 Len:2 */ 
	TimeIntervalID_t PassUpTime; 

}PARA_TIME_INTERVAL_UP_t; 

/**
 * 	数据查询时间属性
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_QUERY_t
{ 

	/** 数据查询时间间隔 Len:2 */ 
	TimeIntervalID_t QueryTime; 

}PARA_TIME_INTERVAL_QUERY_t; 

/**
 * 	参数下载时间属性
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_DOWN_t
{ 

	/** 一卡通参数下载时间 Len:2 */ 
	TimeIntervalID_t YKTDownTime; 

	/** 一卡通清算结果文件下载时间 Len:2 */ 
	TimeIntervalID_t YKTRetTime; 

	/** 线路下载参数时间 Len:2 */ 
	TimeIntervalID_t LineDownTime; 

	/** 车站下载参数时间 Len:2 */ 
	TimeIntervalID_t StaDownTime; 

	/** 设备下载参数时间 Len:2 */ 
	TimeIntervalID_t DevDownTime; 

}PARA_TIME_INTERVAL_DOWN_t; 

/**
 * 	黑名单（含灰名单）下载时间属性
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_BLACK_t
{ 

	/** 黑名单和含灰名单下载时间 Len:2 */ 
	TimeIntervalID_t BlackDownTime; 

}PARA_TIME_INTERVAL_BLACK_t; 

/**
 * 	设备认证时间间隔属性
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_DEV_AUTH_t
{ 

	/** 设备认证时间间隔 Len:2 */ 
	TimeIntervalID_t Time; 

}PARA_TIME_INTERVAL_DEV_AUTH_t; 

/**
 * 	设备状态查询时间属性
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_STATU_QUERY_t
{ 

	/** 设备状态查询时间间隔 Len:2 */ 
	TimeIntervalID_t Time; 

}PARA_TIME_INTERVAL_STATU_QUERY_t; 

/**
 * 	统计时间片属性
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_STATISTICS_t
{ 

	/** 统计时间间隔 Len:2 */ 
	TimeIntervalID_t Time; 

}PARA_TIME_INTERVAL_STATISTICS_t; 

/**
 * 	最大允许乘车时间
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_MAX_INSTATION_t
{ 

	/** 最大允许乘车时间 Len:2 */ 
	TimeIntervalID_t Time; 

}PARA_TIME_INTERVAL_MAX_INSTATION_t; 

/**
 * 	非即时退款间隔时间属性
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_NOINS_RETURN_t
{ 

	/** 非即时退款间隔时间 Len:2 */ 
	TimeIntervalID_t Time; 

}PARA_TIME_INTERVAL_NOINS_RETURN_t; 

/**
 * 	票卡库存数据上报时间间隔
 * 	*/ 
typedef struct PARA_TIME_INTERVAL_TICK_REPORT_t
{ 

	/** 票卡库存数据上报时间间隔 Len:2 */ 
	TimeIntervalID_t Time; 

}PARA_TIME_INTERVAL_TICK_REPORT_t; 

/**
 * 	时钟同步的偏差时间参数
 * 	*/ 
typedef struct PARA_TIME_NTP_DIFF_t
{ 

	/** 时钟同步的偏差时间下限 Len:4 */ 
	Second_t MinTime; 

	/** 时钟同步的偏差时间上限 Len:4 */ 
	Second_t MaxTime; 

}PARA_TIME_NTP_DIFF_t; 

/**
 * 	ACC日历/时间参数
 * 	*/ 
typedef struct PARA_ACC_EOD_Calendar_t
{ 

	PARA_DURATION_t PARA_DUARTION;

	PARA_SPECIAL_DATE_t PARA_SPECIAL_DATE;

	PARA_TIME_ZONE_t PARA_TIME_ZONE;

	PARA_RUN_DATE_t PARA_RUN_DATE;

	PARA_TIME_INTERVAL_UP_t PARA_TIME_INTERVAL_UP;

	PARA_TIME_INTERVAL_QUERY_t PARA_TIME_INTERVAL_QUERY;

	PARA_TIME_INTERVAL_DOWN_t PARA_TIME_INTERVAL_DOWN;

	PARA_TIME_INTERVAL_BLACK_t PARA_TIME_INTERVAL_BLACK;

	PARA_TIME_INTERVAL_DEV_AUTH_t PARA_TIME_INTERVAL_DEV_AUTH;

	PARA_TIME_INTERVAL_STATU_QUERY_t PARA_TIME_INTERVAL_STATU_QUERY;

	PARA_TIME_INTERVAL_STATISTICS_t PARA_TIME_INTERVAL_STATISTICS;

	PARA_TIME_INTERVAL_MAX_INSTATION_t PARA_TIME_INTERVAL_MAX_INSTATION;

	PARA_TIME_INTERVAL_NOINS_RETURN_t PARA_TIME_INTERVAL_NOINS_RETURN;

	PARA_TIME_INTERVAL_TICK_REPORT_t PARA_TIME_INTERVAL_TICK_REPORT;

	PARA_TIME_NTP_DIFF_t PARA_TIME_NTP_DIFF;

}PARA_ACC_EOD_Calendar_t; 
typedef struct PARA_ACC_WaiverDateC_t
{

	/** 模式履历编号 Len:2 */ 
	U16_t Id; 

	/** 运行模式代码 Len:2 */ 
	OperationMode_t ModeCode; 

	/** 模式发生运营日 Len:2 */ 
	Date2_t RunDate; 

	/** 模式发生车站 Len:2 */ 
	StationID_t Sta; 

	/** 模式开始时间 Len:4 */ 
	TimeStamp_t StaTime; 

	/** 模式结束时间 Len:4 */ 
	TimeStamp_t EndTime; 

	/** 敏感期结束时间 Len:4 */ 
	TimeStamp_t sensitiveEnd; 

}PARA_ACC_WaiverDateC_t;

/**
 * 	ACC模式履历参数
 * 	*/ 
typedef struct PARA_ACC_WaiverDate_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	//@LENNAME=Qty.data.data
	PARA_ACC_WaiverDateC_t* PARA_ACC_WaiverDateC_val;

}PARA_ACC_WaiverDate_t; 


/**
 * 	介质类型属性
 * 	*/ 
typedef struct PARA_CHIP_TYPE_t
{ 

	/** 介质技术类型代码 Len:1 */ 
	ChipType_t Type; 

	/** 卡商编码 Len:1 */ 
	CardFactory_t Code; 

	/** 介质使用有效期 Len:2 */ 
	Date2_t Date; 

	/** 介质最大交易次数 Len:4 */ 
	Quantity_t Count; 

}PARA_CHIP_TYPE_t; 

/**
 * 	介质类型扩展属性
 * 	*/ 
typedef struct PARA_CHIP_TYPE_EXT_t
{ 

	/** 介质技术类型代码 Len:1 */ 
	ChipType_t Type; 

	/** 介质技术类型中文名称 Len:64 */ 
	LongName_t CnLongName; 

	/** 介质技术类型中文简称 Len:20 */ 
	Name_t CnName; 

	/** 介质技术类型英文名称 Len:64 */ 
	LongName_t EnLongName; 

	/** 介质技术类型英文简称 Len:20 */ 
	Name_t EnName; 

}PARA_CHIP_TYPE_EXT_t; 

/**
 * 	票种分类类型属性
 * 	*/ 
typedef struct PARA_TICKET_FAMILY_t
{ 

	/** 票种分类编码 Len:1 */ 
	TicketFamily_t Family; 

	/** 介质技术类型代码 Len:1 */ 
	ChipType_t Type; 

}PARA_TICKET_FAMILY_t; 

/**
 * 	票种分类类型扩展属性
 * 	*/ 
typedef struct PARA_TICKET_FAMILY_EXT_t
{ 

	/** 票种分类编码 Len:1 */ 
	TicketFamily_t Family; 

	/** 票种分类类型中文名称 Len:64 */ 
	LongName_t CnLongName; 

	/** 票种分类类型中文简称 Len:20 */ 
	Name_t CnName; 

	/** 票种分类类型英文名称 Len:64 */ 
	LongName_t EnLongName; 

	/** 票种分类类型英文简称 Len:20 */ 
	Name_t EnName; 

}PARA_TICKET_FAMILY_EXT_t; 

/**
 * 	车票类型属性
 * 	*/ 
typedef struct PARA_TICKET_TYPE_t
{ 

	/** 车票类型编码 Len:2 */ 
	TicketType_t Type; 

	/** 票种分类代码 Len:1 */ 
	TicketFamily_t Family; 

	/** 押金或工本费 Len:4 */ 
	ValueCent_t Deposit; 

	/** 单程标志 Len:1 */ 
	Boolean_t SingleFlag; 

	/** 行李标志 Len:1 */ 
	Boolean_t Luggage; 

	/** 仅出站使用标志 Len:1 */ 
	Boolean_t ExitFlag; 

	/** 进出次序标志 Len:1 */ 
	Boolean_t OrderFlag; 

	/** 进站验证标志 Len:1 */ 
	Boolean_t AuthFlag; 

	/** 是否回收 Len:1 */ 
	Boolean_t RecoveryFlag; 

	/** 记名标志 Len:1 */ 
	Boolean_t RegFlag; 

	/** 纪念票标志 Len:1 */ 
	SouvenirFlag_t CommemorativeFlag; 

	/** 车票发售模式 Len:1 */ 
	SalePriceMode_t SellMode; 

	/** 优惠类型编码 Len:1 */ 
	FavourID_t FavourID; 

	/** 计费方式编码 Len:1 */ 
	ChargingMode_t BillMode; 

	/** 费率类型编码 Len:1 */ 
	FareType_t FareType; 

	/** 是否限时 Len:1 */ 
	Boolean_t IfLimitTime; 

	/** 是否限区域 Len:1 */ 
	Boolean_t IfLimitZone; 

	/** 是否限区段 Len:1 */ 
	Boolean_t IfLimitSegment; 

	/** 允许充值 Len:1 */ 
	ActiveFlag_t IfRecharge; 

	/** 有效期分类类型 Len:1 */ 
	ValidDateType_t ValidDateType; 

	/** 有效期允许延期标志 Len:1 */ 
	ActiveFlag_t AllowDalayTime; 

	/** 允许退票 Len:1 */ 
	ActiveFlag_t AllowRetTicket; 

	/** 退票手续费 Len:4 */ 
	ValueCent_t RetFee; 

	/** 退票限制金额 Len:4 */ 
	ValueCent_t RetLimitAmt; 

	/** 允许退卡 Len:1 */ 
	ActiveFlag_t AllowRetCard; 

	/** 允许换卡 Len:1 */ 
	ActiveFlag_t AllowChange; 

	/** 退卡/换卡手续费 Len:4 */ 
	ValueCent_t ServiceFee; 

	/** 折旧 Len:2 */ 
	Depreciation_t Depreciation; 

	/** 印刷方式 Len:2 */ 
	MediaType_t MediaType; 

	/** 积分方案编码 Len:1 */ 
	BonusPointsID_t BonusPointsID; 

	/** 最小进站余额 Len:4 */ 
	ValueCent_t EntryMinBalance; 

	/** 最小出站余额 Len:4 */ 
	ValueCent_t ExitMinBalance; 

	/** 最大余额 Len:4 */ 
	ValueCent_t MaxBalance; 

	/** 允许透支或允许尾程优惠 Len:1 */ 
	ActiveFlag_t AllowOverdraft; 

	/** 连乘优惠类别 Len:1 */ 
	ConcessionType_t ConcessionType; 

	/** 车票类型启用标志 Len:1 */ 
	ActiveFlag_t TicketTypeOpenSign; 

}PARA_TICKET_TYPE_t; 

/**
 * 	车票类型扩展属性
 * 	*/ 
typedef struct PARA_TICKET_TYPE_EXT_t
{ 

	/** 车票类型编码 Len:2 */ 
	TicketType_t Type; 

	/** 车票类型中文名称 Len:64 */ 
	LongName_t CnLongName; 

	/** 车票类型中文简称 Len:20 */ 
	Name_t CnName; 

	/** 车票类型英文名称 Len:64 */ 
	LongName_t EnLongName; 

	/** 车票类型英文简称 Len:20 */ 
	Name_t EnName; 

	/** 显示灯编号 Len:1 */ 
	ConcessionalLampID_t LedID; 

	/** 提示音编号 Len:1 */ 
	SoundDisplayID_t SoundID; 

}PARA_TICKET_TYPE_EXT_t; 

/**
 * 	车票有效期方式属性
 * 	*/ 
typedef struct PARA_TICKET_VALIDDATE_t
{ 

	/** 有效期分类编码 Len:1 */ 
	ValidDateType_t Type; 

	/** 有效期分类名称 Len:20 */ 
	Name_t Name; 

	/** 有效期单位 Len:1 */ 
	DurationType_t ValidType; 

	/** 有效期天数 Len:2 */ 
	Duration_t ValidDate; 

	/** 有效期开始日期 Len:2 */ 
	Date2_t Sta; 

	/** 有效期结束日期 Len:2 */ 
	Date2_t End; 

}PARA_TICKET_VALIDDATE_t; 

/**
 * 	优惠类型属性
 * 	*/ 
typedef struct PARA_TICKET_FAVOUR_t
{ 

	/** 优惠类型编码 Len:1 */ 
	FavourID_t Code; 

	/** 优惠类型名称 Len:20 */ 
	Name_t Name; 

	/** 优惠比例折扣率 Len:1 */ 
	Discount_t Discount; 

}PARA_TICKET_FAVOUR_t; 

/**
 * 	ACC介质/票卡参数
 * 	*/ 
typedef struct PARA_ACC_EOD_MediaCard_t
{ 
	
	/** 介质技术类型数量 Len:1 */ 
	SmallQuantity_t Qty1; 
	//@LENNAME=Qty1.data.data
	PARA_CHIP_TYPE_t *PARA_CHIP_TYPE;

	/** 介质技术类型数量（扩展） Len:1 */ 
	SmallQuantity_t Qty2; 
	//@LENNAME=Qty2.data.data
	PARA_CHIP_TYPE_EXT_t *PARA_CHIP_TYPE_EXT;

	/** 票种分类数量 Len:1 */ 
	SmallQuantity_t Qty3; 
	//@LENNAME=Qty3.data.data
	PARA_TICKET_FAMILY_t *PARA_TICKET_FAMILY;

	/** 票种分类类型数量 Len:1 */ 
	SmallQuantity_t Qty4; 
	//@LENNAME=Qty4.data.data
	PARA_TICKET_FAMILY_EXT_t *PARA_TICKET_FAMILY_EXT;

	/** 车票类型参数数量 Len:2 */ 
	MiddleQuantity_t Qty5; 
	//@LENNAME=Qty5.data.data
	PARA_TICKET_TYPE_t *PARA_TICKET_TYPE;

	/** 车票类型扩展参数数量 Len:2 */ 
	MiddleQuantity_t Qty6; 
	//@LENNAME=Qty6.data.data
	PARA_TICKET_TYPE_EXT_t *PARA_TICKET_TYPE_EXT;

	/** 车票有效期方式参数循环体数量 Len:1 */ 
	SmallQuantity_t Qty7; 
	//@LENNAME=Qty7.data.data
	PARA_TICKET_VALIDDATE_t *PARA_TICKET_VALIDDATE;

	/** 优惠类型数量 Len:1 */ 
	SmallQuantity_t Qty8; 
	//@LENNAME=Qty8.data.data
	PARA_TICKET_FAVOUR_t *PARA_TICKET_FOVOUR;

}PARA_ACC_EOD_MediaCard_t; 
/**
 * 	ACC清分规则参数
 * 	*/ 
typedef struct PARA_ACC_EOD_ClearingRule_t
{ 

	/** 充值代理服务费率 Len:1 */ 
	Percentage_t RechargeServiceFee; 

	/** 销售代理服务费率 Len:1 */ 
	Percentage_t SellServiceFee; 

	/** 清分滞留数据期限 Len:2 */ 
	Duration_t RetentionPeriod; 

	/** 循环体数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 线路编码 Len:1 */ 
	LineID_t Line; 

	/** 分摊比例 Len:1 */ 
	Percentage_t ApportionmentRatio; 

}PARA_ACC_EOD_ClearingRule_t; 


/**
 * 	支付属性
 * 	*/ 
typedef struct PARA_PAY_ATTR_t
{ 

	/** 银行卡支付的最小金额 Len:4 */ 
	ValueCent_t BankPayMinAmt; 

	/** 现金支付的最大金额 Len:4 */ 
	ValueCent_t CashPayMaxAmt; 

}PARA_PAY_ATTR_t; 

/**
 * 	车费类型定义
 * 	*/ 
typedef struct PARA_FARE_TYPE_t
{ 

}PARA_FARE_TYPE_t; 

/**
 * 	费率等级矩阵定义
 * 	*/ 
typedef struct PARA_FARE_LEVEL_t
{ 

	/** 循环体数量 Len:4 */ 
	Quantity_t Qty; 

	/** 起点站 Len:2 */ 
	StationID_t Sta; 

	/** 终点站 Len:2 */ 
	StationID_t End; 

	/** 费率等级代码 Len:1 */ 
	FareRate_t Level; 

}PARA_FARE_LEVEL_t; 

/**
 * 	费率类型对应费率组定义
 * 	*/ 
typedef struct PARA_FARE_TYPE_GROUP_t
{ 

	/** 循环体1数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 费率类型代码 Len:1 */ 
	FareType_t Type; 

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	/** 时间段代码 Len:1 */ 
	U8_t TimeCode; 

	/** 费率组代码 Len:1 */ 
	FareGroup_t FareGroup; 

}PARA_FARE_TYPE_GROUP_t; 

/**
 * 	费率表
 * 	*/ 
typedef struct PARA_FARE_TBL_t
{ 

	/** 循环体1数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 费率组代码 Len:1 */ 
	FareGroup_t FareGroup; 

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	/** 费率等级代码 Len:1 */ 
	FareRate_t Level; 

	/** 费率 Len:4 */ 
	ValueCent_t FareRate; 

}PARA_FARE_TBL_t; 

/**
 * 	费率等级乘车时间表
 * 	*/ 
typedef struct PARA_FARE_TIME_t
{ 

	/** 循环体数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 费率等级代码 Len:1 */ 
	FareRate_t Level; 

	/** 停留时间极限 Len:2 */ 
	TimeIntervalID_t StopLimit; 

}PARA_FARE_TIME_t; 

/**
 * 	其它参数
 * 	*/ 
typedef struct PARA_FARE_OTHER_t
{ 

	/** 最短回程时间 Len:2 */ 
	TimeIntervalID_t ShortRetTime; 

	/** 最短回程费用 Len:4 */ 
	ValueCent_t ShortRetFee; 

	/** 最大交易金额 Len:4 */ 
	ValueCent_t MaxAmt; 

	/** 最小进站金额 Len:4 */ 
	ValueCent_t MinEntryAmt; 

	/** 最小出站金额 Len:4 */ 
	ValueCent_t MinExitAmt; 

}PARA_FARE_OTHER_t; 

/**
 * 	 ACC费率表参数
 * 	 */ 
typedef struct PARA_ACC_EOD_Fare_t
{ 

	PARA_PAY_ATTR_t PARA_PAY_ATTR;

	PARA_FARE_TYPE_t PARA_FARE_TYPE;

	PARA_FARE_LEVEL_t PARA_FARE_LEVEL;

	PARA_FARE_TYPE_GROUP_t PARA_FARE_TYPE_GROUP;

	PARA_FARE_TBL_t PARA_FARE_TBL;

	PARA_FARE_TIME_t PARA_FARE_TIME;

	PARA_FARE_OTHER_t PARA_FARE_OTHER;

}PARA_ACC_EOD_Fare_t; 



/**
 * 	罚款参数
 * 	*/ 
typedef struct PARA_TICK_PENALTY_t
{ 

	/** 循环体数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 罚款原因代码 Len:1 */ 
	PenaltyCode_t Code; 

	/** 罚款金额 Len:4 */ 
	ValueCent_t Amt; 

}PARA_TICK_PENALTY_t; 

/**
 * 	连乘优惠参数
 * 	*/ 
typedef struct PARA_TICK_DISCOUNT_t
{ 

	/** 连乘优惠时间 Len:4 */ 
	Second_t Time; 

	/** 连乘优惠折扣率 Len:1 */ 
	Discount_t Rate; 

	/** 连乘优惠折扣金额 Len:4 */ 
	ValueCent_t Amt; 

}PARA_TICK_DISCOUNT_t; 

/**
 * 	声光报警参数
 * 	*/ 
typedef struct PARA_TICK_ALARM_t
{ 

	/** 显示灯编号 Len:1 */ 
	ConcessionalLampID_t ID; 

	/** 提示音编号 Len:1 */ 
	SoundDisplayID_t SoundID; 

}PARA_TICK_ALARM_t; 

/**
 * 	车票处理参数
 * 	*/ 
typedef struct PARA_TICK_PROCESS_t
{ 
	
	PARA_TICK_PENALTY_t PARA_TICK_PENALTY;
	
	PARA_TICK_DISCOUNT_t PARA_TICK_DISCOUNT;

	PARA_TICK_ALARM_t PARA_TICK_ALARM;

}PARA_TICK_PROCESS_t; 

typedef struct PARA_RECHARGE_1_C_t
{

	/** 计程票充值参数编码 Len:1 */ 
	AddValueCode_t Code; 

	/** 支付金额 Len:4 */ 
	ValueCent_t PayAmt; 

	/** 充值金额 Len:4 */ 
	ValueCent_t RechargeAmt; 

	/** 有效期天数 Len:2 */ 
	Duration_t Validity; 

}PARA_RECHARGE_1_C_t;

typedef struct PARA_RECHARGE_2_C_t
{

	/** 计次票充值参数编码 Len:1 */ 
	AddValueCode_t Code; 

	/** 支付金额 Len:4 */ 
	ValueCent_t PayAmt; 

	/** 充值次数 Len:2 */ 
	MultiRideNumber_t RechargeAmt; 

	/** 有效期天数 Len:2 */ 
	Duration_t Validity; 

}PARA_RECHARGE_2_C_t;

/**
 * 	充值参数编码
 * 	*/ 
typedef struct PARA_RECHARGE_t
{ 

	/** 循环体1数量 Len:1 */ 
	SmallQuantity_t Qty1; 
	
	//@LENNAME=Qty1.data.data
	PARA_RECHARGE_1_C_t* PARA_RECHARGE_1_C_val;

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	//@LENNAME=Qty2.data.data
	PARA_RECHARGE_2_C_t* PARA_RECHARGE_2_C_val;

}PARA_RECHARGE_t; 

/**
 * 	车票发售
 * 	*/ 
typedef struct PARA_TICK_SELL_t
{ 

	/** 循环体1数量 Len:2 */ 
	MiddleQuantity_t Qty1; 

	/** 车票类型编码 Len:2 */ 
	//@LENNAME=Qty1.data.data
	TicketType_t* Type1_val; 

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	/** 发售参数编码 Len:1 */ 
	//@LENNAME=Qty2.data.data
	AddValueCode_t* Type_val; 

}PARA_TICK_SELL_t; 

/**
 * 	车票充值
 * 	*/ 
typedef struct PARA_TICK_RECHARGE_t
{ 

	/** 循环体1数量 Len:2 */ 
	MiddleQuantity_t Qty1; 

	/** 车票类型编码 Len:2 */ 
	//@LENNAME=Qty1.data.data
	TicketType_t* Type1_val; 

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	/** 充值参数编码 Len:1 */
	//@LENNAME=Qty2.data.data
	AddValueCode_t* Type2_val; 

}PARA_TICK_RECHARGE_t; 

/**
 * 	车票限时
 * 	*/ 
typedef struct PARA_TICK_LIMIT_TIME_t
{ 

	/** 循环体1数量 Len:2 */ 
	MiddleQuantity_t Qty1; 

	/** 车票类型编码 Len:2 */ 
	//@LENNAME=Qty1.data.data
	TicketType_t* Type1_val; 

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	/** 时间段代码 Len:1 */ 
	//@LENNAME=Qty2.data.data
	U8_t* Type2_val; 

}PARA_TICK_LIMIT_TIME_t; 

/**
 * 	车票区域
 * 	*/ 
typedef struct PARA_TICK_ZONE_t
{ 

	/** 循环体1数量 Len:2 */ 
	MiddleQuantity_t Qty1; 

	/** 车票类型编码 Len:2 */ 
	TicketType_t Type; 

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	/** 限制使用区域代码 Len:1 */ 
	ZoneID_t ZoneID; 

}PARA_TICK_ZONE_t; 

/**
 * 	车票区段
 * 	*/ 
typedef struct PARA_TICK_SEGMENT_t
{ 

	/** 循环体1数量 Len:2 */ 
	MiddleQuantity_t Qty1; 

	/** 车票类型编码 Len:2 */ 
	TicketType_t Type; 

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	/** 限制使用区段代码 Len:1 */ 
	SegmentID_t SegmentID; 

}PARA_TICK_SEGMENT_t; 

/**
 * 	员工票乘车权限
 * 	*/ 
typedef struct PARA_TICK_AUTH_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty1; 

	/** 员工票类型编码 Len:2 */ 
	TicketType_t Type; 

	/** 员工票乘车权限编码 Len:1 */ 
	AuthorityType_t AuthType; 

}PARA_TICK_AUTH_t; 

/**
 * 	当日最大乘车次数
 * 	*/ 
typedef struct PARA_TICK_MAX_CNT_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** 车票类型编码 Len:2 */ 
	TicketType_t Type; 

	/** 当日最大乘车次数 Len:2 */ 
	MultiRideNumber_t Cnt; 

}PARA_TICK_MAX_CNT_t; 

/**
 * 	最大乘车里程等级
 * 	*/ 
typedef struct PARA_TICK_MAX_FARE_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** 车票类型编码 Len:2 */ 
	TicketType_t Type; 

	/** 最大乘车里程等级 Len:1 */ 
	FareRate_t Rate; 

}PARA_TICK_MAX_FARE_t; 

/**
 * 	积分方案
 * 	*/ 
typedef struct PARA_TICK_BOUNS_t
{ 

	/** 循环体数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 积分方案编码 Len:1 */ 
	BonusPointsID_t ID; 

	/** 积分方案名称 Len:20 */ 
	Name_t Name; 

	/** 积分值 Len:4 */ 
	Quantity_t Quantity; 

}PARA_TICK_BOUNS_t; 

/**
 * 	车票属性参数
 * 	*/ 
typedef struct PARA_TICK_ATTR_t
{ 

	PARA_RECHARGE_t PARA_RECHARGE;

	PARA_TICK_SELL_t PARA_TICK_SELL;

	PARA_TICK_RECHARGE_t PARA_TICK_RECHARGE;

	PARA_TICK_LIMIT_TIME_t PARA_TICK_LIMIT_TIME;

	PARA_TICK_ZONE_t PARA_TICK_ZONE;

	PARA_TICK_SEGMENT_t PARA_TICK_SEGMENT;

	PARA_TICK_AUTH_t PARA_TICK_AUTH;

	PARA_TICK_MAX_CNT_t PARA_TICK_MAX_CNT;

	PARA_TICK_MAX_FARE_t PARA_TICK_MAX_FARE;

	PARA_TICK_BOUNS_t PARA_TICK_BOUNS;

}PARA_TICK_ATTR_t; 

/**
 * 	ACC车票参数
 * 	*/ 
typedef struct PARA_ACC_EOD_Ticket_t
{ 

	PARA_TICK_PROCESS_t PARA_TICK_PROCESS;

	PARA_TICK_ATTR_t PARA_TICK_ATTR;

}PARA_ACC_EOD_Ticket_t; 



/**
 * 	黑名单参数
 * 	*/ 
typedef struct PARA_BLK_t
{ 

}PARA_BLK_t; 

/**
 * 	一卡通储值票逐条黑名单
 * 	*/ 
typedef struct PARA_BLK_YKT_RECORD_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** 黑名单卡号 Len:8 */ 
	TicketPhyID_t PhyID; 

	/** 锁卡原因 Len:1 */ 
	BlockCode_t Code; 

}PARA_BLK_YKT_RECORD_t; 

/**
 * 	一卡通储值票号段黑名单
 * 	*/ 
typedef struct PARA_BLK_YKT_SEGMENT_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** 开始黑名单卡号 Len:8 */ 
	TicketPhyID_t BeginID; 

	/** 结束黑名单卡号 Len:8 */ 
	TicketPhyID_t EndID; 

	/** 锁卡原因 Len:1 */ 
	BlockCode_t Code; 

}PARA_BLK_YKT_SEGMENT_t; 

/**
 * 	一票通逐条黑名单
 * 	*/ 
typedef struct PARA_BLK_YPT_RECORD_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** 黑名单卡号 Len:8 */ 
	TicketLogicalID_t ID; 

	/** 锁卡原因 Len:1 */ 
	BlockCode_t Code; 

}PARA_BLK_YPT_RECORD_t; 

/**
 * 	一票通号段黑名单
 * 	*/ 
typedef struct PARA_BLK_YPT_SEGMENT_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** 开始黑名单卡号 Len:8 */ 
	TicketLogicalID_t BeginDI; 

	/** 结束黑名单卡号 Len:8 */ 
	TicketLogicalID_t EndID; 

	/** 锁卡原因 Len:1 */ 
	BlockCode_t Code; 

}PARA_BLK_YPT_SEGMENT_t; 

/**
 * 	SAM卡黑名单
 * 	*/ 
typedef struct PARA_BLK_SAM_t
{ 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	/** SAM卡黑名单卡号 Len:8 */ 
	SAMID_t SAMID; 

	/** SAM卡类别 Len:1 */ 
	SAMType_t Type; 

}PARA_BLK_SAM_t; 

/**
 * 	灰名单
 * 	*/ 
typedef struct PARA_GRY_t
{ 

	/** 循环体1数量 Len:2 */ 
	MiddleQuantity_t Qty1; 

	/** 一卡通灰名单卡号 Len:8 */ 
	TicketPhyID_t PhyID; 

	/** 循环体2数量 Len:2 */ 
	MiddleQuantity_t Qty2; 

	/** 一票通灰名单卡号 Len:8 */ 
	TicketLogicalID_t LogicalID; 

}PARA_GRY_t; 

/**
 * 	一卡通全量黑名单
 * 	*/ 
typedef struct PARA_BLK_YKT_FULL_t
{ 

}PARA_BLK_YKT_FULL_t; 

/**
 * 	一卡通增量黑名单
 * 	*/ 
typedef struct PARA_BLK_YKT_INCR_t
{ 

}PARA_BLK_YKT_INCR_t; 

/**
 * 	一票通全量黑名单
 * 	*/ 
typedef struct PARA_BLK_ACC_FULL_t
{ 

}PARA_BLK_ACC_FULL_t; 

/**
 * 	一票通增量黑名单
 * 	*/ 
typedef struct PARA_BLK_ACC_INCR_t
{ 

}PARA_BLK_ACC_INCR_t; 

/**
 * 	设备全量黑名单
 * 	*/ 
typedef struct PARA_BLK_Dev_FULL_t
{ 

}PARA_BLK_Dev_FULL_t; 

/**
 * 	全量灰名单
 * 	*/ 
typedef struct PARA_GRY_FULL_t
{ 

}PARA_GRY_FULL_t; 


/**
 * 	设备通讯参数
 * 	*/ 
typedef struct PARA_DEV_COMM_t
{ 

	/** 通讯超时 Len:4 */ 
	MSecond_t Timeout; 

	/** 通信链路测试无报文上送时长 Len:4 */ 
	MSecond_t NoPacketTime; 

	/** ACC通讯IP地址 Len:4 */ 
	U32_t ACCIP; 

	/** ACC通讯端口 Len:2 */ 
	AddressPort_t ACCPort; 

	/** ACC备用通讯IP地址 Len:4 */ 
	U32_t ACCIP2; 

	/** ACC备用通讯端口 Len:2 */ 
	AddressPort_t ACCPort2; 

}PARA_DEV_COMM_t; 

/**
 * 	AGM显示灯参数
 * 	*/ 
typedef struct PARA_AGM_LED_t
{ 

	/** 循环体数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 显示灯编号 Len:1 */ 
	ConcessionalLampID_t ID; 

	/** 显示灯颜色编号 Len:1 */ 
	LampColorType_t Type; 

	/** 显示灯闪烁频率 Len:1 */ 
	HZ_t HZ1; 

	/** 显示灯闪烁时长 Len:4 */ 
	MSecond_t MSecond; 

}PARA_AGM_LED_t; 

/**
 * 	AGM提示音参数
 * 	*/ 
typedef struct PARA_AGM_AUDIT_t
{ 

	/** 循环体数量 Len:1 */ 
	SmallQuantity_t Qty; 

	/** 提示音编号 Len:1 */ 
	SoundDisplayID_t ID; 

	/** 提示音文件名 Len:100 */ 
	FileName_t FileName; 

	/** 数字摘要 Len:16 */ 
	MD5_t MD5; 

}PARA_AGM_AUDIT_t; 

/**
 * 	 ACC AGM设备参数
 * 	 */ 
typedef struct PARA_EOD_AGM_t
{ 

	PARA_AGM_LED_t PARA_AGM_LED;

	PARA_AGM_AUDIT_t PARA_AGM_AUDIT;

}PARA_EOD_AGM_t; 

typedef struct PARA_ACC_EOD_TVM_1_C_t
{

	/** 界面代码 Len:2 */ 
	TVMInterfaceID_t InterfaceCode; 

	/** 图形文件 Len:100 */ 
	FileName_t FileName; 

}PARA_ACC_EOD_TVM_1_C_t;


typedef struct PARA_ACC_EOD_TVM_2_C_t
{

	/** 按钮ID Len:1 */ 
	BtnID_t BtnID; 

	/** 按钮左上角X坐标 Len:4 */ 
	CoordinateUnit_t BtnLeftX; 

	/** 按钮左上角Y坐标 Len:4 */ 
	CoordinateUnit_t BtnLeftY; 

	/** 按钮宽度 Len:4 */ 
	CoordinateUnit_t BtnWidth; 

	/** 按钮高度 Len:4 */ 
	CoordinateUnit_t BtnHeight; 

}PARA_ACC_EOD_TVM_2_C_t;


typedef struct PARA_ACC_EOD_TVM_3_C_t
{

	/** 索引点代码 Len:1 */ 
	TVMPicIndex_t Index; 

	/** 索引点左上角X坐标 Len:4 */ 
	CoordinateUnit_t IndexLeftX; 

	/** 索引点左上角Y坐标 Len:4 */ 
	CoordinateUnit_t IndexLeftY; 

	/** 索引点宽度 Len:4 */ 
	CoordinateUnit_t IndexWidth; 

	/** 索引点高度 Len:4 */ 
	CoordinateUnit_t IndexHeight; 

	/** 索引内容类型 Len:1 */ 
	TVMIndexType_t IndexType; 

	/** 索引内容_界面 Len:2 */ 
	TVMInterfaceID_t IndexInterface; 

	/** 索引内容_站点 Len:2 */ 
	StationID_t IndexStation; 

}PARA_ACC_EOD_TVM_3_C_t;


/**
 * 	 ACC TVM界面参数
 * 	 */ 
typedef struct PARA_EOD_TVM_t
{ 

	/** 屏幕宽度 Len:4 */ 
	CoordinateUnit_t ScreenWidth; 

	/** 屏幕高度 Len:4 */ 
	CoordinateUnit_t ScreenHeight; 

	/** 循环体1数量 Len:2 */ 
	MiddleQuantity_t Qty1; 

	//@LENNAME=Qty1.data.data
	PARA_ACC_EOD_TVM_1_C_t* PARA_ACC_EOD_TVM_1_C_val;

	/** 循环体2数量 Len:1 */ 
	SmallQuantity_t Qty2; 

	//@LENNAME=Qty2.data.data
	PARA_ACC_EOD_TVM_2_C_t* PARA_ACC_EOD_TVM_2_C_val;

	/** 循环体3数量 Len:1 */ 
	SmallQuantity_t Qty3; 

	//@LENNAME=Qty3.data.data
	PARA_ACC_EOD_TVM_3_C_t* PARA_ACC_EOD_TVM_3_C_val;

}PARA_EOD_TVM_t; 

/**
 * 	ACC BOM设备参数
 * 	*/ 
typedef struct PARA_EOD_BOM_t
{ 

}PARA_EOD_BOM_t; 

/**
 * 	ACC 通用设备参数
 * 	*/ 
typedef struct PARA_ACC_EOD_DEV_t
{ 

	PARA_DEV_COMM_t PARA_DEV_COMM;

	PARA_EOD_AGM_t PARA_EOD_AGM;

	PARA_EOD_TVM_t PARA_EOD_TVM;

	PARA_EOD_BOM_t PARA_EOD_BOM;

}PARA_ACC_EOD_DEV_t; 

typedef struct PARA_EOD_PARA_1_C_t
{

	/** 图形文件名1 Len:100 */ 
	FileName_t Name; 

	/** 图形文件1签名 Len:16 */ 
	MD5_t MD5; 

}PARA_EOD_PARA_1_C_t;

typedef struct PARA_EOD_PARA_2_C_t
{

	/** 声音文件名1 Len:100 */ 
	FileName_t Name; 

	/** 声音文件1签名 Len:16 */ 
	MD5_t MD5; 

}PARA_EOD_PARA_2_C_t;

/**
 * 	EOD参数文件主控
 * 	*/ 
typedef struct PARA_EOD_PARA_t
{ 

	/** 文件生成时间 Len:4 */ 
	TimeStamp_t Time; 

	/** 生效起始时间 Len:4 */ 
	TimeStamp_t Time1; 

	/** 参数类型 Len:1 */ 
	ParamType_t Type1; 

	/** 文件名 Len:100 */ 
	FileName_t Name1; 

	/** 版本号 Len:2 */ 
	VersionID_t Ver1; 

	/** 文件签名 Len:16 */ 
	MD5_t MD51; 

	/** 参数类型 Len:1 */ 
	ParamType_t Type2; 

	/** 文件名 Len:100 */ 
	FileName_t Name2; 

	/** 版本号 Len:2 */ 
	VersionID_t Ver2; 

	/** 生效起始时间 Len:4 */ 
	TimeStamp_t Time2; 

	/** 文件签名 Len:16 */ 
	MD5_t MD52; 

	/** 参数类型 Len:1 */ 
	ParamType_t Type3; 

	/** 文件名 Len:100 */ 
	FileName_t Name3; 

	/** 版本号 Len:2 */ 
	VersionID_t Ver3; 

	/** 生效起始时间 Len:4 */ 
	TimeStamp_t Time3; 

	/** 文件签名 Len:16 */ 
	MD5_t MD53; 

	/** 循环体1数量 Len:4 */ 
	Quantity_t Qty1; 

	//@LENNAME=Qty1.data.data
	PARA_EOD_PARA_1_C_t* PARA_EOD_PARA_1_C_val;

	/** 循环体2数量 Len:4 */ 
	Quantity_t Qty2; 

	//@LENNAME=Qty2.data.data
	PARA_EOD_PARA_2_C_t* PARA_EOD_PARA_2_C_val;

}PARA_EOD_PARA_t; 

/**
 * 	模式履历主控
 * 	*/ 
typedef struct PARA_EOD_MODE_t
{ 

	/** 文件生成时间 Len:4 */ 
	TimeStamp_t Time; 

	/** 参数类型 Len:1 */ 
	ParamType_t Type; 

	/** 文件名 Len:100 */ 
	FileName_t Name; 

	/** 版本号 Len:2 */ 
	VersionID_t Ver; 

	/** 生效起始时间 Len:4 */ 
	TimeStamp_t ActiveTime; 

	/** 文件签名 Len:16 */ 
	MD5_t FileMD5; 

	/** 文件签名 Len:16 */ 
	MD5_t EODMD5; 

}PARA_EOD_MODE_t; 

/**
 * 	黑名单主控
 * 	*/ 
typedef struct PARA_EOD_BLK_t
{ 

	/** 文件生成时间 Len:4 */ 
	TimeStamp_t Time; 

	/** 参数类型 Len:1 */ 
	ParamType_t Type; 

	/** 是否有此文件 Len:1 */ 
	Boolean_t IfExist1; 

	/** 文件名 Len:100 */ 
	FileName_t Name1; 

	/** 版本号 Len:2 */ 
	VersionID_t Ver1; 

	/** 生效起始时间 Len:4 */ 
	TimeStamp_t ActiveTime1; 

	/** 文件签名 Len:16 */ 
	MD5_t MD51; 

	/** 是否有此文件 Len:1 */ 
	Boolean_t IfExist2; 

	/** 文件名 Len:100 */ 
	FileName_t Name2; 

	/** 版本号 Len:2 */ 
	VersionID_t Ver2; 

	/** 生效起始时间 Len:4 */ 
	TimeStamp_t ActiveTime2; 

	/** 文件签名 Len:16 */ 
	MD5_t MD52; 

	/** 文件签名 Len:16 */ 
	MD5_t EODMD5; 

}PARA_EOD_BLK_t; 

typedef struct PARA_EOD_TP_C_t
{

	/** 类型号 Len:2 */ 
	MiddleQuantity_t Type; 

	/** 文件名 Len:100 */ 
	FileName_t Name; 

	/** 文件签名 Len:16 */ 
	MD5_t MD5; 

}PARA_EOD_TP_C_t;

/**
 * 	TP主控
 * 	*/ 
typedef struct PARA_EOD_TP_t
{ 

	/** 文件生成时间 Len:4 */ 
	TimeStamp_t Time; 

	/** 参数类型 Len:1 */ 
	ParamType_t Type; 

	/** 版本号 Len:2 */ 
	VersionID_t Ver; 

	/** 生效起始时间 Len:4 */ 
	TimeStamp_t ActiveTime; 

	/** 循环体数量 Len:2 */ 
	MiddleQuantity_t Qty; 

	//@LENNAME=Qty.data.data
	PARA_EOD_TP_C_t* PARA_EOD_TP_C_val;

	/** 文件签名 Len:16 */ 
	MD5_t EODMD5; 

}PARA_EOD_TP_t; 

/**
 * 	版本控制文件
 * 	*/ 
typedef struct PARA_EOD_t
{ 
	/** 文件类型 Len:2 */ 
	FileType_t FileType; 

	/** 参数类型 Len:1 */ 
	ParamType_t Type; 

	/** 文件生成时间 Len:4 */ 
	TimeStamp_t Timeout; 

	//@SWITCH=value->Type.data.data
	union
	{
		// /** ACC EOD参数 */ 
		// //@CASE=1
		// PARA_EOD_t PARA_EOD; 
		
		/** 服务商参数 */ 
		//@CASE=2
		PARA_ACC_EOD_Server_t PARA_ACC_EOD_Server; 
		
		/** 网络拓扑参数 */ 
		//@CASE=3
		PARA_ACC_EOD_NetworkTopo_t PARA_ACC_EOD_NetworkTopo; 
		
		/** 日历时间参数 */ 
		//@CASE=4
		PARA_ACC_EOD_Calendar_t PARA_ACC_EOD_Calendar; 
		
		/** 介质票卡参数 */ 
		//@CASE=5
		PARA_ACC_EOD_MediaCard_t PARA_ACC_EOD_MediaCard; 
		
		/** 清分规则 */ 
		//@CASE=6
		PARA_ACC_EOD_ClearingRule_t PARA_ACC_EOD_ClearingRule; 
		
		/** 费率表参数 */ 
		//@CASE=7
		PARA_ACC_EOD_Fare_t PARA_ACC_EOD_Fare; 
		
		/** 车票参数 */ 
		//@CASE=8
		PARA_ACC_EOD_Ticket_t PARA_ACC_EOD_Ticket; 
		
		/** 通用设备参数 */ 
		//@CASE=51
		PARA_ACC_EOD_DEV_t PARA_ACC_EOD_DEV; 
		
		/** ACC AGM设备参数 */ 
		//@CASE=52
		PARA_EOD_AGM_t PARA_EOD_AGM; 
		
		/** ACC TVM设备参数 */ 
		//@CASE=53
		PARA_EOD_TVM_t PARA_EOD_TVM; 
		
		/** ACC BOM设备参数 */ 
		//@CASE=54
		PARA_EOD_BOM_t PARA_EOD_BOM; 
		
		/** 模式履历参数 */ 
		//@CASE=61
		PARA_EOD_MODE_t PARA_EOD_MODE; 
		
		/** 黑名单（含灰名单）参数 */ 
		//@CASE=71
		PARA_EOD_BLK_t PARA_EOD_BLK; 
		
		/** TP */ 
		//@CASE=81
		PARA_EOD_TP_t PARA_EOD_TP; 
		
		
	}body_u;

	/** 签名 Len:16 */ 
	MD5_t MD5; 

}PARA_EOD_t; 


typedef struct MainEODStu_t{
	//参数类型（1B)
	uint8_t ParaType;
	//文件名（100B)  注：不带目录名
	fixstring_t EODName[101];
	//文件版本号(2B)
	uint16_t MainEODVer;
	uint32_t ActiveTime;
	//MD5文件签名（16B）
	fixstring_t md5[17];
}MainEODStu_t;

typedef struct ParaPic_t{
	//图形文件名n（100B)
	fixstring_t fileName[101];
	//图形文件n签名（16B）
	fixstring_t md5[17];
}ParaPic_t;


typedef struct ParaSound_t{
	//声音文件名m（100B)
	fixstring_t fileName[101];
	//声音文件m签名(16B)
	fixstring_t md5[17];
}ParaSound_t;


typedef struct ParaMainConfigure_t{
	//part1
	uint16_t fileType;//2
	uint32_t editTimeStamp;
	uint32_t activeTimeStamp;
	//part2
	uint16_t component_cnt;
	//@LENNAME=component_cnt
	MainEODStu_t  *component_val;
	//part3
	uint32_t pic_cnt;
	//@LENNAME=pic_cnt
	ParaPic_t *pic_val;

	//part4
	uint32_t sound_cnt;
	//@LENNAME=sound_cnt
	ParaSound_t *sound_val;
}ParaMainConfigure_t;

int adp_PARA_ACC_EOD_Server_t(ADP* adp,PARA_ACC_EOD_Server_t* value);
int adp_PARA_LINE_STATION_DETAIL_t(ADP* adp,PARA_LINE_STATION_DETAIL_t* value);
int adp_PARA_LINE_STATION_t(ADP* adp,PARA_LINE_STATION_t* value);
int adp_PARA_LINE_EXT_t(ADP* adp,PARA_LINE_EXT_t* value);
int adp_PARA_STATION_EXT_t(ADP* adp,PARA_STATION_EXT_t* value);
int adp_PARA_ZONE_DETAIL_t(ADP* adp,PARA_ZONE_DETAIL_t* value);
int adp_PARA_ZONE_t(ADP* adp,PARA_ZONE_t* value);
int adp_PARA_SEGMENT_t(ADP* adp,PARA_SEGMENT_t* value);
int adp_PARA_TRANSFER_STATION_t(ADP* adp,PARA_TRANSFER_STATION_t* value);
int adp_PARA_ACC_EOD_NetworkTopo_t(ADP* adp,PARA_ACC_EOD_NetworkTopo_t* value);
int adp_PARA_DURATION_t(ADP* adp,PARA_DURATION_t* value);
int adp_PARA_SPECIAL_DATE_t(ADP* adp,PARA_SPECIAL_DATE_t* value);
int adp_PARA_TIME_ZONE_t(ADP* adp,PARA_TIME_ZONE_t* value);
int adp_PARA_RUN_DATE_t(ADP* adp,PARA_RUN_DATE_t* value);
int adp_PARA_RUN_TIME_t(ADP* adp,PARA_RUN_TIME_t* value);
int adp_PARA_TIME_INTERVAL_UP_t(ADP* adp,PARA_TIME_INTERVAL_UP_t* value);
int adp_PARA_TIME_INTERVAL_QUERY_t(ADP* adp,PARA_TIME_INTERVAL_QUERY_t* value);
int adp_PARA_TIME_INTERVAL_DOWN_t(ADP* adp,PARA_TIME_INTERVAL_DOWN_t* value);
int adp_PARA_TIME_INTERVAL_BLACK_t(ADP* adp,PARA_TIME_INTERVAL_BLACK_t* value);
int adp_PARA_TIME_INTERVAL_DEV_AUTH_t(ADP* adp,PARA_TIME_INTERVAL_DEV_AUTH_t* value);
int adp_PARA_TIME_INTERVAL_STATU_QUERY_t(ADP* adp,PARA_TIME_INTERVAL_STATU_QUERY_t* value);
int adp_PARA_TIME_INTERVAL_STATISTICS_t(ADP* adp,PARA_TIME_INTERVAL_STATISTICS_t* value);
int adp_PARA_TIME_INTERVAL_MAX_INSTATION_t(ADP* adp,PARA_TIME_INTERVAL_MAX_INSTATION_t* value);
int adp_PARA_TIME_INTERVAL_NOINS_RETURN_t(ADP* adp,PARA_TIME_INTERVAL_NOINS_RETURN_t* value);
int adp_PARA_TIME_INTERVAL_TICK_REPORT_t(ADP* adp,PARA_TIME_INTERVAL_TICK_REPORT_t* value);
int adp_PARA_TIME_NTP_DIFF_t(ADP* adp,PARA_TIME_NTP_DIFF_t* value);
int adp_PARA_ACC_EOD_Calendar_t(ADP* adp,PARA_ACC_EOD_Calendar_t* value);
int adp_PARA_ACC_WaiverDateC_t(ADP* adp,PARA_ACC_WaiverDateC_t* value);
int adp_PARA_ACC_WaiverDate_t(ADP* adp,PARA_ACC_WaiverDate_t* value);
int adp_PARA_CHIP_TYPE_t(ADP* adp,PARA_CHIP_TYPE_t* value);
int adp_PARA_CHIP_TYPE_EXT_t(ADP* adp,PARA_CHIP_TYPE_EXT_t* value);
int adp_PARA_TICKET_FAMILY_t(ADP* adp,PARA_TICKET_FAMILY_t* value);
int adp_PARA_TICKET_FAMILY_EXT_t(ADP* adp,PARA_TICKET_FAMILY_EXT_t* value);
int adp_PARA_TICKET_TYPE_t(ADP* adp,PARA_TICKET_TYPE_t* value);
int adp_PARA_TICKET_TYPE_EXT_t(ADP* adp,PARA_TICKET_TYPE_EXT_t* value);
int adp_PARA_TICKET_VALIDDATE_t(ADP* adp,PARA_TICKET_VALIDDATE_t* value);
int adp_PARA_TICKET_FAVOUR_t(ADP* adp,PARA_TICKET_FAVOUR_t* value);
int adp_PARA_ACC_EOD_MediaCard_t(ADP* adp,PARA_ACC_EOD_MediaCard_t* value);
int adp_PARA_ACC_EOD_ClearingRule_t(ADP* adp,PARA_ACC_EOD_ClearingRule_t* value);
int adp_PARA_PAY_ATTR_t(ADP* adp,PARA_PAY_ATTR_t* value);
int adp_PARA_FARE_TYPE_t(ADP* adp,PARA_FARE_TYPE_t* value);
int adp_PARA_FARE_LEVEL_t(ADP* adp,PARA_FARE_LEVEL_t* value);
int adp_PARA_FARE_TYPE_GROUP_t(ADP* adp,PARA_FARE_TYPE_GROUP_t* value);
int adp_PARA_FARE_TBL_t(ADP* adp,PARA_FARE_TBL_t* value);
int adp_PARA_FARE_TIME_t(ADP* adp,PARA_FARE_TIME_t* value);
int adp_PARA_FARE_OTHER_t(ADP* adp,PARA_FARE_OTHER_t* value);
int adp_PARA_ACC_EOD_Fare_t(ADP* adp,PARA_ACC_EOD_Fare_t* value);
int adp_PARA_TICK_PENALTY_t(ADP* adp,PARA_TICK_PENALTY_t* value);
int adp_PARA_TICK_DISCOUNT_t(ADP* adp,PARA_TICK_DISCOUNT_t* value);
int adp_PARA_TICK_ALARM_t(ADP* adp,PARA_TICK_ALARM_t* value);
int adp_PARA_TICK_PROCESS_t(ADP* adp,PARA_TICK_PROCESS_t* value);
int adp_PARA_RECHARGE_1_C_t(ADP* adp,PARA_RECHARGE_1_C_t* value);
int adp_PARA_RECHARGE_2_C_t(ADP* adp,PARA_RECHARGE_2_C_t* value);
int adp_PARA_RECHARGE_t(ADP* adp,PARA_RECHARGE_t* value);
int adp_PARA_TICK_SELL_t(ADP* adp,PARA_TICK_SELL_t* value);
int adp_PARA_TICK_RECHARGE_t(ADP* adp,PARA_TICK_RECHARGE_t* value);
int adp_PARA_TICK_LIMIT_TIME_t(ADP* adp,PARA_TICK_LIMIT_TIME_t* value);
int adp_PARA_TICK_ZONE_t(ADP* adp,PARA_TICK_ZONE_t* value);
int adp_PARA_TICK_SEGMENT_t(ADP* adp,PARA_TICK_SEGMENT_t* value);
int adp_PARA_TICK_AUTH_t(ADP* adp,PARA_TICK_AUTH_t* value);
int adp_PARA_TICK_MAX_CNT_t(ADP* adp,PARA_TICK_MAX_CNT_t* value);
int adp_PARA_TICK_MAX_FARE_t(ADP* adp,PARA_TICK_MAX_FARE_t* value);
int adp_PARA_TICK_BOUNS_t(ADP* adp,PARA_TICK_BOUNS_t* value);
int adp_PARA_TICK_ATTR_t(ADP* adp,PARA_TICK_ATTR_t* value);
int adp_PARA_ACC_EOD_Ticket_t(ADP* adp,PARA_ACC_EOD_Ticket_t* value);
int adp_PARA_BLK_t(ADP* adp,PARA_BLK_t* value);
int adp_PARA_BLK_YKT_RECORD_t(ADP* adp,PARA_BLK_YKT_RECORD_t* value);
int adp_PARA_BLK_YKT_SEGMENT_t(ADP* adp,PARA_BLK_YKT_SEGMENT_t* value);
int adp_PARA_BLK_YPT_RECORD_t(ADP* adp,PARA_BLK_YPT_RECORD_t* value);
int adp_PARA_BLK_YPT_SEGMENT_t(ADP* adp,PARA_BLK_YPT_SEGMENT_t* value);
int adp_PARA_BLK_SAM_t(ADP* adp,PARA_BLK_SAM_t* value);
int adp_PARA_GRY_t(ADP* adp,PARA_GRY_t* value);
int adp_PARA_BLK_YKT_FULL_t(ADP* adp,PARA_BLK_YKT_FULL_t* value);
int adp_PARA_BLK_YKT_INCR_t(ADP* adp,PARA_BLK_YKT_INCR_t* value);
int adp_PARA_BLK_ACC_FULL_t(ADP* adp,PARA_BLK_ACC_FULL_t* value);
int adp_PARA_BLK_ACC_INCR_t(ADP* adp,PARA_BLK_ACC_INCR_t* value);
int adp_PARA_BLK_Dev_FULL_t(ADP* adp,PARA_BLK_Dev_FULL_t* value);
int adp_PARA_GRY_FULL_t(ADP* adp,PARA_GRY_FULL_t* value);
int adp_PARA_DEV_COMM_t(ADP* adp,PARA_DEV_COMM_t* value);
int adp_PARA_AGM_LED_t(ADP* adp,PARA_AGM_LED_t* value);
int adp_PARA_AGM_AUDIT_t(ADP* adp,PARA_AGM_AUDIT_t* value);
int adp_PARA_EOD_AGM_t(ADP* adp,PARA_EOD_AGM_t* value);
int adp_PARA_ACC_EOD_TVM_1_C_t(ADP* adp,PARA_ACC_EOD_TVM_1_C_t* value);
int adp_PARA_ACC_EOD_TVM_2_C_t(ADP* adp,PARA_ACC_EOD_TVM_2_C_t* value);
int adp_PARA_ACC_EOD_TVM_3_C_t(ADP* adp,PARA_ACC_EOD_TVM_3_C_t* value);
int adp_PARA_EOD_TVM_t(ADP* adp,PARA_EOD_TVM_t* value);
int adp_PARA_EOD_BOM_t(ADP* adp,PARA_EOD_BOM_t* value);
int adp_PARA_ACC_EOD_DEV_t(ADP* adp,PARA_ACC_EOD_DEV_t* value);
int adp_PARA_EOD_PARA_1_C_t(ADP* adp,PARA_EOD_PARA_1_C_t* value);
int adp_PARA_EOD_PARA_2_C_t(ADP* adp,PARA_EOD_PARA_2_C_t* value);
int adp_PARA_EOD_PARA_t(ADP* adp,PARA_EOD_PARA_t* value);
int adp_PARA_EOD_MODE_t(ADP* adp,PARA_EOD_MODE_t* value);
int adp_PARA_EOD_BLK_t(ADP* adp,PARA_EOD_BLK_t* value);
int adp_PARA_EOD_TP_C_t(ADP* adp,PARA_EOD_TP_C_t* value);
int adp_PARA_EOD_TP_t(ADP* adp,PARA_EOD_TP_t* value);
int adp_PARA_EOD_t(ADP* adp,PARA_EOD_t* value);
int adp_MainEODStu_t(ADP* adp,MainEODStu_t* value);
int adp_ParaPic_t(ADP* adp,ParaPic_t* value);
int adp_ParaSound_t(ADP* adp,ParaSound_t* value);
int adp_ParaMainConfigure_t(ADP* adp,ParaMainConfigure_t* value);
#ifdef __cplusplus
}
#endif
#endif
