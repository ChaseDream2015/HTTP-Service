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
* ECSignal.h
* This file for mutil thread used signal define.
*
* Eamil:   epengao@126.com
* Author:  Peter Gao
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef EC_SIGNAL_H
#define EC_SIGNAL_H

#include "ECMutex.h"

#ifdef EC_OS_Win32
#include <windows.h>
#elif defined EC_OS_Linux
/* TODO */
#elif defined EC_OS_MacOS
/* TODO */
#elif defined EC_OS_iOS
#include <pthread.h>
#elif defined EC_OS_Android
/* TODO */
#endif


class ECSignal
{
public:
    ECSignal();
    ~ECSignal();
    void Send();
    void Wait();
    void TimedWait(EC_U32 nTimeout);

private:
#ifdef EC_OS_Win32
    HANDLE  m_Event;
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    pthread_cond_t m_Cond;
    pthread_mutex_t m_Mutex;
#elif defined EC_OS_Android
    /* TODO */
#endif
};

#endif /* EC_SIGNAL_H */
