#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <QtNetwork/QTcpSocket>
#include <QDataStream>
#include <QObject>
#include <cassert>
#include <QDebug>
#include <QString>

/**
 * @file client.h Header file for Client class
 * @author Chedi Fassi
 **/


class Client : public QObject
{
    Q_OBJECT
public:
    //
    /**
     * @brief Client
     * @param Adress
     * @param Port
     * @param parent
     * when you create a Client object give an Adress and a Port
     */
    Client(QString Adress, quint16 Port, QObject *parent=nullptr);
    ~Client();
signals:
    /**
     * @brief clientIsConnectedtoServer
     */
    void clientIsConnectedtoServer(); // when a Client connects to the server
    /**
     * @brief AntwortAufZug
     * @param Cmd
     * @param Statuscode
     */
    void AntwortAufZug(quint8 Cmd, quint8 Statuscode); // Antwort auf Zug OR recived Zug
    /**
     * @brief AntwortAufAnfrage
     * @param Cmd
     * @param Statuscode
     */
    void AntwortAufAnfrage(quint8 Cmd, quint8 Statuscode); // Antwort auf anfrage
    /**
     * @brief AntwortAufSpielfeldParameter
     * @param xGridSize
     * @param yGridSize
     * @param Rundenzahl
     * @param Beginnender
     */
    void AntwortAufSpielfeldParameter(quint8 xGridSize, quint8 yGridSize, quint8 Rundenzahl, quint8 Beginnender); // Antwort auf spielfeld parameter
    /**
     * @brief AntwortAufRundenbeginn
     * @param Rundenummer
     * @param BeginnenderRunde
     */
    void AntwortAufRundenbeginn(quint8 Rundenummer, quint8 BeginnenderRunde); //Antwort auf Rundenbeginn
    /**
     * @brief Fehler
     * @param f
     */
    void Fehler(quint8 f);
    /**
     * @brief AntwortChat
     * @param message
     */
    void AntwortChat(QString message);
    /**
     * @brief sendMessage
     * @param message
     */
    void sendMessage(QString message);
public slots:
    // you can call these functions//////////////////////


    /**
     * @brief connectToServer
     *  connects to server if you have disconnected before or the first time
     */
    void connectToServer();

    /**
     * @brief sendParameters
     * @param Cmd
     * @param length
     * @param var1
     * @param var2
     * @param var3
     * @param var4
     * sends all Parameters either 1 , 2 or 4 parameters
     */
    void sendParameters(quint8 Cmd, quint8 length, quint8 var1, quint8 var2=0, quint8 var3=0, quint8 var4=0);
    /**
     * @brief sendChat
     * @param Cmd
     * @param message
     * sends chat message
     */
    void sendChat(quint8 Cmd, QString message);
    /**
     * @brief disconnectFromServer
     * disconnects from server (client tries to reconnect automatically)
     */
    void disconnectFromServer();

    //don't call these functions these are class intern///////////////////////
    /**
     * @brief enableConnection
     * is called when the server accepts the connection
     */
    void enableConnection(); //
    /**
     * @brief processRecievedInformation
     * recieves all Information
     */
    void processRecievedInformation(); //
    /**
     * @brief disconnected
     * is called when the connection is interrupted
     */
    void disconnected(); //

private:
    QDataStream _mystream;  
    QTcpSocket *_mysocket=nullptr;
    QString _Adress;
    quint16 _Port;


};

#endif // CLIENT_H
