#include <iostream>
#include <string>
#include "Stack.h"

int main()
{
	Stack<int> defaultStack;
	Stack<int> paramStack(10);

	int testInt = 2;
	int* testPointer = &testInt;
	int temp;

	paramStack.push(testPointer);

	cout << *paramStack.topStack() << endl;;
	cin >> temp;
}
