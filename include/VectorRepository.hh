/*************************************************************
**
** File Name : VectorRepository.hh
**
** Purpose :
**
** Creation Date : mar. 15 nov. 2016 22:15:17 CET
**
** Last Modified : mar. 15 nov. 2016 22:15:19 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <mutex>
#include "IRepository.hh"
#include "ISocketAnalyzer.hh"
#include "Vector.hh"

class VectorRepository : public IRepository
{
public:
    virtual void Insert(Packet element);
    virtual void Delete(Packet element);
    virtual void Update(int index, Packet element);
    virtual Packet GetByIndex(int index);
private:
    std::mutex m_mutex;
    Vector<Packet> m_vector;
};
