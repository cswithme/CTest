/*! \file   AFCDataPackComm.c
 *  \brief  基本类型的转换打(解)包
 */

#include "AFCDataPackComm.h"

/*去除字符串右边空格*/  
void StrRTrim(char *pcStr)  
{
    char *pcTmp = pcStr + strlen(pcStr) - 1;

    while (*pcTmp == ' ')
    {
        *pcTmp = 0;
        pcTmp--;
    }
}

/* 字节序转换 */
void ReverseByteOrder(char *p, int iType)
{
    char temp;

    switch (iType) {
        case 2:
            temp = *p;
            *p = *(p + 1);
            *(p + 1) = temp;
            break;
        case 4:
            temp = *p;
            *p = *(p + 3);
            *(p + 3) = temp;

            temp = *(p + 1);
            *(p + 1) = *(p + 2);
            *(p + 2) = temp;
            break;
        default:
            break;
    }
    return;
}

/*char *pin;               source string */
/*char *pout;              destination string */
/*int iLen;                source string length */
/*const char *pInType;     source string coding */
/*const char *pOutType;    destination string coding */
/* 编码转换 */
int Code_Convert(char *pin, char *pout, int iLen, const char *pInType, const char *pOutType)
{
    size_t inleft = iLen;
    size_t outleft = iLen;

    iconv_t cd = iconv_open(pInType, pOutType);
    if((int)cd == -1)
        return ADP_FALSE;

    if((int)iconv(cd, &pin, &inleft, &pout, &outleft) == -1)
        return ADP_FALSE;

    iconv_close(cd);

    return ADP_TRUE;
}

/* ADP memory buffer 处理初始化 */
void adpmem_create (register ADP *adp,caddr_t addr,unsigned int size,enum adp_op op)
{
    adp->op = op;
    adp->tp = ADP_TP_MEM;
    adp->pBuf = adp->pBufCur = addr;
    adp->iBufMaxLen = size;
    adp->iBufCurLen = 0;
    adp->iErrNo = 0;
    adp->pMsgType = NULL;
    adp->pSf = NULL;
}

/* ADP file 处理初始化 */
void adpstdio_create (register ADP *adp, FILE *file, enum adp_op op)    
{    
    adp->op = op;
    adp->tp = ADP_TP_STDIO;
    adp->pBufCur = (caddr_t) file;
    adp->iBufMaxLen = 0;
    adp->iBufCurLen = 0;
    adp->iErrNo = 0;
    adp->pMsgType = NULL;
    adp->pSf = NULL;
}

/* ADP 获取传输长度 */
unsigned int adp_sizeof (adpproc_t func, void *data)
{
    int iRet;

    ADP adp;

    adp.op = ADP_ENCODE;
    adp.tp = ADP_TP_SIZE;
    adp.pBufCur = (caddr_t) NULL;
    adp.iBufMaxLen = 0;
    adp.iBufCurLen = 0;

    iRet = func (&adp, data);

    return iRet == ADP_TRUE ? adp.iBufCurLen : 0;
}

/* ADP 内存释放 */
void adp_free (adpproc_t proc, char *objp)
{
    ADP adp;

    adp.op = ADP_FREE;
    (*proc) (&adp, objp);
}

/* int64 型打(解)包 */
int adp_int64_t (ADP *adp, int64_t *pi, uint32_t isize, ByteOrders iByteOrders)
{
    return adp_uint64_t(adp, (uint64_t *)pi, isize, iByteOrders);
}

