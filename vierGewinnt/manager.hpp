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
 * @author Simon Näther
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
    explicit Manager(QWidget *parent = 0);
    ~Manager();

public slots:

    /**
     *  @brief  creates a server or client-objekt and determens the startingplayer
     *
     *  @param[in] true creates server and false a client
     *  @param[in] portnumber to be used
     *  @param[in] IP-adress to be used
     **/
    void setServerClient (bool serverOrClient ,quint16 port ,QString IP);

    /**
     *  @brief creates ojekt of Spiel class as a datacontainer for the gamestate
     **/
	void spielStart();

    /**
     *  @brief sends gamedata to a recently connected client
     **/
    //void serverRequested(void); // not needed anymore check setSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl)

    /**
     *  @brief saves gamedate send from another server
     *
     *  @param[in] Cmd is not used in this function (exists for copatibility reasons)
     *  @param[in] number of columms for gridsize
     *  @param[in] number of lines for gridsize
     *  @param[in] number of rounds to be played
     *  @param[in] starting player: 0->server 1->client
     **/
    void clientReceived(qint8 Cmd, qint8 x, qint8 y, qint8 rundenzahl, qint8 startinPlayer);

    /**
     *  @brief handles incomming networkevents
     *
     *  @param[in] networkcode identifier
     *  @param[in] value of the incomming command
     **/
    void handleEvent(quint8 code, quint8 value);

	/**
     *  @brief quits the game /programm (if no game running)
     **/
	void quit();

	/**
     *  @brief handles players turn
     *
     *  @param[in] x-coordinate of token to be placed
     **/
	void insertStein(quint8 x);

	/**
     *  @brief setzt Stein in Gitter und gibt y-Wert zurück
     *
     *  @param[in] x-coordinate of token to be placed
     *  @return y-coordinate of token to be placed
     **/
    quint8 setStein(quint8 x);

	/**
     *  @brief handles opponents turn
     *
     *  @param[in] x-coordinate of placed token
     **/
	void checkZug(quint8 x);

	/**
     *  @brief checks if a turn is allowed
     *
     *  @param[in] x-coordinate of token to be placed
     *  @return true turn ok
     **/
	bool checkValid(quint8 x);

	/**
     *  @brief checks if current turn is a winning one
     *
     *  @param[in] x-coordinate of newly placed token
     *  @param[in] y-coordinate of newly placed token
     *  @return true for a win
     **/
	bool checkWin(quint8 x, quint8 y);

	/**
     *  @brief checks if current turn forces a draw
     *
     *  @return true for a draw
     **/
	bool checkDraw();

	/**
     *  @brief ends the current round and sets up a new one if total number of rounds to be played isn#t reached yet
     *
     *  @param[in] true to change starting player for next round
     **/
    void nextRound(bool change);

	/**
     *  @brief changes which players turn it is
     **/
	void nextZug();

    /**
     *  @brief sets gridsize for the next game
     * and sends the first parameters and sets the roundnumber
     *
     *  @param[in] number of columms
     *  @param[in] number of lines
     **/
    void setSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl);

    /**
     *  @brief handles signal to start next round
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

        void networkConnects(bool);
};


#endif
