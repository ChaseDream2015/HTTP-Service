/*
* This software is developed for study and improve coding skill ...
*
* Project:  Enjoyable Coding< EC >
* Copyright (C) Gao Peng, 2015

* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Library General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.

* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Library General Public License for more details.

* You should have received a copy of the GNU Library General Public
* License along with this library; if not, write to the Free
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

* ---------------------------------------------------------------------
* ECDyLibLoader.cpp
*
* This file for dynamic library load APIs implementation
* Eamil:  epengao@126.com
* Author: Gao Peng
* --------------------------------------------------------------------
*/

#include "ECDyLibLoader.h"


EC_HANDLE ecLoadDyLib(EC_PCHAR pDyLibPath)
{
    EC_HANDLE pRet = EC_NULL;
#ifdef EC_OS_Win32
    EC_WCHAR pWDyLibPath[1024];
    EC_U32 nPathSize = strlen(pDyLibPath) + 1;
    memset(pWDyLibPath, 0, 1024);
    MultiByteToWideChar(CP_ACP, 0, pDyLibPath, nPathSize, pWDyLibPath, 1024);
    pRet = LoadLibrary(pWDyLibPath);
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    /* TODO */
#elif defined EC_OS_Android
    /* TODO */
#endif
    return pRet;
}

EC_VOID ecFreeDyLib(EC_HANDLE pDyLibHandle)
{
    if(EC_NULL == pDyLibHandle)
        return;
#ifdef EC_OS_Win32
    FreeLibrary((HMODULE)pDyLibHandle);
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    /* TODO */
#elif defined EC_OS_Android
    /* TODO */
#endif
}

EC_FUNENTRY ecGetDyLibFunAddress(EC_HANDLE hDyLibHandle, EC_PCHAR pFunName)
{
    EC_HANDLE pRet = EC_NULL;

    if (EC_NULL == hDyLibHandle) return pRet;
#ifdef EC_OS_Win32
    pRet = (EC_FUNENTRY)GetProcAddress((HMODULE)hDyLibHandle, (LPCSTR)pFunName);
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    /* TODO */
#elif defined EC_OS_Android
    /* TODO */
#endif
    return pRet;
}
