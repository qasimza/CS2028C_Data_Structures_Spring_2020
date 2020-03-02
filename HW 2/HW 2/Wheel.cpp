#include "Wheel.h"
#include <cstdlib>
#include <ctime>

using namespace std;


//Default Constructor
Wheel::Wheel()
{
	srand(time(NULL));
	lowerBound = 1;
	upperBound = 10;
}

//Parameterized Constructor
Wheel::Wheel(int lBound, int uBound) {
	srand(time(NULL));
	lowerBound = lBound;
	upperBound = uBound;
}


// Getters
int Wheel::getLowerBound() {
	return lowerBound;
}
int Wheel::getUpperBound() {
	return upperBound;
}


// Setters
void Wheel::setLowerBound(int lower_Bound) {
	lowerBound = lower_Bound;
}
void Wheel::setUpperBound(int upper_Bound) {
	upperBound = upper_Bound;
}


//Other Functions
int Wheel::spin()
{
	int ballVal = 0;
	int range = upperBound - lowerBound;
	ballVal = rand() % (range + 1) + lowerBound;
	return ballVal;
}