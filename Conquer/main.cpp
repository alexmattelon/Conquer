#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "config.h"
#include "menus.h"
#include "errorHandling.h"
#include "maps.h"
#include "countries.h"
#include "turn.h"
#include "players.h"

using namespace std;

void main()
{
	//Calling the classes
	Config ApplyConfig;
	Menus DisplayMenus;
	ErrorHandling Check;
	Maps DisplayMaps;
	Turn TurnChoice;
	ofstream fout;
	ifstream fin;

	//Creating the countries
	Countries Domed("Domed", 0, 0, 0, 0, 0, 10);
	Countries Tane("Tane", 0, 0, 0, 0, 0, 20);
	Countries Joha("Joha", 0, 0, 0, 0, 0, 15);
	Countries Odori("Odori", 0, 0, 0, 0, 0, 20);
	Countries Antemie("Antemie", 0, 0, 0, 0, 0, 25);

	//Creating the players
	Players Player(" ", 0, 0, 0, 100);
	Players Artheon("Artheon", 15, 7, 5, 0);

	//Declaring the variables
	int Answer;
	string Name;
	int AnswerTurn;
	int AnswerInfos;
	int AnswerAttack;
	int AnswerDefense;
	int AnswerBuildU;
	char AnswerUnit;
	int AnswerTroops;
	bool Ended = false;
	bool GameOver = false;
	string line[5];
	string endline;
	int x;

	//Apply the config for the screen and the buffer
	ApplyConfig.ConsoleConfig();
	ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	do
	{
		//Display the menu
		DisplayMenus.MainMenu();
		cin >> Answer;
		//Checks if the user has entered a correct input
		Answer = Check.Menu3(Answer);
		ApplyConfig.ClearScreen();
		switch(Answer)
		{
		case 1: //Play
			//Reset values of countries and players to zero
			Player.Name = " ";
			Player.Knights = 0;
			Player.Wizards = 0;
			Player.Demons = 0;
			Player.Ressources = 100;
			Artheon.Knights = 0;
			Artheon.Wizards = 0;
			Artheon.Demons = 0;
			Artheon.Ressources = 100;
			Domed.Ownership = 0;
			Domed.Defense = 0;
			Domed.Knights = 0;
			Domed.Wizards = 0;
			Domed.Demons = 0;
			Tane.Ownership = 0;
			Tane.Defense = 0;
			Tane.Knights = 0;
			Tane.Wizards = 0;
			Tane.Demons = 0;
			Joha.Ownership = 0;
			Joha.Defense = 0;
			Joha.Knights = 0;
			Joha.Wizards = 0;
			Joha.Demons = 0;
			Odori.Ownership = 0;
			Odori.Defense = 0;
			Odori.Knights = 0;
			Odori.Wizards = 0;
			Odori.Demons = 0;
			Antemie.Ownership = 0;
			Antemie.Defense = 0;
			Antemie.Knights = 0;
			Antemie.Wizards = 0;
			Antemie.Demons = 0;
			
			DisplayMenus.Start();
			cin >> Player.Name;
			//You can't make a good game without cheat codes in it xD
			if(Player.Name == "Artheon")
			{
				Player.Ressources = 200;
				Player.Knights = 25;
				Player.Wizards = 25;
				Player.Demons = 25;
				cout << "\n Artheon is a cool name! Here get some free ressources \n";
			}
			cout << "\n";
			do
			{
				DisplayMenus.AllocateRessources(Player.Ressources, Player.Knights, Player.Wizards, Player.Demons);
				cin >> AnswerBuildU;
				//Checks if the user has entered a correct input
				AnswerBuildU = Check.Menu4(AnswerBuildU);
				ApplyConfig.ClearScreen();
				switch(AnswerBuildU)
				{
				case 1: //Knight
					if(Player.Ressources < 1)
					{
						cout << " You don't have enough ressources to build this unit.";
						cin.ignore();
						cout << endl << " Press ENTER to return to the previous menu...\n";
						cin.get();
						ApplyConfig.ClearScreen();
					}
					else
					{
						DisplayMenus.Knight(Player.Ressources);
						cin >> AnswerUnit;
						//Checks if the user has entered a correct input
						AnswerUnit = Check.MenuYN(AnswerUnit);
						ApplyConfig.ClearScreen();
						if(AnswerUnit == 'y')
						{
							Player.Knights = Player.Knights + 1;
							Player.Ressources = Player.Ressources - 1;
						}
					}
					break;
				case 2: //Wizard
					if(Player.Ressources < 5)
					{
						cout << " You don't have enough ressources to build this unit.";
						cin.ignore();
						cout << endl << " Press ENTER to return to the previous menu...\n";
						cin.get();
						ApplyConfig.ClearScreen();
					}
					else
					{
						DisplayMenus.Wizard(Player.Ressources);
						cin >> AnswerUnit;
						//Checks if the user has entered a correct input
						AnswerUnit = Check.MenuYN(AnswerUnit);
						ApplyConfig.ClearScreen();
						if(AnswerUnit == 'y')
						{
							Player.Wizards = Player.Wizards + 1;
							Player.Ressources = Player.Ressources - 5;
						}
					}
					break;
				case 3: //Demon
					if(Player.Ressources < 10)
					{
						cout << " You don't have enough ressources to build this unit.";
						cin.ignore();
						cout << endl << " Press ENTER to return to the previous menu...\n";
						cin.get();
						ApplyConfig.ClearScreen();
					}
					else
					{
						DisplayMenus.Demon(Player.Ressources);
						cin >> AnswerUnit;
						//Checks if the user has entered a correct input
						AnswerUnit = Check.MenuYN(AnswerUnit);
						ApplyConfig.ClearScreen();
						if(AnswerUnit == 'y')
						{
							Player.Demons = Player.Demons + 1;
							Player.Ressources = Player.Ressources - 10;
						}
					}
					break;
				}
			} while(AnswerBuildU != 4);
			cin.ignore();
			cout << "\n Alright " << Player.Name << ", press ENTER to begin your journey!";
			cin.get();			
			do
			{
				do
				{
					ApplyConfig.ClearScreen();
					DisplayMenus.Turn();
					cin >> AnswerTurn;
					//Checks if the user has entered a correct input
					AnswerTurn = Check.Menu6(AnswerTurn);
					ApplyConfig.ClearScreen();
					switch(AnswerTurn)
					{
					case 1: //Show Map
						do
						{
							DisplayMaps.MainMap(Domed.Ownership, Tane.Ownership, Joha.Ownership, Odori.Ownership, Antemie.Ownership);
							DisplayMenus.Infos();
							cin >> AnswerInfos;
							//Checks if the user has entered a correct input
							AnswerInfos = Check.Menu6(AnswerInfos);
							ApplyConfig.ClearScreen();
							switch(AnswerInfos)
							{
							case 1: //Domed
								cout << "\n"
										" Domed\n"
										" \xC4\xC4\xC4\xC4\xC4";
								switch(Domed.Ownership)
								{
								case 0:
									cout << "\n"
											" This country belongs to no one, it has no defenses and give " << Domed.Ressources << " ressources per turn.\n";
									break;
								case 1:
									cout << "\n"
										" This country belongs to you, you have " << Domed.Knights << " knights, " << Domed.Wizards << " wizards and " << Domed.Demons << " demons stationed here,\n"
										" there is " << Domed.Defense << " defenses and this country gives you " << Domed.Ressources << " ressources per turn.\n";
									break;
								case 2:
									cout << "\n"
											" This counrty belongs to your enemy so you cannot get any informations from it.\n";
									break;
								}
								cin.ignore();
								cout << endl << " Press ENTER to return to the map...\n";
								cin.get();							
								ApplyConfig.ClearScreen();
								break;
							case 2: //Tane
								cout << "\n"
										" Tane\n"
										" \xC4\xC4\xC4\xC4";
								switch(Tane.Ownership)
								{
								case 0:
									cout << "\n"
											" This country belongs to no one, it has no defenses and give " << Tane.Ressources << " ressources per turn.\n";
									break;
								case 1:
									cout << "\n"
										" This country belongs to you, you have " << Tane.Knights << " knights, " << Tane.Wizards << " wizards and " << Tane.Demons << " demons stationed here,\n"
										" there is " << Tane.Defense << " defenses and this country gives you " << Tane.Ressources << " ressources per turn.\n";
									break;
								case 2:
									cout << "\n"
											" This counrty belongs to your enemy so you cannot get any informations from it.\n";
									break;
								}
								cin.ignore();
								cout << endl << " Press ENTER to return to the map...\n";
								cin.get();							
								ApplyConfig.ClearScreen();
								break;
							case 3: //Joha
								cout << "\n"
										" Joha\n"
										" \xC4\xC4\xC4\xC4";
								switch(Joha.Ownership)
								{
								case 0:
									cout << "\n"
											" This country belongs to no one, it has no defenses and give " << Joha.Ressources << " ressources per turn.\n";
									break;
								case 1:
									cout << "\n"
										" This country belongs to you, you have " << Joha.Knights << " knights, " << Joha.Wizards << " wizards and " << Joha.Demons << " demons stationed here,\n"
										" there is " << Joha.Defense << " defenses and this country gives you " << Joha.Ressources << " ressources per turn.\n";
									break;
								case 2:
									cout << "\n"
											" This counrty belongs to your enemy so you cannot get any informations from it.\n";
									break;
								}
								cin.ignore();
								cout << endl << " Press ENTER to return to the map...\n";
								cin.get();							
								ApplyConfig.ClearScreen();
								break;
							case 4: //Odori
								cout << "\n"
										" Odori\n"
										" \xC4\xC4\xC4\xC4\xC4";
								switch(Odori.Ownership)
								{
								case 0:
									cout << "\n"
											" This country belongs to no one, it has no defenses and give " << Odori.Ressources << " ressources per turn.\n";
									break;
								case 1:
									cout << "\n"
										" This country belongs to you, you have " << Odori.Knights << " knights, " << Odori.Wizards << " wizards and " << Odori.Demons << " demons stationed here,\n"
										" there is " << Odori.Defense << " defenses and this country gives you " << Odori.Ressources << " ressources per turn.\n";
									break;
								case 2:
									cout << "\n"
											" This counrty belongs to your enemy so you cannot get any informations from it.\n";
									break;
								}
								cin.ignore();
								cout << endl << " Press ENTER to return to the map...\n";
								cin.get();							
								ApplyConfig.ClearScreen();
								break;
							case 5: //Antemie
								cout << "\n"
										" Antemie\n"
										" \xC4\xC4\xC4\xC4\xC4\xC4\xC4";
								switch(Antemie.Ownership)
								{
								case 0:
									cout << "\n"
											" This country belongs to no one, it has no defenses and give " << Antemie.Ressources << " ressources per turn.\n";
									break;
								case 1:
									cout << "\n"
										" This country belongs to you, you have " << Antemie.Knights << " knights, " << Antemie.Wizards << " wizards and " << Antemie.Demons << " demons stationed here,\n"
										" there is " << Antemie.Defense << " defenses and this country gives you " << Antemie.Ressources << " ressources per turn.\n";
									break;
								case 2:
									cout << "\n"
											" This counrty belongs to your enemy so you cannot get any informations from it.\n";
									break;
								}
								cin.ignore();
								cout << endl << " Press ENTER to return to the map...\n";
								cin.get();							
								ApplyConfig.ClearScreen();
								break;
							}
						} while(AnswerInfos != 6);
						Ended = false;
						break;				
					case 2: //Build Units
						do
						{
							DisplayMenus.UnitSelection(Player.Ressources, Player.Knights, Player.Wizards, Player.Demons);
							cin >> AnswerBuildU;
							//Checks if the user has entered a correct input
							AnswerBuildU = Check.Menu4(AnswerBuildU);
							ApplyConfig.ClearScreen();
							switch(AnswerBuildU)
							{
							case 1: //Knight
								if(Player.Ressources < 1)
								{
									cout << " You don't have enough ressources to build this unit.";
									cin.ignore();
									cout << endl << " Press ENTER to return to the previous menu...\n";
									cin.get();
									ApplyConfig.ClearScreen();
								}
								else
								{
									DisplayMenus.Knight(Player.Ressources);
									cin >> AnswerUnit;
									//Checks if the user has entered a correct input
									AnswerUnit = Check.MenuYN(AnswerUnit);
									ApplyConfig.ClearScreen();
									if(AnswerUnit == 'y')
									{
										Player.Knights = Player.Knights + 1;
										Player.Ressources = Player.Ressources - 1;
									}
								}
								break;
							case 2: //Wizard
								if(Player.Ressources < 5)
								{
									cout << " You don't have enough ressources to build this unit.";
									cin.ignore();
									cout << endl << " Press ENTER to return to the previous menu...\n";
									cin.get();
									ApplyConfig.ClearScreen();
								}
								else
								{
									DisplayMenus.Wizard(Player.Ressources);
									cin >> AnswerUnit;
									//Checks if the user has entered a correct input
									AnswerUnit = Check.MenuYN(AnswerUnit);
									ApplyConfig.ClearScreen();
									if(AnswerUnit == 'y')
									{
										Player.Wizards = Player.Wizards + 1;
										Player.Ressources = Player.Ressources - 5;
									}
								}
								break;
							case 3: //Demon
								if(Player.Ressources < 10)
								{
									cout << " You don't have enough ressources to build this unit.";
									cin.ignore();
									cout << endl << " Press ENTER to return to the previous menu...\n";
									cin.get();
									ApplyConfig.ClearScreen();
								}
								else
								{
									DisplayMenus.Demon(Player.Ressources);
									cin >> AnswerUnit;
									//Checks if the user has entered a correct input
									AnswerUnit = Check.MenuYN(AnswerUnit);
									ApplyConfig.ClearScreen();
									if(AnswerUnit == 'y')
									{
										Player.Demons = Player.Demons + 1;
										Player.Ressources = Player.Ressources - 10;
									}
								}
								break;
							}						
						} while(AnswerBuildU != 4);
						break;
					case 3: //Build Defenses
						do
						{
							DisplayMaps.MainMap(Domed.Ownership, Tane.Ownership, Joha.Ownership, Odori.Ownership, Antemie.Ownership);
							DisplayMenus.BuildDefenses();
							cin >> AnswerDefense;
							//Checks if the user has entered a correct input
							AnswerAttack = Check.Menu6(AnswerDefense);
							ApplyConfig.ClearScreen();
							switch(AnswerDefense)
								{
								case 1: //Domed
									if(Domed.Ownership != 1)
									{
										Check.NotOwnedCountry();
									}
									else
									{
										Domed.Defense = TurnChoice.BuildDefenses(Domed.Defense, Player.Ressources);
									}
									ApplyConfig.ClearScreen();
									break;
								case 2: //Tane
									if(Tane.Ownership != 1)
									{
										Check.NotOwnedCountry();
									}
									else
									{
										Tane.Defense = TurnChoice.BuildDefenses(Domed.Defense, Player.Ressources);
									}
									ApplyConfig.ClearScreen();
									break;
								case 3: //Joha
									if(Joha.Ownership != 1)
									{
										Check.NotOwnedCountry();
									}
									else
									{
										Joha.Defense = TurnChoice.BuildDefenses(Domed.Defense, Player.Ressources);
									}
									ApplyConfig.ClearScreen();
									break;
								case 4: //Odori
									if(Odori.Ownership != 1)
									{
										Check.NotOwnedCountry();
									}
									else
									{
										Odori.Defense = TurnChoice.BuildDefenses(Domed.Defense, Player.Ressources);
									}
									ApplyConfig.ClearScreen();
									break;
								case 5: //Antemie
									if(Antemie.Ownership != 1)
									{
										Check.NotOwnedCountry();
									}
									else
									{
										Antemie.Defense = TurnChoice.BuildDefenses(Domed.Defense, Player.Ressources);
									}
									ApplyConfig.ClearScreen();
									break;
								}
						} while(AnswerDefense != 6);
						break;				
					case 4: //Station Troops
						do
						{
							DisplayMaps.MainMap(Domed.Ownership, Tane.Ownership, Joha.Ownership, Odori.Ownership, Antemie.Ownership);
							DisplayMenus.Troops();
							cin >> AnswerTroops;
							//Checks if the user has entered a correct input
							AnswerTroops = Check.Menu6(AnswerTroops);
							ApplyConfig.ClearScreen();
							switch(AnswerTroops)
							{
							case 1: //Domed
								if(Domed.Ownership != 1)
								{
									Check.NotOwnedCountry();
								}
								else
								{
									TurnChoice.StationTroops(Player.Knights, Player.Wizards, Player.Demons, Domed.Knights, Domed.Wizards, Domed.Demons);
								}
								ApplyConfig.ClearScreen();
								break;
							case 2: //Tane
								if(Tane.Ownership != 1)
								{
									Check.NotOwnedCountry();
								}
								else
								{
									TurnChoice.StationTroops(Player.Knights, Player.Wizards, Player.Demons, Tane.Knights, Tane.Wizards, Tane.Demons);
								}
								ApplyConfig.ClearScreen();
								break;
							case 3: //Joha
								if(Joha.Ownership != 1)
								{
									Check.NotOwnedCountry();
								}
								else
								{
									TurnChoice.StationTroops(Player.Knights, Player.Wizards, Player.Demons, Joha.Knights, Joha.Wizards, Joha.Demons);
								}
								ApplyConfig.ClearScreen();
								break;
							case 4: //Odori
								if(Odori.Ownership != 1)
								{
									Check.NotOwnedCountry();
								}
								else
								{
									TurnChoice.StationTroops(Player.Knights, Player.Wizards, Player.Demons, Odori.Knights, Odori.Wizards, Odori.Demons);
								}
								ApplyConfig.ClearScreen();
								break;
							case 5: //Antemie
								if(Antemie.Ownership != 1)
								{
									Check.NotOwnedCountry();
								}
								else
								{
									TurnChoice.StationTroops(Player.Knights, Player.Wizards, Player.Demons, Antemie.Knights, Antemie.Wizards, Antemie.Demons);
								}
								ApplyConfig.ClearScreen();
								break;
							}
						} while(AnswerTroops != 6);
						break;
					case 5: //Attack
						do
						{
							DisplayMaps.MainMap(Domed.Ownership, Tane.Ownership, Joha.Ownership, Odori.Ownership, Antemie.Ownership);
							DisplayMenus.Attack();
							cin >> AnswerAttack;
							//Checks if the user has entered a correct input
							AnswerAttack = Check.Menu5(AnswerAttack);
							ApplyConfig.ClearScreen();
							switch(AnswerAttack)
							{
							case 1: //Domed
								if(Domed.Ownership == 1)
								{
									Check.OwnedCountry();
								}
								else
								{
									Domed.Ownership = TurnChoice.Attack(Domed, Player.Knights, Player.Wizards, Player.Demons);
									Ended = true;
								}
								ApplyConfig.ClearScreen();
								break;
							case 2: //Tane
								if(Tane.Ownership == 1)
								{
									Check.OwnedCountry();
								}
								else
								{
									Tane.Ownership = TurnChoice.Attack(Tane, Player.Knights, Player.Wizards, Player.Demons);
									Ended = true;
								}
								ApplyConfig.ClearScreen();
								break;
							case 3: //Joha
								if(Joha.Ownership == 1)
								{
									Check.OwnedCountry();
								}
								else
								{
									Joha.Ownership = TurnChoice.Attack(Joha, Player.Knights, Player.Wizards, Player.Demons);
									Ended = true;
								}
								ApplyConfig.ClearScreen();
								break;
							case 4: //Odori
								if(Odori.Ownership == 1)
								{
									Check.OwnedCountry();
								}
								else
								{
									Odori.Ownership = TurnChoice.Attack(Odori, Player.Knights, Player.Wizards, Player.Demons);
									Ended = true;
								}
								ApplyConfig.ClearScreen();
								break;
							case 5: //Antemie
								if(Antemie.Ownership == 1)
								{
									Check.OwnedCountry();
								}
								else
								{
									Antemie.Ownership = TurnChoice.Attack(Antemie, Player.Knights, Player.Wizards, Player.Demons);
									Ended = true;
								}
								ApplyConfig.ClearScreen();
								break;
							}
						} while(Ended == false);					
						break;
					case 6: //Exit
						Ended = true;
						break;
					}				
				} while(Ended == false);
				Ended = false;
				ApplyConfig.ClearScreen();
				//Adding the ressources to the player
				if(Domed.Ownership == 1) {
					Player.Ressources = Player.Ressources + Domed.Ressources; }
				if(Tane.Ownership == 1) {
					Player.Ressources = Player.Ressources + Tane.Ressources; }
				if(Joha.Ownership == 1) {
					Player.Ressources = Player.Ressources + Joha.Ressources; }
				if(Odori.Ownership == 1) {
					Player.Ressources = Player.Ressources + Odori.Ressources; }
				if(Antemie.Ownership == 1) {
					Player.Ressources = Player.Ressources + Antemie.Ressources; }

				//Artheon's turn
				TurnChoice.ArtheonTurn(Artheon, Domed, Tane, Joha, Odori, Antemie);

				cin.ignore();
				cout << endl << " Press ENTER to continue.\n";
				cin.get();
				
				//Checks if Artheon or the player owns every continents
				//Checks if Artheon owns all the continents
				if(Domed.Ownership == 2 && Tane.Ownership == 2 && Joha.Ownership == 2 && Odori.Ownership == 2 && Antemie.Ownership == 2)
				{					
					cout << "\n"
							" Artheon has defeated you, he conquered Ameria!\n"
							" Press ENTER to return to the main menu.\n";
					GameOver = true;
				}
				//Checks if player owns all the continents
				else if(Domed.Ownership == 1 && Tane.Ownership == 1 && Joha.Ownership == 1 && Odori.Ownership == 1 && Antemie.Ownership == 1)
				{
					cout << "\n"
							" Congratulation you conquered Ameria!\n"
							" Press ENTER to return to the main menu.\n";
					GameOver = true;
				}				
			} while(GameOver == false);

			//Writing infos for High Score
			fout.open("highscores.txt", ios::out | ios::app);
			if(fout.is_open()) {
				fout << "\n" << Player.Name << "," << Player.Ressources << "," << Player.Knights << "," << Player.Wizards << "," << Player.Demons << ",";	}
			else
			{
				cout << "\n"
						" Unable to open the the file containing the High Scores.";
			}
			fout.close();

			cin.ignore();
			cin.get();
			ApplyConfig.ClearScreen();
			break;
		case 2: //High scores
			fin.open("highscores.txt");
			if(fin.is_open()) 
			{
				cout << "                                                                         \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
						"                                                                         \xBA HIGH SCORES \xBA\n"
						"                                                                         \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
						"\n"
						"                                                         Ressources and Units left at the end of the game\n"
						" Player Name                     Ressources                        Knights                           Wizards                           Demons\n"
						" \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n";
				while (fin.good())
				{
					while(getline(fin, endline))
					{
						for(x = 0; x < 5; x++)
						{
							getline(fin, line[x], ',');
						}
						cout << " " << line[0] << setw(35 - line[0].size()) << line[1] << setw(35 - line[1].size()) << line[2] << setw(35 - line[2].size()) << line[3] << setw(35 - line[3].size()) << line[4] << endl;
					}
				}				
			}
			else
			{
				cout << "\n"
						" Unable to open the the file containing the High Scores.";
			}
			fin.close();

			cin.ignore();
			cout << endl << " Press ENTER to return to the main menu.\n";
			cin.get();
			ApplyConfig.ClearScreen();
			break;
		}
	} while(Answer != 3);
}