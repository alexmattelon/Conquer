#ifndef COUNTRIES_H
#define COUNTRIES_H

#include <iostream>
using namespace std;

class Countries
{
public:
	string Name;
	int Ownership;
	int Defense;
	int Knights;
	int Wizards;
	int Demons;
	int Ressources;

	Countries(string Name, int argOwnership, int argDefense, int argKnights, int argWizards, int argDemons, int argRessources);
	~Countries();
};

#endif