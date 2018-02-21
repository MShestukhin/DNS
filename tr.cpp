#include "tr.h"
#include <QThread>
#include <QDebug>
Tr::Tr(QThread *parent) : QThread(parent)
{

}

Tr::Tr(QDnsLookup *dnsNew){
    dnsTr=dnsNew;
}

void Tr::run(){
    while(1){
    if(dnsTr->isFinished()){
        qDebug()<<"a";
    }
    else{
        qDebug()<<"l";
    }
    QThread::msleep(100);
    }
}
