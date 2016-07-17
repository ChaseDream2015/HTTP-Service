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
* ECDyLibraryLoader.cpp
* This file for dynamic library loader implementation
* Eamil:  epengao@126.com
* Author: Gao Peng
* --------------------------------------------------------------------
*/

#include "ECDyLibraryLoader.h"

EC_HANDLE ECDyLibraryLoader::LoadDyLib(EC_PCHAR pLibPath)
{
    return ecLoadDyLib(pLibPath);
}

void ECDyLibraryLoader::FreeDylib(EC_HANDLE pLibHandle)
{
    ecFreeDyLib(pLibHandle);
}

EC_FUNENTRY ECDyLibraryLoader::GetDyLibFunAddress(EC_HANDLE hLibHandle, EC_PCHAR pFunName)
{
    return ecGetDyLibFuncAddress(hLibHandle, pFunName);
}

