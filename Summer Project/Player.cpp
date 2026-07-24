//****************************************************************************************************

#include"Player.h"

//****************************************************************************************************

#include<iostream>
#include<cstring>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

Player::Player()
{
	strncpy_s(playerName, " ", sizeof(playerName)- 1);
	playerLevel = 1;
	playerXp = 0;

	playerIntel = 0;
	playerCon = 0;
	playerDex = 0;
	playerStr = 0;
}

Player::~Player()
{


}

//****************************************************************************************************
// Name and Level
//****************************************************************************************************

void Player::setName(string name)
{
	strncpy_s(playerName, name.c_str(), sizeof(playerName) -1 );
}


string Player::getName()
{
	return string(playerName);
}

//****************************************************************

void Player::setLevel(int level)
{
	playerLevel = level;
}


int Player::getLevel()
{
	return playerLevel;
}

//****************************************************************************************************
// Level Up
//****************************************************************************************************

void Player::levelUp(Player& p)
{
	setLevel((playerLevel+1));
	setCon((playerCon + 2));
	setDex((playerDex + 1));
	setIntel((playerIntel + 3));
	setStr((playerStr + 1));

}

//****************************************************************************************************
// Skills
//****************************************************************************************************

void Player::setDex(int lvl)
{
	playerDex = lvl;
}

int Player::getDex()
{
	return playerDex;
}

//****************************************************************

void Player::setStr(int lvl)
{
	playerStr = lvl;
}

int Player::getStr()
{
	return playerStr;
}

//****************************************************************

void Player::setWiz(int lvl)
{
	playerWiz = lvl;
}

int Player::getWiz()
{
	return playerWiz;
}

//****************************************************************

void Player::setCon(int lvl)
{
	playerCon = lvl;
}

int Player::getCon()
{
	return playerCon;
}

//****************************************************************

void Player::setIntel(int lvl)
{
	playerIntel = lvl;
}

int Player::getIntel()
{
	return playerIntel;
}

//****************************************************************************************************