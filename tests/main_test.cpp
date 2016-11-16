/*************************************************************
**
** File Name : main_test.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 22:17:33 CET
**
** Last Modified : mer. 16 nov. 2016 22:33:50 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <cassert>

bool PushRepositoryTest();
int ThreadConcurrency();

int main(void)
{
    //ThreadConcurrency();
    assert(PushRepositoryTest() == 1);
    return 0;
}
