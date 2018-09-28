#include "client.h"

Client::Client(QString Adress, quint16 Port, QObject *parent)
    : QObject(parent), _Adress(Adress), _Port(Port)
{
    _mystream.setByteOrder(QDataStream::BigEndian);
}

Client::~Client()
{
    delete _mysocket;
}


void Client::connectToServer()
{

     // do something to GUI enable / disable
    _mysocket = new QTcpSocket(this);

    _mysocket->connectToHost(_Adress, _Port);
    connect( _mysocket, SIGNAL(connected()),
             this, SLOT(enableConnection()) );
    connect( _mysocket, SIGNAL(disconnected()),
             this, SLOT(disconnected()) );
    emit sendMessage("Network: Connecting to IP : "+_Adress+" and Port: "+QString::number(_Port));
    qDebug() << "Connecting to port " << _Port << " IP : " << _Adress;
}

void Client::enableConnection() {
    assert(QObject::sender() != nullptr);

    _mystream.setDevice(_mysocket);
    connect(_mysocket, SIGNAL(readyRead()), this, SLOT(processRecievedInformation()));
    emit sendMessage("Network: Connected you can begin your first Round now");
    qDebug() <<"Connected";       // OUTPUT CONNECTED
    emit clientIsConnectedtoServer();

}

void Client::disconnectFromServer()
{
    qDebug() <<"Disconnected from Server"<< "\n" ;
    emit sendMessage("Network: Disconnected from Server");
    _mysocket->disconnectFromHost();
    _mystream.device()->deleteLater();
}

void Client::disconnected() {
    qDebug() << "Disconnecting/Deleting Socket" << "\n";
    emit sendMessage("Network: Disconnecting/Deleting Socket");
    _mystream.device()->deleteLater();
    connectToServer();
}

void Client::sendChat(quint8 Cmd, QString message);

void Client::sendParameters(quint8 Cmd, quint8 length, quint8 var1, quint8 var2, quint8 var3, quint8 var4)
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
void Client::processRecievedInformation()
{
   // emit sendMessage("RECEIVED");
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
            emit AntwortAufSpielfeldParameter(xGridSize, yGridSize, Rundenzahl, Beginnender);
            qDebug() << "GridSize x: " << xGridSize;
            qDebug() << "GridSize y: " << yGridSize;
            qDebug() << "Rundenzahl: " << Rundenzahl;
            qDebug() << "Beginnender: " << Beginnender;
            break;
        case (static_cast<quint8>(0x02)):
            _mystream >> Rundenummer;
            _mystream >> BeginnenderRunde;
            emit AntwortAufRundenbeginn(Rundenummer, BeginnenderRunde);
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

