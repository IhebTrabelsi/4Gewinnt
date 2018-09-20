#include "manager.hpp"


Manager::Manager(QApplication *parent) :
    QApplication(parent),
    ui(new Ui::Manager))
{
	ui->setupUi(this);
	
	connect(_pbXXXClose, SIGNAL(clicked()), this, SLOT(quit()));
	connect(this, &Manager::closeSignal, this, SLOT(close()));


///Chat Funktionalität
_gameChat = new MyStream("GAME: " + std::cout, ui->tbXXXOut);
_player1Chat = new MyStream("->" + XXX , ui->tbXXXOut);
_player2Chat = new MyStream("<-" + XXX , ui->tbXXXOut);

}



Manager::~Manager()
{
    delete ui;
	delete _gameChat;
	delete _player1Chat;
	delete _player2Chat;
}




void quit(){
	if(_gameRunning){
		_spiel->~Spiel();
		_spiel = nullptr;
		_gameRunning = false;
		std::cout<<"Laufendes Spiel abgebrochen!"<<std::endl;
		//XXX verbindung trennen
	}
	else{
		emit closeSignal();
	}
}



void insertStein(quint8 x){
	if(! checkValid(x))break;
		
	quint8 y = setzeStein(x);
	//emit signal an netzwerk(x);
	if(checkWin(x, y)){
		std::cout<<"Du hast gewonnen!"<<std::endl;
		nextRound();
	}
}



quint8 setzeStein(quint8 x){
	quint8 count=0;
	while(_spiel->_grid[x][count] == zero) count++;
	
	_spiel->_grid[x][count] = _spiel->_currentPlayer;
	return count;
}



void checkZug(quint8 x){
	if(! checkValid(x)){
		if(_spiel->_grid[x][0] !=){
			quint32 out = 0x00110112;
		}
		else{
			quint32 out = 0x00110111;
		}
		emit network(out);
	}
	else{
		quint8 y = setzeStein(x);
		if(checkDraw()){
			quint32 out = 0x00110102;
			std::cout<<"Unentschieden!"<<std::endl;
		}
		else if(checkWin(x ,y )){
			quint32 out = 0x00110101;
			std::cout<<"Du hast verlohren!"<<std::endl;
		}
		else{
			quint32 out = 0x00110100;
		}
		emit network(out);
		
	}
}



bool checkValid(quint8 x){
	if(x < 0 || x > _spiel->_x){
		std::cout<<"Stein wurde neben das Gitter geworfen!"<<std::endl;
		return false;
	}
	
	if(_spiel->_grid[x][0] != zero){
		std::cout<<"Stein wurde in eine bereits volle Spalte geworfen!"<<std::endl;
		return false;
	}
	
	return true;	
	
}



bool checkWin(quint8 x, quint8 y){
	quint8 count = 1;
	stein player = _spiel->_grid[x][y];
	quint8 i;///vertikale
	quint8 ii;///horizontale
	
	///prüfe vertikale(|)	
	for(i = x +1;i <= _spiel->_y ;i++)///geht nach unten
	{
		if(_spiel->_grid[i][y] == player)count++;
	}
	if(count >= 4)return true;
	
	///prüfe horizontale(-)
	count = 1;
	for(ii = y -1; ii >= 0;ii--);///geht nach links
	{
		if(_spiel->_grid[x][ii] == player)count++;
	}
	for(ii = y +1; ii <= _spiel->_x;ii++);///geht nach rechts
	{
		if(_spiel->_grid[x][ii] == player)count++;
	}
	if(count >= 4) return true;
	
	///prüfe diagonaleRechts (\)
	count = 1;
	for(i = x -1, ii= y -1; i >= 0 && ii >=0; i--, ii--);///geht nach schräg oben links
	{
		if(_spiel->_grid[i][ii] == player)count ++;
	}
	for(i = x +1, ii = y+1; i <= _spiel->_x && ii <= _spiel->_y ; i++, ii++);///geht nach schräg unten rechts
	{
		if(_spiel->_grid[i][ii] == player)count ++;
	}
	if(count >= 4) return true;
	
	///prüfe diagonaleLinks(/)
	count = 1;
	for(i = x -1, ii= y +1; i>=0 && ii <= _spiel->_y;  i--, ii++);///geht nach schräg oben rechts
	{
		if(_spiel->_grid[i][ii] == player)count++;
	}
	for(i = x +1, ii= y -1;i <= _spiel->_x && ii >=0; i++, ii--);///geht nach schräg unten links
	{
		if(_spiel->_grid[i][ii] == player)count++;
	}
	if(count >= 4) return true;
	
	return false;
}



bool checkDraw(){
	quint8 count = 0;
	for(i=0, i< __spiel->_x ,i++){
		if(__spiel->_spiel->_grid[i][0] != zero)
			count++
	}
	if(count < (__spiel->_x -2)) return true;
		
	return false;
}



void nextZug(){
	
}
