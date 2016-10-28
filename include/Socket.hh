/*************************************************************
**
** File Name : Socket.hh
**
** Purpose : 
**
** Creation Date : jeu. 27 oct. 2016 22:13:06 CEST
**
** Last Modified : ven. 28 oct. 2016 11:06:35 CEST
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
#include "ISocket.hh"

// http://www.binarytides.com/packet-sniffer-code-c-linux/

class Socket : public ISocket
{
    public:
        Socket();
        virtual ~Socket();
        //virtual int Connect(const std::string hostname, const int port);
        virtual int Connect();
        virtual int Receive();
        virtual int Send();
    private:
        int m_sock;
        struct hostent *m_hostinfo;
        struct sockaddr_in m_sin;
};
