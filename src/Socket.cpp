/*************************************************************
**
** File Name : Socket.cpp
**
** Purpose : 
**
** Creation Date : jeu. 27 oct. 2016 22:19:43 CEST
**
** Last Modified : sam. 12 nov. 2016 19:40:01 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include <unistd.h>
#include "Socket.hh"

////////////////////////////////////////
// Constructor

Socket::Socket()
{
}

////////////////////////////////////////
// Destructor
Socket::~Socket()
{
    close(m_sock);
}

////////////////////////////////////////
// Connect

//int Socket::Connect(cosnt std::string hostname, const int port)
int Socket::Connect()
{
    for (int i = 0; i < 10; ++i)
    {
        if((m_sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) != -1)
        {
            return 0;
        }
        else
        {
            std::cerr << "Attempt " << i << " / 10" << std::endl;
            sleep(1);
        }
    }
    std::cerr << strerror(errno) << std::endl;
    return -1;
}

////////////////////////////////////////
// GetSocket

int Socket::GetSocket() const
{
    return m_sock;
}
