#include "manager.hpp"
#include <stdlib.h> 


Manager::Manager(QWidget *parent)
{

	
    //connect(_pbXXXClose, SIGNAL(clicked()), this, SLOT(quit()));
    //connect(this, &Manager::closeSignal, this, SLOT(close()));

/*
///Chat Funktionalität
_gameChat = new MyStream("GAME: " + std::cout, ui->tbXXXOut);
_player1Chat = new MyStream("->" + XXX , ui->tbXXXOut);
_player2Chat = new MyStream("<-" + XXX , ui->tbXXXOut);
*/
}



Manager::~Manager()
{
    //delete ui;
    //delete _gameChat;
    //delete _player1Chat;
    //delete _player2Chat;
}



void Manager::setServerClient (bool serverOrClient ,quint16 port ,QString IP){
	if(serverOrClient){
        int v = rand() % 2 ;
		if( v==1){
            _beginnender = true;
            MyTcpServer server(port);
            _server = &server;
		}
		else{
            _beginnender = false;
            MyTcpServer server(port);
            _server = &server;
		}
	}
	else{
        Client client(IP , port);
        _client = &client;
	}
}



void Manager::serverRequested(void){
    quint8 val;
    if(_beginnender)val = 0x00;
    else val = 0x01;
    emit sendParameters(0x01, 0x04, _spalten, _zeilen, _rundenzahl, val);

}



void Manager::clientResieved(void){}



void Manager::spielStart(){
	if( _beginnender){
        _spiel = new Spiel(_spalten, _zeilen, stein::Player1);
	}
	else{
        _spiel = new Spiel(_spalten, _zeilen, stein::Player2);
	}
}



void Manager::handleEvent(quint8 code, quint8 value){

    switch(code) {
        case 0x11 :{

                switch(value) {
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
            break;}
			
		case 0x03 :		
            checkZug(value);
			break;
			
//		case 0xXXX :
//			std::cout<<"Gegener ist beigetreten."<<std::endl;
//			break;
	}
}



void Manager::quit(){
	if(_gameRunning){
        delete _spiel;
		_gameRunning = false;
		std::cout<<"Laufendes Spiel abgebrochen!"<<std::endl;
        if(_serverOrClient){
            _server->disconnectTheClient();
            delete _server;
        }
        else{
            _client->disconnectFromServer();
            delete _client;
        }
	}
	else{
		emit closeSignal();
	}
}



void Manager::insertStein(quint8 x){
    if(_spiel->_currentPlayer == stein::Player1 && _gameRunning){
        if(! checkValid(x))return;
		
		quint8 y = setzeStein(x);
        //quint32 out = 0x00030100 + x ;
        emit network(0x03, 0x01, x); //XXX
		if(checkWin(x, y)){
			std::cout<<"Du hast gewonnen!"<<std::endl;
			nextRound();
		}
	}
	else{
		std::cout<<"Du bist nicht am Zug!"<<std::endl;
	}
}



quint8 Manager::setzeStein(quint8 x){
	quint8 count=0;
    while(_spiel->_grid[x][count] == stein::zero) count++;
	
	_spiel->_grid[x][count] = _spiel->_currentPlayer;
	return count;
}



void Manager::checkZug(quint8 x){
	if(! checkValid(x)){
        if(_spiel->_grid[x][0] != stein::zero){
            emit network(0x11, 0x01, 0x12);
		}
		else{
            emit network(0x11, 0x01, 0x11);
		}

	}
	else{
		quint8 y = setzeStein(x);
		if(checkDraw()){
			std::cout<<"Unentschieden!"<<std::endl;
			nextRound();
            emit network(0x11, 0x01 ,0x02);
		}
		else if(checkWin(x ,y )){
			std::cout<<"Du hast verlohren!"<<std::endl;
            _spiel->_gewonnenSpieler2 ++;
            emit network(0x11, 0x01, 0x01);
		}
		else{
			nextZug();
            emit network(0x11, 0x01, 0x00);
		}

	}
}



bool Manager::checkValid(quint8 x){
	if(x < 0 || x > _spiel->_x){
		std::cout<<"Stein wurde neben das Gitter geworfen!"<<std::endl;
		return false;
	}
	
    if(_spiel->_grid[x][0] != stein::zero){
		std::cout<<"Stein wurde in eine bereits volle Spalte geworfen!"<<std::endl;
		return false;
	}
	
	return true;	
	
}



bool Manager::checkWin(quint8 x, quint8 y){
	quint8 count = 1;
	stein player = _spiel->_grid[x][y];
	quint8 i;///vertikale
	quint8 ii;///horizontale

	
	///prüfe vertikale(|)	
	for(i = x +1;i <= _spiel->_y ;i++)///geht nach unten
	{
		if(_spiel->_grid[i][y] == player)count++;
        if(_spiel->_grid[i][y] != player)break;
	}
	if(count >= 4)return true;
	
	///prüfe horizontale(-)
	count = 1;
    for(ii = y -1; ii >= 0;ii--)///geht nach links
	{
		if(_spiel->_grid[x][ii] == player)count++;
        if(_spiel->_grid[x][ii] != player)i=0;
	}
    for(ii = y +1; ii <= _spiel->_x;ii++)///geht nach rechts
	{
		if(_spiel->_grid[x][ii] == player)count++;
        if(_spiel->_grid[x][ii] != player)ii = _spiel->_x +1;
	}
	if(count >= 4) return true;
	
	///prüfe diagonaleRechts (\)
	count = 1;
    for(i = x -1, ii= y -1; i >= 0 && ii >=0; i--, ii--)///geht nach schräg oben links
	{
		if(_spiel->_grid[i][ii] == player)count ++;
        if(_spiel->_grid[i][ii] != player)i = 0;
	}
    for(i = x +1, ii = y+1; i <= _spiel->_x && ii <= _spiel->_y ; i++, ii++)///geht nach schräg unten rechts
	{
		if(_spiel->_grid[i][ii] == player)count ++;
        if(_spiel->_grid[i][ii] != player)i = _spiel->_x +1;
	}
	if(count >= 4) return true;
	
	///prüfe diagonaleLinks(/)
	count = 1;
    for(i = x -1, ii= y +1; i>=0 && ii <= _spiel->_y;  i--, ii++)///geht nach schräg oben rechts
	{
		if(_spiel->_grid[i][ii] == player)count++;
        if(_spiel->_grid[i][ii] != player)i = 0;
	}
    for(i = x +1, ii= y -1;i <= _spiel->_x && ii >=0; i++, ii--)///geht nach schräg unten links
	{
		if(_spiel->_grid[i][ii] == player)count++;
        if(_spiel->_grid[i][ii] != player)ii = 0;
	}
	if(count >= 4) return true;
	
	return false;
}



bool Manager::checkDraw(){
	quint8 count = 0;
    for(int i=0; i< _spiel->_x ;i++){
        if(_spiel->_grid[i][0] != stein::zero)
            count++;
	}
    if(count < (_spiel->_x -2)) return true;
		
	return false;
}



void Manager::nextRound(){

}



void Manager::nextZug(){
    if(_spiel->_currentPlayer == stein::Player1){
        _spiel->_currentPlayer = stein::Player2;
		std::cout<<"Dein Gegner ist jetzt am Zug."<<std::endl;
	}
	else{
        _spiel->_currentPlayer = stein::Player1;
		std::cout<<"Du bist jetzt am Zug."<<std::endl;
	}
}




