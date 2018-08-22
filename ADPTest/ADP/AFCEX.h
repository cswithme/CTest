/****************
*File:AFCEX.h
*Time:20180710 092435
*Note:
*		1.以//@开头的行为标注,不可删除
*		2.建议使用单行注释
****************/
#ifndef _H_AFCEX_
#define _H_AFCEX_
#include "AFCDataPackComm.h"
#ifdef __cplusplus
extern "C"  {
#endif
//@BYTESEQ=BO_MOTO
//1 :not 4 bytes , 4:4 bytes
//@4BYTE=1
//0:定长 1：变长
//@LENTYPE=0
/**
  包头结构 34B
  */
typedef struct CssHeader_t
{
	/*消息长度:(不包含长度域本身大小)*/
	uint32_t MsgLen;
	/*发起方节点*/
	fixstring_t Sender[11];
	/*消息时间*/
	bcd_t Time[15];
	/*消息版本 默认0*/
	uint8_t Ver;
	/*消息流水*/
	uint32_t MSN;
	/*交易日期*/
	//bcd_t TranDate[9]; 
	/*交易序号*/
	uint32_t TranSeq;
	//CRC
	uint32_t CRC;
}CssHeader_t;

typedef struct DevList_t
{
	/*设备ID*/
	fixstring_t DeviceID[11];
	/*设备IP add20160715*/
	uint32_t 	DevIP;
}DevList_t;

typedef struct StationList_t
{
	/*车站ID*/
	fixstring_t StationID[5];
}StationList_t;

typedef struct DevRange_t
{
	/*响应方标识 0:ALL 1:按设备类型 2:指定设备 3:车站*/
	uint8_t Type;
	/*设备类型 Type为1时有效*/
	fixstring_t DevType[3];
	/*车站个数 Type不为0时有效*/
	uint16_t StationList_Cnt;
	//@LENNAME=StationList_Cnt
	StationList_t* StationList;
	/*设备个数 Type为2时有效*/
	uint16_t DevList_Cnt;
	//@LENNAME=DevList_Cnt
	DevList_t* DevList;
}DevRange_t;

typedef struct FileSeqList_t
{
	/*文件流水号*/
	uint16_t FileSeq;
	/*设备范围*/
	DevRange_t DevRange;
}FileSeqList_t;

typedef struct TranRange_t
{
	/*起始交易流水号*/
	uint32_t TranBegin;
	/*截止交易流水号*/
	uint32_t TranEnd;
	/*设备范围*/
	DevRange_t DevRange;
}TranRange_t;


/**
 * 参数信息
 */
typedef struct ParaInfo_t
{
	/*参数类型*/
	fixstring_t ParaType[5];
	/*参数版本类型 1:当前版 2:将来版*/
	uint8_t ParaVerType;
	/*参数版本*/
	fixstring_t ParaVer[21];
	/*生效时间*/
	bcd_t ParaActiveTime[15];
	/*参数文件*/
	fixstring_t ParaFile[41];
	/*处理结果 版本上报时有效 0:成功 1:失败*/
	uint8_t Result;
}ParaInfo_t;

typedef struct ParaList_t
{
	/*参数类型*/
	fixstring_t ParaType[5];
}ParaList_t;

/**
 * 状态信息
 */
typedef struct StatusInfo_t
{
	/*状态ID*/
	fixstring_t StatusID[5];
	/*status value*/
	fixstring_t StatusValue[3];
}StatusInfo_t;

/**
  登录请求(0101)
  */
typedef struct LoginReq_t
{
	/*设备ID*/
	fixstring_t DevID[11];
	/*操作员ID*/
	fixstring_t OperID[11];
	/*密码 操作员ID+操作员密码明文进行MD5加密*/
	block_t PassWd[16];
}LoginReq_t;

/**
  登录/登出通知(0102)
  */
typedef struct LoginNotice_t
{
	/*设备ID*/
	fixstring_t DevID[11];
	/*操作员ID*/
	fixstring_t OperID[11];
	/*登录类型 0:登录 1:登出*/
	uint8_t LoginType;
}LoginNotice_t;

/**
  密码更新通知/广播(0103)
  */
typedef struct PassWdInfo_t
{
	/*操作员ID*/
	fixstring_t OperID[11];
	/*旧密码 操作员ID+操作员密码明文进行MD5加密*/
	block_t PassWdOld[16];
	/*新密码 操作员ID+操作员密码明文进行MD5加密*/
	block_t PassWdNew[16];
	/*执行修改的操作员ID*/
	fixstring_t ModOperID[11];
}PassWdInfo_t;

/**
  操作员登录控制命令(0104)
 */
typedef struct LoginCtl_t
{
	/*命令值*/
	uint16_t Value;
	/*操作时间*/
	bcd_t OperTime[15];
	/*命令源*/
	fixstring_t Source[2];
	/*下发命令操作员*/
	fixstring_t OperID[11];
	/*设备ID*/
	fixstring_t DevID[11];
	/*接收命令操作员*/
	fixstring_t RecvOperID[11];
}LoginCtl_t;

/**
  操作员锁定解锁通知(0105)
 */
typedef struct OperLock_t
{
	/*命令值*/
	uint16_t Value;
	/*操作时间*/
	bcd_t OperTime[15];
	/*命令源*/
	fixstring_t Source[2];
	/*下发命令操作员*/
	fixstring_t OperID[11];
	/*接收命令操作员*/
	fixstring_t RecvOperID[11];
}OperLock_t;
/**
  登录验证结果(0111)
  */
typedef struct LoginResult_t
{
	/*设备ID*/
	fixstring_t DevID[11];
	/*操作员ID*/
	fixstring_t OperID[11];
	/*登录验证结果*/
	uint8_t Result;
}LoginResult_t;

/**
  模式命令
  */
typedef struct ModeInfo_t
{
	/*命令源 0:SC 1:LC 2:ACC 3:WS 4:FAS*/
	fixstring_t ModeSetters[2];
	/*操作员ID，无操作员为NULL*/
	fixstring_t OperID[11];
	/*模式车站*/
	fixstring_t StationID[5];
	/*模式代码*/
	uint16_t Code;
	/*模式时间*/
	bcd_t Time[15];
	/*原模式代码*/
	uint16_t CodeOri;
}ModeInfo_t;

/**
  模式查询(0703)
  */
typedef struct ModeQuery_t
{
	/*循环体数量*/
	uint16_t StationList_Cnt;
	//@LENNAME=StationList_Cnt
	StationList_t* StationList;
}ModeQuery_t;

/**
  模式通知/广播(0701)
  */
typedef struct ModeNotice_t
{
	/*模式消息类型 0:通知 1:广播*/
	uint8_t Type;
	/*循环体数量*/
	uint16_t ModeInfo_Cnt;
	//@LENNAME=ModeInfo_Cnt
	ModeInfo_t* ModeInfo;
}ModeNotice_t;

/**
  参数发布(0201)
  */
typedef struct ParaPublish_t
{
	/*参数发布类型，0:仅发布，1:发布后即时同步*/
	uint8_t Type;
	/*循环体数量*/
	uint16_t ParaList_Cnt;
	//@LENNAME=ParaList_Cnt
	ParaList_t* ParaList_val;
}ParaPublish_t;
/**
  参数差异(0202)
  */
typedef struct ParaSync_t
{
	/*目的节点*/
	fixstring_t DevID[11];
	/*参数差异类型 0:普通 1:指定 2:取消指定 3:强制 4:手动*/
	uint8_t Type;
	/*循环体数量*/
	uint16_t ParaInfo_Cnt;
	//@LENNAME=ParaInfo_Cnt
	ParaInfo_t* ParaInfo_val;
	/*设备范围 droped since 20180710*/
	//DevRange_t DevRange;
}ParaSync_t;

/**
  参数报告(0204)
  */
typedef struct ParaReport_t
{
	/*设备ID*/
	fixstring_t DevID[11];
	/*报告类型 0:普通同步 1:强制同步 2:报告 3:查询反馈 4:参数下载*/
	uint8_t Type;
	/*循环体数量*/
	uint16_t ParaInfo_Cnt;
	//@LENNAME=ParaInfo_Cnt
	ParaInfo_t* ParaInfo_val;
}ParaReport_t;

typedef struct PartParaInfo_t
{
	/*部件ID*/
	fixstring_t PartID[5];
	/*部件主版本*/
	fixstring_t PartMainVer[21];
	/*部件子版本*/
	fixstring_t PartSubVer[21];
}PartParaInfo_t;

/**
  部件版本通知(0205)
 */
typedef struct PartParaReport_t
{
	/*设备ID*/
	fixstring_t DeviceID[11];
	/*循环体数量*/
	uint16_t PartParaInfo_Cnt;
	/*循环体*/
	//@LENNAME=PartParaInfo_Cnt
	PartParaInfo_t* PartParaInfo_val;
}PartParaReport_t;

/**
  读卡器参数版本信息
 */
typedef struct TPUPara_t
{
	/*参数类型*/
	fixstring_t ParaType[5];
	/*参数版本*/
	fixstring_t ParaVer[21];
}TPUPara_t;

/**
  读卡器参数版本
 */
typedef struct TPUParaInfo_t
{
	/*读卡器ID*/
	uint8_t CardReaderID;
	/*参数类型循环体数量*/
	uint16_t TPUPara_Cnt;
	/*参数类型循环体*/
	//@LENNAME=TPUPara_Cnt
	TPUPara_t* TPUPara_val;
}TPUParaInfo_t;

/**
  读卡器参数版本通知(0206)
 */
typedef struct TPUParaReport_t
{
	/*设备ID*/
	fixstring_t DeviceID[11];
	/*读卡器参数版本信息循环体数量*/
	uint16_t TPUParaInfo_Cnt;
	/*读卡器参数版本信息循环体*/
	//@LENNAME=TPUParaInfo_Cnt
	TPUParaInfo_t* TPUParaInfo_val;
}TPUParaReport_t;

/**
  PSAM卡信息
*/
typedef struct PSAMCardInfo_t{
	/**PSAM卡所在卡槽号*/
	uint8_t SlotNum;
	/**旧PSAM卡编号*/
	fixstring_t OLD_PSAMCardNO[13];
	/**旧PSAM卡类型*/
	uint8_t OLD_PSAMType;
	/**新PSAM卡编号*/
	fixstring_t NEW_PSAMCardNO[13];
	/**新PSAM卡类型*/
	uint8_t NEW_PSAMType;
}PSAMCardInfo_t;

/**
  CRW信息
 */
typedef struct CRWInfo_t
{
	/**CRW位置*/
	uint8_t ReaderLoc;
	/**旧CRW编号*/
	uint16_t OLD_CRWNO;
	/**新CRW编号*/
	uint16_t NEW_CRWNO;
	/**PSAM卡信息循环体长度*/
	uint16_t PSAMCardInfo_len;
	/**PSAM卡信息*/
	//@LENNAME=PSAMCardInfo_len
	PSAMCardInfo_t* PSAMCardInfo_val;
}CRWInfo_t;

/**
  SAM卡信息上报(0207)
 */
typedef struct SAMCardInfoReport_t
{
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**车站编码*/
	fixstring_t Station[5];
	/**操作员ID*/
	//fixstring_t OperatorID[11];
	/**CRW记录数*/
	uint16_t CRWInfo_len;
	/**CRW信息循环体*/
	//@LENNAME=CRWInfo_len
	CRWInfo_t* CRWInfo_val;
}SAMCardInfoReport_t;

/**
  文件确认(0406)
  */
typedef struct FileVerify_t
{
	/*文件类型*/
	uint16_t FileType;
	/*文件名*/
	fixstring_t FileName[51];
	/*处理结果 0:成功 1:失败 2:重复 3:文件不存在 4:MD5校验错误 5:文件格式错误 6:文件记录数错误*/
	uint8_t Result;
}FileVerify_t;

/**
  文件通知(0411)
  */
typedef struct FileNotice_t
{
	/*文件类型*/
	uint16_t FileType;
	/*文件名*/
	fixstring_t FileName[51];
	/*MD5值*/
	block_t MD5[16];
}FileNotice_t;

/**
  数据导入/导出(0421)
  */
typedef struct DataImport_t
{
	/*指定类型0:所有文件 1:指定文件类型*/
	uint8_t ImportType;
	/*文件类型*/
	fixstring_t ImportPath[129];
}DataImport_t;

/**
  上传指定文件(0422)
  */
typedef struct FileSpecify_t
{
	/*指定类型0:所有文件 1:指定文件类型*/
	uint8_t Type;
	/*文件类型*/
	uint16_t FileType;
	/*交易日期*/
	bcd_t TranDate[9];
	/*循环体数*/
	uint16_t FileSeqList_Cnt;
	//@LENNAME=FileSeqList_Cnt
	FileSeqList_t* FileSeqList;
}FileSpecify_t;
/**
  上传指定交易(0423)
  */
typedef struct TranSpecify_t
{
	/*文件类型*/
	uint16_t FileType;
	/*交易日期*/
	bcd_t TranDate[9];
	/*循环体数 0为所有交易*/
	uint16_t TranRange_Cnt;
	//@LENNAME=TranRange_Cnt
	TranRange_t* TranRange;
}TranSpecify_t;

/**
  运营配置信息(0601)
  */
typedef struct DevRunCfg_t
{
	/*设备ID*/
	fixstring_t DeviceID[11];
	/*设备类型*/
	uint8_t DeviceType;
	/*设备子类型*/
	uint8_t DeviceSubType;
	/*线路ID*/
	fixstring_t LineID[3];
	/*车站ID*/
	fixstring_t StationID[5];
	/*模式代码*/
	uint16_t Code;
	/*FTP server IP*/
	fixstring_t FtpServerIP[17];
	/*FTP User*/
	fixstring_t FtpUser[33];
	/*FTP Passwd*/
	fixstring_t FtpPasswd[17];
	/*是否24小时运营*/
	uint16_t Run24Hour;
	/*延长运营时间*/
	uint16_t RunExtend;
}DevRunCfg_t;

/**
  存活包(0602)
  */
typedef struct LinkLive_t
{
	/*设备ID*/
	fixstring_t DeviceID[11];
}LinkLive_t;

/**
  设备状态(0604)
  */
typedef struct DevStatus_t
{
	/*状态上报类型 00:全状态 01:变更状态*/
	uint16_t StatusType;
	/*设备ID*/
	//fixstring_t DeviceID[11];
	/*循环体数 0为所有交易*/
	uint16_t StatusInfo_Cnt;
	//@LENNAME=StatusInfo_Cnt
	StatusInfo_t* StatusInfo_val;
}DevStatus_t;

/**
  箱子信息结构体
 */
typedef struct BoxInfo_t
{
	/*箱子类型*/
	uint8_t BoxType;
	/*箱子位置*/
	uint8_t LocationID;
	/*箱子ID*/
	fixstring_t BoxID[11];
	/**票箱：币种代码；钱箱：面额*/
	uint32_t CashTickCode;
	/*数量*/
	uint16_t Cnt;
	/*金额*/
	uint32_t Amt;
}BoxInfo_t;

/**
  钱票箱信息上报(0605)
 */
typedef struct BoxReport_t
{
	/*设备ID*/
	fixstring_t DeviceID[11];
	/*箱子信息循环体数量*/
	uint16_t BoxInfo_Cnt;
	/*箱子信息循环体*/
	//@LENNAME=BoxInfo_Cnt
	BoxInfo_t* BoxInfo_val;
}BoxReport_t;

/**
  控制命令(0606)
  */
typedef struct DevCmd_t
{
	/*命令码*/
	uint16_t Code;
	/*命令值*/
	uint16_t Value;
	/*命令源 1:FAS 2:SC 3:LC 4:ACC 5:ISCS*/
	fixstring_t Source[2];
	/*操作员*/
	fixstring_t OperID[11];
	/*设备范围*/
	DevRange_t DevRange;
}DevCmd_t;

/**
  售票限制命令(0607)
 */
typedef struct SaleLimit_t
{
	/*命令值*/
	uint16_t Value;
	/*命令源*/
	fixstring_t Source[2];
	/*操作时间*/
	bcd_t OperTime[15];
	/*操作员*/
	fixstring_t OperID[11];
	/*开始时间*/
	bcd_t StartTime[15];
	/*结束时间*/
	bcd_t EndTime[15];
	/*车站个数*/
	uint16_t StationList_Cnt;
	/*车站循环体*/
	//@LENNAME=StationList_Cnt
	StationList_t* StationList;	
}SaleLimit_t;

typedef struct DataUploadRecordsC_t
{
	/*数据类型*/
	uint16_t FileType;
	/*总数*/
	uint32_t Total;
	/*已上传*/
	uint32_t Sended;
}DataUploadRecordsC_t;

/**
  数据上传情况上报(0608)
 */
typedef struct DataUploadRecords_t
{
	/*文件类型记录数*/
	uint16_t records_len;
	/*数据上传情况循环*/
	//@LENNAME=records_len
	DataUploadRecordsC_t *DataUploadRecordsC_val;
}DataUploadRecords_t;

/**
  事件通知(0801)
  */
typedef struct Event_t
{
	/*事件码*/
	uint16_t Code;
	/*事件值*/
	fixstring_t Value[65];
}Event_t;

/**
  现金库存循环体  
 */
typedef struct CashStock_t
{
	/**币种代码*/
	uint8_t CurrencyCode;
	/**钱币数量*/
	uint32_t CurrencyNum;
	/**车站备用金限额*/
	uint32_t ReserveMax;
	/**备用金*/
	uint32_t Reserve;
	/**收益*/
	uint32_t Income;
	/**待解行金额*/
	uint32_t DeliveRing;
	/**TVM已领备用金*/
	uint32_t TvmReserveOut;
	/**BOM已领备用金*/
	uint32_t BomReserveOut;
}CashStock_t;

/**
  现金库存上报(1101)
  */
typedef struct CashReport_t
{
	/**车站ID*/
	fixstring_t StationID[5];
	/**上报数据类型*/
	uint8_t DataType;
	/**现金总库存*/
	uint32_t TotalNum;
	/**现金库存循环体数量*/
	uint32_t Count;
	/**现金库存循环体*/
	//@LENNAME=Count
	CashStock_t* CashStock_val;
}CashReport_t;

typedef struct CurrencyCode_t
{
	/**币种代码*/
	uint8_t CurrencyCode;
}CurrencyCode_t;

/**
  现金库存查询(1102)
 */
typedef struct CashQuery_t
{
	/**车站ID*/
	fixstring_t StationID[5];
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**操作员ID*/
	fixstring_t OperID[11];
	/**循环体数量*/
	uint32_t Count;
	//@LENNAME=Count
	CurrencyCode_t* CurrencyCode_val;
}CashQuery_t;

/**
  短款信息
 */
typedef struct CashLackInfo_t
{
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**报表ID*/
	fixstring_t ReportID[33];
	/**通知单据ID*/
	fixstring_t DocumentID[33];
	/**单据状态 00：已补交 01：待处理 02：取消*/
	uint8_t DocumentStatus;
	/**短款金额*/
	uint32_t ShorageAmt;
	/**差错类型 00：客值交接班 01：车站交易 02：BOM结算 03：TVM票款 04：短款补款 05：异常票款 */
	uint8_t ErrorType;
	/**差错员工工号*/
	fixstring_t ErrorOperID[11];
	/**差错日期*/
	bcd_t ErrorDate[9];
	/**补款截止日期*/
	bcd_t RepenishmentDeadline[9];
	/**统计短款起始日期*/
	bcd_t ShortStartDate[9];
	/**统计短款终止日期*/
	bcd_t ShortEndDate[9];
	/**差错原因*/
	fixstring_t ErrorReason[201];
	/**差错说明*/
	fixstring_t ErrorInstruction[201];
} CashLackInfo_t;

/**
  短款通知(1103)
 */
typedef struct CashLack_t
{
	/**车站ID*/
	fixstring_t StationID[5];
	/**审核日期*/
	bcd_t AuditDate[9];
	/**操作时间*/
	bcd_t OperDateTime[15];
	/**审核操作员ID*/
	fixstring_t AuditOperID[11];

	/**短款信息循环体数量*/
	uint32_t Count;
	//@LENNAME=Count
	CashLackInfo_t *CashLackInfo_val;
}CashLack_t;

/**
  补款补交信息
 */
typedef struct CashReplenishInfo_t
{
	/**通知单据ID*/
	fixstring_t DocumentID[33];
	/**补款单据ID*/
	fixstring_t ReplenishmentID[33];
	/**差错员工工号*/
	fixstring_t ErrorOperID[11];
	/**补款操作员ID*/
	fixstring_t AuditOperID[11];
	/**补款金额*/
	uint32_t ReplenishmentAmt;
} CashReplenishInfo_t;

/**
  补款补交(1104)
 */
typedef struct CashReplenish_t
{
	/**补款时所在车站ID*/
	fixstring_t StationID[5];
	/**补款时间*/
	bcd_t ReplenishmentDateTime[15];

	/**短款补交信息循环体数量*/
	uint32_t Count;
	//@LENNAME=Count
	CashReplenishInfo_t *CashReplenishInfo_val;
}CashReplenish_t;

/**
 * 备用金领用归还(1106)
 */
typedef struct SpareCashBringReturn_t
{
	/* 操作类型 */
	uint8_t OperType;
	/* 操作员ID */
	fixstring_t OperatorID[11];
	/* 上次结存现金金额 */
	uint32_t LastBalancesAmount;
	/* 本次操作现金金额 */
	uint32_t OperationAmount;
	/* 本次结存现金金额 */
	uint32_t BalancesAmount;
}SpareCashBringReturn_t;

/**
  BOM现金收益报告(1105)
 */
typedef struct CashBomIncome_t
{
	/*线路ID*/
	fixstring_t LineID[3];
	/*车站ID*/
	fixstring_t StationID[5];
	/*操作时间*/
	bcd_t OperTime[15];
	/*操作员*/
	fixstring_t OperID[11];
	/*运营日*/
	fixstring_t RunDate[9];
	/*应交金额*/
	uint32_t CaculateAmt;
	/*实交金额*/
	uint32_t RealAmt;
	/*备注*/
	fixstring_t Remark[129];
}CashBomIncome_t;

/**
  票卡库存  
  */
typedef struct TickStock_t
{
	/**库存区域*/
	uint32_t StoreID;
	/**票区ID：01：新票区；02：编码区；03：赋值区；04：循环区；05：待注销区；06：待销毁区；07：回收区*/
	uint8_t TickAreaID;
	/**库存管理类型 0x0101 CST 0x0102 P-CSC  0x0201 CSC*/
	uint16_t TickManaType;
	/**车票状态*/
	uint8_t StatusFlag;
	/**发行商ID*/
	uint8_t IssuerID;
	/**票价*/
	uint32_t Price;
	/**票卡有效期*/
	bcd_t Validate[15];
	/**在库数量*/
	uint32_t StoreNum;
	/**车票总库存*/
	uint32_t TotalNum;
}TickStock_t;

/**
  票卡库存上报(1501)
  */
typedef struct TickReport_t
{
	/**车站ID*/
	fixstring_t StationID[5];
	/**上报数据类型*/
	uint8_t DataType;
	/**票卡库存循环体数*/
	uint32_t Count;
	/**票卡库存循环体*/
	//@LENNAME=Count
	TickStock_t* TickStock_val;
}TickReport_t;

typedef struct TickReqC_t
{
	/**票卡类型*/
	uint16_t TickManaType;
	/**票卡状态*/
	uint8_t TickStatus;
	/**票卡有效期*/
	bcd_t ValidateDate[15];
	/**票卡数量*/
	uint32_t TickNum;
	/**票价*/
	uint32_t Price;
	/**介质类型*/
	uint8_t MediaType;
	/**库存区域*/
	uint32_t StroeID;
	/**票区ID：01：新票区；02：编码区；03：赋值区；04：循环区；05：待注销区；06：待销毁区；07：回收区*/
	uint8_t TickAreaID;
	/**备注*/
	fixstring_t Remark[65];
}TickReqC_t;

/**
  票卡库存调配申请(1503)
 */
typedef struct TickReq_t
{
	/**调配单号*/
	fixstring_t DispatchNO[41];
	/**调配类型*/
	uint8_t DispatchType;
	/**申请时间*/
	bcd_t ApplyTime[15];
	/**调入单位*/
	fixstring_t DispatchIn[5];
	/**调出单位*/
	fixstring_t DispatchOut[5];
	/**预期时间*/
	bcd_t ExpectTime[15];
	/**操作员*/
	fixstring_t OperID[11];
	/**备注*/
	fixstring_t Remark[129];
	/**循环体数量*/
	uint32_t Count;
	//@LENNAME=Count
	TickReqC_t *TickReqC_val;
}TickReq_t;

typedef struct TickRespC_t
{
	/**票卡类型*/
	uint16_t TickManaType;
	/**票卡状态*/
	uint8_t TickStatus;
	/**票卡有效期*/
	bcd_t ValidateDate[15];
	/**票卡数量*/
	uint32_t TickNum;
	/**实际调配数量*/
	uint32_t DispacthNum;
	/**票价*/
	uint32_t Price;
	/**介质类型*/
	uint8_t MediaType;
	/**库存区域*/
	uint32_t StroeID;
	/**票区ID：01：新票区；02：编码区；03：赋值区；04：循环区；05：待注销区；06：待销毁区；07：回收区*/
	uint8_t TickAreaID;
	/**备注*/
	fixstring_t Remark[65];
}TickRespC_t;

/**
  票卡库存调配命令(1504)
 */
typedef struct TickResp_t
{
	/**调配单号*/
	fixstring_t DispatchNO[41];
	/**关联单号*/
	fixstring_t AssociateNO[41];
	/**调配类型*/
	uint8_t DispatchType;
	/**申请时间*/
	bcd_t ApplyTime[15];
	/**调入单位*/
	fixstring_t DispatchIn[5];
	/**调出单位*/
	fixstring_t DispatchOut[5];
	/**预期时间*/
	bcd_t ExpectTime[15];
	/**调配时间*/
	bcd_t DispatchTime[15];
	/**操作员*/
	fixstring_t OperID[11];
	/**备注*/
	fixstring_t Remark[129];
	/**循环体数量*/
	uint32_t Count;
	//@LENNAME=Count
	TickRespC_t *TickRespC_val;
}TickResp_t;

typedef struct TickDetailC_t
{

	/**库存区域*/
	uint32_t StroeID;
	/**票区ID：01：新票区；02：编码区；03：赋值区；04：循环区；05：待注销区；06：待销毁区；07：回收区*/
	uint8_t TickAreaID;
	/**票卡类型*/
	uint16_t TickManaType;
	/**介质类型*/
	uint8_t MediaType;
	/*清点状态 00：一致 01：不一致*/
	uint8_t	InventoryStatus;
	/*批次号*/
	fixstring_t BatchNo[17];
	/**票卡有效期*/
	bcd_t ValidateDate[15];
	/*正常票清点数量*/
	uint32_t ValidNum;
	/*废票清点数量*/
	uint32_t InvalidNum;
	/**票卡数量*/
	uint32_t TicketNum; 
	/**票价*/
	uint32_t Price;
	/**备注*/
	fixstring_t Remark[65];
}TickDetailC_t;

/**
  票卡库存出入库明细(1505)
 */
typedef struct TickDetail_t
{
	/**单号*/
	fixstring_t DispatchNO[41];
	/**操作类型*/
	uint8_t OperType;
	/**操作时间*/
	bcd_t OperTime[15];
	/**源车站ID*/
	fixstring_t SourceID[5];
	/**目的车站ID*/
	fixstring_t DestID[5];
	/**操作员*/
	fixstring_t OperID[11];
	/**备注*/
	fixstring_t Remark[129];
	/**循环体数量*/
	uint32_t Count;
	//@LENNAME=Count
	TickDetailC_t *TickDetailC_val;
}TickDetail_t;

typedef struct TickCheckC_t
{
	/**库存区域*/
	uint32_t StroeID;
	/**票区ID：01：新票区；02：编码区；03：赋值区；04：循环区；05：待注销区；06：待销毁区；07：回收区*/
	uint8_t TickAreaID;
	/**票卡类型*/
	uint16_t TickManaType;
	/**预赋值票值*/
	uint32_t TickPrice;
	/**正常票系统数量*/
	uint32_t SysNum;
	/**正常票盘点数量*/
	uint32_t RealNum;
	/**废票系统数量*/
	uint32_t InvalidSysNum;
	/**废票盘点数量*/
	uint32_t InvalidRealNum;
}TickCheckC_t;

/**
  票卡库存盘点(1506)
 */
typedef struct TickCheck_t
{
	/**盘点单号*/
	fixstring_t DispatchNO[41];
	/**车站ID*/
	fixstring_t StationID[5];
	/**操作类型*/
	uint8_t OperType;
	/**操作时间*/
	bcd_t OperTime[15];
	/**操作员*/
	fixstring_t OperID[11];
	/**盘点结果说明*/
	fixstring_t Remark[129];
	/**循环体数量*/
	uint32_t Count;
	/**票卡库存盘点循环体*/
	//@LENNAME=Count
	TickCheckC_t *TickCheckC_val;
}TickCheck_t;

typedef struct TickQueryC_t
{
	/**票卡类型*/
	uint16_t TickManaType;
}TickQueryC_t;

/**
 * 票卡库存查询(1507)
 * */
typedef struct TickQuery_t
{
	/**车站ID*/
	fixstring_t StationID[5];
	/**设备ID*/
	fixstring_t DevicdID[11];
	/**操作员ID*/
	fixstring_t OperID[11];
	/**循环体数量*/
	uint32_t Count;
	/**循环体*/
	//@LENNAME=Count
	TickQueryC_t* TickQueryC_val;
}TickQuery_t;

/**
  包体
  */
typedef struct CssBody_t
{
	/*消息编码*/
	//@BYTESEQ=BO_MOTO
	uint16_t MsgType;
	//@SWITCH=value->MsgType
	union
	{
		//@CASE=0X0101
		LoginReq_t LoginReq0101;
		//@CASE=0X0102
		LoginNotice_t LoginNotice0102;
		//@CASE=0X0103
		PassWdInfo_t PassWdInfo0103;
		//@CASE=0X0104
		LoginCtl_t LoginCtl0104;
		//@CASE=0X0105
		OperLock_t OperLock0105;
		//@CASE=0X0111
		LoginResult_t LoginResult0111;
		//@CASE=0X0201
		ParaPublish_t ParaPublish0201;
		//@CASE=0X0202
		ParaSync_t ParaSync0202;
		//@CASE=0X0204
		ParaReport_t ParaReport0204;
		//@CASE=0x0205
		PartParaReport_t PartParaReport0205;
		//@CASE=0x0206
		TPUParaReport_t TPUParaReport0206;
		//@CASE=0x0207
		SAMCardInfoReport_t SAMCardInfoReport0207;
		//@CASE=0X0406
		FileVerify_t FileVerify0406;
		//@CASE=0X0411
		FileNotice_t FileNotice0411;
		//@CASE=0X0412
		uint16_t FileType;
		//@CASE=0X0421
		DataImport_t DataImport0421;
		//@CASE=0X0422
		FileSpecify_t FileSpecify0422;
		//@CASE=0X0423
		TranSpecify_t TranSpecify0423;
		//@CASE=0x0601
		DevRunCfg_t DevRunCfg0601;
		//@CASE=0x0602
		LinkLive_t LinkLive0602;
		//@CASE=0x0604
		DevStatus_t DevStatus0604;
		//@CASE=0x0605
		BoxReport_t BoxReport0605;
		//@CASE=0x0606
		DevCmd_t DevCmd0606;
		//@CASE=0x0607
		SaleLimit_t SaleLimit0607;
		//@CASE=0x0608
		DataUploadRecords_t DataUploadRecords0608;
		//@CASE=0x0701
		ModeNotice_t ModeNotice0701;
		//@CASE=0x0702
		ModeInfo_t ModeInfo0702;
		//@CASE=0x0703
		ModeQuery_t ModeQuery0703;
		//@CASE=0x0801
		Event_t Event0801;
		//@CASE=0x1101
		CashReport_t CashReport1101;
		//@CASE=0x1102
		CashQuery_t CashQuery1102;
		//@CASE=0x1103
		CashLack_t CashLack1103;
		//@CASE=0x1104
		CashReplenish_t CashReplenish1104;
		//@CASE=0x1105
		CashBomIncome_t CashBomIncome1105;
		//@CASE=0x1106
		SpareCashBringReturn_t SpareCashBringReturn1106;
		//@CASE=0x1501
		TickReport_t TickReport1501;
		//@CASE=0x1503
		TickReq_t TickReq1503;
		//@CASE=0x1504
		TickResp_t TickResp1504;
		//@CASE=0x1505
		TickDetail_t TickDetail1505;
		//@CASE=0x1506
		TickCheck_t TickCheck1506;
		//@CASE=0x1507
		TickQuery_t TickQuery1507;
		//@CASE=0x1523
		TickReq_t TickReq1523;
		//@CASE=0x1524
		TickResp_t TickResp1524;
		//@CASE=0x1525
		TickDetail_t TickDetail1525;
	}body_u;
}CssBody_t;
/**
  包结构
  */
typedef struct Css_t
{
	/*包头 长度34*/
	CssHeader_t CssHeader;
	/*包体*/
	CssBody_t CssBody;
	/*校验码*/
	block_t MD5[16];
}Css_t;


//业务、收益结构体//

/**
 *     售票循环体
 *     */
typedef struct TicketSaleC_t
{
	/**票种*/
	uint32_t TickType;
	/**发售数量*/
	uint32_t TickSaleNum;
	/**发售金额*/
	uint32_t TickSaleAmount;
}TicketSaleC_t;

/**
 *     票卡充值循环体
 *     */
typedef struct TicketRechargeC_t
{
	/**票种*/
	uint32_t TickType;
	/**充值数量*/
	uint32_t TickRechargeNum;
	/**充值金额*/
	uint32_t TickRechargeAmount;
}TicketRechargeC_t;

/**
 *     票卡更新循环体
 *     */
typedef struct TicketUpdateC_t
{
	/**票种*/
	uint32_t TickType;
	/**更新原因*/
	fixstring_t TickUpdateReason[5];
	/**支付方式*/
	fixstring_t TickPayType[5];
	/**更新数量*/
	uint32_t TickUpdateNum;
	/**更新金额*/
	uint32_t TickUpdateAmount;
}TicketUpdateC_t;

/**
 *     行政处理循环体
 *     */
typedef struct AffairDealC_t
{
	/**行政处理结果代码*/
	uint32_t AffairCode;
	/**行政处理数量*/
	uint16_t AffairNum;
	/**行政处理金额*/
	uint32_t AffairAmount;
}AffairDealC_t;

/**
 *     票卡延期循环体
 *     */
typedef struct TicketDelayC_t
{
	/**票种*/
	uint32_t TickType;
	/**延期数量*/
	uint32_t TickDelayNum;
}TicketDelayC_t;

/**
 *     及时退款循环体
 *     */
typedef struct TicketRefundInsC_t
{
	/**票种*/
	uint32_t TickType;
	/**即时退款数量*/
	uint32_t TicketRefundNum;
	/**即时退款余额*/
	uint32_t TickRefundAmount;
	/**即时退款押金*/
	uint32_t TickRefundDeposit;
}TicketRefundInsC_t;

/**
 *     非及时退款循环体
 *     */
typedef struct TicketRefundNoInsC_t
{
	/**票种*/
	uint32_t TickType;
	/**非即时退款数量*/
	uint32_t TickRefundNoInsNum;
	/**非即时退款余额*/
	uint32_t TickRefundNoInsBlance;
	/**非即时退款押金*/
	uint32_t TickRefundNoInsDeposit;
	/**非及时退款罚金*/
	uint32_t TickRefundNoInsPenalty;
}TicketRefundNoInsC_t;

/**
 *     非及时退款申请循环体
 *     */
typedef struct TicketRefundNoInsApplyC_t
{
	/**票种*/
	uint32_t TickType;
	/**非即时退款数量*/
	uint32_t TickRefundNoInsApplyNum;
}TicketRefundNoInsApplyC_t;

/**
 *     冲正循环体
 *     */
typedef struct ChongZhengC_t
{
	/**票种*/
	uint32_t TickType;
	/**冲正数量*/
	uint32_t ChongZhengNum;
	/**冲正金额*/
	uint32_t ChongZhengAmount;
}ChongZhengC_t;

/**
 *     票卡解锁循环体
 *     */
typedef struct TicketUnlockC_t
{
	/**票种*/
	uint32_t TickType;
	/**解锁数量*/
	uint32_t TickUnlockNum;
}TicketUnlockC_t;

/**
	闸机票箱数据
 */
typedef struct GateBoxData_t
{ 
	/**设备ID*/
	bcd_t DeviceID[11];
	/**操作员工号*/
	//@MAX=6
	string_t* OperatorID;
	/**票箱编号*/
	uint32_t TokenBoxID;
	/**票箱取出时间*/
	bcd_t RemoveTime[15];
	/**流水号*/
	uint16_t SerialNO;
	/**票种*/
	bcd_t TicketType[5];
	/**车票数量*/
	uint16_t TicketNum;
}GateBoxData_t;

/**
 * 操作日志  6101
 */
typedef struct OperLog_t
{
	/*设备ID*/
	fixstring_t DeviceID[11];
	/*操作员*/
	fixstring_t OperID[11];
	/*操作时间*/
	bcd_t Opertime[15];
	/*操作代码*/
	fixstring_t OperCode[5];
	/*操作结果 0:成功 1:失败*/
	fixstring_t Result[2];
	/*操作内容*/
	fixstring_t Remark[301];
}OperLog_t;

typedef struct FaultLogC_t
{
	/**故障设备ID*/
	fixstring_t DeviceID[11];
	/**车站ID*/
	fixstring_t StationID[5];
	/**操作员ID*/
	fixstring_t OperatorID[11];
	/**发生时间*/
	bcd_t OccurTime[15];
	/**维修代码*/
	uint32_t MaintainCode;
	/**故障分类*/
	uint16_t FaultType;
	/**故障ID*/
	uint32_t FaultID;
	/**关键字段1*/
	fixstring_t KeyFld1[65];
	/**关键字段2*/
	fixstring_t KeyFld2[65];
}FaultLogC_t;

/**
 * 故障数据 6102
 * */
typedef struct FaultLog_t
{
	/**循环体数量*/
	uint32_t Count;
	/**循环体结构体*/
	//@LENNAME=Count
	FaultLogC_t* FaultLogC_val;
}FaultLog_t;

/**
 * 包传输审计数据 6103
 * */
typedef struct AuditPacket_t
{
	/**数据包类型*/
	uint8_t PacketType;
	/**审计数据序号*/
	uint32_t AuditSeq;
	/**审计开始时间*/
	bcd_t AuditBeginTime[15];
	/**审计结束时间*/
	bcd_t AuditEndTime[15];
	/**数据包ID*/
	fixstring_t PackageID[65];
	/**数据包中记录数*/
	uint32_t RecordInPacket;
	/**开始交易UDSN*/
	uint32_t BeginUDSN;
	/**结束交易UDSN*/
	uint32_t EndUDSN;
}AuditPacket_t;

/**
 * 交易传输审计数据 6104
 * */
typedef struct AuditTran_t
{
	/**数据包类型*/
	uint8_t PacketType;
	/**审计数据序号*/
	uint32_t AuditSeq;
	/**审计开始时间*/
	bcd_t AuditBeginTime[15];
	/**审计结束时间*/
	bcd_t AuditEndTime[15];
	/**交易总比数*/
	uint32_t TotalUDNum;
	/**开始交易UDSN*/
	uint32_t BeginUDSN;
	/**结束交易UDSN*/
	uint32_t EndUDSN;
}AuditTran_t;

typedef struct AudDataC_t
{
	fixstring_t TranType[3];
	fixstring_t PayMode[3];
	bcd_t TickType[5];
	uint32_t TRXCount;
	uint32_t TRXAmount;
}AudDataC_t;

/**
	AGM审计数据  6105
 */
typedef struct AGMAudData_t
{ 
	/**审计数据类型*/
	fixstring_t DataType[2];
	/**操作日期*/
	bcd_t OperationDate[9];
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**当前日期*/
	bcd_t CurTime[15];
	/**SJT票箱取出次数*/
	uint8_t SJTNum;
	/**交易循环体数*/
	uint32_t TransactionC_len;
	//@LENNAME=TransactionC_len
	////**交易循环体*/
	///TransactionC_t* TransactionC_val;
	AudDataC_t* AudDataC_val;
	
}AGMAudData_t;

/**
	TVM审计数据  6106
 */
typedef struct TVMAudData_t
{ 
	fixstring_t DataType[3];
	/**操作日期*/
	bcd_t OperationDate[9];
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**当前日期*/
	bcd_t CurTime[15];
	/**当天Token Hopper补充单程票量*/
	uint16_t TokenHoppers;
	/**当天Token Hopper补充硬币量*/
	uint16_t CoinHopper;
	/**当天Token Hopper补充硬币金额*/
	uint32_t CoinAmount;
	/**当天Token Hopper清空的单程票量*/
	uint16_t TokenClean;
	/**当天Token Hopper清空硬币量*/
	uint16_t CoinClean;
	/**当天Token Hopper清空硬币总金额*/
	uint32_t CoinCleanAmount;
	/**当天 Coin Box回收的硬币总数量*/
	uint16_t CoinBoxCount;
	/**当天 Coin Box回收的硬币总金额*/
	uint32_t CoinBoxAmount;
	/**当天 Banknote Box回收的纸币总张数*/
	uint16_t NoteBoxCount;
	/**当天 Banknote Box回收的纸币总金额*/
	uint32_t NoteBoxAmount;
	/**交易循环体数*/
	uint32_t TransactionC_len;
	//@LENNAME=TransactionC_len
	/**交易循环体*/
	////TransactionC_t* TransactionC_val;
	AudDataC_t* AudDataC_val;
}TVMAudData_t;

typedef struct CashOperC_t
{
	/**操作类型*/
	uint32_t MoneyActionType;
	/**现金类型*/
	uint32_t CashType;
	/**币种*/
	uint32_t DenominationType;
}CashOperC_t;

typedef struct TickOperC_t
{
	///**操作类型*/
	////uint32_t TicketOperCount;
	/**操作类型*/
	uint32_t TicketActionType;
	/**车票类型*/
	uint32_t TickType;
	/**卡号*/
	uint32_t CardSN;
	/**操作结果*/
	uint32_t OperResult;
}TickOperC_t;

/**
 * TVM操作审计数据  6107
 * */
typedef struct TVMOperAudData_t
{
	/**操作流水号*/
	fixstring_t TransID[11];
	//SleTransType
	/**交易开始时间*/
	bcd_t BeginDate[15];
	/**交易结束时间*/
	bcd_t EndDate[15];
	/**目的车站*/
	fixstring_t DestinationStation[5];
	/**车票类型*/
	uint32_t TicketType;
	/**车票子类型*/
	uint32_t TicketSubType;
	/**乘客类型*/
	uint32_t PassengerType;
	/**卡类型*/
	uint32_t CardType;
	/**付费方式*/
	uint32_t PaymentMethod;
	/**交易数量*/
	uint32_t CountFromPassenger;
	/**单价*/
	uint32_t UnitPrice;
	/**应付金额*/
	uint32_t TotalPrice;
	/**已付金额*/
	uint32_t PaymentAmount;
	/**实际交易数量*/
	uint32_t TransCount;
	/**实际交易金额*/
	uint32_t TransAmount;
	/**实际找零金额*/
	uint32_t ChangeAmount;
	/**出票失败数量*/
	uint32_t OutFailCount;
	/**是否打印凭证*/
	uint32_t PrintVoucher;
	/**现金操作记录体数量*/
	uint32_t Count;
	/**现金操作记录循环体*/
	//@LENNAME=Count
	CashOperC_t* CashOperC_val;
	/**票卡操作记录体数量*/
	uint32_t OperCount;
	/**票卡操作记录循环体*/
	//@LENNAME=OperCount
	TickOperC_t* TickOperC_val;
}TVMOperAudData_t;

typedef struct Currency_t 
{
	/** 币种代码 */
	uint8_t CurrencyCode;
	/** 数量 */
	uint16_t Num;
	/** 金额 */
	uint32_t Amount;
}Currency_t;

typedef struct CashBoxInfoC_t
{
	/** 钱箱编号 */
	fixstring_t BoxID[11];
	/** 操作流水号 */
	uint16_t SerialNum;
	/** 操作类型 */
	uint8_t OperType;
	/** 钱箱类型 */
	uint8_t BoxType;
	/** 钱箱位置（钱箱顺序号） */
	uint8_t LocationID;
	///** 币种 */
	//uint8_t CurrencyCode;
	/** 安装时间 */
	bcd_t InstallTime[15];
	/** 操作时间 */
	bcd_t Time[15];
	/** 币种数量 */
	uint16_t CurrencyCount;
	/** 币种循环体 */
	//@LENNAME=CurrencyCount
	Currency_t* Currency_val;
	///** 钱数量 */
	//uint16_t Num;
	///** 钱金额 */
	//uint32_t Amount;
}CashBoxInfoC_t;

/**
	*	钱箱更换数据 6108
 * */
typedef struct CashBoxChangeData_t
{
	/** 设备编号 */
	fixstring_t DeviceID[11];
	/** 操作员员工号 */
	fixstring_t OperatorID[11];
	/** 循环体数量 */
	uint16_t BoxInfo_Cnt;
	/** 钱箱循环体 */
	//@LENNAME=BoxInfo_Cnt
	CashBoxInfoC_t *CashBoxInfoC_val;
}CashBoxChangeData_t;

typedef struct TickBoxInfoC_t
{
	/** 票箱编号 */
	fixstring_t BoxID[11];
	/** 操作流水号 */
	uint16_t SerialNum;
	/** 操作类型 */
	uint8_t OperType;
	/** 票箱类型 */
	uint8_t BoxType;
	/** 票箱位置（钱箱顺序号） */
	uint8_t LocationID;
	/** 票种 */
	uint16_t TicketCode;
	/** 安装时间 */
	bcd_t InstallTime[15];
	/** 操作时间 */
	bcd_t Time[15];
	/** 票数量 */
	uint32_t Num;
}TickBoxInfoC_t;

/**
 * 票箱更换数据 6109
 * */
typedef struct TickBoxChangeData_t
{
	/** 设备编号 */
	fixstring_t DeviceID[11];
	/** 操作员员工号 */
	fixstring_t OperatorID[11];
	/** 循环体数量 */
	uint16_t BoxInfo_Cnt;
	/** 票箱循环体 */
	//@LENNAME=BoxInfo_Cnt
	TickBoxInfoC_t *TickBoxInfoC_val;
}TickBoxChangeData_t;


typedef struct TickCashInfoC_t
{
	/**钱票箱操作类型*/
	uint8_t  OperType;
	/**钱票箱类型*/
	uint8_t BoxType;
	/**钱票箱位置*/
	uint8_t BoxLocation;
	/**数量*/
	uint32_t Count;
	/**金额*/
	uint32_t Amount;
}TickCashInfoC_t;


/**
	TVM自动结存数据 7001
 */
typedef struct TVMAutoData_t
{ 
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**操作员ID*/
	fixstring_t OperatorID[11];
	/**结算日期*/
	bcd_t SettlementDate[9];
	/**结算序号*/
	uint32_t SettlementUDSN;
	/**结算类型*/
	uint16_t SettlementType;
	/**自动结存周期开始时间*/
	bcd_t StartTime[15];
	/**自动结存周期结束时间*/
	bcd_t EndTime[15];
	/**现金售票数量*/
	uint32_t CashSaleNum;
	/**现金售票金额*/
	uint32_t CashSaleSum;
	/**一卡通售票数量*/
	uint32_t YKTSaleNum;
	/**一卡通售票金额*/
	uint32_t YKTSaleSum;
	/**一卡通充值数量*/
	uint32_t YKTChargeNum;
	/**一卡通充值金额*/
	uint32_t YKTChargeSum;
	/**银行卡充值次数*/
	uint32_t BankCardChargeNum;
	/**银行卡充值金额*/
	uint32_t BankCardChargeSum;
	/**借记银行卡充值次数*/
	uint32_t DebitCardChargeNum;
	/**借记银行卡充值金额*/
	uint32_t DebitCardChargeSum;
	/**累计信用卡充值次数*/
	uint32_t CreditCardChargeNum;
	/**累计信用卡充值金额*/
	uint32_t CreditCardChargeSum;
	/**故障交易数量*/
	uint32_t FaultTranNum;
	/**故障交易金额*/
	uint32_t FaultTranSum;
	/**充值总金额*/
	uint32_t ChargeAmount;
	/**纸币接收总金额*/
	uint32_t NoteAmountIn;
	/**硬币接收总金额*/
	uint32_t CoinAmountIn;
	/**纸币找零箱找零总金额*/
	uint32_t NoteChangeAmount;
	/**硬币找零箱找零总金额*/
	uint32_t CoinChangeAmount;
	/**单程票废票数量*/
	uint32_t InvalidCount;
	/**钱票箱记录数据*/
	uint32_t TickCashRecord_Cnt;
	/**钱票箱记录*/
	//@LENNAME=TickCashRecord_Cnt
	TickCashInfoC_t* TickCashInfo_val;
	/**TVM结存金额*/
	uint32_t TotalBlanceAmount;
	/**预留字段1*/
	block_t Rest[64];
}TVMAutoData_t;


/**
	TVM结算数据 7002
 */
typedef struct TVMCheckout_t
{ 
	/**结算日期*/
	bcd_t SettlementDate[9];
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**结算序号*/
	uint32_t SettlementUDSN;
	/**结算类型*/
	uint16_t SettlementType;
	/**操作员 ID*/
	fixstring_t OperatorID[11];
	/**自动结存周期开始时间*/
	bcd_t StartTime[15];
	/**自动结存周期结束时间*/
	bcd_t EndTime[15];
	/**现金售票数量*/
	uint32_t CashSaleNum;
	/**现金售票金额*/
	uint32_t CashSaleSum;
	/**一卡通售票数量*/
	uint32_t YKTSaleNum;
	/**一卡通售票金额*/
	uint32_t YKTSaleSum;
	/**一卡通充值数量*/
	uint32_t YKTChargeNum;
	/**一卡通充值金额*/
	uint32_t YKTChargeSum;
	/**银行卡充值次数*/
	uint32_t BankCardChargeNum;
	/**银行卡充值金额*/
	uint32_t BankCardChargeSum;
	/**借记银行卡充值次数*/
	uint32_t DebitCardChargeNum;
	/**借记银行卡充值金额*/
	uint32_t DebitCardChargeSum;
	/**累计信用卡充值次数*/
	uint32_t CreditCardChargeNum;
	/**累计信用卡充值金额*/
	uint32_t CreditCardChargeSum;
	/**故障交易数量*/
	uint32_t FaultTranNum;
	/**故障交易金额*/
	uint32_t FaultTranSum;
	/**纸币找零箱存入总金额*/
	uint32_t NoteChangeBoxIn;
	/**硬币找零箱存入总金额*/
	uint32_t CoinChangeBoxIn;
	/**纸币接收总金额*/
	uint32_t NoteAcceptAmount;
	/**硬币接收总金额*/
	uint32_t CoinAcceptAmount;
	/**纸币找零箱找零总金额*/
	uint32_t NoteChangeAmount;
	/**硬币找零箱找零总金额*/
	uint32_t CoinChangeAmount;
	/**单程票废票数量*/
	uint32_t InvalidCount;
	/**票箱1数量*/
	uint32_t TicketBox1Amount;
	/**票箱2数量*/
	uint32_t TicketBox2Amount;
	/**TVM结存金额*/
	uint32_t BalanceAmount;
	/**TVM应收总金额*/
	uint32_t TotalAmount;
	block_t Rest[64];
}TVMCheckout_t;

/**
	BOM结算数据  7003
 */
typedef struct BOMShiftData_t
{ 
	/**结算单号*/
	fixstring_t SettlementsSN[11];
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**操作员工号*/
	fixstring_t OperatorID[11];
	/**操作员班次ID*/
	bcd_t ShiftID[5];
	/**第1个操作员登录为1，第2个操作员登录为2…*/
	bcd_t ShiftSeq[5];
	/**班次开始时间*/
	bcd_t ShiftStart[15];
	/**班次结束时间*/
	bcd_t ShiftEnd[15];
	/**售票循环体数*/
	uint32_t TicketSaleC_len;
	/**售票循环体*/
	//@LENNAME=TicketSaleC_len
	TicketSaleC_t* TicketSaleC_val;
	/**发售总金额*/
	uint32_t TotalSaleAmount;
	/**票卡充值循环体数*/
	uint32_t TicketRechargeC_len;
	/**票卡充值循环体*/
	//@LENNAME=TicketRechargeC_len
	TicketRechargeC_t* TicketRechargeC_val;
	/**充值总金额*/
	uint32_t TotalAddAmount;
	/**票卡更新循环体数*/
	uint32_t TicketUpdateC_len;
	/**票卡更新循环体*/
	//@LENNAME=TicketUpdateC_len
	TicketUpdateC_t* TicketUpdateC_val;
	/**现金更新金额总计*/
	uint32_t UpdateCash;
	/**总更新金额*/
	uint32_t TotalUpdateAmount;
	/**行政处理循环体数*/
	uint32_t AffairDealC_len;
	//@LENNAME=AffairDealC_len
	/**行政处理循环体*/
	AffairDealC_t* AffairDealC_val;
	/**总行政处理退款金额*/
	uint32_t AffairRefusedAmount;
	/**总行政处理收入金额*/
	uint32_t AffairAddAmount;
	/**票种延期循环体数*/
	uint32_t TicketDelayC_len;
	/**票种延期循环体*/
	//@LENNAME=TicketDelayC_len
	TicketDelayC_t* TicketDelayC_val;
	/**及时退款循环体数*/
	uint32_t TicketRefundInsC_len;
	/**及时退款循环体*/
	//@LENNAME=TicketRefundInsC_len
	TicketRefundInsC_t* TicketRefundInsC_val;
	/**及时总退票金额 */
	uint32_t TotalRefundInsAmount;
	/**非及时退款循环体数*/
	uint32_t TicketRefundNoInsC_len;
	/**非及时退款循环体*/
	//@LENNAME=TicketRefundNoInsC_len
	TicketRefundNoInsC_t* TicketRefundNoInsC_val;
	/**非及时退款总退票金额 */
	uint32_t TotalRefundNoIns;
	/**非及时退款申请循环体数*/
	uint32_t TicketRefundNoInsApplyC_len;
	/**非及时退款申请循环体*/
	//@LENNAME=TicketRefundNoInsApplyC_len
	TicketRefundNoInsApplyC_t* TicketRefundNoInsApplyC_val;
	/**冲正循环体数*/
	uint32_t ChongZhengC_len;
	//@LENNAME=ChongZhengC_len
	/**冲正循环体*/
	ChongZhengC_t* ChongZhengC_val;
	/**总冲正金额*/
	uint32_t TotalChongZhengAmount;
	/**票卡解锁循环体数*/
	uint32_t TicketUnlockC_len;
	//@LENNAME=TicketUnlockC_len
	/**票卡解锁循环体*/
	TicketUnlockC_t* TicketUnlockC_val;
	/**班次应收非现金金额*/
	uint32_t TotalNoCash;
	/**班次应收现金金额*/
	uint32_t TotalCash;
}BOMShiftData_t;

////**
/// * BOM 故障退款  7007
/// * */
///typedef struct BOMFaultReturn_t
///{
///	/**故障设备ID*/
///	fixstring_t FaultDeviceID[11];
///	/**故障单ID*/
///	uint32_t FaultCertificateID;
///	/**BOM退款金额*/
///	uint32_t RefundmentCount;
///}BOMFaultReturn_t;

/**
 * BOM 行政处理数据 7004
 */
typedef struct BOMAdminData_t
{
	/**交易类型*/
	uint16_t TranType;
	/**设备 ID*/
	fixstring_t DeviceID[11];
	/**操作员号*/
	fixstring_t OperatorID[11];
	/**交易时间*/
	bcd_t TranTime[15];
	/**设备交易序号*/
	fixstring_t TranSN[11];
	/**TVM故障单号码*/
	fixstring_t FaultCertificateID[21];
	/**交易金额*/
	uint32_t TranAmount;
	/**处理类型*/
	uint16_t ProcessType;
	/**处理备注*/
	fixstring_t Remark[31];
	/**交易流水号*/
	uint32_t Udsn;
	/**班次流水号*/
	uint8_t ShiftSeq;
	/**卡号*/
	fixstring_t CardID[21];
	/**预留*/
	fixstring_t Rest[33];
}BOMAdminData_t;

/**
 * TVM 故障交易 7005
 * */
typedef struct TVMFaultTran_t
{
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**故障时间*/
	bcd_t FailTime[15];
	/**故障单ID*/
	fixstring_t FaultCertificateID[21];
	/**对应交易流水号*/
	uint32_t UDSN;
	/**应退款金额*/
	uint32_t RefundmentCount;
	/**故障原因*/
	uint8_t FaultReason;
}TVMFaultTran_t;

/**
 * 边门处理数据 7006
 * */
typedef struct SideDoorRecord_t
{
	/*操作员ID*/
	fixstring_t OperatorID[11];
	/*数据源 01:BOM; 02:AG; 03:WS*/
	fixstring_t Source[3];
	/*操作时间*/
	bcd_t DateTime[15];
	/*车站编码*/
	fixstring_t StationID[5];
	/*设备编码*/
	fixstring_t DeviceID[11];
	/*数据类型 00:ENTRY; 01:EXIT*/
	fixstring_t Type[3];
	/*数据原因*/
	fixstring_t Reason[3];
	/*数量*/
	fixstring_t Number[5];
	/*乘客名称*/
	fixstring_t PassengerName[11];
	/*证件ID*/
	fixstring_t CertificateID[21];
	/*备注*/
	fixstring_t Note[31];
}SideDoorRecord_t;

typedef struct TransCountInfoC_t
{
	/** 代理商ID*/
	uint32_t AgentID;
	/** 卡发型商ID*/
	uint32_t CardIssuerID;
	/** 票种*/
	uint32_t TicketType;
	/** 交易类型*/
	uint32_t TranType;
	/** 交易子类型*/
	uint32_t TranSubType;
	/** 支付方式*/
	uint16_t PayMeansCode;
	/** 交易数量*/
	uint32_t TranCount;
	/** 交易金额*/
	uint32_t TranAmount;
}TransCountInfoC_t;
/**
	TVM结算数据 7007
 */
typedef struct TVMBalance_t
{ 
	/**结算日期*/
	bcd_t SettlementDate[9];
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**结算序号*/
	uint32_t SettlementUDSN;
	/**结算类型*/
	uint16_t SettlementType;
	/**操作员 ID*/
	fixstring_t OperatorID[11];
	/**自动结存周期开始时间*/
	bcd_t StartTime[15];
	/**自动结存周期结束时间*/
	bcd_t EndTime[15];
	/**纸币找零箱存入总金额*/
	uint32_t NoteChangeBoxIn;
	/**硬币找零箱存入总金额*/
	uint32_t CoinChangeBoxIn;
	/**纸币接收总金额*/
	uint32_t NoteAcceptAmount;
	/**硬币接收总金额*/
	uint32_t CoinAcceptAmount;
	/**纸币找零箱找零总金额*/
	uint32_t NoteChangeAmount;
	/**硬币找零箱找零总金额*/
	uint32_t CoinChangeAmount;
	/**单程票废票数量*/
	uint32_t InvalidCount;
	/**票箱1数量*/
	uint32_t TicketBox1Amount;
	/**票箱2数量*/
	uint32_t TicketBox2Amount;
	/*故障交易数量*/
	uint32_t FaultTranNum;
	/*故障交易金额*/
	uint32_t FaultTranSum;
	/**TVM结存金额*/
	uint32_t BalanceAmount;
	/** 循环体数量 */
	uint32_t TransCountInfo_Cnt;
	/** 交易统计循环体 */
	//@LENNAME=TransCountInfo_Cnt
	TransCountInfoC_t *TransCountInfoC_val;
	/** 应收非现金金额*/
	uint32_t TotalNonCashCollected;
	/** TVM应收现金总金额*/
	uint32_t TotalAmount;
	block_t Rest[64];
}TVMBalance_t;

typedef struct BomTicketSaleC_t
{
	/** 代理商ID*/
	uint32_t AgentID;
	/** 卡发型商ID*/
	uint32_t CardIssuerID;
	/** 票种*/
	uint32_t TicketType;
	/** 交易类型*/
	uint32_t TranType;
	/** 交易子类型*/
	uint32_t TranSubType;
	/** 售票处理方式*/
	uint8_t TicketOperation;
	/** 收款处理方式*/
	uint8_t ReceiptOperation;
	/** 支付方式*/
	uint16_t PayMeansCode;
	/** 交易数量*/
	uint32_t TranCount;
	/** 押金金额*/
	uint32_t DepositAmount;
	/** 交易金额*/
	uint32_t TranAmount;
	/** 交易手续费金额*/
	uint32_t FreeAmount;
	/** 卡成本费金额*/
	uint32_t CostAmount;
}BomTicketSaleC_t;
/**
	BOM结算数据  7008
 */
typedef struct BOMBalance_t
{ 
	/**结算单号*/
	fixstring_t SettlementsSN[11];
	/**设备ID*/
	fixstring_t DeviceID[11];
	/**操作员工号*/
	fixstring_t OperatorID[11];
	/**操作员班次ID*/
	bcd_t ShiftID[5];
	/**第1个操作员登录为1，第2个操作员登录为2…*/
	bcd_t ShiftSeq[5];
	/**班次开始时间*/
	bcd_t ShiftStart[15];
	/**班次结束时间*/
	bcd_t ShiftEnd[15];
	/** 循环体数量 */
	uint32_t BomTicketSale_Cnt;
	/** 交易统计循环体 */
	//@LENNAME=BomTicketSale_Cnt
	BomTicketSaleC_t *BomTicketSaleC_val;
	/** 应收非现金金额*/
	uint32_t TotalNonCashCollected;
	/** 应收金额*/
	uint32_t TotalCashCollected;
	block_t Rest[64];
}BOMBalance_t;
/**
 * BOM 日结算数据（项目结构） 8001
 */
typedef struct PrjBomData_t
{
	uint32_t temp;
}PrjBomData_t;

/**
 * TVM 日结算数据（项目结构） 8002
 */
typedef struct PrjTvmData_t
{
	uint32_t temp;
}PrjTvmData_t;

/**
 * AG 日结算数据（项目结构） 8003
 */
typedef struct PrjAgData_t
{
	uint32_t temp;
}PrjAgData_t;

/**
 * 设备寄存器数据（项目结构） 8005
 */
typedef struct PrjRegData_t
{
	uint32_t temp;
}PrjRegData_t;

/**
	收益体
 */
typedef struct CssFile_t
{
	/**文件类型*/
	uint16_t FileType;
	/***/
	uint16_t records_len;
	/***/
	//@SWITCH=(value->FileType)
	union
	{
		/* 操作日志 */ 
		//@CASE = 0x6101 
		//@LENNAME=records_len
		OperLog_t *OperLog_val ;
		/* 故障数据 */ 
		//@CASE = 0x6102
		//@LENNAME=records_len
		FaultLog_t *FaultLog_val ;
		/* 包传输审计 */ 
		//@CASE = 0x6103 
		//@LENNAME=records_len
		AuditPacket_t *AuditPacket_val ;
		/* 交易传输审计 */ 
		//@CASE = 0x6104 
		//@LENNAME=records_len
		AuditTran_t *AuditTran_val ;
		/* AG审计数据 */ 
		//@CASE = 0x6105 
		//@LENNAME=records_len
		AGMAudData_t *AGMAudData_val ;
		/* TVM审计数据 */ 
		//@CASE = 0x6106 
		//@LENNAME=records_len
		TVMAudData_t *TVMAudData_val ;
		/* TVM操作审计数据 */ 
		//@CASE = 0x6107 
		//@LENNAME=records_len
		TVMOperAudData_t *TVMOperAudData_val ;
		/* 钱箱更换数据 */
		//@CASE = 0x6108
		//@LENNAME=records_len
		CashBoxChangeData_t *CashBoxChangeData_val;
		/* 票箱更换数据 */
		//@CASE = 0x6109
		//@LENNAME=records_len
		TickBoxChangeData_t *TickBoxChangeData_val;
		/* TVM结存数据 */ 
		//@CASE = 0x7001 
		//@LENNAME=records_len
		TVMAutoData_t *TVMAutoData_val;
		/* TVM结算数据 */ 
		//@CASE = 0x7002 
		//@LENNAME=records_len
		TVMCheckout_t *TVMCheckout_val;
		/* BOM结算数据 */ 
		//@CASE = 0x7003 
		//@LENNAME=records_len
		//BOMCheckout_t BOMCheckout;
		BOMShiftData_t *BOMShiftData_val;
		////* BOM故障退款 */ 
		/////@CASE = 0x7007 
		/////@LENNAME=records_len
		///BOMFaultReturn_t *BOMFaultReturn_val;
		/* BOM行政处理数据 */
		//@CASE = 0x7004
		//@LENNAME=records_len
		BOMAdminData_t *BOMAdminData_val;
		/* TVM故障交易 */ 
		//@CASE = 0x7005 
		//@LENNAME=records_len
		TVMFaultTran_t *TVMFaultTran_val;
		//@CASE = 0x7006
		//@LENNAME=records_len
		SideDoorRecord_t *SideDoorRecord_val;
		/* TVM结算数据 */ 
		//@CASE = 0x7007 
		//@LENNAME=records_len
		TVMBalance_t *TVMBalance_val;
		/* BOM结算数据 */ 
		//@CASE = 0x7008 
		//@LENNAME=records_len
		BOMBalance_t *BOMBalance_val;
		/* BOM 日结算结构 */
		//@CASE = 0x8001
		//@LENNAME=records_len
		PrjBomData_t *PrjBomData_val;
		/* TVM 日结算结构 */
		//@CASE = 0x8002
		//@LENNAME=records_len
		PrjTvmData_t *PrjTvmData_val;
		/* AG 日结算结构 */
		//@CASE = 0x8003
		//@LENNAME=records_len
		PrjAgData_t *PrjAgData_val;
		/* 设备寄存器数据结构 */
		//@CASE = 0x8005
		//@LENNAME=records_len
		PrjRegData_t *PrjRegData_val;
	}body_u;
}CssFile_t;

typedef struct ParaLineInfo_t
{
	fixstring_t LineID[3];
	fixstring_t LineCnName[11];
	fixstring_t LineEnName[11];
}ParaLineInfo_t;

typedef struct ParaStationInfo_t
{
	fixstring_t StationID[5];
	fixstring_t LocationNumber[11];
	fixstring_t StationCnName[21];
	fixstring_t StationEnName[21];
	fixstring_t StationType[3];
	block_t Rest[32];
}ParaStationInfo_t;

/*
 * A800
 * */
typedef struct ParaA800_t
{
	fixstring_t LineCount[5];
	//@CUSTOM=uint32_t iLineCount = atoi(value->LineCount);
	//@CUSTOM=adp->iRecCnt = iLineCount;
	//@LENNAME=adp->iRecCnt
	ParaLineInfo_t *ParaLineInfo_val;
	fixstring_t StationCount[5];
	//@CUSTOM=uint32_t iStationCount = atoi(value->StationCount);
	//@CUSTOM=adp->iRecCnt = iStationCount;
	//@LENNAME=adp->iRecCnt
	ParaStationInfo_t *ParaStationInfo_val;
}ParaA800_t;

int adp_CssHeader_t(ADP* adp,CssHeader_t* value);
int adp_DevList_t(ADP* adp,DevList_t* value);
int adp_StationList_t(ADP* adp,StationList_t* value);
int adp_DevRange_t(ADP* adp,DevRange_t* value);
int adp_FileSeqList_t(ADP* adp,FileSeqList_t* value);
int adp_TranRange_t(ADP* adp,TranRange_t* value);
int adp_ParaInfo_t(ADP* adp,ParaInfo_t* value);
int adp_ParaList_t(ADP* adp,ParaList_t* value);
int adp_StatusInfo_t(ADP* adp,StatusInfo_t* value);
int adp_LoginReq_t(ADP* adp,LoginReq_t* value);
int adp_LoginNotice_t(ADP* adp,LoginNotice_t* value);
int adp_PassWdInfo_t(ADP* adp,PassWdInfo_t* value);
int adp_LoginCtl_t(ADP* adp,LoginCtl_t* value);
int adp_OperLock_t(ADP* adp,OperLock_t* value);
int adp_LoginResult_t(ADP* adp,LoginResult_t* value);
int adp_ModeInfo_t(ADP* adp,ModeInfo_t* value);
int adp_ModeQuery_t(ADP* adp,ModeQuery_t* value);
int adp_ModeNotice_t(ADP* adp,ModeNotice_t* value);
int adp_ParaPublish_t(ADP* adp,ParaPublish_t* value);
int adp_ParaSync_t(ADP* adp,ParaSync_t* value);
int adp_ParaReport_t(ADP* adp,ParaReport_t* value);
int adp_PartParaInfo_t(ADP* adp,PartParaInfo_t* value);
int adp_PartParaReport_t(ADP* adp,PartParaReport_t* value);
int adp_TPUPara_t(ADP* adp,TPUPara_t* value);
int adp_TPUParaInfo_t(ADP* adp,TPUParaInfo_t* value);
int adp_TPUParaReport_t(ADP* adp,TPUParaReport_t* value);
int adp_PSAMCardInfo_t(ADP* adp,PSAMCardInfo_t* value);
int adp_CRWInfo_t(ADP* adp,CRWInfo_t* value);
int adp_SAMCardInfoReport_t(ADP* adp,SAMCardInfoReport_t* value);
int adp_FileVerify_t(ADP* adp,FileVerify_t* value);
int adp_FileNotice_t(ADP* adp,FileNotice_t* value);
int adp_DataImport_t(ADP* adp,DataImport_t* value);
int adp_FileSpecify_t(ADP* adp,FileSpecify_t* value);
int adp_TranSpecify_t(ADP* adp,TranSpecify_t* value);
int adp_DevRunCfg_t(ADP* adp,DevRunCfg_t* value);
int adp_LinkLive_t(ADP* adp,LinkLive_t* value);
int adp_DevStatus_t(ADP* adp,DevStatus_t* value);
int adp_BoxInfo_t(ADP* adp,BoxInfo_t* value);
int adp_BoxReport_t(ADP* adp,BoxReport_t* value);
int adp_DevCmd_t(ADP* adp,DevCmd_t* value);
int adp_SaleLimit_t(ADP* adp,SaleLimit_t* value);
int adp_DataUploadRecordsC_t(ADP* adp,DataUploadRecordsC_t* value);
int adp_DataUploadRecords_t(ADP* adp,DataUploadRecords_t* value);
int adp_Event_t(ADP* adp,Event_t* value);
int adp_CashStock_t(ADP* adp,CashStock_t* value);
int adp_CashReport_t(ADP* adp,CashReport_t* value);
int adp_CurrencyCode_t(ADP* adp,CurrencyCode_t* value);
int adp_CashQuery_t(ADP* adp,CashQuery_t* value);
int adp_CashLackInfo_t(ADP* adp,CashLackInfo_t* value);
int adp_CashLack_t(ADP* adp,CashLack_t* value);
int adp_CashReplenishInfo_t(ADP* adp,CashReplenishInfo_t* value);
int adp_CashReplenish_t(ADP* adp,CashReplenish_t* value);
int adp_SpareCashBringReturn_t(ADP* adp,SpareCashBringReturn_t* value);
int adp_CashBomIncome_t(ADP* adp,CashBomIncome_t* value);
int adp_TickStock_t(ADP* adp,TickStock_t* value);
int adp_TickReport_t(ADP* adp,TickReport_t* value);
int adp_TickReqC_t(ADP* adp,TickReqC_t* value);
int adp_TickReq_t(ADP* adp,TickReq_t* value);
int adp_TickRespC_t(ADP* adp,TickRespC_t* value);
int adp_TickResp_t(ADP* adp,TickResp_t* value);
int adp_TickDetailC_t(ADP* adp,TickDetailC_t* value);
int adp_TickDetail_t(ADP* adp,TickDetail_t* value);
int adp_TickCheckC_t(ADP* adp,TickCheckC_t* value);
int adp_TickCheck_t(ADP* adp,TickCheck_t* value);
int adp_TickQueryC_t(ADP* adp,TickQueryC_t* value);
int adp_TickQuery_t(ADP* adp,TickQuery_t* value);
int adp_CssBody_t(ADP* adp,CssBody_t* value);
int adp_Css_t(ADP* adp,Css_t* value);
int adp_TicketSaleC_t(ADP* adp,TicketSaleC_t* value);
int adp_TicketRechargeC_t(ADP* adp,TicketRechargeC_t* value);
int adp_TicketUpdateC_t(ADP* adp,TicketUpdateC_t* value);
int adp_AffairDealC_t(ADP* adp,AffairDealC_t* value);
int adp_TicketDelayC_t(ADP* adp,TicketDelayC_t* value);
int adp_TicketRefundInsC_t(ADP* adp,TicketRefundInsC_t* value);
int adp_TicketRefundNoInsC_t(ADP* adp,TicketRefundNoInsC_t* value);
int adp_TicketRefundNoInsApplyC_t(ADP* adp,TicketRefundNoInsApplyC_t* value);
int adp_ChongZhengC_t(ADP* adp,ChongZhengC_t* value);
int adp_TicketUnlockC_t(ADP* adp,TicketUnlockC_t* value);
int adp_GateBoxData_t(ADP* adp,GateBoxData_t* value);
int adp_OperLog_t(ADP* adp,OperLog_t* value);
int adp_FaultLogC_t(ADP* adp,FaultLogC_t* value);
int adp_FaultLog_t(ADP* adp,FaultLog_t* value);
int adp_AuditPacket_t(ADP* adp,AuditPacket_t* value);
int adp_AuditTran_t(ADP* adp,AuditTran_t* value);
int adp_AudDataC_t(ADP* adp,AudDataC_t* value);
int adp_AGMAudData_t(ADP* adp,AGMAudData_t* value);
int adp_TVMAudData_t(ADP* adp,TVMAudData_t* value);
int adp_CashOperC_t(ADP* adp,CashOperC_t* value);
int adp_TickOperC_t(ADP* adp,TickOperC_t* value);
int adp_TVMOperAudData_t(ADP* adp,TVMOperAudData_t* value);
int adp_Currency_t(ADP* adp,Currency_t* value);
int adp_CashBoxInfoC_t(ADP* adp,CashBoxInfoC_t* value);
int adp_CashBoxChangeData_t(ADP* adp,CashBoxChangeData_t* value);
int adp_TickBoxInfoC_t(ADP* adp,TickBoxInfoC_t* value);
int adp_TickBoxChangeData_t(ADP* adp,TickBoxChangeData_t* value);
int adp_TickCashInfoC_t(ADP* adp,TickCashInfoC_t* value);
int adp_TVMAutoData_t(ADP* adp,TVMAutoData_t* value);
int adp_TVMCheckout_t(ADP* adp,TVMCheckout_t* value);
int adp_BOMShiftData_t(ADP* adp,BOMShiftData_t* value);
int adp_BOMAdminData_t(ADP* adp,BOMAdminData_t* value);
int adp_TVMFaultTran_t(ADP* adp,TVMFaultTran_t* value);
int adp_SideDoorRecord_t(ADP* adp,SideDoorRecord_t* value);
int adp_TransCountInfoC_t(ADP* adp,TransCountInfoC_t* value);
int adp_TVMBalance_t(ADP* adp,TVMBalance_t* value);
int adp_BomTicketSaleC_t(ADP* adp,BomTicketSaleC_t* value);
int adp_BOMBalance_t(ADP* adp,BOMBalance_t* value);
int adp_PrjBomData_t(ADP* adp,PrjBomData_t* value);
int adp_PrjTvmData_t(ADP* adp,PrjTvmData_t* value);
int adp_PrjAgData_t(ADP* adp,PrjAgData_t* value);
int adp_PrjRegData_t(ADP* adp,PrjRegData_t* value);
int adp_CssFile_t(ADP* adp,CssFile_t* value);
int adp_ParaLineInfo_t(ADP* adp,ParaLineInfo_t* value);
int adp_ParaStationInfo_t(ADP* adp,ParaStationInfo_t* value);
int adp_ParaA800_t(ADP* adp,ParaA800_t* value);
#ifdef __cplusplus
}
#endif
#endif
