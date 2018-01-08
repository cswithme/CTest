//============================================================================
// Name        : Qd0003ParmTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iconv.h>

#include <map>

#include "TypeDef.h"

#include <time.h>
#include <sys/time.h> //gettimeofday
#include <unistd.h>
#include <errno.h>
using namespace std;

//char* convertAnsiToUnicode()
//将以空格结尾的字符串转为C风格字符串
char* convertToCString(char *pszStr, size_t szStrLength)
{
	if(pszStr == NULL) return pszStr;

	char *pszTemp = pszStr+szStrLength-1;
	while(pszTemp != pszStr-1)
	{
		if(*pszTemp == 0x20) *pszTemp = 0;
		if(*pszTemp != 0x20 && *pszTemp!=0) break;
		--pszTemp;
	}

	return pszStr;
}

/*
 * 编码转换
 * pszOldEncoding：待转换的编码类型 可通过iconv --list查找
 * pszNewEncoding：要转换成的编码类型 +[//TRANSLIT]：遇到无法转换的字符就找相近字符替换；IGNORE ：遇到无法转换字符跳过. e.g."UNICODE//IGNORE"
 *
 * CodeConvert("GB18030" ,"UTF8",   szSrc, uSrcLen,  szRus, &uRusLen)
 *
 *!!!!!!pszSrcData和pszDestData都必须是有存储空间的不能定义为常量!!!!!!
 *!!!!!!pszSrcData和pszDestData都必须是有存储空间的不能定义为常量!!!!!!
 *
 * pszSrcData
 * iSrcLength：要转换的最长字节数
 *
 * pszDestData
 * *piDestLength：入参<pszDestData的长度>,出参<pszDestData剩余的字节数>
 *
 */
bool CodeConvert(const char *pszOldEncoding,const char *pszNewEncoding,
		 char *pszSrcData,size_t iSrcLength,char *pszDestData,size_t *piDestLength)
{
	if(NULL==pszSrcData || NULL==pszDestData)
	{
		*piDestLength = 0;
		puts("pszSrcData or pszDestData is NULL!");
		return false;
	}

	iconv_t pcd;
//	char *pszNewEncoding = "GB18030//IGNORE";
//	char *pszOldEncoding = "UTF-8";
	pcd = iconv_open(pszNewEncoding,pszOldEncoding);
	if ( (iconv_t)-1 == pcd )
	{
//		m_cLog.LogError("[%s][%s][%d]  iconv_open failure", __FILE__ , __FUNCTION__, __LINE__);
		puts("iconv_open failure");
		*piDestLength = 0;
		return false;
	}

	memset(pszDestData, 0, sizeof(pszDestData));

//	printf("Before: pszSrcData<%p>, pszDestData<%p>, &iSrcLength<%p>, piDestLength<%p>\n",
//			pszSrcData, pszDestData, &iSrcLength,piDestLength);
//	printf("Before: iSrcLength[%u], piDestLength[%u]\n", iSrcLength, *piDestLength);

	int iResult = iconv(pcd,&pszSrcData,&iSrcLength,&pszDestData,piDestLength);//iconv 调用前后 pszSrcData、pszDestData指针所指向的地址会变

//	printf("After: pszSrcData<%p>, pszDestData<%p>, &iSrcLength<%p>, piDestLength<%p>\n",
//				pszSrcData, pszDestData, &iSrcLength,piDestLength);
//	printf("After: iSrcLength[%u], piDestLength[%u]\n", iSrcLength, *piDestLength);

	if(iResult == -1)
	{
//		m_cLog.LogError("[%s][%s][%d]  iconv failure", __FILE__ , __FUNCTION__, __LINE__);
		puts("iconv failure");
		return false;
	}

	iconv_close(pcd);
	return true;
}

