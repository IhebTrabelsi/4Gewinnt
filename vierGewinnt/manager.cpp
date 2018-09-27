#include "manager.hpp"





Manager::~Manager()
{
    quit();
    //delete ui;
    //delete _gameChat;
    //delete _player1Chat;
    //delete _player2Chat;
}



void Manager::setServerClient (bool serverOrClient ,quint16 port ,QString IP){
    _serverOrClient = serverOrClient;   // hier finder übergabe von der grafik zur logik
    if(serverOrClient == false){
        //creates server and opens it
        _server = new MyTcpServer(port);
        emit networkConnects(serverOrClient);
        _server->openServer();
        // make a random function who begins and it's given to the other player after
        srand (time(NULL));
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
	else{
        _client = new Client(IP , port);
        emit networkConnects(serverOrClient);
        _client->connectToServer();
	}
}

void Manager::setSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl){
    _spalten = x;
    _zeilen = y;
    _rundenzahl = rundenzahl;
    quint8 val;
    if(_beginnender) val = static_cast<quint8>(0x00);
    else val = static_cast<quint8>(0x01);
    emit sendParameters(0x01, 0x04, _spalten, _zeilen, _rundenzahl, val);
    emit createGrid(_spalten, _zeilen);
    emit gameChat("GAME:  Ihre Grid- und Rundenauswahl würden and den gegner weiter gegeben");

}

void Manager::clientReceived(quint8 xGridSize, quint8 yGridSize, quint8 Rundenzahl, quint8 Beginnender)
{
    if(Beginnender == static_cast<quint8>(0x01))
        _beginnender= true;
    else
        _beginnender =false;

    _spalten = xGridSize;
    _zeilen = yGridSize;
    _rundenzahl = Rundenzahl;
    emit createGrid(_spalten, _zeilen);
    _gridIsOn = true; // braucht man nur beim server
    emit sendParameters(0x10, 0x01, 0x00, 0x00, 0x00, 0x00);

    spielStart();
}



void Manager::spielStart(){
    // emit addStone(1);
    _gameRunning = true;
    if(! _beginnender){
        emit gameChat("Game started du beginnst!!!!!");
        //emit addStone(0);
        _spiel = new Spiel(_spalten, _zeilen, stein::Player1);
	}
	else{
        emit gameChat("Game started");
        // emit addStone(0);
        _spiel = new Spiel(_spalten, _zeilen, stein::Player2);
	}
}



void Manager::handleEvent(quint8 code, quint8 value){

    switch(code) {

        case static_cast<quint8>(0x11) :
            switch(value)
            {
                case static_cast<quint8>(0x00) :
                    nextZug();
                    break;
						
                case static_cast<quint8>(0x01) :
                    //_spiel->_gewonnenSpieler1 ++;
                    nextZug();
                   // nextRound(true);
                    break;
						
                case static_cast<quint8>(0x02) :
                    emit gameChat("GAME:  Unetschieden!"); //<<std::endl;
                    //nextRound(false);
                    break;
						
                case static_cast<quint8>(0x10) :
                   emit gameChat("GAME:  Du warst nicht an der Reihe!"); //<<std::endl;
                   break;
						
                case static_cast<quint8>(0x11) :
                    emit gameChat("GAME:  Außerhalb des Spielfeldes!"); //<<std::endl;
                    break;
						
                case static_cast<quint8>(0x12) :
                    emit gameChat("GAME:  Spalte ist voll!"); //<<std::endl;
                    break;
						
                case static_cast<quint8>(0x13) :
                    emit gameChat("GAME:  kein laufendes Spiel!"); //<<std::endl;
                    break;
					
                case static_cast<quint8>(0x20) :
                    emit gameChat("GAME:  Unbekannter Fehler aufgetreten!"); //<<std::endl;
                    break;
            }
        break;
			
        case static_cast<quint8>(0x03) :
            checkZug(value);
        break;
        case static_cast<quint8>(0x10) :
            switch(value)
            {
                case static_cast<quint8>(0x00):
                    qDebug() << "OK";
                    if(!_gameRunning)
                    {
                    spielStart();
                    emit gameChat("OK Start Game");
                    }
                    //OK
                break;

                case static_cast<quint8>(0x01):
                    //Abgelehnt oder nicht bereit
                break;

                case static_cast<quint8>(0x02):
                    //nicht unterstützt
                break;

                case static_cast<quint8>(0x03):
                    //nachricht unvollständig
                break;

                case static_cast<quint8>(0x04):
                    //Timeout beim Wartenauf bestätigung
                break;

                case static_cast<quint8>(0x20):
                    //Sonstiger Fehler
                break;

            }

			
//		case 0xXXX :
//			emit gameChat("GAME:  Gegener ist beigetreten."); //<<std::endl;
//			break;
	}
}



