#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<dialog.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Send_clicked();

    void on_pushButton_Connect_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_clicked();

    void on_ButtonClient_clicked();

    void on_ButtonServer_clicked();

private:
    Ui::MainWindow *ui;

    Dialog *Game;
};

#endif //MAINWINDOWS_H
