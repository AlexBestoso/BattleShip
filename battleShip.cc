#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include "functions.h"
#include "ai.h"

int main(){
	std::string direction;

	char playerFeild[10][10];
	char emptyField[10][10];
	char aiFeild[10][10];
	
	char xChar;

	int battleship = ship.battleshipSize;
	int destroyer = ship.destroyerSize;
	int submarine = ship.submarineSize;
	int patrole = ship.patroleSize;

	int x, y, ship;


	srand(time(NULL));


	//Format battle fields:
	makeFeild(playerFeild, aiFeild, emptyField);


	/*Place Ships*/
	//Print player's battle field:	
	system("clear");
	printPlayerFeild(playerFeild);
	
	//Gather information: 
	std::cout<<"\nPlace Battleship~\nLetter: ";	
	std::cin>> xChar;
	std::cout<<"Number: ";
	std::cin>> x;
	std::cout<<"What direction?\n left, right, up, down: ";
	std::cin>> direction;
	y = charToInt(xChar);
	//Place Battleship:
	system("clear");
	placeShip(x, y, direction, battleship, playerFeild);
	printPlayerFeild(playerFeild);
	//AI Battleship:
	placeAiShip(x, y, battleship,direction, aiFeild);

	std::cout<<"\nPlace Destroyer~\nLetter: ";	
	std::cin>> xChar;
	std::cout<<"Number: ";
	std::cin>> x;
	std::cout<<"What direction?\n left, right, up, down: ";
	std::cin>> direction;
	y = charToInt(xChar);
	//Place Destroyer:
	system("clear");
	placeShip(x, y, direction, destroyer, playerFeild);
	printPlayerFeild(playerFeild);
	//AI Destroyer:
	placeAiShip(x, y, destroyer, direction, aiFeild);

	std::cout<<"\nPlace Submarine~\nLetter: ";
	std::cin>> xChar;
	std::cout<<"Number: ";
	std::cin>> x;
	std::cout<<"What direction?\n left, right, up, down: ";
	std::cin>> direction;
	y = charToInt(xChar);
	//Place Submarine
	system("clear");
	placeShip(x, y, direction, submarine, playerFeild);
	printPlayerFeild(playerFeild);
	//AI Submarine:
	placeAiShip(x, y, submarine, direction, aiFeild);

	std::cout<<"\nPlace Patrole~\nLetter: ";	
	std::cin>> xChar;
	std::cout<<"Number: ";
	std::cin>> x;
	std::cout<<"What direction?\n left, right, up, down: ";
	std::cin>> direction;
	y = charToInt(xChar);
	//Place Patrole:
	system("clear");
	placeShip(x, y, direction, patrole, playerFeild);
	printPlayerFeild(playerFeild);
	//AI Patrole:
	placeAiShip(x, y, patrole, direction, aiFeild);

	//Play Game:
	while(game.play){

		switch(game.turn){
		case 1:
			system("clear");
			std::cout<< "#> Battle Ship <#\n\n";
			printPlayerFeild(emptyField);
			printPlayerFeild(playerFeild);
	
			std::cout<< "\n#> Your turn: ";
			std::cout<< "Letter: ";
			std::cin>> game.shotChar;
			std::cout<< "Number: ";
			std::cin>> game.shotInt;

			game.shotConv = charToInt(game.shotChar);
			x = game.shotInt;
			y = game.shotConv;

			if(aiFeild[x][y] == piece.ship){
				emptyField[x][y] = piece.hit;
				game.playerScore++;
				std::cout<<game.playerScore<<std::endl;
			}else if(aiFeild[x][y] == piece.water){
				emptyField[x][y] = piece.miss;
			}else{
				std::cout<< "\n[ERROR PLACEING SHOT]\n";
			}

			system("clear");
			std::cout<<"playerScore: " << game.playerScore << std::endl;
			std::cout<< "#> Battle Ship <#\n\n";	
			printPlayerFeild(emptyField);
			printPlayerFeild(playerFeild);

			if(game.playerScore >= 12 || game.aiScore >= 12){
				game.play = 0;
				std::cout<<"\nThanks For Playing!\n";
				break;
			}else{
				game.turn = 2;
			}
		case 2:
			system("clear");
			std::cout<<"\n\n\t\tTime for the ai!\n";	
			game.aiScore = 12;

			if(game.playerScore >= 12 || game.aiScore >= 12){
				/*where we are working at the moment*/
				game.play = 0;
				std::cout<<"\nThanks For Playing!\n";
				break;
			}else{
				game.turn = 2;
			}
		}
	}	
	return 0;
}
