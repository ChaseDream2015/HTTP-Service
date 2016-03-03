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
* ConnectionManager.h
* This file for ConnectionManager define and encapsulation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include "ECType.h"
#include "ECSocket.h"
#include "Connection.h"
#include "ECTaskWorker.h"

class ConnectionManager
{
public:
    ConnectionManager(EC_U32 nCapability = EC_U16_MAX);
    ~ConnectionManager();
    EC_VOID Start();
    EC_VOID Stop();
    EC_U32 AddConnection(Connection* pConnection);

private:
    static void* HandleConnectionEntry(void* pArgv);

private:
    EC_U32 m_nCapability;
    ECTaskWorker* m_pConnectionHandleWorker;
};

#endif /* CONNECTION_MANAGER_H */


