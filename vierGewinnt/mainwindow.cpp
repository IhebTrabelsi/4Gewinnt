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

    Game = new Dialog(this);
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
    /*_GridXtoDraw=7;
    _GridYtoDraw=7;
    RadioPressed = true;*/
}

void MainWindow::on_checkBox_3_clicked() //6
{
    /*_GridXtoDraw=6;
    _GridYtoDraw=6;
    RadioPressed = true;*/
}

void MainWindow::on_checkBox_clicked() //5
{
    /*
    RadioPressed = true;*/
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
