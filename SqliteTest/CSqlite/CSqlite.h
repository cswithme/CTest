/*
 * CSqlite.h
 *
 *  Created on: 2019-8-15
 *      Author: root
 */

#ifndef CSQLITE_H_
#define CSQLITE_H_

#include <sqlite3.h>

class CSqlite
{
public:
	CSqlite(const char* pszMainDbPath=NULL);
	virtual ~CSqlite();
	const char *GetVersion();

	int Execute(const char *pszSql, char *pszErrMsg);
	int GetTable(const char *pszSql, char ***pppszResult, int *piRow, int *piColumn, char *pszErrMsg);
	void FreeTable(char **ppDbResult);

	int SqlitePrepare(const char *pszSql);
	int SqliteStep();
	void FreeStmt();

	const void * GetUd(int iCol=0);
	int GetUdLength(int iCol=0);
	int GetInt(int iCol);
	const char* GetString(int iCol);

private:
	sqlite3 *_pDb;
	sqlite3_stmt  *m_pstmt ;//游标指针
};

#endif /* CSQLITE_H_ */
