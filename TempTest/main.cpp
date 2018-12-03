#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "TypeDef.h"
#include <stdint.h>
#include <map>
#include <math.h>

//定义类型别名
typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned int DWORD;

//0xba
#define MAKEWORD(a, b)      ((WORD)(((BYTE)((DWORD)(a) & 0xff)) | ((WORD)((BYTE)((DWORD)(b) & 0xff))) << 8))
#define PRINTINTVALUE(value)  printf(#value"[%d]\n", value);

void sigCallFunc(int iSig)
{
	printf("Custom sigCallFunc called %d\n", iSig);
}

//void (*signal(int sig,void (*func)(int)))(int)
void (*signal(int iSig, void (*func)(int)))(int)
{
	puts("signal func called!");
	if(func != NULL)
		func(iSig);

	return func;
}

typedef struct
{
	int a;
	int b;
	int c;
	int d;
} ST_TEST;

typedef struct
{
	int a;
	int b;
	ST_TEST stTest;
	int d;
}ST_TEST1;


//int lengthOfLongestSubstring(const char* s) {
//    size_t len = strlen(s);
//    if(1 == len) return 1;
//
//    int iRus = 1;
//    unsigned int iStartPos = 0;
//    for(iStartPos=0; iStartPos<len; ++iStartPos){
//    	for(unsigned int iEndPos=iStartPos+1; iEndPos<len; ++iEndPos){
//    		for(unsigned int j=iEndPos; j>iStartPos; --j){
//    			if(s[iEndPos] == s[j]){
//    				iRus = (iEndPos-iStartPos > (unsigned int)iRus)?iEndPos-iStartPos: iRus;
//    				//                iEndPos = iStartPos = j;
//    				break;
//    			}
//    		}
//    	}
//    }
//    return  iRus;
//}

//const char * findStr(const char *pStart, const char *pEnd)
//{
//	const char *pRus = NULL;
//	for(const char *pCur=pStart; pCur!=pEnd; ++pCur){
//		if(*pCur == *pEnd){
//			pRus = pCur;
//			break;
//		}
//	}
//	return pRus;
//}
//int lengthOfLongestSubstring(const char* s) {
//	if(strlen(s) == 0)  return 0;
//	int iRus = 1;
//	for(const char *pCur = s; *pCur!='\0'; ++pCur){
//		const char *pEnd, *pRus;
//		for(pEnd = pCur+1; *pEnd!='\0'; ++pEnd){
//			pRus = findStr(pCur, pEnd);
//			if(NULL != pRus){
//				int len = pEnd-pCur;
//				if(len>iRus)	iRus=len;
//				break;
//			}
//		}
//		if(*pEnd=='\0' && pRus==NULL){
//			int len = pEnd-pCur;
//			if(len>iRus)	iRus=len;
//		}
//
//	}
//	return iRus;
//}
//
//int lengthOfLongestSubstring(const char* s) {
//	if(strlen(s) == 0)  return 0;
//	int iRus = 1;
//	const char *pCur = s;
//	while(*pCur!='\0'){
//		const char *pEnd, *pRus;
//		for(pEnd = pCur+1; *pEnd!='\0'; ++pEnd){
//			pRus = findStr(pCur, pEnd);
//			if(NULL != pRus){
//				int len = pEnd-pCur;
//				if(len>iRus)	iRus=len;
//				pCur = pRus;
//				break;
//			}
//		}
//		if(*pEnd=='\0' && pRus==NULL){
//			int len = pEnd-pCur;
//			if(len>iRus)	iRus=len;
//		}
//		++pCur;
//	}
//	return iRus;
//}
#include <set>
int lengthOfLongestSubstring(std::string s1) {
//	using namespace std;
	using std::set;
	const char *s = s1.c_str();
	set<char> charSet;
	int iRet = 0;
	int cnt = strlen(s);
	int i=0, j=0;
	while(i<cnt && j<cnt){ //[i,j]
		set<char>::iterator it = charSet.find(s[j]);
		if(it == charSet.end()){ //j右移
			charSet.insert(s[j]);
			++j;
			if(j-i>iRet) iRet = j-i; //
		}
		else{	//i右移
			charSet.erase(s[i++]);
		}
	}
	return iRet;
}
int reverse(int x) {
	int iRus = 0;
	if(x>0){
		const int max = 0x7fffffff;
		const int max1 = max/10;
		while(x != 0){
			int iTemp = x%10;
			if(iRus>max1 || (iRus==max1&&iTemp>max%10)){
				return 0;
			}
//			if(iRus>147483647 && iTemp>=2){  //2147483647
//				return 0;
//			}
			iRus = x%10 + iRus*10;
			x/=10;
		}
	}
	else{
		const int min = 0x80000000;
		const int min1 = min/10;
		while(x != 0){
			int iTemp = x%10;
			if(iRus<min1 || (iRus==min1&&iTemp<min%10)){
				return 0;
			}
//			if(iRus>147483648 && iTemp>=2){  //-2147483648
//				return 0;
//			}
			iRus = x%10 + iRus*10;
			x/=10;
		}
//		iRus = -iRus;
	}
	return iRus;
}

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }

    int arry[20] = {0};
    int arrySize = 0;
    while(x != 0){
        arry[arrySize++] = x%10;
        x /= 10;
    }

    for(int i=0; i<arrySize/2; ++i){
        if(arry[i] != arry[arrySize-i-1]){
            return false;
        }
    }

    return true;

}

