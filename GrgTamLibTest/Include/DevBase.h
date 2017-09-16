

#if !defined(AFX_ODEVBASE_H__8BBC195A_112D_11D4_B865_5254AB1A7D30__INCLUDED_COM_)
#define AFX_ODEVBASE_H__8BBC195A_112D_11D4_B865_5254AB1A7D30__INCLUDED_COM_

#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <termios.h>
#include <fcntl.h> 
#include <ctype.h> 
#include <netinet/in.h>
#include <netdb.h>
#include <stdarg.h>
#include <getopt.h>
#include <math.h>
#include <dlfcn.h>
#include <limits.h>
#include <dirent.h>

#include <sys/ioctl.h>
#include <sys/types.h> 
//#include <sys/socket.h>
//#include <sys/time.h> 
//#include <sys/stat.h>  

//#include "typedef.h"
// 以一字节对齐 [6/7/2012 lmqi]
#pragma pack(push, 1)
//#include "libusbwrapper/libusbwrapper.h"

// #ifndef BYTE
// 	#define BYTE unsigned char
// #endif
// 
// #ifndef UINT
// 	#define UINT unsigned int
// #endif

typedef  unsigned char BYTE;
typedef  unsigned int  UINT;

#define CTSFLOW 1
#define RTSFLOW 2

// 通用定义
#define SUCCESS					0	// 成功
#define FAIL					1	// 失败

#define ERRORFLAG_CLEAR			0	// 清除错误缓存区

// 日志信息类别
#define CATALOG_FATAL			0	// 致命错误
#define	CATALOG_NORMAL			1	// 一般信息
#define	GATALOG_NOTE			2	// 提示信息

// MSG type
#define MSG_GENERAL				1	// 一般信息
#define	MSG_COMM_SEND			2	// 发送数据
#define	MSG_COMM_REV			3	// 接收数据

#define TCPIP_ADDRESS_LENGTH	50
#define USB_PIPES_LENGTH		50
#define USB_EXTENDSTR_LENGTH	256

// Parity
#define NOPARITY            0
#define ODDPARITY           1
#define EVENPARITY          2
#define MARKPARITY          3
#define SPACEPARITY         4

// Stopbit
#define ONESTOPBIT          0
#define ONE5STOPBITS        1	// no this setting in Linux, but only define here.
#define TWOSTOPBITS         2


//==ODevBase==BEGIN==ERROR==DEFINE=======================================================================
#define E_DEVBASE_BASE				    	900

#define E_DEVBASE_LOGICNAME_NULL		(E_DEVBASE_BASE + 20)	// 920 设备的逻辑设备名为空
#define E_DEVBASE_OPEN_COMCFGFILE		(E_DEVBASE_BASE + 21)	// 921 打开GRGDTATM_CommCfg.ini文件失败

#define E_DEVBASE_READ_COMID			(E_DEVBASE_BASE + 30)	// 930 读取配置ComID失败
#define E_DEVBASE_READ_COMMTYPE			(E_DEVBASE_BASE + 31)	// 931 读取配置CommType失败
#define E_DEVBASE_READ_COMBAUD			(E_DEVBASE_BASE + 32)	// 932 读取配置ComBaud失败
#define E_DEVBASE_READ_VID_PID			(E_DEVBASE_BASE + 33)	// 933 读取VID及PID失败
#define E_DEVBASE_READ_INICFGFILE		(E_DEVBASE_BASE + 34)	// 934 打开IniCfgFileName项配置的文件失败
#define E_DEVBASE_ACCESS_INICFG			(E_DEVBASE_BASE + 35)	// 935 读取或者设置IniCfgFileName文件中的配置失败

#define E_DEVBASE_INVALID_COMMTYPE		(E_DEVBASE_BASE + 50)	// 950 配置CommType无效
#define E_DEVBASE_INVALID_COM_ID		(E_DEVBASE_BASE + 51)	// 951 配置ComID无效
#define E_DEVBASE_INVALID_PARA			(E_DEVBASE_BASE + 52)	// 952 接收传入或传出参数失败

#define E_DEVBASE_OPEN_COM				(E_DEVBASE_BASE + 70)	// 970 打开串口失败
#define E_DEVBASE_CLOSE_COM				(E_DEVBASE_BASE + 71)	// 971 关闭串口失败
#define E_DEVBASE_ACCESS_COM			(E_DEVBASE_BASE + 72)	// 972 读取或者修改串口参数失败
#define E_DEVBASE_SEND_CMD				(E_DEVBASE_BASE + 73)	// 973 发送命令失败
#define E_DEVBASE_RECV_DATA				(E_DEVBASE_BASE + 74)	// 974 接收数据失败
#define E_DEVBASE_CLEAR_BUF				(E_DEVBASE_BASE + 75)	// 975 清除缓冲区失败


typedef enum __MIDL_IComm_0001
{	
	COMM_COM			= 1,
	COMM_COMBOARD	= COMM_COM + 1,
	COMM_USB				= COMM_COMBOARD + 1,
	COMM_TCPIP			= COMM_USB + 1
}tCommType;

#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;
#endif /* GUID_DEFINED */

