/*************************************************************
**
** File Name : main.cpp
**
** Purpose :
**
** Creation Date : jeu. 20 oct. 2016 15:04:04 CEST
**
** Last Modified : mer. 16 nov. 2016 23:42:51 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "Network.hh"
#include "Socket.hh"
#include "Vector.hh"
#include "SocketAnalyzer.hh"
#include "VectorRepository.hh"

int main(void)
{
    //Network net;
    IRepository<Packet> *repo = new VectorRepository<Packet>();
    Vector<Packet> v;
    Socket socks;
    SocketAnalyzer<Packet> asock;
    if (socks.Connect(IPPROTO_TCP) == -1)
        return -1;
    std::cout << "Socket created" << std::endl;
    asock.Analyze(socks.GetSocket(), *repo);
    return 0;
}