int main()
{
//	int iRus = lengthOfLongestSubstring("abcbda");
//	printf("rus %d\n", iRus);

//	int iRus = reverse(-123);
//	printf("rus %d\n", iRus);

	bool iRus = isPalindrome(10010);
	printf("rus %d\n", iRus);
//	printf("rus %x\n", (-1 * pow(2, 31)));
//	std::multimap<char,int> mymm;
//
//	mymm.insert (std::make_pair('z',5));
//	mymm.insert (std::make_pair('x',10));
//	mymm.insert (std::make_pair('z',40));
//	mymm.insert (std::make_pair('y',20));
//	mymm.insert (std::make_pair('z',30));
//
//	printf("mymm content:\n");
//	std::multimap<char,int>::iterator it;
//	for(it=mymm.begin(); it!=mymm.end(); ++it){
//		printf("%c %d\n", it->first, it->second);
//	}
//
//	printf("mymm find z(using find):\n");
//	it = mymm.find('z');
//	for(unsigned int i=0; i<mymm.count('z'); i++,it++){
//		printf("%c %d\n", it->first, it->second);
//	}
//
//	using namespace std;
//	printf("mymm find z(using equal_range):\n");
//	typedef std::multimap<char,int>::iterator mapIt_t;
//	pair<mapIt_t, mapIt_t> rangePair = mymm.equal_range('z');
//	for(it=rangePair.first; it!=rangePair.second; ++it){
//		printf("%c %d\n", it->first, it->second);
//	}

//	  it = mymm.find('x');
//	  mymm.erase (it);
//	  mymm.erase (mymm.find('z'));
//
//	  // print content:
//	  std::cout << "elements in mymm:" << '\n';
//	  std::cout << "y => " << mymm.find('y')->second << '\n';
//	  std::cout << "z => " << mymm.find('z')->second << '\n';


//	ST_TEST stTest = {1, 2, 3, 4};
//	ST_TEST1 stTest1,stTest2;
//	memset(&stTest1, 0xff, sizeof(ST_TEST1));
//	printf("stTest1.a[%X], stTest1.stTest.c[%x]\n", stTest1.a, stTest1.stTest.c);
//	printf("pointer:stTest1.a[%p], stTest1.stTest[%p]\n", &stTest1.a, &stTest1.stTest);

//	stTest2 = stTest1;
//	memcpy(&stTest2, &stTest1, sizeof(ST_TEST1));
//	printf("stTest2.a[%X], stTest2.stTest.c[%x]\n", stTest2.a, stTest2.stTest.c);
//	printf("pointer:stTest2.a[%p], stTest2.stTest[%p]\n", &stTest2.a, &stTest2.stTest);
//	char szTemp[16] = {0};
//	printf("szTemp<%p>, szTemp+1<%p>\n", szTemp, szTemp+1);
//	printf("&szTemp<%p>, &szTemp+1<%p>\n", &szTemp, &szTemp+1);

//	printf("flapForwardDayMode<%p>\n", &stWorkMode.flapForwardDayMode);
//	printf("reserved1<%p>\n", &stWorkMode.reserved1);
//	printf("reserved2<%p>\n", &stWorkMode.reserved2);


//	char szTemp[20];	memset(szTemp, 0xff, sizeof(szTemp));
//	printf("szTemp <%p>\n", szTemp);
//	for(uint i=0; i<sizeof(szTemp); ++i)
//	{
//		printf("%02x ", (uint8_t)szTemp[i]);
//	}
//	putchar('\n');
//
//
//	char *pszRet = strcpy(szTemp, "haha");
//	printf("pszRet <%p>\n", pszRet);
//
//	for(uint i=0; i<sizeof(szTemp); ++i)
//	{
//		printf("%02x ", (uint8_t)szTemp[i]);
//	}
//	putchar('\n');


//	0x22, 0x74, 0x79, 0x70, 0x65, 0x22, 0x3a, 0x20, 0x22, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x22, 0x2c, 0x22, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x22, 0x3a, 0x20, 0x7b, 0x22, 0x71, 0x75, 0x65, 0x72, 0x79, 0x22, 0x3a, 0x20, 0x22, 0x77, 0x69, 0x66, 0x69, 0x22, 0x7d, 0x7d
//		char szTemp[] = {0x22, 0x74, 0x79, 0x70, 0x65, 0x22, 0x3a, 0x20, 0x22, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x22, 0x2c, 0x22, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x22, 0x3a, 0x20, 0x7b, 0x22, 0x71, 0x75, 0x65, 0x72, 0x79, 0x22, 0x3a, 0x20, 0x22, 0x77, 0x69, 0x66, 0x69, 0x22, 0x7d, 0x7d};
//	char szTemp[] = {0x7b, 0x22, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e};
//	puts(szTemp);
//	unsigned int uiCrc16 = CRC16(pDataBuf, iBufLen-2);
//	unsigned int uiCrcRx = (pDataBuf[iBufLen-1]<<8) + pDataBuf[iBufLen-2];
	//02 02 01 00 01 00 78 4E
//	unsigned char ucTemp[] = {0x02, 0x02, 0x01, 0x00, 0x01, 0x00, 0x78, 0x4e};
//	size_t iBufLen = sizeof(ucTemp);
//	unsigned int uiCrc16 = CRC16(ucTemp, iBufLen-2);
//	printf("uiCrc16 [%#X]\n", uiCrc16);
//	unsigned int uiCrcRx = (ucTemp[iBufLen-1]<<8) + ucTemp[iBufLen-2];
//	printf("uiCrcRx [%#X]\n", uiCrcRx);

//	unsigned char ucTemp[20] = {0};
//	memcpy(ucTemp, "\x30\x32\x33", 3);
//	for(int i=0; i<3; ++i)
//	{
//		printf("%#02x  ", ucTemp[i]);
//	}
//	putchar('\n');


//	HexToStringForLog(const unsigned char * szSrcData, int iSrcDataLength, char * szDesString, int iDesBufSize)

	//用宏定义实现字符串
//	int iTest = 123666;
//	PRINTINTVALUE(iTest);

	//字符串中用十六进制的ASCII码表示字符的方法
//	const char *pszTest = "\x41\x42\x43\x25";
//	puts(pszTest);
//	printf("%02X,%02X,%02X,%02X,%02X\n",pszTest[0], pszTest[1], pszTest[2], pszTest[3], pszTest[4]);
//	printf("%% is \x25\x25 \n");

//	printf("i[%03d]\n", 12);

//	printf("sizeof char *[%u]\n", sizeof(char *));
//	const char *pucArry[20];
//	printf("sizeof pucArry [%u]\n", sizeof(pucArry));

//	signal(233,sigCallFunc);

//	int a[5] = {1, 3, 5, 7, 9};
//	int *num[5] = {&a[0], &a[1], &a[2], &a[3], &a[4]};
//
//	int i, **p=num;
//	for(i=0; i<5; i++)
//		printf("%d\t", **p++);

//	ST_TPU_POLLING_CARD_INFO
//	printf("sizeof ST_TPU_POLLING_CARD_INFO[%u]\n", sizeof(ST_TPU_POLLING_CARD_INFO));

//	int a = (puts("1"),puts("2"),3 ,2);
//	printf("a= %d\n", a);


//    success = 0,			//成功
//    initFail = 2,			//设备连接初始化失败
//    commandFail = 3,		//设备命令执行失败
//    invalidParam = 4,		//设备命令参数非法
//    notInitialized = 5,		//设备尚未初始化

//	const char *pszErrCode[] = {"成功", "null", "设备连接初始化失败", "设备命令执行失败"};

//	IobCzGateErrorCode eErrCode = IobCzGateErrorCode::initFail;

//	enum class ES_COLOR esColor = ES_COLOR::red;
//	printf("ES_COLOR::red[%d]\n", static_cast<int>esColor);
//	printf("IobCzGateErrorCode::initFail[%s].\n", pszErrCode[eErrCode]);


//	enum class Color { red, green = 20, blue };
//	Color r = Color::blue;
//	switch(r)
//	{
//	    case Color::red  : std::cout << "red\n";   break;
//	    case Color::green: std::cout << "green\n"; break;
//	    case Color::blue : std::cout << "blue\n";  break;
//	}
//	// int n = r; // error: no scoped enum to int conversion
//	int n = static_cast<int>(r); // OK, n = 21
//	printf("int n = %d\n", n);





	//stTicketParam.iTicketType = MAKEWORD(stCardInfo.TicketType, stCardInfo.TicketMainType);
//	BYTE ucMainType = 0x00, ucSubType = 0x01;
//	int iRus = MAKEWORD(ucMainType, ucSubType);
//	printf("%#X\n", iRus);

//	struct {
//		char cSt1[2];
//		char cSt2[6];
//	} stTemp = {{1,2}, {3,4,5,6}};
//
//	char szTemp[20] = {0};
//
//	memcpy(szTemp, &stTemp, sizeof(stTemp));
//
//	for(unsigned char ucTemp=0; ucTemp<sizeof(stTemp); ++ucTemp)
//	{
//		printf("%d\t", szTemp[ucTemp]);
//	}
//	putchar('\n');


//	ST_HM_ABNORMAL_AND_STATUS_INFO stTemp;
//	printf("sizeof ST_HM_ABNORMAL_AND_STATUS_INFO is %u\n", sizeof(ST_HM_ABNORMAL_AND_STATUS_INFO));
//	printf("stTemp<%p>, stTemp+1<%p>\n", &stTemp, &stTemp+1);
//	printf("stTemp<%p>, (char*)stTemp+1<%p>\n", &stTemp, (char *)(&stTemp)+1);

	puts("Test end!");
	return 0;

}




