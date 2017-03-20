void placeAiShip(int x, int y, int ship, std::string direction, char aiFeild[10][10]){
	int run = 1;

	x = rand() % 9 + 0;
	y = rand() % 9 + 0;
	direction = randomDirection();

	while(run){
		if(aiFeild[x][y] == piece.ship){
			std::cout<<"\n\tYou can't do that!\n";
			x = rand() % 9 + 0;
			y = rand() % 9 + 0;
			run=1;
		}
		if(direction == "up" || direction == "Up"){
			if((y <= 2 && ship == 4) || (y <= 1 && ship == 3) || (y <= 0 && ship == 2)){
				for(int i=0; i<ship; i++){
					aiFeild[x][y] = piece.ship;
					y++;
				} run=0;
			}else{
				for(int i=0; i<ship; i++){
					aiFeild[x][y] = piece.ship;
					y--;
				} run=0;
			}		
		}else if(direction == "down" || direction == "Down"){
			if((y >= 7 && ship == 4) || (y <= 8 && ship == 3) || (y <= 9 && ship == 2)){
				for(int i=0; i<ship; i++){
					aiFeild[x][y] = piece.ship;
					y++;
				} run=0;
			}else{
				for(int i=0; i<ship; i++){
					aiFeild[x][y] = piece.ship;
					y++;
				} run=0;
			}	
		}else if(direction == "right" || direction == "Right"){
			if((x >= 7 && ship == 4) || (x >= 8 && ship == 3) || (x >= 9 && ship == 2)){
				for(int i=0; i<ship; i++){
					aiFeild[x][y] = piece.ship;
					x--;	
				} run=0;			
			}else{
				for(int i=0; i<ship; i++){
					aiFeild[x][y] = piece.ship;
					x++;	
				} run=0;
			}	
		}else if(direction == "left" || direction == "Left"){
			if((x <= 2 && ship == 4) || (x <= 1 && ship == 3) || (x <= 0 && ship == 2)){
				for(int i=0; i<ship; i++){
					aiFeild[x][y] = piece.ship;
					x++;
				} run=0;
			}else{
				for(int i=0; i<ship; i++){
					aiFeild[x][y] = piece.ship;
					x--;
				} run=0;
			}	
		}else{
			std::cout<<"[AI Error : Invalid x and y points]";
		}
	}
}