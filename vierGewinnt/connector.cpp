#include "connector.hpp"




Connector::Connector(QObject *parent)
    :QObject(parent)
{


connect(&_mainWindow, &MainWindow::createServer , &_manager, &Manager::setServerClient);
connect(&_mainWindow, &MainWindow::createClient , &_manager, &Manager::setServerClient);
connect(&_mainWindow, &MainWindow::spieleStein , &_manager, &Manager::insertStein);
connect(&_mainWindow, &MainWindow::signalQuit , &_manager, &Manager::quit);
connect(&_mainWindow, &MainWindow::signalSetSize , &_manager, &Manager::setSize);
//XXXconnect(&_manager, &Manager::paint , &_mainWindow, &MainWindow::paint);

//connect(&_manager, &Manager::gameChat , &_mainWindow, &MainWindow::chat);
//connect(&_manager, &Manager::network , &_mainWindow, &MainWindow::sendParameters);

connect(&_manager, SIGNAL(networkServer(quint8,quint8,quint8)) , _manager._client, SLOT(sendParameters(qint8,qint8,qint8)));
connect(&_manager, SIGNAL(networkClient(quint8,quint8,quint8)) , _manager._server, SLOT(sendParameters(qint8,qint8,qint8)));

connect(_manager._client, &Client::AntwortAufSpielfeldParameter , &_manager, &Manager::clientReceived);
connect(_manager._client, &Client::AntwortAufZug , &_manager, &Manager::handleEvent);

connect(_manager._server, &MyTcpServer::AntwortAufZug , &_manager, &Manager::handleEvent);
connect(_manager._server, &MyTcpServer::AntwortAufAnfrage , &_manager, &Manager::handleEvent);

connect(&_manager, &Manager::sendParameters, _manager._server, &MyTcpServer::sendParameters );
connect(_manager._server, &MyTcpServer::serverIsConnectedToClient , &_manager, &Manager::serverRequested);

_mainWindow.show();

}
