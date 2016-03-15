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
#include "HTTPTransaction.h"
#include "ConnectionManager.h"


ConnectionManager::ConnectionManager(HTTPTransactionManager* pTransactionMgr, EC_U32 nCapability)
:m_nCapability(nCapability)
{
    m_pConnectionHandleWorker = 
      new ECTaskWorker(EC_U16_MAX, "ConnectionManager");
    ConnectionManager::m_pTransactionMgr = pTransactionMgr;
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
    return m_pConnectionHandleWorker->AddTask(this, HandleConnectionEntry, pConnection);
}

EC_BOOL ConnectionManager::CheckConnectionSecurity(Connection *pConnection)
{
    return EC_TRUE;
}

void* ConnectionManager::HandleConnectionEntry(void* pUserData, void* pArgv)
{
    Connection *pConnection = (Connection*)pArgv;
    ConnectionManager *pConnMgr = (ConnectionManager*)pUserData;

    /* Debug information output */
    ECSocket *pSocket = pConnection->GetTCPSocket();
    ECSocketAddress *pClientAddr = pConnection->GetClientAddress();
    EC_U32 nPort = pClientAddr->nPort;
    ECString strIPAddr = pClientAddr->strIP.ToCStr();

    if (pConnMgr->CheckConnectionSecurity(pConnection))
    {
        EC_SOCKET nSocketFD = pSocket->GetSocket();
        HTTPTransaction *pTransaction = new HTTPTransaction(pConnection);
        EC_U32 nRet = pConnMgr->m_pTransactionMgr->AddTransaction(pTransaction);
        if (nRet != EC_Err_None)
        {
            pTransaction->Close();
            delete pTransaction;
            secLogI("New connection [%s:%d socket_fd=%d] comes, but TransactionMgr is full, drop it!!!", 
                                     strIPAddr.ToCStr(), nPort, nSocketFD);
        }
        else
        {
            secLogI("New connection [%s:%d socket_fd=%d] comes...", strIPAddr.ToCStr(), nPort, nSocketFD);
        }
    }
    else
    {
        pConnection->Close();
        delete pConnection;
        secLogE("Dangers connection[%s:%d] comes, reject it!!!", strIPAddr.ToCStr(), nPort);
    }

    return EC_NULL;
}