struct  tComInfo
{
    unsigned int iDatabits;
    unsigned int iStopbits;
    unsigned int iParity;

    unsigned int iComID;
    unsigned int iBaudRate;
    unsigned int iFlowcontrol;

	// 以下为预留.
    unsigned int fParity;
    unsigned int fOutxCtsFlow;
    unsigned int fOutxDsrFlow;
    unsigned int fDtrControl;
    unsigned int fDsrSensitivity;
    unsigned int fTXContinueOnXoff;
    unsigned int fOutX;
    unsigned int fInX;
    unsigned int fRtsControl;
    unsigned short XonLim;
    unsigned short XoffLim;
    char XonChar;
    char XoffChar;
    unsigned int ReadIntervalTimeout;
    unsigned int ReadTotalTimeoutMultiplier;
    unsigned int ReadTotalTimeoutConstant;
    unsigned int WriteTotalTimeoutMultiplier;
    unsigned int WriteTotalTimeoutConstant;
};
struct  tComBoardInfo
{
    int iBand;
    int iDataLen;
    int iEventFlag;
    int iStopFlag;
    int iComPort;
    struct tComInfo sComInfo;
};
struct  tUSBInfo
{
    int iReserver1;
    int iReserver2;
    int iReserver3;
    int iReserver4;
};
struct  tTCPIPInfo
{
    unsigned char ipAddress[ TCPIP_ADDRESS_LENGTH ];
    int iSendPort;
    int iReceivePort;
    int iLinkMode;
};
typedef union _UCommInfo
{
    struct tComInfo sComInfo;
    struct tComBoardInfo sComBoardInfo;
    struct tUSBInfo sUSBInfo;
    struct tTCPIPInfo sTCPIPInfo;
    /* Empty union arm */
}	tCommInfo;

struct  tCommCfg
{
    tCommType eCommType;
    tCommInfo unCommInfo;
//  char __RPC_FAR *pcExtern;
};
struct  tUSBInfo2
{
    GUID sGuid;
    char acSendPipes[ USB_PIPES_LENGTH ];
    char acRecvPipes[ USB_PIPES_LENGTH ];
    char acExtendStr[ USB_EXTENDSTR_LENGTH ];
    int iReserve;
};
typedef union _UCommInfo2
{
    struct tComInfo sComInfo;
    struct tComBoardInfo sComBoardInfo;
    struct tUSBInfo2 sUSBInfo;
    struct tTCPIPInfo sTCPIPInfo;
    /* Empty union arm */
}	tCommInfo2;

struct  tCommCfg2
{
    tCommType eCommType;
    tCommInfo2 unCommInfo;
//  char __RPC_FAR *pcExtern;
};



typedef struct
{
	int		iLogicCode;			// 逻辑错误码
	int		iPhyCode;			// 物理错误码
	int		iHandle;			// 处理方法：0-不处理 1-初始化 2-重发命令
	int		iType;				// 错误类型：0-警告 1-严重

	char	acDevReturn[128];	// 硬件返回信息
	char	acReserve[128];		// 保留信息
} tDevReturn;

class ODevBase
{
public:
	ODevBase();
	virtual ~ODevBase();

	// 设置驱动的逻辑设备名
	void vSetLogicalDevName(const char* p_pcLogicalDevName);
	void vGetLogicalDevName(char* p_pcLogicalDevName);

	// 查找并读取GRGDTATM_CommCfg.ini文件中的配置信息
	int iPreInitDev();	
	
	// 获取默认的串口配置
	int iGetDefaultCommConfig(tCommCfg& p_sCommCfg);	
	// 获取默认的串口或者USB配置
	int iGetDefaultCommConfig2(tCommCfg2& p_sCommCfg);

	// 打开串口，修改通信参数并建立通信。
	int iInitComm(tCommCfg p_sCommCfg, bool p_bEnableEvents = false);
	// 打开串口或USB，修改通信参数并建立通信。
	int iInitComm2(tCommCfg2 p_sCommCfg, bool p_bEnableEvents = false);

	// 发送串口命令
	int iSendCommand(const BYTE *p_pbySendCmd, UINT p_uiCmdLength, bool p_bClearRecvBuf = true, bool p_bLog = true);
	// 接收串口数据
	int iWaitResult(BYTE *p_pbyDataRecv, UINT& p_uiRecvLength, UINT p_uiTimeout, bool p_bLog = true);
	// 发送串口命令并接收串口响应数据
	int	iSendAndRecvData(
		const BYTE *p_pbySendCmd, 
		UINT p_uiCmdLength, 
		BYTE *p_pbyDataRecv, 
		UINT& p_uiRecvLength, 
		UINT p_uiTimeout,
		bool p_bClearRecvBuf = true, 
		bool p_bLog = true
		);
	// 发送串口或USB命令
	int iSendCommand2(
		const BYTE *p_pbySendCmd, 
		UINT p_uiCmdLength, 
		short p_shSendPipe, 
		bool p_bClearRecvBuf = true, 
		bool p_bLog = true
		);
	// 接收串口或USB响应数据
	int iWaitResult2(
		BYTE *p_pbyDataRecv, 
		UINT& p_uiRecvLength, 
		UINT p_uiTimeout,
		short p_shRecvPipe, 
		bool p_bLog = true
		);
	// 发送串口或USB命令，并接收串口或USB响应数据
	int	iSendAndRecvData2(
		const BYTE *p_pbySendCmd, 
		UINT p_uiCmdLength, 
		BYTE *p_pbyDataRecv, 
		UINT& p_uiRecvLength, 
		UINT p_uiTimeout,
		short p_shSendPipe, 
		short p_shRecvPipe, 
		bool p_bClearRecvBuf = true, 
		bool p_bLog = true
		);

