/*************************************************************
**
** File Name : main.cpp
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:04:04 CEST
**
** Last Modified : jeu. 27 oct. 2016 18:10:29 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "Network.hh"

int main(void)
{
    Network net;
    auto networkInterfaces = net.GetNetworkInterface();
    for (std::vector<std::string>::iterator it = networkInterfaces.begin();
            it != networkInterfaces.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    net.GetIp("docker0");
    return 0;
}
