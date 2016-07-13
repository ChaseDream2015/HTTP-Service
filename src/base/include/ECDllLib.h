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
* ECDllLib.h
* Eamil:  epengao@126.com
* Author: Gao Peng
* Version: First initinal version.
* --------------------------------------------------------------------
*/

#ifndef EC_DLL_LIB_H
#define EC_DLL_LIB_H

#include "ECPrefDef.h"

#ifdef EC_OS_Win32
#include <windows.h>
#elif defined EC_OS_Linux
/* TODO */
#elif defined EC_OS_MacOS
/* TODO */
#elif defined EC_OS_iOS
/* TODO */
#elif defined EC_OS_Android
/* TODO */
#endif


#ifdef __cplusplus
#define EC_EXPORT extern "C" __declspec (dllexport)
#else
#define EC_EXPORT            __declspec (dllexport)
#endif


#ifdef EC_OS_Win32
#define  EC_ExAPI    WINAPI
#elif defined EC_OS_Linux
#define  EC_ExAPI
#elif defined EC_OS_MacOS
#define  EC_ExAPI
#elif defined EC_OS_iOS
#define  EC_ExAPI
#elif defined EC_OS_Android
#define  EC_ExAPI
#endif

#endif /* EC_DLL_LIB_H */