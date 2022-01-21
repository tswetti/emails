#include "Registration.h"
#include "Validation.h"
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

bool CreateDirectory(const string& username)
{
	char* name = new char[username.length() + 1];
	int cnt = 0;
	for (char el : username)
	{
		name[cnt++] = el;
	}
	name[cnt] = '\0';

	if (_mkdir(name) != 0)
	{
		delete[] name;
		return false;
	}
	
	delete[] name;
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