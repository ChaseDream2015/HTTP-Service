/*
* This software is developed for study and improve coding skill ...
*
* Project:  Enjoyable Coding< EC >
* Copyright (C) 2014-2016 Gao Peng

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
* ECSFSet.h
* This file for ECSFSet class define and encapsulation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef EC_FD_SET_H
#define EC_FD_SET_H

#include "ECType.h"
#include "ECSocket.h"

#ifdef EC_OS_Win32
#include <Winsock2.h>
typedef SOCKET EC_SOCKET;
#elif defined EC_OS_Linux
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
typedef int EC_SOCKET;
#elif defined EC_OS_MacOS
/* TODO */
#elif defined EC_OS_iOS
/* TODO */
#elif defined EC_OS_Android
/* TODO */
#endif

class ECFDSet
{
public:
    ECFDSet();
    ~ECFDSet();
    EC_VOID Zero();
    EC_VOID SetFD(EC_INT nFD);
    EC_VOID ClearFD(EC_INT nFD);
    EC_BOOL IsSetFD(EC_INT nFD);
    friend EC_INT ecSelect(ECFDSet* pAllFDs, EC_U32 nTimeOut);

private:
    fd_set m_FDSet;
    EC_INT m_nMaxFD;
};

#endif /* EC_FD_SET_H */
