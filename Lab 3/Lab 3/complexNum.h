#pragma once
/*
This is task 1
*/

class complexNum {
	double x; //Cartesian x
	double y; //Cartesian y
	double r; //Polar Coordinate
	double theta; //Polar Coordinate
public:
	//Constructors
	complexNum(); //Default Constructor
	complexNum(double, double); //Accepts x, y 
	complexNum(double, double, bool); //Accepts arbitary theta
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
	void add(complexNum);
	void subtract(complexNum);
	void multiply(double);
	void divide(double);
	bool equals(complexNum);
	//Display
	void print();
};