#include "connector.hpp"




Connector::Connector(QObject *parent)
    :QObject(parent)
{

//connect(_mainWindow, &MainWindow::createServer , _manager, [=]() {_manager.setServerClient();});
connect(&_mainWindow, &MainWindow::createServer , &_manager, &Manager::setServerClient);
connect(&_mainWindow, &MainWindow::createClient , &_manager, &Manager::setServerClient);
connect(&_mainWindow, &MainWindow::spieleStein , &_manager, &Manager::insertStein);
connect(&_mainWindow, &MainWindow::signalQuit , &_manager, &Manager::quit);
//XXXconnect(&_manager, &Manager::paint , &_mainWindow, &MainWindow::paint);

//connect(&_manager, &Manager::paint , &_mainWindow, &MainWindow::paint);
//connect(&_manager, &Manager::gameChat , &_mainWindow, &MainWindow::chat);

_mainWindow.show();

}
