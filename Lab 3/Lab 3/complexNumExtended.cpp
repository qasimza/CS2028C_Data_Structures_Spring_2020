#include "complexNumExtended.h"
#include <iostream>
#include <cmath>

using namespace std;

complexNumExtended::complexNumExtended() :complexNum() {
}

complexNumExtended::complexNumExtended(double xCoordinate, double yCoordinate) : complexNum(xCoordinate, yCoordinate){
}

complexNumExtended::complexNumExtended(double xCoordinate, double yCoordinate, bool arbitrary) : complexNum(xCoordinate, yCoordinate, arbitrary) {
}

void complexNumExtended::operator+(complexNumExtended &right) {
	setXCoordinate(getXCoordinate() + right.getXCoordinate());
	setYCoordinate(getYCoordinate() + right.getYCoordinate());
	setRadius(sqrt(pow(getXCoordinate(), 2)+ pow(getYCoordinate(), 2)));
	setAngle(atan(getYCoordinate()/getYCoordinate()));
}

void complexNumExtended::operator-(complexNumExtended &right) {
	setXCoordinate(getXCoordinate() - right.getXCoordinate());
	setYCoordinate(getYCoordinate() - right.getYCoordinate());
	setRadius(sqrt(pow(getXCoordinate(), 2) + pow(getYCoordinate(), 2)));
	setAngle(atan(getYCoordinate() / getYCoordinate()));
}

void complexNumExtended::operator*(double scalar) {
	setXCoordinate(getXCoordinate() * scalar);
	setYCoordinate(getYCoordinate() * scalar);
	setRadius(sqrt(pow(getXCoordinate(), 2) + pow(getYCoordinate(), 2)));
	setAngle(atan(getYCoordinate() / getYCoordinate()));
}

void complexNumExtended::operator/(double scalar) {
	if (scalar == 0){
		cout << "Error Cannot Divide by 0";
	}
	else {
		setXCoordinate(getXCoordinate() / scalar);
		setYCoordinate(getYCoordinate() / scalar);
		setRadius(sqrt(pow(getXCoordinate(), 2) + pow(getYCoordinate(), 2)));
		setAngle(atan(getYCoordinate() / getYCoordinate()));
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