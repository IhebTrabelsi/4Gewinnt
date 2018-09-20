#include "mytcpserver.h"

MyTcpServer::MyTcpServer(quint16 Port, QObject *parent) :
    QObject(parent), _Port(Port)
{
    _myserver = new QTcpServer(this);
    _myserver->setMaxPendingConnections(1);

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

void MyTcpServer::newConnection()
{
    // need to grab the socket
    qint64 i = 123456;
    _mysocket = _myserver->nextPendingConnection();
    _mystream.setDevice(_mysocket);
    _mystream << i;
    connect( _mysocket, SIGNAL(disconnected()),
             this, SLOT(disconnected()) );
    connect( _mysocket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(socketError()) );
    qDebug()<< "Client connected to the server"<< "\n";
    toggleAcceptingConnections();

}

void MyTcpServer::disconnectTheClient()
{
    if (_mysocket)
    {
        _mysocket->close();
        toggleAcceptingConnections();
        qDebug() << "Disconnected The Client"<< "\n";
    }
}

void MyTcpServer::closeServer()
{
    if (_myserver && _myserver->isListening())
        {
            _myserver->close();
            qDebug() << "Server Closed"<< "\n";
        }
}

void MyTcpServer::toggleAcceptingConnections()
{
    if(_myserver && _myserver->hasPendingConnections())
    {
        _myserver->pauseAccepting();
    }
    else
    {
        _myserver->resumeAccepting();
    }
}


void MyTcpServer::disconnected() {
    qDebug() << "Disconnecting/Deleting Socket" << "\n";
    _mystream.device()->deleteLater();
    toggleAcceptingConnections();
}

void MyTcpServer::socketError() {
    qDebug() << "Connection closed or could not connect." << "\n";
    _mystream.device()->deleteLater();
    toggleAcceptingConnections();
}

void MyTcpServer::sendZug(qint8 x)
{
    _mystream << 0x03;
    _mystream << 0x01;
    _mystream << x;
    qDebug() << "Sent: " << 0x03  << 0x01 << x << "\n";
}

void MyTcpServer::sendParameters(qint64 parameter)
{

    _mystream << parameter;
    qDebug() << "Sent: " << parameter <<"\n";

}

void MyTcpServer::processRecievedInformation()
{
    qint64 parameterRecieved;
    _mystream >> parameterRecieved;
    qDebug() << parameterRecieved << "\n";
}
