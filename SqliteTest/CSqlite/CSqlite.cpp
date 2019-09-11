/*
 * CSqlite.cpp
 *
 *  Created on: 2019-8-15
 *      Author: root
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h> //gettimeofday
#include "CSqlite.h"

CSqlite::CSqlite(const char* pszMainDbPath)
{
	if(NULL != pszMainDbPath){
//		SQLITE_OPEN_READONLY
//		SQLITE_OPEN_READWRITE
//		SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE
		printf("Open database: %s\n", pszMainDbPath);
//		int iRet = sqlite3_open(pszMainDbPath, &_pDb);
		int iRet = sqlite3_open_v2(pszMainDbPath, &_pDb, SQLITE_OPEN_READWRITE, NULL);
		if(SQLITE_OK != iRet){
			printf("sqlite3_open_v2 fail!\n");
			_pDb = NULL;
			exit(-1);
		}

//		iRet = sqlite3_busy_timeout(_pDb, 5000);//如果超时设定超时时间
	}
}

CSqlite::~CSqlite()
{
	if(NULL != _pDb) sqlite3_close(_pDb);
}


const char *CSqlite::GetVersion()
{
	return sqlite3_libversion();
}

int CSqlite::Execute(const char *pszSql, char *pszErrMsg)
{
	int iRet = 0;
	char *pMsg = NULL;

	iRet = sqlite3_exec(_pDb, pszSql, NULL, 0, &pMsg);
	if(SQLITE_OK != iRet) {
		if(pMsg != NULL) strncpy(pszErrMsg, pMsg, strlen(pMsg));
		sqlite3_free(pMsg);
	}

	return iRet;
}


int CSqlite::GetTable(const char *pszSql, char ***pppszResult, int *piRow, int *piColumn, char *pszErrMsg)
{
	int iRet = 0;
	char *pMsg = NULL;

	iRet = sqlite3_get_table(_pDb, pszSql, pppszResult, piRow, piColumn, &pMsg);
	if(SQLITE_OK != iRet) {
		if(pMsg != NULL) strncpy(pszErrMsg, pMsg, strlen(pMsg));
		sqlite3_free(pMsg);
	}

	return iRet;
}

void CSqlite::FreeTable(char **ppDbResult)
{
	sqlite3_free_table( ppDbResult );
}


int CSqlite::SqlitePrepare(const char *pszSql)
{
	if(pszSql == NULL)
	{
		return -1;
	}
	return sqlite3_prepare(_pDb, pszSql, -1, &m_pstmt, 0);
}

int CSqlite::SqliteStep()
{
	return sqlite3_step(m_pstmt);
}

void CSqlite::FreeStmt()
{
	sqlite3_finalize(m_pstmt);
}

int CSqlite::GetUdLength(int iCol)
{
	return sqlite3_column_bytes(m_pstmt, iCol);
}

const void * CSqlite::GetUd(int iCol)
{
	return sqlite3_column_blob(m_pstmt, iCol);
}

int CSqlite::GetInt(int iCol)
{
	return sqlite3_column_int(m_pstmt, iCol);
}

const char* CSqlite::GetString(int iCol)
{
	return (const char*)sqlite3_column_text(m_pstmt, iCol);
}

void printGetTableRus(char **ppszRus, int iRow, int iColumn)
{
	for(int i=0; i<=iRow; ++i){
		printf("Row%d:", i);
		for(int j=0; j<iColumn; ++j){
			printf("%s \t", ppszRus[i*iColumn+j]);
		}
		printf("\n");
	}
}

bool LoadFaultTrans(CSqlite *pDb)
{
	int iRet = -1;            //执行结果
	char szSql[2048] = {0};    //SQL语句字符串
	char szError[512] = {0};

	int iUdsn = 0;

	int iRow = 0;
	int iColumn = 0;
	char **ppDbResult = NULL;


	memset (szSql, 0, sizeof(szSql));
	sprintf(szSql, "select UDSN from DATA_YKT_TRAN where UP_FLAG != 0 ORDER BY UDSN DESC;");

	printf("[%s][%s][%d szSql = [%s]\n", __FILE__, __FUNCTION__, __LINE__, szSql);
	iRet = pDb->GetTable(szSql, &ppDbResult, &iRow, &iColumn, szError);
	printf("[%s][%s][%d] iRet = [%d], iRow = [%d], iColumn = [%d]\n", __FILE__, __FUNCTION__, __LINE__, iRet, iRow, iColumn);

	if(SQLITE_OK != iRet) {
		printf("[%s][%s][%d] 获取 DATA_YKT_TRAN 信息失败, %s \n", __FILE__, __FUNCTION__, __LINE__, szError);
		if(ppDbResult != NULL) {
			pDb->FreeTable(ppDbResult);
			ppDbResult = NULL;
		}
		return false;
	}

	if(iRow <= 0) {

		printf("[%s][%s][%d] 从 DATA_YKT_TRAN 没有获取到信息 \n", __FILE__, __FUNCTION__, __LINE__);
		if(ppDbResult != NULL) {
			pDb->FreeTable(ppDbResult);

			ppDbResult = NULL;
		}

		return true;
	}


	struct timespec tsBegin, tsEnd;
	clock_gettime(CLOCK_MONOTONIC, &tsBegin);

	for(int i = 1; i <= iRow; i++) {

		iUdsn = atoi(ppDbResult[i*iColumn]);

		memset (szSql, 0, sizeof(szSql));
		sprintf(szSql, "select UD_CONTENT from DATA_YKT_TRAN where UDSN == %d;",iUdsn);

		printf("[%s][%s][%d] szSql = [%s] \n]", __FILE__, __FUNCTION__, __LINE__, szSql);

		if(SQLITE_OK != pDb->SqlitePrepare(szSql)) {
			printf("[%s][%s][%d]sqlite3_prepare失败  SQL:%s \n", __FILE__, __FUNCTION__, __LINE__, szSql);
			if(ppDbResult != NULL) {
				pDb->FreeTable(ppDbResult);

				ppDbResult = NULL;
			}
			return false;
		}

		while(1) {

			if(SQLITE_ROW != pDb->SqliteStep()) {
				break;
			}

			int  iUDLength = 0;
			const void *pUDContent;

			iUDLength = pDb->GetUdLength();
			pUDContent = pDb->GetUd();

			if(iUDLength < 1) {
				printf("[%s][%s][%d]Ud数据长度错误 iUDLength = %d \n", __FILE__, __FUNCTION__, __LINE__, iUDLength);
				continue;
			}

			printf("[%s][%s][%d]UDLength(%d), UDContent:%s \n", __FILE__, __FUNCTION__, __LINE__, iUDLength, (const char*)pUDContent);
		}

		pDb->FreeStmt();
	}

	clock_gettime(CLOCK_MONOTONIC, &tsEnd);
	uint32_t u32TimeSpendMs = (tsEnd.tv_sec - tsBegin.tv_sec)*1000 + (tsEnd.tv_nsec - tsBegin.tv_nsec)/1000000;
	printf("[%s][%s][%d] bisl for test u32TimeSpendMs(%d)\n", __FILE__, __FUNCTION__, __LINE__, u32TimeSpendMs);


	if(ppDbResult != NULL) {
		pDb->FreeTable(ppDbResult);
		ppDbResult = NULL;
	}

	return true;
}

bool LoadFaultTrans2(CSqlite *pDb)
{
	struct timespec tsBegin, tsEnd;
	clock_gettime(CLOCK_MONOTONIC, &tsBegin);

	char szSql[2048];	memset (szSql, 0, sizeof(szSql));
//	sprintf(szSql, "select UDSN,UD_CONTENT from DATA_YKT_TRAN where UP_FLAG != 0 ORDER BY UDSN DESC limit 1000;");
	sprintf(szSql, "select UDSN,UD_CONTENT,BUS_DATE from DATA_YKT_TRAN where UP_FLAG != 0");
	if(SQLITE_OK != pDb->SqlitePrepare(szSql)) {
		printf("[%s][%s][%d]sqlite3_prepare失败  SQL:%s \n", __FILE__, __FUNCTION__, __LINE__, szSql);
		return false;
	}

	while(SQLITE_ROW == pDb->SqliteStep()) {

		int iUDSN =  pDb->GetInt(0);
		int iUDLength = pDb->GetUdLength(1);
		const void *pUDContent = pDb->GetUd(1);
		const char* pszBizDate = pDb->GetString(2);

		if(iUDLength < 1) {
			printf("[%s][%s][%d]Ud数据长度错误 iUDLength = %d \n", __FILE__, __FUNCTION__, __LINE__, iUDLength);
			continue;
		}

		printf("[%s][%s][%d]UDSN(%d), BUS_DATE(%s), UDLength(%d), UDContent:%s", __FILE__, __FUNCTION__, __LINE__,
				iUDSN, pszBizDate, iUDLength, (const char*) pUDContent);
	}

	pDb->FreeStmt();

	clock_gettime(CLOCK_MONOTONIC, &tsEnd);
	uint32_t u32TimeSpendMs = (tsEnd.tv_sec - tsBegin.tv_sec)*1000 + (tsEnd.tv_nsec - tsBegin.tv_nsec)/1000000;
	printf("[%s][%s][%d] bisl for test u32TimeSpendMs(%d)\n", __FILE__, __FUNCTION__, __LINE__, u32TimeSpendMs);

	return true;
}

void testClass()
{
	CSqlite sledb("/Afc/Data/sledb_UnsendQRMessage.db");
	LoadFaultTrans2(&sledb);
	return;

	char **ppszRus = NULL;
	int iRow = 0, iColumn = 0;
	char szErrMsg[128]; memset(szErrMsg, 0, sizeof(szErrMsg));

//	const char *pszSql = "DELETE FROM DATA_YKT_TRAN;";
//	const char *pszSql = "SELECT UDSN,BUS_DATE,BUS_TIME,UP_FLAG FROM DATA_YKT_TRAN WHERE UP_FLAG!=0;";
	const char *pszSql = "SELECT count(*) FROM DATA_YKT_TRAN WHERE UP_FLAG!=0;";
//	int iRet = sledb.Execute(pszSql, szErrMsg);
	int iRet = sledb.GetTable(pszSql, &ppszRus, &iRow, &iColumn, szErrMsg);
	if(SQLITE_OK == iRet){
		puts("Exec sucess!");
		printf("iRow: %d, iColumn: %d.\n", iRow, iColumn);
		printGetTableRus(ppszRus, iRow, iColumn);
		sledb.FreeTable(ppszRus);

	}
	else{
		printf("Exec Fail, iRet(%d) %s!\n", iRet, szErrMsg);
	}
}
