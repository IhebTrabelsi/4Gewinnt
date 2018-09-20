#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QHostAddress>
#include <QDataStream>
#include <iostream>


class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    MyTcpServer(quint16 Port, QObject *parent = nullptr);
    
signals:
    
public slots:
    //use this functions
    void disconnectTheClient();
    void openServer();
    void disconnectTheServer();
    void sendZug(qint8 x);
    void sendParameters(qint64 parameter);
    void processRecievedInformation();
    // don't use this functions
    void closeServer();
    void newConnection();
    void disconnected();

private:
    QTcpServer *_myserver;
    QDataStream _mystream;
    QTcpSocket *_mysocket;
    quint16 _Port;
};

#endif // MYTCPSERVER_H
