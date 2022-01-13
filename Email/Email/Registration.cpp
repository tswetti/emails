#include "Registration.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

bool Registration(map<string, string> userInfo, string& username, string& password)
{
	bool availableName = true;

	do
	{
		availableName = true;
		cout << "Type a username: ";
		cin >> username;

		for (auto& pair : userInfo)
		{
			if (pair.first == username)
			{
				cout << "The username is taken!" << endl;
				availableName = false;
				break;
			}
		}
	} while (!availableName);

	do
	{
		cout << "Type a password: ";
		cin >> password;
	} while (!isValidPassword(password));

	hash<string> passHash;
	password = to_string(passHash(password));

	fstream users;
	users.open("users.txt", fstream::out | fstream::app);
	users << username << ':' << password << endl;
	users.close();

	return 1;

}

bool isValidPassword(string password)
{
	if (password.length() < 6)
	{
		return false;
	}

	bool hasLowercase = false;
	bool hasUppercase = false;
	bool hasDigit = false;
	bool hasSymbol = false;
	bool isSymbol = false;

	char allowedSymbols[9] = { '&', '*', '<', '>', '?', '.', '+', '-' };

	for (char el : password)
	{
		if (el >= 65 && el <= 90)
		{
			hasUppercase = true;
		}
		else if (el >= 97 && el <= 122)
		{
			hasLowercase = true;
		}
		else if (el >= 48 && el <= 57)
		{
			hasDigit = true;
		}
		else
		{
			isSymbol = false;
			for (char symbol : allowedSymbols)
			{
				if (el == symbol)
				{
					hasSymbol = true;
					isSymbol = true;
					break;
				}
			}
			if (!isSymbol)
			{
				return false;
			}
		}
	}

	if (hasLowercase && hasUppercase && hasDigit && hasSymbol)
	{
		return true;
	}
	else
	{
		return false;
	}
}