void Manager::quit(){
	if(_gameRunning){
        delete _spiel;
		_gameRunning = false;
        emit gameChat("GAME:  Laufendes Spiel abgebrochen!"); //<<std::endl;
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
    if(_spiel->_currentPlayer == stein::Player1 && _gameRunning)
    {
        if(! checkValid(x))return;
        int y = setStein(x);
        emit sendParameters(0x03, 0x01, x, 0x00, 0x00, 0x00);
        if(checkWin(x, y))
        {
            emit gameChat("GAME:  Du hast gewonnen!");
            emit gewonnen("Du hast gewonnen");
            //nextRound(true);
        }
    }
    else{
        emit gameChat("GAME:  Du bist nicht am Zug!");
    }
    gameChat("GAME: You've played now wait for the other Player to Play his role");
    //check win goes here
}



int Manager::setStein(int x){

    int count=0;
    while(_spiel->_grid[x][count] == stein::zero && count < _spiel->_y){++count;}

    _spiel->_grid[x][count-1] = _spiel->_currentPlayer;
    emit addStone(x);
    //emit paint(x, count, _spiel->_currentPlayer);
    return count-1;
}



void Manager::checkZug(int x){
    if(! checkValid(x)){
        if(_spiel->_grid[x][0] != stein::zero){
        emit sendParameters(0x11, 0x01, 0x12, 0x00, 0x00, 0x00);
        }
        else{
        emit sendParameters(0x11, 0x01, 0x11, 0x00, 0x00, 0x00);
        }

    }
    else{
        int y = setStein(x);
        if(checkDraw()){
            emit gameChat("GAME:  Unentschieden!");
            emit gewonnen("Unentschieden");
            nextRound(false);
            emit sendParameters(0x11, 0x01 ,0x02, 0x00, 0x00, 0x00);
        }
        else if(checkWin(x ,y )){
            emit gameChat("GAME:  Du hast verlohren!");
            emit gewonnen("Du hast verloren");
            _spiel->_gewonnenSpieler2 ++;
            emit sendParameters(0x11, 0x01, 0x01, 0x00, 0x00, 0x00);
        }
        else{
            nextZug();
            emit sendParameters(0x11, 0x01, 0x00, 0x00, 0x00, 0x00);

        }

    }
}



bool Manager::checkValid(quint8 x){
    if(x > _spiel->_x){
        emit gameChat("GAME:  Stein wurde neben das Gitter geworfen!"); //<<std::endl;
		return false;
	}
	
    if(_spiel->_grid[x][0] != stein::zero){
        emit gameChat("GAME:  Stein wurde in eine bereits volle Spalte geworfen!"); //<<std::endl;
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
   //quint8 beginnender;
   //if(_client == nullptr && _spiel->_currentPlayer == stein::Player2)beginnender = 0x01;
   //if(_client == nullptr && _spiel->_currentPlayer == stein::Player1)beginnender = 0x00;
   //if(_server == nullptr && _spiel->_currentPlayer == stein::Player2)beginnender = 0x00;
   //if(_server == nullptr && _spiel->_currentPlayer == stein::Player1)beginnender = 0x01;

   //XXX emit
}



void Manager::nextZug(){
    if(_spiel->_currentPlayer == stein::Player1){
        _spiel->_currentPlayer = stein::Player2;
        emit gameChat("GAME:  Dein Gegner ist jetzt am Zug."); //<<std::endl;
	}
	else{
        _spiel->_currentPlayer = stein::Player1;
        emit gameChat("GAME:  Du bist jetzt am Zug."); //<<std::endl;
	}
}



/*void Manager::setNextRound(quint8 Cmd, quint8 Rundenummer, quint8 BeginnenderRunde){
    if(BeginnenderRunde && _serverOrClient)_spiel->_currentPlayer = stein::Player1;
    else _spiel->_currentPlayer = stein::Player2;
    _spiel->_rundennummer = Rundenummer;
}*/
