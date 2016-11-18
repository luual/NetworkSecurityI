/*************************************************************
**
** File Name : PcapTest.cpp
**
** Purpose : 
**
** Creation Date : ven. 18 nov. 2016 09:02:56 CET
**
** Last Modified : ven. 18 nov. 2016 11:55:52 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#include <cassert>
#include <iostream>
#include <thread>
#include <typeinfo>

#include "PcapPacketIEFormat.hh"
#include "VectorRepository.hh"
#include "Network.hh"
#include "Socket.hh"
#include "Vector.hh"
#include "SocketAnalyzer.hh"
#include "VectorRepository.hh"


bool PcapStructDataTest()
{
    assert(sizeof(PcapHeader) == 24);
    assert(sizeof(RecordMetaData) == 16);
    return true;
}

bool PcapImportTest()
{
    IRepository<Packet> *repo = new VectorRepository<Packet>();
    auto start_socket = [](IRepository<Packet> &repo, int protocol){
        ISocket *socket = new Socket();
        SocketAnalyzer<Packet> sa;
        if (socket->Connect(protocol) == -1){
            free(socket);
        }
        else {
        sa.Analyze(socket->GetSocket(), repo);
        free(socket);
        }
    };

    std::thread tcp_thread(start_socket, std::ref(*repo), IPPROTO_TCP);
    std::thread udp_thread(start_socket, std::ref(*repo), IPPROTO_UDP);

    bool flag = true;
    while (flag == true)
    {
        if (repo->Size() > 10)
        {
            flag = false;
            PcapPacketIEFormat a;
            a.Export(*repo, "testcorgi.pcap");
            std::cout << "EXPORT" << std::endl;
        }
        std::cout << "Wait 2 seconds" << std::endl;
        sleep(2);
    }

    tcp_thread.join();
    udp_thread.join();

    return true;
}

