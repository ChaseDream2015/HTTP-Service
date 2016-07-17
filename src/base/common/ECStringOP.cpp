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
* ECStringOP.cpp
* This file for redefing all the EC string interface operation implement.
*
* Eamil:   epengao@126.com
* Author:  Gao Peng
* Version: Intial first version.
* ------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "ECStringOP.h"


EC_U32 ecStrLen(EC_CONST_PCHAR pStr)
{
    return (EC_U32)strlen(pStr);
}

EC_CHAR ecToUpper(EC_CHAR cChar)
{
    EC_CHAR cRet = cChar;
    if(('a'<=cChar) && (cChar<='z'))
        cRet = (cChar-32);
    return cRet;
}

EC_CHAR ecToLower(EC_CHAR cChar)
{
    EC_CHAR cRet = cChar;
    if(('A'<=cChar) && (cChar<='Z'))
        cRet = (cChar+32);
    return cRet;
}

EC_PCHAR ecToUpperStr(EC_PCHAR pStr)
{
    EC_PCHAR pRet = pStr;
    while((*pStr) != '\0')
    {
        *pStr = ecToUpper(*pStr);
        pStr++;
    }
    return pRet;
}

EC_PCHAR ecToLowerStr(EC_PCHAR pStr)
{
    EC_PCHAR pRet = pStr;
    while((*pStr) != '\0')
    {
        *pStr = ecToLower(*pStr);
        pStr++;
    }
    return pRet;
}

EC_PCHAR ecStrCopy(EC_PCHAR pDest, EC_CONST_PCHAR pSrc)
{
    return strcpy(pDest, pSrc);
}

EC_PCHAR ecStrNCopy(EC_PCHAR pDest, const EC_PCHAR pSrc, EC_U32 uSize)
{
    return strncpy(pDest, pSrc, uSize);
}

EC_PCHAR ecStrCat(EC_PCHAR pDest, const EC_PCHAR pSrc)
{
    return strcat(pDest, pSrc);
}

EC_PCHAR ecStrAddPrefix(EC_PCHAR pStr, const EC_PCHAR pPrefix)
{
    EC_PCHAR pNewStr = new EC_CHAR[ecStrLen(pStr) +
                                   ecStrLen(pPrefix) + 1];
    ecStrCopy(pNewStr, pPrefix);
    ecStrCat(pNewStr, pStr);
    delete []pStr;
    pStr = pNewStr;
    return pStr;
}

EC_PCHAR ecStrInsertChar(EC_PCHAR pStr, EC_CHAR cChar, EC_U32 uIndex)
{
    EC_U32 uLength = ecStrLen(pStr);
    if(uIndex > uLength)
        return EC_NULL;

    EC_PCHAR pNewStr = new EC_CHAR[uLength + 2];
    if((0 < uIndex) && (uIndex < uLength))
    {
        pNewStr[uIndex] = cChar;
        ecStrNCopy(pNewStr, pStr, uIndex);
        ecStrCopy(pNewStr+uIndex+1, pStr+uIndex);
    }
    else if (uLength == uIndex)
    {
        ecStrCopy(pNewStr, pStr);
        pNewStr[uLength] = cChar;
        pNewStr[uLength+1] = '\0';
    }
    else if(0 == uIndex)
    {
        pNewStr[0] = cChar;
        ecStrCopy(pNewStr+1, pStr);
    }

    delete pStr;
    pStr = pNewStr;
    return pStr;
}

EC_PCHAR ecStrInsertStr(EC_PCHAR pStr, const EC_PCHAR pInsert, EC_U32 uIndex)
{
    EC_U32 uSrcLength = ecStrLen(pStr);
    EC_U32 uInsertLength = ecStrLen(pInsert);
    EC_U32 uTotalLength = uSrcLength + uInsertLength;

    if(uIndex > uSrcLength)
        return EC_NULL;

    EC_PCHAR pNewStr = new EC_CHAR[uTotalLength + 1];
    if((0 < uIndex) && (uIndex < uSrcLength))
    {
        ecStrCopy(pNewStr+uIndex, pInsert);
        ecStrNCopy(pNewStr, pStr, uSrcLength);
        ecStrCopy(pNewStr+uInsertLength, pStr+uIndex);
    }
    else if (uSrcLength == uIndex)
    {
        ecStrCat(pNewStr, pInsert);
    }
    else if(0 == uIndex)
    {
        ecStrCopy(pNewStr, pInsert);
        ecStrCopy(pNewStr+uInsertLength, pStr);
    }

    delete pStr;
    pStr = pNewStr;
    return pStr;
}

EC_PCHAR ecStrStr(EC_PCHAR pDest, EC_PCHAR pFind)
{
    return strstr(pDest, pFind);
}

EC_PCHAR ecStrSet(EC_PCHAR pStr, EC_CHAR cChar)
{
    memset(pStr, cChar, ecStrLen(pStr));
    return pStr;
}

EC_S32 ecStrCompare(EC_PCHAR pStr1, EC_PCHAR pStr2)
{
    return strcmp(pStr1, pStr2);
}

EC_S32 ecStrNCompare(EC_PCHAR pStr1, EC_PCHAR pStr2, EC_U32 uSize)
{
    return strncmp(pStr1, pStr2, uSize);
}

EC_S32 ecStrCaseCompare(EC_PCHAR pStr1, EC_PCHAR pStr2)
{
    EC_S32 nRet;
    EC_PCHAR pTmpStr1 = new EC_CHAR[ecStrLen(pStr1)+1];
    EC_PCHAR pTmpStr2 = new EC_CHAR[ecStrLen(pStr2)+1];
    ecStrCopy(pTmpStr1, pStr1);
    ecStrCopy(pTmpStr2, pStr2);
    nRet = ecStrCompare(ecToLowerStr(pTmpStr1),
                                    ecToLowerStr(pTmpStr2));
    delete []pTmpStr1;
    delete []pTmpStr2;
    return nRet;
}

EC_S32 ecStrNCaseCompare(EC_PCHAR pStr1, EC_PCHAR pStr2, EC_U32 uSize)
{
    EC_S32 nRet;
    EC_PCHAR pTmpStr1 = new EC_CHAR[ecStrLen(pStr1)+1];
    EC_PCHAR pTmpStr2 = new EC_CHAR[ecStrLen(pStr2)+1];
    ecStrCopy(pTmpStr1, pStr1);
    ecStrCopy(pTmpStr2, pStr2);
    nRet = ecStrNCompare(ecToLowerStr(pTmpStr1),
                                     ecToLowerStr(pTmpStr2), uSize);
    delete []pTmpStr1;
    delete []pTmpStr2;
    return nRet;
}

EC_S32 ecStrToInt(const EC_PCHAR pStr)
{
    return atoi(pStr);
    return 0;
}

EC_PCHAR ecIntToStr(EC_PCHAR pStr, EC_S32 nInt)
{
    sprintf(pStr, "%d", nInt);
    return pStr;
}

EC_PCHAR ecWideStrToCStr(EC_PCHAR pStr, const EC_PWCHAR pWstr)
{
    wcstombs(pStr, pWstr, wcslen(pWstr));
    return pStr;
}

EC_PWCHAR ecCStrToWideStr(EC_PWCHAR pWstr, const EC_PCHAR pStr)
{
    mbstowcs(pWstr, pStr, ecStrLen(pStr));
    return pWstr;
}
