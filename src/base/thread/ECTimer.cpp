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
* ECTimer.cpp
* This file for ECTimer interface & encapsulation implementation.
*
* Eamil:   epengao@126.com
* Author:  Gao Peng
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "ECTimer.h"


ECThread::ECTimer(void*(*TimerEventCallback)(void*),
                  void* pCallbackArg, EC_BOOL bRepeat)
:m_bRepeat(bRepeat)
,m_pCallbackArg(pCallbackArg)
,m_ThreadProcEntry(ThreadProcEntry)
,m_hTimerCallback(TimerEventCallback)
{
#ifdef EC_OS_Win32
    /* TODO */
#elif defined EC_OS_Linux
    m_nTimerID = -1;
    struct sigevent evp;
    memset(&evp, 0, sizeof(evp));
    evp.sigev_notify = SIGEV_THREAD;
    evp.sigev_value.sival_ptr = this;
    evp.sigev_notify_function = TimerEventRoutine;
    timer_create(CLOCK_REALTIME, &evp, &m_nTimerID);
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    dispatch_source_t source = 0;
    source = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, timer_manager_queue());
    dispatch_source_set_event_handler(source, ^{
        if (timer->once_flag)
        {
            dispatch_suspend(source);
        }
        m_hTimerCallback(pCallbackArg);
    });
    m_Source = source;
#elif defined EC_OS_Android
    /* TODO */
#endif
}

ECTimer::~ECTimer()
{
#ifdef EC_OS_Win32
    /* TODO */
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    dispatch_source_cancel(m_Source);
    m_Source = NULL;
#elif defined EC_OS_Android
    /* TODO */
#endif
}

EC_VOID ECTimer::Start(EC_U32 nTime);
{
    if (nTime <= 0) return;
#ifdef EC_OS_Win32
    /* TODO */
#elif defined EC_OS_Linux
    struct itimerspec tmo;
    EC_U32 nSec = nTime / 1000;
    EC_U32 nNsec = (nTime % 1000) * 1000 * 1000;
    if (m_bRepeat)
    {
        tmo.it_interval.tv_sec  = 0;
        tmo.it_interval.tv_nsec = 0;
    }
    else
    {
        tmo.it_interval.tv_sec  = nSec;
        tmo.it_interval.tv_nsec = nNsec;
    }
    tmo.it_value.tv_sec  = nSec;
    tmo.it_value.tv_nsec = nNsec;
    timer_settime(m_nTimerID, 0, &tmo, NULL);
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    EC_U32 nSec = nTime / 1000;
    EC_U32 nUsec = (nTime % 1000) * 1000;
    dispatch_time_t startTime = 0;
    EC_U64 nTotalTime = (EC_U64)(nSec * NSEC_PER_SEC + nUsec * NSEC_PER_USEC);
    startTime = dispatch_time(DISPATCH_TIME_NOW, nTotalTime);
    dispatch_source_set_timer(m_Source, startTime, nTotalTime, 0.0);
    dispatch_resume(m_Source);
#elif defined EC_OS_Android
    /* TODO */
#endif
    m_nStatus = ECThreadStatus_Running;
}

EC_VOID ECTimer::Restart(EC_U32 nTime);
{
        if (nTime <= 0) return;
#ifdef EC_OS_Win32
    /* TODO */
#elif defined EC_OS_Linux
    struct itimerspec tmo;
    EC_U32 nSec = nTime / 1000;
    EC_U32 nNsec = (nTime % 1000) * 1000 * 1000;
    if (m_bRepeat)
    {
        tmo.it_interval.tv_sec  = 0;
        tmo.it_interval.tv_nsec = 0;
    }
    else
    {
        tmo.it_interval.tv_sec  = nSec;
        tmo.it_interval.tv_nsec = nNsec;
    }
    tmo.it_value.tv_sec  = nSec;
    tmo.it_value.tv_nsec = nNsec;
    timer_settime(m_nTimerID, 0, &tmo, NULL);
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    dispatch_time_t startTime = 0;
    dispatch_source_t source  = m_Source;
    EC_U32 nSec = nTime / 1000;
    EC_U32 nUsec = (nTime % 1000) * 1000;
    EC_U64 nWaitTime = (EC_U64)(nSec * NSEC_PER_SEC + nUsec * NSEC_PER_USEC);

    dispatch_source_cancel(source);
    source = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, timer_manager_queue());
    dispatch_source_set_event_handler(source, ^{
        if (m_bRepeat)
        {
            dispatch_suspend(source);
        }
        m_hTimerCallback(m_pCallbackArg);
    });
    startTime = dispatch_time(DISPATCH_TIME_NOW, nWaitTime);
    dispatch_source_set_timer(source, startTime, nWaitTime, 0.0);
    dispatch_resume(source);
    m_Source = source;
#elif defined EC_OS_Android
    /* TODO */
#endif
    m_nStatus = ECThreadStatus_Stoped;
}

EC_VOID ECTimer::Stop()
{
#ifdef EC_OS_Win32
    /* TODO */
#elif defined EC_OS_Linux
    if(m_nTimerID < 0)
        return;
    timer_delete(m_nTimerID);
    m_nTimerID = -1;
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    dispatch_source_cancel(m_Source);
#elif defined EC_OS_Android
    /* TODO */
#endif
}
