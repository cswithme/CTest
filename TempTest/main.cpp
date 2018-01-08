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

#ifdef BSL
	puts("BSL Define!");
#else
	puts("BSL NOT Define");
#endif


	puts("Test end!");
	return 0;

}




