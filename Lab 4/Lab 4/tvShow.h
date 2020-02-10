#pragma once
#include "Show.h"

class TVShow : public Show{
	string episodeList;

public:
	TVShow();
	TVShow(string, string, string, int);
	TVShow(int, int);
};