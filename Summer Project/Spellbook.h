//****************************************************************************************************

#include"Spell.h"

//****************************************************************************************************

class Spellbook
{
private:
	Spell* spells;
	int numSpells;

public:
	Spellbook();
	int getNumSpells();
	void setNumSpells(int);

};