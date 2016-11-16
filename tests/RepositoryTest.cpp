/*************************************************************
**
** File Name : RepositoryTest.cpp
**
** Purpose : 
**
** Creation Date : mer. 16 nov. 2016 21:58:24 CET
**
** Last Modified : mer. 16 nov. 2016 22:32:29 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "VectorRepository.hh"

bool PushRepositoryTest()
{
    IRepository<Packet> *repo = new VectorRepository<Packet>;
    Packet p1;
    repo->Insert(p1);
    return repo->Size() == 1;
}
