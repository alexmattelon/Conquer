#include <iostream>
#include "errorHandling.h"

using namespace std;

int ErrorHandling::Menu3(int Answer)
{
	while(cin.fail() || (Answer < 1 || Answer > 3))
	{
		if(cin.fail()) {
			cout << "\n You have not entered a number!"; }
		else {
			cout << "\n Your selection must be 1, 2 or 3!"; }
		cin.sync();
		cin.clear();

		cout << "\n Enter your selection (1, 2 or 3) > ";
		cin >> Answer;
	}

	return Answer;
}

int ErrorHandling::Menu4(int Answer)
{
	while(cin.fail() || (Answer < 1 || Answer > 4))
	{
		if(cin.fail()) {
			cout << "\n You have not entered a number!"; }
		else {
			cout << "\n Your selection must be between 1 and 4!"; }
		cin.sync();
		cin.clear();

		cout << "\n Enter your selection (1, 2, 3 or 4) > ";
		cin >> Answer;
	}

	return Answer;
}

int ErrorHandling::Menu5(int Answer)
{
	while(cin.fail() || (Answer < 1 || Answer > 5))
	{
		if(cin.fail()) {
			cout << "\n You have not entered a number!"; }
		else {
			cout << "\n Your selection must be between 1 and 5!"; }
		cin.sync();
		cin.clear();

		cout << "\n Enter your selection (1, 2, 3, 4 or 5) > ";
		cin >> Answer;
	}

	return Answer;
}

int ErrorHandling::Menu6(int Answer)
{
	while(cin.fail() || (Answer < 1 || Answer > 6))
	{
		if(cin.fail()) {
			cout << "\n You have not entered a number!"; }
		else {
			cout << "\n Your selection must be between 1 and 6!"; }
		cin.sync();
		cin.clear();

		cout << "\n Enter your selection (1, 2, 3, 4, 5 or 6) > ";
		cin >> Answer;
	}

	return Answer;
}

char ErrorHandling::MenuYN(char Answer)
{
	bool Handled = false;

	while(Handled == false)
	{
		switch(Answer)
		{
		case 'y':
		case 'Y': 
			Handled = true;
			break;
		case 'n':
		case 'N':
			Handled = true;
			break;
		default: 
			cout << "\n Your selection must be \"y\" or \"n\"!";
			cin.sync();
			cin.clear();
			cout << "\n Enter your selection (\"y\" or \"n\"): ";
			cin >> Answer;
			break;
		}
	}

	return Answer;
}

void ErrorHandling::OwnedCountry()
{
	cout << " You already own this country, choose another one.";
	cin.ignore();
	cout << endl << " Press ENTER to choose another country...\n";
	cin.get();
}

void ErrorHandling::NotOwnedCountry()
{
	cout << " You do not own this country, choose another one.";
	cin.ignore();
	cout << endl << " Press ENTER to choose another country...\n";
	cin.get();
}

int ErrorHandling::MenuInt(int Answer)
{
	while(cin.fail())
	{
		cout << "\n You have not entered a number!";
		cin.sync();
		cin.clear();

		cout << "\n Enter your selection > ";
		cin >> Answer;
	}

	return Answer;
}