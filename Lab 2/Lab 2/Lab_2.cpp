# include <iostream>
# include <cmath>
# include <cstring>
# include <string>
# include <ctime>
#include <iomanip>


using namespace std;

const int TOTAL_POSSESSIONS = 20;
const string THIN_LINE_SEPERATOR = "----------------------------------------------------------------------------";
const string THICK_LINE_SEPARATOR = "============================================================================";

class BasketBallPlayer {
private:
	string name;
	string teamName;
	int shotsTaken;
	int shotsMade;
	int passesAttempted;
	int passesMade;
	bool possession;
public:
	//Constructor
	BasketBallPlayer();
	//Getters 
	string getName();
	string getTeamName();
	int getShotsTaken();
	int getShotsMade();
	int getPassesAttempted();
	int getPassesMade();
	bool getPossession();
	//Setters
	void setName(string);
	void setTeamName(string);
	void setPossession(bool);
	//Other game functions
	bool passBall();
	int takeShot(int);
};


//Constructor
BasketBallPlayer::BasketBallPlayer() {
	name = "undefined";
	teamName = "undefined";
	shotsTaken = 0;
	shotsMade = 0;
	passesAttempted = 0;
	passesMade = 0;
	possession = false;
}


//Getters
string BasketBallPlayer::getName() {
	return name;
}

string BasketBallPlayer::getTeamName() {
	return teamName;
}

int BasketBallPlayer::getShotsTaken() {
	return shotsTaken;
}

int BasketBallPlayer::getShotsMade() {
	return shotsMade;
}

int BasketBallPlayer::getPassesAttempted() {
	return passesAttempted;
}

int BasketBallPlayer::getPassesMade() {
	return passesMade;
}

bool BasketBallPlayer::getPossession() {
	return possession;
}

//Setters
void BasketBallPlayer::setName(string playerName) {
	name = playerName;
}

void BasketBallPlayer::setTeamName(string userTeamName) {
	teamName = userTeamName;
}

void BasketBallPlayer::setPossession(bool playerPossession) {
	possession = playerPossession;
}

//Other game functions
bool BasketBallPlayer::passBall() {
	passesAttempted += 1;
	double passPercentage;
	if (passesMade == 0) { 
		/*
		Player maintains a 50% passing percentage until a successful pass is made
		to calculate correct passing percentage and avoid zero division error
		*/
		passPercentage = 50;
	}
	else {
		passPercentage = passesMade * 100 / passesAttempted;
	}
	if (passPercentage >= rand() % 100 + 1) { //Pass successful
		passesMade += 1;
		return true;
	}
	else { //Pass unsuccessful - Turnover
		return false;
	}
	
}

int BasketBallPlayer::takeShot(int points) {
	shotsTaken += 1;
	double shootingPercentage;
	if (shotsMade == 0) {
		/*
		Player maintains a 50% shooting percentage until a successful basket is made
		to calculate correct shooting percentage and avoid zero division error
		*/
		shootingPercentage = 50;
	}
	else {
		shootingPercentage = shotsMade * 100 / shotsTaken;
	}

	if (points < 1 || points >> 3) { //Invalid number of points
		return -1;
	}
	else if (points == 1 && shootingPercentage >= rand() % 80 + 1){
		shotsMade += 1;
		return 1;
	}
	else if (points == 2 && shootingPercentage >= rand() % 100 + 1) {
		shotsMade += 1;
		return 2;
	}
	else if (points == 3 && shootingPercentage >= rand() % 120 + 1) {
		shotsMade += 1;
		return 3;
	}
	else { //Failed shot
		return 0;
	}
}


//Global functions
int getPossessor(BasketBallPlayer* team) {
	/*
	Function should only be called for team on offense 
	and should never return -1
	*/
	for (int i = 0; i < 5; i++) {
		if (team[i].getPossession()) {
			return i;
		}
	}
	/*
	If none of the team members have possession of the ball
	*/
	return -1; 
}

int shoot(int &userScore, BasketBallPlayer* userTeam, BasketBallPlayer* computerTeam) {
	/*
		Calls player's TakeShot() function.
		User choses value 1, 2, 3;
		Updates user points and changes possesion of ball if required
	*/
	int points;
	cout << "Enter point value (1, 2 or 3): ";
	cin >> points;
	cout << endl;
	while (points < 1 || points > 3) {
		cout << "ERROR: Invalid Value. Please enter a valid number of points (1, 2 or 3): ";
		cin >> points;
		cout << endl;
	}
	int playerNum = getPossessor(userTeam);
	int pointsScored = userTeam[playerNum].takeShot(points);
	if (pointsScored == -1) {
		cout << "CRITICAL ERROR: Invalid number of points." << endl;
	}
	else if (pointsScored == 0) {
		cout << userTeam[playerNum].getName() << " missed the basket! " << endl;
		/*
		50% chance of possesion. Detrmined using random value 0-1 
		0 = Possesion lost
		1 = Possession retained
		*/
		if (rand() % 2 == 1) {
			cout << userTeam[playerNum].getName() << " secured the rebound." << endl;
		}
		else {
			/*
			Random player from computer's team steal's the ball
			*/
			int randPlayerNum = rand() % 5;
			userTeam[playerNum].setPossession(false);
			computerTeam[playerNum].setPossession(true);
			cout << " Computer player " << randPlayerNum << "stole the ball from " << userTeam[playerNum].getName() << "!" << endl;
		}
	}
	else {
		/*
		Ball passed to other team after successful basket
		*/
		userScore += pointsScored;
		int randPlayerNum = rand() % 5;
		userTeam[playerNum].setPossession(false);
		computerTeam[playerNum].setPossession(true);
		cout << pointsScored << " points scored by " << userTeam[playerNum].getName() << "! Ball turned over to Computer." << endl;
	}
	return pointsScored;
}

