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
* ECMutableArray.h
*
* define a Mutable Array which can store any type of data.
*
* Eamil:  epengao@126.com
* Author: Gao Peng
* Version: First initinal version.
* --------------------------------------------------------------------
*/

#ifndef EC_MUTABLE_ARRAY_H
#define EC_MUTABLE_ARRAY_H

#include "ECNode.h"
#include "ECError.h"
#include "ECCompare.h"

template<typename T>
class ECMutableArray
{
public:
    ECMutableArray(ECCompare<T> *pCompare = EC_NULL);
    ~ECMutableArray();
    EC_U32 InsertToHead(const T data);
    EC_U32 InsertToTail(const T data);
    EC_U32 InsertAtIndex(const T data, EC_U32 index);
    EC_U32 DeleteFromHead();
    EC_U32 DeleteFromTail();
    EC_U32 DeleteAtIndex(EC_U32 index);
    EC_U32 DeleteAllIndex();
    EC_U32 GetItemFromHead(T* pData)               const;
    EC_U32 GetItemFromTail(T* pData)               const;
    EC_U32 GetItemAtIndex(T* pData, EC_U32 index)  const;
    EC_U32 GetItemsCount() const;
    EC_VOID SetCompare(ECCompare<T> *pCompare) {m_pCompare = pCompare;}
    EC_U32 Sort(EC_BOOL bAscending = EC_TRUE);

private:
    EC_U32          m_nCount;
    ECNode<T>*      m_pHeader;
    ECCompare<T>*   m_pCompare;
};

template<typename T>
ECMutableArray<T>::ECMutableArray(ECCompare<T> *pCompare)
:m_nCount(0)
,m_pHeader(EC_NULL)
,m_pCompare(pCompare)
{
}

template<typename T>
ECMutableArray<T>::~ECMutableArray()
{
    ECNode<T>* node = m_pHeader;
    while(node!=EC_NULL)
    {
        ECNode<T>* tmp = node->m_pNext;
        delete node;
        node = tmp;
    }
    m_pHeader = EC_NULL;
}

template<typename T>
EC_U32 ECMutableArray<T>::InsertToHead(const T data)
{
    ECNode<T>* pNode = new ECNode<T>(data);
    pNode->m_pNext = m_pHeader;
    m_pHeader = pNode;
    m_nCount ++;

    return EC_Err_None;
}

template<typename T>
EC_U32 ECMutableArray<T>::InsertToTail(const T data)
{
    if(m_pHeader==EC_NULL)
        return InsertToHead(data);

    ECNode<T>* node = m_pHeader;
    while(node && node->m_pNext)
        node = node->m_pNext;
    ECNode<T>* pNode = new ECNode<T>(data);
    node->m_pNext = pNode;
    m_nCount ++;

    return EC_Err_None;
}

template<typename T>
EC_U32 ECMutableArray<T>::InsertAtIndex(const T data, EC_U32 index)
{
    EC_U32 nRet = EC_Err_None;
    if( (index>0) && (index<m_nCount) )
    {
        ECNode<T>* node = m_pHeader;
        for(EC_U32 i=0; i<index-1; ++i)
        {
            node = node->m_pNext;
        }
        ECNode<T>* pNode = new ECNode<T>(data, node->m_pNext);
        node->m_pNext = pNode;
        m_nCount ++;
    }
    else if(index == 0)
        nRet = InsertToHead(data);
    else
        nRet = EC_Err_BadParam;

    return nRet;
}

template<typename T>
EC_U32 ECMutableArray<T>::DeleteFromHead()
{
    if(m_pHeader)
    {
        ECNode<T>* node = m_pHeader;
        m_pHeader = m_pHeader->m_pNext;
        delete node;
        m_nCount --;
        return EC_Err_None;
    }

    return EC_Err_ContainerEmpty;
}

template<typename T>
EC_U32 ECMutableArray<T>::DeleteFromTail()
{
    EC_U32 nRet = EC_Err_None;

    if(m_nCount >= 2)
    {
        ECNode<T>* node = m_pHeader;
        for(EC_U32 i=0; i<nCount-2; ++i)
            node = node->m_pNext;
        delete node->m_pNext;
        m_nCount --;
        node->m_pNext = EC_NULL;
    }
    else if(m_nCount == 1)
        nRet = DeleteFromHead();
    else
        nRet = EC_Err_ContainerEmpty;

    return nRet;
}

template<typename T>
EC_U32 ECMutableArray<T>::DeleteAtIndex(EC_U32 index)
{
    EC_U32 nRet = EC_Err_None;

    if( (index>0) && (index<m_nCount-1) )
    {
        ECNode<T>* node = m_pHeader;
        for(EC_U32 i=0; i<index-1; ++i)
            node = node->m_pNext;
        ECNode<T>* deleNode = node->m_pNext;
        node->m_pNext = deleNode->m_pNext;
        m_nCount --;
        delete deleNode;
    }
    else if(index == 0)
        nRet = DeleteFromHead();
    else if(index == (m_nCount-1))
        nRet = DeleteFromTail();
    else
        nRet = EC_Err_BadParam;

    return nRet;
}

template<typename T>
EC_U32 ECMutableArray<T>::DeleteAllIndex()
{
    while (m_pHeader != EC_NULL)
    {
        DeleteFromHead();
    }
    m_nCount = 0;

    return EC_Err_None;
}

template<typename T>
EC_U32 ECMutableArray<T>::GetItemFromHead(T* pData) const
{
    return GetItemAtIndex(pData, 0);
}

template<typename T>
EC_U32 ECMutableArray<T>::GetItemFromTail(T* pData) const
{
    return GetItemAtIndex(pData, m_nCount-1);
}

template<typename T>
EC_U32 ECMutableArray<T>::GetItemAtIndex(T* pData, EC_U32 index) const
{
    EC_U32 nRet = EC_Err_None;

    if(pData)
    {
        if((index>=0) && (index<m_nCount))
        {
            ECNode<T>* node = m_pHeader;
            for(EC_U32 i=0; i<index; ++i)
                node = node->m_pNext;
            *pData = node->m_sData;
        }
    }
    else
        nRet = EC_Err_BadParam;

    return nRet;
}

template<typename T>
EC_U32 ECMutableArray<T>::GetItemsCount() const
{
    return m_nCount;
}

template<typename T>
EC_U32 ECMutableArray<T>::Sort(EC_BOOL bAscending /* EC_TRUE*/)
{
    if(m_pCompare)
    {
        for(EC_U32 i=0; i<m_nItemCount-1; ++i)
        {
            for(EC_U32 j=0; j<m_nItemCount-1; ++j)
            {
                EC_S32 bCompareResult = m_pCompare->Compare(&m_pDatas[j], &m_pDatas[j+1]);
                if( (bSortType && (bCompareResult == EC_GREATER))
                    || (!bSortType && (bCompareResult == EC_LESSTHEN)) )
                {
                    T data = m_pDatas[j];
                    m_pDatas[j] = m_pDatas[j+1];
                    m_pDatas[j+1] = data;
                }
            }
        }
        return EC_Err_None;
    }
    else
        return EC_Err_NotImplement;
}

#endif /* EC_MUTABLE_ARRAY_H */
