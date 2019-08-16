#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "TypeDef.h"
#include <time.h>
#include <sys/time.h> //gettimeofday
#include <unistd.h>
#include <stdint.h>
#include <map>
#include <math.h>
#include <iconv.h>
#include <set>
#include <pthread.h>
#include <vector>
#include <algorithm>    // std::sort

uint32_t _GetMsgIDFromMsg(const char* pszMsg)
{
	//{“command”:   1001, “data”: {“xxxx”: “xxxx”}, “time”:”2019-07-11 13:15:30”, “message_id”:12345}
	const char* szMatch = "\"message_id\":";
	char szMsgID[16]; memset(szMsgID, 0, sizeof(szMsgID));
	const char* pos = strstr(pszMsg, szMatch);
	if(NULL == pos) {
		return 0;
	}

	const char* end = index(pos, ',');
	if(NULL == end) end = index(pos, '}');

	memcpy(szMsgID, pos+strlen(szMatch), end-pos-strlen(szMatch));

	uint32_t u32MsgID = strtoul(szMsgID, NULL, 10);
	return u32MsgID;
}

int main()
{
	puts("Test begin!");

//	uint8_t psz[] = {0x02, 0x30, 0x30, 0x34, 0x38, 0x7B, 0x22, 0x63, 0x6F, 0x6D, 0x6D, 0x61, 0x6E, 0x64,
//			0x22, 0x3A, 0x31, 0x30, 0x30, 0x31, 0x2C, 0x22, 0x64, 0x61, 0x74, 0x61, 0x22, 0x3A, 0x22, 0x7B,
//			0x7D, 0x22, 0x2C, 0x22, 0x74, 0x69, 0x6D, 0x65, 0x22, 0x3A, 0x22, 0x32, 0x30, 0x31, 0x39, 0x2D,
//			0x30, 0x37, 0x2D, 0x33, 0x30, 0x20, 0x31, 0x36, 0x3A, 0x31, 0x33, 0x3A, 0x32, 0x36, 0x22, 0x2C,
//			0x22, 0x6D, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x5F, 0x69, 0x64, 0x22, 0x3A, 0x31, 0x7D, 0x42,
//			0x33, 0x43, 0x34, 0x03};
//
//	printf("psz(%s)\n", psz);
//	uint32_t u32Ret = _GetMsgIDFromMsg((const char*)psz);
//	printf("u32Ret(%d)\n", u32Ret);

	uint32_t u32Data = 600197;
	printf("u32Data(%u)\n", u32Data);

	puts("Test end!");

	return 0;

}




