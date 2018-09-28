#include "connector.hpp"




Connector::Connector(QObject *parent)
    :QObject(parent)
{
connect(&_mainWindow, &MainWindow::signalSetSizeAndSend , &_manager, &Manager::setSizeAndSend);
connect(&_mainWindow, &MainWindow::createServer , &_manager, &Manager::setServerClient);
connect(&_mainWindow, &MainWindow::createClient , &_manager, &Manager::setServerClient);
connect(&_manager, &Manager::gameChat, &_mainWindow, &MainWindow::sendMessage);
connect(&_manager, &Manager::createGrid, &_mainWindow, &MainWindow::createGrid);
connect(&_mainWindow, &MainWindow::spieleStein , &_manager, &Manager::insertStein);
connect(&_mainWindow, &MainWindow::signalQuit , &_manager, &Manager::quit);
connect(&_manager, &Manager::resetGraphik, &_mainWindow, &MainWindow::newRound);
connect(&_manager, &Manager::sendChatGrafik, &_mainWindow, &MainWindow::receivechatGrafik);
connect(&_mainWindow, &MainWindow::sendChatGrafik, &_manager, &Manager::managerSendChat);
connect(&_manager, &Manager::openChat, &_mainWindow, &MainWindow::openChat);



_mainWindow.show();

connect(&_manager, SIGNAL(networkConnects(bool)), this, SLOT(networkConnects(bool))); // umleitung von allen connects nachdem client / server erstellt würden
connect(&_mainWindow, SIGNAL(connectGame()), this, SLOT(gameConnects()));

}

void Connector::gameConnects()
{
qDebug() << "Game Connnnnects ------------------";
connect(&_manager, &Manager::addStone, _mainWindow.Game, &Dialog::addStone);
connect(_mainWindow.Game, &Dialog::sendZug, &_manager, &Manager::insertStein);
connect(&_manager, &Manager::gewonnen, _mainWindow.Game, &Dialog::gewonnen);
connect(&_manager, &Manager::setRunde, _mainWindow.Game, &Dialog::setRunde);
connect(&_manager, &Manager::setRunde2, _mainWindow.Game, &Dialog::setRunde2);
connect(&_manager, &Manager::setPunkteIch, _mainWindow.Game, &Dialog::setPunkteIch);
connect(&_manager, &Manager::setPunkteGegner, _mainWindow.Game, &Dialog::setPunkteGegner);
connect(_mainWindow.Game, &Dialog::nextRound, &_manager, &Manager::newRound);
connect(&_manager, &Manager::disableNextRoundButton, _mainWindow.Game, &Dialog::disableNextRoundButton);
connect(&_manager, &Manager::toggleNextButton, _mainWindow.Game, &Dialog::toggleNextButton);
}
// !!!!!!!put all the connects that need the server and client object here because you can't connect before the object is created
void Connector::networkConnects(bool serverOrClient)
{
    if (serverOrClient == false)
    {
        connect(_manager._server, &MyTcpServer::sendMessage, &_mainWindow, &MainWindow::sendMessage); // this is for sending messages for the chat
        connect(_manager._server, &MyTcpServer::serverIsConnectedToClient, &_mainWindow, &MainWindow::whenConnected);
        connect(&_manager, &Manager::sendParameters , _manager._server, &MyTcpServer::sendParameters);
        connect(_manager._server, &MyTcpServer::AntwortAufAnfrage, &_manager, &Manager::handleEvent);
        connect(_manager._server, &MyTcpServer::AntwortAufZug, &_manager, &Manager::handleEvent);
        connect(&_manager, &Manager::sendChat, _manager._server, &MyTcpServer::sendChat);
        connect(_manager._server, &MyTcpServer::AntwortChat, &_manager, &Manager::receiveChat);
        //connect(_manager._server, &MyTcpServer::AntwortAufRundenbeginn, &_manager, &Manager::StartRunde);
    }
    else
    {
        connect(_manager._client, SIGNAL(sendMessage(QString)), &_mainWindow, SLOT(sendMessage(QString)));
        connect(_manager._client, &Client::clientIsConnectedtoServer, &_mainWindow, &MainWindow::whenConnected);
        connect(&_manager, &Manager::sendParameters , _manager._client, &Client::sendParameters);
        connect(_manager._client, &Client::AntwortAufSpielfeldParameter, &_manager, &Manager::clientReceived);
        connect(_manager._client, &Client::AntwortAufZug, &_manager, &Manager::handleEvent);
       // connect(_manager._client, &Client::AntwortAufRundenbeginn, &_manager, &Manager::StartRunde);
        connect(_manager._client, &Client::AntwortAufAnfrage, &_manager, &Manager::handleEvent);
        connect(&_manager, &Manager::sendChat, _manager._client, &Client::sendChat);
        connect(_manager._client, &Client::AntwortChat, &_manager, &Manager::receiveChat);
    }
}
