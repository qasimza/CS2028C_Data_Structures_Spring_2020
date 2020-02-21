
#include <string>
#include <iostream>
#include "Player.h"
#include "Wheel.h"

const string THIN_LINE = "---------------------------------------------------------------";
const string THICK_LINE = "================================================================";

using namespace std;

int getNumRange() {
	//Asks player the number of values (6-20)
	int numValues = -1;
	bool inputCheck = false;
	cout << THICK_LINE << endl;
	cout << "Enter the number of values on the wheel (6 - 20): ";
	cin >> numValues;
	while (cin.fail() || numValues < 6 || numValues > 20) {
		cin.clear();
		cin.ignore(); 
		cout << THIN_LINE << endl;
		cout << "Please enter a valid number of values(6 - 20): ";
		cin >> numValues;
	}
	cout << THICK_LINE << endl;
	return numValues;
}

bool getHardMode() {
	//Asks the user if hardmode should be implemented 
	//Returns true if yes, false if no
	cout << THICK_LINE << endl;
	cout << "Enable Hard Mode(y/n)?: ";
	char c;
	cin >> c;
	while (c != 'y' && c != 'n') {
		cout << THIN_LINE << endl;
		cout << "Error: Incorrect Selection(Press y for yes or n for no): " << endl;
		cin >> c;
	}
	cout << THICK_LINE << endl;
	return c == 'y';
}

double getUserBet(Player player) {
	//Returns the amount user wants to bet
	//Checks for validity of the betting amount
	double betAmount = 0;
	cout << THICK_LINE << endl;
	cout << "Please enter a bet amount (0 to cashout): ";
	cin >> betAmount;

	while (cin.fail() || betAmount > player.getBalance() || betAmount < 0) {
		cout << THIN_LINE << endl;
		cin.clear();
		cin.ignore();
		cout << "Total Allowable Betting Range: " << 0 << " - " << player.getBalance() << endl;
		cout << "Please enter a valid betting amount(0 to cashout): ";
		cin >> betAmount;
		cout << endl;
	}
	cout << THICK_LINE << endl;
	return betAmount;
}

double getUserChange(Player * player) {
	int response;
	cout << "Select change: " << endl;
	cout << THIN_LINE << endl;
	cout << "	1 - Halved" << endl;
	cout << "	2 - No Change" << endl;
	cout << "	3 - Double" << endl;
	cout << THIN_LINE << endl;
	cout << "	Enter response(1-3): ";
	cin >> response;
	while (cin.fail() || response < 1 || response > 3) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid betting amount(0 to cashout): ";
		cin >> response;
		cout << endl;
	}
	double factor;
	switch (response) {
	case 1:
		factor = 0.5;
		break;
	case 2:
		factor = 1;
		break;
	case 3:
		factor = 2;
		break;
	default:
		factor = 0;
	}
	return factor;
}

//Conduct one round 
void gameRound(Player *player, Wheel *house) {

	//declare variables
	double bet, change;
	int userRoll;

	//Bet amount
	bet = getUserBet(*player);
	player->setBet(bet);

	if (bet != 0){
	
		//Spinning wheel
		userRoll = player->play();
		cout << "You rolled: " << userRoll << endl;

		//Change factor
		change = getUserChange(player);

		//Set bet amount
		double x = bet * change;
		player->setBet(x);

		//Spin house wheel
		int houseRoll1 = house->spin();
		int houseRoll2 = house->spin();
	
		cout << THICK_LINE << endl; 
		cout << "Round Summary: " << endl;
		cout << THIN_LINE << endl;

			cout << "Starting Balance: $" << player->getBalance() << endl;
			cout << "Betting Amount: $" << bet << endl;
			cout << "You rolled: " << userRoll << endl;
			cout << "Change: ";
			if (change == 0.5) {
				cout << "Halved wager" << endl;
				cout << "House Rolled: " << houseRoll1 << ", " << houseRoll2 << endl;
				if (userRoll <= houseRoll1 && userRoll <= houseRoll2) {
					cout << "You lost this round!" << endl;
					player->updateBalance(-1);
				}
				else {
					cout << "You won this round!" << endl;
					player->updateBalance(0);
				}			 
			} 
			else if(change == 1) {
				cout << "No change in wager" << endl;
				cout << "House Rolled: " << houseRoll1 << endl;
				if (userRoll <= houseRoll1) {
					cout << "You lost this round!" << endl;
					player->updateBalance(-1);
				}
				else {
					cout << "You won this round!" << endl;
					player->updateBalance(1);
				}
			}
			else {
				cout << "Doubled wager" << endl;
				cout << "House Rolled: " << houseRoll1 << ", " << houseRoll2 << endl;
				if (userRoll <= houseRoll1 || userRoll <= houseRoll2) {
					cout << "You lost this round!" << endl;
					player->updateBalance(-2);
				}
				else {
					cout << "You won this round!" << endl;
					player->updateBalance(2);
				}
			}
			player->displayCurrentBalance(); //Displaying current balance
		}
	else {
		cout << "You bet $0! Cashing out." << endl;
		cout << THICK_LINE << endl;
	}
}

int main() {
	Player userPlayer;
	Wheel house, *playerWheel;
	double bal;
	cout << THICK_LINE << endl;
	cout << "Enter your balance: ";
	cin >> bal;
	while (bal <= 0) {
		cout << THIN_LINE <<endl;
		cout << "Balance must be positive. Enter correct value: ";
		cin >> bal;
	}
	userPlayer.setBalance(bal);
	cout << THICK_LINE << endl;
	int numValues = getNumRange();
	if (!getHardMode()){
		playerWheel = new Wheel(1, numValues);
		userPlayer.setWheel(playerWheel);
		do{
			gameRound(&userPlayer, &house);
		} while (userPlayer.getBet()!=0 && userPlayer.getBalance()!=0);
		cout << THICK_LINE << endl;
		cout << "GAME OVER" << endl;
		userPlayer.displayCurrentBalance();
	}
	else{

	}
	return 0;
}