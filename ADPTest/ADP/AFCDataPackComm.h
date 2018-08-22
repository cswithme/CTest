/*! \file   AFCDataPackComm.h
 *  \brief  基本类型的转换打(解)包
 *  \auther xuyk
 *  \date   2010-12-22
 */

#ifndef	_H_AFC_DATA_PACK_COMM_
#define	_H_AFC_DATA_PACK_COMM_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iconv.h>
#include <arpa/inet.h>

#define ADP_FALSE   0
#define ADP_TRUE    1

#define mem_alloc(bsize)    malloc(bsize)
//#define mem_free(ptr, bsize)    free(ptr)//del zhaoxw20161017
//#define mem_free(ptr, bsize)    ptr==NULL?1==1:free(ptr)  //zhaoxw20161017
#ifdef   mem_free // LiuYF add @20170506 for prevent re-define
# undef  mem_free
# define mem_free(ptr, bsize)    ptr==NULL?1==1:free(ptr)
#else 
# define mem_free(ptr, bsize)    ptr==NULL?1==1:free(ptr)
#endif

/***************/
/*  定长字符串   */
/***************/
#define ADP_STR_FIXED_LENGTH    0

typedef char string_t;
typedef char fixstring_t;
typedef char bcd_t;
typedef unsigned char block_t;
typedef char string2_t; //char4字节长度(默认)+buf内容 。tranp中赋值时直接当作string_t类型赋值，不考虑长度域.
typedef unsigned char block2_t;//变长block类型 ，前面n个字节表示长度。用主机序对长度赋值zxw20161116

/* 操作 */
enum adp_op {
    ADP_ENCODE = 0,     /*打包*/
    ADP_DECODE = 1,     /*解包*/
    ADP_FREE = 2,       /*释放内存*/
    ADP_CHECK = 3       /**/
};

/* 处理类型 */
enum adp_tp {
    ADP_TP_MEM = 0,     /*memory buffer*/
    ADP_TP_STDIO = 1,   /*file*/
    ADP_TP_SIZE = 2     /*get size*/
};

/* Afc Data Pack struct */
typedef struct {
	enum adp_op op;                 /*操作*/
    enum adp_tp tp;                 /*处理类型*/
	caddr_t         pBuf;           /*数据Buffer头指针*/
	caddr_t         pBufCur;		/*数据Buffer当前位置指针*/
	unsigned int    iBufCurLen;     /*数据Buffer已打(解)包长度*/
	unsigned int    iBufMaxLen;     /*数据Buffer最大长度*/
    unsigned int    iErrNo;         /*error code*/
    caddr_t         *pMsgType;      /*message type*/
    caddr_t         *pSf;           /*session flag*/
    //caddr_t         *pRecCnt;       /*包体可变部分记录数 xuyk add 20161219*/
    int iRecCnt;       /*包体可变部分记录数 mod zhaoxw20161220*/
}ADP;

typedef int (*adpproc_t)(ADP *, void *);

/* 字节序 */
typedef enum {
	BO_MOTO = 0,
	BO_INTEL
}ByteOrders;


/* 字节序转换 */
extern void ReverseByteOrder(char *p, int iType);

/* 编码转换 */
extern int Code_Convert(char *pin, char *pout, int iLen, const char *pInType, const char *pOutType);

extern void adpmem_create(ADP *, const caddr_t, const unsigned int, const enum adp_op);
extern void adpstdio_create(ADP *, FILE *, const enum adp_op);
extern void adp_free(adpproc_t, char *);
extern unsigned int adp_sizeof(adpproc_t, void *);

extern int adp_int64_t(ADP *, int64_t *, uint32_t, ByteOrders);
extern int adp_int32_t(ADP *, int32_t *, uint32_t, ByteOrders);
extern int adp_int16_t(ADP *, int16_t *, uint32_t, ByteOrders);
extern int adp_int8_t(ADP *, int8_t *, uint32_t);
extern int adp_uint64_t(ADP *, uint64_t *, uint32_t, ByteOrders);
extern int adp_uint32_t(ADP *, uint32_t *, uint32_t, ByteOrders);
extern int adp_uint16_t(ADP *, uint16_t *, uint32_t, ByteOrders);
extern int adp_uint8_t(ADP *, uint8_t *, uint32_t);
extern int adp_string_t(ADP *, char **, uint32_t, int, char *, char *);
extern int adp_fixstring_t(ADP *, char *, uint32_t);
extern int adp_bcd_t(ADP *, char *,  int);
extern int adp_block_t(ADP *, unsigned char *, unsigned int);
extern int adp_indefblock_t (ADP *, unsigned char *, unsigned int, unsigned int);
extern int adp_string2_t (ADP *adp, char **ppc, uint32_t imaxsize, int iStrType, int iChSize);
extern int adp_putbytes (ADP *, caddr_t, int);
extern int adp_getbytes (ADP *, caddr_t, int);
extern int adp_array(ADP *, caddr_t *, unsigned int, const unsigned int, const unsigned int, const adpproc_t);



#endif

