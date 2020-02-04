#include "complexNumExtended.h"
#include <iostream>

using namespace std;

void complexNumExtended::operator+(complexNumExtended &right) {
	setXCoordinate(getXCoordinate() + right.getXCoordinate());
	setXCoordinate(getYCoordinate() + right.getYCoordinate());
}

void complexNumExtended::operator-(complexNumExtended &right) {
	setXCoordinate(getXCoordinate() - right.getXCoordinate());
	setXCoordinate(getYCoordinate() - right.getYCoordinate());
}

void complexNumExtended::operator*(double scalar) {
	setXCoordinate(getXCoordinate() * scalar);
	setXCoordinate(getYCoordinate() * scalar);
}

void complexNumExtended::operator/(double scalar) {
	if (scalar == 0){
		cout << "Error Cannot Divide by 0";
	}
	else {
		setXCoordinate(getXCoordinate() / scalar);
		setXCoordinate(getYCoordinate() / scalar);
	}
}

bool complexNumExtended::operator==(complexNumExtended &right) {
	if (getXCoordinate() == right.getXCoordinate() && getYCoordinate() == right.getYCoordinate()){
		return true;
	}
	else {
		return false;
	}
}