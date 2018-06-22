#include <QCoreApplication>
#include <QDnsLookup>
#include <QDnsDomainNameRecord>
#include <QDnsMailExchangeRecord>
#include <QDnsServiceRecord>
#include <QThread>
#include <QHostAddress>
#include <QDebug>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDnsLookup* dns=new QDnsLookup();
    QHostAddress adress=QHostAddress("8.8.8.8");
    QThread* tr=new QThread;
    dns->setNameserver(adress);
    dns->setName("google.com");
    dns->setType(QDnsLookup::ANY);
    dns->moveToThread(tr);
    tr->start();
    dns->lookup();
    int fin=1;
    while (fin){
        if(dns->isFinished()){
           qDebug()<< "Dns finished lookup";
           foreach(const QDnsHostAddressRecord &record,dns->hostAddressRecords()){
               qDebug()<<record.value().toString();
               qDebug()<<record.name();
           }
           dns->setName("google.com");
           dns->setType(QDnsLookup::ANY);
           dns->lookup();
           fin=0;
        }
        else{
            fin=1;
        }
        QThread::msleep(1000);
    }
    return a.exec();
}
