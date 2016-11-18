/*************************************************************
**
** File Name : PcapPacketIEFormat.cpp
**
** Purpose : 
**
** Creation Date : ven. 18 nov. 2016 08:48:44 CET
**
** Last Modified : ven. 18 nov. 2016 13:58:05 CET
**
** Created by : Alexandre LUU <https://github.com/luual>
**
**************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include "PcapPacketIEFormat.hh"
#include "VectorRepository.hh"

PcapPacketIEFormat::PcapPacketIEFormat()
{
}

PcapPacketIEFormat::~PcapPacketIEFormat()
{
}

void PcapPacketIEFormat::WriteHeader(PcapHeader p, std::string filename)
{
    std::fstream fs;
    fs.open(filename, std::fstream::out);
    char *buffer = new char[4];
    buffer[0] = static_cast<char>(p.magicNumber);
    buffer[1] = static_cast<char>(p.magicNumber >> 8);
    buffer[2] = static_cast<char>(p.magicNumber >> 16);
    buffer[3] = static_cast<char>(p.magicNumber >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(p.versionMajor);
    buffer[1] = static_cast<char>(p.versionMajor >> 8);
    fs.write(buffer, 2);
    buffer[0] = static_cast<char>(p.versionMinor);
    buffer[1] = static_cast<char>(p.versionMinor >> 8);
    fs.write(buffer, 2);
    buffer[0] = static_cast<char>(p.zone);
    buffer[1] = static_cast<char>(p.zone >> 8);
    buffer[2] = static_cast<char>(p.zone >> 16);
    buffer[3] = static_cast<char>(p.zone >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(p.accuracy);
    buffer[1] = static_cast<char>(p.accuracy >> 8);
    buffer[2] = static_cast<char>(p.accuracy >> 16);
    buffer[3] = static_cast<char>(p.accuracy >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(p.size);
    buffer[1] = static_cast<char>(p.size >> 8);
    buffer[2] = static_cast<char>(p.size >> 16);
    buffer[3] = static_cast<char>(p.size >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(p.type);
    buffer[1] = static_cast<char>(p.type >> 8);
    buffer[2] = static_cast<char>(p.type >> 16);
    buffer[3] = static_cast<char>(p.type >> 24);
    fs.write(buffer, 4);
    delete[] buffer;
}

void PcapPacketIEFormat::WriteMetaData(RecordMetaData rmd, std::string filename)
{
    std::fstream fs;
    fs.open(filename, std::fstream::app);
    char *buffer = new char[4];
    buffer[0] = static_cast<char>(rmd.tsSec);
    buffer[1] = static_cast<char>(rmd.tsSec >> 8);
    buffer[2] = static_cast<char>(rmd.tsSec >> 16);
    buffer[3] = static_cast<char>(rmd.tsSec >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(rmd.tsUsec);
    buffer[1] = static_cast<char>(rmd.tsUsec >> 8);
    buffer[2] = static_cast<char>(rmd.tsUsec >> 16);
    buffer[3] = static_cast<char>(rmd.tsUsec >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(rmd.incLength);
    buffer[1] = static_cast<char>(rmd.incLength >> 8);
    buffer[2] = static_cast<char>(rmd.incLength >> 16);
    buffer[3] = static_cast<char>(rmd.incLength >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(rmd.origLength);
    buffer[1] = static_cast<char>(rmd.origLength >> 8);
    buffer[2] = static_cast<char>(rmd.origLength >> 16);
    buffer[3] = static_cast<char>(rmd.origLength >> 24);
    fs.write(buffer, 4); 
    delete[] buffer;
}

void PcapPacketIEFormat::WriteMetaData(Packet p, std::string filename)
{
    std::fstream fs;
    RecordMetaData rmd;
    rmd.incLength = p.ipHeader.length + p.header.length + p.data.length;
    rmd.origLength = p.ipHeader.length + p.header.length + p.data.length;
    fs.open(filename, std::fstream::app);
    char *buffer = new char[4];
    buffer[0] = static_cast<char>(rmd.tsSec);
    buffer[1] = static_cast<char>(rmd.tsSec >> 8);
    buffer[2] = static_cast<char>(rmd.tsSec >> 16);
    buffer[3] = static_cast<char>(rmd.tsSec >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(rmd.tsUsec);
    buffer[1] = static_cast<char>(rmd.tsUsec >> 8);
    buffer[2] = static_cast<char>(rmd.tsUsec >> 16);
    buffer[3] = static_cast<char>(rmd.tsUsec >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(rmd.incLength);
    buffer[1] = static_cast<char>(rmd.incLength >> 8);
    buffer[2] = static_cast<char>(rmd.incLength >> 16);
    buffer[3] = static_cast<char>(rmd.incLength >> 24);
    fs.write(buffer, 4);
    buffer[0] = static_cast<char>(rmd.origLength);
    buffer[1] = static_cast<char>(rmd.origLength >> 8);
    buffer[2] = static_cast<char>(rmd.origLength >> 16);
    buffer[3] = static_cast<char>(rmd.origLength >> 24);
    fs.write(buffer, 4); 
    delete[] buffer;
}

void printRawData(char *buffer, int length)
{
    for (int i = 0; i < length; ++i)
    {
        if ((buffer[i] >= 32) && (buffer[i] < 127))
        {
            std::cout << buffer[i];
        }
        else
        {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

void PcapPacketIEFormat::Export(IRepository<Packet> &repo, std::string filename)
{
    std::fstream fs;
    PcapHeader a;
    WriteHeader(a, filename);
    std::map<std::string, std::string> hwaddrmap;
    char line[500];
    char ipaddr[100];
    int hw_type;
    int flag;
    char hwaddr[20];
    char mask[100];
    char device[100];
    FILE *arptable = fopen("/proc/net/arp", "r");
    if (arptable != NULL)
    {
        fgets(line, sizeof(line), arptable);
        while(fgets(line, sizeof(line), arptable))
        {
            sscanf(line, "%s 0x%x 0x%x %s %s %s\n",
                    ipaddr,
                    &hw_type,
                    &flag,
                    hwaddr,
                    mask,
                    device);
            hwaddrmap.insert(std::pair<std::string, std::string>(ipaddr, hwaddr));
        }
    }
    /*
    for(std::map<std::string, std::string>::iterator it = hwaddrmap.begin(); it != hwaddrmap.end(); ++it)
    {
        std::cout << "[" << it->first << "] : [" << hwaddrmap[it->first] << "]" << std::endl;
    }
    */
    for (int i = 0; i < repo.Size(); ++i)
    {
        Packet p = repo.GetByIndex(i);
        WriteMetaData(p, filename);
        fs.open(filename, std::fstream::app);
        int length = p.ipHeader.length + p.header.length + p.data.length;
        std::cout << "Packet length : " << length << std::endl;

        fs.write(p.ipHeader.data, p.ipHeader.length);
        fs.write(p.header.data, p.header.length);
        fs.write(p.data.data, p.data.length);
    }
}


