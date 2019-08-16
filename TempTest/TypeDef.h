/*
 * TypeDef.h
 *
 *  Created on: 2017-9-20
 *      Author: root
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

#include <stdint.h>
#include <errno.h>
#include <string.h>

#pragma pack(push,1)
typedef struct _ST_TPU_YKT_UDDATA_
{
	unsigned char ucTranType; //交易类型
	unsigned char ucProductMainType; //车票主类型编码
	unsigned char ucProductType; //车票类型码
	unsigned char ucCardType; //票卡物理类型
	unsigned char ucCardLogicalNo[8]; //逻辑卡号	长度不足时左补0
	unsigned char ucCardVersionCode; //卡版本号 1
	unsigned char ucOperCode[4]; //操作员编号	仅用于BOM		Char	4
	unsigned char ucSamNo[6]; //SAM卡号 即终端机编号
	unsigned char ucTranDateTime[7]; //交易日期时间	Timestamp	7
	unsigned char ucPaymentCode; //支付方式
	unsigned long ulBeforeTranValue; //交易前票值		Long	4
	unsigned short ucReversed1; //[保留]	Block 2
	unsigned short ulTranValue; //交易金额	无值交易为0
	unsigned char ucCurrStation[4]; //当前车站	节点编码	BCD	4
	unsigned char ucLastStation[4]; //上次使用车站	节点编码，交易代码为出站交易时，该字段填出站车站节点编码	BCD	4
	unsigned char ucDeviceCode[4]; //终端设备标识	节点编码	BCD	4
	unsigned long ulSleSeq; //终端设备流水号	Long	4
	unsigned short usCardCount; //票计数器	Word	2
	unsigned short usCityCode; //城市代码	卡的发行城市代码（BCD码）	Word	2
	unsigned char ucMainCardType; //卡主类型
	unsigned char ucSonCardType; //卡子类型
	unsigned char ucIndustryApplicationTypes; //行业应用类型	00：消费正常交易09：消费灰交易
	unsigned char ucBusinessType;//业务类型	06：电子钱包消费09：复合消费
	unsigned short usDeposit; //押金	仅用于出售储值票交易	Word	2
	unsigned short usDiscountValue; //优惠金额	全价票额与实际交易额的差值	Word	2
	unsigned long ulSAMCardSN1; //SAM卡序列号
	unsigned long ulSAMCardSN2; //SAM卡流水号
	unsigned char ucDiscountType; //优惠类型	0-无优惠1-换乘优惠2-时段优惠
	unsigned char ucTransferDate[7]; //换乘最近时间	YYYYMMDDHHMMSS
	unsigned short ulTranValueTransfer; //换乘时上一笔交易金额
	unsigned char ucTransferUnitNumber[6]; //换乘最近单位编号 6
	unsigned char ucTransferLineNumber[4]; //换乘最近线路编号 4
	unsigned char ucACCTransTime[7]; //ACC主机交易时间	用于联机充值	Timestamp	7
	unsigned char ucReversed2[20]; //[保留]		Block	20
	unsigned char ucTAC[4]; //TAC	Block	4
} ST_TPU_YKT_UDDATA;

typedef struct _ST_TPU_JTB_UDDATA_
{
	unsigned char ucTranType; //交易类型
	unsigned char ucProductMainType; //车票主类型编码
	unsigned char ucProductType; //车票类型码
	unsigned char ucCardType; //票卡物理类型
	unsigned char ucCardPHNo[8]; //票卡CSN	票卡物理号,不足后补0x00	Block	8
	unsigned char ucCardLogicalNo[20]; //票卡逻辑号	交通部卡号，不足20位右补空格
	unsigned char ucReversed1; //卡版本号
	unsigned char ucOperCode[4]; //操作员编号	仅用于BOM		Char	4
	unsigned char ucSamNo[6]; //SAM卡号
	unsigned char ucTranDateTime[7]; //交易日期时间	Timestamp	7
	unsigned char ucPaymentCode; //支付方式
	//unsigned char ucRunDate[4]; //运营日期	YYYYMMDD	BCD	4
	unsigned long ulBeforeTranValue; //交易前票值	计次票、月票为余次	Long	4
	unsigned short ulTranTimes; //预留
	unsigned short ulTranValue; //交易金额
	unsigned char ucCurrStation[4]; //当前车站	节点编码	BCD	4
	unsigned char ucLastStation[4]; //上次使用车站	节点编码，交易代码为出站交易时，该字段填出站车站节点编码	BCD	4
	unsigned char ucDeviceCode[4]; //终端设备标识	节点编码	BCD	4
	unsigned long ulSleSeq; //终端设备流水号	Long	4
	unsigned short usCardCount; //票计数器	Word	2
	unsigned short usCityCode; //城市代码	卡的发行城市代码（BCD码）	Word	2

//	unsigned long ulWalletStartDate; //钱包起始日期	仅月票充值交易使用，表明月票充值交易归属的周期开始日期，例如：为月票2010年7月充值为20100701。	其它交易填全‘0’
//	unsigned short usDeposit; //押金	仅用于出售储值票交易	Word	2
//	unsigned short usDiscountValue; //优惠金额	全价票额与实际交易额的差值	Word	2
//	unsigned char  ucSVCLogicalNo[8]; //储值票逻辑卡号	仅用于储值票购买单程票	Block	8
//	unsigned char ucOutStationTicketFlag; //出站票交易标记	0：非出站票，1：出站票	Byte	1
//	unsigned char ucCommemorativeTicketFlag; //纪念票交易标记	0：非纪念票，1：纪念票	Byte	1
//	unsigned char ucTestFlag; //测试交易标志	0x00-正常交易	0x01-测试交易	Byte	1
//	unsigned char ucACCTransTime[7]; //ACC主机交易时间	用于联机充值	Timestamp	7
//	unsigned long ucReversed[18]; //进闸机构标识
//	unsigned char ucReversed8[20]; //[保留]		Block	8
	unsigned char ucTAC[103]; //TAC	Block	4
} ST_TPU_JTB_UDDATA;

#pragma pack(pop)
#endif
