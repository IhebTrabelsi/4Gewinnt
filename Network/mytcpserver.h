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
    /**
     * @brief is called when a player enters the game and Closes the server after it
     */
    void newConnection();
    void disconnectTheClient();
    void toggleAcceptingConnections();
    void closeServer();
    void disconnected();
    void socketError();
    void sendZug(qint8 x);
    void sendParameters(qint64 parameter);
    void processRecievedInformation();

private:
    QTcpServer *_myserver;
    QDataStream _mystream;
    QTcpSocket *_mysocket;
    quint16 _Port;
};

#endif // MYTCPSERVER_H
