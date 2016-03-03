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
* SocketManager.h
* This file for SocketManager define and encapsulation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef SOCKET_MANAGER_H
#define SOCKET_MANAGER_H

#define  WIN32_LEAN_AND_MEAN

#include "ECThread.h"
#include "Connection.h"
#include "ECTCPSocket.h"
#include "ConnectionManager.h"


class SocketManager
{
public:
    SocketManager();
    ~SocketManager();
    EC_VOID Start();
    EC_VOID Stop();

private:
    static void* SocketManagerProc(void* pArgv);

private:
    EC_BOOL m_isRunning;
    ECTCPSocket *m_pListenSocket;
    ECThread *m_pSocketManagerThread;
    ConnectionManager *m_pConnectionManager;
};

#endif /* SOCKET_MANAGER_H */


