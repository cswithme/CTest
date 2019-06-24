#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "TypeDef.h"
#include <time.h>
#include <sys/time.h> //gettimeofday
#include <unistd.h>
#include <stdint.h>
#include <map>
#include <math.h>
#include <iconv.h>
#include <set>
#include <pthread.h>
#include <vector>
#include <algorithm>    // std::sort

//int iTemp = printf("function call out func\n");

int getValueFromStr1(const char* pszSource, const char* pszParamStr, char *szParamValue)
{
	const char* pos = strstr(pszSource, pszParamStr);
	if(NULL == pos)	return -1;

	const char* end = index(pos, '&');
	if(NULL == end){
		strcpy(szParamValue, pos+strlen(pszParamStr)+1);
	}
	else{
		memcpy(szParamValue, pos+strlen(pszParamStr)+1, end-pos-strlen(pszParamStr)-1);
	}
	return 0;
}

void getValueFromQueryStr2(const char * szQueryStr, const char * szParamName, char *szParamValue)
{
	using namespace std;
	//cout<<"Query String is "<<szQueryStr<< ", paramname is " << szParamName <<endl;
	string queryStr(szQueryStr);
	string paramName(szParamName);

	string::size_type pos1, pos2;
	pos2 = queryStr.find('&');
	pos1 = 0;
	bool breakFlag = false;
	while (true)
	{
		breakFlag = string::npos == pos2;
		string strKeyValue = "";
		if(!breakFlag)
			strKeyValue = queryStr.substr(pos1, pos2 - pos1);
		else
			strKeyValue = queryStr.substr(pos1);
		if(!strKeyValue.compare(0,paramName.length(),paramName))
		{
			int beginPos = strKeyValue.find_first_of('=');
			strKeyValue = strKeyValue.substr(beginPos+1,strKeyValue.length());
			int endPos = strKeyValue.find_first_of('&');
			strKeyValue = strKeyValue.substr(0,endPos);
			memcpy(szParamValue,strKeyValue.c_str(),strKeyValue.length());
			break ;
		}
		if(breakFlag)
			break;
		pos1 = pos2 + 1;
		pos2 = queryStr.find('&', pos1);
	}
}

int main()
{
	puts("Test begin!");

	char szTmp[] = {0x68, 0x6C, 0x6F, 0x47, 0x53, 0x4C, 0x33, 0x35, 0x44, 0x4F, 0x5A, 0x2B, 0x61, 0x41, 0x56, 0x6D, 0x74, 0x4C, 0x45, 0x63, 0x6E, 0x61, 0x52, 0x63, 0x31, 0x42, 0x76, 0x4C, 0x4F, 0x58, 0x72, 0x51, 0x69, 0x64, 0x42, 0x57, 0x51, 0x31, 0x48, 0x45, 0x74, 0x76, 0x4D, 0x3D};
	puts(szTmp);
	puts("Test end!");

	return 0;

}




