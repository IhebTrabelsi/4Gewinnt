#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <QtNetwork/QTcpSocket>
#include <QDataStream>
#include <QObject>
#include <cassert>
#include <QDebug>

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QString Adress, quint16 Port, QObject *parent=nullptr);
signals:

public slots:
    void connectToServer();

    void sendParameters(qint64 parameter);

    void processRecievedInformation();

    void sendZug(qint8 x);

    void enableConnection();

    void disconnected();

    void socketError();

    void disconnectFromServer();

private:
    QDataStream _mystream;
    QTcpSocket *_mysocket=nullptr;
    QString _Adress;
    quint16 _Port;


};

#endif // CLIENT_H
