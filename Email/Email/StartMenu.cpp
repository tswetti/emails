#include "StartMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int StartMenuScreen(map<string, string> loginInfo)
{
	int loginAttempts = 1, maxAttempts = 3;
	char command;
	cout << "Type a command: ";

	do
	{
		cin >> command;
		if (command == 'L')
		{
			cout << endl;
			while (maxAttempts >= loginAttempts++ && !Login(loginInfo));
			return 0;
		}
		else if (command == 'R')
		{
			return 0;
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

bool Login(map<string, string> userInfo)
{
	string username, password;
	bool match = false;

	cout << "Type your username: ";
	cin >> username;
	cout << "Type your password: ";
	cin >> password;

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
		cout << "Unsuccessful login. Try again!" << endl;
		return false;
	}
}