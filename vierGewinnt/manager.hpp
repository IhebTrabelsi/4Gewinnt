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

	void spielStart();
    void handleEvent(quint8 code, quint8 value); 
	void quit();
    void insertStein(quint8 x);
    int setStein(int x);
    void checkZug(int x);
	bool checkValid(quint8 x);
    bool checkWin(int x, int y);
	bool checkDraw();
	void nextZug();
    //void setNextRound(quint8 Cmd, quint8 Rundenummer, quint8 BeginnenderRunde);

    void setServerClient (bool serverOrClient ,quint16 port ,QString IP);
    void setSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl);
    void clientReceived(quint8 xGridSize, quint8 yGridSize, quint8 Rundenzahl, quint8 Beginnender);
    //void StartRunde(quint8 Rundenummer, quint8 BeginnenderRunde);
    void newRound();

	
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

        void sendParameters(quint8, quint8, quint8, quint8, quint8, quint8);
        void networkConnects(bool);
        void gameChat(QString massage);
        void createGrid(quint8, quint8);
        void gewonnen(QString);
        void setRunde(quint8);
        void setRunde2(quint8);
        void setPunkteIch(quint8);
        void setPunkteGegner(quint8);
        void disableNextRoundButton(bool yesNo);
        void toggleNextButton(bool yesNo);
        //needs to be removed
        void networkServer(quint8, quint8,quint8);
        void networkClient(quint8, quint8,quint8);
        void addStone(int);
        void resetGraphik();

};


#endif
