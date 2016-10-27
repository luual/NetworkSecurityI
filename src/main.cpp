/*************************************************************
**
** File Name : main.cpp
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:04:04 CEST
**
** Last Modified : jeu. 27 oct. 2016 12:13:26 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "Network.hh"

int main(void)
{
    Network net;
    std::cout << net.GetIp() << std::endl;
    return 0;
}
