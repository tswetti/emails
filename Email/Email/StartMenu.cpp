#include "StartMenu.h"
#include "Registration.h"
#include "Login.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

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

int StartMenuScreen(map<string, string>& loginInfo, string& username, string& password)
{
	int loginAttempts = 0, maxAttempts = 3;
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
			while (++loginAttempts <= maxAttempts && !Login(loginInfo, username, password));
			if (loginAttempts == maxAttempts + 1)
			{
				return 1;
			}
			cout << endl << "Welcome back, " << username << '!' << endl;
			return 2;
		}
		else if (command == 'R')
		{
			cout << endl;
			if (!Registration(loginInfo, username, password))
			{
				return 1;
			}
			cout << endl << "Welcome, " << username << '!' << endl;
			return 2;
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