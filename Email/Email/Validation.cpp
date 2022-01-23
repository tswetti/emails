#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <cstdio>	// used by remove and rename functions

using namespace std;

bool validateUsersFile()
{
	fstream users, usersCopy;
	users.open("users.txt", fstream::in | fstream::out | fstream::app);
	usersCopy.open("usersCopy.txt", fstream::out);

	string buffer = "";
	int colonCnt = 0;
	bool isValid = true;

	while (getline(users, buffer))
	{
		colonCnt = 0;
		if (buffer.empty())
		{
			continue;
		}

		for (char el : buffer)
		{
			if (!isLowercaseLetter(el) && !isUppercaseLetter(el) && !isDigit(el) && !isAllowedSpecialSymbol(el))
			{
				if (el == ':')
				{
					colonCnt++;
				}
				else
				{
					isValid = false;
					break;
				}
			}
		}

		if (isValid && colonCnt == 1)
		{
			usersCopy << buffer << endl;
		}
	}
	users.close();
	usersCopy.close();

	if (remove("users.txt") != 0 || rename("usersCopy.txt", "users.txt") != 0)
	{
		return false;
	}
	return true;
}

bool isValidCommandLength(char& command)
{
	string commandStr = "";
	getline(cin, commandStr);

	if (commandStr.length() != 1)
	{
		cout << "The command should consist of one letter only. " << endl << "Please, try again: ";
		return false;
	}

	command = commandStr[0];
	return true;
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

bool isValidStrInput(const string& str)
{
	for (char el : str)
	{
		if (!isLowercaseLetter(el) && !isUppercaseLetter(el) && !isDigit(el) && (!isAllowedSpecialSymbol(el) && el != '!'))
		{
			return false;
		}
	}
	return true;
}

bool isValidPassword(const string& password)
{
	if (password.length() < 6)
	{
		cout << "The password must be 6 characters or more." << endl;
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
				cout << "The password must have at least 1 uppercase letter, 1 lowercase letter, 1 digit and 1 symbol (&*<>?.+-)." << endl;
				return false;
			}
			hasSymbol = true;
		}
	}

	if (hasLowercase && hasUppercase && hasDigit && hasSymbol)
	{
		return true;
	}
	cout << "The password must have at least 1 uppercase letter, 1 lowercase letter, 1 digit and 1 symbol (&*<>?.+-)." << endl;
	return false;
}

bool isValidUsername(const map<string, string>& usersInfo, const string& username)
{
	if (username.length() < 3 || username.length() > 20)
	{
		cout << "The username must be between 3 and 20 letters!" << endl;
		return false;
	}

	for (char el : username)
	{
		if (!isLowercaseLetter(el) && !isUppercaseLetter(el))
		{
			cout << "The username must consist of latin letters only!" << endl;
			return false;
		}
	}

	for (auto pair : usersInfo)
	{
		if (pair.first == username)
		{
			cout << "This username is taken." << endl;
			return false;
		}
	}

	return true;
}