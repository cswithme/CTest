/*
 * main.cpp
 *
 *  Created on: 2018-5-24
 *      Author: root
 */

#include "PubSleDb.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int main()
{
	puts("Test begin!");

	int iRet = SQLITE_OK;

	PubSleDb *m_pDb = new PubSleDb;

	if(m_pDb == NULL )	puts("PubSleDb实例创建失败！");
	else	puts("PubSleDb实例创建成功！");

	m_pDb->InitDb("/Afc/Data/MobileScan.db", true, true);

	char szSql[2048] = {0}, szError[512] = {0};    //SQL语句字符串

	//2. 执行查询 插入
	memset(szSql, 0, sizeof(szSql));
	memset(szError, 0, sizeof(szError));


	sprintf(szSql, " INSERT INTO check_tickets_trans"
			"(itpUserId, trxType, issueChannelCode, signChannelCode, cardId, "
			"cardType, handleDateTime, handleStationCode, trxAmount, overtimeAmount, "
			"lastTicketStatus, handleResultCode, lastHandleStationCode, lastHandleDateTime,tikcetTransSeq,"
			"reserve1, reserve2, need_retransmission, DEAL_DATETIME)"
			"VALUES"
			"(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, "
			"%s, %s, 1, %s); ",
			"667", "556", "123", "123",
			"123", "123", "123", "123", "123",
			"123", "123", "123", "123", "123",
			"123", "123", "123", "strftime('%Y%m%d%H%M%S','now','localtime')" );

//	m_pDb->SqlitePrepare(szSql);
//	m_pDb->
	for(unsigned int i=0; i<5; ++i)
	{
		iRet = m_pDb->Execute(szSql, szError);
	}

	if(SQLITE_OK != iRet)
	{
		printf(" UpdateTrans failed, szError = %s\n", szError);
		return -1;
	}
	puts("插入成功！");


//	sleep(10);

	//执行查询 获取表
	memset(szSql, 0, sizeof(szSql));
	memset(szError, 0, sizeof(szError));
	int iRow = 0, iColumn = 0;
	char **ppDbResult = NULL;

	sprintf(szSql, "select rowid, itpUserId, trxType, issueChannelCode, signChannelCode, cardId,"
		"cardType, handleDateTime, handleStationCode, trxAmount, overtimeAmount, lastTicketStatus,"
		"handleResultCode, lastHandleStationCode, lastHandleDateTime,tikcetTransSeq, reserve1, reserve2 "
//		"from check_tickets_trans where need_retransmission != 0 ORDER BY rowid DESC limit 10;");
		"from check_tickets_trans where need_retransmission != 0;");

	iRet = m_pDb->GetTable(szSql, &ppDbResult, &iRow, &iColumn, szError);
	printf("iRet = [%d], iRow = [%d], iColumn = [%d]\n", iRet, iRow, iColumn);

	if(SQLITE_OK != iRet)
	{
		printf("获取信息失败, %s\n", szError);
		m_pDb->FreeTable(ppDbResult);
		return -1;
	}

	if(iRow <=0)
	{
		puts("没有获取到信息");
		m_pDb->FreeTable(ppDbResult);
		return -1;
	}

	putchar('\n');
	for(int iRowCnt=0; iRowCnt<iRow; ++iRowCnt)
	{
		printf("Row[%d]: ", iRowCnt);
		for(int iColumnCnt=0; iColumnCnt<iColumn; ++iColumnCnt)
		{
			printf("Column[%d] <%s>\t",iColumnCnt, ppDbResult[iRowCnt * iColumn + iColumnCnt]==NULL? "NULL": ppDbResult[iRowCnt * iColumn + iColumnCnt]);
		}
		putchar('\n');
	}

	m_pDb->FreeTable(ppDbResult);

	m_pDb->CloseDb();
	delete m_pDb;

	puts("Test end!");

	return 0;
}
