#ifndef SPIEL_HPP
#define SPIEL_HPP

#include <QtGlobal>
#include <vector>

/**
 * @file spiel.hpp headerfile for Spiel class
 * @author Simon Näther
 **/

enum class stein : char { Player1 , Player2 , zero }; /*!< tokens for the grid */

/**
 *  @brief represents the gamestate as a datacontainer
 */
//template<size_t X_size, size_t Y_size>  //there was once the intent to use an array for performance insted of a vector of voctors
class Spiel {
    friend class Manager;
public:
    /**
     *  @brief Spiel constructor und destructor
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

