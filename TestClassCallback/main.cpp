/*
 * main.cpp
 *
 *  Created on: 2017-5-31
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

class ICallBack;
class IComFunc;

class ICallBack
{
public:
	virtual void TicIns()=0;
	virtual void ResComFunc(IComFunc *pIComFunc)=0;
};

class CCallBack:public ICallBack
{
public:
	void TicIns();


	void ResComFunc(IComFunc *pIComFunc)
	{
		mpIComFunc = pIComFunc;
	}

private:
	IComFunc *mpIComFunc;

};

class IComFunc
{
public:
	virtual void WithdrawTic()=0;
	virtual void ResCallBack(ICallBack *pICallBack)=0;
};

class CComFunc:public IComFunc
{
public:
	CComFunc()
	{
		puts("Thread Starting!");

		pthread_t pid;
		pthread_attr_t pAttr;
		pthread_attr_init(&pAttr);
		pthread_attr_setdetachstate(&pAttr,PTHREAD_CREATE_DETACHED);

		if(pthread_create(&pid,&pAttr,Poll,this) != 0)
		{
			puts("Thread Create ERR!");
		}
		else
			puts("Thread Start sucess!");
	}
	void WithdrawTic()
	{
		puts("Withdraw Tic Begin!");
		usleep(400 * 1000);
		puts("Withdraw Tic end!");
	}

	void ResCallBack(ICallBack *pICallBack)
	{
		mpICallBack = pICallBack;
	}

	static void* Poll(void *pram)
	{
		CComFunc *pThis = (CComFunc*)pram;
		for(int i=0; i<3 ;i++)
		{
			usleep(900 * 1000);
			if(pThis->mpICallBack != NULL)
			{
				puts("\nThread CallBack!");
				pThis->mpICallBack->TicIns();
			}
		}
		return NULL;
	}

private:
	ICallBack *mpICallBack;

};


void CCallBack::TicIns()
{
	puts("Ticket insert Func called !");
	if(mpIComFunc != NULL)
		mpIComFunc->WithdrawTic();
}

int main()
{
	IComFunc *pComFunc = new CComFunc();
	ICallBack *pCallBack = new CCallBack();

	pCallBack->ResComFunc(pComFunc);
	pComFunc->ResCallBack(pCallBack);

	while(1)
		sleep(1);

	return 0;
}
