/*************************************************************
**
** File Name : VectorRepository.hh
**
** Purpose :
**
** Creation Date : mar. 15 nov. 2016 22:15:17 CET
**
** Last Modified : mer. 16 nov. 2016 22:18:54 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include "IRepository.hh"
#include "ISocketAnalyzer.hh"
#include "Vector.hh"

template <typename T>
class VectorRepository : public IRepository<T>
{
public:
    VectorRepository();
    ~VectorRepository();
    virtual void Insert(T element);
    virtual void Delete(int index);
    virtual void Update(int index, T element);
    virtual const T GetByIndex(int index);
    virtual int Size() const;
    //virtual const std::vector<T> GetAll();
private:
    Vector<T> m_vector;
};

#include "VectorRepository.hpp"
