#pragma once
/*
This is task 1
*/

class complexNumber {
	double x; //Cartesian x
	double y; //Cartesian y
	double r; //Polar Coordinate
	double theta; //Polar Coordinate
public:
	//Constructors
	complexNumber(); //Default Constructor
	complexNumber(double, double); //Accepts x, y 
	complexNumber(double, double, bool); //Accepts arbitary theta
	//Getters
	double getXCoordinate();
	double getYCoordinate();
	double getRadius();
	double getAngle();
	//Setters
	void setXCoordinate(double);
	void setYCoordinate(double);
	void setRadius(double);
	void setAngle(double);
	//Calculators
	void add(complexNumber);
	void subtract(complexNumber);
	void multiply(double);
	void divide(double);
	//Display
	void print();
};