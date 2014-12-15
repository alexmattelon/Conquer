#include "countries.h"

Countries::Countries(string argName, int argOwnership, int argDefense, int argKnights, int argWizards, int argDemons, int argRessources)
{
	Name = argName;
	Ownership = argOwnership;
	Defense = argDefense;
	Knights = argKnights;
	Wizards = argWizards;
	Demons = argDemons;
	Ressources = argRessources;
}

Countries::~Countries()
{

}