/*************************************************************
**
** File Name : main_test.cpp
**
** Purpose :
**
** Creation Date : lun. 14 nov. 2016 22:17:33 CET
**
** Last Modified : ven. 18 nov. 2016 09:32:50 CET
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
// ========== END Optimization test ==========

// ========== Pcap test ==========
bool PcapStructDataTest();
bool PcapImportTest();
// ========== END Pcap test ==========


int main(void)
{
    //ThreadConcurrency();
    assert(PushRepositoryTest() == 1);
    assert(PacketIntegrityTest() == 1);
    PcapStructDataTest();
    PcapImportTest();
    //LeakTest();
    return 0;
}
