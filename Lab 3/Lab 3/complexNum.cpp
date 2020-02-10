#include "complexNum.h"
#include <cmath>
#include <iostream>

using namespace std;

complexNum::complexNum() {
	x = 0;
	y = 0;
	r = 0;
	theta = 0;
}

complexNum::complexNum(double xCoordinate, double yCoordinate) {
	x = xCoordinate;
	y = yCoordinate;
	r = sqrt(pow(x, 2) + pow(y, 2));
	theta = atan(y / x); //in radians
}

complexNum::complexNum(double radius, double angle, bool arbitrary) {
	r = radius;
	theta = angle;
	x = r * sin(angle);
	y = r * cos(angle);
}

double complexNum::getXCoordinate() {
	return x;
}

double complexNum::getYCoordinate() {
	return y;
}

double complexNum::getRadius() {
	return r;
}

double complexNum::getAngle() {
	return theta;
}

void complexNum::setXCoordinate(double xCoordinate) {
	x = xCoordinate;
}

void complexNum::setYCoordinate(double yCoordinate) {
	y = yCoordinate;
}

void complexNum::setRadius(double radius) {
	r = radius;
}

void complexNum::setAngle(double angle) {
	theta = angle;
}

void complexNum::add(complexNum z) {
	x = x + z.getXCoordinate();
	y = y + z.getYCoordinate();
	r = sqrt(pow(x,2) + pow(y,2));
	theta = atan(y / x);
}

void complexNum::subtract(complexNum z) {
	x = x - z.getXCoordinate();
	y = y - z.getYCoordinate();
	r = sqrt(pow(x, 2) + pow(y, 2));
	theta = atan(y / x);
}

void complexNum::multiply(double scalar) {
	x = x * scalar;
	y = y * scalar;
	r = sqrt(pow(x, 2) + pow(y, 2));
	theta = atan(y / x);
}

void complexNum::divide(double scalar) {
	x = x / scalar;
	y = y / scalar;
	r = sqrt(pow(x, 2) + pow(y, 2));
	theta = atan(y / x);
}

bool complexNum::equals(complexNum z) {
	if (x == z.getXCoordinate() && y == z.getYCoordinate()) {
		return true;
	}
	else {
		return false;
	}
}

void complexNum::print() {
	cout << "Cartesian Coordinates: " << endl;
	cout << "X-coordinate: " << x << endl;
	cout << "Y-coordinate: " << y << endl;
	cout << "Polar Coordinates: " << endl;
	cout << "Radius: " << r << endl;
	cout << "Angle(in radians): " << theta << endl;
}