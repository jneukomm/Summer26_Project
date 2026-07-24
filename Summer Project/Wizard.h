//****************************************************************************************************

#ifndef WIZARD_H
#define WIZARD_H

//****************************************************************************************************

#include"Player.h"
#include"Spell.h"

//****************************************************************************************************

class Wizard : public Player
{
protected:
	int numSpells;
	Spell* spells;
public:
	Wizard();
	~Wizard();

	int getNumSpells();
	void setNumSpells(Wizard&);

	void createPlayerSpell(Wizard&, Spell*, const int&);
	void displayPlayerSpell(Wizard&);

	Spell* getSpells() { return spells; }
	void setSpells(Spell*, int);
};



//****************************************************************************************************

#endif

//****************************************************************************************************
