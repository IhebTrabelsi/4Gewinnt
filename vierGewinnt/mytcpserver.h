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
    void AntwortAufZug(quint8 Cmd, quint8 Statuscode); // Antwort auf Zug OR recived Zug
    void AntwortAufAnfrage(quint8 Cmd, quint8 Statuscode); // Antwort auf anfrage
    /*not needed*/void AntwortAufSpielfeldParameter(quint8 Cmd, quint8 xGridSize, quint8 yGridSize, quint8 Rundenzahl, quint8 Beginnender); // Antwort auf spielfeld parameter
    void AntwortAufRundenbeginn(quint8 Cmd, quint8 Rundenummer, quint8 BeginnenderRunde); //Antwort auf Rundenbeginn
    void Fehler(quint8 f);
    void sendMessage(QString message);
public slots:
    //use this functions//////////////////////
    void disconnectTheClient(); // disconnect the client from the server (! client reconnects automatically)
    void openServer(); // opens the Server for possible connections
    void disconnectTheServer(); // kicks the client out and closes the server
    void sendParameters(quint8 Cmd, quint8 length, quint8 var1, quint8 var2=0, quint8 var3=0, quint8 var4=0);    //sends all Parameters either 1 , 2 or 4 parameters
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
