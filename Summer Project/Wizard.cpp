//****************************************************************************************************

#include"Wizard.h"
#include"Player.h"

//****************************************************************************************************

#include<iostream>
#include<iomanip>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

Wizard::Wizard()
{
	numSpells = 0;
	spells = nullptr;
}

Wizard::~Wizard()
{

}

//****************************************************************************************************

int Wizard::getNumSpells()
{
	return numSpells;

}

void Wizard::setNumSpells(Wizard& w)
{
	int wIntel = w.getIntel();
	int wWiz = w.getWiz();
	numSpells = ((wIntel + (wWiz /2)) / 2);
}


//****************************************************************************************************

void Wizard::createPlayerSpell(Wizard& w, Spell* pool ,const int& poolSize)
{
	int tempSpell = ' ';

	cout << "Pick " << w.getNumSpells() << " spells from the pool.\n";

	w.spells = new Spell[w.getNumSpells()];

	for (int i = 0; i < w.getNumSpells(); i++)
	{
		cout << "Pick your Spell: \n";

		for (int p = 0; p < poolSize; p++)
		{
			cout << "[" << (p + 1) << "]" << " " << pool[p].spellName
				<< " | " << "Level:" << pool[p].spellLevel << endl;
		}
		cout << "Input: ";
		cin >> tempSpell;
		tempSpell = (tempSpell - 1);

		w.spells[i] = pool[tempSpell];

	}

}

//****************************************************************************************************

void Wizard::displayPlayerSpell(Wizard& w)
{
	int numSpells = w.getNumSpells();
		for (int i = 0; i < numSpells; i++)
		{
			cout << left;
			cout << setw(15) << "Spell Name: " << setw(8) << w.spells[i].spellName << endl;
			cout << setw(15) << "Spell Level: " << setw(8) << w.spells[i].spellLevel << endl;
			cout << setw(15) << "Spell Damage: " << setw(8) << w.spells[i].spellDamage << endl;
			cout << setw(15) << "Spell Desc: " << setw(50) << w.spells[i].spellDescription << endl;
		}
}

//****************************************************************************************************

void Wizard::setSpells(Spell* s, int num)
{
	delete[] spells;
	spells = s;
	numSpells = num;
}

//****************************************************************************************************