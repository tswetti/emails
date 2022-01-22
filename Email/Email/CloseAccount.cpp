#include "CloseAccount.h"
#include "MainMenu.h"
#include "StartMenu.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
#include <direct.h>

using namespace std;

bool CloseAccount(const string& username, const string& password, int& mails, map<string, string>& userInfo)
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

	if (!DeleteDirectory(username, mails) || !RewriteFile(username, password))
	{
		cout << "An error occured while deleting this user's profile. Please, try closing the account later." << endl;
		return false;
	}

	userInfo.erase(username);

	cout << "Profile deleted successfully!" << endl;
	return true;
}

bool DeleteDirectory(const string& username, int& mails)
{
	// the directory has to be empty in order to be deleted
	if (!DeleteAllUserMails(username, mails) || !DeleteTotalMailsFile(username))
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


bool DeleteAllUserMails(const string& username, int& mails)
{
	string fileName = "";
	int cnt = 0;

	for (int i = 1; i <= mails; i++)
	{
		fileName = username + "/" + to_string(i) + ".txt";
		char* currentMail = StringToArray(fileName);	// the remove function accepts only char arrays

		if (remove(currentMail) != 0)
		{
			delete[] currentMail;
			return false;
		}
		delete[] currentMail;
	}
	mails = 0;
	return true;
}

bool DeleteTotalMailsFile(const string& username)
{
	int cnt = 0;
	string fileName = username + "/totalMails.txt";
	char* totalMails = StringToArray(fileName);			// the remove function accepts only char arrays

	if (remove(totalMails) != 0)
	{
		delete[] totalMails;
		return false;
	}
	delete[] totalMails;
	return true;
}

bool RewriteFile(const string& username, const string& password)
{
	string buffer = "";

	fstream users, usersCopy;
	users.open("users.txt", fstream::in);
	usersCopy.open("usersCopy.txt", fstream::out | fstream::app);

	// rewrite the file with all info except this user's
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