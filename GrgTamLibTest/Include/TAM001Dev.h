// TAM001LogDev.h: interface for the OTAM001LogDev class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _TAM001DEV_H_
#define _TAM001DEV_H_

#include "typedef.h"
#include "DevBase.h"
#include "TAM001DevDef.h"
#include "TAM001DevStruct.h"

#ifdef __cplusplus
extern "C" {
#endif	

HANDLE hOpenLogicalDevice(LPCTSTR p_pcLogicDevName, tDevReturn *p_psStatus);
void vCloseLogicalDevice(HANDLE p_hDevHandle);

int iGetIntValue(HANDLE p_hDevHandle, const char *p_pcSection, const char *p_pcKeyName, int &p_iKeyValue);

int iGetStringValue(HANDLE p_hDevHandle, const char *p_pcSection, const char *p_pcKeyName, char* p_psKeyValue,unsigned int& p_iLen);
  
int iSetIntValue(HANDLE p_hDevHandle, const char *p_pcSection, const char *p_pcKeyName, long p_lKeyValue);
  
int iSetStringValue(HANDLE p_hDevHandle, const char *p_pcSection, const char *p_pcKeyName, char* p_psKeyValue, unsigned int p_iLen);	

//关闭串口
int iCloseComm(HANDLE p_hDevHandle);

//设置驱动逻辑设备名
void vSetLogicalDevName(HANDLE p_hDevHandle, const char* p_pcLogicalDevName);

//获取驱动逻辑设备名
void vGetLogicalDevName(HANDLE p_hDevHandle, char* p_pcLogicalDevName);

//设置设备通讯
int iSetCommPara(HANDLE p_hDevHandle, tDevReturn* p_psStatus);

//获取动态库的版本
int iGetVersion(HANDLE p_hDevHandle, char* p_pcVersion);

//获取模块所有版本信息
int iGetDevVersion(HANDLE p_hDevHandle, tTAM001_OUT_DEV_VER * p_psTAM001VerInfo, tDevReturn* p_psStatus);

//初始化
int iInit(HANDLE p_hDevHandle, const tTAM001_IN_INIT* p_psInit, tTAM001_OUT_RET* p_psRet, tDevReturn* p_psStatus);

//读模块状态
int iGetStatus(HANDLE p_hDevHandle, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//允许接收票卡
int iEnableReceiveCard(HANDLE p_hDevHandle, const tTAM001_IN_RECV* p_psRecvCard, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//禁止接收票卡
int iDisableReceiveCard(HANDLE p_hDevHandle, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//回收票卡
int iRetractCard(HANDLE p_hDevHandle, const tTAM001_IN_RETR* p_psRetractCard, tTAM001_OUT_RET* p_psRet, tDevReturn* p_psStatus);

//退卡
int iReturnCard(HANDLE p_hDevHandle, const tTAM001_IN_RET* p_psReturnedCard, tTAM001_OUT_RET* p_psRet, tDevReturn* p_psStatus);

//更换票箱,同步票箱和控制板数据
int iSynCeCardbox(HANDLE p_hDevHandle, const tTAM001_IN_SYNCECARDBOX* p_psSynCeCardBox, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//设置卡箱票卡数量
int iSetCardBoxNum(HANDLE p_hDevHandle, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//向RFID 写一个Block 数据
int iRFWriteBlock(HANDLE p_hDevHandle, const tTAM001_IN_RWRFID* p_psWRFID, const tTAM001_DATA* p_psData, tDevReturn *p_psStatus);

//从RFID 读一个Block 数据
int iRFReadBlock(HANDLE p_hDevHandle, const tTAM001_IN_RWRFID* p_psRRFID, tTAM001_DATA* p_psData, tDevReturn *p_psStatus);

//读取RFID 的物理编号
int iGetRFIDCardInfo(HANDLE p_hDevHandle, const tTAM001_IN_CARD_INFO* p_psCardInfo, tTAM001_DATA* p_psData, tDevReturn *p_psStatus);

//读取卡箱SN 号
int iGetCardBoxSn(HANDLE p_hDevHandle, const tTAM001_IN_CARD_INFO* p_psCardInfo, tTAM001_DATA* p_psData, tDevReturn* p_psStatus);

//读模块序列号
int iGetSerialNumber(HANDLE p_hDevHandle, tTAM001_DATA* p_psData, tDevReturn* p_psStatus); 


//added by hguang 2012-09-03
//以下接口仅针对北京地铁导则需求增加，其它使用要求原则上不建议调用以下接口
int iRFInitComm(HANDLE p_hDevHandle,int p_iportNum,tDevReturn *p_psrStatus);	
int iRFCloseComm(HANDLE p_hDevHandle);	
int iRFReadData(HANDLE p_hDevHandle,int p_iblock,char* p_pchData,int p_ilen,tDevReturn *p_psStatus);
int iRFWriteData(HANDLE p_hDevHandle,int p_iblock,const char* p_pchData,int p_ilen,tDevReturn *p_psStatus);
//end added

//内部命令,慎用
/***********************************************
插卡口闸门控制
p_byCtrType 控制类型:
	0x41：闸门打开；
        0x42：闸门关闭；
 	0x43：释放闸门（如果是常开型闸门，释放后闸门会处于打开状态；如果是常闭型闸门，释放会闸门会处于关闭状态）
***********************************************/
int iShutterControl(HANDLE p_hDevHandle, const BYTE p_byCtrType, tDevReturn* p_psStatus);
	
/***********************************************
托盘控制
p_byBoxId:卡箱号
p_byCtrlType:控制类型
	0x31：托盘上升，不等待上升到位；
        0x32：托盘下降，不等待下降到位；
        0x33：停止；
	0x34：托盘上升，等待到位；
	0x35：托盘下降，等待到位
***********************************************/
int iTrayControl(HANDLE p_hDevHandle, const BYTE p_byBoxId, const BYTE p_byCtrlType, tDevReturn* p_psStatus);
	
/***********************************************
电机控制
p_byMotorId:电机号
	0x01：A 卡箱电机
	0x02：B 卡箱电机
	0x03：主电机
p_byCtrlType:控制类型
	0x21：正转；
	0x22：反转；
	0x23：刹车；
	0x24：停止
***********************************************/
int iMotorControl(HANDLE p_hDevHandle, const BYTE p_byMotorId, const BYTE p_byCtrlType, tDevReturn* p_psStatus);
	
/***********************************************
换向器控制
p_byRouterType:换向器类型
	0x52：A卡箱换向器；
	0x53：回收箱换向器
p_byCtrlType:控制类型
	0x51：换向器打开（A 卡箱接收）
	0x52：换向器关闭（B 卡箱接收）
***********************************************/
int iRouterControl(HANDLE p_hDevHandle, const BYTE p_byRouterType, const BYTE p_byCtrlType, tDevReturn* p_psStatus);


#ifdef __cplusplus
}
#endif

#endif
















