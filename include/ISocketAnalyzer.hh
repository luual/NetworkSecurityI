/*************************************************************
**
** File Name : IAnalyzer.hh
**
** Purpose :
**
** Creation Date : ven. 04 nov. 2016 17:49:52 CET
**
** Last Modified : ven. 04 nov. 2016 18:18:40 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <unistd.h>

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
    int size;
    void Clear()
    {
        free(source);
        free(destination);
    }
};

struct PacketHeader
{
    int length;
    char *data;
    void Clear()
    {
        free(data);
    }
};

struct PacketData
{
    int length;
    char *data;
    void Clear()
    {
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

class ISocketAnalyzer
{
    public:
        virtual int Analyze(const int socket) = 0;
};
