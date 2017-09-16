/////////////////////////////////////////////////////
//
//	TAM001DevStruct.h
//

#ifndef TAM001DEVSTRUCT_H_
#define TAM001DEVSTRUCT_H_

#define TAM001_IGNORE		0  // 忽略
#define TAM001_RESEND		1  // 重发
#define TAM001_INIT			2  // 初始化
#define TAM001_STOP			3  // 停止

#define TAM001_NORMAL		0  // 正常0
#define TAM001_WARNNING		1  // 警告
#define TAM001_ERROR		2  // 错误

//初始化方式
enum TAM001_INIT_TYPE
{
	TAM001_PASSAGE_SELF_CHECK = 0X01,	//通道自检
	TAM001_TRAY_SELF_CHECK = 0X02,		//托盘自检
	TAM001_ALL_PARTS_CHECK = 0XFF		//所有部件自检
};

//允许接收方式
enum TAM001_ENABLE_TYPE
{
	TAM001_ONLY_ONE_CARD = 0x01,				//一次接收一张卡
	TAM001_NO_LIMITED	  = 0xFF					//始终有效
};

//票卡清理方式
enum TAM001_CARD_CLEAR_TYPE
{
	TAM001_RETRACT_AUTO		  = 0x00,	//默认回收
	TAM001_RETRACT_CARD_BOX_A = 0x01,	//回收到卡箱A
	TAM001_RETRACT_CARD_BOX_B = 0x02,	//回收到卡箱B
	TAM001_RETRACT_REJECT_BOX = 0x03,	//回收到废票箱
	TAM001_RETURN_AND_DISCARD  = 0x11,	//从插卡口退出并丢弃
	TAM001_RETURN_TO_SLOT	   = 0x12	//退出到插卡口并夹住
};

//卡箱号
enum TAM001_CARD_BOX_ID
{
	TAM001_CARD_BOX_A = 0x01,					//卡箱A
	TAM001_CARD_BOX_B = 0x02,					//卡箱B
	TAM001_REJECT_BOX = 0x03,					//回收箱
	TAM001_ALL_CARD_BOX = 0xFF					//所有卡箱
};

//更换方式
enum TAM001_REPLACE_TYPE
{
	TAM001_DETACH_BOX = 0x61,							//取卡箱
	TAM001_ATTACH_BOX = 0x62							//装卡箱
};

//字节对齐
#pragma pack(push,1)
//硬件版本信息
typedef struct 
{
	char				acModuleType[16];				//模块型号

	char				acMCUVer[16];					//MCU 程序版本号

	char				acCPLDVer[16];					//CPLD 版本号
}tTAM001_OUT_DEV_VER;

// 卡箱的数据信息
typedef struct 
{
	int					iCardBox[4];					//卡箱卡片数量 [0]---A [1]---B [2\3]---Reserved
		
	UINT				uiRejectBox;					//废卡箱卡片数量
	
	BYTE				byPassage;						//通道里当前票卡数量

	BYTE				byReserved[3];					//保留字段	
}tTAM001_CARD_NUM;

//初始化类型
typedef struct 
{
	BYTE				byInitType;						//初始化方式
	
	BYTE				byClearType;					//通道里的票卡的清理方式

	BYTE				byReserved[2];					//保留字段
	
}tTAM001_IN_INIT;

//清理卡信息
typedef struct 
{
	BYTE				byRet;							//本次成功清理/退卡/回收的票卡张数

	BYTE				byReserved[3];					//保留字段

	tTAM001_CARD_NUM	sCardNum;						//卡数量信息
}tTAM001_OUT_RET;

//接收票卡
typedef struct 
{
	BYTE				byEnableType;					//接收方式
	
	BYTE				byReserved[3];					//保留字段
}tTAM001_IN_RECV;

//回收票卡
typedef struct 
{
	BYTE				byBoxId;						//卡箱号

	BYTE				byReserved[3];					//保留字段	
}tTAM001_IN_RETR;

//退卡
typedef struct 
{
	BYTE				byReturnedType;					//退卡方式

	BYTE				byReserved[3];					//保留字段

}tTAM001_IN_RET;

//更换票箱数据同步
typedef struct 
{
	BYTE				byBoxId;						//卡箱号

	BYTE				byReplType;						//更换方式
	
	BYTE				byReserved[2];					//保留字段
}tTAM001_IN_SYNCECARDBOX;

//读写卡箱RFID数据
typedef struct 
{
	BYTE				byBoxId;						//卡箱号

	BYTE				byBlockIndex;					//RFID block号
	
	BYTE				byReserved[2];					//保留字段
	
}tTAM001_IN_RWRFID;

//卡箱信息
typedef struct 
{
	BYTE				byBoxId;						//卡箱号
		
	BYTE				byReserved[3];					//保留字段
	
}tTAM001_IN_CARD_INFO;

//读/写数据
typedef struct 
{		
	char				caData[64];						// 写入/读出的数据
}tTAM001_DATA;

//设备日志
typedef struct
{
	BYTE				byLogDate[4];			        //日志记录日期 年月日时
	
	UINT				uiLogStartAddress;				//记录DwLogDate当天的日志开始地址
	
	UINT				uiLogEndAddress;			    //记录DwLogDate当天的日志结束地址	
	
}tTAM001_Log;

//审计信息
typedef struct 
{
	WORD				wCardBox[4];					//[Out] 累计回收卡数 [0]--卡箱A [1]---卡箱B [2\3]---保留

	WORD				wReserved[4];					//[Out] 保留字段

	WORD				wErr;							//[Out] 累计错误

}tTAM001_AuditInfo;

#pragma pack(pop)
#endif
