#pragma once

#include <iostream>

using namespace std;


template <class Item> 
class Stack {

	int MAX_SIZE;
	int top;
	Item data;


public:

	// Exceptions
	class StackOverflow {};
	class StackUnderflow {};

	// Constructors
	Stack();
	Stack(int);

	//Getters
	int getMaxSize();

	// Setters
	void setMaxSize(int);

	//Other functions
	void push(Item);
	int* pop();
	bool isFull();
	bool isEmpty();
	Item topStack();
	int length();
	void makeEmpty();	// Use delete
	int getCapacity();
};

// Constructors
template <class Item>
Stack<Item>::Stack() {
	MAX_SIZE = 0;
	top = 0;
	data = new Item*[MAX_SIZE];
}

template <class Item>
Stack<Item>::Stack(int size) {
	MAX_SIZE = size;
	top = 0;
	data = new Item*[MAX_SIZE];
}


//	Setters & Getters
template <class Item>
int Stack<Item>::getMaxSize() {
	return MAX_SIZE;
}

template <class Item>
void Stack<Item>::setMaxSize(int sizeInput) {
	MAX_SIZE = sizeInput;
}

// Stack Functions
template <class Item>
void Stack<Item>::push(Item pointer) {
	if (!isFull()) {
		data[top] = *pointer;
		top++;
	}
	else {
		// Throw Overflow Exception
		throw StackOverflow();
	}
}

template <class Item>
int* Stack<Item>::pop() {

	if (!isEmpty()) {
		top--;
		return data[top];
	}
	else {
		// Throw Underflow Exception
		throw StackUnderflow();
	}

}

template <class Item>
bool Stack<Item>::isFull() {
	return top == MAX_SIZE;
}

template <class Item>
bool Stack<Item>::isEmpty() {
	return top == 0;
}

template <class Item>
Item Stack<Item>::topStack() {
	return &data[top];
}

template <class Item>
int Stack<Item>::length() {
	return top;
}

template <class Item>
void Stack<Item>::makeEmpty() {
	for (int i = top; i >= 0; i--) {
		delete data[i];
		top--;
	}
}

template <class Item>
int Stack<Item>::getCapacity() {
	return MAX_SIZE - top;
}



