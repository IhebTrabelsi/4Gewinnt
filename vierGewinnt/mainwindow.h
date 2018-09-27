#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<dialog.h>
#include<QDebug>

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
    void spieleStein (quint8 x); //bitte überall einbauen wo ein Stein gesetzt werden sollXXX
    void signalQuit();
    void signalSetSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl);
    void connectGame();
public slots:
    //void chat(QString massage); //bitte in chat ausgebenXXX
    //void paint(quint8 x, quint8 y, stein spieler); //bitte stein in spielfeld setzenXXX

public slots:
    void on_pushButton_clicked();

    void on_pushButton_Send_clicked();

    void on_pushButton_Connect_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_clicked();

    void on_ButtonClient_clicked();

    void on_ButtonServer_clicked();

    void sendMessage(QString message);

    void whenConnected();

    void createGrid(quint8 x, quint8 y,bool beginnender);


public:
    Ui::MainWindow *ui;
    Dialog *Game;
    //---------------------COLUMN AND ROW NUMBER TO PASS-----------------
    quint8 m_ColumNumberToPass=7;
    quint8 m_RowNumberToPass=7;
    //-------------------------------------------------------------------
    //---------------------- PLACE HOLDERS for flags---------------------
    bool m_holderFlagbSet6 = false;
    bool m_holderFlagbSet7 = false;

    bool _ServerOrClient= true;
    quint8 _rundenzahl;

};

#endif //MAINWINDOWS_H
