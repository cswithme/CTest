/*
 * FuncToTest.cpp
 *
 *  Created on: 2019-9-10
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <iostream>

#include <unistd.h>
#include <errno.h>

#include "FuncToTest.h"

void _PrintParseRus(ST_QR_NET_SETTING_PARAM stQrParam);


void _ParseQRParmCfg1(void *parm)
{
	using namespace std;
	const char *pszFilePath = "/Afc/SoftUpdate/currentversion/TransParamsFile_0005.dat";

	//3 解析文件内容
	bool bOK=true;
	FILE *fp = fopen(pszFilePath, "rb");
	if(fp == NULL) {
		printf("fopen %s fail, %s!\n", pszFilePath, strerror(errno));
		bOK = false;
	}

	if(bOK) {
		ST_QR_NET_SETTING_PARAM stQrParam;	memset(&stQrParam,0,sizeof(stQrParam));

		char buffer[1024]; memset(buffer,0x00,sizeof(buffer));

		while(fgets(buffer, sizeof(buffer), fp)) {

			string queryStr(buffer);
			string::size_type pos = queryStr.find_first_of('=');
			string data = queryStr.substr(pos + 1);	data.erase(data.find_last_not_of(" \t\r\n")+1);
			string key = queryStr.substr(0, pos);

//			m_pBizLog->LogError("[%s][%s][%d] key[%s] : data[%s]", __FILE__, __FUNCTION__, __LINE__, key.c_str(), data.c_str());

			char szKey[64]; memset(szKey, 0, sizeof(szKey));
			strcpy(szKey, key.c_str());

			if(strcmp(szKey, "agm_int_private_key") == 0) {
			}
			else if(strcmp(szKey, "qr_trans_service_addr") == 0) {
				strcpy(stQrParam.szQR_IP, data.c_str());
			}
			else if(strcmp(szKey, "qr_trans_service_port") == 0) {
				strcpy(stQrParam.szQR_Port, data.c_str());
			}
			else if(strcmp(szKey, "qr_trans_timeout") == 0) {
				stQrParam.cQR_TimeOut = atoi(data.c_str());
			}
			else if(strcmp(szKey, "qr_od_check_service_ip") == 0) {
				strcpy(stQrParam.szQR_OD_IP, data.c_str());
			}
			else if(strcmp(szKey, "qr_od_check_service_port") == 0) {
				strcpy(stQrParam.szQR_OD_Port, data.c_str());
			}
			else if(strcmp(szKey, "qr_od_check_timeout") == 0) {
				stQrParam.cQR_OD_TimeOut = atoi(data.c_str());
			}
			else if(strcmp(szKey, "qr_heartbeat_interval") == 0) {
				stQrParam.iQR_Interval = atoi(data.c_str());
			}

			else if(strcmp(szKey, "quickpass_trans_service_ip") == 0) {
				strcpy(stQrParam.szODA_IP, data.c_str());
			}
			else if(strcmp(szKey, "quickpass_trans_service_port") == 0) {
				strcpy(stQrParam.szODA_Port, data.c_str());
			}
			else if(strcmp(szKey, "quickpass_trans_timeout") == 0) {
				stQrParam.cODA_TimeOut = atoi(data.c_str());
			}
			else if(strcmp(szKey, "quickpass_od_check_service_ip") == 0) {
				strcpy(stQrParam.szODA_OD_IP, data.c_str());
			}
			else if(strcmp(szKey, "quickpass_od_check_service_port") == 0) {
				strcpy(stQrParam.szODA_OD_Port, data.c_str());
			}
			else if(strcmp(szKey, "quickpass_od_check_timeout") == 0) {
				stQrParam.cODA_OD_TimeOut = atoi(data.c_str());
			}
			else if(strcmp(szKey, "quickpass_heartbeat_interval") == 0) {
				stQrParam.cODA_OD_iInterval = atoi(data.c_str());
			}
			else if(strcmp(szKey, "op_app_id") == 0) {
				strcpy(stQrParam.sz_op_app_id, data.c_str());
			}
		}
		_PrintParseRus(stQrParam);
	}

	if(fp != NULL) fclose(fp);

//	return bOK;
}

void _ParseQRParmCfg2(void *parm)
{
	using namespace std;
	const char *pszFilePath = "/Afc/SoftUpdate/currentversion/TransParamsFile_0005.dat";

	//3 解析文件内容
	bool bOK=true;
	FILE *fp = fopen(pszFilePath, "rb");
	if(fp == NULL) {
		printf("fopen %s fail, %s!\n", pszFilePath, strerror(errno));
		bOK = false;
	}

	if(bOK) {
		ST_QR_NET_SETTING_PARAM stQrParam;	memset(&stQrParam,0,sizeof(stQrParam));

		char buffer[1024]; memset(buffer,0x00,sizeof(buffer));

		std::map<std::string, std::string> qrCfgMap;
		while(fgets(buffer, sizeof(buffer), fp)) {

			string queryStr(buffer);
			string::size_type pos = queryStr.find_first_of('=');
			string data = queryStr.substr(pos + 1);	data.erase(data.find_last_not_of(" \t\r\n")+1);
			string key = queryStr.substr(0, pos);

//			m_pBizLog->LogError("[%s][%s][%d] key[%s] : data[%s]", __FILE__, __FUNCTION__, __LINE__, key.c_str(), data.c_str());

			qrCfgMap.insert(make_pair(key, data));
		}

		strcpy(stQrParam.szQR_IP, qrCfgMap["qr_trans_service_addr"].c_str());
		strcpy(stQrParam.szQR_Port, qrCfgMap["qr_trans_service_port"].c_str());
		stQrParam.cQR_TimeOut = atoi(qrCfgMap["qr_trans_timeout"].c_str());

		strcpy(stQrParam.szQR_OD_IP, qrCfgMap["qr_od_check_service_ip"].c_str());
		strcpy(stQrParam.szQR_OD_Port, qrCfgMap["qr_od_check_service_port"].c_str());
		stQrParam.cQR_OD_TimeOut = atoi(qrCfgMap["qr_od_check_timeout"].c_str());
		stQrParam.iQR_Interval = atoi(qrCfgMap["qr_heartbeat_interval"].c_str());

		strcpy(stQrParam.szODA_IP, qrCfgMap["quickpass_trans_service_ip"].c_str());
		strcpy(stQrParam.szODA_Port, qrCfgMap["quickpass_trans_service_port"].c_str());
		stQrParam.cODA_TimeOut = atoi(qrCfgMap["quickpass_trans_timeout"].c_str());

		strcpy(stQrParam.szODA_OD_IP, qrCfgMap["quickpass_od_check_service_ip"].c_str());
		strcpy(stQrParam.szODA_OD_Port, qrCfgMap["quickpass_od_check_service_port"].c_str());
		stQrParam.cODA_OD_TimeOut = atoi(qrCfgMap["quickpass_od_check_timeout"].c_str());
		stQrParam.cODA_OD_iInterval = atoi(qrCfgMap["quickpass_heartbeat_interval"].c_str());

		strcpy(stQrParam.sz_op_app_id, qrCfgMap["op_app_id"].c_str());

		_PrintParseRus(stQrParam);
	}
	if(fp != NULL) fclose(fp);
//	fp=NULL;

//	m_pBizLog->LogDebug("[%s][%s][%d] _ParseQRParmCfg end!", __FILE__, __FUNCTION__, __LINE__);
//	return bOK;
}

void _PrintParseRus(ST_QR_NET_SETTING_PARAM stQrParam)
{
	return;
	printf("szQR_IP(%s), szQR_Port(%s), cQR_TimeOut(%d)\n", stQrParam.szQR_IP, stQrParam.szQR_Port, stQrParam.cQR_TimeOut);
	printf("szQR_OD_IP(%s), szQR_OD_Port(%s), cQR_OD_TimeOut(%d)\n", stQrParam.szQR_OD_IP, stQrParam.szQR_OD_Port, stQrParam.cQR_OD_TimeOut);
	printf("sz_op_app_id(%s)\n", stQrParam.sz_op_app_id);
}
