/*************************************************************
**
** File Name : main.cpp
**
** Purpose :
**
** Creation Date : jeu. 20 oct. 2016 15:04:04 CEST
**
** Last Modified : lun. 14 nov. 2016 22:18:44 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "Network.hh"
#include "Socket.hh"
#include "Vector.hh"
#include "SocketAnalyzer.hh"

int main(void)
{
    Network net;
    Vector<Packet> v;
    Socket socks;
    SocketAnalyzer asock;
    if (socks.Connect(IPPROTO_TCP) == -1)
        return -1;
    std::cout << "Socket created" << std::endl;
    asock.Analyze(socks.GetSocket());
    return 0;
}
