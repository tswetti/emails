#include "CloseAccount.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
#include <direct.h>

using namespace std;

bool CloseAccount(string username, string password, map<string, string>& userInfo)
{
	string inputPass;
	cout << "Are you sure you want to delete your account? Enter your password to continue: ";
	cin >> inputPass;

	hash<string> passHash;
	inputPass = to_string(passHash(password));

	if (inputPass != password)
	{
		return false;
	}

	DeleteDirectory(username);
	userInfo.erase(username);
	RewriteFile(username, password);
	return true;
}

bool DeleteDirectory(string username)
{
	char* name = new char[50];
	int cnt = 0;
	for (char el : username)
	{
		name[cnt++] = el;
	}
	name[cnt] = '\0';

	if (_rmdir(name) != 0)
	{
		delete[] name;
		return false;
	}

	delete[] name;
	return true;
}

void RewriteFile(string username, string password)
{
	fstream users, usersCopy;
	string buffer = "";
	users.open("users.txt", fstream::in);
	usersCopy.open("usersCopy.txt", fstream::out | fstream::app);

	while (getline(users, buffer))
	{
		if (buffer != (username + ":" + password))
		{
			usersCopy << buffer;
		}
	}

	users.close();
	usersCopy.close();

	remove("users.txt");
	rename("usersCopy.txt", "users.txt");
	remove("usersCopy.txt");
}
