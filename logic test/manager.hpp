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
    void serverRequested(void);

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
     *  @brief setzt Stein in Gitter und gibt y-Wert zurück
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
	void checkZug(quint8 x);

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
     * not very smart. Just checks if the grid is full
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
     *
     *  @param[in] number of columms
     *  @param[in] number of lines
     **/
    void setSize(quint8 x, quint8 y);

    /**
     *  @brief handles signal to start next round
     **/
    void setNextRound(qint8 Cmd, qint8 Rundenummer, qint8 BeginnenderRunde);

    /**
     *  @brief creates a sigleplayergame for testpurposes
     **/
    bool testSinglePlayer(void);

    /**
     *  @brief simple output to comandline for testing
     *
     *  prints simple characters to comandline for a grafical representation
     **/
    void printGrid(void);

    /**
     *  @brief sets up the singelplayer
     **/
    void setSingleplayer(void);

    /**
     *  @brief handles insertion of tokens
     *
     *  @param[in] x-coordinate of token
     **/
    bool insertSteinSingle(int x);

    /**
     *  @brief converts a stein enum to a printable string
     *
     *  only for testing porposses
     *
     *  @param[in] stein
     **/
    std::string enum2str(stein e);

    /**
     *  @brief gets imput from comandline
     *
     *  takes only numbers
     **/
    int getNumber();

	
private:
        int  _zeilen =7;                /*!< number of lines of the grid to be created for the next instance if Spiel */
        int  _spalten = 7;              /*!< number of columms of the grid to be created for the next instance if Spiel */
        int  _rundenzahl = 3;           /*!< how many rounds should be played */
        bool    _beginnender;           /*!< to determine the starting player */
        bool    _serverOrClient;        /*!< for creating a server or client at start: false server, true client */
        QString _IPadresse;             /*!< holds ip network instance */
        QString _port;                  /*!< holds port for network instance */
        bool    _gameRunning;           /*!< flag for running game */
        Spiel*   _spiel;                /*!< pointer for datacontainer of running game */
        Client* _client = nullptr;      /*!< pointer for network instance */
        MyTcpServer* _server = nullptr; /*!< pointer for network instance */




		
		
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
