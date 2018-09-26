#include "dialog.h"
#include <QApplication>
#include <mainwindow.h>
#include "connector.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connector connector;

    return a.exec();
}