/* uint64 型打(解)包 */
int adp_uint64_t (ADP *adp, uint64_t *ip, uint32_t isize, ByteOrders iByteOrders)
{
    uint32_t t1, t2;

    if (isize != sizeof(uint64_t))
        return ADP_FALSE;

    switch (adp->op) {
        case ADP_ENCODE:
            t1 = (uint32_t) ((*ip) >> 32);
            t2 = (uint32_t) (*ip);
            return (adp_uint32_t(adp, &t1, sizeof(uint32_t), iByteOrders) && adp_uint32_t(adp, &t2, sizeof(uint32_t),iByteOrders));

        case ADP_DECODE:
        case ADP_CHECK: 
            if (!adp_uint32_t(adp, &t1, sizeof(uint32_t), iByteOrders) || !adp_uint32_t(adp, &t2, sizeof(uint32_t), iByteOrders))
                return ADP_FALSE;
            *ip = ((uint64_t) t1) << 32;
            *ip |= t2;
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/* int32 型打(解)包 */
int adp_int32_t (ADP *adp,int32_t *pi, uint32_t isize, ByteOrders iByteOrders)
{
    return adp_uint32_t(adp, (uint32_t *)pi, isize, iByteOrders);
}

/* uint32 型打(解)包 */
int adp_uint32_t (ADP *adp, uint32_t *pi, uint32_t isize, ByteOrders iByteOrders)
{
    uint32_t i;
    char caTmp[3] = "";
    char caPrintStr[13] = "";
    uint8_t *pcValue;
    uint32_t iValue = (*pi);

    if (isize != sizeof(uint32_t))
        return ADP_FALSE;

    adp->iBufCurLen += isize;

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            iValue = htonl(iValue);

            /* 强制INTEL字节序转换 */
            if (iByteOrders == BO_INTEL) {
                ReverseByteOrder((char *)&iValue, isize);
            }

            return adp_putbytes(adp, (caddr_t)&iValue, isize);

        case ADP_DECODE:
        case ADP_CHECK: 
            if (!adp_getbytes(adp, (caddr_t)&iValue, isize))
                return ADP_FALSE;

            if(adp->op == ADP_CHECK)
            {
                pcValue = (uint8_t *)&iValue;
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(caPrintStr, " ");
                    sprintf(caTmp, "%02X", *(pcValue + i));
                    strcat(caPrintStr, caTmp);
                }
                printf("%s\n", caPrintStr);
            }

            /* 强制INTEL字节序转换 */
            if (iByteOrders == BO_INTEL) {
                ReverseByteOrder((char *)&iValue, isize);
            }

            (*pi) = ntohl(iValue);
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/* int16 型打(解)包 */
int adp_int16_t (ADP *adp, int16_t *pi, uint32_t isize,ByteOrders iByteOrders)
{
    uint32_t i;
    char caTmp[3] = "";
    char caPrintStr[13] = "";
    uint8_t *pcValue;
    int16_t sValue = (*pi);
    int32_t iValue = (*pi);

    if (isize != sizeof(int16_t) && isize != sizeof(int32_t))
        return ADP_FALSE;

    adp->iBufCurLen += isize;

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            /* 是否需要4字节对齐 */
            isize == sizeof(int16_t) ? (sValue = htons(sValue)) : (iValue = htonl(iValue));

            /* 强制INTEL字节序转换 */
            if (iByteOrders == BO_INTEL) {
                ReverseByteOrder(isize == sizeof(int16_t) ? (char *)&sValue : (char *)&iValue, isize);
            }

            return adp_putbytes(adp, isize == sizeof(int16_t) ? (caddr_t)&sValue : (caddr_t)&iValue, isize);

        case ADP_DECODE:
        case ADP_CHECK:     
            if (!adp_getbytes(adp, isize == sizeof(int16_t) ? (caddr_t)&sValue : (caddr_t)&iValue, isize))
                return ADP_FALSE;

            if(adp->op == ADP_CHECK)
            {
                pcValue = isize == sizeof(int16_t) ? (uint8_t*)&sValue : (uint8_t*)&iValue;
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(caPrintStr, " ");
                    sprintf(caTmp, "%02X", *(pcValue + i));
                    strcat(caPrintStr, caTmp);
                }
                printf("%s\n", caPrintStr);
            }

            /* 强制INTEL字节序转换 */
            if (iByteOrders == BO_INTEL) {
                ReverseByteOrder(isize == sizeof(int16_t) ? (char *)&sValue : (char *)&iValue, isize);
            }

            /* 是否需要4字节对齐 */
            isize == sizeof(int16_t) ? ((*pi) = htons(sValue)) : ((*pi) = ntohl(iValue));
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/* uint16 型打(解)包 */
int adp_uint16_t (ADP *adp,uint16_t *pi, uint32_t isize, ByteOrders iByteOrders)
{
    uint32_t i;
    char caTmp[3] = "";
    char caPrintStr[13] = "";
    uint8_t *pcValue;
    uint16_t sValue = (*pi);
    uint32_t iValue = (*pi);

    if (isize != sizeof(uint16_t) && isize != sizeof(uint32_t))
        return ADP_FALSE;

    adp->iBufCurLen += isize;

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            /* 是否需要4字节对齐 */
            isize == sizeof(uint16_t) ? (sValue = htons(sValue)) : (iValue = htonl(iValue));

            /* 强制INTEL字节序转换 */
            if (iByteOrders == BO_INTEL) {
                ReverseByteOrder(isize == sizeof(uint16_t) ? (char *)&sValue : (char *)&iValue, isize);
            }

            return adp_putbytes(adp, isize == sizeof(uint16_t) ? (caddr_t)&sValue : (caddr_t)&iValue, isize);

        case ADP_DECODE:
        case ADP_CHECK: 
            if (!adp_getbytes(adp, isize == sizeof(uint16_t) ? (caddr_t)&sValue : (caddr_t)&iValue, isize))
                return ADP_FALSE;

            if(adp->op == ADP_CHECK)
            {
                pcValue = isize == sizeof(uint16_t) ? (uint8_t*)&sValue : (uint8_t*)&iValue;
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(caPrintStr, " ");
                    sprintf(caTmp, "%02X", *(pcValue + i));
                    strcat(caPrintStr, caTmp);
                }
                printf("%s\n", caPrintStr);
            }

            /* 强制INTEL字节序转换 */
            if (iByteOrders == BO_INTEL) {
                ReverseByteOrder(isize == sizeof(uint16_t) ? (char *)&sValue : (char *)&iValue, isize);
            }

            /* 是否需要4字节对齐 */
            isize == sizeof(uint16_t) ? ((*pi) = htons(sValue)) : ((*pi) = ntohl(iValue));
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/* int8 型打(解)包 */
int adp_int8_t (ADP *adp, int8_t *pi, uint32_t isize)
{
    uint32_t i;
    char caTmp[3] = "";
    char caPrintStr[13] = "";
    uint8_t *pcValue;
    int32_t iValue = (*pi);
    int8_t cValue = (*pi);

    if (isize != sizeof(int8_t) && isize != sizeof(int32_t))
        return ADP_FALSE;

    adp->iBufCurLen += isize;

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            /* 是否需要4字节对齐 */
            if (isize == sizeof(int32_t))
                iValue = htonl(iValue);

            return adp_putbytes(adp, isize == sizeof(int8_t) ? (caddr_t)&cValue : (caddr_t)&iValue, isize);

        case ADP_DECODE:
        case ADP_CHECK:     
            if (!adp_getbytes(adp, isize == sizeof(int8_t) ? (caddr_t)&cValue : (caddr_t)&iValue, isize))
                return ADP_FALSE;

            if(adp->op == ADP_CHECK)
            {
                pcValue = isize == sizeof(int8_t) ? (uint8_t*)&cValue : (uint8_t*)&iValue;
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(caPrintStr, " ");
                    sprintf(caTmp, "%02X", *(pcValue + i));
                    strcat(caPrintStr, caTmp);
                }
                printf("%s\n", caPrintStr);
            }

            /* 是否需要4字节对齐 */
            isize == sizeof(int8_t) ? ((*pi) = cValue) : ((*pi) = ntohl(iValue));
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/* uint8 型打(解)包 */
int adp_uint8_t (ADP *adp, uint8_t *pi, uint32_t isize)
{
    uint32_t i;
    char caTmp[3] = "";
    char caPrintStr[13] = "";
    uint8_t *pcValue;
    uint32_t iValue = (*pi);
    uint8_t cValue = (*pi);

    if (isize != sizeof(uint8_t) && isize != sizeof(uint32_t))
        return ADP_FALSE;

    adp->iBufCurLen += isize;

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            /* 是否需要4字节对齐 */
            if (isize == sizeof(uint32_t))
                iValue = htonl(iValue);

            return adp_putbytes(adp, isize == sizeof(uint8_t) ? (caddr_t)&cValue : (caddr_t)&iValue, isize);

        case ADP_DECODE:
        case ADP_CHECK: 
            if (!adp_getbytes(adp, isize == sizeof(uint8_t) ? (caddr_t)&cValue : (caddr_t)&iValue, isize))
                return ADP_FALSE;

            if(adp->op == ADP_CHECK)
            {
                pcValue = isize == sizeof(uint8_t) ? (uint8_t*)&cValue : (uint8_t*)&iValue;
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(caPrintStr, " ");
                    sprintf(caTmp, "%02X", *(pcValue + i));
                    strcat(caPrintStr, caTmp);
                }
                printf("%s\n", caPrintStr);
            }

            /* 是否需要4字节对齐 */
            isize == sizeof(uint8_t) ? ((*pi) = cValue) : ((*pi) = ntohl(iValue));
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/* string 型打(解)包 */
/*uint32_t imaxsize;   string max size */
/*int iStrType;        string type (0:fixed length 1:actual length) */
/*char *pStrCodingN;   string coding in net */
/*char *pStrCodingL;   string coding in local */
int adp_string_t (ADP *adp, char **ppc, uint32_t imaxsize, int iStrType, char *pStrCodingN, char *pStrCodingL)
{
    uint32_t i;
    char caTmp[3] = "";
    char *pcaPrintStr = NULL;
    char *pcStr = NULL;
    unsigned int isize = 0, iplus = 0;
    unsigned int inodesize = 0;

    char adp_zero[4] = {0, 0, 0, 0};

    /* 长度 */
    switch (adp->op) {
        case ADP_FREE:
            if (*ppc == NULL) {
                return ADP_TRUE;
            }

        case ADP_ENCODE:
            iStrType == ADP_STR_FIXED_LENGTH ? (isize = imaxsize) : (isize = (*ppc ? strlen(*ppc) : 0));
            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            isize = imaxsize;
            break;
    }

    /* 非定长字符串 */
    if (iStrType != ADP_STR_FIXED_LENGTH) {
        if (adp->op == ADP_CHECK)
            printf("string len : ");
        if (!adp_uint32_t(adp, &isize, 4, BO_MOTO))
            return ADP_FALSE;

        if(isize == 0)          
            return ADP_TRUE;    

        /* 是否需要4字节对齐 */
        iplus = isize % 4;
        if (iplus > 0) {
            iplus = 4 - iplus;
        }
    }

    if (isize + iplus > imaxsize) {
        return ADP_FALSE;
    }
    inodesize = isize + 1;

    adp->iBufCurLen += (isize + iplus);

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            if (pStrCodingN && pStrCodingL) {
                /* 需要 字符编码转换 */
                pcStr = mem_alloc(inodesize);
                memset(pcStr, 0, inodesize);
                if(!Code_Convert((*ppc), pcStr, isize, pStrCodingL, pStrCodingN))
                {
                    mem_free(pcStr, inodesize);
                    return ADP_FALSE;
                }

                if (!adp_putbytes(adp, (caddr_t)pcStr, isize)) {
                    mem_free(pcStr, inodesize);
                    return ADP_FALSE;
                }
                mem_free(pcStr, inodesize);
            } else {
                /* 不需要 字符编码转换 */
                if (!adp_putbytes(adp, (caddr_t)(*ppc), isize))
                    return ADP_FALSE;
            }

            /* 需要补位时 */
            if (iplus > 0) {
                if (!adp_putbytes(adp, (caddr_t)adp_zero, iplus))
                    return ADP_FALSE;
            }
            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            if (isize == 0) {
                return ADP_TRUE;
            }
            if ((*ppc) == NULL) {
                *ppc = mem_alloc(inodesize);
            }
            (*ppc)[isize] = 0;

            /* 字符编码转换 */
            if (pStrCodingN && pStrCodingL) {
                /* 需要 字符编码转换 */
                pcStr = mem_alloc(inodesize);

                if (!adp_getbytes(adp, (caddr_t)pcStr, isize)) {
                    mem_free(pcStr, inodesize);
                    return ADP_FALSE;
                }

                if(!Code_Convert(pcStr, (*ppc), isize, pStrCodingN, pStrCodingL)) {
                    mem_free(pcStr, inodesize);
                    return ADP_FALSE;
                }
                mem_free(pcStr, inodesize);
            } else {
                /* 不需要 字符编码转换 */
                if (!adp_getbytes(adp, (caddr_t)(*ppc), isize))
                    return ADP_FALSE;
            }

            if(adp->op == ADP_CHECK)
            {
                pcaPrintStr = malloc((isize + iplus) * 2 + (isize * iplus));
                if (NULL==pcaPrintStr )
                {
                    return ADP_FALSE ;
                }
                memset(pcaPrintStr, 0, (isize + iplus) * 2 + (isize * iplus));
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(pcaPrintStr, " ");
                    sprintf(caTmp, "%02X", *((*ppc) + i));
                    strcat(pcaPrintStr, caTmp);
                }
            }

            /* 需要补位时 */
            if (iplus > 0) {
                if (!adp_getbytes(adp, (caddr_t)adp_zero, iplus))
                {
                    if(pcaPrintStr) free(pcaPrintStr);
                    return ADP_FALSE;
                }
                if(adp->op == ADP_CHECK)
                {
                    for(i = 0; i < iplus; i++)
                    {
                        if(iplus == 2 || (iplus == 3 && i == 1))
                            strcat(pcaPrintStr, " ");
                        sprintf(caTmp, "%02X", adp_zero[i]);
                        strcat(pcaPrintStr, caTmp);
                    }
                }
            }
            if(adp->op == ADP_CHECK)
                printf("%s\n", pcaPrintStr);
            if(pcaPrintStr) free(pcaPrintStr);
            break;

        case ADP_FREE:
            mem_free(*ppc, inodesize);
            (*ppc) = NULL;
            break;
    }

    return ADP_TRUE;
}
/*
 * author:zhaoxw
 * date:20160416
 * note:
 * 支持char4类型作为不定长字符串的长度域
 * iChSize 长度域所占字节数
 * */
