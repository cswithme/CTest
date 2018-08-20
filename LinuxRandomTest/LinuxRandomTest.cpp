//============================================================================
// Name        : LinuxRandomTest.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
using namespace std;

int random_number(unsigned int min, unsigned int max);
unsigned char calcRus(unsigned int uiC, unsigned int uiD);

//typedef struct
//{
//    unsigned char C0;
//    unsigned char C1;
//    unsigned char C2;
//    unsigned char C3;
//
//    unsigned char D0;
//    unsigned char D1;
//    unsigned char D2;
//    unsigned char D3;
//}ST_GCU_ECU;

typedef struct
{

	unsigned char C3;
	unsigned char C2;
	unsigned char C1;
	unsigned char C0;

	unsigned char D3;
	unsigned char D2;
	unsigned char D1;
	unsigned char D0;
}ST_GCU_ECU;

int main()
{
	while(1)
	{
		usleep(1000 * 1000);

//		unsigned int iRus1 = random_number(0x01, 0xffffffff);
//		printf("%#010x\n", iRus);

//		unsigned char ucRus = calcRus(random_number(0x01, 0xffffffff), random_number(0x01, 0xffffffff));
//		0X3BF1AD75
		unsigned char ucRus = calcRus(0X3BF1AD75, 0XCF2BCAA1);
		printf("%#04x\n", ucRus);
		continue;
		static int iCnt =0;
		if(++iCnt == 10)
		{
			putchar('\n');
			iCnt = 0;
		}
	}

	return 0;
}

unsigned char calcRus(unsigned int uiC, unsigned int uiD)
{
	ST_GCU_ECU g_Gcu_Ecu;
	memcpy(&g_Gcu_Ecu.C3, &uiC, 4);
	memcpy(&g_Gcu_Ecu.D3, &uiD, 4);

	g_Gcu_Ecu.D3 = 2*((((g_Gcu_Ecu.C0<<1) + (g_Gcu_Ecu.D0 + 4))*2)+((g_Gcu_Ecu.C1 + 3)*(g_Gcu_Ecu.D1>>3))+(g_Gcu_Ecu.C2 - 10)*(g_Gcu_Ecu.D2>>2))/(g_Gcu_Ecu.C3 + 7);
	return g_Gcu_Ecu.D3;
}


/* 从min和max中返回一个随机值 */
int random_number(unsigned int min,unsigned int max)
{
    static int dev_random_fd = -1;
    char *next_random_byte;
    int bytes_to_read;
    unsigned random_value;

    assert(max > min);

    if (dev_random_fd == -1)
    {
        dev_random_fd = open("/dev/urandom", O_RDONLY);
        assert(dev_random_fd != -1);
    }

    next_random_byte = (char *)&random_value;
    bytes_to_read = sizeof(random_value);

    /* 因为是从/dev/random中读取，read可能会被阻塞，一次读取可能只能得到一个字节，
     * 循环是为了让我们读取足够的字节数来填充random_value.
     */
    do
    {
        int bytes_read;
        bytes_read = read(dev_random_fd, next_random_byte, bytes_to_read);
        bytes_to_read -= bytes_read;
        next_random_byte += bytes_read;
    }while(bytes_to_read > 0);

    return min + (random_value % (max - min + 1));
}
