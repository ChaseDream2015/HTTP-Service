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

typedef struct
{
    Connection *pConnection;
    HTTPTransactionManager *pTransMgr;
} HandleConnectionParam;

ConnectionManager::ConnectionManager(HTTPTransactionManager* pTransactionMgr, EC_U32 nCapability)
:m_nCapability(nCapability)
{
    m_pConnectionHandleWorker = 
      new ECTaskWorker(m_nCapability, "ConnectionManager");
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
    HandleConnectionParam *pParam = new HandleConnectionParam;
    pParam->pConnection = pConnection;
    pParam->pTransMgr = m_pTransactionMgr;
    return m_pConnectionHandleWorker->AddTask(HandleConnectionEntry, pParam);
}

void* ConnectionManager::HandleConnectionEntry(void* pArgv)
{
    HandleConnectionParam *pParam = (HandleConnectionParam*)pArgv;

    Connection *pConnection = pParam->pConnection;
    HTTPTransactionManager *pTransMgr = pParam->pTransMgr;

    ECSocket *pSocket = pConnection->GetTCPSocket();
    ECSocketAddress *pClientAddr = pConnection->GetClientAddress();
    EC_U32 nPort = pClientAddr->nPort;
    ECString strIPAddr = pClientAddr->strIP.ToCStr();

    if (pConnection->CheckSecurity())
    {
        EC_SOCKET nSocketFD = pSocket->GetSocket();
        HTTPTransaction *pTransaction = new HTTPTransaction(pConnection);
        EC_U32 nRet = pTransMgr->AddTransaction(pTransaction);
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

    delete pParam;
    return EC_NULL;
}
