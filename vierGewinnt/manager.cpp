#include "manager.hpp"


/**
 * @file manager.cpp implementation of Manager class functions
 * @author Simon Näther
 **/



Manager::Manager(QWidget *parent)
{

	

}



Manager::~Manager()
{
    delete _spiel;
    if(_server != nullptr)delete _server;
    if(_client != nullptr)delete _client;
}



void Manager::setServerClient (bool serverOrClient ,quint16 port ,QString IP){
    _serverOrClient = serverOrClient;
    if(serverOrClient == false){    ///creates server and opens it
        _server = new MyTcpServer(port);
        emit networkConnects(serverOrClient);
        _server->openServer();
        srand (time(NULL));  /// to make the starting player random
        int v = rand() % 2 ;
        if( v==1)
        {
            _beginnender = true;
        }
        else
        {
            _beginnender = false;
		}
	}
    else{   ///creates a client and tells it to connenct
        _client = new Client(IP , port);
        emit networkConnects(serverOrClient);
        _client->connectToServer();
	}
}




void Manager::clientReceived(qint8 Cmd, qint8 spalten, qint8 zeilen, qint8 rundenzahl, qint8 startinPlayer){ ///Cmd is unused but there for compatability with signal...
    if(startinPlayer == 0x00)_beginnender= true;
    else _beginnender =false;

    _spalten = spalten;
    _zeilen = zeilen;
    _rundenzahl = rundenzahl;

    if(! _serverOrClient)emit networkServer(0x10, 0x01, 0x00);
    else emit networkClient(0x10, 0x01, 0x00);
    spielStart();
}



void Manager::spielStart(){
    if(! _beginnender){
        _spiel = new Spiel(_spalten, _zeilen, stein::Player1);
	}
	else{
        _spiel = new Spiel(_spalten, _zeilen, stein::Player2);
	}
}



void Manager::handleEvent(quint8 code, quint8 value){

    switch(code) {
        case 0x11 :{ ///handles answer to send turn

                switch(value) {
					case 0x00 :
						nextZug();
						break;
						
					case 0x01 :
                        emit gameChat("GAME:  Du hast gewonnen!");
						_spiel->_gewonnenSpieler1 ++;
						nextZug();
                        nextRound(true);
						break;
						
					case 0x02 :
                        emit gameChat("GAME:  Unetschieden!");
                        nextRound(false);
						break;
						
					case 0x10 :
                        emit gameChat("GAME:  Du warst nicht an der Reihe!");
						break;
						
					case 0x11 :
                        emit gameChat("GAME:  Außerhalb des Spielfeldes!");
						break;
						
					case 0x12 :
                        emit gameChat("GAME:  Spalte ist voll!");
						break;
						
					case 0x13 :
                        emit gameChat("GAME:  kein laufendes Spiel!");
						break;
					
					case 0x20 :
                        emit gameChat("GAME:  Unbekannter Fehler aufgetreten!");
						break;
				}
            break;}
			
        case 0x03 :   ///handles incomming opponents turn
            int x = static_cast<int>(value);
            checkZug(x);
			break;
			
	}
}



