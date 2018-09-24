#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <QObject>
#include <QWidget>
#include <memory>
#include <iostream>
#include "spiel.hpp"
#include "mytcpserver.h"
#include "client.h"


/**
 * @file manager.hpp Header file für Manager Klasse
 * @author Simon Näther
 **/



/**
 *  @brief Manager stellt die oberste Logikebene dar
 */
class Manager: public QObject {
    Q_OBJECT

public:
    /**
     *  @brief Manager Konstruktor und Destruktor
     *
     **/
    explicit Manager(QWidget *parent = 0);
    ~Manager();

public slots:
    void setServerClient (bool serverOrClient ,quint16 port ,QString IP);
	void spielStart();

    /**
     *  @brief bearbeitet Anfrage eines Clients
     **/
    void serverRequested(void);

    /**
     *  @brief bearbeitet vom Server gesandete Spielparameter
     **/
    void clientReceived(qint8 Cmd, qint8 x, qint8 y, qint8 Rundenzahl, qint8 Beginnender);

    void handleEvent(quint8 code, quint8 value);

	/**
     *  @brief beendet das Spiel
     **/
	void quit();
	/**
     *  @brief verarbeitet zug des Spielers
     **/
	void insertStein(quint8 x);
	/**
     *  @brief setzt stein in Gitter und gibt y-Wert zurück
     **/
	quint8 setzeStein(quint8 x);
	/**
     *  @brief verarbeitet generischen Zug
     **/
	void checkZug(quint8 x);
	/**
     *  @brief prüft ob Zug erlaubt
     **/
	bool checkValid(quint8 x);
	/**
     *  @brief prüft ob Zug die Runde gewinnt
     **/
	bool checkWin(quint8 x, quint8 y);
	/**
     *  @brief prüft ob Zug zu Unetschieden führt
     **/
	bool checkDraw();
	/**
     *  @brief beendet die Runde
     **/
    void nextRound(bool change);
	/**
     *  @brief Zugwechsel
     **/
	void nextZug();

    /**
     *  @brief ändert Spielfeldgröße
     **/
    void setSize(quint8 x, quint8 y);

    /**
     *  @brief ändert Spielfeldgröße
     **/
    void setNextRound(qint8 Cmd, qint8 Rundenummer, qint8 BeginnenderRunde);



	
public:
		quint8  _zeilen =7;
		quint8  _spalten = 7;
		quint8  _rundenzahl = 3;
		bool    _beginnender;
        bool    _serverOrClient; // 0x00 Server / 0x01 Client
        QString _IPadresse;
        QString _port;
		bool    _gameRunning;
        Spiel*   _spiel;
        Client* _client = nullptr;
        MyTcpServer* _server = nullptr;

//		MyStream *_gameChat;
//		MyStream *_player1Chat;
//		MyStream *_player2Chat;
		
		
signals:
        //signalClose();
        void networkServer(quint8 , quint8, quint8);
        void networkClient(quint8 , quint8, quint8);
        void closeSignal();
        void sendParameters(quint8, quint8, quint8, quint8, quint8, quint8);
        void paint(quint8 x, quint8 y, stein spieler);
        void gameChat(QString massage);
        void signalNextRound(quint8, quint8, quint8);
};


#endif
