#include "players.h"

Players::Players(string argName, int argKnights, int argWizards, int argDemons, int argRessources)
{
	Name = argName;
	Knights = argKnights;
	Wizards = argWizards;
	Demons = argDemons;
	Ressources = argRessources;
}

Players::~Players()
{

}