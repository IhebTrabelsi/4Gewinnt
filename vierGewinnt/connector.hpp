#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include <QObject>
#include <QWidget>
#include "manager.hpp"
#include "mainwindow.h"



class Connector: public QObject {
    Q_OBJECT
private:
    Manager _manager;
    Ui::MainWindow _mainWindow;

public:
    Connector(Ui::MainWindow ui, QWidget *parent = nullptr);

signals:

};

#endif // CONNECTOR_HPP

