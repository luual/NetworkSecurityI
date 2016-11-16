/*************************************************************
**
** File Name : Network.cpp
**
** Purpose : 
**
** Creation Date : jeu. 20 oct. 2016 15:33:39 CEST
**
** Last Modified : jeu. 27 oct. 2016 18:10:31 CEST
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
        std::cerr << strerror(errno) << std::endl;
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
// GetNetworkInterface
std::vector<std::string> Network::GetNetworkInterface() const
{
    std::vector<std::string> out;
    if (m_ifap == NULL)
        return out;
    struct ifaddrs* tmp = m_ifap;
    while (tmp)
    {
        bool flag = false;
        for (std::vector<std::string>::iterator it = out.begin();
                it != out.end();
                ++it)
        {
            if (tmp->ifa_name == *it)
                flag = true;
        }
        if (flag == false)
            out.push_back(tmp->ifa_name);
        tmp = tmp->ifa_next;
    }
    return out;
}
/////////////////////////////////////////////////////
// GetNetworkInterface
std::string             Network::GetIp(std::string const networkName) const
{
    struct ifaddrs* tmp = m_ifap;
    while (tmp)
    {
        if (tmp->ifa_name == networkName)
        {
            struct sockaddr_in* myaddr = (struct sockaddr_in*)tmp->ifa_addr->sa_data;
            std::cout << inet_ntoa(myaddr->sin_addr) << std::endl;
            std::cout << "port : "<< myaddr->sin_port << std::endl;
        }
        tmp = tmp->ifa_next;
    }
    return "asd";
}
