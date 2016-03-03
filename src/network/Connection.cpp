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
* Connection.cpp
* This file for Connection interface & encapsulation implementation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "Connection.h"


Connection::Connection(ECTCPSocket *pSocket,
                       ECSocketAddress *pClientAddr)
{
    m_pClientAddr = new ECSocketAddress();
    m_pClientAddr->nPort = pClientAddr->nPort;
    m_pClientAddr->strIP = pClientAddr->strIP;
    m_pSocket = new ECTCPSocket(pSocket->GetSocket());
}

Connection::~Connection()
{
    if (m_pSocket) delete m_pSocket;
    if (m_pClientAddr) delete m_pClientAddr;
}

EC_VOID Connection::Close()
{
    if (m_pSocket) m_pSocket->Close();
}

EC_BOOL Connection::CheckSecurity()
{
    return EC_TRUE;
}

ECTCPSocket* Connection::GetTCPSocket() const
{
    return m_pSocket;
}

ECSocketAddress* Connection::GetClientAddress() const
{
    return m_pClientAddr;
}
