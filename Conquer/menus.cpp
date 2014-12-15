#include <iostream>
#include "menus.h"

using namespace std;

void Menus::MainMenu()
{
	cout << "\n"
			"                                                                             \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
			"                                                                             \xBA CONQUER \xBA\n"
			"                                                                             \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
			"                                                        Welcome to Conquer, the command line version of RISK."			
			"\n\n\n"
			"                                                                          \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
			"                                                                          \xBA    Main Menu   \xBA\n"
			"                                                                          \xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n"
			"                                                                          \xBA 1) Play        \xBA\n"
			"                                                                          \xBA 2) High Scores \xBA\n"
			"                                                                          \xBA 3) Exit        \xBA\n"
			"                                                                          \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
			" Enter your selection > ";
}

void Menus::Start()
{
	cout << "\n"
			" Welcome to CONQUER, the command line version of RISK.\n"
			" In this version of RISK you are in a fantasy world called Ameria, this world has five continents and your aim is to rule them all.\n"
			" But it won't be easy, you are not the only one, Artheon also wants to be the ruler of Ameria.\n"
			" You will be able to recruit Knights, Wizards and even Demons to help you in your quest.\n"
			"\n"
			" During your turn you will have a certain amount of ressources that you can use to recruit units or build defences on the different countries you own, when you\n"
			" are done you can either attack or end your turn, if you choose to attack, at the end of that phase your turn will end so you better use your ressources before\n"
			" attacking!\n"
			"\n"
			" Before starting your journey we need to know your name > ";
}

void Menus::AllocateRessources(int Ressources, int Knights, int Wizards, int Demons)
{
	cout << " You are now going to allocate your ressources,"
			"\n"
			"                                                                          \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
			"                                                                          \xBA Unit Selection \xBA\n"
			"                                                                          \xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n"
			"                                                                          \xBA   1) Knight    \xBA\n"
			"                                                                          \xBA   2) Wizard    \xBA\n"
			"                                                                          \xBA   3) Demon     \xBA\n"
			"                                                                          \xBA   4) Finish    \xBA\n"
			"                                                                          \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
			"\n"
			" You currently have " << Ressources << " ressources, " << Knights << " knights, " << Wizards << " wizards and " << Demons << " demons.\n"
			" Which unit do you want to recruit? > ";
}

void Menus::Turn()
{
	cout << "\n"
			" It's your turn to play, choose an option from the menu\n"
			"                                                                        \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
			"                                                                        \xBA 1) Show Map       \xBA\n"			
			"                                                                        \xBA 2) Recruit Units  \xBA\n"
			"                                                                        \xBA 3) Build Defenses \xBA\n"
			"                                                                        \xBA 4) Manage Troops  \xBA\n"
			"                                                                        \xBA 5) Attack         \xBA\n"
			"                                                                        \xBA 6) End Turn       \xBA\n"
			"                                                                        \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"
			" Enter your selection > ";
}

void Menus::Infos()
{
	cout << " Choose a Country for which you want more info:\n"
			" \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n"
			"     1) Domed                     2) Tane                     3) Joha                     4) Odori                     5) Antemie                    6) Exit\n"
			" Enter your selection > ";
}

void Menus::Attack()
{
	cout << " Choose a Country to attack:\n"
			" \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n"
			"     1) Domed                            2) Tane                            3) Joha                            4) Odori                            5) Antemie\n"
			" Enter your selection > ";
}

void Menus::BuildDefenses()
{
	cout << " Choose a Country on which you want to build defenses:\n"
			" \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n"
			"     1) Domed                     2) Tane                     3) Joha                     4) Odori                     5) Antemie                    6) Exit\n"
			" Enter your selection > ";
}

void Menus::Troops()
{
	cout << " Choose a Country in which you want to manage your troops:\n"
			" \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n"
			"     1) Domed                     2) Tane                     3) Joha                     4) Odori                     5) Antemie                    6) Exit\n"
			" Enter your selection > ";
}

void Menus::UnitSelection(int Ressources, int Knights, int Wizards, int Demons)
{
	cout << "\n"
			"                                                                          \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"
			"                                                                          \xBA Unit Selection \xBA\n"
			"                                                                          \xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n"
			"                                                                          \xBA   1) Knight    \xBA\n"
			"                                                                          \xBA   2) Wizard    \xBA\n"
			"                                                                          \xBA   3) Demon     \xBA\n"
			"                                                                          \xBA   4) Exit      \xBA\n"
			"                                                                          \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n"		
			" You currantly have " << Ressources << " ressources, " << Knights << " knights, " << Wizards << " wizards and " << Demons << " demons.\n"
			" Enter your selection > ";
}

