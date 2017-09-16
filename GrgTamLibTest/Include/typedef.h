// typedef.h
//
//////////////////////////////////////////////////////////////////////////

#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__


#if defined(DEBUG)
#define TRACE printf
#else
#define TRACE
#endif

#ifndef SUCCESS
#define SUCCESS				0	
#endif

#ifndef FAIL
#define FAIL					1
#endif		

#ifndef FALSE
#define FALSE					0	
#endif

#ifndef TRUE
#define TRUE					1
#endif		

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef min
#define min(a,b)        (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#endif

#ifndef VOID
#define VOID 						void
#endif

#ifndef CONST
#define CONST 					const
#endif

typedef unsigned long 	ULONG;
typedef ULONG 					*PULONG;
typedef unsigned short 	USHORT;
typedef USHORT 					*PUSHORT;
typedef unsigned char 	UCHAR;
typedef UCHAR 					*PUCHAR;
typedef char 						*PSZ;

typedef unsigned char   byte;

typedef unsigned long   DWORD;
typedef int             BOOL;
typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef float           FLOAT;
typedef FLOAT           *PFLOAT;
typedef BOOL 		        *PBOOL;
typedef BOOL 		        *LPBOOL;
typedef BYTE 		        *PBYTE;
typedef BYTE 		        *LPBYTE;
typedef int 			      *PINT;
typedef int 			      *LPINT;
typedef WORD 			      *PWORD;
typedef WORD 			      *LPWORD;
typedef long 			      *LPLONG;
typedef DWORD 		      *PDWORD;
typedef DWORD 		      *LPDWORD;
typedef void 			      *LPVOID;
typedef CONST void		  *LPCVOID;

typedef int             INT;
typedef unsigned int    UINT;
typedef unsigned int    *PUINT;

typedef char 						CHAR;
typedef short 					SHORT;
typedef long 						LONG;

typedef CHAR 						*PCHAR;
typedef CHAR 						*LPCH, *PCH;

typedef CONST CHAR 			*LPCCH, *PCCH;
typedef CHAR 						*NPSTR;
typedef CHAR 						*LPSTR, *PSTR;
typedef CONST CHAR 			*LPCSTR, *PCSTR;

typedef LPSTR 					LPTCH, PTCH;
typedef LPSTR 					PTSTR, LPTSTR;
typedef LPCSTR 					LPCTSTR;

typedef SHORT 					*PSHORT;  
typedef LONG 						*PLONG;    

typedef long long				LONGLONG;
typedef unsigned long long ULONGLONG;

typedef LONGLONG 				*PLONGLONG;
typedef ULONGLONG 			*PULONGLONG;

typedef ULONGLONG  			DWORDLONG;
typedef DWORDLONG 			*PDWORDLONG;

typedef char 						TCHAR, *PTCHAR;
typedef unsigned char 	TBYTE, *PTBYTE;

typedef void*						HANDLE;

typedef DWORD   				COLORREF;
typedef DWORD   				*LPCOLORREF;

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;

typedef const RECT *LPCRECT;

typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;

typedef struct tagSIZE
{
    LONG        cx;
    LONG        cy;
} SIZE, *PSIZE, *LPSIZE;

#ifndef MAKEWORD
#define MAKEWORD(a, b)  ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#endif

#ifndef MAKELONG
#define MAKELONG(a, b)  ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
#endif

#ifndef LOWORD
#define LOWORD(l)       ((WORD)(l))
#endif

#ifndef HIWORD
#define HIWORD(l)       ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#endif

#ifndef LOBYTE
#define LOBYTE(w)       ((BYTE)(w))
#endif

#ifndef HIBYTE
#define HIBYTE(w)       ((BYTE)(((WORD)(w) >> 8) & 0xFF))
#endif

#ifndef MAKELPARAM
#define MAKELPARAM(l, h)   ((LONG) MAKELONG(l, h)) 
#endif

#endif // __TYPEDEF_H__
