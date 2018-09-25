#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->hide();
    ui->_Port->setMaximum(49150);
    ui->_Port->setMinimum(1024);
    ui->Chat->setReadOnly(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox->setDisabled(true);
    ui->checkBox_2->setDisabled(true);
    ui->checkBox_3->setDisabled(true);
    ui->pushButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMessage(QString message)
{
    ui->Chat->append(message);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->checkBox_2->isChecked())
    {
       m_ColumNumberToPass = 7;
       m_RowNumberToPass = 7;
    }
    else if (ui->checkBox_3->isChecked())
    {
       m_ColumNumberToPass = 6;
       m_RowNumberToPass = 6;
    }
    else
    {
       m_ColumNumberToPass = 5;
       m_RowNumberToPass = 5;
    }
    ui->checkBox->setDisabled(true);
    ui->checkBox_2->setDisabled(true);
    ui->checkBox_3->setDisabled(true);
    ui->pushButton->setDisabled(true);
    emit signalSetSizeAndSend(m_ColumNumberToPass, m_RowNumberToPass, 1); // add graphic interface

    Game = new Dialog(this ,m_ColumNumberToPass ,m_RowNumberToPass ,m_holderFlagbSet6 ,m_holderFlagbSet7);
    Game->show();
}

void MainWindow::on_pushButton_Send_clicked()
{

}

void MainWindow::on_pushButton_Connect_clicked()
{
    if(_ServerOrClient == true)
    {
        if (ui->_IP->text().toStdString() == "")
        {
            sendMessage("Please type in an IP adress");
            return;
        }
        ui->pushButton_Connect->setDisabled(true);
        emit createClient(_ServerOrClient, ui->_Port->text().toUShort(), ui->_IP->text());
    }
    else
    {

            ui->pushButton_Connect->setDisabled(true);
            emit createServer(_ServerOrClient,ui->_Port->text().toUShort(),ui->_IP->text());
    }

}

void MainWindow::on_checkBox_2_clicked() //7
{
    // moved to the click button function
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void MainWindow::on_checkBox_3_clicked() //6
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
}


void MainWindow::on_checkBox_clicked() //5
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}


void MainWindow::on_ButtonClient_clicked()
{
    ui->widget->show();
    _ServerOrClient = true;
    ui->ButtonClient->setDisabled(true);
    ui->ButtonServer->setDisabled(true);
    sendMessage("You have chosen to be client");
}

void MainWindow::on_ButtonServer_clicked()
{
    ui->IP->hide();
    ui->_IP->hide();
    ui->widget->show();
    _ServerOrClient = false;
    ui->ButtonClient->setDisabled(true);
    ui->ButtonServer->setDisabled(true);
    sendMessage("You have chosen to be server");
}

void MainWindow::whenConnected()
{
    if (_ServerOrClient == false){
        ui->checkBox->setEnabled(true);
        ui->checkBox_2->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->pushButton->setEnabled(true);
        emit sendMessage("The Server decides :D choose a grid size and press Let's GO");
    }
    else
    {
        emit sendMessage("You have to wait for the Server to choose a grid Size it won't last long");
    }
}

