/*
 * main.cpp
 *
 *  Created on: May 25, 2017
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TAM001Dev.h"

int main()
{
	tDevReturn m_acDevReturn[8];//设备返回信息

	//1. 获取设备HANDEL
	memset(m_acDevReturn, 0x00, 8*sizeof(tDevReturn));
	HANDLE devHandel = hOpenLogicalDevice(NULL, m_acDevReturn);
	printf("devHandel address is %p\n",devHandel);

	//2.设置串口

	memset(m_acDevReturn, 0x00, 8*sizeof(tDevReturn));
	int l_iResult = iSetCommPara(devHandel, m_acDevReturn);
	printf("iSetCommPara iRus = %s\n", l_iResult ? "失败" : "成功");

	for(int i=0; i<8; ++i)
	{
		printf("m_acDevReturn[%d]:\n",i);
		printf(
					"iLogicCode:%d, iPhyCode:%d, iHandle:%d, iType:%d.\nacDevReturn:%s, acReserve:%s.\n",
					m_acDevReturn[i].iLogicCode, m_acDevReturn[0].iPhyCode,
					m_acDevReturn[i].iHandle, m_acDevReturn[0].iType,
					m_acDevReturn[i].acDevReturn, m_acDevReturn[0].acReserve);
	}


	//3.获取版本
//	int iGetDevVersion(  HANDLE p_hDevHandle,tTAM001_OUT_DEV_VER* p_psVerInfo,   tDevReturn* p_psStatus);
	memset(m_acDevReturn, 0x00, 8*sizeof(tDevReturn));
	tTAM001_OUT_DEV_VER stVerInfo; memset(&stVerInfo,0,sizeof(tTAM001_OUT_DEV_VER));

	l_iResult = iGetDevVersion(devHandel,&stVerInfo,m_acDevReturn);

	printf("iGetDevVersion iRus = %s\n", l_iResult ? "失败" : "成功");
	printf("ModuleType:%s, MCUVer:%s, CPLDVer:%s.\n",stVerInfo.acModuleType,stVerInfo.acMCUVer,stVerInfo.acCPLDVer);
	for(int i=0; i<8; ++i)
	{
		printf("m_acDevReturn[%d]:\n",i);
		printf(
					"iLogicCode:%d, iPhyCode:%d, iHandle:%d, iType:%d.\nacDevReturn:%s, acReserve:%s.\n",
					m_acDevReturn[i].iLogicCode, m_acDevReturn[0].iPhyCode,
					m_acDevReturn[i].iHandle, m_acDevReturn[0].iType,
					m_acDevReturn[i].acDevReturn, m_acDevReturn[0].acReserve);
	}


	//4. 初始化
#if 1
	tTAM001_IN_INIT l_asInit;
	memset(&l_asInit, 0x00, sizeof(tTAM001_IN_INIT));
	tTAM001_OUT_RET l_asRet;
	memset(&l_asRet, 0x00, sizeof(tTAM001_OUT_RET));

	l_asInit.byInitType = 0xFF;
	l_asInit.byClearType = 0x00;

	memset(m_acDevReturn, 0x00, 8*sizeof(tDevReturn));
	l_iResult = iInit(devHandel, &l_asInit, &l_asRet, m_acDevReturn);

	printf("iInit iRus = %s\n", l_iResult ? "失败" : "成功");
	for(int i=0; i<8; ++i)
	{
		printf("m_acDevReturn[%d]:\n",i);
		printf(
					"iLogicCode:%d, iPhyCode:%d, iHandle:%d, iType:%d.\nacDevReturn:%s, acReserve:%s.\n",
					m_acDevReturn[i].iLogicCode, m_acDevReturn[0].iPhyCode,
					m_acDevReturn[i].iHandle, m_acDevReturn[0].iType,
					m_acDevReturn[i].acDevReturn, m_acDevReturn[0].acReserve);
	}
	puts("\nSensor Sta(acDevReturn[0])!");
	for (int i = 0; i < 128; ++i)
	{
		printf("m_acDevReturn[0]:%X\t",m_acDevReturn[0].acDevReturn[i]);
	}

	puts("\nSensor Sta(acReserve[0])!");
	for (int i = 0; i < 128; ++i)
	{
		printf("acReserve[0]:%X\t",m_acDevReturn[0].acReserve[i]);
	}
	puts("");
	sleep(1);
#endif

	//l_iResult = iInit(devHandel, &l_asInit, &l_asRet, m_acDevReturn);
	printf("\n\niGetStatus test!\n");
	tTAM001_CARD_NUM ltCardNum; memset(&ltCardNum,0,sizeof(tTAM001_CARD_NUM));

	l_iResult = iGetStatus(devHandel, &ltCardNum, m_acDevReturn);

	printf("iGetStatus iRus = %s\n", l_iResult ? "失败" : "成功");
	for (int i = 0; i < 8; ++i)
	{
		printf("m_acDevReturn[%d]:\n", i);
		printf(
				"iLogicCode:%d, iPhyCode:%d, iHandle:%d, iType:%d.\nacDevReturn:%s, acReserve:%s.\n",
				m_acDevReturn[i].iLogicCode, m_acDevReturn[0].iPhyCode,
				m_acDevReturn[i].iHandle, m_acDevReturn[0].iType,
				m_acDevReturn[i].acDevReturn, m_acDevReturn[0].acReserve);
	}

	puts("\nSensor Sta(acDevReturn[0])!");
	for (int i = 0; i < 128; ++i)
	{
		printf("m_acDevReturn[0]:%X\t",m_acDevReturn[0].acDevReturn[i]);
	}

	puts("\nSensor Sta(acReserve[0])!");
	for (int i = 0; i < 128; ++i)
	{
		printf("acReserve[0]:%X\t",m_acDevReturn[0].acReserve[i]);
	}
	puts("");
	return 0;
}
