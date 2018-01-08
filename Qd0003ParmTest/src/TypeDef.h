/*
 * TypeDef.h
 *
 *  Created on: 2017-10-26
 *      Author: root
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

#pragma pack(push,1)

//灯光提示
typedef struct _ST_PARM006_LIGTH_INFO
{
    unsigned long ulLightID;    //灯光提示ID
    char szLightName[32];   //灯光提示名称
    unsigned char ucLightFlag;  //灯光提示标志 0表示不亮灯 Bit0：黄灯 Bit1：绿灯 Bit2：红灯 Bit3：蓝灯 Bit4：白灯
}ST_PARM006_LIGTH_INFO;

//提示音
typedef struct _ST_PARM006_SOUND_INFO
{
    unsigned long ulSoundId;    //提示音ID
    char szSoundName[32];      //提示音名称
    char szSoundFileName[32];   //提示音文件名
    unsigned char szFileMd5[16];    //提示音文件校验码
}ST_PARM006_SOUND_INFO;

//票卡芯片类型记录
typedef struct _ST_PARM0003_CARD_PHY_INFO
{
    unsigned char ucCardPhyType;   //票卡芯片类型
    long lValidDay;    //有效期天数
    long lMaxTradeCnt;  //最大交易次数
}ST_PARM_CARD_PHY_INFO; //票卡芯片类型记录

//车票类型记录
typedef struct _ST_PARM0003_CARD_INFO
 {
	unsigned char	TicketType;						//车票类型
	char	TicketTypeChineseName[32];	//车票类型中文名称
	char	TicketTypeEnglishName[32];	//车票类型中文名称
	unsigned char	TicketMainType;					//车票主类型
	unsigned char	TicketPublisher;				//车票发行方
	unsigned char	PriceCalculateMode;				//车票计价方式
	unsigned char	UseLimitFlag;					//使用范围限制标志
	unsigned int	PassengerCountForRideTicket;	//计次票乘客次数
	unsigned int	FixSalePrice;					//固定发售金额(单位分)
	unsigned short	GeneralFlag;					//标志位 Bit0：纪念票标志 Bit1：记名票标志 Bit2：充值授权标志 Bit3：退票授权标志 Bit4：单程票售票站进站限制标志
	//Bit5：单程票回收标志 Bit6：单程票废票回收标志 Bit7：进出站次序检验标志 Bit8：计期票延期标志 Bit9：激活标志 Bit10～Bit15：[保留]
	unsigned char	BatchIDForRecycleTicket[5];		//回收废票发行批次
	unsigned int	MaxUseCountForRecycleTicket;	//回收废票最大使用次数
	unsigned int	MaxUseDaysForRecycleTicket;		//回收废票最大使用天数
	unsigned int	AlertSoundID;					//提示音ID
	unsigned int	AlertLightID;					//灯光提示ID
	unsigned int	MinChargeAmount;				//最小充值金额
	unsigned int	MaxRemainTicketAmount;			//储值票最大余额
	unsigned int	MinRemainAmountForEntry;		//最小进站金额
	unsigned int	MinRemainAmountForExit;			//最小出站金额
	unsigned int	Deposit;						//押金
	unsigned int	DepreciateParam;				//折旧计算参数
	unsigned int	MaxAmountForDirectRefund;		//最大即时退票金额
	unsigned int	FeeForRefund;					//退票手续费
	unsigned int	MaxRideCount;					//最多乘车次数
	unsigned char	TicketValidType;				//车票有效期类别
	unsigned int	ValidDaysAfterSale;				//车票发售有效天数
	unsigned int	ValidDaysAfterActive;			//车票激活有效天数
	unsigned char		FixEndValidDate[4];				//固定截止有效日期
	unsigned int 	MaxSecondsForFreeUpdateEntry;	//重复进站免费更新最大时效
	unsigned int 	FineAmountForUpdateEntry;		//重复进站更新罚款金额
	unsigned int	FineAmountForOverTime;			//超时罚款金额
	unsigned int	FineForMismatch;				//基础站不匹配罚金(进站段)
	unsigned int	FineForExitAgNotAtFineStation;	//非罚款车站过闸罚款金额
	unsigned int	IntervalBetweenExitAndEntry;	//两次交易时间间隔
	unsigned char	FavourMode[8];					//优惠方式
	unsigned short	IntervalForFavourRide;			//联程优惠时间间隔
	unsigned short	MissIntervalForFavourRide;		//联程优惠误差时间
	unsigned short	FavourCountForFavourRid;		//联程优惠值
	unsigned char	AccFavourMode;					//累计优惠方式
	//2017.06.26 增加了两个字段
	unsigned int   NomlocalCardTradeUndoneAmount;	//异地卡交易未完成收费金额
	unsigned char	NomlocalCardUpdateControl;		//异地卡更新控制 0x00-不允许更新  	0x01-根据未完成收费金额更新（固定）  	0x02-根据未完成收费金额更新（固定）可修改
}ST_PARM0003_CARD_INFO;

//优惠等级记录
typedef struct _ST_PARM0003_FAVOUR_RANGE
{
	unsigned short	AccStartAmount;		//累计优惠开始值
	unsigned short	AccEndAmount;		//累计优惠结束值
	unsigned short	FavourPercent;		//优惠比例
}ST_PARM0003_FAVOUR_RANGE;

#pragma pack(pop)

#endif /* TYPEDEF_H_ */
