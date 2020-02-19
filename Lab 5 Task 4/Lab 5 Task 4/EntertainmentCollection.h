#ifndef ECOLL
#define ECOLL
#include <iostream>

using namespace std;

//Template
template <class Item>

class EntertainmentCollection {

	const static int MAX_ITEMS = 10;
	int numItems;
	Item itemsArray[MAX_ITEMS];

public:

	//Exceptions
	class EntertainmentCollectionOverflow {
		int itemCount;
	public:
		EntertainmentCollectionOverflow(int);
		void error();
	};
	class EntertainmentCollectionUnderflow {
	public:
		void error();
	};


	//Constructor
	EntertainmentCollection();
	EntertainmentCollection(int, Item *);

	//Getters
	int getMaxItems();
	int getNumItems();
	Item * getItemsList();

	//Setters
	void setNumItems(int);
	void setItems(Item *, int);

	//Other functions
	void addItem(Item); //Adds an Item
	Item removeItem(); //Returns Last Item


};

#endif ECOLL