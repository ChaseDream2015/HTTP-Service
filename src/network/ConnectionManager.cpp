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
* ConnectionManager.cpp
* This file for ConnectionManager interface & encapsulation implementation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "ECLog.h"
#include "ConnectionManager.h"


ConnectionManager::ConnectionManager(EC_U32 nCapability)
:m_nCapability(nCapability)
{
    m_pConnectionHandleWorker = 
        new ECTaskWorker(m_nCapability, "ConnectionManager");
}

ConnectionManager::~ConnectionManager()
{
    if (m_pConnectionHandleWorker)
    {
        delete m_pConnectionHandleWorker;
    }
}

EC_VOID ConnectionManager::Start()
{
    m_pConnectionHandleWorker->Run();
}

EC_VOID ConnectionManager::Stop()
{
    m_pConnectionHandleWorker->Stop();
}

EC_U32 ConnectionManager::AddConnection(Connection* pConnection)
{
    return m_pConnectionHandleWorker->AddTask(
                                HandleConnectionEntry, 
                                pConnection);
}

void* ConnectionManager::HandleConnectionEntry(void* pArgv)
{
    /* Check connection security*/
    /* Create HTTP Transaction */
    /* Send HTTP Transaction to Manager*/
    Connection *pConnection = (Connection*)pArgv;
    ECSocket *pSocket = pConnection->GetTCPSocket();
    ECSocketAddress *pClientAddr = pConnection->GetClientAddress();

    EC_U32 nPort = pClientAddr->nPort;
    ECString strIPAddr = pClientAddr->strIP.ToCStr();
    EC_SOCKET nSocket = pSocket->GetSocket();

    pConnection->Close();
    delete pConnection;

    secLogI("New connection comes, [%s:%d socket_fd=%d]", strIPAddr.ToCStr(), nPort, nSocket);

    return EC_NULL;
}
