/*************************************************************
**
** File Name : IAnalyzer.hh
**
** Purpose :
**
** Creation Date : ven. 04 nov. 2016 17:49:52 CET
**
** Last Modified : jeu. 17 nov. 2016 15:32:08 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <unistd.h>
#include "IRepository.hh"
#include "IFinalizer.hh"

struct IPHeader
{
    int version;
    int length;
    int typeOfService;
    int totalLength;
    int ttl;
    int protocol;
    int checksum;
    char *source = NULL;
    char *destination = NULL;
    char *data = NULL;
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
    int type;
    int code;
    char *data = NULL;
    void Clear()
    {
        if (data != NULL)
            free(data);
    }
};

struct PacketData
{
    int length;
    char *data = NULL;
    void Clear()
    {
        if (data != NULL)
            free(data);
    }
};

struct Packet : public IFinalizer
{
    struct IPHeader ipHeader;
    PacketHeader header;
    PacketData data;
    void Finalize()
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
