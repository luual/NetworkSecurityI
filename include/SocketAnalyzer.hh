/*************************************************************
**
** File Name : Analyzer.hh
**
** Purpose :
**
** Creation Date : ven. 04 nov. 2016 18:14:30 CET
**
** Last Modified : jeu. 17 nov. 2016 03:32:31 CET
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
#include <unistd.h>
#include "ISocketAnalyzer.hh"

template <typename T>
class SocketAnalyzer : public ISocketAnalyzer<T>
{
    public:
        SocketAnalyzer();
        virtual ~SocketAnalyzer();
        virtual int Analyze(const int socket, IRepository<T> &repo);
    private:
        int Process(char* data, int length, IRepository<T> &repo);
        int PrintHeader(struct iphdr* iph, int iphdrlen);
        int PrintTCP(char* buffer, struct iphdr* iph, int iphdrlen, int size);
        void PrintData(char* data, int size);
        int FillIPHeader(struct iphdr& iph, int iphdrlen, Packet &p);
        int FillTCP(char* buffer, int iphdrlen, Packet &p, int totalSize);
        int FillUDP(char* buffer, int iphdrlen, Packet &p, int totalSize);


};

#include "SocketAnalyzer.hpp"
