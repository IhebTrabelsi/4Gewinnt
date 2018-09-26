#include "connector.hpp"




Connector::Connector(QObject *parent)
    :QObject(parent)
{
connect(&_mainWindow, &MainWindow::signalSetSizeAndSend , &_manager, &Manager::setSizeAndSend);
connect(&_mainWindow, &MainWindow::createServer , &_manager, &Manager::setServerClient);
connect(&_mainWindow, &MainWindow::createClient , &_manager, &Manager::setServerClient);
connect(&_manager, &Manager::gameChat, &_mainWindow, &MainWindow::sendMessage);

connect(&_mainWindow, &MainWindow::spieleStein , &_manager, &Manager::insertStein);
connect(&_mainWindow, &MainWindow::signalQuit , &_manager, &Manager::quit);
//XXXconnect(&_manager, &Manager::paint , &_mainWindow, &MainWindow::paint);

//connect(&_manager, &Manager::gameChat , &_mainWindow, &MainWindow::chat);
//connect(&_manager, &Manager::network , &_mainWindow, &MainWindow::sendParameters);


_mainWindow.show();

connect(&_manager, SIGNAL(networkConnects(bool)), this, SLOT(networkConnects(bool))); // umleitung von allen connects nachdem client / server erstellt würden

}

// !!!!!!!put all the connects that need the server and client object here because you can't connect before the object is created
void Connector::networkConnects(bool serverOrClient)
{
    if (serverOrClient == false)
    {
        connect(_manager._server, &MyTcpServer::sendMessage, &_mainWindow, &MainWindow::sendMessage); // this is for sending messages for the chat
        connect(_manager._server, &MyTcpServer::serverIsConnectedToClient, &_mainWindow, &MainWindow::whenConnected);

        //connect(&_manager, SIGNAL(networkClient(quint8,quint8,quint8)) , _manager._server, SLOT(sendParameters(qint8,qint8,qint8)));
       // connect(_manager._server, &MyTcpServer::AntwortAufZug , &_manager, &Manager::handleEvent); // das ist doppelt ?? passt so ?
        //connect(_manager._server, &MyTcpServer::AntwortAufAnfrage , &_manager, &Manager::handleEvent);
        //connect(&_manager, &Manager::sendParameters, _manager._server, &MyTcpServer::sendParameters );
        //connect(_manager._server, &MyTcpServer::serverIsConnectedToClient , &_manager, &Manager::serverRequested);
    }
    else
    {
        connect(_manager._client, SIGNAL(sendMessage(QString)), &_mainWindow, SLOT(sendMessage(QString)));
        connect(_manager._client, &Client::clientIsConnectedtoServer, &_mainWindow, &MainWindow::whenConnected);

        //connect(&_manager, SIGNAL(networkServer(quint8,quint8,quint8)) , _manager._client, SLOT(sendParameters(qint8,qint8,qint8)));
        //connect(_manager._client, &Client::AntwortAufSpielfeldParameter , &_manager, &Manager::clientReceived);
        //connect(_manager._client, &Client::AntwortAufZug , &_manager, &Manager::handleEvent);
    }
}
