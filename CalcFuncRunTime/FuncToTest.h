/*
 * FuncToTest.h
 *
 *  Created on: 2019-9-10
 *      Author: root
 */
#ifndef FUNCTOTEST_H_
#define FUNCTOTEST_H_

typedef struct _ST_QR_SETTING_PARAM_
{
	char szQR_IP[50]; //服务器IP地址
	char szQR_Port[10]; //服务器端口号
	char cQR_ConnectTimeOut; //连接超时时间
	int cQR_TimeOut; //超时时间
	int iQR_Interval; //失败尝试次数

	char szQR_OD_IP[50]; //服务器IP地址
	char szQR_OD_Port[10]; //服务器端口号
	char cQR_OD_ConnectTimeOut; //连接超时时间
	int cQR_OD_TimeOut; //超时时间
	int cQR_OD_iInterval; //失败尝试次数

	char szODA_IP[50]; //服务器IP地址
	char szODA_Port[10]; //服务器端口号
	char cODA_ConnectTimeOut; //连接超时时间
	int cODA_TimeOut; //超时时间
	int iODA_Interval; //失败尝试次数

	char szODA_OD_IP[50]; //服务器IP地址
	char szODA_OD_Port[10]; //服务器端口号
	char cODA_OD_ConnectTimeOut; //连接超时时间
	int cODA_OD_TimeOut; //超时时间
	int cODA_OD_iInterval; //失败尝试次数

	char szLocalID[50];

	char sz_op_app_id[17]; //行业应用ID
} ST_QR_NET_SETTING_PARAM;

void _ParseQRParmCfg1(void *parm);
void _ParseQRParmCfg2(void *parm);

#endif
