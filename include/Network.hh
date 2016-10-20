/*************************************************************
**
** File Name : Network.hh
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:27:36 CEST
**
** Last Modified : jeu. 20 oct. 2016 16:13:44 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#pragma once
#include <sys/types.h>
#include <ifaddrs.h>
#include <string.h>
#include <errno.h>

#include "INetwork.hh"

class Network : public INetwork 
{
    private:
        struct ifaddrs* m_ifap;
    public:
        Network();
        ~Network();
        int Connect();
        int Disconnect();
        std::string GetIp() const;
};
