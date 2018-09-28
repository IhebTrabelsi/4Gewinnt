#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <QObject>
#include <QWidget>
#include <memory>
#include <iostream>
#include "spiel.hpp"
#include "mytcpserver.h"
#include "client.h"
#include <stdlib.h>
#include <time.h>


/**
 * @file manager.hpp Header file for Manager class
 * @author Simon Näther / Chedi Fassi
 **/



/**
 *  @brief Manager class represents the gamelogic
 */
class Manager: public QObject {
    Q_OBJECT

public:
    /**
     *  @brief Manager constructor and destructor
     *
     **/
    Manager() = default;
    ~Manager();

public slots:
    /**
     * @brief spielStart
     */
	void spielStart();
    /**
     * @brief handleEvent
     * @param code
     * @param value
     */
    void handleEvent(quint8 code, quint8 value); 
    /**
     * @brief quit
     */
	void quit();
    /**
     * @brief insertStein
     * @param x
     */
    void insertStein(quint8 x);
    /**
     * @brief setStein
     * @param x
     * @return
     */
    int setStein(int x);
    /**
     * @brief checkZug
     * @param x
     */
    void checkZug(int x);
    /**
     * @brief checkValid
     * @param x
     * @return
     */
	bool checkValid(quint8 x);
    /**
     * @brief checkWin
     * @param x
     * @param y
     * @return
     */
    bool checkWin(int x, int y);
    /**
     * @brief checkDraw
     * @return
     */
	bool checkDraw();
    /**
     * @brief nextZug
     */
	void nextZug();
    //void setNextRound(quint8 Cmd, quint8 Rundenummer, quint8 BeginnenderRunde);
    /**
     * @brief setServerClient
     * @param serverOrClient
     * @param port
     * @param IP
     */
    void setServerClient (bool serverOrClient ,quint16 port ,QString IP);
    /**
     * @brief setSizeAndSend
     * @param x
     * @param y
     * @param rundenzahl
     */
    void setSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl);
    /**
     * @brief clientReceived
     * @param xGridSize
     * @param yGridSize
     * @param Rundenzahl
     * @param Beginnender
     */
    void clientReceived(quint8 xGridSize, quint8 yGridSize, quint8 Rundenzahl, quint8 Beginnender);
    /**
     * @brief newRound
     */
    void newRound();
    /**
     * @brief receiveChat
     * @param message
     */
    void receiveChat(QString message);
    /**
     * @brief managerSendChat
     * @param message
     */
    void managerSendChat(QString message);

	
public:
        quint8  _PunkteZahlPlayer1=0;
        quint8  _PunkteZahlPlayer2=0;
		quint8  _zeilen =7;
		quint8  _spalten = 7;
        quint8  _rundenzahl = 1;
        quint8 _rundenzahlCurrent = 0;
		bool    _beginnender;
        bool    _serverOrClient; // 0x00 Server / 0x01 Client
        QString _IPadresse;
        QString _port;
		bool    _gameRunning;
        Spiel*   _spiel;
        Client* _client = nullptr;
        MyTcpServer* _server = nullptr;
        bool _gridIsOn = false;

//		MyStream *_gameChat;
//		MyStream *_player1Chat;
//		MyStream *_player2Chat;
		
		
signals:
        //signalClose();
        /**
         * @brief sendParameters
         */
        void sendParameters(quint8, quint8, quint8, quint8, quint8, quint8);
        /**
         * @brief networkConnects
         */
        void networkConnects(bool);
        /**
         * @brief gameChat
         * @param massage
         */
        void gameChat(QString massage);
        /**
         * @brief createGrid
         */
        void createGrid(quint8, quint8);
        /**
         * @brief gewonnen
         */
        void gewonnen(QString);
        /**
         * @brief setRunde
         */
        void setRunde(quint8);
        /**
         * @brief setRunde2
         */
        void setRunde2(quint8);
        /**
         * @brief setPunkteIch
         */
        void setPunkteIch(quint8);
        /**
         * @brief setPunkteGegner
         */
        void setPunkteGegner(quint8);
        /**
         * @brief disableNextRoundButton
         * @param yesNo
         */
        void disableNextRoundButton(bool yesNo);
        /**
         * @brief toggleNextButton
         * @param yesNo
         */
        void toggleNextButton(bool yesNo);
        //needs to be removed
        /**
         * @brief addStone
         */
        void addStone(int);
        /**
         * @brief resetGraphik
         */
        void resetGraphik();
        /**
         * @brief sendChat
         * @param Cmd
         * @param message
         */

        void sendChat(quint8 Cmd, QString message);
        /**
         * @brief sendChatGrafik
         * @param message
         */
        void sendChatGrafik(QString message);
        /**
         * @brief openChat
         */
        void openChat();
};


#endif
