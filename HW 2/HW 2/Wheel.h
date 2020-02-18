#pragma once

using namespace std;

class Wheel
{
	int lowerBound;
	int upperBound;
public:
	Wheel(); // Sets lower bound to 1 and upper bound to 10 by default
	Wheel(int, int);

	//Setters
	void setLowerBound(int);
	void setUpperBound(int);

	//Getters
	int getLowerBound();
	int getUpperBound();

	//Other functions
	virtual int spin(); //returns randomly assigned value to ball passed to it
};

