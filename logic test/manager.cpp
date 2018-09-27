#include "manager.hpp"
#include <stdlib.h> 
#include <string.h>
#include <limits>


/**
 * @file manager.cpp implementation of Manager class functions
 * @author Simon Näther
 **/



Manager::Manager(QWidget *parent)
{

	

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
            _server = new MyTcpServer(port);
        }
		else{
            _beginnender = false;
            _server = new MyTcpServer(port);
		}
	}
	else{
        _client = new Client(IP , port);
	}
}



void Manager::serverRequested(void){
    quint8 val;
    if(_beginnender)val = 0x00;
    else val = 0x01;
   ;//emit sendParameters(0x01, 0x04, _spalten, _zeilen, _rundenzahl, val);
   ;//emit gameChat("GAME:  Gegner Verbunden!"); //<<std::endl;
}



void Manager::clientReceived(qint8 Cmd, qint8 spalten, qint8 zeilen, qint8 rundenzahl, qint8 startinPlayer){
    if(startinPlayer = 0x00)_beginnender= true;
    else _beginnender =false;

    _spalten = spalten;
    _zeilen = zeilen;
    _rundenzahl = rundenzahl;

    if(! _serverOrClient);//emit networkServer(0x10, 0x01, 0x00);
    else;//emit networkClient(0x10, 0x01, 0x00);
    spielStart();
}



void Manager::spielStart(){
    if(! _beginnender){
        _spiel = new Spiel(_spalten, _zeilen, stein::Player1);
        _gameRunning = true;
	}
	else{
        _spiel = new Spiel(_spalten, _zeilen, stein::Player2);
        _gameRunning = true;
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
                       ;//emit gameChat("GAME:  Du hast gewonnen!"); //<<std::endl;
						_spiel->_gewonnenSpieler1 ++;
						nextZug();
                        nextRound(true);
						break;
						
					case 0x02 :
                       ;//emit gameChat("GAME:  Unetschieden!"); //<<std::endl;
                        nextRound(false);
						break;
						
					case 0x10 :
                       ;//emit gameChat("GAME:  Du warst nicht an der Reihe!"); //<<std::endl;
						break;
						
					case 0x11 :
                       ;//emit gameChat("GAME:  Außerhalb des Spielfeldes!"); //<<std::endl;
						break;
						
					case 0x12 :
                       ;//emit gameChat("GAME:  Spalte ist voll!"); //<<std::endl;
						break;
						
					case 0x13 :
                       ;//emit gameChat("GAME:  kein laufendes Spiel!"); //<<std::endl;
						break;
					
					case 0x20 :
                       ;//emit gameChat("GAME:  Unbekannter Fehler aufgetreten!"); //<<std::endl;
						break;
				}
            break;}
			
		case 0x03 :		
            checkZug(value);
			break;
			
//		case 0xXXX :
//			;//emit gameChat("GAME:  Gegener ist beigetreten."); //<<std::endl;
//			break;
	}
}



void Manager::quit(){
	if(_gameRunning){
        delete _spiel;
		_gameRunning = false;
       ;//emit gameChat("GAME:  Laufendes Spiel abgebrochen!"); //<<std::endl;
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
       ;//emit closeSignal();
	}
}



void Manager::insertStein(int x){
    if(_spiel->_currentPlayer == stein::Player1 && _gameRunning){
        if(! checkValid(x))return;
		
        int y = setStein(x);
        //quint32 out = 0x00030100 + x ;
        if(! _serverOrClient);//emit networkServer(0x03, 0x01, x);
        else;//emit networkClient(0x03, 0x01, x);
		if(checkWin(x, y)){
           ;//emit gameChat("GAME:  Du hast gewonnen!"); //<<std::endl;
            nextRound(true);
		}
	}
	else{
       ;//emit gameChat("GAME:  Du bist nicht am Zug!"); //<<std::endl;
	}
}



int Manager::setStein(int x){
    //std::cout<<"setStein"<<std::endl;
    int count=0;
    //std::cout<<x<<std::endl;
    while(_spiel->_grid[x][count] == stein::zero && count < _spiel->_y){++count;}

    //std::cout << "before: " << enum2str(_spiel->_grid[x][count]) << std::endl; //for testing
    _spiel->_grid[x][count-1] = _spiel->_currentPlayer;

    //std::cout << "after: " << enum2str(_spiel->_grid[x][count]) << std::endl;  //for testing

    //Z;//emit paint(x, count, _spiel->_currentPlayer);
    return count-1;
}





