/*************************************************************
**
** File Name : Socket.cpp
**
** Purpose : 
**
** Creation Date : jeu. 27 oct. 2016 22:19:43 CEST
**
** Last Modified : ven. 04 nov. 2016 18:30:14 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
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
}

////////////////////////////////////////
// Connect

//int Socket::Connect(cosnt std::string hostname, const int port)
int Socket::Connect()
{
    while((m_sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
    {
        std::cerr << strerror(errno) << std::endl;
    }
    return 0;
}

////////////////////////////////////////
// GetSocket

const int Socket::GetSocket() const
{
    return m_sock;
}
