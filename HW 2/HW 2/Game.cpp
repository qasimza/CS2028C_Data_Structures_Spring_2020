#include <string>
#include <iostream>
#include "Player.h"


using namespace std;

//Asks player the number of values (6-20)
int getNumRange() {
	int numValues = -1;
	bool inputCheck = false;
	cout << "Enter the number of values on the wheel (6 - 20): ";
	cin >> numValues;
	cout << endl;
	while (cin.fail() || numValues < 6 || numValues > 20) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid number of values(6 - 20): ";
		cin >> numValues;
		cout << endl;
	}
	return numValues;
}

bool getHardMode() {
	//Asks the user if hardmode should be implemented 
	//Returns true if yes, false if no
}

//Conduct one round 
bool gameround(Player *user, Wheel *house) {

	int userRoll;
	int houseRoll1;
	int houseRoll2;

	user->setBet(makeBet());
	if (user->getBet() == 0) {
		return false;
	}

	userRoll = user.play()
	cout << "You rolled a " + userRoll + "." << endl;

	user->setBet(changeBet(user.bet));

	if 






}


double makeBet() {
	double betAmount = 0;
	cout << "Please enter a bet amount (0 to cashout): ";
	cin >> betAmount;
	cout << endl;

	return betAmount;
}

string stringToLower(string input) {
	string output;
	for (int i = 0; i < input.length(); i++) {
		output += tolower(input[i]);
	}
	return output;
}

string changeBetMenu() {
	string response;
	cout << "How would you like your bet changed: " << endl;
	cout << "__________________________________________" << endl;
	cout << "    1. Double " << endl;
	cout << "    2. Halved " << endl;

	cin >> response;
	try {
		response = stringToLower(response);
	}
	catch{}

	return response;
}

double changeBet(double betAmount) {
	bool betChanged;
	string newBet = "";
	string response;
	cout << "Would you like to change your bet (Yes/No): ";
	cin >> response;

	response = stringToLower(response);

	if (reponse == "yes") {
		newBet = changeBetMenu();
	}

	if (newBet == "1" || newBet = "doubled") {
		betAmount = betAmount * 2;
	}
	else if (newBet = "2" || newBet = "halved"){
		betAmount = betAmount / 2;
	}

	return betAmount;
}

int main() {
	Player userPlayer;
	Wheel house;
	int numValues = getNumRange();
	userPlayer.wheel->setUpperBound(numValues);
	wheel.setUpperBound(numValues);

	bool exitGame = true; 
	if (!hardMode()){
		while (exitGame) {//Define Exit condition
			
			exitGame = gameRound(&userPlayer, &house);
		}
	}
	else{

	}
	return 0;
}