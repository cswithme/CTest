/*
 * MapTest.cpp
 *
 *  Created on: 2017-10-26
 *      Author: root
 */


#include <stdio.h>
#include <stdlib.h>
#include <map>

typedef struct _ST_STUDENT
{
	unsigned int uiSn;
	char szName[20];
}ST_STUDENT;

void MapTestFunc()
{
	using namespace std;
	map<int,ST_STUDENT> mapStu;
	ST_STUDENT stStu[4] = {{660,"B666"},{661,"B661"}, {662,"B662"}, {663,"B663"}};
//	mapStu.insert(2,stStu[2]);
	mapStu.insert(make_pair(1,stStu[1]));
	mapStu.insert(make_pair(0,stStu[0]));
	mapStu.insert(make_pair(3,stStu[3]));
	mapStu.insert(make_pair(2,stStu[2]));

	//map::insert 插入单条 返回值测试
//	pair<map<int,ST_STUDENT>::iterator, bool> ret;
//	ret = mapStu.insert(make_pair(4,stStu[3]));
//	printf("mapStu.insert(make_pair(4,stStu[3])) %s\n", ret.second? "true": "false");
//	ret = mapStu.insert(make_pair(3,stStu[3]));
//	printf("mapStu.insert(make_pair(4,stStu[3])) %s\n", ret.second? "true": "false");

	map<int,ST_STUDENT>::iterator itMapStu;

	ST_STUDENT stTemp = {666,"Bbz"};
	mapStu[6] = stTemp;

	map<int,ST_STUDENT>::iterator itMapTemp = mapStu.find(6);
	itMapTemp->second.uiSn = 555;


	for(itMapStu = mapStu.begin(); itMapStu!=mapStu.end(); ++itMapStu)
		printf("it First[%d], content:sn[%d],szName[%s]\n",itMapStu->first, itMapStu->second.uiSn, itMapStu->second.szName);

}
