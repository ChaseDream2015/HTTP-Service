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
* HTTPTransactionPorcCarrier.cpp
* This file for HTTPTransactionPorcCarrier interface & encapsulation implementation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "ECError.h"
#include "ECAutoLock.h"
#include "HTTPTransactionProcCarrier.h"


HTTPTransactionPorcCarrier::HTTPTransactionPorcCarrier(EC_U32 nCapability)
:m_nCurrTransCount(0)
,m_nMaxTransCount(nCapability)
,m_pTransactionList(EC_NULL)
,m_pTransactionsProcThread(EC_NULL)
{
    if (nCapability > 0)
    {
        m_pTransactionList = new HTTPTransaction*[nCapability];
        m_pTransactionsProcThread = new ECThread(HTTPTransactionProcEntry,
                                                 this, "HTTPTransactionProcCarrier");
    }
}

HTTPTransactionPorcCarrier::~HTTPTransactionPorcCarrier()
{
    StopTransactionProc();
    if (m_pTransactionList)
    {
        delete[] m_pTransactionList;
    }
    if (m_pTransactionsProcThread)
    {
        delete m_pTransactionsProcThread;
    }
}

EC_U32 HTTPTransactionPorcCarrier::GetProcWaitTime()
{
    return -1;
}

EC_VOID HTTPTransactionPorcCarrier::StopTransactionProc()
{
    m_pTransactionsProcThread->WaitStop();
    ECAutoLock autoLock(&m_mtxTransaction);
    {
        for (EC_U32 i = 0; i < m_nCurrTransCount; i++)
        {
            m_pTransactionList[i]->Close();
            delete m_pTransactionList[i];
        }
    }
}

EC_U32 HTTPTransactionPorcCarrier::AddHTTPTransaction(HTTPTransaction *pTransaction)
{
    EC_U32 nRet = EC_Err_None;
    if (pTransaction == EC_NULL)
    {
        nRet = EC_Err_BadParam;
    }
    else
    {
        ECAutoLock autoLock(&m_mtxTransaction);
        {
            if (m_nCurrTransCount >= m_nMaxTransCount)
                nRet = EC_Err_ContainerFull;
            else
            {
                m_pTransactionList[m_nCurrTransCount] = pTransaction;
                m_nCurrTransCount++;
            }
        }
    }
    return nRet;
}

/* Private Methods */
EC_VOID HTTPTransactionPorcCarrier::HandleSelectEvent()
{
}

EC_VOID HTTPTransactionPorcCarrier::HandleTransactionEvent(HTTPTransaction *pTransaction)
{
}

EC_VOID HTTPTransactionPorcCarrier::DeleteHTTPTransaction(HTTPTransaction *pTransaction)
{
}

void* HTTPTransactionPorcCarrier::HTTPTransactionProcEntry(void* pArgv)
{

}
