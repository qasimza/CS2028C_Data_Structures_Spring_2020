#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

int getNumValues() {
	//Asks player the number of values (6-20)
	return 0;
}

bool hardMode() {
	//Asks the user if hardmode should be implemented 
	//Returns true if yes, false if no
}

void gameRound(Player *user, Player *house) {
	//Conduct one round and display results
}

int main() {
	Player userPlayer, housePlayer;
	while (true){//Define Exit conition
		gameRound(&userPlayer, &housePlayer);
	}
	return 0;
}