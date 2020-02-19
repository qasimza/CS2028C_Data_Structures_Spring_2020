#include "EntertainmentCollection.h"

//Exceptions
template <class Item>
EntertainmentCollection<Item>::EntertainmentCollectionOverflow::EntertainmentCollectionOverflow(int cItems) {
	itemCount = cItems;
}

template <class Item>
void EntertainmentCollection<Item>::EntertainmentCollectionOverflow::error() {
	cout << "Overflow Error: Collection is full. Cannot add another Item!" << endl;
	cout << "Maximum Shows Allowed: " << MAX_ITEMS << endl;
	cout << "Current Number Items: " << itemCount << endl;
}

template <class Item>
void EntertainmentCollection<Item>::EntertainmentCollectionUnderflow::error() {
	cout << "Underflow Error: Shelf is empty. Cannot remove an item!" << endl;
}


//Default Constructor
template <class Item>
EntertainmentCollection<Item>::EntertainmentCollection() {
	numItems = 0;
}

//Parameterized Constructor
template <class Item>
EntertainmentCollection<Item>::EntertainmentCollection(int uNumItems, Item *uPtr) {
	numItems = uNumItems;
	for (int i = 0; i < uNumItems; i++) {
		itemsArray[i] = uPtr[i];
	}
}


//Getters
template <class Item>
int EntertainmentCollection<Item>::getMaxItems() {
	return MAX_ITEMS;
}

template <class Item>
int EntertainmentCollection<Item>::getNumItems() {
	return numItems;
}

template <class Item>
Item * EntertainmentCollection<Item>::getItemsList() {
	Item *ptr = &itemsArray[0];
	return ptr;
}

//Setters
template <class Item>
void EntertainmentCollection<Item>::setNumItems(int uNumItems) {
	numItems = uNumItems;
}

template <class Item>
void EntertainmentCollection<Item>::setItems(Item *uPtr, int uNumItems) {
	numItems = uNumItems;
	for (int i = 0; i < uNumItems; i++) {
		itemsArray[i] = uPtr[i];
	}
}

//Other functions
template <class Item>
void EntertainmentCollection<Item>::addItem(Item uItem) {
	if (numItems < MAX_ITEMS) {
		itemsArray[numItems] = uItem;
		numItems++;
	}
	else {
		throw EntertainmentCollectionOverflow(numItems);
	}
}

template <class Item>
Item EntertainmentCollection<Item>::removeItem() {
	if (numItems > 0) {
		numItems--;
		return itemsArray[numItems];
	}
	else {
		throw EntertainmentCollectionUnderflow();
	}
}