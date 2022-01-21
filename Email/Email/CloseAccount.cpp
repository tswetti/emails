#include "CloseAccount.h"
#include "MainMenu.h"
#include "Validation.h"
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

	if (!DeleteDirectory(username) || !RewriteFile(username, password))
	{
		cout << "An error occured while deleting this user's profile. Please, try closing the account later." << endl;
		return false;
	}
	userInfo.erase(username);
	return true;
}

bool DeleteAllUserMails(const string& username)
{
	int mailsCnt = GetTotalMails(username);
	string fileName = "";
	int cnt = 0;

	for (int i = 1; i <= mailsCnt; i++)
	{
		fileName = username + "/" + to_string(i) + ".txt";
		char* currentMail = StringToArray(fileName);

		if (remove(currentMail) != 0)
		{
			delete[] currentMail;
			return false;
		}
		delete[] currentMail;
	}
	return true;
}

bool DeleteTotalMailsFile(const string& username)
{
	int cnt = 0;
	string fileName = username + "/totalMails.txt";
	char* totalMails = StringToArray(fileName);

	if (remove(totalMails) != 0)
	{
		delete[] totalMails;
		return false;
	}
	delete[] totalMails;
	return true;
}

char* StringToArray(const string& str)
{
	char* arr = new char[str.length() + 1];
	int cnt = 0;

	for (char el : str)
	{
		arr[cnt++] = el;
	}
	arr[cnt] = '\0';
	return arr;
}

bool DeleteDirectory(const string& username)
{
	// the directory has to be empty in order to be deleted
	if (!DeleteAllUserMails(username) || !DeleteTotalMailsFile(username))
	{
		return false;
	}

	char* directoryName = StringToArray(username);

	if (_rmdir(directoryName) != 0)
	{
		delete[] directoryName;
		return false;
	}

	delete[] directoryName;
	return true;
}

bool RewriteFile(const string& username, const string& password)
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

	if (remove("users.txt") != 0 || rename("usersCopy.txt", "users.txt") != 0)
	{
		return false;
	}

	return true;
}