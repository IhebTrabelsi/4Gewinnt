#include "manager.hpp"
#include <stdlib.h> 

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



void setServerClient (bool serverOrClient ,qstring port ,qstring IP){
	if(serverOrClient){
		v = rand() % 2 ; 
		if( v==1){
			_beginnender = true;
		}
		else{
			_beginnender = false;
		}
		//XXX netzwerkbefahl
	}
	else{
		//XXX netzwerkbefahl
	}
}



void spielStart(){
	if( _beginnender){
		*_spiel = Spiel(player1);
	}
	else{
		*_spiel = Spiel(player2);
	}
}



void handleEvent(quint32 netcode){
	quint8 code = netcode >>16;
	switch code {
		case 0x11 :
			quint8 value = netcode;
				switch value {
					case 0x00 :
						nextZug();
						break;
						
					case 0x01 :
						std::cout<<"Du hast gewonnen!"<<std::endl;
						_spiel->_gewonnenSpieler1 ++;
						nextZug();
						nextRound();
						break;
						
					case 0x02 :
						std::cout<<"Unetschieden!"<<std::endl;						
						nextRound();
						break;
						
					case 0x10 :
						std::cout<<"Du warst nicht an der Reihe!"<<std::endl;
						break;
						
					case 0x11 :
						std::cout<<"Außerhalb des Spielfeldes!"<<std::endl;
						break;
						
					case 0x12 :
						std::cout<<"Spalte ist voll!"<<std::endl;
						break;
						
					case 0x13 :
						std::cout<<"kein laufendes Spiel!"<<std::endl;
						break;
					
					case 0x20 :
						std::cout<<"Unbekannter Fehler aufgetreten!"<<std::endl;
						break;
				}
			break;
			
		case 0x03 :
			quint8 x = netcode;
			checkZug(x);
			break;
			
		case 0xXXX :
			std::cout<<"Gegener ist beigetreten."<<std::endl;
			break;
	}
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
	if(_spiel->_currentPlayer == player1 && _gameRunning){
		if(! checkValid(x))break;
		
		quint8 y = setzeStein(x);
		quint32 out = 0x00030100 + x ;
		emit network(out);
		if(checkWin(x, y)){
			std::cout<<"Du hast gewonnen!"<<std::endl;
			nextRound();
		}
	}
	else{
		std::cout<<"Du bist nicht am Zug!"<<std::endl;
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
			nextRound();
		}
		else if(checkWin(x ,y )){
			quint32 out = 0x00110101;
			std::cout<<"Du hast verlohren!"<<std::endl;
			_spiel->_gewonnenSpieler2 ++;
		}
		else{
			quint32 out = 0x00110100;
			nextZug();
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
	for(i=0, i< _spiel->_x ,i++){
		if(_spiel->_grid[i][0] != zero)
			count++
	}
	if(count < (__spiel->_x -2)) return true;
		
	return false;
}



void nextZug(){
	if(_spiel->_currentPlayer == player1){
		_spiel->_currentPlayer = player2;
		std::cout<<"Dein Gegner ist jetzt am Zug."<<std::endl;
	}
	else{
		_spiel->_currentPlayer = player1;
		std::cout<<"Du bist jetzt am Zug."<<std::endl;
	}
}

Spiel::Spiel(stein startPlayer )
:_currentPlayer(startPlayer)
{

}

