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

//�رմ���
int iCloseComm(HANDLE p_hDevHandle);

//���������߼��豸��
void vSetLogicalDevName(HANDLE p_hDevHandle, const char* p_pcLogicalDevName);

//��ȡ�����߼��豸��
void vGetLogicalDevName(HANDLE p_hDevHandle, char* p_pcLogicalDevName);

//�����豸ͨѶ
int iSetCommPara(HANDLE p_hDevHandle, tDevReturn* p_psStatus);

//��ȡ��̬��İ汾
int iGetVersion(HANDLE p_hDevHandle, char* p_pcVersion);

//��ȡģ�����а汾��Ϣ
int iGetDevVersion(HANDLE p_hDevHandle, tTAM001_OUT_DEV_VER * p_psTAM001VerInfo, tDevReturn* p_psStatus);

//��ʼ��
int iInit(HANDLE p_hDevHandle, const tTAM001_IN_INIT* p_psInit, tTAM001_OUT_RET* p_psRet, tDevReturn* p_psStatus);

//��ģ��״̬
int iGetStatus(HANDLE p_hDevHandle, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//�������Ʊ��
int iEnableReceiveCard(HANDLE p_hDevHandle, const tTAM001_IN_RECV* p_psRecvCard, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//��ֹ����Ʊ��
int iDisableReceiveCard(HANDLE p_hDevHandle, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//����Ʊ��
int iRetractCard(HANDLE p_hDevHandle, const tTAM001_IN_RETR* p_psRetractCard, tTAM001_OUT_RET* p_psRet, tDevReturn* p_psStatus);

//�˿�
int iReturnCard(HANDLE p_hDevHandle, const tTAM001_IN_RET* p_psReturnedCard, tTAM001_OUT_RET* p_psRet, tDevReturn* p_psStatus);

//����Ʊ��,ͬ��Ʊ��Ϳ��ư�����
int iSynCeCardbox(HANDLE p_hDevHandle, const tTAM001_IN_SYNCECARDBOX* p_psSynCeCardBox, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//���ÿ���Ʊ������
int iSetCardBoxNum(HANDLE p_hDevHandle, tTAM001_CARD_NUM* p_psCardNum, tDevReturn* p_psStatus);

//��RFID дһ��Block ����
int iRFWriteBlock(HANDLE p_hDevHandle, const tTAM001_IN_RWRFID* p_psWRFID, const tTAM001_DATA* p_psData, tDevReturn *p_psStatus);

//��RFID ��һ��Block ����
int iRFReadBlock(HANDLE p_hDevHandle, const tTAM001_IN_RWRFID* p_psRRFID, tTAM001_DATA* p_psData, tDevReturn *p_psStatus);

//��ȡRFID ��������
int iGetRFIDCardInfo(HANDLE p_hDevHandle, const tTAM001_IN_CARD_INFO* p_psCardInfo, tTAM001_DATA* p_psData, tDevReturn *p_psStatus);

//��ȡ����SN ��
int iGetCardBoxSn(HANDLE p_hDevHandle, const tTAM001_IN_CARD_INFO* p_psCardInfo, tTAM001_DATA* p_psData, tDevReturn* p_psStatus);

//��ģ�����к�
int iGetSerialNumber(HANDLE p_hDevHandle, tTAM001_DATA* p_psData, tDevReturn* p_psStatus); 


//added by hguang 2012-09-03
//���½ӿڽ���Ա������������������ӣ�����ʹ��Ҫ��ԭ���ϲ�����������½ӿ�
int iRFInitComm(HANDLE p_hDevHandle,int p_iportNum,tDevReturn *p_psrStatus);	
int iRFCloseComm(HANDLE p_hDevHandle);	
int iRFReadData(HANDLE p_hDevHandle,int p_iblock,char* p_pchData,int p_ilen,tDevReturn *p_psStatus);
int iRFWriteData(HANDLE p_hDevHandle,int p_iblock,const char* p_pchData,int p_ilen,tDevReturn *p_psStatus);
//end added

//�ڲ�����,����
/***********************************************
�忨��բ�ſ���
p_byCtrType ��������:
	0x41��բ�Ŵ򿪣�
        0x42��բ�Źرգ�
 	0x43���ͷ�բ�ţ�����ǳ�����բ�ţ��ͷź�բ�Żᴦ�ڴ�״̬������ǳ�����բ�ţ��ͷŻ�բ�Żᴦ�ڹر�״̬��
***********************************************/
int iShutterControl(HANDLE p_hDevHandle, const BYTE p_byCtrType, tDevReturn* p_psStatus);
	
/***********************************************
���̿���
p_byBoxId:�����
p_byCtrlType:��������
	0x31���������������ȴ�������λ��
        0x32�������½������ȴ��½���λ��
        0x33��ֹͣ��
	0x34�������������ȴ���λ��
	0x35�������½����ȴ���λ
***********************************************/
int iTrayControl(HANDLE p_hDevHandle, const BYTE p_byBoxId, const BYTE p_byCtrlType, tDevReturn* p_psStatus);
	
/***********************************************
�������
p_byMotorId:�����
	0x01��A ������
	0x02��B ������
	0x03�������
p_byCtrlType:��������
	0x21����ת��
	0x22����ת��
	0x23��ɲ����
	0x24��ֹͣ
***********************************************/
int iMotorControl(HANDLE p_hDevHandle, const BYTE p_byMotorId, const BYTE p_byCtrlType, tDevReturn* p_psStatus);
	
/***********************************************
����������
p_byRouterType:����������
	0x52��A���任������
	0x53�������任����
p_byCtrlType:��������
	0x51���������򿪣�A ������գ�
	0x52���������رգ�B ������գ�
***********************************************/
int iRouterControl(HANDLE p_hDevHandle, const BYTE p_byRouterType, const BYTE p_byCtrlType, tDevReturn* p_psStatus);


#ifdef __cplusplus
}
#endif

#endif
















