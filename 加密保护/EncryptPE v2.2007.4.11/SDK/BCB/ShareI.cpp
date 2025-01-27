#include <stdio.h>
#include "ShareI.h"
#include <malloc.h>

HWND RegisterHandle;
char* RegisterStrings[MAX_REGISTER_INFO_NUMBER];

void GetRegisterHandle()
{
    char szFileName[3 * MAX_PATH];
    char *p = szFileName ;
    HANDLE  hMapFile = NULL;
    HMODULE  hModule = GetModuleHandle(NULL);
    RegisterHandle = NULL ;
    if(hModule == NULL)   return ;
    if(GetModuleFileName(hModule,szFileName,3 * MAX_PATH) == 0) return ;
    int nFileNameLen = strlen (szFileName);
    if(nFileNameLen == 3 * MAX_PATH) return ;
    while (*p != '\0')
    {
        if(*p == '\\')
        {
            *p = '/';
        }
        if(p - szFileName >= nFileNameLen)
        {
            break;
        }
        p++;
    }
    char szTemp[16] ;
    sprintf(szTemp,"%.8x",GetCurrentProcessId());
    strupr(szTemp);
    if(strlen(szTemp)+ strlen(szFileName) >=  3 * MAX_PATH) return ;
    else
    {
        strcat(p,"/");
        strcat(szFileName,szTemp);
    }
    hMapFile = OpenFileMapping(FILE_MAP_WRITE,false,(LPCTSTR ) szFileName);
    if(! hMapFile )  return ;
    int *  lpBaseAddress = (int *)MapViewOfFile(hMapFile,FILE_MAP_WRITE,0,0,0);
    if(lpBaseAddress != NULL)
    {
        RegisterHandle = (HWND )(*lpBaseAddress);
        UnmapViewOfFile(lpBaseAddress);
    }
    CloseHandle(hMapFile);
}


char * GetRegisterInfo(unsigned int  nInteger )
{
    char *pRet=NULL;
     if(IsWindow(RegisterHandle) == FALSE)   return pRet ;
     else{
        int i ,MessageResult;
        for (i = 1; i <= 100 ; i++)
        {
            MessageResult = :: SendMessage(RegisterHandle, WM_USER, 0, 1);
            if ((MessageResult != -1)  && (MessageResult != 0))
            {
                pRet = (char *)MessageResult;
                char *pTemp = pRet;
                int inx = 0 ;
                RegisterStrings[inx] = pTemp;
                while(*pTemp != '\0')
                {
                    if((*pTemp == (char)13))
                    {   pTemp ++;
                        if(*pTemp != (char)10)  continue;
                        *(pTemp - 1) = '\0';
                        inx ++ ;
                        if(inx >= MAX_REGISTER_INFO_NUMBER)
                          break;
                        RegisterStrings[inx] =  pTemp + 1;
                     }
                    pTemp ++;
                }
                if(nInteger >=0 && nInteger < MAX_REGISTER_INFO_NUMBER)
                {
                    pRet = RegisterStrings[nInteger];
                    return pRet;
                }
        }
    }
    }
    return pRet;
}

char * GetRegisterUser()
{
    if(IsWindow(RegisterHandle))
    {
        char *pRegInfo = GetRegisterInfo();
        if(*pRegInfo == 'Y' || *pRegInfo == 'y')
        return RegisterStrings[2];
    }
    return NULL;
}

BOOL ShowRegisterForm()
{
    int i ,nMessageResult ;
    BOOL bRet = FALSE ;
    if(::IsWindow(RegisterHandle) == FALSE)
        return bRet;
    for (i =  1 ; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle,WM_USER,0 ,0 );
        if(nMessageResult == 1)
        {
            bRet = TRUE ;
            break;
        }
    }
    return bRet;
}

BOOL KillProcess(char* pszProcessName)
{
    int i ,nMessageResult ;
    BOOL bRet = FALSE;
    if(pszProcessName == NULL || (::IsWindow(RegisterHandle) == FALSE))
    {
        return bRet;
    }
    for(i = 1 ; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle,WM_USER,88,(LPARAM)(pszProcessName));
        if(nMessageResult ==1)
        {
            bRet = TRUE ;
            break;
        }
    }
    return bRet;
}

