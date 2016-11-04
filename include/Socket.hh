/*************************************************************
**
** File Name : Socket.hh
**
** Purpose : 
**
** Creation Date : jeu. 27 oct. 2016 22:13:06 CEST
**
** Last Modified : ven. 04 nov. 2016 18:30:48 CET
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

// http://www.binarytides.com/packet-sniffer-code-c-linux/

class Socket : public ISocket
{
    public:
        Socket();
        virtual ~Socket();
        virtual const int GetSocket() const;
        virtual int Connect();
    private:
        int m_sock;
};
