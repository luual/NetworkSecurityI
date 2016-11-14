/*************************************************************
**
** File Name : Thread.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 23:02:33 CET
**
** Last Modified : lun. 14 nov. 2016 23:02:35 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#include "IThread.hh"

ScopeLock::ScopeLock(pthread_mutex_t &mutex):
m_mutex(mutex)
{
    pthread_mutex_lock(&m_mutex);
}
ScopeLock::~ScopeLock()
{
    pthread_mutex_unlock(&m_mutex);
}
