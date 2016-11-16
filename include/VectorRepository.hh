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

class VectorRepository : public IRepository<Packet>
{
public:
    ~VectorRepository();
    virtual void Insert(Packet element);
    virtual void Delete(int index);
    virtual void Update(int index, Packet element);
    virtual const Packet GetByIndex(int index) const;
    virtual const Vector<Packet> GetAll() const;
    static &VectorRepository GetInstance();
private:
    VectorRepository();
    std::mutex m_mutex;
    Vector<Packet> m_vector;
};