void Menus::Knight(int Ressources)
{
	cout << endl <<
			" ***************************************************************************************************************************************************************\n"
			" *                     {}                                                                                                                                      *\n"
			" *                   .-''-.                                                \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB                                                                          *\n"
			" *                  /  __  \\                                               \xBA Knight \xBA                                                                          *\n"
			" *                 /.-'  '-.\\                                              \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC                                                                          *\n"
			" *                 \\::.  .::/                                                                                                                                  *\n"
			" *                  \\'    '/                                                Attack:  1                                                                         *\n"
			" *             __ ___)    (___ __                                           Defense: 1                                                                         *\n"
			" *           .'   \\\\        //   `.                                         Cost:    1                                                                         *\n"
			" *          /     | '-.__.-' |     \\                                                                                                                           *\n"
			" *          |     |  '::::'  |     |                                                                                                                           *\n"
			" *          |    /    '::'    \\    |                                                                                                                           *\n"
			" *          |_.-;\\     __     /;-._|                                                                                                                           *\n"
			" *          \\.'^`\\\\    \\/    //`^'./                                                                                                                           *\n"
			" *          /   _.-._ _||_ _.-._   \\                                                                                                                           *\n"
			" *         `\\___\\    '-..-'    /___/`                                                                                                                          *\n"
			" *              /'---.  `\\.---'\\                                                                                                                               *\n"
			" *             ||    |`\\\\\\|    ||                                                                                                                              *\n"
			" *             ||    | || |    ||                                                                                                                              *\n"
			" *             |;.__.' || '.__.;|                                                                                                                              *\n"
			" *             |       ||       |                                                                                                                              *\n"
			" *             {{{{{{{{||}}}}}}}}                                                                                                                              *\n"
			" *              |      ||      |                                                                                                                               *\n"
			" *              |.-==-.||.-==-.|                                                                                                                               *\n"
			" *              <.    .||.    .>                                                                                                                               *\n"
			" *               \\'=='/||\\'=='/                                                                                                                                *\n"
			" *               |   / || \\   |                                                                                                                                *\n"
			" *               |   | || |   |                                                                                                                                *\n"
			" *               |   | || |   |                                                                                                                                *\n"
			" *               /^^\\| || |/^^\\                                                                                                                                *\n"
			" *              /   .' || '.   \\                                                                                                                               *\n"
			" *             /   /   ||   \\   \\                                                                                                                              *\n"
			" *            (__.'    \\/    '.__)                                                                                                                             *\n"			
			" ***************************************************************************************************************************************************************\n"
			" you have " << Ressources << " Ressource(s).\n"
			" Do you want to recruit this unit? (\"y\" or \"n\") > ";
}

void Menus::Wizard(int Ressources)
{
	cout << endl <<
			" ***************************************************************************************************************************************************************\n"			
			" *                           ____                                                                                                                              *\n"
			" *                         .'* *.'                                                \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB                                                                   *\n"
			" *                      __/_*_*(_                                                 \xBA Wizard \xBA                                                                   *\n"
			" *                     / _______ \\                                                \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC                                                                   *\n"
			" *                    _\\_)/___\\(_/_                                                                                                                            *\n"
			" *                   / _((\\- -/))_ \\                                               Attack:  5                                                                  *\n"
			" *                   \\ \\())(-)(()/ /                                               Defense: 5                                                                  *\n"
			" *                    ' \\(((()))/ '                                                Cost:    5                                                                  *\n"
			" *                   / ' \\)).))/ ' \\                                                                                                                           *\n"
			" *                  / _ \\ - | - /_  \\                                                                                                                          *\n"
			" *                 (   ( .;''';. .'  )                                                                                                                         *\n"
			" *                 _\\\"__ /    )\\ __\"/_                                                                                                                         *\n"
			" *                   \\/  \\   ' /  \\/                                                                                                                           *\n"
			" *                    .'  '...' ' )                                                                                                                            *\n"
			" *                     / /  |  \\ \\                                                                                                                             *\n"
			" *                    / .   .   . \\                                                                                                                            *\n"
			" *                   /   .     .   \\                                                                                                                           *\n"
			" *                  /   /   |   \\   \\                                                                                                                          *\n"
			" *                .'   /    b    '.  '.                                                                                                                        *\n"
			" *            _.-'    /     Bb     '-. '-._                                                                                                                    *\n"
			" *        _.-'       |      BBb       '-.  '-.                                                                                                                 *\n"
			" *       (________mrf\\____.dBBBb.________)____)                                                                                                                *\n"			
			" ***************************************************************************************************************************************************************\n"
			" you have " << Ressources << " Ressource(s).\n"
			" Do you want to recruit this unit? (\"y\" or \"n\") > ";
}

