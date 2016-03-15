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
* ECFDSet.cpp
* This file for ECFDSet class implementation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "ECError.h"
#include "ECFDSet.h"


ECFDSet::ECFDSet()
:m_nMaxFD(-1)
{
    FD_ZERO(&m_FDSet);
}

ECFDSet::~ECFDSet()
{
}

EC_VOID ECFDSet::Zero()
{
    m_nMaxFD = -1;
    FD_ZERO(&m_FDSet);
}

EC_VOID ECFDSet::SetFD(EC_INT nFD)
{
    FD_SET(nFD, &m_FDSet);
    if (nFD > m_nMaxFD) m_nMaxFD = nFD;
}

EC_VOID ECFDSet::ClearFD(EC_INT nFD)
{
    FD_CLR(nFD, &m_FDSet);
}

EC_BOOL ECFDSet::IsSetFD(EC_INT nFD)
{
    return FD_ISSET(nFD, &m_FDSet);
}

/* Friend method of class ECFDSet */
EC_INT ecSelect(ECFDSet* pAllFDs, EC_U32 nTimeOut)
{
    EC_INT ret = EC_Err_None;
    if (pAllFDs == EC_NULL)
    {
        ret = EC_Err_BadParam;
    }
    else
    {
        struct timeval timeout;
        timeout.tv_usec = 0;
        timeout.tv_sec = nTimeOut;

        ret = select(pAllFDs->m_nMaxFD + 1, &(pAllFDs->m_FDSet), EC_NULL, EC_NULL, &timeout);
    }
    return ret;
}