bool pass(BasketBallPlayer* userTeam, BasketBallPlayer* computerTeam) {
	int passer = getPossessor(userTeam);
	int receiver;
	cout << "Enter pass player number (1 - 5) exluding " << passer << ": ";
	cin >> receiver;
	while (receiver < 1 || receiver > 5 || passer == receiver) {
		cout << "ERROR: Incorrect Player Selection. Enter pass player number (1 - 5) exluding " << passer+1 << ": ";
		cin >> receiver;
	}
	receiver -= 1;
	if (userTeam[passer].passBall()) {
		cout << userTeam[passer].getName() << " passed the ball to " << userTeam[receiver].getName() << endl;
		userTeam[passer].setPossession(false);
		userTeam[receiver].setPossession(true);
		return true;
	}
	else {
		cout << userTeam[passer].getName() << " failed to pass the ball to " << userTeam[receiver].getName() << endl;
		userTeam[passer].setPossession(false);
		int randPlayerNum = rand() % 5;
		computerTeam[randPlayerNum].setPossession(true);
		cout << "Computer Team's player " << computerTeam[randPlayerNum].getName() << " now has the ball." << endl;
		return false;
	}
}

void seePlayerStats(BasketBallPlayer* team) {
	cout << THICK_LINE_SEPARATOR << endl;
	cout << "ALL PLAYER'S STATS FOR TEAM: " << team[0].getTeamName() << endl;
	cout << THICK_LINE_SEPARATOR << endl;
	cout << left << setw(20) << "Player Name";
	cout << left << setw(13) << "Shots Taken";
	cout << left << setw(12) << "Shots Made";
	cout << left << setw(18) << "Passes Attempted";
	cout << left << setw(13) << "Passes Made" << endl;
	cout << THIN_LINE_SEPERATOR << endl;
	for (int i = 0; i < 5; i++) {
		cout << left << setw(20) << team[i].getName();
		cout << left << setw(13) << team[i].getShotsTaken();
		cout << left << setw(12) << team[i].getShotsMade();
		cout << left << setw(18) << team[i].getPassesAttempted();
		cout << left << setw(13) << team[i].getPassesMade() << endl;
		cout << left << THIN_LINE_SEPERATOR << endl;
	   }
	cout << THICK_LINE_SEPARATOR << endl << endl;
}

void seeScore(int playerScore, int computerScore, int playerPossessions, int computerPossessions) {
	cout << THICK_LINE_SEPARATOR << endl;
	cout << "CURRENT GAME STATS: " << endl;
	cout << THICK_LINE_SEPARATOR << endl;
	cout << "User vs. Computer Score: " << playerScore << ":" << computerScore << endl;
	cout << "Remaining User possessions: " << TOTAL_POSSESSIONS - playerPossessions << endl;
	cout << "Remaining Computer possessions: " << TOTAL_POSSESSIONS - computerPossessions << endl;
	cout << THIN_LINE_SEPERATOR << endl;
	cout << THICK_LINE_SEPARATOR << endl << endl;
}

int turnMenu() {
	int response;
	cout << THICK_LINE_SEPARATOR << endl;
	cout << "MENU OPTIONS: " << endl;
	cout << THICK_LINE_SEPARATOR << endl;
	cout << "Pick One: " << endl;
	cout << THIN_LINE_SEPERATOR << endl;
	cout << "	1. Pass" << endl;
	cout << "	2. Shoot" << endl;
	cout << "	3. See Your Players' Stats" << endl;
	cout << "	4. See Score " << endl;
	cout << "	5. See Computer Players' Stats" << endl;
	cout << THIN_LINE_SEPERATOR << endl;
	cout << "  Type in your response: ";
	cin >> response;
	cout << THIN_LINE_SEPERATOR << endl;
	cout << endl;
	while  (response < 1 || response > 5) {
		cout << "ERROR: Invalid response. Select correct option from menu above: ";
		cin >> response;
		cout << endl;
	}
	return response;
}

