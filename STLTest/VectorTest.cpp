/*
 * Iterator.cpp
 *
 *  Created on: 2017-10-19
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>

void vectorTest()
{
	using namespace std;
	vector<string> vsTest(3,"aaa");

	int iTemp = 0;
	for(vector<string>::iterator itTest=vsTest.begin(); itTest!=vsTest.end(); ++itTest)
	{
		itTest->append(iTemp++, 'b');
	}

	//vector<string>::reference 元素引用 string&
	vector<string>::reference rTemp = vsTest.at(2);
	rTemp.assign("666");

	for(vector<string>::iterator itTest=vsTest.begin(); itTest!=vsTest.end(); ++itTest)
	{
		printf("%s\n",itTest->c_str());
	}

	//vector<string>::value_type 元素类型 string
	vector<string>::value_type value;
	value.assign("bbb");
	printf("vector<string>::value_type content[%s]\n",value.c_str());
}
