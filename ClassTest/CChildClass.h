/*
 * CChildClass.h
 *
 *  Created on: 2019-5-10
 *      Author: root
 */

#ifndef CCHILDCLASS_H_
#define CCHILDCLASS_H_

#include "CBaseClass.h"

class CChildClass: public CBaseClass
{
public:
	CChildClass();
	virtual ~CChildClass();

	void Init();

	virtual void callStaticFunc();
	static void virStaticFunc();
protected:
	void _BizInit();
};

#endif /* CCHILDCLASS_H_ */
