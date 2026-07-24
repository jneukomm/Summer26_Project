//****************************************************************************************************

#ifndef PLAYER_H
#define PLAYER_H

//****************************************************************************************************

#include<string>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

class Player
{
protected:
	char playerName[31];
	int playerLevel,
		playerXp;

	int playerIntel,
		playerWiz,
		playerDex,
		playerCon,
		playerStr;


public:
	Player();
	~Player();

	void levelUp(Player& w);


	void setName(string);
	string getName();

	void setLevel(int);
	int getLevel();

	void setIntel(int);
	int getIntel();

	void setDex(int);
	int getDex();

	void setCon(int);
	int getCon();

	void setStr(int);
	int getStr();

	void setWiz(int);
	int getWiz();

};

//****************************************************************************************************

#endif

//****************************************************************************************************