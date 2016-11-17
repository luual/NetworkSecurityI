/*************************************************************
**
** File Name : main.cpp
**
** Purpose :
**
** Creation Date : jeu. 20 oct. 2016 15:04:04 CEST
**
** Last Modified : jeu. 17 nov. 2016 15:32:35 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <iostream>
#include <thread>
#include <typeinfo>
#include "Network.hh"
#include "Socket.hh"
#include "Vector.hh"
#include "SocketAnalyzer.hh"
#include "VectorRepository.hh"

int main(void)
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

    tcp_thread.join();
    udp_thread.join();
    free(repo);

    //if (socks.Connect(IPPROTO_TCP) == -1)
    //    return -1;
    //std::cout << "Socket created" << std::endl;
    //asock.Analyze(socks.GetSocket(), *repo);
    return 0;
}
