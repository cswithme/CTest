/*
 * ExterncCallbackTest.h
 *
 *  Created on: 2018-1-10
 *      Author: root
 */

#ifndef EXTERNCCALLBACKTEST_H_
#define EXTERNCCALLBACKTEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//用exter C声明的函数中要求传入一个回调函数指针
extern "C" int init(void (*pCallBackFunc)(int iRet));

//在该类中实现回调函数
class CTest
{
public:
	int Init();
	void CallBackFunc(int iRet); //错误的实现方式
//	static void CallBackFunc(int iRet); //正确的实现方式
};


#endif /* EXTERNCCALLBACKTEST_H_ */
