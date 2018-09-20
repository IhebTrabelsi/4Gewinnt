#ifndef NETWORK_H
#define NETWORK_H
#include <QtNetwork/QTcpSocket>
#include <QDataStream>
#include <QString>

class Network
{
public:
    Network(QString Adress, QString Port);



protected:
    QDataStream _mystream;
    QTcpSocket _mysocket;
    QString _Adress;
    QString _Port;

};

#endif // NETWORK_H
