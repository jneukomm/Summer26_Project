//****************************************************************************************************

#include"Wizard.h"
#include"Spell.h"

#include<conio.h>

//****************************************************************************************************

#include<iostream>
#include<fstream>
#include<cstring>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

void nextScreen();
void spellSubMenu(char&, Spell*&, int&);

void createCharacter(const string&, Wizard&, Spell*, const int&);
void saveCharacter(const string&, Wizard&);
void loadCharacter(const string&, Wizard&);
void displayCharacter(Wizard&);

void createSpellPool(const string&, Spell*&, int&);
void saveSpells(const string&, Spell&, int);
void loadSpellPool(const string&, Spell*&, int&);
void displaySpells(const string&, Spell*&, int&);

int randRoll();

//****************************************************************************************************

int main()
{
	srand((unsigned int)time(0));
	Wizard player;
	Spell* pool = nullptr;
	int poolSize = 0;
	char tempChoice = ' ',
		 choice = ' ',
		 sChoice = ' ';
	ifstream charFile("Character.dat", ios::binary);
	ifstream spellFile("Spellpool.dat", ios::binary);

//****************************************************************************************************
//  Intro
//****************************************************************************************************

	cout << "===================================\n"
		 << "|        Dnd Wizard Creator       |\n"
		 << "|          Summer Project         |\n"
		 << "===================================\n"
		 << "|Instructions:                     \n"
		 << "|Make a choice based of text in [].\n"
		 << "|[y] Yes.                          \n" 
		 << "|[n] No.                           \n"
		 << "|Press any key to continue.        \n";

	_getch();
	nextScreen();

//****************************************************************************************************
//  Character Check & Load
//****************************************************************************************************

	if (!charFile.fail())
	{
		cout << "Character File Found. \n"
			<< "Load Character?        \n"
			<< "[y] Yes \t"
			<< "[n] No                 \n"
			<< "Input:                 \n";
		tempChoice = _getch();
		choice = tolower(tempChoice);
		if (choice == 'y')
		{
			loadCharacter("Character.dat", player);
			nextScreen();
		}
		else
			cout << "===================================\n";
	}

//****************************************************************************************************
//  Spell Check & Load
//****************************************************************************************************

	if (!spellFile.fail())
	{
		cout << "Spell List Found.  \n"
			 << "Load Spells?       \n"
			 << "[y] Yes \t"
			 << "[n] No             \n"
			 << "Input: ";
		tempChoice = _getch();
		cout << endl;
		choice = tolower(tempChoice);
		if (choice == 'y')
		{
			loadSpellPool("Spellpool.dat", pool, poolSize);
			nextScreen();
		}
		else
			cout << "===================================\n";
	}

//****************************************************************************************************
//  Main Menu Loop
//****************************************************************************************************

	while (choice != 'q')
	{
		cout << "\tMain Menu\n"
			<< "===================================\n"
			<< "| Pick from the following:         \n"
			<< "| [c] Create Character             \n"
			<< "| [d] Display Character            \n"
			<< "| [s] Spells                       \n"
			<< "| [p] Play                         \n"
			<< "| [q] Quit                         \n"
			<< "| Input:                           \n";
		tempChoice = _getch();
		choice = tolower(tempChoice);

		nextScreen();

//****************************************************************************************************
//	Switch Logic
//****************************************************************************************************

		switch (choice)
		{

			case 'c':
				createCharacter("Character.dat", player, pool, poolSize);
				nextScreen();
				break;

			case 'd':
				displayCharacter(player);
				nextScreen();
				break;

			case 's':
				spellSubMenu(sChoice, pool, poolSize);
				break;
				
			case 'p':
				cout << "You Level up.";
				player.levelUp(player);
				displayCharacter(player);
				cout << "\n=================";
				cout << "\n\nCongrats! You Level up again";
				player.levelUp(player);
				saveCharacter("Character.dat", player);
				cout << "displayed:\n";
				cout << "=================\n";
				displayCharacter(player);
				break;

			default:
				cout << "Invalid Selection\n";

		}
	}

//****************************************************************************************************
//  Main Return - Do not move this, you'll have a headache...
//****************************************************************************************************
	
	return 0;
}

