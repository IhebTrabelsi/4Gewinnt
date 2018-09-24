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
    //when you create a Client object give a Port
    MyTcpServer(quint16 Port, QObject *parent = nullptr);
    
signals:
    void serverIsConnectedToClient();
    void AntwortAufZug(qint8 Cmd, qint8 Statuscode); // Antwort auf Zug OR recived Zug
    void AntwortAufAnfrage(qint8 Cmd, qint8 Statuscode); // Antwort auf anfrage
    void AntwortAufSpielfeldParameter(qint8 Cmd, qint8 xGridSize, qint8 yGridSize, qint8 Rundenzahl, qint8 Beginnender); // Antwort auf spielfeld parameter
    void AntwortAufRundenbeginn(qint8 Cmd, qint8 Rundenummer, qint8 BeginnenderRunde); //Antwort auf Rundenbeginn
    void Fehler(qint8 f);
public slots:
    //use this functions//////////////////////
    void disconnectTheClient(); // disconnect the client from the server (! client reconnects automatically)
    void openServer(); // opens the Server for possible connections
    void disconnectTheServer(); // kicks the client out and closes the server
    void sendParameters(qint8 Cmd, qint8 length, qint8 var1, qint8 var2=0, qint8 var3=0, qint8 var4=0);    //sends all Parameters either 1 , 2 or 4 parameters
    // don't use this functions///////////////////
    void processRecievedInformation(); // recive Information
    void closeServer(); // no longer accept connections but the client stays in
    void newConnection(); // is called when a client connects
    void disconnected(); // is called when a client disconnects

private:
    QTcpServer *_myserver;
    QDataStream _mystream;
    QTcpSocket *_mysocket;
    quint16 _Port;
};

#endif // MYTCPSERVER_H
