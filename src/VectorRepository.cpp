/*************************************************************
**
** File Name : VectorRepository.cpp
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:33:39 CEST
**
** Last Modified : jeu. 27 oct. 2016 18:10:31 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include "VectorRepository.hh"

VectorRepository::VectorRepository()
{
}

~VectorRepository::VectorRepository()
{
}

void VectorRepository::Insert(Packet element)
{
}

void VectorRepository::Delete(Packet element)
{
}

void VectorRepository::Update(int index, Packet element)
{
}

const Packet VectorRepository::GetByIndex(int index) const
{
    if (index > m_vector.Size())
    {
        return null;
    }
    return m_vector[index];
}

const Vector<Packet> VectorRepository::GetAll() const
{
    return m_vector;
}
