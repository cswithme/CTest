#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "TypeDef.h"

//定义类型别名
typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned int DWORD;

//0xba
#define MAKEWORD(a, b)      ((WORD)(((BYTE)((DWORD)(a) & 0xff)) | ((WORD)((BYTE)((DWORD)(b) & 0xff))) << 8))
#define PRINTINTVALUE(value)  printf(#value"[%d]\n", value);

void sigCallFunc(int iSig)
{
	printf("Custom sigCallFunc called %d\n", iSig);
}

//void (*signal(int sig,void (*func)(int)))(int)
void (*signal(int iSig, void (*func)(int)))(int)
{
	puts("signal func called!");
	if(func != NULL)
		func(iSig);

	return func;
}

typedef struct
{
	int a;
	int b;
	int c;
	int d;
} ST_TEST;

int main()
{
	puts("Test Begin!");

	char szTemp[] = { 0x7b, 0x22, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x22, 0x3a, 0x7b, 0x22, 0x61, 0x72, 0x67, 0x31, 0x22, 0x3a, 0x30, 0x2c, 0x22, 0x69, 0x6e, 0x66, 0x6f, 0x22, 0x3a, 0x7b, 0x22, 0x70, 0x6f, 0x77, 0x65, 0x72, 0x22, 0x3a, 0x33, 0x36, 0x30, 0x30, 0x31, 0x34, 0x39, 0x38, 0x30, 0x30, 0x35, 0x35, 0x30, 0x34, 0x2c, 0x22, 0x62, 0x65, 0x61, 0x6d, 0x22, 0x3a, 0x31, 0x2c, 0x22, 0x43, 0x4d, 0x53, 0x63, 0x6f, 0x72, 0x65, 0x22, 0x3a, 0x31, 0x34, 0x37, 0x2c, 0x22, 0x63, 0x68, 0x61, 0x6e, 0x6e, 0x65, 0x6c, 0x22, 0x3a, 0x30, 0x2c, 0x22, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x22, 0x3a, 0x39, 0x39, 0x7d, 0x2c, 0x22, 0x61, 0x72, 0x67, 0x32, 0x22, 0x3a, 0x30, 0x2c, 0x22, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x54, 0x79, 0x70, 0x65, 0x22, 0x3a, 0x34, 0x7d, 0x2c, 0x22, 0x74, 0x79, 0x70, 0x65, 0x22, 0x3a, 0x22, 0x61, 0x69, 0x75, 0x69, 0x5f, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x22, 0x7d};
//	char szTemp[] = {0x7b, 0x22, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e};
	puts(szTemp);
//	unsigned int uiCrc16 = CRC16(pDataBuf, iBufLen-2);
//	unsigned int uiCrcRx = (pDataBuf[iBufLen-1]<<8) + pDataBuf[iBufLen-2];
	//02 02 01 00 01 00 78 4E
//	unsigned char ucTemp[] = {0x02, 0x02, 0x01, 0x00, 0x01, 0x00, 0x78, 0x4e};
//	size_t iBufLen = sizeof(ucTemp);
//	unsigned int uiCrc16 = CRC16(ucTemp, iBufLen-2);
//	printf("uiCrc16 [%#X]\n", uiCrc16);
//	unsigned int uiCrcRx = (ucTemp[iBufLen-1]<<8) + ucTemp[iBufLen-2];
//	printf("uiCrcRx [%#X]\n", uiCrcRx);

//	unsigned char ucTemp[20] = {0};
//	memcpy(ucTemp, "\x30\x32\x33", 3);
//	for(int i=0; i<3; ++i)
//	{
//		printf("%#02x  ", ucTemp[i]);
//	}
//	putchar('\n');


//	HexToStringForLog(const unsigned char * szSrcData, int iSrcDataLength, char * szDesString, int iDesBufSize)

	//用宏定义实现字符串
//	int iTest = 123666;
//	PRINTINTVALUE(iTest);

	//字符串中用十六进制的ASCII码表示字符的方法
//	const char *pszTest = "\x41\x42\x43\x25";
//	puts(pszTest);
//	printf("%02X,%02X,%02X,%02X,%02X\n",pszTest[0], pszTest[1], pszTest[2], pszTest[3], pszTest[4]);
//	printf("%% is \x25\x25 \n");

//	printf("i[%03d]\n", 12);

//	printf("sizeof char *[%u]\n", sizeof(char *));
//	const char *pucArry[20];
//	printf("sizeof pucArry [%u]\n", sizeof(pucArry));

//	signal(233,sigCallFunc);

//	int a[5] = {1, 3, 5, 7, 9};
//	int *num[5] = {&a[0], &a[1], &a[2], &a[3], &a[4]};
//
//	int i, **p=num;
//	for(i=0; i<5; i++)
//		printf("%d\t", **p++);

//	ST_TPU_POLLING_CARD_INFO
//	printf("sizeof ST_TPU_POLLING_CARD_INFO[%u]\n", sizeof(ST_TPU_POLLING_CARD_INFO));

//	int a = (puts("1"),puts("2"),3 ,2);
//	printf("a= %d\n", a);


//    success = 0,			//成功
//    initFail = 2,			//设备连接初始化失败
//    commandFail = 3,		//设备命令执行失败
//    invalidParam = 4,		//设备命令参数非法
//    notInitialized = 5,		//设备尚未初始化

//	const char *pszErrCode[] = {"成功", "null", "设备连接初始化失败", "设备命令执行失败"};

//	IobCzGateErrorCode eErrCode = IobCzGateErrorCode::initFail;

//	enum class ES_COLOR esColor = ES_COLOR::red;
//	printf("ES_COLOR::red[%d]\n", static_cast<int>esColor);
//	printf("IobCzGateErrorCode::initFail[%s].\n", pszErrCode[eErrCode]);


//	enum class Color { red, green = 20, blue };
//	Color r = Color::blue;
//	switch(r)
//	{
//	    case Color::red  : std::cout << "red\n";   break;
//	    case Color::green: std::cout << "green\n"; break;
//	    case Color::blue : std::cout << "blue\n";  break;
//	}
//	// int n = r; // error: no scoped enum to int conversion
//	int n = static_cast<int>(r); // OK, n = 21
//	printf("int n = %d\n", n);





	//stTicketParam.iTicketType = MAKEWORD(stCardInfo.TicketType, stCardInfo.TicketMainType);
//	BYTE ucMainType = 0x00, ucSubType = 0x01;
//	int iRus = MAKEWORD(ucMainType, ucSubType);
//	printf("%#X\n", iRus);

//	struct {
//		char cSt1[2];
//		char cSt2[6];
//	} stTemp = {{1,2}, {3,4,5,6}};
//
//	char szTemp[20] = {0};
//
//	memcpy(szTemp, &stTemp, sizeof(stTemp));
//
//	for(unsigned char ucTemp=0; ucTemp<sizeof(stTemp); ++ucTemp)
//	{
//		printf("%d\t", szTemp[ucTemp]);
//	}
//	putchar('\n');


//	ST_HM_ABNORMAL_AND_STATUS_INFO stTemp;
//	printf("sizeof ST_HM_ABNORMAL_AND_STATUS_INFO is %u\n", sizeof(ST_HM_ABNORMAL_AND_STATUS_INFO));
//	printf("stTemp<%p>, stTemp+1<%p>\n", &stTemp, &stTemp+1);
//	printf("stTemp<%p>, (char*)stTemp+1<%p>\n", &stTemp, (char *)(&stTemp)+1);

	puts("Test end!");
	return 0;

}