//****************************************************************************************************
//	Functions
//****************************************************************************************************

	void createCharacter(const string & fileName, Wizard & w, Spell * pool, const int& poolSize)
	{
		string tempName;
		char tempChoice = ' ',
			 tempSpell = ' ';
		int skillLvl = 0;
		

	//************************************************************************************************
	//  Set Skills
	//************************************************************************************************

		w.setIntel(randRoll());
		w.setWiz(randRoll());
		w.setCon(randRoll());
		w.setDex(randRoll());
		w.setStr(randRoll());

	//************************************************************************************************

		cout << "\tCharacter Creator\n"
			<< "===================================\n";

		cout << "\nEnter Name: ";
		getline(cin, tempName);
		w.setName(tempName);

	//************************************************************************************************
	//	Initial Display - Hard coded to avoid the repeating name
	//************************************************************************************************

		cout << "Your Class is: Wizard\n"
			<< "Your Race is: Gnome\n";
		cout << "Level: " << w.getLevel()
			<< "\nIntel:" << w.getIntel()
			<< "\nWiz: " << w.getWiz()
			<< "\nDex: " << w.getDex()
			<< "\nCon: " << w.getCon()
			<< "\nStr: " << w.getStr();
		w.setNumSpells(w);
		cout << "\nNum Spells: " << w.getNumSpells();
		cout << "\n\n \t Press Enter To Continue: " << endl;
		cin.get();

	//************************************************************************************************
	//	Spell Picker and Display
	//************************************************************************************************

		cout << "\n===================================\n";
		cout << "Spell Creator\n"
			<< "=====================================\n";

		cout << "Your total spells right now are: " << w.getNumSpells() << endl;

		w.createPlayerSpell(w, pool, poolSize);

		w.displayPlayerSpell(w);

	//************************************************************************************************
	//  Save character
	//************************************************************************************************
		
		cout << "\n\n \t Press Enter To Continue: " << endl;
		cin.get();
		cout << "Save?\n"
			<< "[y] Yes\n"
			<< "[n] No\n"
			<< "Input: ";
		cin >> tempChoice;
		tempChoice = tolower(tempChoice);
		cout << "===================================\n";

		if (tempChoice == 'y')
		{
			saveCharacter(fileName, w);
			cout << "\tCharacter Saved";
		}
		else
			cout << "Not Saved.";

		cout << "\n===================================\n";

		return;
	}

//****************************************************************************************************

	void nextScreen()
	{
		cout << "===================================\n";

		for (int i = 0; i < 3; i++)
		{
			cout << "///////////////////////////////////\n";
		}

		cout << "===================================\n";
	}

//****************************************************************************************************

	void loadCharacter(const string & fileName, Wizard & w)
	{
		ifstream f("Character.dat", ios::binary);
		f.read(reinterpret_cast<char*>(&w), sizeof(w));
		int numSpells = 0;
		f.read(reinterpret_cast<char*>(&numSpells), sizeof(int));
		if (numSpells > 0)
		{
			Spell* temp = new Spell[numSpells];
			f.read(reinterpret_cast<char*>(temp), sizeof(Spell) * numSpells);
			w.setSpells(temp, numSpells);
		}
		
		return;
	}

//****************************************************************************************************

	void saveCharacter(const string & fileName, Wizard & w)
	{
		ofstream f(fileName, ios::binary);
		f.write(reinterpret_cast<char*>(&w), sizeof(w));
		int numSpells = w.getNumSpells();
		f.write(reinterpret_cast<char*>(&numSpells), sizeof(int));
		if (numSpells > 0)
		{
			f.write(reinterpret_cast<char*>(w.getSpells()), sizeof(Spell) * numSpells);
		}

		return;
	}

//****************************************************************************************************

	int randRoll()
	{
		int roll = 0;

		roll = rand() % 8 + 1;

		return roll;
	}

//****************************************************************************************************

	void displayCharacter(Wizard & player)
	{
		player.setNumSpells(player);
		cout << "Name: " << player.getName()
			<< "\nLevel: " << player.getLevel();
		cout << "\nIntel: " << player.getIntel()
			<< "\nDex: " << player.getDex()
			<< "\nCon: " << player.getCon()
			<< "\nStr: " << player.getStr()
			<< "\nNum Spells: " << player.getNumSpells()
			<< endl;

		cout << "=================================\n";

		player.displayPlayerSpell(player);
	}

