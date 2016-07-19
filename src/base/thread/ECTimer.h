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
* ECTimer.h
* This file for ECTimer define and encapsulation.
*
* Eamil:   epengao@126.com
* Author:  Gao Peng
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#ifndef EC_TIMER_H
#define EC_TIMER_H

#ifdef EC_OS_Win32
#include <windows.h>
#elif defined EC_OS_Linux
/* TODO */
#elif defined EC_OS_MacOS
/* TODO */
#elif defined EC_OS_iOS
#include <time.h>
#include <signal.h>
#include <sys/time.h>
#elif defined EC_OS_Android
/* TODO */
#endif

class ECTimer
{
public:
    ECTimer(void*(*TimerEventCallback)(void*),
            void* pCallbackArg, EC_BOOL bRepeat = EC_FALSE);
    ~ECTimer();
    EC_VOID Start(EC_U32 nTime);   /* millisecond after */
    EC_VOID Restart(EC_U32 nTime); /* millisecond after */
    EC_VOID Stop();

private:
    static void TimerEventRoutine(void* pArg);

private:
    EC_BOOL  m_bRepeat;
    EC_VOID* m_pCallbackArg;
    EC_VOID* (*m_hTimerCallback)(void*);

#ifdef EC_OS_Win32
    UINT_PTR m_nTimerID;
#elif defined EC_OS_Linux
    EC_S32 m_nTimerID;
#elif defined EC_OS_MacOS
    EC_S32 m_nTimerID;
#elif defined EC_OS_iOS
    EC_S32 m_nTimerID;
    dispatch_source_t m_Source;
#elif defined EC_OS_Android
/* TODO */
#endif
};

#endif /* EC_TIMER_H */
