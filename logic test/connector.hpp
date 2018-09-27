#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include <QObject>
#include "manager.hpp"
#include "mainwindow.h"




class Connector: public QObject {
    Q_OBJECT
private:
    Manager _manager;
    //MainWindow _mainWindow;


public:
    Connector(QObject *parent = nullptr);

signals:

};

#endif // CONNECTOR_HPP

