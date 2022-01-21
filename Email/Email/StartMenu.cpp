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

int StartMenuScreen(map<string, string>& loginInfo, string& username, string& password)
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
			cout << "Invalid command! Try again: ";
		}
	} while (true);
}

bool Login(const map<string, string>& userInfo, string& username, string& password)
{
	bool match = false;

	cout << "Type your username: ";
	cin >> username;
	cout << "Type your password: ";
	cin >> password;

	hash<string> passHash;
	password = to_string(passHash(password));

	for (auto& pair : userInfo)
	{
		if (pair.first == username && pair.second == password)
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
		password = "";
		return false;
	}
}

void ValidateUsersFile()
{
	fstream users;
	users.open("users.txt", fstream::in);
	fstream usersCopy;
	usersCopy.open("usersCopy.txt", fstream::out);
	string buffer = "";
	int colonCnt = 0;
	while (getline(users, buffer))
	{
		colonCnt = 0;
		if (buffer == "")
		{
			continue;
		}
		for (char el : buffer)
		{
			if (
				el != '&' && el != '*' && el != '<' && el != '>' && el != '?' && el != '.' && el != '+' && el != '-' && 
				((el < 65 || el > 122) || 
				(el > 90 && el < 97)) && 
				(el < 48 || el > 57)
				)
			{
				if (el == ':')
				{
					colonCnt++;
				}
				else
				{
					continue;
				}
			}
		}
		if (colonCnt == 1)
		{
			usersCopy << buffer << endl;
		}
	}
	users.close();
	usersCopy.close();

	remove("users.txt");
	rename("usersCopy.txt", "users.txt");
	remove("usersCopy.txt");
}