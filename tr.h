#ifndef TR_H
#define TR_H

#include <QObject>
#include <QThread>
#include "dnsclass.h"
#include <QDnsLookup>
class Tr : public QThread
{
    Q_OBJECT
public:
    explicit Tr(QThread *parent = nullptr);
    explicit Tr(QDnsLookup* dnsNew);
    QDnsLookup* dnsTr;
    void run();
signals:

public slots:
};

#endif // TR_H