int adp_string2_t (ADP *adp, char **ppc, uint32_t imaxsize, int iStrType, int iChSize)
{
    uint32_t i;
    char caTmp[3] = "";
    char *pcaPrintStr = NULL;
    //char *pcStr = NULL;
    unsigned int isize = 0, iplus = 0;
    unsigned int inodesize = 0;

    char adp_zero[4] = {0, 0, 0, 0};

    /* 长度 */
    switch (adp->op) {
        case ADP_FREE:
            if (*ppc == NULL) {
                return ADP_TRUE;
            }

        case ADP_ENCODE:
            isize = (*ppc ? strlen(*ppc) : 0);
            //iStrType == ADP_STR_FIXED_LENGTH ? (isize = imaxsize) : (isize = (*ppc ? (strlen(*ppc) - iChSize): 0));//zhaoxw20160505			
            //printf("isize=%d\n",isize);
            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            isize = imaxsize;
            break;
    }

    /* 非定长字符串 */
    if (iStrType != ADP_STR_FIXED_LENGTH) {
        if (adp->op == ADP_CHECK)
            printf("string len : ");
        /*支持char [4]类型作长度 add by zhaoxw20160415 */
        char caSize[8]={0};
        if (adp->op == ADP_ENCODE)
        {
            memset(caSize,'0',iChSize);
            char catmp[8]={0};
            sprintf(catmp,"%d",isize);
            memcpy(caSize+iChSize-strlen(catmp),catmp,strlen(catmp));
            //   printf("caSize=[%s]\n",caSize);
        }
        if(!adp_fixstring_t(adp,caSize,iChSize))
        {
            if (adp->iErrNo==0)
                adp->iErrNo=0x00021;
            return ADP_FALSE;
        }
        isize=atoi(caSize);
        /*zhaoxw add end*/

        if(isize == 0)          
            return ADP_TRUE;    

        /* 是否需要4字节对齐 */
        iplus = isize % 4;
        iplus=0;//string2_t类型不需要四字节对齐 zhaoxw20160505
        if (iplus > 0) {
            iplus = 4 - iplus;
        }
    }

    if (isize + iplus > imaxsize) {
        return ADP_FALSE;
    }
    inodesize = isize + 1;

    adp->iBufCurLen += (isize + iplus);

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            if (!adp_putbytes(adp, (caddr_t)(*ppc), isize))
                return ADP_FALSE;

            /* 需要补位时 */
            if (iplus > 0) {
                if (!adp_putbytes(adp, (caddr_t)adp_zero, iplus))
                    return ADP_FALSE;
            }
            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            if (isize == 0) {
                return ADP_TRUE;
            }
            if ((*ppc) == NULL) {
                *ppc = mem_alloc(inodesize);
            }
            (*ppc)[isize] = 0;

            if (!adp_getbytes(adp, (caddr_t)(*ppc), isize))
                return ADP_FALSE;

            if(adp->op == ADP_CHECK)
            {
                pcaPrintStr = malloc((isize + iplus) * 2 + (isize * iplus));
                if (NULL==pcaPrintStr )
                {
                    return ADP_FALSE ;
                }
                memset(pcaPrintStr, 0, (isize + iplus) * 2 + (isize * iplus));
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(pcaPrintStr, " ");
                    sprintf(caTmp, "%02X", *((*ppc) + i));
                    strcat(pcaPrintStr, caTmp);
                }
            }

            /* 需要补位时 */
            if (iplus > 0) {
                if (!adp_getbytes(adp, (caddr_t)adp_zero, iplus))
                {
                    if(pcaPrintStr) free(pcaPrintStr);
                    return ADP_FALSE;
                }
                if(adp->op == ADP_CHECK)
                {
                    for(i = 0; i < iplus; i++)
                    {
                        if(iplus == 2 || (iplus == 3 && i == 1))
                            strcat(pcaPrintStr, " ");
                        sprintf(caTmp, "%02X", adp_zero[i]);
                        strcat(pcaPrintStr, caTmp);
                    }
                }
            }
            if(adp->op == ADP_CHECK)
                printf("%s\n", pcaPrintStr);
            if(pcaPrintStr) free(pcaPrintStr);
            break;

        case ADP_FREE:
            mem_free(*ppc, inodesize);
            (*ppc) = NULL;
            break;
    }

    return ADP_TRUE;
}