BOOL NotKillProcess(char* pszProcessName)
{
    int i ,nMessageResult ;
    BOOL bRet = FALSE;
    if(pszProcessName == NULL || (::IsWindow(RegisterHandle) == FALSE))
    {
        return bRet;
    }
    for(i = 1 ; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle,WM_USER,89,(LPARAM)(pszProcessName));
        if(nMessageResult ==1)
        {
            bRet = TRUE ;
            break;
        }
    }
    return bRet;
}

BOOL KillDLL(char* pszDLLName)
{
    int i ,nMessageResult ;
    BOOL bRet = FALSE;
    if (::IsWindow(RegisterHandle) == false)
    {
        return bRet;
    }
    for(i = 1 ; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle,WM_USER,90,(LPARAM)(pszDLLName));
        if(nMessageResult ==1)
        {
            bRet = TRUE ;
            break;
        }
    }
    return bRet;
}

char * EPEHash(char* pszSourceString)
{
    int i ,nMessageResult ;
    char *pszReturn = NULL;
    if (::IsWindow(RegisterHandle) == false)
    {
        return pszReturn;
    }
    for(i = 1 ; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle,WM_USER,99,(LPARAM)(pszSourceString));
        if ((MessageResult != -1)  && (MessageResult != 0))
        {
            pszReturn = (char *)MessageResult;
            break;
        }
    }
    return pszReturn;
}

BOOL SetRegisterInfo(char *pszUser,char *pszInfo)
{
    TUserRecord   p ;
    int i ,nMessageResult ;
    BOOL bRet =  FALSE;
    if(::IsWindow (RegisterHandle) == FALSE || (pszUser == NULL) || (pszInfo == NULL) )
    {
        return bRet;
    }
    p.Bz = 0xff ;
    p.ValueSize = strlen(pszUser);
    if(p.ValueSize > 0)
    {
        p.ValueBuf = pszUser ;
    }
    else
    {
        p.ValueBuf = NULL;
    }
    p.PassSize = strlen(pszInfo);
    if(p.PassSize > 0)
    {
        p.PassBuf = pszInfo ;
    }
    else
    {
        p.PassBuf = NULL ;
    }
    for(i = 0 ; i <= 100 ; i ++)
    {
        nMessageResult = SendMessage(RegisterHandle, WM_USER, 100, (LPARAM)&p) ;
        if(nMessageResult == 1)
        {
            bRet = TRUE;
            break;
        }
    }
    return bRet ;
}


BOOL SetLanguage(void * pvLanguage)
{
    int   i, MessageResult;
    BOOL  bResult = FALSE;
    char *pszLanguage = (char *)pvLanguage ;
    if(pszLanguage == NULL || (IsWindow(RegisterHandle) ==FALSE ))
    {
        return bResult;
    }
  for (i = 1 ; i <= 100 ; i ++)
  {
    MessageResult = SendMessage(RegisterHandle, WM_USER, 1000, (LPARAM) pszLanguage);
    if (MessageResult == 1 )
    {
      bResult = TRUE;
      break;
    }
  }
  return bResult;
}
BOOL SetRegisterHint(void * pvPHint)
{
    int i , nMessageResult ;
    BOOL bResult = FALSE ;
    if(pvPHint == NULL ||(::IsWindow(RegisterHandle) == FALSE) )
    {
        return bResult;
    }
    for(i =  1 ; i <= 100 ; i ++)
    {
         nMessageResult = SendMessage(RegisterHandle, WM_USER, 10000, (LPARAM)(int *)(pvPHint));
         if(nMessageResult == 1)
         {
             bResult = TRUE;
             break;
         }
    }
    return bResult ;
}

 
int EPECaclResult(int nValue1,int nValue2, BYTE Index) 
{
    TUserRecord p ;
    int i , nMessageResult ;
    int  nResult = 0 ;
    if(::IsWindow(RegisterHandle) ==FALSE )
    {
        return 0;
    }
    p.Bz = (int)Index ;
    p.ValueSize = nValue1;
    p.PassSize = nValue2 ;
    for(i= 1; i <= 100 ; i ++)
    {
        nMessageResult = SendMessage(RegisterHandle, WM_USER, 5, (LPARAM)&p) ;
        if(nMessageResult == 1)
        {
            nResult = p.ValueSize;
            break;
        }
    }
    return nResult;
}
 