void Manager::checkZug(int x){
	if(! checkValid(x)){
        if(_spiel->_grid[x][0] != stein::zero){
            if(! _serverOrClient);//emit networkServer(0x11, 0x01, 0x12);
            else;//emit networkClient(0x11, 0x01, 0x12);
		}
		else{
            if(! _serverOrClient);//emit networkServer(0x11, 0x01, 0x11);
            else;//emit networkClient(0x11, 0x01, 0x11);
		}

	}
	else{
        int y = setStein(x);
		if(checkDraw()){
           ;//emit gameChat("GAME:  Unentschieden!"); //<<std::endl;
            nextRound(false);
            if(! _serverOrClient);//emit networkServer(0x11, 0x01 ,0x02);
            else;//emit networkClient(0x11, 0x01 ,0x02);
		}
		else if(checkWin(x ,y )){
           ;//emit gameChat("GAME:  Du hast verlohren!"); //<<std::endl;
            _spiel->_gewonnenSpieler2 ++;
            if(! _serverOrClient);//emit networkServer(0x11, 0x01, 0x01);
            else;//emit networkClient(0x11, 0x01, 0x01);
		}
		else{
			nextZug();
            if(! _serverOrClient);//emit networkServer(0x11, 0x01, 0x00);
            else;//emit networkClient(0x11, 0x01, 0x00);
		}

	}
}



bool Manager::checkValid(int x){
    if(x < 0 || x > _spiel->_x-1){
       ;//emit gameChat("GAME:  Stein wurde neben das Gitter geworfen!"); //<<std::endl;
		return false;
	}
	
    if(_spiel->_grid[x][0] != stein::zero){
       ;//emit gameChat("GAME:  Stein wurde in eine bereits volle Spalte geworfen!"); //<<std::endl;
		return false;
	}
	
	return true;	
	
}



bool Manager::checkWin(int x, int y){
    int count = 1;
	stein player = _spiel->_grid[x][y];
    int i;///vertikale
    int ii;///horizontale


    ///checks verticaly(|)
    if(y < _spiel->_y){
        for(ii = y+1 ;ii < _spiel->_y ;++ii)///looks down
        {
          if(_spiel->_grid[x][ii] == player)count++;
          if(_spiel->_grid[x][ii] != player)break;
        }
        if(count >= 4)return true;
    }

    ///checks horizontaly(-)
	count = 1;
    for(i = x -1; i >= 0;--i)///looks left
	{
        if(_spiel->_grid[i][y] == player)count++;
        if(_spiel->_grid[i][y] != player)i=0;
	}
    for(i = x +1; i < _spiel->_x;++i)///looks right
	{
        if(_spiel->_grid[i][y] == player)count++;
        if(_spiel->_grid[i][y] != player)i = _spiel->_x +1;
	}
	if(count >= 4) return true;
	
    ///checks right slope (\)
	count = 1;
    for(i = x -1, ii= y -1; i >= 0 && ii >=0; --i, --ii)///looks in the direction of upper left corner
	{
		if(_spiel->_grid[i][ii] == player)count ++;
        if(_spiel->_grid[i][ii] != player)i = 0;
	}
    for(i = x +1, ii = y+1; i < _spiel->_x && ii < _spiel->_y ; ++i, ++ii)///looks in the direction of lower right corner
	{
		if(_spiel->_grid[i][ii] == player)count ++;
        if(_spiel->_grid[i][ii] != player)i = _spiel->_x +1;
	}
	if(count >= 4) return true;
	
    ///checks left slope(/)
	count = 1;
    for(i = x -1, ii= y +1; i>=0 && ii < _spiel->_y;  --i, ++ii)///looks in the direction of lower left corner
	{
		if(_spiel->_grid[i][ii] == player)count++;
        if(_spiel->_grid[i][ii] != player)i = 0;
	}
    for(i = x +1, ii= y -1;i < _spiel->_x && ii >=0; ++i, --ii)///looks in the direction of upper right corner
	{
		if(_spiel->_grid[i][ii] == player)count++;
        if(_spiel->_grid[i][ii] != player)ii = 0;
	}
	if(count >= 4) return true;
	
	return false;
}



bool Manager::checkDraw(){
    int count = 0;
    for(int i=0; i< _spiel->_x ;i++){
        if(_spiel->_grid[i][0] != stein::zero)
            count++;
	}
    if(count > (_spiel->_x -1)) return true;
		
	return false;
}



