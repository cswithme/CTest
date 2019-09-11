/*
 * CalcFuncSpendTime.h
 *
 *  Created on: 2019-9-10
 *      Author: root
 */

#ifndef CALCFUNCSPENDTIME_H_
#define CALCFUNCSPENDTIME_H_

typedef void (*Ptr_Func)(void * parm); //需要计算的函数指针

/*
 * parm: uiFuncRunCnt Run Cnt
 * Ret Time Cost ms
 */
unsigned long CaclFuncRunTime(Ptr_Func pFunc, void* parm, unsigned int uiFuncRunCnt = 1);


#endif /* CALCFUNCSPENDTIME_H_ */
