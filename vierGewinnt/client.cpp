#include "client.h"

Client::Client(QString Adress, quint16 Port, QObject *parent)
    : QObject(parent), _Adress(Adress), _Port(Port)
{
    _mystream.setByteOrder(QDataStream::BigEndian);
    connectToServer();
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
    qDebug() << "Connecting to port " << _Port << "\n";
}

void Client::enableConnection() {
    assert(QObject::sender() != nullptr);

    _mystream.setDevice(_mysocket);
    connect(_mysocket, SIGNAL(readyRead()), this, SLOT(processRecievedInformation()));
    qDebug() <<"Connected";       // OUTPUT CONNECTED
    emit clientIsConnectedtoServer();

}

void Client::disconnectFromServer()
{
    qDebug() <<"Disconnected from Server"<< "\n" ;
    _mysocket->disconnectFromHost();
    _mystream.device()->deleteLater();
}

void Client::disconnected() {
    qDebug() << "Disconnecting/Deleting Socket" << "\n";
    _mystream.device()->deleteLater();
    connectToServer();
}

void Client::sendParameters(qint8 Cmd, qint8 length, qint8 var1, qint8 var2, qint8 var3, qint8 var4)
{

    _mystream << Cmd;
    _mystream << length;
    _mystream << var1;
    qDebug() << "Sent Cmd + lenghth + Parameter 1 : " << Cmd << ", "<< length << ", " << var1;
    if(length == static_cast<qint8>(0x04))
    {
        _mystream << var2;
        _mystream << var3;
        _mystream << var4;
        qDebug() << "Sent Parameter 2 & 3 & 4" << var2 << ", " << var3 << ", "<< var4;
    }
    else if(length == static_cast<qint8>(0x02))
    {
        _mystream << var2;
         qDebug() << "Sent Parameter 2: "<< var2;
    }

}
void Client::processRecievedInformation()
{
    qint8 Cmd=0;
    qint8 length=0;
    qint8 xGridSize;
    qint8 yGridSize;
    qint8 Rundenzahl;
    qint8 Beginnender;
    qint8 Rundenummer;
    qint8 BeginnenderRunde;
    qint8 xCoordinate;
    qint8 Statuscode;
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
        case (static_cast<qint8>(0x01)):
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
        case (static_cast<qint8>(0x02)):
            _mystream >> Rundenummer;
            _mystream >> BeginnenderRunde;
            emit AntwortAufRundenbeginn(Cmd, Rundenummer, BeginnenderRunde);
            qDebug() << "Rundennummer: " << Rundenummer;
            qDebug() << "BeginnenderRunde: " << BeginnenderRunde;
            break;
        case (static_cast<qint8>(0x03)):
            _mystream >> xCoordinate;
            emit AntwortAufZug(Cmd, xCoordinate);
            qDebug() << "xCoordinate: " << xCoordinate;
            break;
        case (static_cast<qint8>(0x10)):
            _mystream >> Statuscode;
            emit AntwortAufAnfrage(Cmd, Statuscode);
            qDebug() << "Recieved Statuscode: " << Statuscode;
            break;
        case (static_cast<qint8>(0x11)):
            _mystream >> Statuscode;
            emit AntwortAufZug(Cmd, Statuscode);
            qDebug() << "X Position Zug: " << Statuscode;
            break;
        default:
            emit Fehler(0x02);


    }

}

