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
* ECBuffer.h
* This file for ECBuffer interface define.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "ECType.h"

class ECBuffer
{
public:
    ECBuffer();
    ECBuffer(EC_PTR pData, EC_U32 nSize);
    virtual ~ECBuffer();
    virtual EC_VOID Clear();
    virtual EC_U32 Read(EC_PTR pBuf, EC_U32 nBufMaxSize);
    virtual EC_U32 Write(EC_PTR pData, EC_U32 nDataSize);

protected:
    EC_PTR m_pBuffer;
    EC_U32 m_nBufferSize;
};
