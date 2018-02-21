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
    QHostAddress adress=QHostAddress("192.168.1.1");
    QThread* tr=new QThread;
    dns->setNameserver(adress);
    dns->setName("google.com");
    dns->setType(QDnsLookup::ANY);
    dns->moveToThread(tr);
    tr->start();
    dns->lookup();
    while (true) {
        if(dns->isFinished()){
           qDebug()<< "Dns finished lookup";
           foreach(const QDnsHostAddressRecord &record,dns->hostAddressRecords()){
                       qDebug()<<"tut";
                       qDebug()<<record.value().toString();
                       qDebug()<<record.name();
           }
           dns->setName("mail.ru");
           dns->setType(QDnsLookup::ANY);
           dns->lookup();
        }
        else{
            qDebug()<<"lll";
        }
        QThread::msleep(1000);

        }
    return a.exec();
}
