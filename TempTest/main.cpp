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

int main()
{
	puts("Test Begin!");

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


	enum class Color { red, green = 20, blue };
	Color r = Color::blue;
	switch(r)
	{
	    case Color::red  : std::cout << "red\n";   break;
	    case Color::green: std::cout << "green\n"; break;
	    case Color::blue : std::cout << "blue\n";  break;
	}
	// int n = r; // error: no scoped enum to int conversion
	int n = static_cast<int>(r); // OK, n = 21
	printf("int n = %d\n", n);



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



	puts("Test end!");
	return 0;

}




