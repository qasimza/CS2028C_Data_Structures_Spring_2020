#include <iostream>
#include "Queue.h"

using namespace std;

void testQueue() {
	//Default Constructor
	Queue<int> q1(1);

	cout << "Length=" << q1.length() << endl;
	cout << "IsFull()" << q1.isFull() << endl;
	cout << "IsEmpty()" << q1.isEmpty() << endl;
	cout << "Testing peek() on empty" << endl;
	try {
		cout << "Peek=" << q1.peek() << endl;
	}
	catch (Queue<int>::QueueUnderflow){
		cout << "Caught Exception " << endl;
	}
	cout << "Testing dequeue() on empty" << endl;
	try {
		cout << "Dequeue=" << *q1.dequeue() << endl;
	}
	catch (Queue<int>::QueueUnderflow) {
		cout << "Caught Exception " << endl;
	}
	int x = 12;
	int *y = &x;
	//q1.enqueue(y);
	cout << "Testing enqueue()" << endl;
	try {
		q1.enqueue(y);
	}
	catch (Queue<int>::QueueOverflow) {
		cout << "Caught Overflow Exception " << endl;
	}
}

int main() {
	testQueue();
	return 0;
}