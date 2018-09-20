/**
 * @file manager.hpp Header file für Manager Klasse
 * @author Simon Näther
 **/
 
 
#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <QWidget>
#include <QApplication>
#include <memory>
#include <array>

enum class stein : char { Player1 , Player2 , zero };

/**
 *  @brief Manager stellt die oberste Logikebene dar
 */
class Manager : public QApplication {
    Q_OBJECT

public:
    /**
     *  @brief Manager Konstruktor und Destruktor
     *
     **/
    explicit Manager(QApplication * parent = nullptr);
    ~Manager();
	
	void spielStart();
	void setServerClient (bool serverOrClient);
	void handleEvent();
	
	/**
     *  @brief beendet das Spiel
     **/
	void quit();
	
	/**
     *  @brief verarbeitet zug des Spielers
     **/
	void insertStein(quint8 x);
	
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
	stein checkWin(quint8 x, quint8 y);
	
	/**
     *  @brief prüft ob Zug zu Unetschieden führt
     **/
	bool checkDraw();
	
	/**
     *  @brief beendet das Spiel
     **/
	void nextRound();
	
	
private:
		quint8  _zeilen =7;
		quint8  _spalten = 7;
		quint8  _rundenzahl = 3;
		bool    _beginnender;
		bool    _serverOrClient;
		qstring _IPadresse;
		qstring _port;
		bool    _gameRunning;
		Spiel*  _spiel
};


/**
 *  @brief Spiel stellt den Spielstand dar
 */
class Spiel {
    Q_OBJECT

public:
    /**
     *  @brief Spiel Konstruktor und Destruktor
     *
     **/
    explicit Spiel(quint8 x, quint8 y, stein beginnenderSpieler);
    ~Spiel();
	

	
	
	
private:
		quint8  	  _rundennummer =1;
		stein   	  _currentPlayer;
		stein[x][y]   _grid;
		const quint8  _x;
		const quint8  _y;
		
		
};

#endif
