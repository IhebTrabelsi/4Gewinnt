#include "manager.hpp"


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




void Manager::clientReceived(qint8 Cmd, qint8 spalten, qint8 zeilen, qint8 rundenzahl, qint8 startinPlayer){
    if(startinPlayer = 0x00)_beginnender= true;
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
        case 0x11 :{

                switch(value) {
					case 0x00 :
						nextZug();
						break;
						
					case 0x01 :
                        emit gameChat("GAME:  Du hast gewonnen!"); //<<std::endl;
						_spiel->_gewonnenSpieler1 ++;
						nextZug();
                        nextRound(true);
						break;
						
					case 0x02 :
                        emit gameChat("GAME:  Unetschieden!"); //<<std::endl;
                        nextRound(false);
						break;
						
					case 0x10 :
                        emit gameChat("GAME:  Du warst nicht an der Reihe!"); //<<std::endl;
						break;
						
					case 0x11 :
                        emit gameChat("GAME:  Außerhalb des Spielfeldes!"); //<<std::endl;
						break;
						
					case 0x12 :
                        emit gameChat("GAME:  Spalte ist voll!"); //<<std::endl;
						break;
						
					case 0x13 :
                        emit gameChat("GAME:  kein laufendes Spiel!"); //<<std::endl;
						break;
					
					case 0x20 :
                        emit gameChat("GAME:  Unbekannter Fehler aufgetreten!"); //<<std::endl;
						break;
				}
            break;}
			
		case 0x03 :		
            checkZug(value);
			break;
			
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
    if(_spiel->_currentPlayer == stein::Player1 && _gameRunning){
        if(! checkValid(x))return;
        quint8 y =0; // just to compile
        //quint8 y = setzeStein(x);
        //quint32 out = 0x00030100 + x ;
        if(! _serverOrClient)emit networkServer(0x03, 0x01, x);
        else emit networkClient(0x03, 0x01, x);
		if(checkWin(x, y)){
            emit gameChat("GAME:  Du hast gewonnen!"); //<<std::endl;
            nextRound(true);
		}
	}
	else{
        emit gameChat("GAME:  Du bist nicht am Zug!"); //<<std::endl;
	}
}



quint8 Manager::setStein(quint8 x){
	quint8 count=0;
    while(_spiel->_grid[x][count] == stein::zero) count++;
	
	_spiel->_grid[x][count] = _spiel->_currentPlayer;
    //Zemit paint(x, count, _spiel->_currentPlayer);
	return count;
}



void Manager::checkZug(quint8 x){
    quint8 y =0; // just to compile should be removed
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
//		quint8 y = setzeStein(x);
		if(checkDraw()){
            emit gameChat("GAME:  Unentschieden!"); //<<std::endl;
            nextRound(false);
            if(! _serverOrClient)emit networkServer(0x11, 0x01 ,0x02);
            else emit networkClient(0x11, 0x01 ,0x02);
		}
		else if(checkWin(x ,y )){
            emit gameChat("GAME:  Du hast verlohren!"); //<<std::endl;
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



bool Manager::checkValid(quint8 x){
	if(x < 0 || x > _spiel->_x){
        emit gameChat("GAME:  Stein wurde neben das Gitter geworfen!"); //<<std::endl;
		return false;
	}
	
    if(_spiel->_grid[x][0] != stein::zero){
        emit gameChat("GAME:  Stein wurde in eine bereits volle Spalte geworfen!"); //<<std::endl;
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


void Manager::setSizeAndSend(quint8 x, quint8 y, quint8 rundenzahl){
    _spalten = x;
    _zeilen = y;
    _rundenzahl = rundenzahl;
    quint8 val;
    if(_beginnender) val = 0x00;
    else val = 0x01;
    emit sendParameters(0x01, 0x04, _spalten, _zeilen, _rundenzahl, val);
    emit gameChat("GAME:  Ihre Grid- und Rundenauswahl würden and den gegner weiter gegeben");

}

void Manager::setNextRound(qint8 Cmd, qint8 Rundenummer, qint8 BeginnenderRunde){
    if(BeginnenderRunde && _serverOrClient)_spiel->_currentPlayer = stein::Player1;
    else _spiel->_currentPlayer = stein::Player2;
    _spiel->_rundennummer = Rundenummer;
}
