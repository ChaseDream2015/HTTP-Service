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
* ECBuffer.cpp
* This file for ECBuffer class implement.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* ------------------------------------------------------------------------
*/

#include "ECMemOP.h"
#include "ECBuffer.h"

ECBuffer::ECBuffer()
:m_nBufferSize(0)
,m_pBuffer(EC_NULL)
{
}

ECBuffer::ECBuffer(EC_VOIDP pData, EC_U32 nSize)
{
    m_nBufferSize = nSize;
    m_pBuffer = ecMemAlloc(nSize);
    ecMemCopy(m_pBuffer, pData, nSize);
}

ECBuffer::~ECBuffer()
{
    if (m_pBuffer) delete m_pBuffer;
}

EC_VOID ECBuffer::Clear()
{
    if (m_pBuffer)
    {
        delete m_pBuffer;
    }
    m_nBufferSize = 0;
    m_pBuffer = EC_NULL;
}

EC_U32 ECBuffer::Read(EC_PTR pBuf, EC_U32 nBufMaxSize)
{
    EC_U32 nRet = 0;
    if (pBuf && m_pBuffer)
    {
        if (m_nBufferSize > nBufMaxSize)
        {
            nRet = nBufMaxSize;
            ecMemCopy(pBuf, m_pBuffer, nBufMaxSize);
        }
        else
        {
            nRet = m_nBufferSize;
            ecMemCopy(pBuf, m_pBuffer, m_nBufferSize);
        }

    }
    return nRet;
}

EC_U32 ECBuffer::Write(EC_PTR pData, EC_U32 nDataSize)
{
}