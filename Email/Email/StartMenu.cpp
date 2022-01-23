#include "StartMenu.h"
#include "Registration.h"
#include "Login.h"
#include "Validation.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;

int startMenuScreen(string& username, string& password, map<string, string>& usersInfo)
{
	const char	LOG_UPPER = 'L', LOG_LOWER = 'l',
				REG_UPPER = 'R', REG_LOWER = 'r',
				QUIT_UPPER = 'Q', QUIT_LOWER = 'q';

	printStartMenuGuide();

	char command;
	cout << "Type a command: ";

	do
	{
		if (!isValidCommandLength(command))
		{
			continue;
		}

		if (command == LOG_UPPER || command == LOG_LOWER)
		{
			cout << endl;

			if (!isSuccessfulLogin(usersInfo, username, password))
			{
				return 1;
			}

			cout << endl << "Welcome back, " << username << "!" << endl;
			cin.ignore();

			return 0;
		}
		else if (command == REG_UPPER || command == REG_LOWER)
		{
			cout << endl;

			if (!isSuccessfulRegistration(usersInfo, username, password))
			{
				return 1;
			}

			cout << endl << "Welcome, " << username << "!" << endl;
			cin.ignore();

			return 0;
		}
		else if (command == QUIT_UPPER || command == QUIT_LOWER)
		{
			return 1;
		}
		else
		{
			cout << "Invalid command! Please, try again: ";
		}
	}
	while (true);
}

void printStartMenuGuide()
{
	cout << "Choose one of the following options: " << endl;
	cout << "L - login" << endl
		<< "R - register" << endl
		<< "Q - quit" << endl
		<< endl;
}