#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <QTcpSocket>
#include <QDataStream>
#include <QTcpServer>
#include <QObject>
#include <QHostAddress>
#include <QDebug>


class Server : public QObject
{
    Q_OBJECT
public:

    explicit Server(quint16 Port, QObject *parent=nullptr);
private:
    QTcpServer *_myserver;
    QDataStream _mystream;
    QTcpSocket *_mysocket;
    quint16 _Port;

public slots:
    void newConnection();
//    /**
//    *  @brief send a parameter compsed of
//    * 8bit Cmd / 8bit Length / 8bit Roundnumber / 8bit Beginner Round
//    *
//    **/
//    void sendParameters(qint64 parameter);
//    /**
//    *  @brief when data is recived process the data and emit a logic signal
//    * with the parameters
//    *
//    **/
//    void processRecievedInformation();
//    /**
//    *  @brief send information about the Zug 8bit Cmd / 8bit Length / 8bit x
//    *
//    **/
//    void sendZug(qint8 x);
//    /**
//    *  @brief Listens to the Object Port
//    *
//    **/
//    void openServer();
//    /**
//    *  @brief if a connection is found connects the clients socket to the server socket and binds the stream to it
//    *
//    **/
//    ///////////////////
//    /**
//    *  @brief disconnects the Client from the server
//    *
//    **/
//    void disconnected();
//    /**
//    *  @brief when an error happens delete the socket
//    *
//    **/
//    void socketError();
//    /**
//    *  @brief disconnect from the server
//    *
//    **/
//    void disconnectTheClient();
//    /**
//     * @brief closes the Server
//     */
//    void closeServer();


};

#endif // SERVER_H
