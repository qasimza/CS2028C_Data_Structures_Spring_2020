#pragma once
#include <string>
#include "Wheel.h"
using namespace std;

class Player
{
	string name;
	double account;
	Wheel wheel;

public:

	//Constructors
	Player();
	Player(string, double, Wheel);

	//Setters

	//Getters

	//Other Functions
	void displayCurrentBalance();
	void play();
};

