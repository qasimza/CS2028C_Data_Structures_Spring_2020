# include <iostream>
# include <cmath>
# include <cstring>
# include <string>
# include <ctime>


using namespace std;

// bool shoot(basketBallPlayer);
// void pass(basketBallPlayer, basketBallPlayer);
// void seePlayerStats(basketBallPlayer);
// void seeScore();

int score = 0;
int totalPossessions = 0;

class basketBallPlayer {
	unsigned int shotsTaken = 0;
	unsigned int shotsMade = 0;
	unsigned int passesAttempted = 0;
	unsigned int passesMade = 0;
	double passingPercent = 0.0;
	double shotPercent = 0.0;
	bool possession = false;
public:
	string name;
	unsigned int teamNum;
	bool getPossession();
	int getShotsTaken();
	int getShotsMade();
	int getPassesAttempted();
	int getPassesMade();
	void setPossession(bool);
	bool passBall();
	int takeShot(unsigned int);
	double findShotPercent();
	double findPassPercent();
};

#pragma region Getters
bool basketBallPlayer::getPossession() {
	return possession;
}

int basketBallPlayer::getShotsTaken() {
	return shotsTaken;
}

int basketBallPlayer::getShotsMade() {
	return shotsMade;
}

int basketBallPlayer::getPassesAttempted() {
	return passesAttempted;
}

int basketBallPlayer::getPassesMade() {
	return passesMade;
}



#pragma endregion 

void basketBallPlayer::setPossession(bool pos) {
	possession = pos;
}

bool basketBallPlayer::passBall() {
	srand(time(NULL));
	int r1 = rand() % 100 + 1;
	if (r1 > findPassPercent()) {
		passesAttempted = passesAttempted + 1;
		return false;
	}
	else {
		passesAttempted = passesAttempted + 1;
		passesMade = passesMade + 1;
		return true;
	}
}

int basketBallPlayer::takeShot(unsigned int points) {
	//Refer page 1 description
	srand(time(NULL));
	int randomNum = 150;
	int newPointVal;

	if (points == 1) {
		randomNum = rand() % 80 + 1;

	}
	else if (points == 2) {
		randomNum = rand() % 100 + 1;

	}
	else if (points == 3) {
		randomNum = rand() % 120 + 1;

	}
	else {
		cout << "Please enter a valid point value: ";
		cin >> newPointVal;
		cout << endl;
		basketBallPlayer::takeShot(newPointVal);
	}

	if (findShotPercent() > randomNum) {

		shotsMade++;
		shotsTaken++;
		return true;

	}
	else {

		shotsTaken++;
		return false;
	}

}

double basketBallPlayer::findShotPercent() {
	if (shotsMade > 1 && shotsMade != shotsTaken) {
		shotPercent = shotsMade / shotsTaken;
	}
	else if (shotsMade == shotsTaken && shotsMade > 0) {
		shotPercent = (shotsMade / shotsTaken) - 25;
	}
	else {
		shotPercent = 60;
	}
	return shotPercent;
}

double basketBallPlayer::findPassPercent() {
	double passPercent = 0;
	if (passesMade > 1) {
		passPercent = passesMade / passesAttempted;
	}
	else if (passesMade == passesAttempted && passesMade > 0) {
		passPercent = (passesMade / passesAttempted) - 25;
	}
	else {
		passPercent = 60;
	}
	return passPercent;
}

bool shoot(basketBallPlayer player) {	// Returns posession of the ball
	//True - Current team retains posssesion
	//False - Ball passed to other team
	int points;
	do {
		cout << "Select number of points (1, 2 or 3): ";
		cin >> points;
	} while (points < 1 || points > 3);

	if (!player.takeShot(points) && rand() % 2 == 1) {
		player.setPossession(false);
		if (player.teamNum == 1) {
			totalPossessions++;
		}
		return false;
	}
	else {
		return true;
	}
}

void pass(basketBallPlayer* player1, basketBallPlayer* player2) {


}

void seePlayerStats(basketBallPlayer player) {
	//Refer page 2 description
	cout << "Name: " << player.name << endl;
	cout << "Shots taken: " << player.getShotsTaken() << endl;
	cout << "Shots made: " << player.getShotsMade() << endl;
	cout << "Passes attempted: " << player.getPassesAttempted() << endl;
	cout << "Passes made: " << player.getPassesMade() << endl;
}

void seeScore() {
	//Refer page 2 description
}

string trimString(string input) {
	
	string output;

	int i = 0;
	for (char c : input) {
		if (!isspace(c)) {
			i++;	
		}
	}

	output = input.substr(i, input.length() - i);

	return output;
}

int turnMenu() {
	string response;
	cout << "Your Turn! " << endl;
	cout << "			Pick One:			" << endl;
	cout << "-------------------------------" << endl;
	cout << "	1. Pass" << endl;
	cout << "	2. Shoot" << endl;
	cout << "	3. See Player's Stats" << endl;
	cout << "	4. See Score " << endl;
	cout << "-------------------------------" << endl;
	cout << "  Type in your response: ";
	cin >> response;
	cout << endl;

	if (trimString(response) == "1" || trimString(response) == "Pass") {
		return 1;
	}
	else if (trimString(response) == "2" || trimString(response) == "Shoot") {
		return 2;
	}
	else if (trimString(response) == "3" || trimString(response) == "See Player's Stats") {
		return 3;
	}
	else if (trimString(response) == "4" || trimString(response) == "See Score") {
		return 4;
	}
	else {
		cout << "Please enter a valid response" << endl;
		return turnMenu();
	}

}

int main() {

	basketBallPlayer Team1[5];
	basketBallPlayer Team2[5];

	int scoreLimit;
	int response;

	cout << "Please enter a score limit: ";
	cin >> scoreLimit;
	cout << endl;

	string teamNameUser;
	cout << "Please enter a team name: ";
	cin >> teamNameUser;
	cout << endl;

	string playerName;
	Team1[0].name = "Kobe Bryant";

		for (int i = 1; i < 5; i++) {

			cout << "Please enter a player's name: " << endl;
			cin >> Team1[i].name;
			cout << endl;
		}

	cout << "All players are accounted for." << endl << endl;
	cout << teamNameUser + " Players:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << Team1[i].name << endl;
	}
	cout << endl;

	srand(time(NULL));
	bool coinFlip = rand() % 2 + 1;
	
	basketBallPlayer* Offense;

	int teamNumber;

	if (coinFlip = 1) {
		Offense = Team1;
		teamNumber = 1;
	}
	else {
		Offense = Team2;
		teamNumber = 2;
	}

	while (totalPossessions <= 20) {	// change to total possession <= 20

		response = turnMenu();
		
		switch (response) {
			case 1: 
				// Call Pass
				break;
			case 2:
				// Call Shoot
				break;
			case 3:
				// Call Player's Stats
				break;
			case 4:
				// Call See Score
				break;
			default:
				break;
		}

		if (Offense->getPossession == false) {
			if (teamNumber == 1) {
				Offense = Team2;
			}
			else if (teamNumber == 2) {
				Offense = Team1;
			}
		}

		

	}








}