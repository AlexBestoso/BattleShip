class BattleShips{
	public:
	int battleshipSize = 4;
	int destroyerSize = 3;
	int submarineSize = 3;
	int patroleSize = 2;

}ship;

class GamePieces{
	public:
	char hit = '!';
	char miss = '#';
	char ship = 'O';
	char water = '~';
}piece;

class PlayGame{
	public:
	int playerScore = 0;
	int aiScore = 0;
	int turn = 1;
	int shotInt;
	int shotConv;
	int play = 1;

	char shotChar;
}game;
//*************************************************************
int charToInt(char xChar){
	int x;

	if(xChar == 'A' ||  xChar == 'a'){
		x = 0;
	}else if(xChar == 'B' || xChar == 'b'){
		x = 1;
	}else if(xChar == 'C' || xChar == 'c'){
		x = 2;
	}else if(xChar == 'D' || xChar == 'd'){
		x = 3;
	}else if(xChar == 'E' || xChar == 'e'){
		x = 4;
	}else if(xChar == 'F' || xChar =='f'){
		x = 5;
	}else if(xChar == 'G' || xChar  =='g'){
		x = 6;
	}else if(xChar == 'H' || xChar =='h'){
		x = 7;
	}else if(xChar == 'I' || xChar =='i'){
		x = 8;
	}else if(xChar == 'J' || xChar =='j'){
		x = 9;
	}else{
		std::cout<<"\n\n[Error : Invalid Letter]\n";
		return 1;
	}	
	
	return x;
}	
//*************************************************************
std::string randomDirection(){

	std::string direction;
	int randomNumber;

	randomNumber = rand() % 4 + 1;

	if(randomNumber == 1){
		direction = "up";
	}else if(randomNumber == 2){
		direction = "down";
	}else if(randomNumber == 3){
		direction = "left";
	}else if(randomNumber == 4){
		direction = "right";
	}else{
		std::cout<<"Error###";	
	}

	return direction;
}
//*************************************************************
void makeFeild(char playerFeild[10][10], char aiFeild[10][10], char emptyField[10][10]){
	for(int x=0; x<10; x++){//initialize playerFeild
		for(int y=0; y<10; y++){
			playerFeild[x][y] = piece.water;
		}
	}

	for(int x=0; x<10; x++){//initialize aiFeild
		for(int y=0; y<10; y++){
			aiFeild[x][y] = piece.water;
		}
	}

	for(int x=0; x<10; x++){//initialize emptyField
		for(int y=0; y<10; y++){
			emptyField[x][y] = piece.water;
		}
	}
}	


void printPlayerFeild(char playerFeild[10][10]){
	char Letters = 'A';

	std::cout<<" ";
	for(int i=0; i<10; i++){
		std::cout<<i;
	}
	std::cout<<std::endl<<Letters;	
	for(int y=0; y<10; y++){
		for(int x=0; x<10; x++){
			if(x >= 10){
				x=0;
			}else if(x>=10 && y>=10){
				break;
			}
			std::cout<<playerFeild[x][y];	
		}
		if(y != 9){
			Letters += 1;
			std::cout<<std::endl<<Letters;
		}
	}
	std::cout<<std::endl;
}

void placeShip(int x, int y, std::string direction, int ship, char playerFeild[10][10]){
	int run = 1;
	while(run){
		if(playerFeild[x][y] == piece.ship){
			std::cout<<"\n\tYou can't do that!\n";
			x = rand() % 9 + 0;
			y = rand() % 9 + 0;
			run=1;
		}
		if(direction == "up" || direction == "Up"){
			if((y <= 2 && ship == 4) || (y <= 1 && ship == 3) || (y <= 0 && ship == 2)){
				for(int i=0; i<ship; i++){
					playerFeild[x][y] = piece.ship;
					y++;
				} run = 0;
			}else{	
				for(int i=0; i<ship; i++){
					playerFeild[x][y] = piece.ship;
					y--;
				} run = 0;
			}	
		}else if(direction == "down" || direction == "Down"){
			if((y >= 7 && ship == 4) || (y >= 8 && ship == 3) || (y >= 9 && ship == 2)){
				for(int i=0; i<ship; i++){
					playerFeild[x][y] = piece.ship;
					y--;
				} run=0;
			}else{
				for(int i=0; i<ship; i++){
					playerFeild[x][y] = piece.ship;
					y++;
				} run=0;
			}	
		}else if(direction == "right" || direction == "Right"){
			if((x >= 7 && ship == 4) || (x >= 8 && ship == 3) || (x >= 9 && ship == 2)){
				for(int i=0; i<ship; i++){
					playerFeild[x][y] = piece.ship;
					x--;	
				} run=0;
			}else{	
				for(int i=0; i<ship; i++){
					playerFeild[x][y] = piece.ship;
					x++;	
				} run=0;
			}	
		}else if(direction == "left" || direction == "Left"){
			if((x <= 2 && ship == 4) || (x <= 1 && ship == 3) || (x <= 0 && ship == 2)){
				for(int i=0; i<ship; i++){
					playerFeild[x][y] = piece.ship;
					x++;
				} run=0;
			}else{
				for(int i=0; i<ship; i++){
					playerFeild[x][y] = piece.ship;
					x--;
				} run=0;
			}	
		}else{
			std::cout<<"[Error : Invalid x and y points]";
			run=0;
		}
	}
}