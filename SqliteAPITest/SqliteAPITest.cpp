//============================================================================
// Name        : SqliteAPITest.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char **argv)
{
	sqlite3 *db;
	char *errmsg = NULL; //用来存储错误信息字符串
	char ret = 0;
	char **dbResult;
	int nRow = 0, nColumn = 0; //nRow 查找出的总行数,nColumn 存储列

	ret = sqlite3_open("/Afc/Data/sledb_UnsendQRMessage.db", &db);
	if(1 == ret) {//数据库创建未成功
		fprintf(stderr, "Can't open this database: %s\n", sqlite3_errmsg(db)); //用sqlite3_errmsg()得到错误字符串
		sqlite3_close(db);
		return -1;
	}

	ret = sqlite3_get_table(db, "SELECT * FROM DATA_YKT_TRAN limit 5;", &dbResult, &nRow, &nColumn, &errmsg);

	if(NULL != errmsg) {
		printf("sqlite3_get_table fail\n");
		sqlite3_free_table(dbResult);
		errmsg = NULL;
		return -1;
	}

	printf("sqlite3_get_table sucess(%d, %d)\n", nRow, nColumn);
	sqlite3_free_table(dbResult);
	return 0;
}

