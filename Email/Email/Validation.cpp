#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

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
			if (!isLowercaseLetter(el) && !isUppercaseLetter(el) && !isDigit(el) && !isAllowedSpecialSymbol(el))
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

bool isValidCommandLength(char& command)
{
	string commandStr = "";
	getline(cin, commandStr);
	if (commandStr.length() != 1)
	{
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