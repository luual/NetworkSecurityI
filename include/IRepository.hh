/*************************************************************
**
** File Name : IRepository.hh
**
** Purpose :
**
** Creation Date : mar. 15 nov. 2016 00:24:02 CET
**
** Last Modified : mer. 16 nov. 2016 22:16:45 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

template <typename T>
class IRepository
{
public:
    virtual void Insert(T element) = 0;
    virtual void Delete(int index) = 0;
    virtual void Update(int index, T element) = 0;
    virtual const T GetByIndex(int index) = 0;
    //virtual const T GetAll() = 0; 
    virtual int Size() const = 0;
};
