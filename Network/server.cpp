#include "server.h"

Server::Server(quint16 Port, QObject *parent)
    : QObject(parent), _Port(Port)
{
    _myserver = new QTcpServer(this);

    // whenever a user connects, it will emit signal
    connect(_myserver, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!_myserver->listen(QHostAddress::Any, 9999))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
        qDebug() << _myserver->serverAddress();
        qDebug() << _myserver->serverPort();
    }
}

//void Server::openServer()
//{


//}

void Server::newConnection()
{
    QTcpSocket *socket = _myserver->nextPendingConnection();
    socket->write("Hello client\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
    //_mystream.setDevice(_mysocket);
    //connect(_mysocket, SIGNAL(readyRead()), this, SLOT(processRecievedInformation()));
    qDebug()<< "Client connected to the server"<< "\n";
}

//void Server::processRecievedInformation()
//{
//    qint64 parameterRecieved;
//    _mystream >> parameterRecieved;
//    qDebug() << parameterRecieved << "\n";
//}
//void Server::sendParameters(qint64 parameter)
//{

//    _mystream << parameter;
//    qDebug() << "Sent: " << parameter <<"\n";

//}
//void Server::sendZug(qint8 x)
//{
//    _mystream << 0x03;
//    _mystream << 0x01;
//    _mystream << x;
//    qDebug() << "Sent: " << 0x03  << 0x01 << x << "\n";
//}

//void Server::disconnectTheClient()
//{
//    if (_mysocket)
//    {
//        _mysocket->close();
//        qDebug() << "Disconnected The Client"<< "\n";
//    }
//}

//void Server::closeServer()
//{
//    if (_myserver && _myserver->isListening())
//        {
//            _myserver->close();
//            qDebug() << "Server Closed"<< "\n";
//        }
//}
