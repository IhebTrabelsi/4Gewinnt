#ifndef SPIEL_HPP
#define SPIEL_HPP

#include <QtGlobal>
#include <vector>

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
    quint8  	  _rundennummer =1;
    stein   	  _currentPlayer;
    std::vector<std::vector<stein>> _grid;
    //stein[X_size][Y_size]   _grid = {zero};
    quint8  _x;
    quint8  _y;
};


#endif // SPIEL_HPP

