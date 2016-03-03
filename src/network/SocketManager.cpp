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
* SocketManager.cpp
* This file for SocketManager interface & encapsulation implementation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "ECLog.h"
#include "ECError.h"
#include "ECOSUtil.h"
#include "Connection.h"
#include "SocketManager.h"

#define LISTEN_IP   "0.0.0.0"
#define LISTEN_PORT      8259
#define MAX_CON_NUBMBER  4096
#define MAX_WAIT_CON_TIME  10


SocketManager::SocketManager()
:m_isRunning(EC_FALSE)
,m_pListenSocket(EC_NULL)
{
    m_pConnectionManager = new ConnectionManager(MAX_CON_NUBMBER);
    m_pSocketManagerThread = new ECThread(SocketManagerProc, this, "SocketManager");
}

SocketManager::~SocketManager()
{
    if (m_pSocketManagerThread)
    {
        if (m_isRunning)
        {
            Stop();
            if (m_pConnectionManager)
                m_pConnectionManager->Stop();
        }
        delete m_pSocketManagerThread;
    }
    if (m_pListenSocket) delete m_pListenSocket;
    if (m_pConnectionManager) delete m_pConnectionManager;
}

EC_VOID SocketManager::Start()
{
    m_isRunning = EC_TRUE;

    ECSocketAddress address;
    address.strIP = LISTEN_IP;
    address.nPort = LISTEN_PORT;
    m_pListenSocket = new ECTCPSocket();
    m_pListenSocket->BindAddress(&address);
    m_pListenSocket->Listen(MAX_CON_NUBMBER);

    m_pConnectionManager->Start();
    m_pSocketManagerThread->Start();
}

EC_VOID SocketManager::Stop()
{
    m_isRunning = EC_FALSE;
    m_pListenSocket->Close();
    m_pSocketManagerThread->WaitStop();
    m_pConnectionManager->Stop();
}

void* SocketManager::SocketManagerProc(void* pArgv)
{
    SocketManager *pSktMgr = (SocketManager*)pArgv;
    ConnectionManager *pConnMgr = pSktMgr->m_pConnectionManager;

    while (EC_TRUE)
    {
        fd_set fdSet;
        struct timeval timeout;
        timeout.tv_usec = 0;
        timeout.tv_sec = MAX_WAIT_CON_TIME;

        if (pSktMgr->m_isRunning)
        {
            ECSocketAddress clientAddress;
            ECTCPSocket *pListenSocket = pSktMgr->m_pListenSocket;

            FD_ZERO(&fdSet);
            FD_CLR(pListenSocket->GetSocket(), &fdSet);
            FD_SET(pListenSocket->GetSocket(), &fdSet);
            int nMaxFd = pListenSocket->GetSocket() + 1;
            
            int nRet = select(nMaxFd, &fdSet, EC_NULL, EC_NULL, &timeout);
            if (nRet > 0)
            {
                ECTCPSocket socket = pListenSocket->Accept(&clientAddress);
                if (socket.GetSocket() > 0)
                {
                    secLogI("New client comes, Create new Connection");
                    Connection* pConnection = new Connection(&socket, &clientAddress);
                    nRet = pConnMgr->AddConnection(pConnection);
                    if (nRet != 0)
                    {
                        secLogI("ConnectionManager is full, drop this connection.");
                        pConnection->Close();
                        delete pConnection;
                    }
                }
            }
            else if (nRet == 0)
            {
                secLogI("No connection comes, continue listening...");
            }
            else
            {
                secLogE("SocketManager Select error... Thread Exit!!!");
                return EC_NULL;
            }
        }
        else
        {
            return EC_NULL;
        }
    }
    return EC_NULL;
}
