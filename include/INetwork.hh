/*************************************************************
**
** File Name : INetwork.hh
**
** Purpose :
**
** Creation Date : jeu. 20 oct. 2016 15:07:03 CEST
**
** Last Modified : ven. 28 oct. 2016 11:01:57 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#pragma once
#include <string>
#include <vector>

class INetwork
{
    public:
        virtual ~INetwork(){}
        virtual std::vector<std::string> GetNetworkInterface() const = 0;
        virtual std::string GetIp(std::string networkName) const = 0;
};
