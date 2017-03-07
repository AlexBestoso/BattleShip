#include <iostream>
#include <string.h>
#include "functions.h"



int main(){
	std::string direction;

	char playerFeild[10][10];
	char aiFeild[10][10];
	
	char xChar;

	int battleship = ship.battleshipSize;
	int destroyer = ship.destroyerSize;
	int submarine = ship.submarineSize;
	int patrole = ship.patroleSize;

	int x, y, ship;

	//Format battle fields:
	makeFeild(playerFeild, aiFeild);


	/*Place players Ships*/
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

	return 0;
}
