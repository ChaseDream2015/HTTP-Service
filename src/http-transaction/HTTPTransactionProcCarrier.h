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
* HTTPTransactionProcCarrier.h
* This file for HTTPTransactionProcCarrier define and encapsulation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef HTTP_TRANSACTION_PROC_CARIIER_H
#define HTTP_TRANSACTION_PROC_CARIIER_H

#include "ECMutex.h"
#include "ECThread.h"
#include "HTTPTransaction.h"

class HTTPTransactionPorcCarrier
{
public:
    HTTPTransactionPorcCarrier(EC_U32 nCapability);
    ~HTTPTransactionPorcCarrier();
    EC_U32 GetProcWaitTime();
    EC_VOID StopTransactionProc();
    EC_U32 AddHTTPTransaction(HTTPTransaction *pTransaction);

private:
    EC_VOID HandleSelectEvent();
    EC_VOID HandleTransactionEvent(HTTPTransaction *pTransaction);
    EC_VOID DeleteHTTPTransaction(HTTPTransaction *pTransaction);
    static void* HTTPTransactionProcEntry(void* pArgv);

private:
    EC_U32 m_nMaxTransCount;
    EC_U32 m_nCurrTransCount;
    ECMutex m_mtxTransaction;
    ECThread* m_pTransactionsProcThread;
    HTTPTransaction** m_pTransactionList;
};

#endif /* HTTP_TRANSACTION_PROC_CARIIER_H */
