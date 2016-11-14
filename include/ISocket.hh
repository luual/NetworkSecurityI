/*************************************************************
**
** File Name : ISocket.hh
**
** Purpose :
**
** Creation Date : jeu. 27 oct. 2016 21:56:45 CEST
**
** Last Modified : sam. 12 nov. 2016 19:41:07 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#pragma once
#include <string>

class ISocket
{
    public:
        virtual ~ISocket(){}
        //virtual int Connect(const std::string hostname, const int port) = 0;
        virtual int Connect(int protocol) = 0;
        virtual int GetSocket() const = 0;
};
