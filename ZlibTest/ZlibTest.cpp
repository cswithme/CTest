//============================================================================
// Name        : ZlibTest.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "zlib.h"

using namespace std;

typedef unsigned long uLong;

void printHex(const unsigned char *pHex, unsigned int uiHexLen);
int gzdecompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata);
int testfunc1();

int main()
{
	puts("Test begin!");

//	testfunc1();

	/*1. 解压GZIP格式的数据*/
	char szDataToUnzip[] = {0x1F, 0x8B, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1D, 0x8D, 0xB1,
			0x0E, 0xC2, 0x20, 0x14, 0x45, 0xFF, 0xE5, 0xCE, 0x0C, 0x0F, 0xA5, 0x56, 0x58, 0x9D, 0x9D, 0xEA, 0x6E, 0x28, 0x79, 0x56,
			0x92, 0xFA, 0x68, 0x08, 0x6A, 0x4C, 0xD3, 0x7F, 0x97, 0xB2, 0x9D, 0x9C, 0x9B, 0x9C, 0xBB, 0x22, 0x24, 0x29, 0x2C, 0x05,
			0x6E, 0x85, 0xCF, 0x93, 0x86, 0x23, 0x85, 0x28, 0x8F, 0xB4, 0x8B, 0x25, 0x7D, 0x39, 0xC3, 0x1D, 0x4F, 0x44, 0xDA, 0xD8,
			0x33, 0x51, 0xD7, 0x91, 0x51, 0x18, 0xD9, 0xBF, 0xE0, 0xB4, 0xC2, 0xE5, 0x3A, 0x84, 0x94, 0xB9, 0xB2, 0xE9, 0x15, 0xC2,
			0xD3, 0x8B, 0xF0, 0xDC, 0x0A, 0x5E, 0xA6, 0xB9, 0x7A, 0x6B, 0x37, 0xB5, 0x67, 0x0F, 0x4D, 0xF2, 0xA7, 0x1E, 0xDD, 0x7E,
			0x4B, 0x1D, 0x4C, 0xF5, 0xA5, 0x11, 0x7C, 0x7C, 0xC7, 0x7B, 0x9B, 0xB0, 0xFD, 0x01, 0xEE, 0x79, 0xC8, 0x8E, 0x8F, 0x00,
			0x00, 0x00};

	char szDataRus[1024] = {0};
	uLongf rusLen = sizeof(szDataRus);


	//	从网上down下来的代码https://blog.csdn.net/chary8088/article/details/48047835，调用
	/* zdata 原数据 nzdata 原数据长度 data 解压后数据 ndata 解压后长度 */
//	int gzdecompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata)
	int iRet = gzdecompress((Byte *)szDataToUnzip, sizeof(szDataToUnzip), (Byte *)szDataRus, &rusLen);
	if(iRet)
		puts("失败");

	puts("\nData after unzip:");
	printHex((unsigned char*)szDataRus, rusLen);


	/*2. 原始数据通过compressBound解密,默认是zlib的文件格式*/
//	char szDataToZip[] = {
//			0x7B,  0x22,  0x63,  0x6F,  0x6E,  0x74,  0x65,  0x6E,  0x74,  0x22,  0x3A,  0x7B,  0x22,  0x61,  0x72,  0x67,
//			0x31,  0x22,  0x3A,  0x30,  0x2C,  0x22,  0x69,  0x6E,  0x66,  0x6F,  0x22,  0x3A,  0x7B,  0x22,  0x70,  0x6F,
//			0x77,  0x65,  0x72,  0x22,  0x3A,  0x33,  0x36,  0x30,  0x30,  0x31,  0x34,  0x39,  0x38,  0x30,  0x30,  0x35,
//			0x35,  0x30,  0x34,  0x2C,  0x22,  0x62,  0x65,  0x61,  0x6D,  0x22,  0x3A,  0x31,  0x2C,  0x22,  0x43,  0x4D,
//			0x53,  0x63,  0x6F,  0x72,  0x65,  0x22,  0x3A,  0x31,  0x34,  0x37,  0x2C,  0x22,  0x63,  0x68,  0x61,  0x6E,
//			0x6E,  0x65,  0x6C,  0x22,  0x3A,  0x30,  0x2C,  0x22,  0x61,  0x6E,  0x67,  0x6C,  0x65,  0x22,  0x3A,  0x39,
//			0x39,  0x7D,  0x2C,  0x22,  0x61,  0x72,  0x67,  0x32,  0x22,  0x3A,  0x30,  0x2C,  0x22,  0x65,  0x76,  0x65,
//			0x6E,  0x74,  0x54,  0x79,  0x70,  0x65,  0x22,  0x3A,  0x34,  0x7D,  0x2C,  0x22,  0x74,  0x79,  0x70,  0x65,
//			0x22,  0x3A,  0x22,  0x61,  0x69,  0x75,  0x69,  0x5F,  0x65,  0x76,  0x65,  0x6E,  0x74,  0x22,  0x7D};
//
//	puts(szDataToZip);
//
//	/* 计算缓冲区大小，并为其分配内存 */
//	unsigned int blen = compressBound(sizeof(szDataToZip)); /* 压缩后的长度是不会超过blen的 */
//	char *buf = (char*)malloc(blen);
//	if (buf == NULL)
//	{
//		printf("no enough memory!\n");
//		return -1;
//	}
	puts("Test end!");
	return 0;
}