int EPERandom(int nValue)
{ 
    int   i , nResult = 0 ;
    if(::IsWindow(RegisterHandle) ==FALSE )
    {
        return nResult;
    }
    for (i = 1 ; i <= 100 ; i++)
    {
        nResult = ::SendMessage(RegisterHandle, WM_USER, 15, nValue);
        if (nResult != -1 )
            break;
    }
    return nResult;
}

DWORD EPECustomValue(int Index)
{
    int i ;
    DWORD dwResult = 0;
    if(Index <0 || Index > 9 ||(::IsWindow(RegisterHandle) == FALSE) )
    {
        return dwResult;
    }
    for(i = 1 ; i <= 100 ; i ++)
    {
        dwResult = (DWORD) ::SendMessage(RegisterHandle, WM_USER, 25, Index);
        if(dwResult !=(DWORD)-1)
        {
            break;
        }
        else
        {
            if(Index == 2)
                break;
        }
    }
    return dwResult;
}

BOOL EPEWindowFunction(int Index , HWND aHwnd )
{
    int i , nMessageResult;
    BOOL bResult = FALSE;
    if(Index < 0 || Index > 10 || (::IsWindow(aHwnd) == FALSE ) ||(::IsWindow(RegisterHandle) == FALSE ))
    {
        return bResult;
    }
    for( i = 1; i <= 100; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, Index * 10 + 35, (LPARAM)(int)aHwnd);
        if(nMessageResult == 1)
        {
            bResult = TRUE;
            break;
        }
    }
    return bResult;
}

char *  EPEGetMem(int nSize)
{
    int i , nMessageResult ;
    char *pszReturn = NULL;
    if(nSize <= 0 ||( ::IsWindow(RegisterHandle) == FALSE) )
    {
        return pszReturn;
    }
    for(i = 1 ; i <= 100 ; i++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 145, nSize);
        if(nMessageResult != -1 && nMessageResult != 0)
        {
            pszReturn = (char *)nMessageResult;
            break;
        }
    }
    return pszReturn;
}

BOOL EPEFreeMem(void * pBuf)
{
    int i ,nMessageResult ;
    BOOL bRet = FALSE;
    if(pBuf == NULL ||( ::IsWindow(RegisterHandle) == FALSE) )
    {
        return bRet;
    }
    for(i =  1 ; i <= 100; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 155,  (LPARAM)(int*) pBuf );
        if(nMessageResult == 1)
        {
            bRet = TRUE;
            break;
        }
    }
    return bRet ;
}

BOOL EPEZeroMemory(void * pBuf, int nSize)
{
    TUserRecord p ;
    int i , nMessageResult ;
    BOOL bRet = FALSE;
    if(pBuf == NULL || nSize <= 0 ||( ::IsWindow(RegisterHandle) == FALSE) )
    {
        return bRet;
    }
    p.Bz = 0;
    p.ValueSize = nSize;
    p.ValueBuf = pBuf;
    for(i = 1; i <=  100; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 165, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            bRet = TRUE;
            break;
        }
    }
    return bRet;
}

BOOL EPEFillMemory(void * pBuf ,int nSize , BYTE byFill)
{
    TUserRecord p;
    int i , nMessageResult ;
    BOOL bRet = FALSE;
    if(pBuf == NULL || nSize <= 0 ||( ::IsWindow(RegisterHandle) == FALSE) )
    {
        return bRet;
    }
    p.Bz = 1;
    p.ValueSize = nSize;
    p.ValueBuf  = pBuf;
    p.PassSize  = (int)byFill;
    for(i = 1 ; i <= 100; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 165, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            bRet = TRUE;
            break;
        }
    }
    return bRet;
}

