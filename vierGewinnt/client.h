#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <QtNetwork/QTcpSocket>
#include <QDataStream>
#include <QObject>
#include <cassert>
#include <QDebug>
#include <QString>


class Client : public QObject
{
    Q_OBJECT
public:
    //when you create a Client object give an Adress and a Port
    Client(QString Adress, quint16 Port, QObject *parent=nullptr);
signals:
    void clientIsConnectedtoServer(); // when a Client connects to the server
    void AntwortAufZug(quint8 Cmd, quint8 Statuscode); // Antwort auf Zug OR recived Zug
    void AntwortAufAnfrage(quint8 Cmd, quint8 Statuscode); // Antwort auf anfrage
    void AntwortAufSpielfeldParameter(quint8 xGridSize, quint8 yGridSize, quint8 Rundenzahl, quint8 Beginnender); // Antwort auf spielfeld parameter
    void AntwortAufRundenbeginn(quint8 Cmd, quint8 Rundenummer, quint8 BeginnenderRunde); //Antwort auf Rundenbeginn
    void Fehler(quint8 f);
    void sendMessage(QString message);
public slots:
    // you can call these functions//////////////////////

    // connects to server if you have disconnected before (when you first creat an object the Server is initiated automaticly)
    void connectToServer();
    //sends all Parameters either 1 , 2 or 4 parameters
    void sendParameters(quint8 Cmd, quint8 length, quint8 var1, quint8 var2=0, quint8 var3=0, quint8 var4=0);
    //disconnects from server (client tries to reconnect automatically)
    void disconnectFromServer();


    //don't call these functions these are class intern///////////////////////
    void enableConnection(); // is called when the server accepts the connection
    void processRecievedInformation(); // recieves Infomation
    void disconnected(); // is called when the connection is interrupted

private:
    QDataStream _mystream;
    QTcpSocket *_mysocket=nullptr;
    QString _Adress;
    quint16 _Port;


};

#endif // CLIENT_H
