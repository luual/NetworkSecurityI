/*************************************************************
**
** File Name : main_test.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 22:17:33 CET
**
** Last Modified : mer. 16 nov. 2016 23:04:17 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <cassert>

// ========== Repository test ==========
bool PushRepositoryTest();
bool PacketIntegrityTest();
// ========== END Repository test ==========

int ThreadConcurrency();

int main(void)
{
    //ThreadConcurrency();
    assert(PushRepositoryTest() == 1);
    assert(PacketIntegrityTest() == 1);
    return 0;
}