void Menus::Demon(int Ressources)
{
	cout << endl <<
			" ***************************************************************************************************************************************************************\n"
			" *               _.'          .                                                                                                                                *\n"
			" *             |P`            ?\                                              \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB                                                                         *\n"
			" *            .\"h              \"B                                            \xBA Demon \xBA                                                                         *\n"
			" *            (\"\"h             \"P                                            \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC                                                                         *\n"
			" *            ?\"\"\",          .\"\"P                                                                                                                              *\n"
			" *            {\"``\"\"oo____oo\"\"\"\"P                                             Attack:  10                                                                      *\n"
			" *             '\"\"888888888888,;                                              Defense: 10                                                                      *\n"
			" *              `?88P^\\,?88^\\,Y                                               Cost:    10                                                                      *\n"
			" *                88?\\__d88\\_/'                                                                                                                                *\n"
			" *                `8o8888/\\88P                                                                                                                                 *\n"
			" *                 ,?oo88oo8P                                                                                                                                  *\n"
			" *       ___  __===~88~\\\\\\\\\\|~====__ __       ___                                                                                                              *\n"
			" *   .-==ooo~odoooob ?8/////'oooood88888ooo?P88888?ooo?888PooooOoooooooo=~--                                                                                   *\n"
			" *  d,d8888obo8,oo8b,``~~~,o?8oo,8888**8P88?8`oo,o888?898o8P888P~8b                                                                                            *\n"
			" *  8o88888oP?.,,ooood8b,.oo.,oo88?o8888P^^^?8888P^^^^==+=~~~?8bo?P                                                                                            *\n"
			" *  ?8.=~=.8do.,oo88888ooo,o,oo88888o,;                                                                                                                        *\n"
			" *  .?*o88ob`8.,o88888888oo,o,o88888o,'                                                                                                                        *\n"
			" *  |*o8888o`8,oo88888888oo,o,o?8888o'                                                                                                                         *\n"
			" *  `?o8888P`88,,oo88888oo,,.,oo88oo;                                                                                                                          *\n"
			" *  .8`o888'**888oo,,,,oood88oo,,d8'                                                                                                                           *\n"
			" *  doo,,oP  ?888o,,o8o,o8o,,,o8oo'                                                                                                                            *\n"
			" *  8od8bo'  `?88o,,o8o,o88o,.,o,o'                                                                                                                            *\n"
			" *  8o888o    `88o,,o8o,o8o,.,o,o'                                                                                                                             *\n"
			" *  ?o888P     ===========<666>==                                                                                                                              *\n"
			" *  `?88P     ********************                                                                                                                             *\n"
			" *   ?ooPb   ',odoo,************,b                                                                                                                             *\n"
			" *  d{{{{b\\,(,oo88ooo,,********,oob                                                                                                                            *\n"
			" *  OOOOO \\\\,oo8888ooo,,******,o888,                                                                                                                           *\n"
			" *  (\\\\\\\\ ||,o8888888oo,,*****,o88o)                                                                                                                           *\n"
			" *    \\\\\\\\/`,o8888888oo',*****,888o|                                                                                                                           *\n"
			" *          `oo8888888o',*****,888o|                                                                                                                           *\n"
			" *          `,o888888oo,,*****,o8oo'                                                                                                                           *\n"
			" *          `,o88888oo,, *****,o8oP                                                                                                                            *\n"
			" *          `?,o888oP,,  *****,ooP                                                                                                                             *\n"
			" *           `8-==-P,    |****,,-='                                                                                                                            *\n"
			" *            ?o88oP     |*'d*,o88                                                                                                                             *\n"
			" *           .dboodb.     *;8*,o88                                                                                                                             *\n"
			" *           ,od88boo     *,o*,o88'                                                                                                                            *\n"
			" *           ?o8888oP     |`,|,oo'                                                                                                                             *\n"
			" *           `o8888o'     `?o8oP                                                                                                                               *\n"
			" *            `o88o'      ,o88o'                                                                                                                               *\n"
			" *             ?ooP       `?88o'                                                                                                                               *\n"
			" *            dooo'b      'o88oo,.                                                                                                                             *\n"
			" *           '?o===o   ~-=8oo888888oo.__                                                                                                                       *\n"
			" *           8888888     `~~~' `==~~~=-,'                                                                                                                      *\n"
			" *           ?8P?88P                                                                                                                                           *\n"
			" *            V''V'                                                                                                                                            *\n"
			" ***************************************************************************************************************************************************************\n"
			" you have " << Ressources << " Ressource(s).\n"
			" Do you want to invoke this unit? (\"y\" or \"n\") > ";
}