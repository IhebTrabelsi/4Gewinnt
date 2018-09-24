
#include "dialog.h"
#include <QApplication>
#include "connector.hpp"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connector c;


    return a.exec();
}