/* Compress gzip data */
/* data 原数据 ndata 原数据长度 zdata 压缩后数据 nzdata 压缩后长度 */
int gzcompress(Bytef *data, uLong ndata,
               Bytef *zdata, uLong *nzdata)
{
    z_stream c_stream;
    int err = 0;

    if(data && ndata > 0) {
        c_stream.zalloc = NULL;
        c_stream.zfree = NULL;
        c_stream.opaque = NULL;
        //只有设置为MAX_WBITS + 16才能在在压缩文本中带header和trailer
        if(deflateInit2(&c_stream, Z_DEFAULT_COMPRESSION, Z_DEFLATED,
                        MAX_WBITS + 16, 8, Z_DEFAULT_STRATEGY) != Z_OK) return -1;
        c_stream.next_in  = data;
        c_stream.avail_in  = ndata;
        c_stream.next_out = zdata;
        c_stream.avail_out  = *nzdata;
        while(c_stream.avail_in != 0 && c_stream.total_out < *nzdata) {
            if(deflate(&c_stream, Z_NO_FLUSH) != Z_OK) return -1;
        }
        if(c_stream.avail_in != 0) return c_stream.avail_in;
        for(;;) {
            if((err = deflate(&c_stream, Z_FINISH)) == Z_STREAM_END) break;
            if(err != Z_OK) return -1;
        }
        if(deflateEnd(&c_stream) != Z_OK) return -1;
        *nzdata = c_stream.total_out;
        return 0;
    }
    return -1;
}

/* Uncompress gzip data */
/* zdata 数据 nzdata 原数据长度 data 解压后数据 ndata 解压后长度 */
int gzdecompress(Byte *zdata, uLong nzdata,
                 Byte *data, uLong *ndata)
{
    int err = 0;
    z_stream d_stream = {0}; /* decompression stream */
    static char dummy_head[2] = {
        0x8 + 0x7 * 0x10,
        (((0x8 + 0x7 * 0x10) * 0x100 + 30) / 31 * 31) & 0xFF,
    };
    d_stream.zalloc = NULL;
    d_stream.zfree = NULL;
    d_stream.opaque = NULL;
    d_stream.next_in  = zdata;
    d_stream.avail_in = 0;
    d_stream.next_out = data;
    //只有设置为MAX_WBITS + 16才能在解压带header和trailer的文本
    if(inflateInit2(&d_stream, MAX_WBITS + 16) != Z_OK) return -1;
    //if(inflateInit2(&d_stream, 47) != Z_OK) return -1;
    while(d_stream.total_out < *ndata && d_stream.total_in < nzdata) {
        d_stream.avail_in = d_stream.avail_out = 1; /* force small buffers */
        if((err = inflate(&d_stream, Z_NO_FLUSH)) == Z_STREAM_END) break;
        if(err != Z_OK) {
            if(err == Z_DATA_ERROR) {
                d_stream.next_in = (Bytef*) dummy_head;
                d_stream.avail_in = sizeof(dummy_head);
                if((err = inflate(&d_stream, Z_NO_FLUSH)) != Z_OK) {
                    return -1;
                }
            } else return -1;
        }
    }
    if(inflateEnd(&d_stream) != Z_OK) return -1;
    *ndata = d_stream.total_out;
    return 0;
}

void printHex(const unsigned char *pHex, unsigned int uiHexLen)
{
	for(unsigned int i=0; i<uiHexLen; ++i)
	{
		if(i!=0 && i%16==0)	putchar('\n');

		printf("%02x ", pHex[i]);
	}
	putchar('\n');
}

int testfunc1()
{
#if 1
	char text[] = "zlib compress and uncompress test\nturingo@163.com\n2012-11-05\n";
	char de_text[1024];
	uLong tlen = strlen(text) + 1;  /* 需要把字符串的结束符'\0'也一并处理 */
	char* buf = NULL;
	uLong blen;

	puts("\nData before zip:");
	printHex((unsigned char*)text, strlen(text)+1);

	/* 计算缓冲区大小，并为其分配内存 */
	blen = compressBound(tlen); /* 压缩后的长度是不会超过blen的 */
	if ((buf = (char*)malloc(sizeof(char) * blen)) == NULL)
	{
		printf("no enough memory!\n");
		return -1;
	}

	/* 压缩 */
	if (compress((Bytef *)buf, &blen, (Bytef *)text, tlen) != Z_OK)
	{
		printf("compress failed!\n");
		return -1;
	}

	puts("\nData after zip:");
	printHex((unsigned char*)buf, blen);

	/* 解压缩 */
	if (uncompress((Bytef *)de_text, &tlen, (Bytef *)buf, blen) != Z_OK)
	{
		printf("uncompress failed!\n");
		return -1;
	}
	puts("\nData after unzip:");
	printHex((unsigned char*)de_text, tlen);

	/* 打印结果，并释放内存 */
	printf("%s", de_text);
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	return 0;
#endif
}
