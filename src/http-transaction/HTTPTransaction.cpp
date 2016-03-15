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
* HTTPTransaction.cpp
* This file for HTTPTransaction interface & encapsulation implementation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "HTTPTransaction.h"


HTTPTransaction::HTTPTransaction(Connection *pConnection)
:m_pConnection(pConnection)
{
}

HTTPTransaction::~HTTPTransaction()
{
    if (m_pConnection)
    {
        delete m_pConnection;
    }
}

EC_VOID HTTPTransaction::Close()
{
    m_pConnection->Close();
}

EC_BOOL HTTPTransaction::IsFinished()
{
    return EC_FALSE;
}

EC_SOCKET HTTPTransaction::GetSocketFD()
{
    EC_SOCKET nRetSocket = -1;
    ECSocket *pSocket = EC_NULL;
    if (m_pConnection)
    {
        pSocket = m_pConnection->GetTCPSocket();
        if (pSocket)
            nRetSocket = pSocket->GetSocket();
    }
    return nRetSocket;
}

EC_VOID HTTPTransaction::ReceivedData(EC_PTR pData, EC_U32 nSize)
{
    /* TODO: Parser HTTP Header */
}
