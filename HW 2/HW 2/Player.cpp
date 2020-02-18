#include "Player.h"

//Constructors

Player::Player()
{
	name = "Undefined";
	balance = 0.0;
	bet = 0.0;
	wheel = NULL;
}

Player::Player(string pName, double pBalance, double pBet, Wheel *ptr) {
	name = pName;
	balance = pBalance;
	bet = pBet;
	wheel = ptr;
}

//Getters
string Player::getName(){
	return name;
}	
double Player::getBalance(){
	return balance;
}
double Player::getBet(){
	return bet;
}

Wheel * Player::getWheel() {
	return wheel;
}

//Setters
void Player::setName(string playerName){
	name = playerName;
}
void Player::setBalance(double playerBalance){
	balance = playerBalance;
}
void Player::setBet(double playerBet){
	bet = playerBet;
}

void Player::setWheel(Wheel *ptr) {
	wheel = ptr;
}

//Other functions
void Player::displayCurrentBalance() {
	cout << "Current Balance: $" << balance << endl;
}

void Player::updateBalance(int change) {
	balance = balance - change * bet;
}

int Player::play() {
	return wheel->spin();
}