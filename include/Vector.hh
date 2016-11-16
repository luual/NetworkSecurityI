/*************************************************************
**
** File Name : Vector.hh
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 20:33:35 CET
**
** Last Modified : mer. 16 nov. 2016 21:35:58 CET
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
        virtual const T GetFront() const;
        virtual const T GetBack() const;
        virtual const std::vector<T> GetAll();
        virtual int Size() const;
        virtual void Remove(int position);
        virtual T operator[](int index);
    private:
        std::vector<T> m_vector;
        std::mutex m_guard;
};

#include "Vector.hpp"
