#include "client.h"

Client::Client(QString Adress, quint16 Port, QObject *parent)
    : QObject(parent), _Adress(Adress), _Port(Port)
{
    _mystream.setByteOrder(QDataStream::BigEndian);
}

void Client::connectToServer()
{
    _mysocket = new QTcpSocket(this);

    qDebug() << "Connecting to port " << _Port << "\n";
    _mysocket->connectToHost(_Adress, _Port);
    // do something to GUI enable / disable
    connect( _mysocket, SIGNAL(connected()),
             this, SLOT(enableConnection()) );
    connect( _mysocket, SIGNAL(disconnected()),
             this, SLOT(disconnected()) );
    connect( _mysocket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(socketError()) );

}

void Client::enableConnection() {
    assert(QObject::sender() != nullptr);

    // OUTPUT CONNECTED
    qDebug() <<"Connected";
    _mystream.setDevice(_mysocket);

    connect(_mysocket, SIGNAL(readyRead()), this, SLOT(processRecievedInformation()));
   sendParameters(6566707172);
   // sendZug(0x99);

}

void Client::disconnectFromServer()
{
    qDebug() <<"Disconnected from Server"<< "\n" ;
    _mysocket->disconnectFromHost();
}

void Client::disconnected() {
    qDebug() << "Disconnecting/Deleting Socket" << "\n";
    _mystream.device()->deleteLater();
}

void Client::socketError() {
    qDebug() << "Connection closed or could not connect." << "\n";
    _mystream.device()->deleteLater();
}
void Client::sendParameters(qint64 parameter)
{

    _mystream << parameter;
    qDebug() << "Sent: " << parameter <<"\n";

}
void Client::processRecievedInformation()
{
    qint64 parameterRecieved;
    _mystream >> parameterRecieved;
    qDebug() << parameterRecieved << "\n";
}
void Client::sendZug(qint8 x)
{
    _mystream << 0x03;
    _mystream << 0x01;
    _mystream << x;
    qDebug() << "Sent: " << 0x03  << 0x01 << x << "\n";
}
