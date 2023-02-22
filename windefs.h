#ifndef _WINDEFS_
#define _WINDEFS_

typedef unsigned long   DWORD;
typedef int             BOOL;
typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef float    		    FLOAT;
typedef FLOAT   		    *PFLOAT;
typedef BOOL 	 		      *PBOOL;
typedef BOOL  			    *LPBOOL;
typedef BYTE  			    *PBYTE;
typedef BYTE   			    *LPBYTE;
typedef int  			      *PINT;
typedef int  			      *LPINT;
typedef WORD   			    *PWORD;
typedef WORD   			    *LPWORD;
typedef long  			    *LPLONG;
typedef DWORD  			    *PDWORD;
typedef DWORD  			    *LPDWORD;
typedef const char  	  *LPCSTR;
typedef void   			    *LPVOID;
typedef const void  	  *LPCVOID;
typedef void  			    *HANDLE;

#define GENERIC_READ   			  NULL
#define FILE_SHARE_READ  		  NULL
#define OPEN_EXISTING  			  NULL
#define FILE_ATTRIBUTE  		  NULL
#define INVALID_HANDLE_VALUE 	NULL
#define PAGE_READONLY 			  NULL
#define FILE_MAP_READ  			  NULL

#define CreateFileA(a, b, c, d, e, f, g) 		  (NULL)
#define CreateFileMappingA(a, b, c, d, e, f) 	(NULL)
#define MapViewOfFile(a, b, c, d, e) 			    (NULL)
#define CloseHandle(a) 							          (NULL)

#endif