void Manager::quit(){
	if(_gameRunning){
        delete _spiel;
		_gameRunning = false;
        emit gameChat("GAME:  Laufendes Spiel abgebrochen!");
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



void Manager::insertStein(int x){
    if(_spiel->_currentPlayer == stein::Player1 && _gameRunning){
        if(! checkValid(x))return;
        int y = setStein(x);
        //quint32 out = 0x00030100 + x ; //legacy: old format for data
        if(! _serverOrClient)emit networkServer(0x03, 0x01, x);
        else emit networkClient(0x03, 0x01, x);

		if(checkWin(x, y)){
            emit gameChat("GAME:  Du hast gewonnen!");
            nextRound(true);
		}
	}
	else{
        emit gameChat("GAME:  Du bist nicht am Zug!");
	}
}



int Manager::setStein(int x){
    int count=0;
    while(_spiel->_grid[x][count] == stein::zero && count < _spiel->_y){++count;}

    _spiel->_grid[x][count-1] = _spiel->_currentPlayer;

    emit paint(x, count, _spiel->_currentPlayer);
	return count;
}



void Manager::checkZug(int x){
	if(! checkValid(x)){
        if(_spiel->_grid[x][0] != stein::zero){
            if(! _serverOrClient)emit networkServer(0x11, 0x01, 0x12);
            else emit networkClient(0x11, 0x01, 0x12);
		}
		else{
            if(! _serverOrClient)emit networkServer(0x11, 0x01, 0x11);
            else emit networkClient(0x11, 0x01, 0x11);
		}

	}
	else{
        int y = setStein(x);
		if(checkDraw()){
            emit gameChat("GAME:  Unentschieden!");
            nextRound(false);
            if(! _serverOrClient)emit networkServer(0x11, 0x01 ,0x02);
            else emit networkClient(0x11, 0x01 ,0x02);
		}
		else if(checkWin(x ,y )){
            emit gameChat("GAME:  Du hast verlohren!");
            _spiel->_gewonnenSpieler2 ++;
            if(! _serverOrClient)emit networkServer(0x11, 0x01, 0x01);
            else emit networkClient(0x11, 0x01, 0x01);
		}
		else{
			nextZug();
            if(! _serverOrClient)emit networkServer(0x11, 0x01, 0x00);
            else emit networkClient(0x11, 0x01, 0x00);
		}

	}
}



bool Manager::checkValid(int x){
    if(x < 0 || x > _spiel->_x-1){
        emit gameChat("GAME:  Stein wurde neben das Gitter geworfen!");
        return false;
    }

    if(_spiel->_grid[x][0] != stein::zero){
        emit gameChat("GAME:  Stein wurde in eine bereits volle Spalte geworfen!");
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
   if(change){
       if(_spiel->_currentPlayer == stein::Player1)_spiel->_currentPlayer = stein::Player2;
       if(_spiel->_currentPlayer == stein::Player2)_spiel->_currentPlayer = stein::Player1;
   }
   quint8 beginnender;
   if(_client == nullptr && _spiel->_currentPlayer == stein::Player2)beginnender = 0x01;
   if(_client == nullptr && _spiel->_currentPlayer == stein::Player1)beginnender = 0x00;
   if(_server == nullptr && _spiel->_currentPlayer == stein::Player2)beginnender = 0x00;
   if(_server == nullptr && _spiel->_currentPlayer == stein::Player1)beginnender = 0x01;
   _spiel->_rundennummer++;
   emit signalNextRound(0x02, _spiel->_rundennummer, beginnender);
   resetGrid();
}



void Manager::nextZug(){
    if(_spiel->_currentPlayer == stein::Player1){
        _spiel->_currentPlayer = stein::Player2;
        emit gameChat("GAME:  Dein Gegner ist jetzt am Zug.");
	}
	else{
        _spiel->_currentPlayer = stein::Player1;
        emit gameChat("GAME:  Du bist jetzt am Zug.");
	}
}


void Manager::setSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl){
    _spalten = x;
    _zeilen = y;
    _rundenzahl = rundenzahl;
    quint8 val;
    if(_beginnender) val = 0x00;
    else val = 0x01;
    emit sendParameters(0x01, 0x04, _spalten, _zeilen, _rundenzahl, val);
    emit gameChat("GAME:  Ihre Grid- und Rundenauswahl wurden and den gegner weiter gegeben.");

}

void Manager::setNextRound(qint8 Cmd, qint8 Rundenummer, qint8 BeginnenderRunde){
    if(BeginnenderRunde && _serverOrClient)_spiel->_currentPlayer = stein::Player1;
    else _spiel->_currentPlayer = stein::Player2;
    _spiel->_rundennummer = Rundenummer;
}

void Manager::resetGrid(void){
    for(int i=0; i< _spiel->_x ; i++){
        for(int ii=0 ; ii< _spiel->_x; ii++){
            _spiel->_grid[i][ii] = stein::zero;
        }
    }
}
