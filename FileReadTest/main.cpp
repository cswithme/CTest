/*
 * main.cpp
 * C语言文件操作
 *  Created on: 2017-9-18
 *      Author: root
 */

/*
 * return 读出字节数,-1 Error!
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>


int fileRead(const char *szFileName, unsigned char *ucReadBuff, unsigned long ulReadBuffCnt)
{
	//xxx 不使用rb模式打开,fread读出换行符页不受影响
	FILE * fp  = fopen (szFileName, "r");

	if (fp == NULL)
	{
		puts("Open file Fail");
		return -1;
	}

	if (fseek(fp, 0, SEEK_SET) != 0)
	{
		puts("fseek(fp, 23, SEEK_SET) != 0");
		return -1;
	}

	size_t iReadCnt = fread((void *)ucReadBuff, sizeof(unsigned char), ulReadBuffCnt, fp);

	fclose(fp);

	return iReadCnt;
}

int main()
{

	unsigned char ucReadBuff[1024] = {0};

	int iReadCnt = fileRead("/home/PRM.0103.0000.000065", ucReadBuff, sizeof(ucReadBuff));

	printf("Read %d Bytes: ", iReadCnt);

	if(iReadCnt > 0)
	{
		for(int iCnt=0; iCnt < iReadCnt; ++iCnt)
		{
			printf("%02X ",ucReadBuff[iCnt]);
		}
	}
	putchar('\n');

	struct
	{
		unsigned int	uiMaxTransAmount;
		unsigned short	usMaxOfflineRunDays;
		unsigned short	usYKTTransDataUpdateInterval;
		unsigned short	usYPTTransDataUpdateInterval;
		unsigned short	usRegisterUpdateInterval;
		unsigned short	usStoryStoryUpdateInterval;
		unsigned int	uiSJTAlertAmount;
		unsigned char	ucTicketNearEmpty;
		unsigned char	ucTicketEmpty;
		unsigned char	ucDiskNearFull;
		unsigned char	ucDiskFull;
		unsigned char	ucTicketTypeAllow;
		unsigned char	ucReserve[16];
	}stParm;

	if(iReadCnt != 77)
	{
		puts("Parm Length Err!");
		return -1;
	}
	memset(&stParm, 0, sizeof(stParm));

	memcpy(&stParm.uiMaxTransAmount, ucReadBuff+22, 4); //文件最大交易数量 4B

	memcpy(&stParm.usMaxOfflineRunDays, ucReadBuff+26, 2);//最大脱机运营天数 2B

	memcpy(&stParm.usYKTTransDataUpdateInterval, ucReadBuff+28, 2);//一卡通交易数据上传时间间隔 2B 秒

	memcpy(&stParm.usYPTTransDataUpdateInterval, ucReadBuff+30, 2);//一票通交易数据上传时间间隔 2B 秒

	memcpy(&stParm.usRegisterUpdateInterval, ucReadBuff+32, 2);//寄存器数据上传时间间隔 2B 秒

	memcpy(&stParm.usStoryStoryUpdateInterval, ucReadBuff+34, 2);//事件数据上传时间间隔 2B 秒

	memcpy(&stParm.uiSJTAlertAmount, ucReadBuff+36, 4); //单程票报警数量 4B

	stParm.ucTicketNearEmpty = *(ucReadBuff + 40); //票箱将空百分比 1B
	stParm.ucTicketEmpty = *(ucReadBuff + 41);	//票箱已空百分比 1B

	stParm.ucDiskNearFull = *(ucReadBuff + 42);	//磁盘将满百分比 1B
	stParm.ucDiskFull = *(ucReadBuff + 43);	//磁盘已满百分比 1B

	stParm.ucTicketTypeAllow = *(ucReadBuff + 44);	//允许处理票类 1B

	memcpy(stParm.ucReserve, ucReadBuff+45, sizeof(stParm.ucReserve)); //保留 16B

	puts("Test End!");

	return 0;
}

