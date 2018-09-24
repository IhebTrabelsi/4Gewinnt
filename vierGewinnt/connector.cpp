#include "connector.hpp"




Connector::Connector(Ui::MainWindow ui, QWidget *parent)
    :QObject(parent)
{

connect(ui->ButtonClient, SIGNAL(clicked()), _manager, SLOT(setServerClient (false ,9999 ,"127.0.0.1")));
connect(ui->ButtonServer, SIGNAL(clicked()), _manager, SLOT(setServerClient (true ,9999 ,"127.0.0.1")));

}
