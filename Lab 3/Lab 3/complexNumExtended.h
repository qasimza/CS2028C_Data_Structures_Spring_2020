#pragma once
#include "complexNum.h"

class complexNumExtended : public complexNum{
public:
	complexNumExtended();
	complexNumExtended(double, double);
	complexNumExtended(double, double, bool);
	void operator+(complexNumExtended &);
    void operator-(complexNumExtended &);
	void operator*(double);
	void operator/(double);
	bool operator==(complexNumExtended &);
};

