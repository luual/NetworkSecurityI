/*************************************************************
**
** File Name : IVector.hh
**
** Purpose :
**
** Creation Date : jeu. 27 oct. 2016 22:13:06 CEST
**
** Last Modified : sam. 12 nov. 2016 19:41:05 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <vector>

template <typename T>
class IVector
{
public:
    virtual void Push(T element) = 0;
    virtual T GetByIndex(int index) const = 0;
    virtual const T GetFront() const = 0;
    virtual const T GetBack() const = 0;
    virtual const std::vector<T> GetAll() const = 0;
    virtual int Size() const = 0;
    virtual void Remove(int position) = 0;
};
