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
    ui->_Rundenzahl->setMinimum(1);
    ui->_Rundenzahl->setMaximum(10);
    ui->_Rundenzahl->setDisabled(true);
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
       m_holderFlagbSet7 = true;
    }
    else
    {
       m_ColumNumberToPass = 5;
       m_RowNumberToPass = 5;
       m_holderFlagbSet6 = true;
       m_holderFlagbSet7 = true;
    }
    _rundenzahl = ui->_Port->text().toUShort();
    ui->checkBox->setDisabled(true);
    ui->checkBox_2->setDisabled(true);
    ui->checkBox_3->setDisabled(true);
    ui->pushButton->setDisabled(true);
    ui->_Rundenzahl->setDisabled(true);
    emit signalSetSizeAndSend(m_ColumNumberToPass, m_RowNumberToPass, _rundenzahl); // add graphic interface

}

void MainWindow::createGrid(quint8 x, quint8 y, bool beginnender)
{
    if (x == static_cast<quint8>(5))
    {
       m_holderFlagbSet6 = true;
       m_holderFlagbSet7 = true;
    }
    else if(x == static_cast<quint8>(6))
    {
        m_holderFlagbSet6 = false;
        m_holderFlagbSet7 = true;

    }
    else
    {
        m_holderFlagbSet6 = false;
        m_holderFlagbSet7 = false;

    }
    m_ColumNumberToPass = x;
    m_RowNumberToPass = y;
    Game = new Dialog(this ,m_ColumNumberToPass ,m_RowNumberToPass ,m_holderFlagbSet6 ,m_holderFlagbSet7);
    Game->show();
    emit connectGame();

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
        ui->_IP->setDisabled(true);
        ui->_Port->setDisabled(true);
        ui->_Rundenzahl->setDisabled(true);
        emit createClient(_ServerOrClient, ui->_Port->text().toUShort(), ui->_IP->text());
    }
    else
    {

            ui->pushButton_Connect->setDisabled(true);
            ui->_IP->setDisabled(true);
            ui->_Port->setDisabled(true);
            ui->_Rundenzahl->setDisabled(true);
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
        ui->_Rundenzahl->setEnabled(true);
        emit sendMessage("The Server decides :D choose a grid size and press Let's GO");
    }
    else
    {
        emit sendMessage("You have to wait for the Server to choose a grid Size it won't last long");
    }
}