/* fixstring 型打(解)包 */
/*uint32_t imaxsize;   string max size */
int adp_fixstring_t (ADP *adp, char *ppc, uint32_t imaxsize)
{
    uint32_t i;
    char caTmp[3] = "";
    char *pcaPrintStr = NULL;
    //char *pcStr = NULL;
    unsigned int isize = 0, iplus = 0;

    //char adp_zero[4] = {0, 0, 0, 0};

    /* 长度 */
    switch (adp->op) {
        case ADP_FREE:
        case ADP_ENCODE:
        case ADP_DECODE:
        case ADP_CHECK:     
            isize = imaxsize;
            break;
    }

    adp->iBufCurLen += isize;

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            if (!adp_putbytes(adp, (caddr_t)(ppc), isize))
                return ADP_FALSE;

            break;

        case ADP_DECODE:
        case ADP_CHECK:    
            if (isize == 0) {
                return ADP_TRUE;
            }

            if (!adp_getbytes(adp, (caddr_t)(ppc), isize))
                return ADP_FALSE;
            StrRTrim(ppc); //xuyk add 20160331

            if(adp->op == ADP_CHECK)
            {
                pcaPrintStr = malloc((isize + iplus) * 2 + (isize * iplus));
                if (NULL==pcaPrintStr )
                {
                    return ADP_FALSE ;
                }
                memset(pcaPrintStr, 0, (isize + iplus) * 2 + (isize * iplus));
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(pcaPrintStr, " ");
                    sprintf(caTmp, "%02X", *((ppc) + i));
                    strcat(pcaPrintStr, caTmp);
                }
            }
            if(adp->op == ADP_CHECK)
                printf("%s\n", pcaPrintStr);
            if(pcaPrintStr) free(pcaPrintStr);
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/* BCD 型打(解)包 */
/*char *pBCDStr;           BCD string in local */
/*unsigned int iBCDLen;    BCD length in net */
//int adp_bcd_t (ADP *adp, char *pBCDStr, unsigned int iBCDLen)
int adp_bcd_t(ADP *adp, char *pBCDStr, int iBCDLen)
{
    int i;
    char caTmp[3] = "";
    char *pcaPrintStr = NULL;
    char *pBCD = NULL;

    adp->iBufCurLen += iBCDLen;

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            pBCD = mem_alloc(iBCDLen);
            //! BCD字符串转BCD
            for (i = 0; i < iBCDLen; i++) {
                *(pBCD + i) = ((*(pBCDStr + i * 2) - 0x30) << 4) + (*(pBCDStr + i * 2 + 1) - 0x30);
            }

            if (!adp_putbytes(adp, (caddr_t)pBCD, iBCDLen)) {
                mem_free(pBCD, iBCDLen);
                return ADP_FALSE;
            }
            mem_free(pBCD, iBCDLen);
            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            pBCD = mem_alloc(iBCDLen);

            if (!adp_getbytes(adp, (caddr_t)pBCD, iBCDLen)) {
                mem_free(pBCD, iBCDLen);
                return ADP_FALSE;
            }

            if(adp->op == ADP_CHECK)
            {
                pcaPrintStr = malloc(iBCDLen * 2 + iBCDLen);
                if (NULL==pcaPrintStr )
                {
                    return ADP_FALSE ;
                }
                memset(pcaPrintStr, 0, iBCDLen * 2 + iBCDLen);
                for (i = 0; i < iBCDLen; i++) {
                    if(i > 0 && i % 2 == 0)
                        strcat(pcaPrintStr, " ");
                    sprintf(caTmp, "%02X", *(pBCD + i));
                    strcat(pcaPrintStr, caTmp);
                }
                printf("%s\n", pcaPrintStr);
                free(pcaPrintStr);
            }

            //! BCD转BCD字符串
            for (i = 0; i < iBCDLen; i++) {
                *(pBCDStr + i * 2) = (((*(pBCD + i) & 0xf0) >> 4) + 0x30);
                *(pBCDStr + i * 2 + 1) = ((*(pBCD + i) & 0x0f) + 0x30);
            }

            mem_free(pBCD, iBCDLen);
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/* BLOCK(定长) 型打(解)包 */
/*char *pBlock;            block buffer */
/*unsigned int iBlockLen;  block length */
int adp_block_t (ADP *adp, unsigned char *pBlock, unsigned int iBlockLen) 
{
    uint32_t i;
    char caTmp[3] = "";
    char *pcaPrintStr = NULL;

    adp->iBufCurLen += iBlockLen;

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            if (!adp_putbytes(adp, (caddr_t)pBlock, iBlockLen))
                return ADP_FALSE;
            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            if (!adp_getbytes(adp, (caddr_t)pBlock, iBlockLen))
                return ADP_FALSE;
            if(adp->op == ADP_CHECK)
            {
                pcaPrintStr = malloc(iBlockLen * 2 + iBlockLen);
                if (NULL==pcaPrintStr )
                {
                    return ADP_FALSE ;
                }
                memset(pcaPrintStr, 0, iBlockLen * 2 + iBlockLen);
                for (i = 0; i < iBlockLen; i++) {
                    if(i > 0 && i % 2 == 0)
                        strcat(pcaPrintStr, " ");
                    sprintf(caTmp, "%02X", *(pBlock + i));
                    strcat(pcaPrintStr, caTmp);
                }
                printf("%s\n", pcaPrintStr);
                free(pcaPrintStr);
            }
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

/*变长block
 * zhaoxw
 * 20161116
 * parameter:
 *  lensize:长度字节数
 *  bytesOrder:长度字节序0:MOTO 1:INTEL
 *
 *  在赋值时长度字节始终以主机序
 * 
 * */
int adp_block2_t(ADP *adp, char **ppc, int lensize,int bytesOrder)
{
    uint32_t i;
    char caTmp[3] = "";
    char *pcaPrintStr = NULL;
    char *pcStr = NULL;
    unsigned int isize = 0, iplus = 0;
    unsigned int inodesize = 0;

    char adp_zero[4] = {0, 0, 0, 0};

    /* 长度 */
    switch (adp->op) {
        case ADP_FREE:
            if (*ppc == NULL) {
                return ADP_TRUE;
            }

        case ADP_ENCODE:
            memcpy(&isize,*ppc,lensize);
            if (isize==0)
                return ADP_TRUE;

            if (lensize==4){
                if (!adp_uint32_t(adp, &isize, 4,bytesOrder))
                    return ADP_FALSE;
            }
            else if (lensize==2){
                if (!adp_uint16_t(adp, &isize, 2, bytesOrder ))
                    return ADP_FALSE;
            }
            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            if (lensize==4){
                if (!adp_uint32_t(adp, &isize, 4,bytesOrder))
                    return ADP_FALSE;
            }
            else if (lensize==2){
                if (!adp_uint16_t(adp, &isize, 2, bytesOrder ))
                    return ADP_FALSE;
            }
            break;
    }

    if (adp->op == ADP_CHECK)
        printf("string len : ");

    if(isize == 0)          
        return ADP_TRUE;    

    adp->iBufCurLen += (isize + iplus);

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            if (!adp_putbytes(adp, (caddr_t)(*ppc)+lensize, isize))
                return ADP_FALSE;

            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            if (isize == 0) {
                return ADP_TRUE;
            }
            inodesize = isize + 1;
            if ((*ppc) == NULL) {
                *ppc = mem_alloc(inodesize);
            }
            (*ppc)[isize] = 0;

            if (!adp_getbytes(adp, (caddr_t)(*ppc)+lensize, isize))
                return ADP_FALSE;

            if(adp->op == ADP_CHECK)
            {
                pcaPrintStr = malloc((isize + iplus) * 2 + (isize * iplus));
                if (NULL==pcaPrintStr )
                {
                    return ADP_FALSE ;
                }
                memset(pcaPrintStr, 0, (isize + iplus) * 2 + (isize * iplus));
                for(i = 0; i < isize; i++)
                {
                    if(i > 0 && i % 2 == 0)
                        strcat(pcaPrintStr, " ");
                    sprintf(caTmp, "%02X", *((*ppc) + i));
                    strcat(pcaPrintStr, caTmp);
                }
            }

            if(adp->op == ADP_CHECK)
                printf("%s\n", pcaPrintStr);
            if(pcaPrintStr) free(pcaPrintStr);
            break;

        case ADP_FREE:
            mem_free(*ppc, inodesize);
            (*ppc) = NULL;
            break;
    }

    return ADP_TRUE;
}
/* BLOCK(不定长) 型打(解)包 */
/*char *pBlock;            block buffer */
/*unsigned int iBlockLen;  block length */
/*unsigned int iBlockLenType;  block length type (2: short  4:int)*/
int adp_indefblock_t (ADP *adp, unsigned char *pBlock, unsigned int iBlockLen, unsigned int iBlockLenByte) 
{
    uint32_t i;
    uint16_t ssize = 0;
    unsigned int isize = 0, iplus = 0;
    char caTmp[3] = "";
    char *pcaPrintStr = NULL;

    char adp_zero[4] = {0, 0, 0, 0};

    if (adp->op == ADP_CHECK)
        printf("block len : %d", iBlockLen);

    /* 不定长block长度 */
    if (iBlockLenByte == 4) {
        //长度本身占4个字节，block部分4字节对齐（实际长度外补零）
        isize = iBlockLen;
        if (!adp_uint32_t(adp, &isize, 4, BO_MOTO))
            return ADP_FALSE;

        if(isize == 0)          
            return ADP_TRUE;    

        /* 是否需要4字节对齐 */
        iplus = isize % 4;
        if (iplus > 0) {
            iplus = 4 - iplus;
        }
    } else {
        //长度本身占2个字节，block部分为实际长度
        ssize = iBlockLen;
        if (!adp_uint16_t(adp, &ssize, 2, BO_MOTO))
            return ADP_FALSE;

        if(ssize == 0)          
            return ADP_TRUE;    
    }

    adp->iBufCurLen += (iBlockLenByte + iBlockLen + iplus);

    switch (adp->op) {
        case ADP_ENCODE:
            if (adp->tp == ADP_TP_SIZE) {
                return ADP_TRUE;
            }

            if (!adp_putbytes(adp, (caddr_t)pBlock, iBlockLen))
                return ADP_FALSE;

            /* 需要补位时 */
            if (iplus > 0) {
                if (!adp_putbytes(adp, (caddr_t)adp_zero, iplus))
                    return ADP_FALSE;
            }
            break;

        case ADP_DECODE:
        case ADP_CHECK:     
            if (!adp_getbytes(adp, (caddr_t)pBlock, iBlockLen))
                return ADP_FALSE;
            if(adp->op == ADP_CHECK)
            {
                pcaPrintStr = malloc(iBlockLen * 2 + iBlockLen);
                if (NULL==pcaPrintStr )
                {
                    return ADP_FALSE ;
                }
                memset(pcaPrintStr, 0, iBlockLen * 2 + iBlockLen);
                for (i = 0; i < iBlockLen; i++) {
                    if(i > 0 && i % 2 == 0)
                        strcat(pcaPrintStr, " ");
                    sprintf(caTmp, "%02X", *(pBlock + i));
                    strcat(pcaPrintStr, caTmp);
                }
                printf("%s\n", pcaPrintStr);
                free(pcaPrintStr);
            }
            /* 需要补位时 */
            if (iplus > 0) {
                if (!adp_getbytes(adp, (caddr_t)adp_zero, iplus))
                {
                    return ADP_FALSE;
                }
            }
            break;

        case ADP_FREE:
            break;
    }

    return ADP_TRUE;
}

int adp_putbytes (ADP *adp, caddr_t addr, int len)
{
    if (adp->tp == ADP_TP_MEM) {
        if (adp->iBufCurLen > adp->iBufMaxLen)
            return ADP_FALSE;
        memcpy(adp->pBufCur, addr, len);
        adp->pBufCur += len;
    }
    if (adp->tp == ADP_TP_STDIO) {
        if (fwrite(addr, len, 1, (FILE *)adp->pBufCur) != 1)
            return ADP_FALSE;
    }
    return ADP_TRUE;
}

int adp_getbytes (ADP *adp, caddr_t addr, int len)
{    
    if (adp->tp == ADP_TP_MEM) {
        if (adp->iBufCurLen > adp->iBufMaxLen)
            return ADP_FALSE;
        memcpy(addr, adp->pBufCur, len);
        adp->pBufCur += len;
    }
    if (adp->tp == ADP_TP_STDIO) {
        if (fread (addr, len, 1, (FILE *)adp->pBufCur) != 1)
            return ADP_FALSE;
    }
    return ADP_TRUE;
}

/*caddr_t *addrp;             array pointer */
/*unsigned int *sizep;        number of elements */
/*unsigned int maxsize;       max numberof elements */    
/*unsigned int elsize;        size in bytes of each element */    
/*adpproc_t elproc;           adp routine to handle each element */    
//int adp_array (register ADP *adp, caddr_t *addrp, unsigned int *sizep, unsigned int maxsize, unsigned int elsize, adpproc_t elproc)
int adp_array (register ADP *adp, caddr_t *addrp, unsigned int sizep, unsigned int maxsize, unsigned int elsize, adpproc_t elproc)
{    
    char    cmd;    
    register unsigned int i;
    register caddr_t target = *addrp;
    register unsigned int c;       /* the actual element count */
    register int stat = ADP_TRUE;
    register unsigned int nodesize;

    c = sizep;
    if ((c > maxsize) && (adp->op != ADP_FREE)) {
        return (ADP_FALSE);
    }
    nodesize = c * elsize;

    /*                                                                      
     * if we are deserializing, we may need to allocate an array.           
     * We also save time by checking for a null array if we are freeing.    
     */    
    if (target == NULL)
        switch (adp->op) {
            case ADP_DECODE:
            case ADP_CHECK:     
                if (c == 0)
                    return (ADP_TRUE);
                *addrp = target = mem_alloc (nodesize);
                if (target == NULL) {
                    (void) fprintf (stderr,
                            "adp_array: out of memory\n");
                    return (ADP_FALSE);
                }
                memset (target, 0, nodesize);
                break;

            case ADP_FREE:
                return (ADP_TRUE);

            case ADP_ENCODE:
                break;
        }    
    /*                                                                      
     * now we adp each element of array                                     
     */   
    for (i = 0; (i < c) && stat; i++) {
        if(adp->op == ADP_CHECK)
        {
            scanf("%c", &cmd);
            if(cmd != 'y')
                return (ADP_FALSE);
        }
        stat = (*elproc) (adp, target);
        target += elsize;
    }

    /*                                                                      
     * the array may need freeing                                           
     */    
    if (adp->op == ADP_FREE) {
        mem_free (*addrp, nodesize);
        *addrp = NULL;
    }
    return (stat);
}

