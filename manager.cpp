#include "manager.hpp"


bool checkWin(quint8 x, quint8 y){
	quint8 count = 1;
	stein player = _grid[x][y];
	quint8 i;//vertikale
	quint8 ii;//horizontale
	
	//prüfe vertikale(|)	
	for(i = x +1;i <= spiel->_y ;i++)//geht nach unten
	{
		if(_grid[i][y] == player)count++;
	}
	if(count >= 4)return true;
	
	//prüfe horizontale(-)
	count = 1;
	for(ii = y -1; ii >= 0;ii--);//geht nach links
	{
		if(_grid[x][ii] == player)count++;
	}
	for(ii = y +1; ii <= spiel->_x;ii++);//geht nach rechts
	{
		if(_grid[x][ii] == player)count++;
	}
	if(count >= 4) return true;
	
	//prüfe diagonaleRechts (\)
	count = 1;
	for(i = x -1, ii= y -1; i >= 0 && ii >=0; i--, ii--);//geht nach schräg oben links
	{
		if(_grid[i][ii] == player)count ++;
	}
	for(i = x +1, ii = y+1; i <= spiel->_x && ii <= spiel->_y ; i++, ii++);//geht nach schräg unten rechts
	{
		if(_grid[i][ii] == player)count ++;
	}
	if(count >= 4) return true;
	
	//prüfe diagonaleLinks(/)
	count = 1;
	for(i = x -1, ii= y +1; i>=0 && ii <= spiel->_y;  i--, ii++);//geht nach schräg oben rechts
	{
		if(_grid[i][ii] == player)count++;
	}
	for(i = x +1, ii= y -1;i <= spiel->_x && ii >=0; i++, ii--);//geht nach schräg unten links
	{
		if(_grid[i][ii] == player)count++;
	}
	if(count >= 4) return true;
	
	return false;
}



bool checkDraw(){
	quint8 count = 0;
	for(i=0, i< _spiel->_x ,i++){
		if(_spiel->_grid[i][0] != zero)
			count++
	}
	if(count < (_spiel->_x -2)) return true;
		
	return false;
}
