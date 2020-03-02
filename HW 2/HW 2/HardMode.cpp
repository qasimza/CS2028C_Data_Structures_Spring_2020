#include "HardMode.h"
#include <iostream>


HardMode::HardMode():Wheel()
{
}

HardMode::HardMode(int lbound, int ubound) : Wheel(lbound, ubound) {
}

int HardMode::spin(int x) {
	if (x == -1 || x == 2)
		cout << "================================================================" << endl;
	if (x == -1 and getUpperBound() < MAX_RANGE) {
		cout << "House lost in the last round. Increasing wheel range for house." << endl;
		setUpperBound(getUpperBound() + 1);
		cout << "New Range: " << getLowerBound() << "-" << getUpperBound() << endl;
	}
	else if (x == -1) {
		cout << "House lost in the last round. Maximum range reached.\nCannot increase further." << endl;
		cout << "Current Range: " << getLowerBound() << "-" << getUpperBound() << endl;
	}
	else if (x == 2 and getUpperBound() > MIN_RANGE) {
		cout << "House won the last two rounds. Decreasing wheel range for house" << endl;
		setUpperBound(getUpperBound() - 1);
		cout << "New Range: " << getLowerBound() << "-" << getUpperBound() << endl;
	}
	else if (x == 2) {
		cout << "House lost in the last round. Minimum range reached.\nCannot decrease further." << endl;
		cout << "Current Range: " << getLowerBound() << "-" << getUpperBound() << endl;
	}
	if (x == -1 || x == 2)
		cout << "================================================================" << endl;
	int ballVal = 0;
	int range = getUpperBound() - getLowerBound();
	ballVal = rand() % (range + 1) + getLowerBound();
	return ballVal;
}