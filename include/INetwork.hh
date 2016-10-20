/*************************************************************
**
** File Name : INetwork.hh
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:07:03 CEST
**
** Last Modified : jeu. 20 oct. 2016 16:05:19 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#pragma once
#include <string>

class INetwork
{
    public:
        virtual int Connect() = 0;
        virtual int Disconnect() = 0;
        virtual std::string GetIp() = 0;
};
