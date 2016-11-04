/*************************************************************
**
** File Name : Network.hh
**
** Purpose :
**
** Creation Date : jeu. 20 oct. 2016 15:27:36 CEST
**
** Last Modified : jeu. 27 oct. 2016 21:59:41 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <string.h>
#include <errno.h>
#include <algorithm>

#include "INetwork.hh"

class Network : public INetwork
{
    private:
        struct ifaddrs* m_ifap;
    public:
        Network();
        virtual ~Network();
        virtual std::vector<std::string> GetNetworkInterface() const;
        virtual std::string GetIp(std::string networkName) const;
};
