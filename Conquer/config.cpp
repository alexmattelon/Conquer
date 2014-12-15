#include <windows.h>
#include "config.h"

void Config::ConsoleConfig()
{
	//Declare variables
	HANDLE H;
	HWND hWnd;
	//Get handle
	H = GetStdHandle(STD_OUTPUT_HANDLE);
	//Set the coordinates for the buffer size
	COORD UsersCoord = {161, 51};

	SetConsoleScreenBufferSize(H, UsersCoord);
	SMALL_RECT myWindow = {0, 0, 160, 50};
	SetConsoleWindowInfo(H, TRUE, &myWindow);

	//hWnd = GetConsoleWindow();
	//ShowWindow(hWnd,SW_SHOWMAXIMIZED);	
}

void Config::ColorChanger(int flags)
{
	//Declare variables
	HANDLE H;
	//Get handle
	H = GetStdHandle(STD_OUTPUT_HANDLE);
	//Change the color of the backgroud and the foreground
	SetConsoleTextAttribute(H, flags);
}

void Config::ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
	hStdOut,
	(TCHAR) ' ',
	cellCount,
	homeCoords,
	&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
	hStdOut,
	csbi.wAttributes,
	cellCount,
	homeCoords,
	&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition( hStdOut, homeCoords );
}