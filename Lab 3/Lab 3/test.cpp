//Task 4

#include "complexNumExtended.h"
#include "complexNum.h"
#include <iostream>
# include <string>

using namespace std;

int menu() {

	int returnOperator;
	cout << endl;
	cout << "	Operator Menu: " << endl;
	cout << "		1. Add (+) " << endl;
	cout << "		2. Subtract (-) " << endl;
	cout << "		3. Multiple (*) " << endl;
	cout << "		4. Divide (/) " << endl;
	cout << "		5. Equality (==) " << endl;
	cout << "		6. Quit " << endl;
	cout << "----------------------------------------" << endl;
	cout << "	Enter: ";
	cin >> returnOperator;
	cout << endl;
	
	while (returnOperator < 1 || returnOperator > 6) {
		cout << "Please enter a valid selection (1-6): ";
		cin >> returnOperator;
		cout << endl;
	}

	return returnOperator;
}

complexNumExtended inputComplexNum() {
	int selection;
	double n1, n2;
	complexNumExtended z;
	cout << "Enter 1 to use cartesian coorinates(x, y) and 2 to use polar coordinates (r, theta): ";
	cin >> selection;
	cout << endl;
	while (selection != 1 && selection != 2) {
		cout << "ERROR: Incorrect input Valid selections (1-2): ";
		cin >> selection;
		cout << endl;
	}
	switch (selection) {
	case 1:
		cout << "Please enter a value for the x component: ";
		cin >> n1;
		cout << endl << "Please enter a value for the imaginary component, y: ";
		cin >> n2;
		cout << endl;
		z = complexNumExtended(n1, n2);
		break;
	case 2:
		cout << "Please enter a value for the radius: ";
		cin >> n1;
		cout << endl << "Please enter a value for the the angle (in radians): ";
		cin >> n2;
		cout << endl;
		z = complexNumExtended(n1, n2, true);
		break;
	default:
		cout << "FATAL ERROR!" << endl;
	}
	return z;
}

int main() {

	double x1, y1, x2, y2, scalar;
	bool quitFlag = false, q;
	int operatorReturn;
	
	complexNumExtended n1, n2;
	n1 = inputComplexNum();
	n1.print();
	cout << endl;

	do
	{
		operatorReturn = menu();
		switch (operatorReturn)
		{
		
		case 1: //Add
			n2 = inputComplexNum();
			cout << "Number Entered: " << endl; 
			n2.print();
			n1 + n2;
			cout << endl << "Results:" << endl << endl;
			n1.print();
			break;
		
		case 2: //Subtract
			n2 = inputComplexNum();
			cout << "Number Entered: " << endl;
			n2.print();
			cout << endl << "Results:" << endl << endl;
			n1 - n2;
			n1.print();
			break;

		case 3: //Multiply
			cout << "Please enter a value for the scalar you want to multiply the complex number with: ";
			cin >> scalar;
			cout << endl;
			cout << endl << "Results:" << endl << endl;
			n1 * scalar;
			n1.print();
			break;

		case 4: //Divide
		cout << "Please enter a value for the factor you want to divide the complex number by: ";
			cin >> scalar;
			cout << endl;
			cout << endl << "Results:" << endl;
			n1 / scalar;
			n1.print();
			break;

		case 5: // Equality
			n2 = inputComplexNum();
			cout << "Number Entered: " << endl;
			n2.print();
			cout << endl << "Results:" << endl << endl;
			q = n1 == n2;
			if (q) {
				cout << "The numbers are equal" << endl;
			}
			else {
				cout << "The numbers are unequal" << endl;
			}
			break;
		
		case 6: //Quit
			quitFlag = true;
			break;
		default:
			cout << "FATAL ERROR: This should not be happening!";
		}
	} while (!quitFlag);


	return 0;
}