int func2()
{
	FILE * fp  = fopen ("/Afc/SoftUpdate/currentversion/PRM.0006.9900.000009", "r");
//	FILE * fp  = fopen ("/Afc/SoftUpdate/currentversion/PRM.0006.9900.000002", "r");
	//  /Afc/SoftUpdate/currentversion/PRM.0006.9900.000002
	if (fp == NULL)
	{
		puts("Open file Fail");
		printf("[%s][%s][%d]bisl Open file Fail, errno=%d, reason<%s>!.", __FILE__ , __FUNCTION__, __LINE__,
						errno, strerror(errno));
		return -1;
	}

	//1.包头
	if (fseek(fp, 0x16, SEEK_SET) != 0)
		return -1;

	//2.1灯光提示记录数
	unsigned long ulLightCnt = 0;
	size_t iReadCnt = fread((void *)&ulLightCnt, sizeof(unsigned long), 1, fp);

	if(iReadCnt != 1)
	{
		printf("read file length err, iReadCnt[%u]\n",iReadCnt);
		return -1;
	}
	printf("灯光提示记录数:%lu\n",ulLightCnt);

	//2.2 灯光提示记录
	ST_PARM006_LIGTH_INFO stLightInfo[10];	memset(stLightInfo, 0, sizeof(stLightInfo));
	iReadCnt = fread((void *)stLightInfo, sizeof(ST_PARM006_LIGTH_INFO), ulLightCnt, fp);
	if(iReadCnt != ulLightCnt)
	{
		puts("read file length err2");
		return -1;
	}

	for(unsigned int i=0; i<ulLightCnt; i++)
	{
		//参数灯光提示名称为ansi，转为UTF-8
		size_t uSrcLen = sizeof(stLightInfo[i].szLightName);
		char szTransRus[50] = {0};
		size_t uRusLen =sizeof(szTransRus);
		if(!CodeConvert("GB18030" ,"UTF8//IGNORE", stLightInfo[i].szLightName,uSrcLen, szTransRus,&uRusLen))
		{
			puts("CodeConvert fail!");
			return -1;
		}
		convertToCString(szTransRus, sizeof(szTransRus)); //去掉尾部的空格
		memcpy(stLightInfo[i].szLightName, szTransRus, strlen(szTransRus)+1);

		printf("ulLightID[%lu], ucLightFlag[%#04x], szLightName[%s]\n",stLightInfo[i].ulLightID, stLightInfo[i].ucLightFlag,
				stLightInfo[i].szLightName);
	}

	//3.1 声音提示记录数
	unsigned long ulSoundCnt = 0;
	iReadCnt = fread((void *)&ulSoundCnt, sizeof(unsigned long), 1, fp);

	if(iReadCnt != 1)
	{
		printf("read file length err, iReadCnt[%u]\n",iReadCnt);
		return -1;
	}
	printf("灯光提示记录数:%lu\n",ulSoundCnt);

	//3.2 声音提示记录
	ST_PARM006_SOUND_INFO stSoundInfo[15];	memset(stSoundInfo, 0, sizeof(stSoundInfo));
	iReadCnt = fread((void *)stSoundInfo, sizeof(ST_PARM006_SOUND_INFO), ulSoundCnt, fp);
	if(iReadCnt != ulSoundCnt)
	{
		puts("read file length err2");
		return -1;
	}

	for(unsigned int i=0; i<ulSoundCnt; i++)
	{
		//szSoundName名称为ansi，转为UTF-8
		size_t uSrcLen = sizeof(stSoundInfo[i].szSoundName);
		char szTransRus[50] = {0};
		size_t uRusLen =sizeof(szTransRus);
		if(!CodeConvert("GB18030" ,"UTF8//IGNORE", stSoundInfo[i].szSoundName,uSrcLen, szTransRus,&uRusLen))
		{
			puts("CodeConvert fail!");
			return -1;
		}
		convertToCString(szTransRus, sizeof(szTransRus)); //去掉尾部的空格
		memcpy(stSoundInfo[i].szSoundName, szTransRus, strlen(szTransRus)+1);

		printf("ulSoundId[%lu], szSoundName[%s], szSoundFileName[%s]\n",stSoundInfo[i].ulSoundId, stSoundInfo[i].szSoundName,
				convertToCString(stSoundInfo[i].szSoundFileName, sizeof(stSoundInfo[i].szSoundFileName)));
	}

	fclose(fp);
	return 0;
}

