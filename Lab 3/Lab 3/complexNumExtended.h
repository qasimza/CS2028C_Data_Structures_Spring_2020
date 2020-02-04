#pragma once
#include "complexNum.h"

class complexNumExtended : public complexNum{
public:
	void operator+(complexNumExtended &);
	void operator-(complexNumExtended &);
	void operator*(double);
	void operator/(double);
	bool operator==(complexNumExtended &);
};

