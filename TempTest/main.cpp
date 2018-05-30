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


int main()
{
	puts("Test Begin!");

	//用宏定义实现字符串
//	int iTest = 123666;
//	PRINTINTVALUE(iTest);

	//字符串中用十六进制的ASCII码表示字符的方法
//	const char *pszTest = "\x41\x42\x43\x25";
//	puts(pszTest);
//	printf("%02X,%02X,%02X,%02X,%02X\n",pszTest[0], pszTest[1], pszTest[2], pszTest[3], pszTest[4]);
//	printf("%% is \x25\x25 \n");

	int i = 010;
	printf("i=%#x\n", i);

//	signal(233,sigCallFunc);


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




