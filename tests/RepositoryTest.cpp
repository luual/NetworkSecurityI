/*************************************************************
**
** File Name : RepositoryTest.cpp
**
** Purpose : 
**
** Creation Date : mer. 16 nov. 2016 21:58:24 CET
**
** Last Modified : jeu. 17 nov. 2016 00:01:59 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "VectorRepository.hh"

static void TestPushRepository(IRepository<Packet> &repo)
{
    Packet p1;
    repo.Insert(p1);
}

bool PushRepositoryTest()
{
    IRepository<Packet> *repo = new VectorRepository<Packet>;
    TestPushRepository(*repo);
    return repo->Size() == 1;
}

static void TestPacketIntegrity(IRepository<Packet> &repo)
{
    Packet p1;
    p1.ipHeader.version = 4;
    repo.Insert(p1);
}

bool PacketIntegrityTest()
{
    IRepository<Packet> *repo = new VectorRepository<Packet>;
    TestPacketIntegrity(*repo);
    Packet p2 = repo->GetByIndex(0);
    return p2.ipHeader.version == 4;
}
