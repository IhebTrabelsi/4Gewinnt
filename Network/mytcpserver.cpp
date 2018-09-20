#include "mytcpserver.h"

MyTcpServer::MyTcpServer(quint16 Port, QObject *parent) :
    QObject(parent), _Port(Port)
{
openServer();
}

void MyTcpServer::openServer()
{
    _myserver = new QTcpServer(this);

    // whenever a user connects, it will emit signal
    connect(_myserver, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!_myserver->listen(QHostAddress::Any, _Port))
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
    _mysocket = _myserver->nextPendingConnection();
    _mystream.setDevice(_mysocket);
    qDebug()<< "Client connected to the server"<< "\n";
    connect( _mysocket, SIGNAL(disconnected()),
             this, SLOT(disconnected()) );
    connect(_mysocket, SIGNAL(readyRead()), this, SLOT(processRecievedInformation()));
    //sendZug(1);

}

void MyTcpServer::disconnectTheClient()
{
    if (_mysocket)
    {
        _mysocket->close();
        qDebug() << "Disconnected The Client"<< "\n";
    }
}

void MyTcpServer::disconnectTheServer()
{
    disconnectTheClient();
    closeServer();
    qDebug() << "Server is Totally Closeds"<< "\n";
}
void MyTcpServer::closeServer()
{
    if (_myserver && _myserver->isListening())
        {
            _myserver->close();
            qDebug() << "Server Closed for more Connections "<< "\n";
        }
}


void MyTcpServer::disconnected() {
    qDebug() << "Disconnecting/Deleting Socket" << "\n";
    _mystream.device()->deleteLater();
    openServer();
}


void MyTcpServer::sendZug(qint8 x)
{
    _mystream << 0x03;
    _mystream << 0x01;
    _mystream << x;
    std::cout << "Sent: " << std::hex << 0x03 << 0x01 << x <<"\n";
}

void MyTcpServer::sendParameters(qint64 parameter)
{

    _mystream << parameter;
    std::cout << "Sent: " << std::hex << parameter <<"\n";

}

void MyTcpServer::processRecievedInformation()
{
    qint64 parameterRecieved;
    _mystream >> parameterRecieved;
    std::cout << "Recieved: " << std::hex << parameterRecieved <<"\n";
}
