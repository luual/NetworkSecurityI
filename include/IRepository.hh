/*************************************************************
**
** File Name : IRepository.hh
**
** Purpose :
**
** Creation Date : mar. 15 nov. 2016 00:24:02 CET
**
** Last Modified : mar. 15 nov. 2016 00:24:09 CET
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
    virtual void Delete(T element) = 0;
    virtual void Update(int index, T element) = 0;
    virtual T GetByIndex(int index) = 0;
};