void playComputer(int &computerScore, BasketBallPlayer* userTeam, BasketBallPlayer* computerTeam) {
	/*
	Takes computer's turn.
	Updates computer's score
	Changes possesion of ball if needed.
	*/
	int cPointSelection = rand() % 3 + 1;
	int cPlayerNum = getPossessor(computerTeam);
	if (rand() % 100 + 1 > 40) { //Computer made succssful shot (60% chance for each computer player)
		cout << "Computer Team's " << computerTeam[cPlayerNum].getName() << " scored " << cPointSelection << " points! " << endl;
		int randUserPlayer = rand() % 5;
		computerScore += cPointSelection;
		cout << "Ball handed over to " << userTeam[randUserPlayer].getTeamName() << "'s " << userTeam[randUserPlayer].getName() << endl;
		computerTeam[cPlayerNum].setPossession(false);
		userTeam[randUserPlayer].setPossession(true);
	}
	else if (rand() % 2 == 1) {//50% chance of retaining possession if basket unsucsessful
		// Rebound secured case
		cout << "Computer Team's " << computerTeam[cPlayerNum].getName() << " missed the basket but mangaged to secure the rebound" << endl;
		playComputer(computerScore, userTeam, computerTeam);
	}
	else {
		//Failed to secure rebound
		cout << "Computer Team's " << computerTeam[cPlayerNum].getName() << " missed the basket." << endl;
		int randUserPlayer = rand() % 5;
		cout << userTeam[randUserPlayer].getTeamName() << "'s " << userTeam[randUserPlayer].getName() << " stole the ball" << endl;
		computerTeam[cPlayerNum].setPossession(false);
		userTeam[randUserPlayer].setPossession(true);
	}
 }

int main() {
	srand(time(NULL));
	BasketBallPlayer userTeam[5];
	BasketBallPlayer computerTeam[5];
	int userPossessions = 0;
	int computerPossessions = 0;
	int userScore = 0;
	int computerScore = 0;
	string teamName;
	cout << "Enter Team's Name: ";
	cin >> teamName;
	cout << endl;
	for (int i = 0; i < 5; i++) {
		string playerName;
		cout << "Enter player " << i << "'s name: ";
		cin >> playerName;
		userTeam[i].setName(playerName);
		userTeam[i].setTeamName(teamName);
		computerTeam[i].setName("Player " + to_string(i));
		computerTeam[i].setTeamName("Computer");
	}
	cout << THICK_LINE_SEPARATOR << endl;
	cout << "STARTING GAME: " << endl;
	cout << THICK_LINE_SEPARATOR << endl;
	seeScore(userScore, computerScore, userPossessions, computerPossessions);
	seePlayerStats(userTeam);
	seePlayerStats(computerTeam);
	cout << "RESULTS OF COIN TOSS (WINNER GETS THE BALL): "; 
	int t = rand() % 2;
	int randPlayer = rand() % 5;
	if (t == 0) {
		cout << "Computer Wins. Ball handed to: " << computerTeam[randPlayer].getName() << endl;
		computerTeam[randPlayer].setPossession(true);
	}
	else {
		cout << "Team " << userTeam[randPlayer].getTeamName() << " Wins. Ball handed to: " << userTeam[randPlayer].getName() << endl;
		userTeam[randPlayer].setPossession(true);
	}
	
	int response;
	while (userPossessions < 20 and computerPossessions < 20) {
		if (getPossessor(userTeam) == -1) {
			playComputer(computerScore, userTeam, computerTeam);
			computerPossessions += 1;
		}
		else {
			response = turnMenu();
			switch (response) {
			case 1:
				cout << THICK_LINE_SEPARATOR << endl;
				cout << "ATTEMPTING PASS" << endl;
				cout << THICK_LINE_SEPARATOR << endl;
				if (!pass(userTeam, computerTeam)) {
					userPossessions += 1;
				}
				break;
			case 2:
				cout << THICK_LINE_SEPARATOR << endl;
				cout << "ATTEMPTING TO SHOOT BASKET" << endl;
				cout << THICK_LINE_SEPARATOR << endl;
				shoot(userScore, userTeam, computerTeam);
				if (getPossessor(userTeam) == -1) { //If rebound is not secured
					userPossessions += 1;
				}
				break;
			case 3:
				seePlayerStats(userTeam);
				break;
			case 4:
				seeScore(userScore, computerScore, userPossessions, computerPossessions);
				break;
			case 5:
				seePlayerStats(computerTeam);
				break;
			default:
				cout << "WHY? HOW?" << endl;
			}
		
		}
		seeScore(userScore, computerScore, userPossessions, computerPossessions);
	}

	if (userScore > computerScore) {
		cout << THICK_LINE_SEPARATOR << endl;
		cout << "RESULTS: " << userTeam[0].getTeamName() << "wins! " << endl;
		cout << THICK_LINE_SEPARATOR << endl;
	}
	else if (userScore == computerScore){
		cout << THICK_LINE_SEPARATOR << endl;
		cout << "RESULTS: Game Tied!" << endl;
		cout << THICK_LINE_SEPARATOR << endl;
	}
	else {
		cout << THICK_LINE_SEPARATOR << endl;
		cout << "RESULTS: Computer wins! " << endl;
		cout << THICK_LINE_SEPARATOR << endl;
	}
	seeScore(userScore, computerScore, userPossessions, computerPossessions);
	return 0;
}

