#include "Stack.h"

void testStack() {

	Stack<int> defaultStack;
	Stack<int> paramStack(10);

	int testInt = 2;
	int* testPointer = &testInt;
	int temp;
	
	paramStack.push(testPointer);
			
	cout << *paramStack.topStack();
	cout << "Enter temp" << endl;
	cin >> temp;
}