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
* HTTPHeaderSection.h
* This file for HTTPHeaderSection define and encapsulation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef HTTP_HEADER_SECTION_H
#define HTTP_HEADER_SECTION_H

#include "ECString.h"
#include "ECBuffer.h"
#include "HTTPDefine.h"

class HTTPHeaderSection
{
public:
    HTTPHeaderSection();
    HTTPHeaderSection(EC_PCHAR pSecBuf, EC_U32 nBufSize);
    ~HTTPHeaderSection();
    ECString GetName() const;
    ECString GetValue() const;
    EC_VOID SetName(EC_PCHAR pName);
    EC_VOID SetValue(EC_PCHAR pValue);
    ECBuffer GetSectionBuffer();

private:
    ECString m_strName;
    ECString m_strValue;
};

#endif /* HTTP_HEADER_SECTION_H */


