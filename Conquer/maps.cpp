#include <iostream>
#include <string>
#include <windows.h>
#include "maps.h"

using namespace std;

void Maps::MainMap(int Domed, int Tane, int Joha, int Odori, int Antemie)
{	
	//Calling the classes
	Config ApplyConfig;
	//Declaring the variables
	int x;
	int y;
	
	//Create the map
	char WorldMap[47][161] = {" \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB",
							  " \xBA                                                                                                     &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                    \xBA",
							  " \xBA                                                                                                    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                  \xBA",
							  " \xBA                            !!!!!!!!!!!      !!!!!!!                                              &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                  \xBA",
							  " \xBA                       !!!!!!!!!!!!!!!!!!   !!!!!!!!!!                                           &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                 \xBA",
							  " \xBA                  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                                         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              \xBA",
							  " \xBA              !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                                         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&           \xBA",
							  " \xBA            !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                                         &&&&&&&&&&&&&&&&&&&&&O D O R I&&&&&&&&&&&&&&&&&&&&&&         \xBA",
							  " \xBA          !!!!!!!!!!!!!!!!!D O M E D!!!!!!!!!!!!!!!!!!!                     @@@@@@@@@@@           &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        \xBA",
							  " \xBA         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                   @@@@@@@@@@@@@            &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        \xBA",
							  " \xBA         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                   @@@@@@@@@@@@               &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        \xBA",
							  " \xBA         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                       @@@@@@@@@                    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        \xBA",
							  " \xBA         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!                                   @@@@@@@@@@@@@                              &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&         \xBA",
							  " \xBA           !!!!!!!!!!!!!!!!!!!!!!!!!!                                    @@@@@@@@@@@@@@@@                               &&&&&&&&&&&&&&&&&&&&&&&&&&           \xBA",
							  " \xBA                           !!!!!!                                       @@@@@@@@@@@@@@@@@ @@                                 &&&&&&&&&&&&&&&&&               \xBA",
							  " \xBA                                                                      @@@@@@@@@@@@@@@@@@@@@@                                                                 \xBA",
							  " \xBA                                                                     @@@@@@@@@@@@@@@@@@@@@@@                                                                 \xBA",
							  " \xBA                               $$$$$$$$$$$$$                         @@@@@@@@@@@@@@@@@@@@@@@                                                                 \xBA",
							  " \xBA        $$$$$$$$$$$$          $$$$$$$$$$$$$$$                       @@@@@@@@@@@@@@@@@@@@@@@@                                                                 \xBA",
							  " \xBA         $$$$$$$$$$          $$$$$$$$$$$$$$$$                       @@@@@@@@@@@@@@@@@@@@@@@@                        #####                                    \xBA",
							  " \xBA              $$$$$$$       $$$$$$$$$$$$$$$$$                       @@@@@@@@@@@@@@@@@@@@@@                     #################                             \xBA",
							  " \xBA              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                        @@@@@@@@@@@@@@@@@@@@                      ###########################                    \xBA",
							  " \xBA              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$                         @@@@@@@@@@@@@@@@@@@@                       ############################                  \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$$$                           @@@@@@@@@@@@@@@@@@@@                       #############################                 \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$$$                         @@@@@@@@J O H A@@@@@@@                       ##############################                \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$$                        @@@@@@@@@@@@@@@@@@@@@@@@                       ##############################                \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$$                      @@@@@@@@@@@@@@@@@@@@@@@@@@                       ###############################               \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$$$                     @@@@@@@@@@@@@@@@@@@@@@@@@@                       ################################              \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$$$                     @@@@@@@@@@@@@@@@@@@@@@@@@@                       ################################              \xBA",
							  " \xBA             $$$$$$$$$$T A N E$$$$$$$$$$$                     @@@@@@@@@@@@@@@@@@@@@@@@@@                       ################################              \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$$$                     @@@@@@@@@@@@@@@@@@@@@@@@@@                      #################################              \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$$                      @@@@@@@@@@@@@@@@@@@@@@@@@@                    ############A N T E M I E##########              \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$$                       @@@@@@@@@@@@@@@@@@@@@@@@@@                  #####################################              \xBA",
							  " \xBA             $$$$$$$$$$$$$$$$$$$$$$$$$                        @@@@@@@@@@@@@@@@@@@@@@@@@@                  ####################################               \xBA",
							  " \xBA              $$$$$$$$$$$$$$$$$$$$$$$                         @@@@@@@@@@@@@@@@@@@@@@@@@@                  ####################################               \xBA",
							  " \xBA                $$$$$$$$$$$$$$$$$$$                          @@@@@@@@@@@      @@@@@@@                     ####################################               \xBA",
							  " \xBA                 $$$$$$$$$$$$$$$$$$                         @@@@@@@@@@@         @@@                       ####################################               \xBA",
							  " \xBA                  $$$$$$$$$$$$$$$$$                         @@@@@@@@@@@                                   ####################################               \xBA",
							  " \xBA                   $$$$$$$$$$$$$$$$                        @@@@@@@@@@@                                    ####################################               \xBA",
							  " \xBA                    $$$$$$$$$$$$$$$                          @@@@@@@                                       ###################################               \xBA",
							  " \xBA                    $$$$$$$$$$$$$$$$                                                                        #################################                \xBA",
							  " \xBA                     $$$$$$$$$$$$$$$                                                                        #################################                \xBA",
							  " \xBA                      $$$$$$$$$$$$$$                                                                        #################################                \xBA",
							  " \xBA                       $$$$$$$$$$$$$                                                                         ###################                             \xBA",
							  " \xBA                          $$$$$$$$$$                                                                                                                         \xBA",							 
							  " \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC",
							  "                                      * = land you own          | = land owned by no one          : = land owned by enemy                                       "};
	//Draw the map on the screen
	cout << endl;
	for(x = 0; x < 47; x++)
	{
		for(y = 0; y < 161; y++)
		{
			//Looks for special characters and if found, change the foreground and background colors
			switch(WorldMap[x][y])
			{
			case '!':
				switch(Domed)
				{
				case 0:
					ApplyConfig.ColorChanger(FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 1:
					ApplyConfig.ColorChanger(FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 2:
					ApplyConfig.ColorChanger(FOREGROUND_RED| FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
				break;
			case '$':
				switch(Tane)
				{
				case 0:
					ApplyConfig.ColorChanger(FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 1:
					ApplyConfig.ColorChanger(FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 2:
					ApplyConfig.ColorChanger(FOREGROUND_RED| FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
				break;
			case '@':
				switch(Joha)
				{
				case 0:
					ApplyConfig.ColorChanger(FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 1:
					ApplyConfig.ColorChanger(FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 2:
					ApplyConfig.ColorChanger(FOREGROUND_RED| FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
				break;
			case '&':
				switch(Odori)
				{
				case 0:
					ApplyConfig.ColorChanger(FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 1:
					ApplyConfig.ColorChanger(FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 2:
					ApplyConfig.ColorChanger(FOREGROUND_RED| FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
				break;
			case '#':
				switch(Antemie)
				{
				case 0:
					ApplyConfig.ColorChanger(FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 1:
					ApplyConfig.ColorChanger(FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				case 2:
					ApplyConfig.ColorChanger(FOREGROUND_RED| FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
					cout << WorldMap[x][y];
					ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
				break;
			case '*':
				ApplyConfig.ColorChanger(FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
				cout << WorldMap[x][y];
				ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			case '|':
				ApplyConfig.ColorChanger(FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				cout << WorldMap[x][y];
				ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			case ':':
				ApplyConfig.ColorChanger(FOREGROUND_RED| FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << WorldMap[x][y];
				ApplyConfig.ColorChanger(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			default:
				cout << WorldMap[x][y];
				break;
			}			
		}
	}
}

