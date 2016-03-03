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
* HTTPRequestHeader.h
* This file for HTTPRequestHeader define and encapsulation.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef HTTP_REQUEST_HEADER_H
#define HTTP_REQUEST_HEADER_H

#include "HTTPDefine.h"

class HTTPRequestHeader
{
public:
    HTTPRequestHeader();
    ~HTTPRequestHeader();
    EC_VOID SetMethod(EC_PCHAR pMethod);
    EC_VOID SetURL(EC_PCHAR pURL);
    EC_VOID SetVersion(EC_PCHAR pVersion);
    EC_VOID AddHTTPHeaderSection(HTTP_HeaderSection* pSection);
    EC_VOID SetBodyReadStream();
};

#endif /* HTTP_REQUEST_HEADER_H */


