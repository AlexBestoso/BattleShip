class BattleShips{
	public:
	int battleshipSize = 4;
	int destroyerSize = 3;
	int submarineSize = 3;
	int patroleSize = 2;

}ship;

void makeFeild(char playerFeild[10][10], char aiFeild[10][10]){
	for(int x=0; x<10; x++){//initialize playerFeild
		for(int y=0; y<10; y++){
			playerFeild[x][y] = '-';
		}
	}
	for(int x=0; x<10; x++){//initialize aiFeild
		for(int y=0; y<10; y++){
			aiFeild[x][y] = '-';
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

