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

	return 0;

}
