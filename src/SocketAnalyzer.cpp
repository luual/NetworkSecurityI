/*************************************************************
 **
 ** File Name : Analyzer.cpp
 **
 ** Purpose : 
 **
 ** Creation Date : ven. 04 nov. 2016 18:14:20 CET
 **
 ** Last Modified : ven. 04 nov. 2016 19:10:00 CET
 **
 ** Created by : Alexandre LUU <https://github.com/luual>
 **
 **************************************************************/
#include <iostream>
#include <unistd.h>
#include "SocketAnalyzer.hh"

////////////////////////////////////////
// Analyzer
int SocketAnalyzer::Analyze(const int socket)
{
    struct sockaddr addr;
    int dataSize;
    unsigned int length;
    char buffer[60000];

    while ((dataSize = recvfrom(socket, buffer, 60000, 0, &addr, &length)))
    {
        if (dataSize > 0)
        {
            Process(buffer, dataSize);
        }
        else
        {
            std::cerr << "Failed to received packet" << std::endl;
        }
        sleep(1);
    }
    return 0;
}

////////////////////////////////////////
// Print Header

int SocketAnalyzer::PrintHeader(struct iphdr* iph, int iphdrlen)
{
    struct sockaddr_in source, dest;
    source.sin_addr.s_addr = iph->saddr;
    dest.sin_addr.s_addr = iph->daddr;
    std::cout << "////////////////////" << std::endl;
    std::cout << "Ip Version : " << iph->version << std::endl;
    std::cout << "Length : " << (int)iph->ihl * 4 << std::endl;
    std::cout << "Type of service : " << (int)iph->tos << std::endl;
    std::cout << "IP Total Length : " << ntohs(iph->tot_len) << std::endl;
    std::cout << "TTL : " << (int)iph->ttl << std::endl;
    std::cout << "Protocol : " << (int)iph->protocol << std::endl;
    std::cout << "Checksum  : " << ntohs(iph->check) << std::endl;
    std::cout << "Source : " << inet_ntoa(source.sin_addr) << std::endl;
    std::cout << "Destination : " << inet_ntoa(dest.sin_addr) << std::endl;
    return 0;
}

////////////////////////////////////////
// process

int SocketAnalyzer::Process(char* data, int length)
{
    struct iphdr* iph = (struct iphdr*)data;
    int iphdrlen = iph->ihl*4;
    struct tcphdr* tcph = (struct tcphdr*)(data + iphdrlen);
    PrintHeader(iph, iphdrlen);
    std::cout << "protocol : " << (int)iph->protocol << std::endl;
    std::cout << "port : " << ntohs(tcph->source) << std::endl;
    return 0;
}

int SocketAnalyzer::Process(std::string data, int length)
{
    struct iphdr* iph = (struct iphdr*)data.c_str();
    int iphdrlen = iph->ihl*4;
    struct tcphdr* tcph = (struct tcphdr*)(data.c_str() + iphdrlen);
    std::cout << "size : " << data.length() << std::endl;
    std::cout << "protocol : " << (int)iph->protocol << std::endl;
    std::cout << "Port : " << ntohs(tcph->source) << std::endl;
    return 0;

}
