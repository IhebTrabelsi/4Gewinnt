#include "mytcpserver.h"
MyTcpServer::MyTcpServer(quint16 Port, QObject *parent) :
    QObject(parent), _Port(Port)
{
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
        emit sendMessage("Network: Server could not start");
    }
    else{
        emit sendMessage("Network: Server started! Just wait for a client to connect");
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
    emit sendMessage("Network: Client connected to the server");
    connect( _mysocket, SIGNAL(disconnected()),
             this, SLOT(disconnected()) );
    connect(_mysocket, SIGNAL(readyRead()), this, SLOT(processRecievedInformation()));
    emit serverIsConnectedToClient();
}

void MyTcpServer::disconnectTheClient()
{
    if (_mysocket)
    {
        _mysocket->close();
        emit sendMessage("Network: Disconnected The Client");
        qDebug() << "Disconnected The Client"<< "\n";
    }
}

void MyTcpServer::disconnectTheServer()
{
    disconnectTheClient();
    closeServer();
    emit sendMessage("Network: Server is Totally Closed");
    qDebug() << "Server is Totally Closed"<< "\n";
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
    sendMessage("Network: Disconnecting");
    qDebug() << "Disconnecting/Deleting Socket" << "\n";
    _mystream.device()->deleteLater();
    openServer();
}


void MyTcpServer::sendParameters(quint8 Cmd, quint8 length, quint8 var1, quint8 var2, quint8 var3, quint8 var4)
{
    //emit sendMessage("SENT");
    _mystream << Cmd;
    _mystream << length;
    _mystream << var1;
    qDebug() << "Sent Cmd + lenghth + Parameter 1 : " << Cmd << ", "<< length << ", " << var1;
    if(length == static_cast<quint8>(0x04))
    {
        _mystream << var2;
        _mystream << var3;
        _mystream << var4;
        qDebug() << "Sent Parameter 2 & 3 & 4" << var2 << ", " << var3 << ", "<< var4;
    }
    else if(length == static_cast<quint8>(0x02))
    {
        _mystream << var2;
         qDebug() << "Sent Parameter 2: "<< var2;
    }
}

void MyTcpServer::processRecievedInformation()
{
    //emit sendMessage("RECEIVED");
    quint8 Cmd=0;
    quint8 length=0;
    quint8 xGridSize;
    quint8 yGridSize;
    quint8 Rundenzahl;
    quint8 Beginnender;
    quint8 Rundenummer;
    quint8 BeginnenderRunde;
    quint8 xCoordinate;
    quint8 Statuscode;
    _mystream >> Cmd;
    _mystream >>  length;
    qint64 bytesAvailabe= _mysocket->bytesAvailable();
    qDebug() << "BytesAvailable" << bytesAvailabe;
    if (bytesAvailabe != length)
    {
        emit Fehler(0x03);
        return;
    }
    qDebug() << "Cmd: " << Cmd;
    qDebug() << "Length: " << length;
    switch(Cmd)
    {
        case (static_cast<quint8>(0x01)):
            _mystream >>xGridSize;
            _mystream >>yGridSize;
            _mystream >>Rundenzahl;
            _mystream >>Beginnender;
            emit AntwortAufSpielfeldParameter(Cmd, xGridSize, yGridSize, Rundenzahl, Beginnender);
            qDebug() << "GridSize x: " << xGridSize;
            qDebug() << "GridSize y: " << yGridSize;
            qDebug() << "Rundenzahl: " << Rundenzahl;
            qDebug() << "Beginnender: " << Beginnender;
            break;
        case (static_cast<quint8>(0x02)):
            _mystream >> Rundenummer;
            _mystream >> BeginnenderRunde;
            emit AntwortAufRundenbeginn(Cmd, Rundenummer, BeginnenderRunde);
            qDebug() << "Rundennummer: " << Rundenummer;
            qDebug() << "BeginnenderRunde: " << BeginnenderRunde;
            break;
        case (static_cast<quint8>(0x03)):
            _mystream >> xCoordinate;
            emit AntwortAufZug(Cmd, xCoordinate);
            qDebug() << "xCoordinate: " << xCoordinate;
            break;
        case (static_cast<quint8>(0x10)):
            _mystream >> Statuscode;
            emit AntwortAufAnfrage(Cmd, Statuscode);
            qDebug() << "Recieved Statuscode: " << Statuscode;
            break;
        case (static_cast<quint8>(0x11)):
            _mystream >> Statuscode;
            emit AntwortAufZug(Cmd, Statuscode);
            qDebug() << "X Position Zug: " << Statuscode;
            break;
        default:
            emit Fehler(0x02);


    }

}
