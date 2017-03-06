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
	
	//Print player's battle field:	
	printPlayerFeild(playerFeild);
	
	//Gather information: 
	std::cout<<"\nPlace Battleship~\nLetter: ";	
	std::cin>> xChar;
	std::cout<<"Number: ";
	std::cin>> x;
	std::cout<<"What direction?\n left, right, up, down: ";
	std::cin>> direction;
	y = charToInt(xChar);

	if(direction == "up" || direction == "Up"){
		for(int i=0; i<battleship; i++){
			playerFeild[x][y] = 'O';
			y--;
		}
	}else if(direction == "down" || direction == "Down"){
		for(int i=0; i<battleship; i++){
			playerFeild[x][y] = 'O';
			y++;
		}
	}else if(direction == "right" || direction == "Right"){
		for(int i=0; i<battleship; i++){
			playerFeild[x][y] = 'O';
			x++;	
		}
	}else if(direction == "left" || direction == "Left"){
		for(int i=0; i<battleship; i++){
			playerFeild[x][y] = 'O';
			x--;
		}
	}else{
		std::cout<<"[Error : Invalid x and y points]";
	}
	printPlayerFeild(playerFeild);
	return 0;
}
