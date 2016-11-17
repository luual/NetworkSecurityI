/*************************************************************
**
** File Name : ThreadTest.cpp
**
** Purpose : 
**
** Creation Date : mer. 16 nov. 2016 22:20:04 CET
**
** Last Modified : jeu. 17 nov. 2016 15:26:27 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <thread>
#include <iostream>
#include "Vector.hh"
#include "SocketAnalyzer.hh"

int Add(Vector<Packet> &v, int i);

int ThreadConcurrency()
{
    Vector<Packet> v;
    std::thread f1(Add, std::ref(v), 9);
    std::thread f2(Add, std::ref(v), 19);
    std::thread f3(Add, std::ref(v), 29);
    std::thread f4(Add, std::ref(v), 39);
    f1.join();
    f2.join();
    f3.join();
    f4.join();
    const std::vector<Packet> t = v.GetAll();
    for(std::vector<Packet>::const_iterator it = t.begin(); it != t.end(); ++it)
    {
        std::cout << it->ipHeader.protocol << std::endl;
    }
    return 0;
}
