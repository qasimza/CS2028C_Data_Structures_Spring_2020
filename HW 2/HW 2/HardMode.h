#pragma once
#include "Wheel.h"

class HardMode:public Wheel{
public:
	//Constructor
	HardMode();
	//Overriden Function
	int spin(int);
};