BOOL EPECopyMemory(void * pvDestination, void *pvSource, int nSize)
{
    TUserRecord p;
    int i ,nMessageResult ;
    BOOL bRet = FALSE;
    if(pvDestination == NULL || pvSource == NULL || nSize <= 0 || ( ::IsWindow(RegisterHandle) == FALSE) )
    {
        return bRet;
    }
    p.Bz = 2;
    p.PassBuf = pvDestination;
    p.ValueBuf  = pvSource;
    p.ValueSize  = nSize;
    for(i = 1; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 165, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            bRet = TRUE;
            break;
        }
    }
    return bRet;
}

BOOL  EPEMoveMemory(void * pvDestination, void * pvSource , int nSize)
{
    TUserRecord p;
    int i ,nMessageResult ;
    BOOL bRet = FALSE;
    if(pvDestination == NULL || pvSource == NULL || nSize <= 0 || ( ::IsWindow(RegisterHandle) == FALSE) )
    {
        return bRet;
    }
    p.Bz  = 3;
    p.PassBuf  = pvDestination;
    p.ValueBuf  = pvSource;
    p.ValueSize  = nSize;
    for( i  = 1; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 165, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            bRet = TRUE;
            break;
        }
    }
    return bRet;
}

char * EPESystemStr(int nIndex)
{
    int i ,nMessageResult ;
    char *pszReturn = NULL;
    if(nIndex <0 || nIndex > 5 ||( ::IsWindow(RegisterHandle) == FALSE) )
    {
        return pszReturn;
    }
    for(i = 1 ; i <= 100; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 175, nIndex);
        if(nMessageResult != -1 && nMessageResult != 0)
        {
            pszReturn = (char *)nMessageResult;
            break;
        }
    }
    return pszReturn;
}


void  Compress(void *pvInBuf, int nInBytes, void* * pvOutBuf, int& nOutBytes , char *  pzPassword )
{
    TUserRecord p;
    int i ,nMessageResult ;
    *pvOutBuf  = NULL ;
    nOutBytes=0;
    if(pvInBuf == NULL || nInBytes <= 0 ||( ::IsWindow(RegisterHandle) == FALSE) )
    {
        return;
    }
    p.Bz  = 0;
    p.ValueSize  = nInBytes;
    p.ValueBuf  = pvInBuf;
    if (pzPassword != NULL)
    {
        p.PassSize = strlen(pzPassword);
        p.PassBuf  =  pzPassword;
    }
    else
    {
        p.PassSize = 0;
        p.PassBuf  = NULL;
    }
    for(i = 1; i < 100 ; i ++)
    {
        nMessageResult  = :: SendMessage(RegisterHandle, WM_USER, 0x7FFFFFFF  , (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            try
            {
                char *pTemp =  (char *) new char [p.ValueSize+1  ] ;
  	        memset(pTemp,0,p.ValueSize+1);
                *pvOutBuf = pTemp;
                memcpy(pTemp, p.ValueBuf ,  p.ValueSize);
                nOutBytes = p.ValueSize;
                break;
            }
            catch (...)
            {
                *pvOutBuf =NULL;
                nOutBytes = 0;
            }
        }
    }
}

void  Decompress(void * pvInBuf, int nInBytes, void * * pvOutBuf,
                 int &  nOutBytes, char *pzPassword , int nOutEstimate )
{
    TUserRecord p ;
    int i ,nMessageResult ;
    *pvOutBuf  = NULL ;
    nOutBytes = 0 ;
    if(pvInBuf == NULL || nInBytes <=0 || (::IsWindow(RegisterHandle) == FALSE))
    {
        return;
    }
    p.Bz = 1;
    p.ValueSize = nInBytes;
    p.ValueBuf = pvInBuf;

    if (pzPassword != NULL)
    {
        p.PassSize = strlen(pzPassword);
        p.PassBuf  =  pzPassword;
    }
    else
    {
        p.PassSize = 0;
        p.PassBuf  = NULL;
    }
    for(i = 1; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 0x7FFFFFFF, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            try
            {
                char *pTemp = (char *)new char[p.ValueSize+1 ];
 	        memset(pTemp,0,p.ValueSize+1);
                *pvOutBuf = pTemp;
                nOutBytes = p.ValueSize ;
                memcpy(pTemp,p.ValueBuf,p.ValueSize);
                break;
            }
            catch (...)
            {

                *pvOutBuf = NULL;
                nOutBytes = 0 ;
            }
        }
    }
}

