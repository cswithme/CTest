/*
 * ItertorTest.cpp
 *
 *  Created on: 2018-8-20
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>

typedef struct
{
	int a;
	int b;
	int c;
}ST_TEST;

void IteratorTest()
{
	using namespace std;


	puts("Test Begin!");
	ST_TEST stTest[3] = {{11,12,13}, {21,22,23}, {31,32,33}};

	vector<ST_TEST> vStTest = {{11,12,13}, {21,22,23}, {31,32,33}};

//	vector<ST_TEST> vStTest;
//	vStTest.push_back(stTest[0]);
//	vStTest.push_back(stTest[1]);
//	vStTest.push_back(stTest[2]);

	vector<ST_TEST>::iterator itStTest;
	for(itStTest=vStTest.begin(); itStTest!=vStTest.end(); ++itStTest)
	{
		printf("a[%d], b[%d], c[%d]\n", itStTest->a, itStTest->b, itStTest->c);
	}


	map<int, ST_TEST*> mapStTest;
	mapStTest[0] = stTest;
	mapStTest[1] = stTest+1;
	mapStTest[2] = stTest+2;

	map<int, ST_TEST*>::iterator itMap;
	for(itMap= mapStTest.begin(); itMap!=mapStTest.end(); ++itMap)
	{
		printf("a[%d], b[%d], c[%d]\n", itMap->second->a, itMap->second->b, itMap->second->c);
	}
}
