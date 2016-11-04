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

class ISocketAnalyzer
{
    public:
        virtual int Analyze(const int socket) = 0;
};
