#include "turn.h"

int RanNumGen(int Num);

int Turn::Attack(Countries &Country, int &Knights, int &Wizards, int &Demons)
{
	Turn TurnChoice;
	int RandomNumber;
	int Army;

	Army = Knights + (Wizards * 5) + (Demons * 10);

	if(Country.Ownership == 0)
	{
		cout << " You conquered this land!\n"
				" You can now choose to station troops here,\n";		
		TurnChoice.StationTroops(Knights, Wizards, Demons, Country.Knights, Country.Wizards, Country.Demons);
		return 1;
	}
	else
	{
		if(Army > (Country.Defense + Country.Knights + (Country.Wizards * 5) + (Country.Demons * 10)))
		{
			//Setting the Counrty's defenses and troops to zero
			Country.Defense = 0;
			Country.Knights = 0;
			Country.Wizards = 0;
			Country.Demons = 0;
			cout << " You win, this land is now yours!\n"
					" You can now choose to station troops here,\n";
			StationTroops(Knights, Wizards, Demons, Country.Knights, Country.Wizards, Country.Demons);			
			return 1;
		}
		else
		{
			Knights = (Knights / 2);
			Wizards = (Wizards / 2);
			Demons = (Demons / 2);
			cout << " You lose.\n"
					" Half of your army as been killed, you now have " << Knights << " knights, " << Wizards << " wizards and " << Demons << " demons.\n";
			cin.ignore();
			cout << " Press ENTER to return to the map.";
			cin.get();
			return 2;
		}
	}
}

int Turn::BuildDefenses(int Defense, int &Ressources)
{
	//Calling the classes
	ErrorHandling Check;
	//Declaring the variables
	int Answer;

	cout << "\n"
			" You have " << Ressources << " ressource(s)\n"
			" This country has " << Defense << " defense point(s)\n"
			"\n"
			" you need 10 ressources to add one point to the defense of this country."
			"\n"
			" How many points do you want to add to this country > ";
	cin >> Answer;
	//Checks if the user has entered a correct input
	Answer = Check.MenuInt(Answer);
	while(Answer > (Ressources / 10))
	{
		cout << "\n You do not have enough ressources to add this many points.\n"
				" How many points do you want to add to this country > ";
		cin >> Answer;
		//Checks if the user has entered a correct input
		Answer = Check.MenuInt(Answer);		
	}

	Defense = Defense + Answer;
	Ressources = Ressources - (Answer * 10);

	return Defense;
}

