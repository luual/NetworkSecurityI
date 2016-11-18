/*************************************************************
**
** File Name : PacketForging.cpp
**
** Purpose : 
**
** Creation Date : ven. 18 nov. 2016 13:46:33 CET
**
** Last Modified : ven. 18 nov. 2016 13:57:12 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#include "PacketForging.hh"

PacketForging::PacketForging()
{
}

PacketForging::~PacketForging()
{
}

void PacketForging::Send(Packet p, std::map<int, int> socketmap)
{
    char *buffer = new char[p.ipHeader.length + p.header.length + p.data.length + 1];
}
