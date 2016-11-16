/*************************************************************
**
** File Name : VectorRepository.cpp
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:33:39 CEST
**
** Last Modified : mer. 16 nov. 2016 22:06:07 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

//#include <iostream>
//#include "VectorRepository.hh"


template <typename T>
VectorRepository<T>::VectorRepository()
{
}

template <typename T>
VectorRepository<T>::~VectorRepository()
{
}

template <typename T>
void VectorRepository<T>::Insert(T element)
{
    m_vector.Push(element);
}

template <typename T>
void VectorRepository<T>::Delete(int index)
{
    m_vector.Remove(index);
}

template <typename T>
void VectorRepository<T>::Update(int index, T element)
{
    if (index > m_vector.Size())
    {
        std::cerr << "OutOfRangeException : You requested an element which is not in the range of the table" << std::endl;
        return ;
    }
    m_vector[index] = element;
}

template <typename T>
const T VectorRepository<T>::GetByIndex(int index)
{
    return m_vector[index];
}

//template<typename T>
//const std::vector<T> VectorRepository<T>::GetAll()
//{
//    return m_vector.GetAll();
//}

template <typename T>
int VectorRepository<T>::Size() const
{
    return m_vector.Size();
}
