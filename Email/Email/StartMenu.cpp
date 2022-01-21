#include "StartMenu.h"
#include "Registration.h"
#include "Login.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int StartMenuScreen(map<string, string>& loginInfo, string& username, string& password)
{
	printStartMenuGuide();
	char command = '\0';
	cout << "Type a command: ";

	do
	{
		if (!isValidCommandLength(command))
		{
			cout << "The command should consist of one letter only. " << endl << "Please, try again: ";
			continue;
		}

		if (command == 'L')
		{
			cout << endl;
			if (!isLoggedIn(loginInfo, username, password))
			{
				return 1;
			}
			cout << endl << "Welcome back, " << username << "!" << endl;
			cin.ignore();
			return 0;
		}
		else if (command == 'R')
		{
			cout << endl;
			if (!Registration(loginInfo, username, password))
			{
				return 1;
			}
			cout << endl << "Welcome, " << username << "!" << endl;
			cin.ignore();
			return 0;
		}
		else if (command == 'Q')
		{
			return 1;
		}
		else
		{
			cout << "Invalid command! Please, try again: ";
		}
	} while (true);
}

void UsersInfoToMap(map<string, string>& info)
{
	string key, value, buffer, fileName = "users.txt";
	const char DELIMITER = ':';

	fstream usersInfo;
	usersInfo.open(fileName, fstream::in);

	while (getline(usersInfo, buffer))
	{
		key = buffer.substr(0, buffer.find(DELIMITER));
		value = buffer.substr(buffer.find(DELIMITER) + 1);
		info.insert(pair<string, string>(key, value));
	}
	usersInfo.close();
}

void printStartMenuGuide()
{
	cout << "Choose one of the following options: " << endl;
	cout << "L - login" << endl
		<< "R - register" << endl
		<< "Q - quit" << endl
		<< endl;
}