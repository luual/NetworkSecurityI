/*************************************************************
**
** File Name : Socket.hh
**
** Purpose :
**
** Creation Date : jeu. 27 oct. 2016 22:13:06 CEST
**
** Last Modified : sam. 12 nov. 2016 19:41:05 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include "ISocket.hh"

class Socket : public ISocket
{
    public:
        Socket();
        virtual ~Socket();
        virtual int GetSocket() const;
        virtual int Connect(int protocol);
    private:
        int m_sock;
};
