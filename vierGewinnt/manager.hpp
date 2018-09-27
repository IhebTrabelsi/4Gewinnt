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

  //  /**
  //   *  @brief sends gamedata to a recently connected client (obsolete)
  //   **/
  //  void serverRequested(void); // made obsolete by setSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl)

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
    void insertStein(int x);

	/**
     *  @brief sets toke in grid and returns y-coordinate of set token
     *
     *  @param[in] x-coordinate of token to be placed
     *  @return y-coordinate of token to be placed
     **/
    int setStein(int x);

	/**
     *  @brief handles opponents turn
     *
     *  @param[in] x-coordinate of placed token
     **/
    void checkZug(int x);

	/**
     *  @brief checks if a turn is allowed
     *
     *  @param[in] x-coordinate of token to be placed
     *  @return true turn ok
     **/
    bool checkValid(int x);

	/**
     *  @brief checks if current turn is a winning one
     *
     *  @param[in] x-coordinate of newly placed token
     *  @param[in] y-coordinate of newly placed token
     *  @return true for a win
     **/
    bool checkWin(int x, int y);

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
    int          _zeilen =7;            /*!< number of lines of the grid to be created for the next instance if Spiel */
    int          _spalten = 7;          /*!< number of columms of the grid to be created for the next instance if Spiel */
    int          _rundenzahl = 3;       /*!< how many rounds should be played */
    bool         _beginnender;          /*!< to determine the starting player */
    bool         _serverOrClient;       /*!< for creating a server or client at start: false server, true client */
    QString      _IPadresse;            /*!< holds ip network instance */
    QString      _port;                 /*!< holds port for network instance */
    bool         _gameRunning;          /*!< flag for running game */
    Spiel*       _spiel;                /*!< pointer for datacontainer of running game */
    Client*      _client = nullptr;     /*!< pointer for network instance */
    MyTcpServer* _server = nullptr;     /*!< pointer for network instance */
		
		
signals:
        //signalClose();
        void networkServer(quint8 , quint8, quint8);                                    /*!< to hand over information for creating gameflow-controling signals to networkinstance */
        void networkClient(quint8 , quint8, quint8);                                    /*!< to hand over information for creating gameflow-controling signals to networkinstance */
        void closeSignal();                                                             /*!< signal to quit programm */
        void sendParameters(quint8, quint8, quint8, quint8, quint8, quint8);            /*!< hands parameters to be send over to network instance */
        void paint(quint8 x, quint8 y, stein spieler);                                  /*!< hands information for newly inserted token to grafic to be displayed */
        void gameChat(QString massage);                                                 /*!< hands chatmassages to grafic */
        void signalNextRound(quint8 Cmd, quint8 roundNumber, quint8 startingPlayer);    /*!< hands parameters to be send over to network instance to request a new round-start */
        void networkConnects(bool);                                                     /*!< hands connection status to network instance */
};


#endif
