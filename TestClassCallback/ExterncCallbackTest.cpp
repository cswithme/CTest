/*
 * ExterncCallbackTest.cpp
 * 用exter C声明的函数中要求传入一个回调函数指针
 * 测试在类中实现该回调函数
 * 测试类在实现回调函数时必须将函数声明为static，否则会出现以下错误:
 * ../ExterncCallbackTest.cpp:62: 错误：实参类型为‘void (CTest::)(int)’，与‘void (*)(int)’不匹配
 *  Created on: 2018-1-10
 *      Author: root
 */

#include "ExterncCallbackTest.h"
#include <pthread.h>


/*extern C 函数实现*/

typedef void (*PT_CallBackFunc)(int iRet);

static PT_CallBackFunc gpCallBackFunc = NULL;

//定时调用回调函数
void *thr_fn2(void *arg)
{
	puts("thread Create sucess!");

	int iRet = 233;

	while(1)
	{
		usleep(1200 * 1000);
		if(gpCallBackFunc == NULL) continue;

		gpCallBackFunc(iRet+=3);
	}
	pthread_exit(NULL);
}

//用exter C声明的函数中要求传入一个回调函数指针
int init(void (*pCallBackFunc)(int iRet))
{
	gpCallBackFunc = pCallBackFunc;

	int			err;
	pthread_t	tid2;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	err = pthread_create(&tid2, &attr, thr_fn2, (void *)1);
	if (err != 0)
	{
		printf("can't create thread 2[err = %d]\n", err);
		exit(-1);
	}

	return 0;
}

/* Class 实现 */
int CTest::Init()
{
//	int init(void (*pCallBackFunc)(int iRet));
	init(CallBackFunc);
	return 0;
}

void CTest::CallBackFunc(int iRet)
{
	printf("CallBackFunc get[%d]!\n", iRet);
}

int ExterncCallbackTest()
{
	CTest cTest;
	cTest.Init();
	while(1) sleep(2);
	return 0;
}

