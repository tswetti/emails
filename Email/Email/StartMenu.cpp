#include "StartMenu.h"
#include "Registration.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>

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

int StartMenuScreen(map<string, string> loginInfo, string& username, string& password)
{
	int loginAttempts = 0, maxAttempts = 3;
	char command;
	cout << "Type a command: ";

	do
	{
		cin >> command;
		if (command == 'L')
		{
			cout << endl;
			while (++loginAttempts <= maxAttempts && !Login(loginInfo, username));
			if (loginAttempts == maxAttempts + 1)
			{
				return 1;
			}
			return 2;
		}
		else if (command == 'R')
		{
			cout << endl;
			if (!Registration(loginInfo, username, password))
			{
				return 1;
			}
			return 3;
		}
		else if (command == 'Q')
		{
			return 1;
		}
		else
		{
			cout << "Invalid command! Try again: ";
		}
	} while (true);
}

bool Login(map<string, string> userInfo, string& username)
{
	string password;
	bool match = false;

	cout << "Type your username: ";
	cin >> username;
	cout << "Type your password: ";
	cin >> password;
	hash<string> passHash;

	for (auto& pair : userInfo)
	{
		if (pair.first == username && pair.second == to_string(passHash(password)))
		{
			match = true;
			break;
		}
	}

	if (match)
	{
		cout << "Successful login!" << endl;
		return true;
	}
	else
	{
		cout << "Unsuccessful login." << endl;
		username = "";
		return false;
	}
}