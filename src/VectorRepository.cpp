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
#include <iostream>
#include "VectorRepository.hh"

VectorRepository& VectorRepository::GetInstance()
{
    return &m_instance;
}

VectorRepository::VectorRepository()
{
}

VectorRepository::~VectorRepository()
{
}

void VectorRepository::Insert(Packet element)
{
    m_vector.Push(element);
}

void VectorRepository::Delete(int index)
{
    m_vector.Remove(index);
}

void VectorRepository::Update(int index, Packet element)
{
    if (index > m_vector.Size())
    {
        std::cerr << "OutOfRangeException : You requested an element which is not in the range of the table" << std::endl;
        return ;
    }
    m_vector[index] = element;
}

const Packet VectorRepository::GetByIndex(int index) const
{
    return m_vector[index];
}

const Vector<Packet> VectorRepository::GetAll() const
{
    return m_vector;
}
