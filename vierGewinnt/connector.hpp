#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include <QObject>
#include "manager.hpp"
#include "mainwindow.h"


/**
 * @file connector.hpp Header file for Connector class
 * @author Chedi Fassi
 **/


class Connector: public QObject {
    Q_OBJECT
private:
    Manager _manager;
    MainWindow _mainWindow;


public:
    Connector(QObject *parent = nullptr);

signals:

public slots:
    /**
     * @brief networkConnects
     * @param serverOrClient
     * to connect all server/client connects when a network object is created
     */
    void networkConnects(bool serverOrClient);
    void gameConnects();

};

#endif // CONNECTOR_HPP

