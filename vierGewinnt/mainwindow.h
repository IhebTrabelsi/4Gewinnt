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

signals:
    void createServer(bool server, quint16 port, QString ip);
    void createClient(bool server, quint16 port, QString ip);
    void spieleStein (quint8 x);
    void signalQuit();
public slots:
    //void chat(QString massage);

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
    //---------------------COLUMN AND ROW NUMBER TO PASS-----------------
    int m_ColumNumberToPass=7;
    int m_RowNumberToPass=7;
    //-------------------------------------------------------------------

    //--------- BOOL To check if one CHECKBOX IS ALREADY PRESSED---------
    bool m_CheckBoxPressed;
    //---------------------- PLACE HOLDERS for flags---------------------
    bool m_holderFlagbSet6 = false;
    bool m_holderFlagbSet7 = false;

};

#endif //MAINWINDOWS_H
