/*
 * CChildClass.cpp
 *
 *  Created on: 2019-5-10
 *      Author: root
 */


#include "CChildClass.h"

CChildClass::CChildClass()
{
	printf("CChildClass constructor!\n");
}

CChildClass::~CChildClass()
{
	printf("CChildClass destructor!\n");
}

void CChildClass::Init()
{
	printf("CChildClass Init!\n");
	_BizInit();
}

void CChildClass::_BizInit()
{
	printf("CChildClass _BizInit!\n");

}

void CChildClass::virStaticFunc()
{
	printf("CChildClass virStaticFunc!\n");
}

void CChildClass::callStaticFunc()
{
	virStaticFunc();
}
