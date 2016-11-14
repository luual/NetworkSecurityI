/*************************************************************
**
** File Name : IThread.hh
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 20:34:42 CET
**
** Last Modified : lun. 14 nov. 2016 21:58:40 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <pthread.h>

class ScopeLock
{
public:
    ScopeLock(pthread_mutex_t &mutex);
    ~ScopeLock();
private:
    pthread_mutex_t &m_mutex;
};
