/*************************************************************
**
** File Name : Vector.hh
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 20:33:35 CET
**
** Last Modified : lun. 14 nov. 2016 22:16:54 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <mutex>
#include "IThread.hh"
#include "IVector.hh"

template <typename T>
class Vector : public IVector<T>
{
    public:
        Vector();
        virtual ~Vector();
        virtual void Push(T element);
        virtual T GetByIndex(int index) const;
        virtual const std::vector<T> GetAll() const;
        virtual const T GetFront() const;
        virtual const T GetBack() const;
        virtual int Size() const;
        virtual void Remove(int position);
    private:
        std::vector<T> m_vector;
        std::mutex m_guard;
        pthread_mutex_t m_lock;
};

#include "Vector.tpp"
