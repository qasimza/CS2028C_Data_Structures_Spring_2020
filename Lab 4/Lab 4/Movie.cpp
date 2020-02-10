#include "Movie.h"


//Constructors
Movie::Movie() :Show() {
	credits;
}

Movie::Movie(string movieTitle, string movieDescription, string movieDirector, int movieYear, int numMovieCredits):Show(movieTitle, movieDescription, movieDirector, movieYear){
	credits = new string[numMovieCredits];
}

//Getters
string Movie::getCredits() {
	return *credits;
}
//
//void Movie::setCredits(string movieCredits[]) {
//	credits[] = movieCredits[]
//}
//
////Setters
//
//
//
//void Movie::play() {
//
//	for (int i = 0; i < credits.length; i++) {
//		cout << credits[i] << endl;
//	}
//
//}
//
//
