/*************************************************************
**
** File Name : Network.cpp
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:33:39 CEST
**
** Last Modified : jeu. 27 oct. 2016 12:22:46 CEST
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include "Network.hh"

/////////////////////////////////////////////////////
// Initialize the class and dynamically allocated
// the pointer will be free in the destructor
Network::Network()
{
    while (getifaddrs(&m_ifap) == -1)
            std::cout << strerror(errno) << std::endl;
}

/////////////////////////////////////////////////////
// Destructor of the class will free the memory
// allocated in the constructor
Network::~Network()
{
    if (m_ifap != NULL)
        freeifaddrs(m_ifap);
}

/////////////////////////////////////////////////////
// TO DO 
// Connect
int Network::Connect()
{
    return 0;
}

/////////////////////////////////////////////////////
// TO DO
// Disconnect

int Network::Disconnect()
{
    return 0;
}

/////////////////////////////////////////////////////
// GetIp
std::string Network::GetIp() const
{
    if (m_ifap == NULL)
        return "";
    std::string out;
    struct ifaddrs* tmp = m_ifap;
    while (tmp)
    {
        out += tmp->ifa_name;
        out += "::";
        tmp = tmp->ifa_next;
    }
    return out;
}
