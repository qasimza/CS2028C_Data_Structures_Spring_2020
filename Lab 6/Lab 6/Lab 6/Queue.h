#pragma once

template <class Item>

class Queue {
	
	//private members
	int size;
	int len;
	Item *ptrArray;
	
public:
	
	//Constructors
	Queue();
	Queue(int);
	
	//Other Functions
	void enqueue(Item *);
	Item * dequeue();
	Item * peek();
	int length();
	bool isEmpty();
	bool isFull();
	void MakeEmpty();

	//Exceptions
	class QueueOverflow {};
	class QueueUnderflow {};

};

//Constructors
template <class Item>
Queue<Item>::Queue() {
	size = 0;
	len = 0;
	ptrArray = new Item[0];
}

template <class Item>
Queue<Item>::Queue(int uSize) {
	size = uSize;
	len = 0;
	ptrArray = new Item[uSize];
}

//Other Functions

//Add Item
template <class Item>
void Queue<Item>::enqueue(Item * ptr) {
	if (!isFull()) {
		ptrArray[len] = *ptr;
		len++;
	}
	else {
		throw QueueOverflow();
	}
}


//Remove Item
template <class Item>
Item * Queue<Item>::dequeue() {
	if (!isEmpty()) {
		Item top = ptrArray[0];
		Item *front = &top;
		len--;
		for (int i = 0; i < len; i++) {
			ptrArray[i] = ptrArray[i + 1];
		}
		return front;
	}
	else {
		throw QueueUnderflow();
	}
}

template <class Item>
Item * Queue<Item>::peek() {
	if (!isEmpty()) {
		return &ptrArray[0];
	}
	else {
		throw QueueUnderflow();
	}
}

template <class Item>
int Queue<Item>::length() {
	return len;
}

template <class Item>
bool Queue<Item>::isEmpty() {
	return len == 0;
}

template <class Item>
bool Queue<Item>::isFull() {
	return len >= size;
}

template <class Item>
void Queue<Item>::MakeEmpty() {
	ptrArray = new Item[size];
}