void Turn::StationTroops(int &PlayerKnights, int &PlayerWizards, int &PlayerDemons, int &CountryKnights, int &CountryWizards, int &CountryDemons)
{
	ErrorHandling Check;
	Config ApplyConfig;

	int Answer;
	int AnswerKnights;
	int AnswerWizards;
	int AnswerDemons;
	int CountKnights;
	int CountWizards;
	int CountDemons;

	do
	{
		cout << "\n"
				"                                                                          \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
				"                                                                          \xBA   1) Knight    \xBA\n"
				"                                                                          \xBA   2) Wizard    \xBA\n"
				"                                                                          \xBA   3) Demon     \xBA\n"
				"                                                                          \xBA   4) Exit      \xBA\n"
				"                                                                          \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
				" This Country has " << CountryKnights << " knights, " << CountryWizards << " wizards and " << CountryDemons << " demons stationed.\n"
				" You have " << PlayerKnights << " knights, " << PlayerWizards << " wizards and " << PlayerDemons << " demons."
				"\n"
				" Which unit do you want to manage? > ";
		cin >> Answer;
		//Checks if the user has entered a correct input
		Answer = Check.Menu4(Answer);
		ApplyConfig.ClearScreen();
		switch(Answer)
		{
		case 1:
			cout << "\n"
					"                                                                          \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
					"                                                                          \xBA 1) Retrieve Knights \xBA\n"
					"                                                                          \xBA 2) Station Knights  \xBA\n"
					"                                                                          \xBA 3) Exit             \xBA\n"
					"                                                                          \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
					" You have " << PlayerKnights << " knights.\n"
					" There is " << CountryKnights << " knights stationed here.\n"
					" What do you want to do? > ";
			cin >> AnswerKnights;
			//Checks if the user has entered a correct input
			AnswerKnights = Check.Menu3(AnswerKnights);
			switch(AnswerKnights)
			{
			case 1:
				if(CountryKnights < 1)
				{
					ApplyConfig.ClearScreen();
					cout << " There is no knights stationed here, choose another unit.\n";
					cin.ignore();
					cout << " Press ENTER to return to the unit selection menu.";
					cin.get();
				}
				else
				{
					cout << "\n"
							" How many knights do you want to retrieve? > ";
					cin >> CountKnights;
					//Checks if the user has entered a correct input
					CountKnights = Check.MenuInt(CountKnights);
					while(CountKnights > CountryKnights)
					{
						cout << " You cannot retrieve more knights than there is stationed.\n"
								" How many knights do you want to retrieve? > ";
						cin >> CountKnights;
						//Checks if the user has entered a correct input
						CountKnights = Check.MenuInt(CountKnights);
					}
					CountryKnights = CountryKnights - CountKnights;
					PlayerKnights = PlayerKnights + CountKnights;
				}
				ApplyConfig.ClearScreen();
				break;
			case 2:
				if(PlayerKnights < 1)
				{
					ApplyConfig.ClearScreen();
					cout << " Youd do not have any knights, choose another unit.\n";
					cin.ignore();
					cout << " Press ENTER to return to the unit selection menu.";
					cin.get();
				}
				else
				{
					cout << "\n"
							" How many knights do you want to station? > ";
					cin >> CountKnights;
					//Checks if the user has entered a correct input
					CountKnights = Check.MenuInt(CountKnights);
					while(CountKnights > PlayerKnights)
					{
						cout << " You cannot station more knights than you have.\n"
								" How many knights do you want to station? > ";
						cin >> CountKnights;
						//Checks if the user has entered a correct input
						CountKnights = Check.MenuInt(CountKnights);
					}
					CountryKnights = CountryKnights + CountKnights;
					PlayerKnights = PlayerKnights - CountKnights;
				}
				ApplyConfig.ClearScreen();
				break;
			}
			break;
		case 2:
			cout << "\n"
					"                                                                          \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
					"                                                                          \xBA 1) Retrieve Wizards \xBA\n"
					"                                                                          \xBA 2) Station Wizards  \xBA\n"
					"                                                                          \xBA 3) Exit             \xBA\n"
					"                                                                          \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
					" You have " << PlayerWizards << " wizards.\n"
					" There is " << CountryWizards << " wizards stationed here.\n"
					" What do you want to do? > ";
			cin >> AnswerWizards;
			//Checks if the user has entered a correct input
			AnswerWizards = Check.Menu3(AnswerWizards);
			switch(AnswerWizards)
			{
			case 1:
				if(CountryWizards < 1)
				{
					ApplyConfig.ClearScreen();
					cout << " There is no wizards stationed here, choose another unit.\n";
					cin.ignore();
					cout << " Press ENTER to return to the unit selection menu.";
					cin.get();
				}
				else
				{
					cout << "\n"
							" How many wizards do you want to retrieve? > ";
					cin >> CountWizards;
					//Checks if the user has entered a correct input
					CountWizards = Check.MenuInt(CountWizards);
					while(CountWizards > CountryWizards)
					{
						cout << " You cannot retrieve more wizards than there is stationed.\n"
								" How many wizards do you want to retrieve? > ";
						cin >> CountWizards;
						//Checks if the user has entered a correct input
						CountWizards = Check.MenuInt(CountWizards);
					}
					CountryWizards = CountryWizards - CountWizards;
					PlayerWizards = PlayerWizards + CountWizards;
				}
				ApplyConfig.ClearScreen();
				break;
			case 2:
				if(PlayerWizards < 1)
				{
					ApplyConfig.ClearScreen();
					cout << " Youd do not have any wizards, choose another unit.\n";
					cin.ignore();
					cout << " Press ENTER to return to the unit selection menu.";
					cin.get();
				}
				else
				{
					cout << "\n"
							" How many wizards do you want to station? > ";
					cin >> CountWizards;
					//Checks if the user has entered a correct input
					CountWizards = Check.MenuInt(CountWizards);
					while(CountWizards > PlayerWizards)
					{
						cout << " You cannot station more wizards than you have.\n"
								" How many wizards do you want to station? > ";
						cin >> CountWizards;
						//Checks if the user has entered a correct input
						CountKnights = Check.MenuInt(CountKnights);
					}
					CountryWizards = CountryWizards + CountWizards;
					PlayerWizards = PlayerWizards - CountWizards;
				}
				ApplyConfig.ClearScreen();
				break;
			}
			break;
		case 3:
			cout << "\n"
					"                                                                          \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
					"                                                                          \xBA 1) Retrieve Demons \xBA\n"
					"                                                                          \xBA 2) Station Demons  \xBA\n"
					"                                                                          \xBA 3) Exit            \xBA\n"
					"                                                                          \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
					" You have " << PlayerDemons << " demons.\n"
					" There is " << CountryDemons << " demons stationed here.\n"
					" What do you want to do? > ";
			cin >> AnswerDemons;
			//Checks if the user has entered a correct input
			AnswerDemons = Check.Menu3(AnswerDemons);
			switch(AnswerDemons)
			{
			case 1:
				if(CountryDemons < 1)
				{
					ApplyConfig.ClearScreen();
					cout << " There is no demons stationed here, choose another unit.\n";
					cin.ignore();
					cout << " Press ENTER to return to the unit selection menu.";
					cin.get();
				}
				else
				{
					cout << "\n"
							" How many demons do you want to retrieve? > ";
					cin >> CountDemons;
					//Checks if the user has entered a correct input
					CountDemons = Check.MenuInt(CountDemons);
					while(CountDemons > CountryDemons)
					{
						cout << " You cannot retrieve more demons than there is stationed.\n"
								" How many demons do you want to retrieve? > ";
						cin >> CountDemons;
						//Checks if the user has entered a correct input
						CountDemons = Check.MenuInt(CountDemons);
					}
					CountryDemons = CountryDemons - CountDemons;
					PlayerDemons = PlayerDemons + CountDemons;
				}
				ApplyConfig.ClearScreen();
				break;
			case 2:
				if(PlayerDemons < 1)
				{
					ApplyConfig.ClearScreen();
					cout << " Youd do not have any demons, choose another unit.\n";
					cin.ignore();
					cout << " Press ENTER to return to the unit selection menu.";
					cin.get();
				}
				else
				{
					cout << "\n"
							" How many demons do you want to station? > ";
					cin >> CountDemons;
					//Checks if the user has entered a correct input
					CountDemons = Check.MenuInt(CountDemons);
					while(CountDemons > PlayerDemons)
					{
						cout << " You cannot station more demons than you have.\n"
								" How many demons do you want to station? > ";
						cin >> CountDemons;
						//Checks if the user has entered a correct input
						CountDemons = Check.MenuInt(CountDemons);
					}
					CountryDemons = CountryDemons + CountDemons;
					PlayerDemons = PlayerDemons - CountDemons;
				}
				ApplyConfig.ClearScreen();
				break;
			}
			break;
		}
	} while(Answer != 4);
}

