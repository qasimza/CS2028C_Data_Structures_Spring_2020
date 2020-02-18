#pragma once
#include <iostream>
#include <string>
#include "Wheel.h"
using namespace std;

class Player
{
	string name;
	double balance;
	double bet;
	Wheel *wheel;

public:

	//Constructors
	Player();
	Player(string, double, double, Wheel *);

	//Getters
	string getName();
	double getBalance();
	double getBet();
	Wheel * getWheel();

	//Setters
	void setName(string);
	void setBalance(double);
	void setBet(double);
	void setWheel(Wheel *);

	//Other Functions
	void displayCurrentBalance();
	void updateBalance(int);
	int play();
};