	// 清除串口接收缓冲区。
	void vClearRecvBuf();
	
	// 清除接收缓冲区
	void vClearRecvBuf2(short p_shPipe = -1);
	
	// 关闭串口
	int iCloseComm(); 

	// 关闭USB（串口）通讯
	int iCloseComm2();

	// 预留
	int	iWriteLog(
		char *p_pcData, 
		UINT p_uiLen = 0, 
		int	p_iInfoCatalog = GATALOG_NOTE, 
		int p_iMSGType = MSG_GENERAL, 
		bool p_bBinaryData = false
		);
	
	// 硬件错误标志处理接口
	int			iGetErrorFlag();							// 读取硬件错误标志
	tDevReturn	tGetErrorFlag();							// 读取硬件错误标志
	void		vSetErrorFlag(const int p_iFlag);			// 设置硬件错误标志
	void		vSetErrorFlag(const tDevReturn p_sDevErr);	// 设置硬件错误标志

	// 以下函数是提供给驱动自己来实现	
	int	iGetVersion(char *p_pcVersion);			// 取驱动软件版本号
	int	iGetDevVersion(char *p_pcVersion);		// 取硬件版本号

	// 设备驱动通用接口
	int	iGetStatus(tDevReturn* p_sDevReturn)
	{
		return SUCCESS;
	};	
	int	iInit(tDevReturn* p_sDevReturn)	
	{
		return SUCCESS;
	};	
	int	iTest(tDevReturn* p_sDevReturn)
	{
		return SUCCESS;
	};	

	int iGetIntValue(const char *p_pcSection, const char *p_pcKeyName, int& p_iKeyValue);
	int iGetStringValue(const char *p_pcSection, const char *p_pcKeyName, char *p_pcKeyValue, UINT& p_uiLength);
    int iSetIntValue(const char *p_pcSection, const char *p_pcKeyName, long p_lKeyValue);
    int iSetStringValue(const char *p_pcSection, const char *p_pcKeyName, char *p_pcKeyValue, UINT p_uiLength);

    DWORD dwGetTickCount();
	void vDelay(int p_iMillisecond);	// 延时（毫秒）

	char			m_acVersion[32];			// 驱动版本信息
	char			m_acDevVersion[32];			// 硬件版本信息 
private:
	struct tGrgIniCfgInfo
	{
		int		iCommType;	// 通讯类型，1:串口通讯，3:USB，其它为错误配置
		int		iComID;		// 串口ID；	
		int		iComBaud;	// 串口波特率
		
		char	acSendPipes[USB_PIPES_LENGTH];		//发送管道号
		char	acRecvPipes[USB_PIPES_LENGTH];		//接收管道号
		char	acIniCfgFileName[32];	// 配置文件配置
		char	acDevCommLogID[32];		// 通信日志配置
		char	acExtendStr[32];		// 硬件返回信息
		int		aiReserved[32];			// 保留
	};
	int iGetModuleFileName(char *p_pcFileName, int p_iNameSize);	

	int iLoadCfgInfo(tGrgIniCfgInfo& p_sCfg);	// 读取配置文件中的配置信息

	int iHexToDec(char p_cData);	
	int iHexToInt(char *p_pcData, UINT p_uiLength);
	int iMakeUpper(char *p_pcData, UINT p_uiLength);
	void vSetVersion(char *p_pcVersion);		// 设置软件版本号
	

private:
	tDevReturn		m_sDevErr;					// 错误描述结构
	char			m_acTrace[200];				// 日志信息的临时变量: obsolete
	
	int m_iHandle;
	class CIniFile *m_poIniFile;		// 通信配置文件
	class CIniFile *m_poOtherIniFile;	// 其他配置文件

	char m_acLogicalDevName[256];		// 设备逻辑标识名称 
	char m_acGrgIniPath[256];				// 通信配置文件所在的目录
	char m_acGrgIniPathName[256];			// 通信配置文件路径及文件名
	char m_acOtherIniPathName[256];				// 其他配置文件路径及文件名

	class ODevDriverLog	*m_pOLog;
	BOOL	m_bLog;		// 是否记录日志
	int		m_iComID;
	BOOL	m_bCom;		// 设定的通信是USB通信还是串口通信

	// USB通信类 [2/22/2012 lmqi]
	class CLibUsbWrapper *m_pCLibUsb;
	int		m_iVid;
	int		m_iPid;

	tGrgIniCfgInfo m_sCfg;
};

#pragma pack(pop)

#endif //_COMM_H_ 
