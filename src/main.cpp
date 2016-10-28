/*************************************************************
**
** File Name : main.cpp
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:04:04 CEST
**
** Last Modified : ven. 28 oct. 2016 11:12:24 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "Network.hh"
#include "Socket.hh"

int main(void)
{
    Network net;
    Socket socks;
    auto networkInterfaces = net.GetNetworkInterface();
    for (std::vector<std::string>::iterator it = networkInterfaces.begin();
            it != networkInterfaces.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    //net.GetIp("docker0");
    socks.Connect();
    socks.Receive();
    return 0;
}
