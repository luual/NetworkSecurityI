/*************************************************************
**
** File Name : Vector.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 21:08:14 CET
**
** Last Modified : lun. 14 nov. 2016 22:16:54 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include "Vector.hh"

template<typename T>
Vector<T>::Vector()
{
}

template <typename T>
Vector<T>::~Vector()
{
}

template <typename T>
void Vector<T>::Push(T element)
{
    std::lock_guard<std::mutex> lock(m_guard);
    m_vector.push_back(element);
}

template <typename T>
T Vector<T>::GetByIndex(int index) const
{
    return m_vector[index];
}

template <typename T>
const T Vector<T>::GetFront() const
{
    return m_vector.front();
}

template <typename T>
const T Vector<T>::GetBack() const
{
    return m_vector.back();
}

template <typename T>
int Vector<T>::Size() const
{
    return m_vector.size();
}

template <typename T>
void Vector<T>::Remove(int position)
{
    std::lock_guard<std::mutex> lock(m_guard);
    m_vector.erase(m_vector.begin() + position);
}

template <typename T>
const std::vector<T> Vector<T>::GetAll()
{
    return m_vector;
}

template <typename T>
T Vector<T>::operator[](int index)
{
    return m_vector[index];
}
