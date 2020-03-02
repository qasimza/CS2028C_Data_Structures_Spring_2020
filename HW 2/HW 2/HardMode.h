#pragma once
#include "Wheel.h"

class HardMode:public Wheel{
	int const MIN_RANGE = 6;
	int const MAX_RANGE = 20;
public:
	//Constructor
	HardMode();
	HardMode(int, int);

	//Overriden Function
	int spin(int);
};

