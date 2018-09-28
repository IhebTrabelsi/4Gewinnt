#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<dialog.h>
#include<QDebug>
#include<QPixmap>
#include<QListView>

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
    /**
     * @brief createServer
     * @param server
     * @param port
     * @param ip
     */
    void createServer(bool server, quint16 port, QString ip);
    /**
     * @brief createClient
     * @param server
     * @param port
     * @param ip
     */
    void createClient(bool server, quint16 port, QString ip);
    /**
     * @brief spieleStein
     * @param x
     * bitte überall einbauen wo ein Stein gesetzt werden soll
     */
    void spieleStein (quint8 x); //
    /**
     * @brief signalQuit
     */
    void signalQuit();
    /**
     * @brief signalSetSizeAndSend
     * @param x
     * @param y
     * @param rundenzahl
     */
    void signalSetSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl);
    /**
     * @brief connectGame
     */
    void connectGame();
    /**
     * @brief sendChatGrafik
     * @param message
     */
    void sendChatGrafik(QString message);
public slots:
    //void chat(QString massage); //bitte in chat ausgebenXXX
    //void paint(quint8 x, quint8 y, stein spieler); //bitte stein in spielfeld setzenXXX

public slots:
    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();
    /**
     * @brief on_pushButton_Send_clicked
     */
    void on_pushButton_Send_clicked();
    /**
     * @brief on_pushButton_Connect_clicked
     */
    void on_pushButton_Connect_clicked();
    /**
     * @brief on_checkBox_2_clicked
     */
    void on_checkBox_2_clicked();
    /**
     * @brief on_checkBox_3_clicked
     */
    void on_checkBox_3_clicked();
    /**
     * @brief on_checkBox_clicked
     */
    void on_checkBox_clicked();
    /**
     * @brief on_ButtonClient_clicked
     */
    void on_ButtonClient_clicked();
    /**
     * @brief on_ButtonServer_clicked
     */
    void on_ButtonServer_clicked();
    /**
     * @brief sendMessage
     * @param message
     */
    void sendMessage(QString message);
    /**
     * @brief whenConnected
     */
    void whenConnected();
    /**
     * @brief createGrid
     * @param x
     * @param y
     * für die grafik
     */
    void createGrid(quint8 x, quint8 y);
    /**
     * @brief newRound
     */
    void newRound();
    /**
     * @brief receivechatGrafik
     * @param message
     */
    void receivechatGrafik(QString message);
    /**
     * @brief openChat
     */
    void openChat();


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
