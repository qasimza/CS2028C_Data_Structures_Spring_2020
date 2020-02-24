#include <iostream>
#include "Queue.h"

using namespace std;

void testQueue() {
	//Default Constructor
	Queue<int> q1(1);
	int * x;
	int y = 12;
	x = &y;
	cout << "Length=" << q1.length() << endl;
	cout << "IsFull()" << q1.isFull() << endl;
	cout << "IsEmpty()" << q1.isEmpty() << endl;
	cout << "Testing peek() on empty"
	
	q1.enqueue(x);
	q1.peek();
	cout << *q1.dequeue();
}

int main() {
	testQueue();
	return 0;
}