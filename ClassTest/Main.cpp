//============================================================================
// Name        : ClassTest.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CChildClass.h"
using namespace std;

int main() {
	cout << "main entry" << endl;

	CBaseClass *pBaseClass = new CChildClass();

	/*
	 * Init内部调用的虚函数_BizInit是子类的_BizInit
	 */
	pBaseClass->Init(); //
	pBaseClass->virStaticFunc();
	pBaseClass->callStaticFunc();

	delete pBaseClass;
	cout << "main exit!" << endl;
	return 0;
}
