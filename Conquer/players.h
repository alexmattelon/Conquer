#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
using namespace std;

class Players
{
public:
	string Name;
	int Knights;
	int Wizards;
	int Demons;
	int Ressources;

	Players(string Name, int argKnights, int argWizards, int argDemons, int argRessources);
	~Players();
};

#endif