IRepository<Packet>* PcapPacketIEFormat::Import(std::string filepath)
{
    VectorRepository<Packet>  *vrepo = new VectorRepository<Packet>();
    std::fstream fs;
    fs.open(filepath);
    char buffer[5000];
    char data[5000];
    if(fs.is_open() == true)
    {
        fs.read(buffer, sizeof(PcapHeader) + sizeof(RecordMetaData));
        PcapHeader *h = (PcapHeader*)(buffer);
        RecordMetaData *rmd = (RecordMetaData*) (buffer + sizeof(PcapHeader));
        // Print Data
        /*
        std::cout << std::hex << h->magicNumber << std::endl;
        std::cout << std::hex << h->versionMajor << std::endl;
        std::cout << std::hex << h->versionMinor << std::endl;
        std::cout << std::hex << h->zone << std::endl;
        std::cout << std::hex << h->accuracy << std::endl;
        std::cout << std::hex << h->size << std::endl;
        std::cout << std::hex << h->type << std::endl;

        std::cout << std::hex << rmd->tsSec << std::endl;
        std::cout << std::hex << rmd->tsUsec << std::endl;
        std::cout << std::hex << rmd->incLength << std::endl;
        std::cout << std::hex << rmd->origLength << std::endl;
        fs.read(data, rmd->incLength);
        for (int i = 0; i < rmd->incLength; ++i)
        {
            if ((data[i] >= 32) && (data[i] < 127))
            {
                std::cout << data[i];
            }
            else
            {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
        */
    }
    else
    {
        std::cerr << "Impossible to open the file" << std::endl;
    }
    return vrepo;
}
