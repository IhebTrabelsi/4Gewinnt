#include "spiel.hpp"

Spiel::Spiel(quint8 x, quint8 y,stein startPlayer )
:_x(x), _y(y), _currentPlayer(startPlayer)
{
for(int i=0; i< x ; i++){
    std::vector<stein> s;
    _grid.push_back(s);
    for(int ii=0 ; ii<y; ii++){
        _grid[i].push_back(stein::zero);
    }
}
}



Spiel::~Spiel()
{

}