void Manager::nextRound(bool change){
 //XXX
   if(change){
       if(_spiel->_currentPlayer == stein::Player1)_spiel->_currentPlayer = stein::Player2;
       if(_spiel->_currentPlayer == stein::Player2)_spiel->_currentPlayer = stein::Player1;
   }
   quint8 beginnender;
   if(_client == nullptr && _spiel->_currentPlayer == stein::Player2)beginnender = 0x01;
   if(_client == nullptr && _spiel->_currentPlayer == stein::Player1)beginnender = 0x00;
   if(_server == nullptr && _spiel->_currentPlayer == stein::Player2)beginnender = 0x00;
   if(_server == nullptr && _spiel->_currentPlayer == stein::Player1)beginnender = 0x01;

   //XXX;//emit
}



void Manager::nextZug(){
    if(_spiel->_currentPlayer == stein::Player1){
        _spiel->_currentPlayer = stein::Player2;
       ;//emit gameChat("GAME:  Dein Gegner ist jetzt am Zug."); //<<std::endl;
	}
	else{
        _spiel->_currentPlayer = stein::Player1;
       ;//emit gameChat("GAME:  Du bist jetzt am Zug."); //<<std::endl;
	}
}


void Manager::setSize(quint8 x, quint8 y){
    _spalten = x;
    _zeilen = y;
}

void Manager::setNextRound(qint8 Cmd, qint8 Rundenummer, qint8 BeginnenderRunde){
    if(BeginnenderRunde && _serverOrClient)_spiel->_currentPlayer = stein::Player1;
    else _spiel->_currentPlayer = stein::Player2;
    _spiel->_rundennummer = Rundenummer;
}

void Manager::printGrid(void){
    //std::cout << "element00 " << enum2str(_spiel->_grid[0][0]) << std::endl; //debug
    for(int ii=1; ii<= _spiel->_x; ii++)std::cout<<"  "<< ii<< "  "<<std::flush;
    std::cout<<std::endl;
    for(int ii=0; ii< _spiel->_x; ii++)std::cout<<"-----"<<std::flush;
    std::cout<<std::endl;
    for(int i =0; i< _spiel->_y; i++){       ///parses grid line after line
        for(int ii=0; ii< _spiel->_x; ii++){
            if(_spiel->_grid[ii][i] == stein::Player1)std::cout<<"  A  "<<std::flush;
            else if(_spiel->_grid[ii][i] == stein::Player2)std::cout<<"  B  "<<std::flush;
            else if(_spiel->_grid[ii][i] == stein::zero)std::cout<<"  O  "<<std::flush;
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
    for(int ii=0; ii< _spiel->_x; ii++)std::cout<<"====="<<std::flush;
    std::cout<<std::endl;
    std::cout<<std::endl;
}

bool Manager::testSinglePlayer(void){
    if(_spiel->_currentPlayer == stein::Player1)std::cout<<"Player A please insert a token:"<<std::endl;
    else std::cout<<"Player B please insert a token:"<<std::endl;

    int x = getNumber()-1;
    //std::cout << x << std::endl; //debug
    if(checkValid(x)){
        bool flag = insertSteinSingle(x);
        printGrid();
        return flag;
    }
    else{
        std::cout<<"Invalid turn! Please try again."<<std::endl;
        bool flag = testSinglePlayer();
        return flag;
    }
}

void Manager::setSingleplayer(void){
    std::cout<<"How many collums is the game soppused to have?"<<std::endl;
    //std::cout << number << std::endl; //debug
    _spalten = getNumber();
    std::cout<<"How many lines is the game soppused to have?"<<std::endl;
    _zeilen = getNumber();
    /*std::cin>>number;
    std::cout<<"Would you like to begin? (0->no 1->yes)"<<std::endl; //old stuff
    std::cin>>number;
    if(number==0)_beginnender = false;*/
    _beginnender = false;
    spielStart();
}


std::string Manager::enum2str(stein e){
    if (e == stein::zero){
        return "zero";
    }
    if (e == stein::Player1){
        return "player1";
    }
    if (e == stein::Player2){
        return "player2";
    }
    else return "no stein";
}

bool Manager::insertSteinSingle(int x){
    int y = setStein(x);

    if(checkDraw()){
        std::cout<<"It's a Draw! (no Trap this time Ackbar...)"<<std::endl;
        return false;
    }
    if(checkWin(x ,y)){
        if(_spiel->_currentPlayer == stein::Player1)std::cout<<"Player A won the game!"<<std::endl;
        else std::cout<<"Player B won the game!"<<std::endl;
        return false;
    }
    nextZug();
    return true;
}

int Manager::getNumber(){
    int number;  ///cin cant use quint8!!! int<-->quint8 bad!
    while(!(std::cin>> number)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "A number please.  Try again: ";
        }
    return number;
}