void Turn::ArtheonTurn(Players &Artheon, Countries &Domed, Countries &Tane, Countries &Joha, Countries &Odori, Countries &Antemie)
{
	//Declaring the variables
	bool Ended = false;
	int ArtheonArmy;
	int Land = 0;
	int HalfKnights;
	int HalfWizards;
	int HalfDemons;
	int SplitRessources;
	int SplitKnights;
	int SplitWizards;
	int SplitDemons;
	bool ArtheonDomed = false;
	bool ArtheonTane = false;
	bool ArtheonJoha = false;
	bool ArtheonOdori = false;
	bool ArtheonAntemie = false;	
	int RandomNumber;

	//Artheon Recruit Troops
	if(Artheon.Ressources > 0) {
		ArtheonTroops(Artheon.Ressources, Artheon.Knights, Artheon.Wizards, Artheon.Demons); }

	//Split in half Artheon's units for stationing on countries
	HalfKnights = Artheon.Knights / 2;
	HalfWizards = Artheon.Wizards / 2;
	HalfDemons = Artheon.Demons / 2;

	//Build defenses and station troops
	if(Artheon.Ressources > 0)
	{
		//Checking how many lands Artheon owns
		if(Domed.Ownership == 2)
		{
			Land = Land + 1;
			ArtheonDomed = true;
		}
		if(Tane.Ownership == 2)
		{
			Land = Land + 1;
			ArtheonTane = true;
		}
		if(Joha.Ownership == 2)
		{
			Land = Land + 1;
			ArtheonJoha = true;
		}
		if(Odori.Ownership == 2)
		{
			Land = Land + 1;
			ArtheonOdori = true;
		}
		if(Antemie.Ownership == 2)
		{
			Land = Land + 1;
			ArtheonAntemie = true;
		}
		//Building Defenses and station troops
		switch(Land)
		{
		case 1:
			//Add defenses and units
			if(Artheon.Ressources >= 30)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 3;
					Domed.Knights = Domed.Knights + HalfKnights;
					Domed.Wizards = Domed.Wizards + HalfWizards;
					Domed.Demons = Domed.Demons + HalfDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 3;
					Tane.Knights = Tane.Knights + HalfKnights;
					Tane.Wizards = Tane.Wizards + HalfWizards;
					Tane.Demons = Tane.Demons + HalfDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 3;
					Joha.Knights = Joha.Knights + HalfKnights;
					Joha.Wizards = Joha.Wizards + HalfWizards;
					Joha.Demons = Joha.Demons + HalfDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 3;
					Odori.Knights = Odori.Knights + HalfKnights;
					Odori.Wizards = Odori.Wizards + HalfWizards;
					Odori.Demons = Odori.Demons + HalfDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 3;
					Antemie.Knights = Antemie.Knights + HalfKnights;
					Antemie.Wizards = Antemie.Wizards + HalfWizards;
					Antemie.Demons = Antemie.Demons + HalfDemons;
				}

				//Take from Artheon the ressources and units he used
				Artheon.Ressources = Artheon.Ressources - 30;
				Artheon.Knights = Artheon.Knights - HalfKnights;
				Artheon.Wizards = Artheon.Wizards - HalfWizards;
				Artheon.Demons = Artheon.Demons - HalfDemons;
			}
			else if(Artheon.Ressources >= 20 && Artheon.Ressources < 30)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 2;
					Domed.Knights = Domed.Knights + HalfKnights;
					Domed.Wizards = Domed.Wizards + HalfWizards;
					Domed.Demons = Domed.Demons + HalfDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 2;
					Tane.Knights = Tane.Knights + HalfKnights;
					Tane.Wizards = Tane.Wizards + HalfWizards;
					Tane.Demons = Tane.Demons + HalfDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 2;
					Joha.Knights = Joha.Knights + HalfKnights;
					Joha.Wizards = Joha.Wizards + HalfWizards;
					Joha.Demons = Joha.Demons + HalfDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 2;
					Odori.Knights = Odori.Knights + HalfKnights;
					Odori.Wizards = Odori.Wizards + HalfWizards;
					Odori.Demons = Odori.Demons + HalfDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 2;
					Antemie.Knights = Antemie.Knights + HalfKnights;
					Antemie.Wizards = Antemie.Wizards + HalfWizards;
					Antemie.Demons = Antemie.Demons + HalfDemons;
				}

				//Take from Artheon the ressources and units he used
				Artheon.Ressources = Artheon.Ressources - 20;
				Artheon.Knights = Artheon.Knights - HalfKnights;
				Artheon.Wizards = Artheon.Wizards - HalfWizards;
				Artheon.Demons = Artheon.Demons - HalfDemons;
			}
			else if(Artheon.Ressources >= 10 && Artheon.Ressources < 20)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 1;
					Domed.Knights = Domed.Knights + HalfKnights;
					Domed.Wizards = Domed.Wizards + HalfWizards;
					Domed.Demons = Domed.Demons + HalfDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 1;
					Tane.Knights = Tane.Knights + HalfKnights;
					Tane.Wizards = Tane.Wizards + HalfWizards;
					Tane.Demons = Tane.Demons + HalfDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 1;
					Joha.Knights = Joha.Knights + HalfKnights;
					Joha.Wizards = Joha.Wizards + HalfWizards;
					Joha.Demons = Joha.Demons + HalfDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 1;
					Odori.Knights = Odori.Knights + HalfKnights;
					Odori.Wizards = Odori.Wizards + HalfWizards;
					Odori.Demons = Odori.Demons + HalfDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 1;
					Antemie.Knights = Antemie.Knights + HalfKnights;
					Antemie.Wizards = Antemie.Wizards + HalfWizards;
					Antemie.Demons = Antemie.Demons + HalfDemons;
				}

				//Take from Artheon the ressources and units he used
				Artheon.Ressources = Artheon.Ressources - 10;
				Artheon.Knights = Artheon.Knights - HalfKnights;
				Artheon.Wizards = Artheon.Wizards - HalfWizards;
				Artheon.Demons = Artheon.Demons - HalfDemons;
			}
			break;
		case 2:
			//Split Artheon's ressources and units to build defenses
			SplitRessources = Artheon.Ressources / 2;
			SplitKnights = HalfKnights / 2;
			SplitWizards = HalfWizards / 2;
			SplitDemons = HalfDemons / 2;

			//Add defenses and units
			if(SplitRessources >= 30)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 3;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 3;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 3;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 3;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 3;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 60;
			}
			else if(SplitRessources >= 20 && SplitRessources < 30)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 2;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 2;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 2;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 2;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 2;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 40;
			}
			else if(SplitRessources >= 10 && SplitRessources < 20)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 1;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 1;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 1;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 1;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 1;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 20;				
			}
			//Take from Artheon the units he used
			Artheon.Knights = Artheon.Knights - HalfKnights;
			Artheon.Wizards = Artheon.Wizards - HalfWizards;
			Artheon.Demons = Artheon.Demons - HalfDemons;
			break;
		case 3:
			//Split Artheon's ressources to build defenses
			SplitRessources = Artheon.Ressources / 3;
			SplitKnights = HalfKnights / 2;
			SplitWizards = HalfWizards / 2;
			SplitDemons = HalfDemons / 2;

			//Add defenses and units
			if(SplitRessources >= 30)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 3;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 3;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 3;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 3;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 3;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 90;
			}
			else if(SplitRessources >= 20 && SplitRessources < 30)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 2;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 2;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 2;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 2;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 2;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 60;
			}
			else if(SplitRessources >= 10 && SplitRessources < 20)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 1;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 1;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 1;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 1;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 1;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 30;
			}
			//Take from Artheon the units he used
			Artheon.Knights = Artheon.Knights - HalfKnights;
			Artheon.Wizards = Artheon.Wizards - HalfWizards;
			Artheon.Demons = Artheon.Demons - HalfDemons;
			break;
		case 4:
			//Split Artheon's ressources to build defenses
			SplitRessources = Artheon.Ressources / 4;
			//Add defenses and units
			if(SplitRessources >= 30)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 3;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 3;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 3;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 3;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 3;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 120;
			}
			else if(SplitRessources >= 20 && SplitRessources < 30)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 2;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 2;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 2;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 2;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 2;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 80;
			}
			else if(SplitRessources >= 10 && SplitRessources < 20)
			{
				if(ArtheonDomed == true)
				{
					Domed.Defense = Domed.Defense + 1;
					Domed.Knights = Domed.Knights + SplitKnights;
					Domed.Wizards = Domed.Wizards + SplitWizards;
					Domed.Demons = Domed.Demons + SplitDemons;
				}
				if(ArtheonTane == true)
				{
					Tane.Defense = Tane.Defense + 1;
					Tane.Knights = Tane.Knights + SplitKnights;
					Tane.Wizards = Tane.Wizards + SplitWizards;
					Tane.Demons = Tane.Demons + SplitDemons;
				}
				if(ArtheonJoha == true)
				{
					Joha.Defense = Joha.Defense + 1;
					Joha.Knights = Joha.Knights + SplitKnights;
					Joha.Wizards = Joha.Wizards + SplitWizards;
					Joha.Demons = Joha.Demons + SplitDemons;
				}
				if(ArtheonOdori == true)
				{
					Odori.Defense = Odori.Defense + 1;
					Odori.Knights = Odori.Knights + SplitKnights;
					Odori.Wizards = Odori.Wizards + SplitWizards;
					Odori.Demons = Odori.Demons + SplitDemons;
				}
				if(ArtheonAntemie == true)
				{
					Antemie.Defense = Antemie.Defense + 1;
					Antemie.Knights = Antemie.Knights + SplitKnights;
					Antemie.Wizards = Antemie.Wizards + SplitWizards;
					Antemie.Demons = Antemie.Demons + SplitDemons;
				}

				//Take from Artheon the ressources he used
				Artheon.Ressources = Artheon.Ressources - 40;
			}
			//Take from Artheon the units he used
			Artheon.Knights = Artheon.Knights - HalfKnights;
			Artheon.Wizards = Artheon.Wizards - HalfWizards;
			Artheon.Demons = Artheon.Demons - HalfDemons;
			break;
		}
	}

	do
	{
		//Choosing a Country to attack
		RandomNumber = RanNumGen(5);
		ArtheonArmy = Artheon.Knights + (Artheon.Wizards * 5) + (Artheon.Demons * 10);
		switch(RandomNumber)
		{
		case 1: //Domed
			if(Domed.Ownership != 2)
			{
				if(ArtheonArmy > (Domed.Defense + Domed.Knights + (Domed.Wizards * 5) + (Domed.Demons * 10)))
				{
					//Setting the Counrty's defenses and troops to zero
					Domed.Defense = 0;
					Domed.Knights = 0;
					Domed.Wizards = 0;
					Domed.Demons = 0;

					Domed.Ownership = 2;
					cout << " Artheon conquered Domed!";

					//Station Troops
					Domed.Knights = Domed.Knights + HalfKnights;
					Domed.Wizards = Domed.Wizards + HalfWizards;
					Domed.Demons = Domed.Demons + HalfDemons;
					//Take from Artheon the units he used
					Artheon.Knights = Artheon.Knights - HalfKnights;
					Artheon.Wizards = Artheon.Wizards - HalfWizards;
					Artheon.Demons = Artheon.Demons - HalfDemons;
				}
				else
				{
					Artheon.Knights = (Artheon.Knights / 2);
					Artheon.Wizards = (Artheon.Wizards / 2);
					Artheon.Demons = (Artheon.Demons / 2);

					cout << " Artheon tried to conquer Domed but he failed!";
				}
				Ended = true;
			}
			break;
		case 2: //Tane
			if(Tane.Ownership != 2)
			{
				if(ArtheonArmy > (Tane.Defense + Tane.Knights + (Tane.Wizards * 5) + (Tane.Demons * 10)))
				{
					//Setting the Counrty's defenses and troops to zero
					Tane.Defense = 0;
					Tane.Knights = 0;
					Tane.Wizards = 0;
					Tane.Demons = 0;

					Tane.Ownership = 2;
					cout << " Artheon conquered Tane!";

					//Station Troops
					Tane.Knights = Tane.Knights + HalfKnights;
					Tane.Wizards = Tane.Wizards + HalfWizards;
					Tane.Demons = Tane.Demons + HalfDemons;
					//Take from Artheon the units he used
					Artheon.Knights = Artheon.Knights - HalfKnights;
					Artheon.Wizards = Artheon.Wizards - HalfWizards;
					Artheon.Demons = Artheon.Demons - HalfDemons;
				}
				else
				{
					Artheon.Knights = (Artheon.Knights / 2);
					Artheon.Wizards = (Artheon.Wizards / 2);
					Artheon.Demons = (Artheon.Demons / 2);

					cout << " Artheon tried to conquer Tane but he failed!";
				}
				Ended = true;
			}
			break;
		case 3: //Joha
			if(Joha.Ownership != 2)
			{
				if(ArtheonArmy > (Joha.Defense + Joha.Knights + (Joha.Wizards * 5) + (Joha.Demons * 10)))
				{
					//Setting the Counrty's defenses and troops to zero
					Joha.Defense = 0;
					Joha.Knights = 0;
					Joha.Wizards = 0;
					Joha.Demons = 0;

					Joha.Ownership = 2;
					cout << " Artheon conquered Joha!";

					//Station Troops
					Joha.Knights = Joha.Knights + HalfKnights;
					Joha.Wizards = Joha.Wizards + HalfWizards;
					Joha.Demons = Joha.Demons + HalfDemons;
					//Take from Artheon the units he used
					Artheon.Knights = Artheon.Knights - HalfKnights;
					Artheon.Wizards = Artheon.Wizards - HalfWizards;
					Artheon.Demons = Artheon.Demons - HalfDemons;
				}
				else
				{
					Artheon.Knights = (Artheon.Knights / 2);
					Artheon.Wizards = (Artheon.Wizards / 2);
					Artheon.Demons = (Artheon.Demons / 2);

					cout << " Artheon tried to conquer Joha but he failed!";
				}
				Ended = true;
			}
			break;
		case 4: //Odori
			if(Odori.Ownership != 2)
			{
				if(ArtheonArmy > (Odori.Defense + Odori.Knights + (Odori.Wizards * 5) + (Odori.Demons * 10)))
				{
					//Setting the Counrty's defenses and troops to zero
					Odori.Defense = 0;
					Odori.Knights = 0;
					Odori.Wizards = 0;
					Odori.Demons = 0;

					Odori.Ownership = 2;
					cout << " Artheon conquered Odori!";

					//Station Troops
					Odori.Knights = Odori.Knights + HalfKnights;
					Odori.Wizards = Odori.Wizards + HalfWizards;
					Odori.Demons = Odori.Demons + HalfDemons;
					//Take from Artheon the units he used
					Artheon.Knights = Artheon.Knights - HalfKnights;
					Artheon.Wizards = Artheon.Wizards - HalfWizards;
					Artheon.Demons = Artheon.Demons - HalfDemons;
				}
				else
				{
					Artheon.Knights = (Artheon.Knights / 2);
					Artheon.Wizards = (Artheon.Wizards / 2);
					Artheon.Demons = (Artheon.Demons / 2);

					cout << " Artheon tried to conquer Odori but he failed!";
				}
				Ended = true;
			}
			break;
		case 5: //Antemie
			if(Antemie.Ownership != 2)
			{
				if(ArtheonArmy > (Antemie.Defense + Antemie.Knights + (Antemie.Wizards * 5) + (Antemie.Demons * 10)))
				{
					//Setting the Counrty's defenses and troops to zero
					Antemie.Defense = 0;
					Antemie.Knights = 0;
					Antemie.Wizards = 0;
					Antemie.Demons = 0;

					Antemie.Ownership = 2;
					cout << " Artheon conquered Antemie!";

					//Station Troops
					Antemie.Knights = Antemie.Knights + HalfKnights;
					Antemie.Wizards = Antemie.Wizards + HalfWizards;
					Antemie.Demons = Antemie.Demons + HalfDemons;
					//Take from Artheon the units he used
					Artheon.Knights = Artheon.Knights - HalfKnights;
					Artheon.Wizards = Artheon.Wizards - HalfWizards;
					Artheon.Demons = Artheon.Demons - HalfDemons;
				}
				else
				{
					Artheon.Knights = (Artheon.Knights / 2);
					Artheon.Wizards = (Artheon.Wizards / 2);
					Artheon.Demons = (Artheon.Demons / 2);

					cout << " Artheon tried to conquer Antemie but he failed!";
				}
				Ended = true;
			}
			break;
		}
	} while(Ended == false);
	Ended = false;

	//Adding the ressources to Artheon
	if(Domed.Ownership == 2) {
		Artheon.Ressources = Artheon.Ressources + Domed.Ressources; }
	if(Tane.Ownership == 2) {
		Artheon.Ressources = Artheon.Ressources + Tane.Ressources; }
	if(Joha.Ownership == 2) {
		Artheon.Ressources = Artheon.Ressources + Joha.Ressources; }
	if(Odori.Ownership == 2) {
		Artheon.Ressources = Artheon.Ressources + Odori.Ressources; }
	if(Antemie.Ownership == 2) {
		Artheon.Ressources = Artheon.Ressources + Antemie.Ressources; }
}

void Turn::ArtheonTroops(int &ARessources, int &AKnights, int &AWizards, int &ADemons)
{
	const int Knights = 1;
	const int Wizards = 5;
	const int Demons = 10;
	int Total;
	int i;
	int x;
	int y;
	int Count = 0;

	for(i = 1; i <= ARessources; i++)
	{
		for(x = 1; x <= ARessources; x++)
		{
			for(y = 1; y <= ARessources; y++)
			{
				if((Knights * i) + (Wizards * x) + (Demons * y) == ARessources) 
				{
					AKnights = AKnights + i;
					AWizards = AWizards + x;
					ADemons = ADemons + y;
					ARessources = 0;
					break;
				}
			}
		}
	}
}

//Random Number Generator
int RanNumGen(int Num)
{
	srand((unsigned)time(0));
	int random_integer;

	random_integer = 1 + rand()%(Num);

	return random_integer;
}