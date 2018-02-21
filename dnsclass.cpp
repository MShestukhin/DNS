#include "dnsclass.h"

DnsClass::DnsClass(QObject *parent) : QObject(parent)
{
    dns=new QDnsLookup();
    QHostAddress adress=QHostAddress("192.168.1.1");
    dns->setNameserver(adress);
}

void DnsClass::start(){
    dns->setName("google.com");
    dns->setType(QDnsLookup::ANY);
    dns->lookup();
}
