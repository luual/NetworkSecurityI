/*************************************************************
**
** File Name : main_test.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 22:17:33 CET
**
** Last Modified : lun. 14 nov. 2016 23:29:29 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <thread>
#include <iostream>
#include "Vector.hh"

int Add(Vector<int> &v, int i);

int main(void)
{
    Vector<int> v;
    std::thread f1(Add, std::ref(v), 9);
    std::thread f2(Add, std::ref(v), 19);
    std::thread f3(Add, std::ref(v), 29);
    std::thread f4(Add, std::ref(v), 39);
    f1.join();
    f2.join();
    f3.join();
    f4.join();
    const std::vector<int> t = v.GetAll();
    for(std::vector<int>::const_iterator it = t.begin(); it != t.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
