#include "StartMenu.h"
#include "Registration.h"
#include "Login.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int startMenuScreen(map<string, string>& loginInfo, string& username, string& password)
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
			cout << "The command should consist of one letter only. " << endl << "Please, try again: ";
			continue;
		}

		if (command == LOG_UPPER || command == LOG_LOWER)
		{
			cout << endl;
			if (!isSuccessfulLogin(loginInfo, username, password))
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
			if (!isSuccessfulRegistration(loginInfo, username, password))
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

void usersInfoToMap(map<string, string>& info)
{
	string key, value, buffer, fileName = "users.txt";
	const char DELIMITER = ':';

	ifstream usersInfo;
	usersInfo.open(fileName);

	while (getline(usersInfo, buffer))
	{
		key = buffer.substr(0, buffer.find(DELIMITER));		// get the username which stops at :
		value = buffer.substr(buffer.find(DELIMITER) + 1);	// get the hashed password which starts right after :
		info.insert(pair<string, string>(key, value));
	}
	usersInfo.close();
}

char* stringToArray(const string& str)
{
	char* arr = new char[str.length() + 1];
	int cnt = 0;

	for (char el : str)
	{
		arr[cnt++] = el;
	}
	arr[cnt] = '\0';
	return arr;
}
