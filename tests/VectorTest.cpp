/*************************************************************
**
** File Name : VectorTest.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 22:18:35 CET
**
** Last Modified : jeu. 17 nov. 2016 15:19:46 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include "Vector.hh"
#include "SocketAnalyzer.hh"

int Add(Vector<Packet> &v, int i)
{
    while(i % 10)
    {
        Packet p;
        v.Push(p);
        --i;
    }
    return 0;
}
