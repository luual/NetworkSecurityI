/*************************************************************
**
** File Name : IAnalyzer.hh
**
** Purpose :
**
** Creation Date : ven. 04 nov. 2016 17:49:52 CET
**
** Last Modified : jeu. 17 nov. 2016 02:44:51 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <unistd.h>
#include "IRepository.hh"

struct IPHeader
{
    int version;
    int length;
    int typeOfService;
    int totalLength;
    int ttl;
    int protocol;
    int checksum;
    char *source;
    char *destination;
    char *data;
    int size;
    void Clear()
    {
        if (source != NULL)
            free(source);
        if (destination != NULL)
            free(destination);
        if (data != NULL)
            free(data);
    }
};

struct PacketHeader
{
    int length;
    int sourcePort;
    int destPort;
    int checksum;
    char *data;
    void Clear()
    {
        if (data != NULL)
            free(data);
    }
};

struct PacketData
{
    int length;
    char *data;
    void Clear()
    {
        if (data != NULL)
            free(data);
    }
};

struct Packet
{
    struct IPHeader ipHeader;
    PacketHeader header;
    PacketData data;
    void Clear()
    {
        ipHeader.Clear();
        header.Clear();
        data.Clear();
    }
};

template <typename T>
class ISocketAnalyzer
{
    public:
        virtual ~ISocketAnalyzer(){}
        virtual int Analyze(const int socket, IRepository<T> &repo) = 0;
};
