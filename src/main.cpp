/*************************************************************
**
** File Name : main.cpp
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:04:04 CEST
**
** Last Modified : ven. 04 nov. 2016 18:34:42 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "Network.hh"
#include "Socket.hh"
#include "SocketAnalyzer.hh"

int main(void)
{
    Network net;
    Socket socks;
    SocketAnalyzer asock;
    socks.Connect();
    asock.Analyze(socks.GetSocket());
    return 0;
}
