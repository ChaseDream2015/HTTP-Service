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
* HTTPDefine.h
* This file for HTTP headers and structs define.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef HTTP_DEFINE_H
#define HTTP_DEFINE_H

#include "ECType.h"

/* HTTP Methods */
#define HTTP_GET      "GET"
#define HTTP_PUT      "PUT"
#define HTTP_POST     "POST"
#define HTTP_HEAD     "HEAD"
#define HTTP_TRACE    "TARCE"
#define HTTP_DELETE   "DELETE"
#define HTTP_OPTIONS  "OPTIONS"

/* HTTP Version */
#define HTTP_V_1_0    "HTTP/1.0"
#define HTTP_V_1_1    "HTTP/1.1"

/* HTTP Line Segment */
#define HTTP_Segment    "\r\n"

/* HTTP Blank Line */
#define HTTP_BlankLine  "\n"

/* HTTP Status */
enum
{
    HTTP_Status_100,
    HTTP_Status_101,
    HTTP_Status_200,
    HTTP_Status_201,
    HTTP_Status_202,
    HTTP_Status_203,
    HTTP_Status_204,
    HTTP_Status_205,
    HTTP_Status_206,
    HTTP_Status_300,
    HTTP_Status_301,
    HTTP_Status_302,
    HTTP_Status_303,
    HTTP_Status_304,
    HTTP_Status_305,
    HTTP_Status_306,
    HTTP_Status_307,
    HTTP_Status_400,
    HTTP_Status_401,
    HTTP_Status_402,
    HTTP_Status_403,
    HTTP_Status_404,
    HTTP_Status_405,
    HTTP_Status_406,
    HTTP_Status_407,
    HTTP_Status_408,
    HTTP_Status_409,
    HTTP_Status_410,
    HTTP_Status_411,
    HTTP_Status_412,
    HTTP_Status_413,
    HTTP_Status_414,
    HTTP_Status_415,
    HTTP_Status_416,
    HTTP_Status_417,
    HTTP_Status_500,
    HTTP_Status_501,
    HTTP_Status_502,
    HTTP_Status_503,
    HTTP_Status_504,
    HTTP_Status_505,
};

EC_PCHAR HTTP_Status[] =
{
    "100 Continue",
    "101 Switching Protocols",
    "200 OK",
    "201 Created",
    "202 Accepted",
    "203 Non-authoritative Information",
    "204 No Content",
    "205 Reset Content",
    "206 Partial Content",
    "300 Multiple Choices",
    "301 Moved Permanently",
    "302 Found",
    "303 See Other",
    "304 Not Modified",
    "305 Use Proxy",
    "306 Unused",
    "307 Temporary Redirect",
    "400 Bad Request",
    "401 Unauthorized",
    "402 Payment Required",
    "403 Forbidden",
    "404 Not Found",
    "405 Method Not Allowed",
    "406 Not Acceptable",
    "407 Proxy Authentication Required",
    "408 Request Timeout",
    "409 Conflict",
    "410 Gone",
    "411 Length Required",
    "412 Precondition Failed",
    "413 Request Entity Too Large",
    "414 Request-url Too Long",
    "415 Unsupported Media Type",
    "416 Requested Range Not Satisfiable",
    "417 Expectation Failed",
    "500 Internal Server Error",
    "501 Not Implemented",
    "502 Bad Gateway",
    "503 Service Unavailable",
    "504 Gateway Timeout",
    "505 HTTP Version Not Supported",
};

typedef struct
{
    EC_PCHAR pName;
    EC_PCHAR pValue;
} HTTP_HeaderSection;

#endif /* HTTP_DEFINE_H */



