/*************************************************************
**
** File Name : INetwork.hh
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:07:03 CEST
**
** Last Modified : jeu. 27 oct. 2016 12:16:36 CEST
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
        virtual std::string GetIp() const = 0;
};