//****************************************************************************************************

	void createSpellPool(Spell *& pool, int& poolSize)
	{
		string tempName;
		string tempDesc;
		int newSpells = 0;

		cin.get();
		cout << "|Welcome to the Spellbook Wizard.\n"
			 << "|Instructions:\n"
			 << "|Here We Will create a spell pool\n"
			 << "|for use within the game.\n";

		cout << "===================================\n"
			<< "\tStep One\n"
			<< "===================================\n"

			<< "\nHow many spells to add? ";

		cin >> newSpells;
		cin.ignore();

		Spell* temp = new Spell[poolSize + newSpells];

		//********************************************************************************************
		//  Copy Existing Array
		//********************************************************************************************

		for (int i = 0; i < poolSize; i++)
		{
			temp[i] = pool[i];
		}
		
		//********************************************************************************************
		//  Add New Spells
		//********************************************************************************************

		for (int i = 0; i < newSpells; i++)
		{
			int idx = poolSize + i;

			cout << "\tStep Two\n"
				 << "===================================\n";
			cout << "\nEnter Information for spell " << idx + 1 << ":\n";

			cout << "Enter spell name (Max 30 Char): ";
			getline(cin, tempName);
			if (tempName.length() > 30)
			{
				cout << "Name too long - Trimmed to 30 Char";
				tempName = tempName.substr(0, 30);
			}
			strncpy_s(temp[idx].spellName, tempName.c_str(), sizeof(temp[idx].spellName) - 1);

			cout << "Enter spell level: ";
			cin >> temp[idx].spellLevel;

			cout << "Enter spell damage: ";
			cin >> temp[idx].spellDamage;
			cin.ignore();

			cout << "Enter spell description (Max 100 Char): ";
			getline(cin, tempDesc);
			if (tempDesc.length() > 100)
			{
				cout << "Description too long - trimmed to 100 Char";
				tempDesc = tempDesc.substr(0, 100);
			}
			strncpy_s(temp[idx].spellDescription, tempDesc.c_str(), 
				      sizeof(temp[idx].spellDescription) - 1);
		}

		delete[] pool;
		pool = temp;
		poolSize += newSpells;

		ofstream f("Spellpool.dat", ios::binary);
		f.write(reinterpret_cast<char*>(&poolSize), sizeof(int));
		f.write(reinterpret_cast<char*>(pool), sizeof(Spell) * poolSize);
		f.close();
	
		cout << "Spellbook saved. Total number of spells: " << poolSize << ".\n";
 	}

//****************************************************************************************************

	void displaySpells(const string&, Spell*& pool, int& poolSize)
	{
		if (pool == nullptr || poolSize == 0)
		{
			cout << "No spells in pool.\n";
			return;
		}

		cout << "\n\t--- Spell Pool ---\n";
		cout << "===================================\n";

		for (int i = 0; i < poolSize; i++)
		{
			cout << i + 1 << ". "
				<< "\nName:        " << pool[i].spellName
				<< "\nLevel:       " << pool[i].spellLevel
				<< "\nDamage:      " << pool[i].spellDamage
				<< "\nDescription: " << pool[i].spellDescription
				<< "\n===================================\n";
		}
	}

//****************************************************************************************************

	void saveSpells(const string & fileName, Spell & spellbook, int totSpells)
	{
		ofstream f(fileName, ios::binary);

		f.write(reinterpret_cast<char*>(&totSpells), sizeof(int));
		f.write(reinterpret_cast<char*>(&spellbook), sizeof(spellbook));
		return;
	}

//****************************************************************************************************

	void loadSpellPool(const string & fileName, Spell*& pool, int& poolSize)
	{
		char tempChoice = ' ';
		ifstream spellFile("Spellpool.dat", ios::binary);

				spellFile.read(reinterpret_cast<char*>(&poolSize), sizeof(int));
				delete[] pool;
				pool = new Spell[poolSize];
				spellFile.read(reinterpret_cast<char*>(pool), sizeof(Spell) * poolSize);
	}

//****************************************************************************************************

	void spellSubMenu(char& sChoice, Spell*& pool, int& poolSize)
	{
		sChoice = ' ';

		while (sChoice != 'z')
		{
			cout << "\tSpell Sub Menu\n"
				<< "Number of Spells in pool: " << poolSize << "\n"
				<< "===================================\n"
				<< "| [c] Create Spellbook             \n"
				<< "| [l] Load Spellbook               \n"
				<< "| [d] Display Spellbook            \n"
				<< "| [r] Return                       \n"
				<< "| Input: ";
			cin >> sChoice;
			sChoice = tolower(sChoice);
			cin.ignore();

			switch (sChoice)
			{
			case 'l':
				loadSpellPool("Spellpool.dat", pool, poolSize);
				break;
			case 'c':
				createSpellPool(pool, poolSize);
				break;
			case 'd':
				displaySpells("Spellpool.dat", pool, poolSize);
				break;
			case 'r':
				sChoice = 'z';
				break;
			default:
				cout << "Invalid selection\n";
				break;
			}
		}
	}

//****************************************************************************************************