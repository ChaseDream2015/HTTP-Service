/*
* This software is developed for study and improve coding skill ...
*
* Project:  Enjoyable Coding< EC >
* Copyright (C) Gao Peng, 2015

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
* ECStringOP.h
* This file for redefing all EC string operation interface define.
*
* Eamil:   epengao@126.com
* Author:  Gao Peng
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include <string.h>
#include "ECType.h"

EC_U32 ecStrLen(EC_CONST_PCHAR pStr);
EC_CHAR ecToUpper(EC_CHAR cChar);
EC_CHAR ecToLower(EC_CHAR cChar);
EC_PCHAR ecToUpperStr(EC_PCHAR pStr);
EC_PCHAR ecToLowerStr(EC_PCHAR pStr);
EC_PCHAR ecStrCopy(EC_PCHAR pDest, EC_CONST_PCHAR pSrc);
EC_PCHAR ecStrNCopy(EC_PCHAR pDest, const EC_PCHAR pSrc, EC_U32 uSize);
EC_PCHAR ecStrCat(EC_PCHAR pDest, const EC_PCHAR pSrc);
EC_PCHAR ecStrAddPrefix(EC_PCHAR pStr, const EC_PCHAR pPrefix);
EC_PCHAR ecStrInsertChar(EC_PCHAR pStr, EC_CHAR cChar, EC_U32 uIndex);
EC_PCHAR ecStrInsertStr(EC_PCHAR pStr, const EC_PCHAR pInsert, EC_U32 uIndex);
EC_PCHAR ecStrStr(EC_PCHAR pDest, EC_PCHAR pFind);
EC_PCHAR ecStrSet(EC_PCHAR pStr, EC_CHAR cChar);
EC_PCHAR ecIntToStr(EC_PCHAR pStr, EC_S32 nInt);
EC_PCHAR ecWideStrToCStr(EC_PCHAR pStr, EC_PWCHAR pWstr);
EC_PWCHAR ecCStrToWideStr(EC_PWCHAR pWstr, EC_PCHAR pStr);
EC_S32 ecStrToInt(const EC_PCHAR pStr);
EC_S32 ecStrCompare(EC_PCHAR pStr1, EC_PCHAR pStr2);
EC_S32 ecStrNCompare(EC_PCHAR pStr1, EC_PCHAR pStr2, EC_U32 uSize);
EC_S32 ecStrCaseCompare(EC_PCHAR pStr1, EC_PCHAR pStr2);
EC_S32 ecStrNoCaseCompare(EC_PCHAR pStr1, EC_PCHAR pStr2, EC_U32 uSize);
