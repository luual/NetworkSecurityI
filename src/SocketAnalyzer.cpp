/*************************************************************
 **
 ** File Name : Analyzer.cpp
 **
 ** Purpose : 
 **
 ** Creation Date : ven. 04 nov. 2016 18:14:20 CET
 **
 ** Last Modified : lun. 14 nov. 2016 20:07:24 CET
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
            std::cout << "Found Something" << std::endl;
            Process(buffer, dataSize);
        }
        else
        {
            std::cerr << "Failed to received packet" << std::endl;
        }
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
    std::cout << "Size ip header : " << iphdrlen << std::endl;
    return 0;
}

////////////////////////////////////////
// PrintData

void SocketAnalyzer::PrintData(char* data, int size)
{
    for(int i = 0; i < size; ++i)
    {
        if ((data[i] >= 32) && (data[i] <= 126))
        {
            std::cout << data[i];
        }
        else
        {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

////////////////////////////////////////
// PrintTCP

int SocketAnalyzer::PrintTCP(char* buffer, struct iphdr* iph, int iphdrlen, int size)
{
    struct tcphdr* tcp = (struct tcphdr*)(buffer + iphdrlen);
    std::cout << "////////////////////////////////////////" << std::endl;
    std::cout << "TCP" << std::endl;
    std::cout << "Source Port : " << ntohs(tcp->source) << std::endl;
    std::cout << "Destination Port : " << ntohs(tcp->dest) << std::endl;
    std::cout << "Header Length : " << tcp->doff * 4 << std::endl;
    std::cout << "Checksum : " << tcp->check << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Size ip header : " << ntohs(iph->tot_len) << std::endl;
    std::cout << "IP Header" << std::endl;
    PrintData(buffer, iphdrlen);
    std::cout << "TCP Header" << std::endl;
    PrintData(buffer + iphdrlen, tcp->doff * 4);
    std::cout << "TCP body " << std::endl;
    PrintData(buffer + iphdrlen + tcp->doff * 4, size - (tcp->doff * 4 + iphdrlen));
    return 0;
}

////////////////////////////////////////
// process

int SocketAnalyzer::Process(char* data, int length)
{
    struct iphdr* iph = (struct iphdr*)data;
    int iphdrlen = iph->ihl*4;
    //struct tcphdr* tcph = (struct tcphdr*)(data + iphdrlen);
    PrintHeader(iph, iphdrlen);
    PrintTCP(data, iph, iphdrlen, length);
    return 0;
}
