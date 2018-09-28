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
    /**
     * @brief MyTcpServer
     * @param Port
     * @param parent
     */
    MyTcpServer(quint16 Port, QObject *parent = nullptr);
    ~MyTcpServer();
signals:
    /**
     * @brief serverIsConnectedToClient
     */
    void serverIsConnectedToClient();
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
     *
     */
    void AntwortAufAnfrage(quint8 Cmd, quint8 Statuscode); // Antwort auf anfrage
    /**
     * @brief AntwortAufSpielfeldParameter
     * @param Cmd
     * @param xGridSize
     * @param yGridSize
     * @param Rundenzahl
     * @param Beginnender
     * not needed
     */
    void AntwortAufSpielfeldParameter(quint8 Cmd, quint8 xGridSize, quint8 yGridSize, quint8 Rundenzahl, quint8 Beginnender); // Antwort auf spielfeld parameter
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
     * @brief sendMessage
     * @param message
     */
    void sendMessage(QString message);
    /**
     * @brief AntwortChat
     * @param message
     */
    void AntwortChat(QString message);
public slots:
    //use this functions//////////////////////
    /// \brief disconnectTheClient
    ///
    void disconnectTheClient(); // disconnect the client from the server (! client reconnects automatically)
    /**
     * @brief openServer
     */
    void openServer(); // opens the Server for possible connections
    /**
     * @brief disconnectTheServer
     */
    void disconnectTheServer(); // kicks the client out and closes the server
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
    void sendParameters(quint8 Cmd, quint8 length, quint8 var1, quint8 var2=0, quint8 var3=0, quint8 var4=0);    //sends all Parameters either 1 , 2 or 4 parameters
    // don't use this functions///////////////////
    /**
     * @brief processRecievedInformation
     */
    void processRecievedInformation(); // recive Information
    /**
     * @brief closeServer
     * receive Information
     */
    void closeServer(); // no longer accept connections but the client stays in
    /**
     * @brief newConnection
     * // no longer accept connections but the client stays in
     */
    void newConnection(); // is called when a client connects
    /**
     * @brief disconnected
     * is called when a client connects
     */
    void disconnected(); // is called when a client disconnects
    /**
     * @brief sendChat
     * @param Cmd
     * @param message
     * is called when a client disconnects
     */
    void sendChat(quint8 Cmd, QString message);

private:
    QTcpServer *_myserver;
    QDataStream _mystream;
    QTcpSocket *_mysocket;
    quint16 _Port;
};

#endif // MYTCPSERVER_H
