#include "CloseAccount.h"
#include "MainMenu.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
#include <direct.h>

using namespace std;

bool CloseAccount(const string& username, const string& password, map<string, string>& userInfo)
{
	string inputPass;
	cout << "Are you sure you want to delete your account? Enter your password to continue: ";
	cin >> inputPass;

	hash<string> passHash;
	inputPass = to_string(passHash(inputPass));

	if (inputPass != password)
	{
		cout << "Wrong password!";
		return false;
	}

	if (!DeleteDirectory(username))
	{
		cout << "Error while deleting directory.";
	}
	userInfo.erase(username);
	RewriteFile(username, password);
	return true;
}

bool DeleteDirectory(const string& username)
{
	int mailsCnt = GetTotalMails(username);
	string fileName;
	int cnt = 0;
	for (int i = 1; i <= mailsCnt; i++)
	{
		fileName = username + "/" + to_string(i) + ".txt";
		char file[50] = { };
		cnt = 0;
		for (char el : fileName)
		{
			file[cnt++] = el;
		}
		remove(file);
	}
	cnt = 0;
	fileName = username + "/totalMails.txt";
	char fileMeta[50] = { };
	for (char el : fileName)
	{
		fileMeta[cnt++] = el;
	}
	remove(fileMeta);

	char name[50] = { };
	cnt = 0;
	for (char el : username)
	{
		name[cnt++] = el;
	}
	name[cnt] = '\0';

	if (_rmdir(name) != 0)
	{
		return false;
	}

	return true;
}

void RewriteFile(const string& username, const string& password)
{
	fstream users, usersCopy;
	string buffer = "";
	users.open("users.txt", fstream::in);
	usersCopy.open("usersCopy.txt", fstream::out | fstream::app);

	while (getline(users, buffer))
	{
		if (buffer != (username + ':' + password))
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
