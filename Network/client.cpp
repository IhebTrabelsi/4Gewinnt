#include "client.h"

Client::Client(QString Adress, quint16 Port, QObject *parent)
    : QObject(parent), _Adress(Adress), _Port(Port)
{
    _mystream.setByteOrder(QDataStream::BigEndian);
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
    emit clientIsConnected();

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

void Client::sendParameters(qint64 parameter)
{

    _mystream << parameter;
    std::cout << "Sent: " << std::hex << parameter <<"\n";

}
void Client::processRecievedInformation()
{
    qint64 parameterRecieved;
    _mystream >> parameterRecieved;
   std::cout << "Recieved: " << std::hex << parameterRecieved <<"\n";
}
void Client::sendZug(qint8 x)
{
    _mystream << 0x03;
    _mystream << 0x01;
    _mystream << x;
    std::cout << "Sent: " << std::hex << 0x03 << 0x01 << x <<"\n";
}