char * StringCompress(char *pszSourceString ,char * pszPassword, BOOL bHFlag )
{
    TUserRecord p;
    int i ,nMessageResult ;
    char *lpszReturn = NULL;
    if(pszSourceString == NULL || (::IsWindow(RegisterHandle) == FALSE) )
    {
        return lpszReturn;
    }
    if(bHFlag)
    {
        p.Bz = 10;
    }
    else
    {
        p.Bz = 20;
    }
    
    p.ValueSize  = strlen(pszSourceString);
    p.ValueBuf  = pszSourceString;
    if(pszPassword != NULL)
    {
        p.PassSize  = strlen(pszPassword);
        p.PassBuf  = pszPassword;
    }
    else
    {
        p.PassSize = 0;
        p.PassBuf= NULL;
    }
    
    for(i =  1; i <= 100; i ++)
    {
        nMessageResult = :: SendMessage(RegisterHandle, WM_USER, 0x7FFFFFFF, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            try
            {
                lpszReturn = (char *) new char [p.ValueSize + 1];
  	        memset(lpszReturn,0,p.ValueSize+1);
                memcpy( lpszReturn, p.ValueBuf, p.ValueSize);
                break;
            }
            catch (...)
            {
            }
        }
    }
    return lpszReturn ;
}

 
char * StringDecompress(char *pszSourceString, char *pszPassword, BOOL bHFlag )
{
    TUserRecord p;
    int i ,nMessageResult ;
    char *szpReturn = NULL;
    if(pszSourceString == NULL || (::IsWindow(RegisterHandle) == FALSE))
    {
        return szpReturn;
    }
    if(bHFlag)
    {
        p.Bz = 11;
    }
    else
    {
        p. Bz = 21;
    }
    
    p.ValueSize  = strlen(pszSourceString);
    p.ValueBuf  = pszSourceString;
    if(pszPassword != NULL)
    {
        p.PassSize  = strlen(pszPassword);
        p.PassBuf  = pszPassword;
    }
    else
    {
        p.PassSize = 0;
        p.PassBuf= NULL;
    }
    for (i = 1 ;i <= 100 ; i ++)
    {
        nMessageResult = :: SendMessage(RegisterHandle, WM_USER, 0x7FFFFFFF, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            try
            {
                szpReturn = new char [p.ValueSize + 1];
  	        memset(szpReturn,0,p.ValueSize+1);
                memcpy(szpReturn,p.ValueBuf, p.ValueSize) ;
                break;
            }
            catch (...) {
            }
        }
    }
    return szpReturn ;
}


void  Encrypt(void * pvInBuf , int nInBytes,void * *pvOutBuf, int & nOutBytes,  char *pszPassword)
{
    TUserRecord p;
    int i ,nMessageResult ;
    *pvOutBuf = NULL;
    nOutBytes = 0;
    if(pvInBuf == NULL || nInBytes <= 0 || (::IsWindow(RegisterHandle) == FALSE))
    {
        return;
    }
    p.Bz  = 100;
    p.ValueSize  = nInBytes;
    p.ValueBuf  = pvInBuf;
    if(pszPassword != NULL)
    {
        p.PassSize  = strlen(pszPassword);
        p.PassBuf  =pszPassword ;
    }
    else
    {
        p.PassSize = 0;
        p.PassBuf  = NULL ;
    }
    for(i =  1; i <= 100 ; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 0x7FFFFFFF, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            try
            {
                char *pTemp = (char *)new char [p.ValueSize+1 ];
   	        memset(pTemp,0,p.ValueSize+1);
                *pvOutBuf = pTemp;
                nOutBytes = p.ValueSize ;
                memcpy(pTemp, p.ValueBuf, p.ValueSize);
                break;
            }
            catch (...) {
                *pvOutBuf = NULL;
                nOutBytes = 0;
            }
        }
    }
}


