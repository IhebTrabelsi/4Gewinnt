#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->hide();
    m_CheckBoxPressed=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /*if(RadioPressed)
    {*/
        //Dialog *Game = new Dialog();
        //Game->setModal(true);
        //Game->exec();
    /*}
    else
    {
        qDebug()<<"You Have To choooose";
    }*/

    Game = new Dialog(this ,m_ColumNumberToPass ,m_RowNumberToPass ,m_holderFlagbSet6 ,m_holderFlagbSet7);
    Game->show();
}

void MainWindow::on_pushButton_Send_clicked()
{

}

void MainWindow::on_pushButton_Connect_clicked()
{

}

void MainWindow::on_checkBox_2_clicked() //7
{
    if(!m_CheckBoxPressed)
        {
            m_CheckBoxPressed=true;
            m_ColumNumberToPass=7;
            m_RowNumberToPass=7;
        }
    //-------------------------Maybe add ui->check3 and checkbox -> hide-------------
    //---------------- ui->checkBox3->hide
    //                 ui->checkBox->hide
    //                 ui->you just choosed WIDGET-> show()
    //-------------------------------------------------------------------------------
}

void MainWindow::on_checkBox_3_clicked() //6
{   if(!m_CheckBoxPressed)
    {
        m_CheckBoxPressed=true;
        m_ColumNumberToPass=6;
        m_RowNumberToPass=6;
        m_holderFlagbSet7 = true;
    }
}

void MainWindow::on_checkBox_clicked() //5
{
    if(!m_CheckBoxPressed)
        {
            m_CheckBoxPressed=true;
            m_ColumNumberToPass=5;
            m_RowNumberToPass=5;
            m_holderFlagbSet7 = true;
            m_holderFlagbSet6 = true;
        }
}


void MainWindow::on_ButtonClient_clicked()
{
    /*QPropertyAnimation *animation = new QPropertyAnimation(ui->widget, "maximumHeight");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(100);

    animation->start();*/
    ui->widget->show();
}

void MainWindow::on_ButtonServer_clicked()
{
    ui->widget->show();
}
