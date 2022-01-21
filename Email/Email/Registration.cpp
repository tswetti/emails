#include "Registration.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <direct.h>

using namespace std;

bool Registration(map<string, string>& usersInfo, string& username, string& password)
{
	do
	{
		cout << "Type a username: ";
		cin >> username;
	}
	while (!isValidUsername(usersInfo, username));

	do
	{
		cout << "Type a password: ";
		cin >> password;
	} while (!isValidPassword(password));

	hash<string> passHash;
	password = to_string(passHash(password));

	if (!CreateDirectory(username))
	{
		cout << "Unable to create a directory. Registration failed." << endl;
		return 0;
	}

	SaveNewUser(usersInfo, username, password);

	cout << "Successful registration!" << endl;
	return 1;
}

bool isLowercaseLetter(const char& symbol)
{
	return symbol >= 97 && symbol <= 122;
}

bool isUppercaseLetter(const char& symbol)
{
	return symbol >= 65 && symbol <= 90;
}

bool isDigit(const char& symbol)
{
	return symbol >= 48 && symbol <= 57;
}

bool isAllowedSpecialSymbol(const char& symbol)
{
	char allowedSymbols[8] = { '&', '*', '<', '>', '?', '.', '+', '-' };
	for (char el : allowedSymbols)
	{
		if (el == symbol)
		{
			return true;
		}
	}
	return false;
}

bool isValidPassword(const string& password)
{
	if (password.length() < 6)
	{
		return false;
	}

	bool hasLowercase = false;
	bool hasUppercase = false;
	bool hasDigit = false;
	bool hasSymbol = false;

	for (char el : password)
	{
		if (isUppercaseLetter(el))
		{
			hasUppercase = true;
		}
		else if (isLowercaseLetter(el))
		{
			hasLowercase = true;
		}
		else if (isDigit(el))
		{
			hasDigit = true;
		}
		else
		{
			if (!isAllowedSpecialSymbol(el))
			{
				return false;
			}
			hasSymbol = true;
		}
	}

	if (hasLowercase && hasUppercase && hasDigit && hasSymbol)
	{
		return true;
	}
	return false;
}

bool isValidUsername(const map<string, string>& usersInfo, const string& username)
{
	for (char el : username)
	{
		if (!isLowercaseLetter(el) && !isUppercaseLetter(el))
		{
			cout << "The username must consist of latin letters only!" << endl;
			return false;
		}
	}

	for (auto& pair : usersInfo)
	{
		if (pair.first == username)
		{
			cout << "The username is taken." << endl;
			return false;
		}
	}
	
	return true;
}

bool CreateDirectory(const string& username)
{
	char name[50];
	int cnt = 0;
	for (char el : username)
	{
		name[cnt++] = el;
	}
	name[cnt] = '\0';

	if (_mkdir(name) != 0)
	{
		return false;
	}

	return true;
}

void SaveNewUser(map<string, string>& usersInfo, const string& username, const string& password)
{
	fstream users;
	users.open("users.txt", fstream::out | fstream::app);
	users << username << ':' << password << endl;
	users.close();

	usersInfo.insert(pair<string, string>(username, password));
}