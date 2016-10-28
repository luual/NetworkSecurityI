/*************************************************************
**
** File Name : ISocket.hh
**
** Purpose : 
**
** Creation Date : jeu. 27 oct. 2016 21:56:45 CEST
**
** Last Modified : ven. 28 oct. 2016 11:09:35 CEST
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
        virtual int Connect() = 0;
        virtual int Receive() = 0;
        virtual int Send() = 0;
};
