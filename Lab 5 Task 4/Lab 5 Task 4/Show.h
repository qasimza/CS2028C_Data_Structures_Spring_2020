#ifndef SHOW
#define SHOW
#include <string> 
#include <iostream>


using namespace std;

class Show{

private:
	string title;
	string description;
	string director;
	int year;
	
public:
	//Constructors
	Show();
	Show(string, string, string, int);
	
	//Getters
	string getTitle();
	string getDescription();
	string getDirector();
	int getYear();

	//Setters
	void setTitle(string);
	void setDescription(string);
	void setDirector(string);
	void setYear(int);

	//Other Functions
	virtual void play();
	void details();
};

#endif