/*************************************************************
 **
 ** File Name : Analyzer.cpp
 **
 ** Purpose :
 **
 ** Creation Date : ven. 04 nov. 2016 18:14:20 CET
 **
 ** Last Modified : mer. 16 nov. 2016 23:50:28 CET
 **
 ** Created by : Alexandre LUU <https://github.com/luual>
 **
 **************************************************************/

#include <iostream>

template <typename T>
SocketAnalyzer<T>::SocketAnalyzer()
{
}

template <typename T>
SocketAnalyzer<T>::~SocketAnalyzer()
{
}


////////////////////////////////////////
// Analyzer
template <typename T>
int SocketAnalyzer<T>::Analyze(const int socket, IRepository<T> &repo)
{
    struct sockaddr addr;
    int dataSize;
    unsigned int length;
    char buffer[60000];

    while ((dataSize = recvfrom(socket, buffer, 60000, 0, &addr, &length)))
    {
        if (dataSize > 0)
        {
            //std::cout << "Found Something" << std::endl;
            Process(buffer, dataSize, repo);
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

template <typename T>
int SocketAnalyzer<T>::PrintHeader(struct iphdr* iph, int iphdrlen)
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

template <typename T>
void SocketAnalyzer<T>::PrintData(char* data, int size)
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

template <typename T>
int SocketAnalyzer<T>::PrintTCP(char* buffer, struct iphdr* iph, int iphdrlen, int size)
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

template <typename T>
int SocketAnalyzer<T>::FillIPHeader(struct iphdr &iph, int iphdrlen, Packet &p)
{
    struct sockaddr_in source;
    //struct sockaddr_in dest;
    source.sin_addr.s_addr = iph.saddr;
    //dest.sin_addr.s_addr = iph.daddr;
    p.ipHeader.version = iph.version;
    p.ipHeader.length = iph.ihl * 4;
    p.ipHeader.typeOfService = iph.tos;
    p.ipHeader.totalLength = ntohs(iph.tot_len);
    p.ipHeader.ttl = iph.ttl;
    p.ipHeader.protocol = iph.protocol;
    p.ipHeader.checksum = ntohs(iph.check);
    p.ipHeader.source = strdup(inet_ntoa(source.sin_addr));
    p.ipHeader.destination = strdup(inet_ntoa(source.sin_addr));
    p.ipHeader.size = iphdrlen;
    return 0;
}

template <typename T>
int SocketAnalyzer<T>::FillTCP(char* buffer, int iphdrlen, Packet &p, int totalSize)
{
    struct tcphdr* tcp = (struct tcphdr*)(buffer + iphdrlen);
    p.header.length = tcp->doff * 4;
    p.header.sourcePort = ntohs(tcp->source);
    p.header.destPort = ntohs(tcp->dest);
    p.header.checksum = tcp->check;
    p.header.data = strndup(buffer + iphdrlen, tcp->doff * 4);
    p.data.length = totalSize - iphdrlen - tcp->doff * 4;
    p.data.data = strndup(buffer + iphdrlen + tcp->doff * 4, totalSize - iphdrlen - tcp->doff * 4);
    return 0;
}

template <typename T>
int SocketAnalyzer<T>::FillUDP(char* buffer, int iphdrlen, Packet &p, int totalSize)
{
    struct udphdr* udp = (struct udphdr*)(buffer + iphdrlen);
    p.header.length = ntohs(udp->len);
    p.header.sourcePort = ntohs(udp->source);
    p.header.destPort = ntohs(udp->dest);
    p.header.checksum = ntohs(udp->check);
    p.header.data = strndup(buffer + iphdrlen, sizeof(udp));
    p.data.length = totalSize - sizeof(udp) - iphdrlen;
    p.data.data = strndup(buffer + sizeof(udp) + iphdrlen, p.data.length);
    return 0;
}

template<typename T>
int SocketAnalyzer<T>::FillICMP(char *buffer, int iphdrlen, Packet &p, int totalSize)
{
    struct icmphdr* icmp = (struct icmphdr*)(buffer + iphdrlen);
    p.header.type = icmp->type;
    p.header.code = icmp->code;
    p.header.checksum = ntohs(icmp->checksum);
    p.header.data = strndup(buffer + iphdrlen, sizeof(icmp));
    p.data.length = totalSize - sizeof(icmp) - iphdrlen;
    p.data.data = strndup(buffer + iphdrlen + sizeof(icmp), p.data.length);
    return 0;
}

////////////////////////////////////////
// process

template <typename T>
int SocketAnalyzer<T>::Process(char* data, int length, IRepository<T> &repo)
{
    //std::cout << repo.Size() << std::endl;
    Packet p;
    struct iphdr* iph = (struct iphdr*)data;
    int iphdrlen = iph->ihl*4;
    //struct tcphdr* tcph = (struct tcphdr*)(data + iphdrlen);
    //PrintHeader(iph, iphdrlen);
    FillIPHeader(*iph, iphdrlen, p);
    p.ipHeader.data = strndup(data, iphdrlen);
    switch (p.ipHeader.protocol)
    {
        case 1:
            FillTCP(data, iphdrlen, p, length);
            break;
        case 6:
            FillTCP(data, iphdrlen, p, length);
            break;
        case 17:
            FillUDP(data, iphdrlen, p, length);
            break;
    }
    repo.Insert(p);
    //PrintTCP(data, iph, iphdrlen, length);
    //std::cout << "==============RAW==============" << std::endl;
    //for (int i = 0; i < length; ++i)
    //{
    //    if (data[i] >= 32 && data[i] < 127)
    //    {
    //        std::cout << data[i];
    //    }
    //    else
    //    {
    //        std::cout << ",";
    //    }
    //}
    //std::cout << std::endl;
    return 0;
}
