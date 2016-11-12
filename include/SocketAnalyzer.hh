/*************************************************************
**
** File Name : Analyzer.hh
**
** Purpose : 
**
** Creation Date : ven. 04 nov. 2016 18:14:30 CET
**
** Last Modified : sam. 12 nov. 2016 19:37:38 CET
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
#include <map>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include "ISocketAnalyzer.hh"

class SocketAnalyzer : public ISocketAnalyzer
{
    public:
        virtual int Analyze(const int socket);
    private:
        int Process(char* data, int length);
        int PrintHeader(struct iphdr* iph, int iphdrlen);
        int PrintTCP(char* buffer, struct iphdr* iph, int iphdrlen, int size);
        void PrintData(char* data, int size);

};
