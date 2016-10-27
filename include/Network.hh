/*************************************************************
**
** File Name : Network.hh
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:27:36 CEST
**
** Last Modified : jeu. 27 oct. 2016 12:22:47 CEST
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
        virtual int Connect();
        virtual int Disconnect();
        virtual std::string GetIp() const;
};
