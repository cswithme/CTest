/*
 * main.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int main()
{
	time_t curTime;
	time(&curTime);
	printf("time is %ld\n",curTime);



	tm *tLocaltime = localtime(&curTime);
	printf("tm_year[%04d], tm_mon[%02d], tm_mday[%02d], tm_hour[%02d]\n",tLocaltime->tm_year+1900, tLocaltime->tm_mon,
			tLocaltime->tm_mday, tLocaltime->tm_hour);

	char szTimeStr[64] = {0}; //2019-07-18 15:01:33
	sprintf(szTimeStr, "%04d-%02d-%02d %02d:%02d:%02d", tLocaltime->tm_year+1900, tLocaltime->tm_mon,
			tLocaltime->tm_mday, tLocaltime->tm_hour, tLocaltime->tm_min, tLocaltime->tm_sec);
	printf("szTimeStr (%s)\n", szTimeStr);

	printf("ctime result (%s)\n", ctime(&curTime));

	return 0;

}
