/*************************************************************
**
** File Name : main_test.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 22:17:33 CET
**
** Last Modified : jeu. 17 nov. 2016 16:20:49 CET
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

// ========== Optimization test ==========
void LeakTest();
// ========== Optimization test ==========

int main(void)
{
    //ThreadConcurrency();
    assert(PushRepositoryTest() == 1);
    assert(PacketIntegrityTest() == 1);
    LeakTest();
    return 0;
}
