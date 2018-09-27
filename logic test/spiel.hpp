#ifndef SPIEL_HPP
#define SPIEL_HPP

#include <QtGlobal>
#include <vector>

/**
 * @file spiel.hpp headerfile for Spiel class
 * @author Simon Näther
 **/


enum class stein : char { Player1 , Player2 , zero };

/**
 *  @brief Spiel stellt den Spielstand dar
 */
//template<size_t X_size, size_t Y_size>
class Spiel {
    friend class Manager;
public:
    /**
     *  @brief Spiel Konstruktor und Destruktor
     *
     **/
    explicit Spiel(quint8 x, quint8 y, stein startPlayer);
    ~Spiel();

private:
    int                              _rundennummer =1;     /*!< number of round that is currently played */
    stein                            _currentPlayer;       /*!< flag to mark current player */
    std::vector<std::vector<stein>>  _grid;                /*!< to represent the playing field */
    const int                        _x;                   /*!< number of columms */
    const int                        _y;                   /*!< number of rows */
    int                              _gewonnenSpieler1 =0; /*!< counter for won games by player1 */
    int                              _gewonnenSpieler2 =0; /*!< counter for won games by player2 */
};


#endif // SPIEL_HPP

