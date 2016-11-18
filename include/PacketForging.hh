/*************************************************************
**
** File Name : PacketForging.hh
**
** Purpose : 
**
** Creation Date : jeu. 17 nov. 2016 16:15:16 CET
**
** Last Modified : ven. 18 nov. 2016 13:51:43 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <map>
#include <sys/types.h>
#include <sys/socket.h>
#include "ISocketAnalyzer.hh"


class PacketForging
{
    public:
        PacketForging();
        ~PacketForging();
        void Send(Packet p, std::map<int, int> socketmap);
}
