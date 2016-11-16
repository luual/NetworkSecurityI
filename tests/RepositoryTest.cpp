/*************************************************************
**
** File Name : RepositoryTest.cpp
**
** Purpose : 
**
** Creation Date : mer. 16 nov. 2016 21:58:24 CET
**
** Last Modified : mer. 16 nov. 2016 23:04:15 CET
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

bool PacketIntegrityTest()
{
    IRepository<Packet> *repo = new VectorRepository<Packet>;
    Packet p1;
    p1.ipHeader.version = 4;
    repo->Insert(p1);
    Packet p2 = repo->GetByIndex(0);
    return p1.ipHeader.version == p2.ipHeader.version;
}
