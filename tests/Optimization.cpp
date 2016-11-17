/*************************************************************
**
** File Name : Optimization.cpp
**
** Purpose : 
**
** Creation Date : jeu. 17 nov. 2016 15:26:24 CET
**
** Last Modified : jeu. 17 nov. 2016 15:32:11 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include "Vector.hh"
#include "SocketAnalyzer.hh"

void LeakTest()
{
    Packet p;
    Vector<Packet> v;
    v.Push(p);
    v.Push(p);
    v.Push(p);
    v.Push(p);
}
