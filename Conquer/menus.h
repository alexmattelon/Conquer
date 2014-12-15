#ifndef MENUS_H
#define MENUS_H

#include "countries.h"

class Menus
{
public:
	void MainMenu();
	void Start();
	void AllocateRessources(int Ressources, int Knights, int Wizards, int Demons);
	void Turn();
	void Infos();
	void Attack();
	void BuildDefenses();
	void Troops();
	void UnitSelection(int Ressources, int Knights, int Wizards, int Demons);
	void Knight(int Ressources);
	void Wizard(int Ressources);
	void Demon(int Ressources);
};

#endif