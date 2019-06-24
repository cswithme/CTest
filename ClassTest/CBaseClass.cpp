/*
 * CBaseClass.cpp
 *
 *  Created on: 2019-5-10
 *      Author: root
 */

#include "CBaseClass.h"

CBaseClass::CBaseClass()
{
	printf("CBaseClass constructor!\n");
}

CBaseClass::~CBaseClass()
{
	printf("CBaseClass destructor!\n");
}

void CBaseClass::Init()
{
	printf("CBaseClass Init!\n");
	_BizInit();
}

void CBaseClass::virStaticFunc()
{
	printf("CBaseClass virStaticFunc!\n");
}

void CBaseClass::callStaticFunc()
{
	virStaticFunc();
}

void CBaseClass::virStaticFunc(int n)
{
	printf("CBaseClass virStaticFunc, (%d)!\n", n);
}

void CBaseClass::_BizInit()
{
	printf("CBaseClass _BizInit!\n");

}
