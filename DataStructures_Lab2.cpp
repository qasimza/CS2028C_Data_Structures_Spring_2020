# include <iostream>
# include <cmath>
# include <cstring>
# include <string>
# include <time>

using namespace std;

bool shoot(basketBallPlayer);
void pass(basketBallPlayer, basketBallPlayer);
void seePlayerStats(basketBallPlayer);
void seeScore(unsigned int remainingPossessions, unsigned int score1, unsigned int score2);

int score = 0;
int totalPossessions = 0;

class basketBallPlayer {
	unsigned int teamNum;
	unsigned int shotsTaken = 0;
	unsigned int shotsMade = 0;
	unsigned int passesAttempted = 0;
	unsigned int passesMade = 0;
	double passingPercent = 0.0;
	double shotPercent = 0.0;
	bool possession = false;
public:
	string name;
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

bool basketBallPlayer::getPossession() {
	return possession;
}

bool basketBallPlayer::getShotsTaken() {
	return shotsTaken;
}

bool basketBallPlayer::getShotsMade() {
	return shotsTaken;
}

bool basketBallPlayer::getPassesAttempted() {
	return passesAttempted;
}

bool basketBallPlayer::getPassesMade() {
	return passesMade;
}

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

int basketBallPlayer::TakeShot(unsigned int points) {
	srand(time(NULL));
	int randomNum;
	int newPointVal;
	if (points == 1) {
		randomNum = rand() % 80 + 1;
	}
	else if (points == 2) {
		randomNum = rand() % 100 + 1;
	}
	else if (points == 3) {
		randNum = rand() % 120 + 1;
	}
	else {
		cout << "Please enter a valid point value: ";
		cin >> newPointVal;
		cout << endl;
		basketBallPlayer::TakeShot(newPointVal);
	}

	if (findShotPercent() > randNum) {
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
		shotPercent = abs((shotsMade / shotsTaken) - 25);
	}
	else {
		shotPercent = 60;
	}
	return shotPercent;
}

double basketBallPlayer::findPassPercent() {
	if (passesMade > 1) {
		passPercent = passesMade / passesAttempted;
	}
	else if (passesMade == passesAttempted && passesMade > 0) {
		passPercent = abs((passesMade / passesAttempted) - 25);
	}
	else {
		passPercent = 60;
	}
	return passPercent;
}

bool shoot(basketBallPlayer* player) {	
	// Returns posession of the ball
	//True - Current team retains posssesion
	//False - Ball passed to other team
	do {
		int points;
		cout << "Select number of points (1, 2 or 3): ";
		cin >> points;
	} while (points < 1 || points > 3);

	if (!player.TakeShot() && rand() % 2 == 1) {
		player->setPossession(false);
		if (player.teamNum = 1) {
			totalPossessions++;
		}
		return false;
	}
	else {
		return true;
	}
}

void pass(basketBallPlayer* player1, basketBallPlayer* player2) {
	// player1 passes ball
	// player2 receives ball
	if player1.passBall() {
		player2->setPossession(true);
	}
	player1->setPossession(false)
}

void seePlayerStats(basketBallPlayer player) {
	cout << "Name: " << player.name << endl;
	cout << "Shots taken: " << player.getShotsTaken() << endl;
	cout << "Shots made: " << player.getShotsMade() << endl;
	cout << "Passes attempted: " << player.getPassesAttempted() << endl;
	cout << "Passes made: " << player.getPassesMade() << endl;
}

void seeScore(unsigned int remainingPossessions, unsigned int score1, unsigned int score2) {
	int remainingPossessions, score;
	cout << "Possesions remaining: " << remainingPossessions << "/20" <<endl;
	cout << "Current score: " << score1 << ":" << score2 << endl;
}

int main() {

	basketBallPlayer Team1[5];
	basketBallPlayer Team2[5];

	int score1 = 0, score2 = 0;
	int possessionsRemainig = 20;

	string teamNameUser;
	cout << "Please enter a team name: ";
	cin >> teamNameUser;
	cout << endl;

	string playerName;
	Team1[0].name = "Kobe Bryant"

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



	while (totalPossessions <= 20) {	// change to total possession <= 20

	  // game play


	}








}