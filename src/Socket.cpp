/*************************************************************
**
** File Name : Socket.cpp
**
** Purpose : 
**
** Creation Date : jeu. 27 oct. 2016 22:19:43 CEST
**
** Last Modified : ven. 04 nov. 2016 16:32:36 CET
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
    m_hostinfo = NULL;
    while((m_sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
    {
        std::cerr << strerror(errno) << std::endl;
    }
    return 0;
}

//int Socket::Connect(const std::string hostname, const int port)
//{
//    m_hostinfo = gethostbyname(hostname);
//    if (m_hostinfo == NULL)
//    {
//        std::cerr << "Unknown host " << hostname << std::endl;
//    }
//    m_sin.sin_addr = *(struct in_addr*)m_hostinfo->h_addr;
//    m_sin.port = htons(port);
//    m_sin.family = AF_INET;
//}

////////////////////////////////////////
// Receive
int Socket::Receive()
{
    struct sockaddr addr;
    int dataSize;
    unsigned int length;
    char buffer[60000];

    dataSize = recvfrom(m_sock, buffer, 60000, 0, &addr, &length);
    if (dataSize > 0)
    {
        std::cout << buffer << std::endl;
    }
    else
    {
        std::cerr << "Failed to received packet" << std::endl;
    }
    Process(buffer);
    return 0;
}

////////////////////////////////////////
// Send

int Socket::Send()
{
    return 0;
}

////////////////////////////////////////
// process

int Socket::Process(char* data)
{
    struct iphdr* iph = (struct iphdr*)data;
    int iphdrlen = iph->ihl*4;
    struct tcphdr* tcph = (struct tcphdr*)(data + iphdrlen);
    std::cout << "protocol : " << (int)iph->protocol << std::endl;
    std::cout << "Source : " << ntohs(tcph->source) << std::endl;
    return 0;
}
