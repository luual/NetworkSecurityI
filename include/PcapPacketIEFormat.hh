/*************************************************************
**
** File Name : PcapPacketIEFormat.hh
**
** Purpose : 
**
** Creation Date : jeu. 17 nov. 2016 23:36:27 CET
**
** Last Modified : ven. 18 nov. 2016 13:35:55 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/
#pragma once

#include <string>
#include "IRepository.hh"
#include "SocketAnalyzer.hh" // include to have Packet needs to be change
#define PCAP_MAGICNUMBER 0xa1b2c3d4
#define PCAP_MAJORVERSION 0x02
#define PCAP_MINORVERSION 0x04
#define PCAP_ZONE 0x0
#define PCAP_ACCURACY 0x0
#define PCAP_SIZE 0x40000
#define PCAP_TYPE 0x1

struct PcapHeader
{
    public:
    int magicNumber = PCAP_MAGICNUMBER;  ;
    short versionMajor = PCAP_MAJORVERSION;;
    short versionMinor = PCAP_MINORVERSION;;
    int zone = PCAP_ZONE;
    int accuracy = PCAP_ACCURACY;
    int size = PCAP_SIZE;
    int type = PCAP_TYPE;
};

struct RecordMetaData
{
    int tsSec = 0; // Timestamp in sec
    int tsUsec = 0; // Timestamp in sec
    int incLength = 0; // length saved in file
    int origLength = 0; // original length
};

// Class to Import / Export Pcap with Packet as Data
class PcapPacketIEFormat
{
    public:
        PcapPacketIEFormat();
        virtual ~PcapPacketIEFormat();
        virtual void Export(IRepository<Packet> &repo, std::string filename);
        virtual IRepository<Packet>* Import(std::string filepath);
    private:
        void WriteHeader(PcapHeader p, std::string filename);
        void WriteMetaData(RecordMetaData rmd, std::string filename);
        void WriteMetaData(Packet p, std::string filename);
};
