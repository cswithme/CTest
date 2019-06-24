/*
 * CBaseClass.h
 *
 *  Created on: 2019-5-10
 *      Author: root
 */

#ifndef CBASECLASS_H_
#define CBASECLASS_H_

#include "include.h"

class CBaseClass
{
public:
	CBaseClass();
	virtual ~CBaseClass();

	void Init();

	virtual void callStaticFunc();

	static void virStaticFunc();
	static void virStaticFunc(int n);
protected:
	virtual void _BizInit(); //声明为virtual后，基类指针调用Init，Init内部调用的_BizInit由实例化的类确定
};

#endif /* CBASECLASS_H_ */
