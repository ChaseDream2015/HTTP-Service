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
* ECType.h
* This file for redefing all the C++ basic types.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef EC_TYPE_H
#define EC_TYPE_H

#include "ECBaseType.h"

#ifdef __cplusplus
extern "C" {
#endif

/* signed type */
typedef _EC_CHAR               EC_CHAR;
typedef _EC_SHORT              EC_SHORT;
typedef _EC_LONG               EC_LONG;
typedef _EC_S32                EC_S32;
typedef _EC_INT                EC_INT;
typedef _EC_S64                EC_S64;
typedef _EC_FLOAT              EC_FLOAT;
typedef _EC_DOUBLE             EC_DOUBLE;
typedef _EC_LONG_DOUBLE        EC_LDOUBLE;
typedef _EC_WCHAR              EC_WCHAR;
typedef _EC_CONST_CHAR         EC_CONST_CHAR;

/* unsigned domain */ 
typedef _EC_U8                 EC_U8;
typedef _EC_U16                EC_U16;
typedef _EC_U32                EC_U32;
typedef _EC_U64                EC_U64;

/* bool */
typedef _EC_BOOL               EC_BOOL;

#ifdef __cplusplus
#define EC_FALSE               false
#define EC_TRUE                true
#else
#define EC_FALSE               _EC_FALSE
#define EC_TRUE                (!EC_FALSE)
#endif

/* void */
#define EC_VOID            void

/* pointer */
typedef _EC_POINTER       EC_VOIDP;
typedef _EC_POINTER       EC_PTR;
typedef _EC_POINTER       EC_POINTER;
typedef EC_POINTER        EC_HANDLE;
typedef EC_POINTER        EC_FUNENTRY;
typedef EC_CHAR*          EC_PCHAR;
typedef EC_SHORT*         EC_PSHORT;
typedef EC_INT*           EC_PINT;
typedef EC_S32*           EC_PS32;
typedef EC_LONG*          EC_PLONG;
typedef EC_S64*           EC_PS64;
typedef EC_FLOAT*         EC_PFLOAT;
typedef EC_DOUBLE*        EC_PDOUBLE;
typedef EC_LDOUBLE*       EC_P_LDOUBLE;
typedef EC_U8*            EC_PU8;
typedef EC_U16*           EC_PU16;
typedef EC_U32*           EC_PU32;
typedef EC_U64*           EC_PU64;
typedef EC_BOOL*          EC_PBOOL;
typedef EC_WCHAR*         EC_PWCHAR;
typedef EC_CHAR*          EC_BUFFER;
typedef EC_CONST_CHAR*    EC_CONST_PCHAR;
#define EC_NULL           _EC_NULL

/* max define */
#define EC_U8_MAX         _EC_U8_MAX
#define EC_U16_MAX        _EC_U16_MAX
#define EC_U32_MAX        _EC_U32_MAX
#define EC_U64_MAX        _EC_U64_MAX

/* time struct */
typedef struct
{
    EC_U32 m_nHour;
    EC_U32 m_nMinute;
    EC_U32 m_nSecond;
    EC_U32 m_nMillisecond;
} EC_Time;

/* date and time struct*/
typedef struct
{
    EC_U32  m_nYear;
    EC_U32  m_nMonth;
    EC_U32  m_nDay;
    EC_Time m_nTime;
    EC_U32  m_nDayOfWeek;
} EC_Date;

#ifdef EC_OS_Win32
#define ecThreadHandle  HANDLE
#elif defined EC_OS_Linux
#define ecThreadHandle  pthread_t
#elif defined EC_OS_MacOS
/* TODO */
#elif defined EC_OS_iOS
#define ecThreadHandle  pthread_t
#elif defined EC_OS_Android
/* TODO */
#endif

#ifdef __cplusplus
}
#endif

#endif /* EC_TYPE_H */
