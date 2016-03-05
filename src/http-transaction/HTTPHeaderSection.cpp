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
* HTTPHeaderSection.cpp
* This file for HTTPHeaderSection interface & encapsulation implementation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "ECMemOP.h"
#include "ECStringOP.h"
#include "HTTPHeaderSection.h"


HTTPHeaderSection::HTTPHeaderSection(EC_PCHAR pSecBuf, EC_U32 nBufSize)
:m_strName(EC_NULL)
,m_strValue(EC_NULL)
{
    if (pSecBuf && nBufSize)
    {
        EC_INT nColonPos = ecFindByteFromMem(':', pSecBuf, nBufSize);
        EC_INT nSegmentPos = ecFindMemFromMem(HTTP_Segment, 2, pSecBuf, nBufSize);
        if ((nColonPos > 0) &&
            (nSegmentPos > 0) &&
            (nSegmentPos > nColonPos))
        {
            m_strName = ECString(pSecBuf, nColonPos);
            m_strValue = ECString(pSecBuf + nColonPos + 1, nSegmentPos - (nColonPos + 1));
        }
    }
}

HTTPHeaderSection::~HTTPHeaderSection()
{
}

ECString HTTPHeaderSection::GetName() const
{
    return m_strName;
}

ECString HTTPHeaderSection::GetValue() const
{
    return m_strValue;
}

EC_VOID HTTPHeaderSection::SetName(EC_PCHAR pName)
{
    m_strName = pName;
}

EC_VOID HTTPHeaderSection::SetValue(EC_PCHAR pValue)
{
    m_strValue = pValue;
}

ECBuffer HTTPHeaderSection::GetSectionBuffer()
{
    ECBuffer RetBuf;
    EC_U32 nBufSize = 0;
    EC_PTR pBuf = EC_NULL;
    EC_U32 nNameLen = m_strName.Length() + 1;
    EC_U32 nValueLen = m_strValue.Length() + 1;

    if ((nNameLen > 0) && (nValueLen > 0))
    {
        EC_U32 nSegLen = 2;
        nBufSize = nNameLen + 1 + nValueLen + nSegLen;

        pBuf = ecMemAlloc(nBufSize);
        ecMemCopy(pBuf, m_strName.ToCStr(), nNameLen);
        ecMemCopy((EC_PCHAR)pBuf + nNameLen, ":", 1);
        ecMemCopy((EC_PCHAR)pBuf + nNameLen + 1, m_strValue.ToCStr(), nValueLen);
        ecMemCopy((EC_PCHAR)pBuf + nNameLen + nValueLen + 1, HTTP_Segment, nSegLen);

        RetBuf.ReSetBuffer(pBuf, nBufSize);
    }

    return RetBuf;
}
