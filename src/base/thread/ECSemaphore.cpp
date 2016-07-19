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
* ECSemaphore.h
* This file for ECSemaphore interface implementation.
*
* Eamil:   epengao@126.com
* Author:  Gao Peng
* Version: Intial first version.
* --------------------------------------------------------------------
*/

#include "ECOSUtil.h"
#include "ECStringOP.h"
#include "ECSemaphore.h"


ECSemaphore::ECSemaphore(EC_U32 nInitSig, /*0*/
                         EC_U32 nMaxSig   /*EC_MAX_U16*/)
{
#ifdef EC_OS_Win32
    m_hSemaphore = CreateSemaphore
                    (
                        EC_NULL,  // default security attributes
                        nInitSig,  // initial count
                        nMaxSig,   // maximum count
                        EC_NULL   // unnamed semaphore
                    );
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    //m_pSemaphoreName = new EC_CHAR[128];
    //ECStringOP::IntToStr(m_pSemaphoreName, (EC_U32)(ecGetSystemTimeU() % EC_U32_MAX));
    //m_hSemaphore = sem_open(m_pSemaphoreName, O_CREAT, 644, nInitSig);
    m_nSignalTimes = 0;
    pthread_cond_init(&m_Cond, EC_NULL);
    pthread_mutex_init(&m_Mutex, EC_NULL);
#elif defined EC_OS_Android
    /* TODO */
#endif
}

ECSemaphore::~ECSemaphore()
{
#ifdef EC_OS_Win32
    CloseHandle(m_hSemaphore);
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    //sem_close(m_hSemaphore);
    //sem_unlink(m_pSemaphoreName);
    //if(m_pSemaphoreName) delete m_pSemaphoreName;
    pthread_cond_destroy(&m_Cond);
    pthread_mutex_destroy(&m_Mutex);
#elif defined EC_OS_Android
    /* TODO */
#endif
}

EC_BOOL ECSemaphore::SemPost()
{
#ifdef EC_OS_Win32
    return ReleaseSemaphore(m_hSemaphore, 1, EC_NULL);
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    //return (0 == sem_post(m_hSemaphore));
    pthread_mutex_lock(&m_Mutex);
    {
        m_nSignalTimes++;
        return (0 == pthread_cond_signal(&m_Cond));
    }
    pthread_mutex_unlock(&m_Mutex);
#elif defined EC_OS_Android
    /* TODO */
#endif
}

EC_BOOL ECSemaphore::SemWait()
{
#ifdef EC_OS_Win32
    return (0 == WaitForSingleObject(m_hSemaphore, INFINITE));
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    //return (0 == sem_wait(m_hSemaphore));
    pthread_mutex_lock(&m_Mutex);
    {
        m_nSignalTimes--；
        while (m_nSignalTimes < 0)
        {
            pthread_cond_wait(&m_Cond, &m_Mutex);
        }
    }
    pthread_mutex_unlock(&m_Mutex);
    return EC_TRUE;
#elif defined EC_OS_Android
    /* TODO */
#endif
}

EC_BOOL ECSemaphore::TimedSemWait(EC_U32 nTimeout)
{
#ifdef EC_OS_Win32
    return (0 == WaitForSingleObject(m_hSemaphore, nTimeout));
#elif defined EC_OS_Linux
    /* TODO */
#elif defined EC_OS_MacOS
    /* TODO */
#elif defined EC_OS_iOS
    //struct timespec timeout;
    //timeout.tv_nsec = 0;
    //timeout.tv_sec = time(NULL) + nTimeout;
    //return (0 == sem_timedwait(m_hSemaphore, nTimeout));
    struct timespec timeout;
    timeout.tv_nsec = 0;
    timeout.tv_sec = time(NULL) + secs;

    pthread_mutex_lock(&m_Mutex);
    {
        m_nSignalTimes--；
        while (m_nSignalTimes < 0)
        {
            pthread_cond_timedwait(&m_Cond, &m_Mutex, &timeout);
        }
    }
    pthread_mutex_unlock(&m_Mutex);
    return EC_TRUE;
#elif defined EC_OS_Android
    /* TODO */
#endif
}
