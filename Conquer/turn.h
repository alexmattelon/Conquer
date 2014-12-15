#ifndef TURN_H
#define TURN_H

#include <iostream>
#include <ctime>
#include "countries.h"
#include "players.h"
#include "errorHandling.h"
#include "config.h"

using namespace std;

class Turn
{
public:
	int Attack(Countries &Country, int &Knights, int &Wizards, int &Demons);
	int BuildDefenses(int Defense, int &Ressources);
	void StationTroops(int &PlayerKnights, int &PlayerWizards, int &PlayerDemons, int &CountryKnights, int &CountryWizards, int &CountryDemons);
	void ArtheonTurn(Players &Artheon, Countries &Domed, Countries &Tane, Countries &Joha, Countries &Odori, Countries &Antemie);
	void ArtheonTroops(int &ARessources, int &AKnights, int &AWizards, int &ADemons);
};

#endif