#pragma once
class ShelfOfGames
{
	const static int MAX_GAMES = 10;
	int numGames;
	//array of games

public:
	//Constructor
	ShelfOfGames();
	//Getters
	int getMaxGames();
	int getNumGames();
	//*Game getGameList();
	//Setters
	void setNumGames(int);
	//void setGames(*game);
	//Other functions
	//void addBoardGame(Game); //Adds board game
	//Game removeBoardGame(); //Should this accept which game to remove?


};

