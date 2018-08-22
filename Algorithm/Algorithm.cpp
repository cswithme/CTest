//============================================================================
// Name        : Algorithm.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h> //gettimeofday
#include <unistd.h>

const int MAXN = 50; //多项式最大阶数

//计算  f(x) = a0+ a1x + a(x-1) x(n-1) +an xn  n = MAXN-1
double func1(int argc, double a[], double x)
{
	double dRus = a[0];
	for(int i=1; i<=argc; ++i)
	{
		dRus += a[i] * pow(x, i);
	}
	return dRus;
}

double func2(int argc, double a[], double x)
{
	double dRus = a[argc];
	for(int i=argc; i>0; --i)
	{
		dRus = a[i-1] + x * dRus;
	}
	return dRus;
}

double func3(int argc, double a[], double x)
{
	double xn = 1, dRus=a[0];
	for(int i=1; i<=argc; ++i)
	{
		xn *= x;
		dRus += a[i] * xn;
	}
	return dRus;
}

typedef double (*P_Func)(int argc, double a[], double x);
unsigned long caclFuncRunTime(P_Func pFunc, int argc, double a[], double x, unsigned int uiFuncRunCnt = 1);
unsigned long caclFuncRunTime(P_Func pFunc, int argc, double a[], double x, unsigned int uiFuncRunCnt)
{
	struct timespec tsBegin,tsEnd;
	clock_gettime(CLOCK_REALTIME, &tsBegin);
//	printf("Before Call Func: tv_sec[%ld], tv_usec[%ld](ns)\n", tsBegin.tv_sec, tsBegin.tv_nsec);

	double dRus = 0;
	for(unsigned int i=0; i<uiFuncRunCnt; ++i)
		dRus = pFunc(argc, a, x); //call func

	clock_gettime(CLOCK_REALTIME, &tsEnd);
//	printf("After Call Func: tv_sec[%ld], tv_usec[%ld](ns)\n", tsEnd.tv_sec, tsEnd.tv_nsec);

	printf("Rus is %f \n", dRus);

	unsigned long ulTimeUsedMs = (tsEnd.tv_sec - tsBegin.tv_sec)*1000 + (tsEnd.tv_nsec - tsBegin.tv_nsec)/1000000;
//	printf("func exe use %lu ms \n",ulTimeUsedMs);

    printf("Time spend:tv_sec[%ld], tv_usec[%ld](ns)\n", tsEnd.tv_sec-tsBegin.tv_sec,
			tsEnd.tv_nsec-tsBegin.tv_nsec);
	return ulTimeUsedMs;

}


int main()
{
	puts("Test Begin!");

	double a[MAXN];

//	for(int i=0; i<MAXN; ++i)
//	{
//		a[i] = i;
//	}

	srand((unsigned int)time(NULL));
	for(int i=0; i<MAXN; ++i)
	{
		a[i] = rand() / (double)(RAND_MAX / 10) ;
		printf("a[%d]:%f  ", i, a[i]);
	}
	putchar('\n');


	caclFuncRunTime(func1, MAXN-1, a, 2 , 100);
	caclFuncRunTime(func2, MAXN-1, a, 2, 100);
	caclFuncRunTime(func3, MAXN-1, a, 2, 100);
//	double dRus1 = func1(MAXN-1, a, 2);
//	printf("dRus1 [%f]\n", dRus1);
//
//	double dRus2 = func2(MAXN-1, a, 2);
//	printf("dRus2 [%f]\n", dRus2);

	puts("Test end!");
	return 0;
}