int func()
{
	FILE * fp  = fopen ("/Afc/PRM.0003.9900.000062", "r");

	if (fp == NULL)
	{
		puts("Open file Fail");
		return -1;
	}

	//1.包头
	if (fseek(fp, 0x1A, SEEK_SET) != 0)
		return -1;

	//2.1票卡芯片类型记录数
	unsigned int uiPhyTypeCnt = 0;
	//ST_PARM_CARD_PHY_INFO
	size_t iReadCnt = fread((void *)&uiPhyTypeCnt, sizeof(unsigned int), 1, fp);
	if(iReadCnt != 1)
	{
		puts("read file length err");
		return -1;
	}
	printf("uiPhyTypeCnt = %d\n",uiPhyTypeCnt);

	//2.2票卡芯片类型
	if (fseek(fp, uiPhyTypeCnt*sizeof(ST_PARM_CARD_PHY_INFO), SEEK_CUR) != 0)//累计优惠分段记录与保留字段不需要读取，跳过
	{
		puts("fseek Error!");
		return -1;
	}
//	ST_PARM_CARD_PHY_INFO stCardPhyInfo[10];
//	iReadCnt = fread((void *)&stCardPhyInfo, sizeof(ST_PARM_CARD_PHY_INFO), uiPhyTypeCnt, fp);
//	if(iReadCnt != uiPhyTypeCnt)
//	{
//		puts("read file length err");
//		return -1;
//	}
//	printf("iReadCnt = %d\n", iReadCnt);
//	for(unsigned int i=0; i<iReadCnt; ++i)
//	{
//		printf("<%d> ucCardPhyType[%d], lMaxTradeCnt[%ld], lValidDay[%ld]\n", i,
//				stCardPhyInfo[i].ucCardPhyType, stCardPhyInfo[i].lMaxTradeCnt, stCardPhyInfo[i].lValidDay);
//	}

	//3.1车票类型记录数
	unsigned int uiTypeCnt = 0;
	iReadCnt = fread((void *)&uiTypeCnt, sizeof(unsigned int), 1, fp);
	if(iReadCnt != 1)
	{
		puts("read file length err");
		return -1;
	}
	printf("uiTypeCnt = %d\n",uiTypeCnt);

	//3.2车票类型记录
	for(unsigned int i=0; i<uiTypeCnt; ++i)
	{
		ST_PARM0003_CARD_INFO stCardInfo;

		memset(&stCardInfo, 0, sizeof(ST_PARM0003_CARD_INFO));
		iReadCnt = fread((void *)&stCardInfo, sizeof(ST_PARM0003_CARD_INFO), 1, fp);
		if(iReadCnt != 1)
		{
			puts("read file length err");
			return -1;
		}

		//参数中卡中文名为ansi，转为UTF-8
		size_t uSrcLen = sizeof(stCardInfo.TicketTypeChineseName);
		char szTransRus[60] = {0};
		size_t uRusLen =sizeof(szTransRus);
		if(!CodeConvert("GB18030" ,"UTF8//IGNORE", stCardInfo.TicketTypeChineseName,uSrcLen, szTransRus,&uRusLen))
		{
			puts("CodeConvert fail!");
			return -1;
		}
		convertToCString(szTransRus, sizeof(szTransRus)); //去掉尾部的空格

		memset(stCardInfo.TicketTypeChineseName, 0, sizeof(stCardInfo.TicketTypeChineseName));
		memcpy(stCardInfo.TicketTypeChineseName, szTransRus, strlen(szTransRus)+1); //拷贝回原来的结构体中

		printf("TicketMainType[%#04X], TicketType[%#04X], AlertLightID[%d], AlertSoundID[%d], TicketTypeChineseName[%s],TicketTypeEnglishName[%s]\n",
				stCardInfo.TicketMainType, stCardInfo.TicketType, stCardInfo.AlertLightID, stCardInfo.AlertSoundID,stCardInfo.TicketTypeChineseName,
				convertToCString(stCardInfo.TicketTypeEnglishName,sizeof(stCardInfo.TicketTypeEnglishName))
				);

		//优惠等级记录数
		unsigned int uiFavourCnt = 0;
		iReadCnt = fread((void *)&uiFavourCnt, sizeof(unsigned int), 1, fp);
		if(iReadCnt != 1)
		{
			puts("read file length err");
			return -1;
		}
//		printf("uiFavourCnt[%d]\n", uiFavourCnt);

		if (fseek(fp, uiFavourCnt*sizeof(ST_PARM0003_FAVOUR_RANGE)+32, SEEK_CUR) != 0)//累计优惠分段记录与保留字段不需要读取，跳过
		{
			puts("fseek Error!");
			return -1;
		}

	}
	fclose(fp);
	return 0;
}

int main()
{
	struct timespec tsBegin,tsEnd;
	clock_gettime(CLOCK_REALTIME, &tsBegin);
	printf("Before Call Func: tv_sec[%ld], tv_usec[%ld](ns)\n", tsBegin.tv_sec, tsBegin.tv_nsec);

	func();
	puts("\n\nFunc2");
	func2();

	clock_gettime(CLOCK_REALTIME, &tsEnd);
	printf("After Call Func: tv_sec[%ld], tv_usec[%ld](ns)\n", tsEnd.tv_sec, tsEnd.tv_nsec);

	printf("Time spend:tv_sec[%ld], tv_usec[%ld](ns)\n", tsEnd.tv_sec-tsBegin.tv_sec,
			tsEnd.tv_nsec-tsBegin.tv_nsec);

//	char szTemp[33] = {0xC6, 0xD5, 0xCD, 0xA8, 0xB5, 0xA5, 0xB3, 0xCC, 0xC6, 0xB1, 0x20,
//			0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
//			0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
//	size_t uTempLen = sizeof(szTemp);
//
//	char szTransRus[60] = {0};
//	size_t uRusLen =sizeof(szTransRus);
//
//	if(!CodeConvert("GB18030" ,"UTF8//IGNORE", szTemp,uTempLen, szTransRus,&uRusLen))
//	{
//		puts("CodeConvert fail!");
//		return -1;
//	}
//
//	for(size_t i=0; i<sizeof(szTransRus); ++i)
//		printf("%02X ", *((unsigned char*)szTransRus + i));
//	putchar('\n');
//
//
//	convertToCString(szTransRus, sizeof(szTransRus));
//	for(size_t i=0; i<sizeof(szTransRus); ++i)
//		printf("%02X ", *((unsigned char*)szTransRus + i));
//	putchar('\n');
//
//	printf("string[%s]\n", szTransRus);
//
//	const char *pszstr = "1普通单程票";
//
//	for(unsigned int i=0; i<strlen(pszstr)+1; ++i)
//	{
//		printf("%02X ",*((const unsigned char *)pszstr+i));
//	}
//	putchar('\n');

	return 0;
}