void Decrypt(void *pvInBuf,int nInBytes,void* *pvOutPointer,int& nOutBytes,char * pszPassword)
{
    TUserRecord p;
    int i ,nMessageResult;
    *pvOutPointer = NULL;
    nOutBytes = 0;
    if(pvInBuf == NULL || nInBytes <= 0 || (::IsWindow(RegisterHandle) == FALSE))
    {
        return ;
    }
    p.Bz  = 101;
    p.ValueSize = nInBytes;
    p.ValueBuf  = pvInBuf;
    if(pszPassword != NULL)
    {
        p.PassSize  = strlen(pszPassword);
        p.PassBuf  =pszPassword ;
    }
    else
    {
        p.PassSize = 0;
        p.PassBuf  = NULL ;
    }
    for ( i = 1 ;i <= 100; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 0x7FFFFFFF, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            try
            {
                char *pTemp  = (char *)new char [p.ValueSize+1 ];
        	memset(pTemp,0,p.ValueSize+1);
                *pvOutPointer = pTemp;
                nOutBytes = p.ValueSize ;
                memcpy(pTemp, p.ValueBuf, p.ValueSize);
                break;
            }
            catch (...) {
                *pvOutPointer = NULL;
                nOutBytes = 0;
            }
        }
    }
}

char * StringEncrypt(char* pszSourceString,  char *pszPassword, BOOL bHFlag )
{
    TUserRecord p;
    int i ,nMessageResult ;
    char *pszReturn = NULL;
    if(pszSourceString == NULL ||(::IsWindow(RegisterHandle) == FALSE) )
    {
        return pszReturn ;
    }
    if (bHFlag )
    {
        p.Bz  = 110;
    }
    else
    {
        p.Bz  = 120;
    }
    p.ValueSize  = strlen(pszSourceString);
    p.ValueBuf = pszSourceString;
    if(pszPassword != NULL)
    {
        p.PassSize  = strlen(pszPassword);
        p.PassBuf  =pszPassword ;
    }
    else
    {
        p.PassSize = 0;
        p.PassBuf  = NULL ;
    }
    for(i = 1 ; i <= 100; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 0x7FFFFFFF, (LPARAM)(&p));
        if(nMessageResult == 1)
        {

            try
            {
                char *pTemp = new char [p.ValueSize + 1];
        	memset(pTemp,0,p.ValueSize+1);
                pszReturn = pTemp;
                memcpy(pszReturn, p.ValueBuf, p.ValueSize);
                break;
            }
            catch (...) {
                pszReturn = NULL;
            }
            break;
        }
    }
    return pszReturn;
}
 
char * StringDecrypt(char* pszSourceString , char * pszPassword,BOOL bHFlag )
{
    TUserRecord p;
    int i ,nMessageResult ;
    char *pszReturn = NULL;
    if(pszSourceString == NULL ||(::IsWindow(RegisterHandle) == FALSE) )
    {
        return pszReturn ;
    }
    if (bHFlag )
    {
        p.Bz  = 111;
    }
    else
    {
        p.Bz  = 121;
    }
    p.ValueSize  = strlen(pszSourceString);
    p.ValueBuf = pszSourceString;
    if(pszPassword != NULL)
    {
        p.PassSize  = strlen(pszPassword);
        p.PassBuf  =pszPassword ;
    }
    else
    {
        p.PassSize = 0;
        p.PassBuf  = NULL ;
    }
    for(i = 1 ; i <= 100; i ++)
    {
        nMessageResult = ::SendMessage(RegisterHandle, WM_USER, 0x7FFFFFFF, (LPARAM)(&p));
        if(nMessageResult == 1)
        {
            
            try
            {
                pszReturn = new char [p.ValueSize + 1];
        	memset(pszReturn,0,p.ValueSize+1);
                memcpy(pszReturn, p.ValueBuf, p.ValueSize);
                break;
            }
            catch (...) {
                pszReturn = NULL;
            }
            break;
        }
    }
    return pszReturn;
}

void InitSdk()
{
    memset(RegisterStrings,0x00 ,sizeof(RegisterStrings) );
}
void UnLoadSdk()
{
    int i;
    for (i = 0 ; i < MAX_REGISTER_INFO_NUMBER ; i ++)
    {
        if(RegisterStrings[i] != NULL)
        {
            delete RegisterStrings[i];
            RegisterStrings[i] = NULL;
        }
    }
}