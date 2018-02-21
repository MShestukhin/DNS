#ifndef DNSCLASS_H
#define DNSCLASS_H

#include <QObject>
#include <QDnsLookup>
#include <QDnsDomainNameRecord>
#include <QDnsMailExchangeRecord>
#include <QDnsServiceRecord>
#include <QHostAddress>

class DnsClass : public QObject
{
    Q_OBJECT
public:
    explicit DnsClass(QObject *parent = nullptr);
    QDnsLookup* dns;
    void start();
signals:

public slots:
};

#endif // DNSCLASS_H
