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
* ECDyLibraryLoader.h
* This file for dll loader define and encapsulation.
* Eamil:  epengao@126.com
* Author: Gao Peng
* --------------------------------------------------------------------
*/

#ifndef EC_DY_LIBRARY_LOADER_H
#define EC_DY_LIBRARY_LOADER_H

#include "ECType.h"
#include "ECDyLibLoader.h"

class ECDyLibraryLoader
{
public:
    static EC_HANDLE   LoadDyLib(EC_PCHAR pLibPath);
    static EC_VOID     FreeDyLib(EC_HANDLE pLibHandle);
    static EC_FUNENTRY GetDyLibFunAddress(EC_HANDLE hLibHandle, EC_PCHAR pFunName);

private:
    ECDyLibraryLoader();
};

#endif /* EC_DY_LIBRARY_LOADER_H */
