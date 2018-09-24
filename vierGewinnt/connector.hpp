#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include <QObject>
#include <QWidget>



class Connector: public QObject {
    Q_OBJECT
public:
    Connector(QWidget *parent = 0);

signals:

};

#endif // CONNECTOR_HPP

