/*
 * basiFunc.cpp
 *
 *  Created on: 2018-6-30
 *      Author: root
 */

#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int BasiFuncTestWithCallback()
{
	bool bError = false;
	sqlite3 *ppDb;
	int iRet;

	if(!bError)
	{

		iRet = sqlite3_open_v2("/Afc/Data/MobileScan.db", &ppDb, SQLITE_OPEN_READWRITE, NULL);
		if(SQLITE_OK != iRet)
		{
			printf("open datebase error,iRet = %d\n", iRet);
			bError = true;
		}
	}


	//2. 执行查询 插入
	if(!bError)
	{
		char szSql[2048] = {0};    //SQL语句字符串
		memset(szSql, 0, sizeof(szSql));
		sprintf(szSql, "SELECT rowid,* FROM  check_tickets_trans;");

		char *szErrMsg = NULL;
		iRet = sqlite3_exec(ppDb, szSql, NULL, NULL, &szErrMsg);
		if(SQLITE_OK != iRet)
		{
			printf("exec error, iRet = %d, errorMsg[%s]\n", iRet, szErrMsg);
			sqlite3_free(szErrMsg); //xxx 此处不free会造成mem leak
			bError = true;
		}
	}

	if(!bError)
		puts("sqlite3_exec sucess!");

	sqlite3_close(ppDb);
	return bError? -1: 0;
}

int BasiFuncTest()
{
	bool bError = false;
	sqlite3 *ppDb;
	int iRet;

	if(!bError)
	{

		iRet = sqlite3_open_v2("/Afc/Data/MobileScan.db", &ppDb, SQLITE_OPEN_READWRITE, NULL);
		if(SQLITE_OK != iRet)
		{
			printf("open datebase error,iRet = %d\n", iRet);
			bError = true;
		}
	}


	//2. 执行查询 插入
	if(!bError)
	{
		char szSql[2048] = {0};    //SQL语句字符串
		memset(szSql, 0, sizeof(szSql));
		sprintf(szSql, " INSERT INTO check_tickets_trans"
				"(itpUserId, trxType, issueChannelCode, signChannelCode, cardId, "
				"cardType, handleDateTime, handleStationCode, trxAmount, overtimeAmount, "
				"lastTicketStatus, handleResultCode, lastHandleStationCode, lastHandleDateTime,tikcetTransSeq,"
				"reserve1, reserve2, need_retransmission, DEAL_DATETIME)"
				"VALUES"
				"(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, "
				"%s, %s, 1, %s); ",
				"233", "233", "123", "123",
				"123", "123", "123", "123", "123",
				"123", "123", "123", "123", "123",
				"123", "123", "123", "strftime('%Y%m%d%H%M%S','now','localtime')" );

		puts(szSql);
		char *szErrMsg = NULL;
		iRet = sqlite3_exec(ppDb, szSql, NULL, NULL, &szErrMsg);
		if(SQLITE_OK != iRet)
		{
			printf("exec error, iRet = %d, errorMsg[%s]\n", iRet, szErrMsg);
			sqlite3_free(szErrMsg); //xxx 此处不free会造成mem leak
			bError = true;
		}
	}

	if(!bError)
		puts("sqlite3_exec sucess!");

	sqlite3_close(ppDb);
	return bError? -1: 0;
}
