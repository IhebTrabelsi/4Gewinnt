#include <QCoreApplication>
#include "client.h"
#include "mytcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer s(9999);
   //Client c("127.0.0.1",9999);
    //c.connectToServer();
     return a.exec();
}


