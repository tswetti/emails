#include "Registration.h"
#include "Validation.h"
#include "StartMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>	// used for hashing
#include <direct.h>			// used for creating directories

using namespace std;

bool isSuccessfulRegistration(map<string, string>& usersInfo, string& username, string& password)
{
	do
	{
		cout << "Type a username: ";
		cin >> username;

		if (username == "Q" || username == "q")
		{
			return false;
		}
	}
	while (!isValidUsername(usersInfo, username));

	do
	{
		cout << "Type a password: ";
		cin >> password;

		if (password == "Q" || password == "q")
		{
			return false;
		}
	}
	while (!isValidPassword(password));

	hash<string> passHash;
	password = to_string(passHash(password));

	if (!CreateDirectory(username))
	{
		cout << "Unable to create a directory. Registration failed." << endl;
		return false;
	}

	SaveNewUser(usersInfo, username, password);

	cout << "Successful registration!" << endl;
	return true;
}

bool CreateDirectory(const string& username)
{
	char* directoryName = StringToArray(username);

	if (_mkdir(directoryName) != 0)
	{
		delete[] directoryName;
		return false;
	}
	
	delete[] directoryName;
	return true;
}

void SaveNewUser(map<string, string>& usersInfo, const string& username, const string& password)
{
	ofstream users;
	users.open("users.txt", fstream::app);
	users << username << ':' << password << endl;
	users.close();

	usersInfo.insert(pair<string, string>(username, password));
}