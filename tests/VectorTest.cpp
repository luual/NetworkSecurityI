/*************************************************************
**
** File Name : VectorTest.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 22:18:35 CET
**
** Last Modified : lun. 14 nov. 2016 22:37:05 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include "Vector.hh"

int Add(Vector<int> &v, int i)
{
    while(i % 10)
    {
        v.Push(i);
        --i;
    }
    return 0;
}
