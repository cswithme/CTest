//============================================================================
// Name        : BaseTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct _ST_Block
{
	char block0;
	char block1;
	char block2;
	char block3;
}ST_Block;

typedef struct _ST_Message
{
	unsigned int uiBlockCnt;
	ST_Block *pstBlock;
}ST_Message;

void HexStringToHex(const char *pHexString, unsigned char *pHex, int iHexSize)
{
	if (NULL == pHexString) {
		return;
	}
	char szTemp[16] = { 0 };

	unsigned int uiTmp = 0;
	int iLength = strlen(pHexString);
	int k = 0;
	for (int i = iLength-1; i >= 0; i-=2)
	{
		if(k >= iHexSize) break;
		if(0 == i)
		{
			szTemp[0] = '0';
			szTemp[1] = pHexString[i];
		}
		else
		{
			memcpy(szTemp, pHexString + i - 1, 2);
		}
		sscanf(szTemp, "%02x", &uiTmp);
		pHex[k++] = uiTmp;
	}
	return;
}

void HexStringtoHEX(const unsigned char *pHexString, unsigned char *pHex) {
	if (NULL == pHexString) {
		return;
	}
	char szTemp[16] = { 0 };
	int k = 0;
	int iLength = strlen((char*) pHexString);
	for (int i = 0; i < iLength; i++) {
		memcpy(szTemp, pHexString + i, 2);
		sscanf(szTemp, "%x", (int*) &pHex[k++]);
		i++;
	}
	return;

}

void HexStringToHexArray(const char *pHexString, unsigned char *pHex)
{
	if (NULL == pHexString)
		return;

	char szTemp[3] = { 0 };
	unsigned int uiTmp = 0;
	int iLength = strlen(pHexString);

	for (int i = 0; i < iLength; i+=2)
	{
		memcpy(szTemp, pHexString + i, 2);
		sscanf(szTemp, "%02x", &uiTmp);
		pHex[i/2] = uiTmp;
	}
	return;
}

int main()
{
	char szAscii[5] = {0x30, 0x33, 0x35, 0x32};
	unsigned int iRus = strtoul(szAscii, NULL, 16);
	printf("iRus = %#10X\n",iRus);

//	unsigned m_uiDiNeglectMask = 0xffffffff;
//	m_uiDiNeglectMask &= ~(0x01 << 7);
//	printf("m_uiDiNeglectMask:[%#X]",m_uiDiNeglectMask);
//	const char *pszHexStr = "20170829160432";
//	unsigned char ucRus[10];
//	HexStringToHex(pszHexStr, ucRus, sizeof(ucRus));
////	HexStringtoHEX((const unsigned char *)pszHexStr,ucRus);
//	HexStringToHexArray(pszHexStr, ucRus);
//
//	for(int i=0; i<10; ++i)
//	{
//		printf("ucRus[%d] = [%02x]\n", i, ucRus[i]);
//	}
//	char szTemp[16] = {'2', '0', '\0'};
//	unsigned char ucRus[6] = {6,6,6,6,6,6};
//
//	sscanf(szTemp,"%x",(int*) &ucRus);
//	for(int i=0; i<6; ++i)
//	{
//		printf("ucRus[%d] = [%02x]\n", i, ucRus[i]);
//	}

//	char szSendBuff[20] = {0};
//
//	ST_Block stBlock[3] = {{0,0,0,0},{1,1,1,1},{2,2,2,2}};
//	ST_Message stMessage;
//	stMessage.uiBlockCnt = 3;
//	stMessage.pstBlock = stBlock;
//	printf("stMessage.pstBlock = [%p]\n",stBlock);
//
//	memcpy(szSendBuff, &stMessage, 16);
//
//	for(int i=0; i<20; ++i)
//	{
//		printf("szSendBuff[%d] = %#X\n",i,szSendBuff[i]);
//	}
	return 0;
}
