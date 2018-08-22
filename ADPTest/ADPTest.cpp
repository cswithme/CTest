//============================================================================
// Name        : ADPTest.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"  {
#endif

#include "EXDATA.h"
#include "AFCDataPackComm.h"

#ifdef __cplusplus
}
#endif

using namespace std;

int main()
{

	puts("Test begin!");




#if 0
	ADP 		stAdp;
	CssFile_t     stFile;
	FILE			*fp;

	const char *pathFileName = "./temp.txt";

	fp = fopen(pathFileName, "wb+");	//打开文件

	adpstdio_create(&stAdp,  fp,  ADP_ENCODE);//adp 文件初始化

	if(0 == adp_CssFile_t(&stAdp,&stFile))	// 根据文件结构与初始化的adp结构生成文件
	{
		puts("adp_CashBoxChangeData_t failed");
		return -1;
	}

	fclose(fp);	//关闭文件


	/*释放内存*/
//	adp_free((adpproc_t)adp_CssFile_t,(char *)&stFile);
#endif

#if 1
	PrjFileOper_t stCashBoxChangeData;  memset(&stCashBoxChangeData, 0, sizeof(PrjFileOper_t));

//	CurrencyCodeQty_t stDenoInfo[15]; memset(stDenoInfo, 0, sizeof(stDenoInfo));

	stCashBoxChangeData.CurCount.data.data = 3;

	CurrencyCodeQty_t *pstDenoInfo = (CurrencyCodeQty_t *)calloc(sizeof(CurrencyCodeQty_t), stCashBoxChangeData.CurCount.data.data);
	stCashBoxChangeData.CurrencyCodeQty = pstDenoInfo;

	unsigned int uiDataLen = adp_sizeof((adpproc_t)adp_PrjFileOper_t , &stCashBoxChangeData);
	printf("uiDataLen[%u]\n", uiDataLen);

	ADP stAdp; 	memset(&stAdp, 0, sizeof(ADP));

	char szTempBuf[1024 * 10] = { 0 };
	adpmem_create(&stAdp, szTempBuf, sizeof(szTempBuf), ADP_ENCODE);
	if(0 == adp_PrjFileOper_t(&stAdp, &stCashBoxChangeData))
	{
		puts("adp_CashBoxChangeData_t failed");
		return -1;
	}

	adp_free((adpproc_t)adp_PrjFileOper_t,(char *)&stCashBoxChangeData);

#endif

#if 0
	ADP 		stAdp;
	CssFile_t     stFile;	memset(&stFile, 0, sizeof(CssFile_t));
	char szTempBuf[1024 * 10] = { 0 };
	adpmem_create(&stAdp, szTempBuf, sizeof(szTempBuf), ADP_ENCODE);

	if(0 == adp_CssFile_t(&stAdp, &stFile))
	{
		puts("adp_CashBoxChangeData_t failed");
		return -1;
	}

	adp_free((adpproc_t)adp_CssFile_t,(char *)&stFile);
#endif

	puts("Test end");

	return 0;
}
