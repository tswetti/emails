#include "CloseAccount.h"
#include "LoadEmail.h"
#include "Validation.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>

// used for deleting directories
#ifdef _WIN32
#include <direct.h>	
#else
#include <unistd.h>
#endif

using namespace std;

bool closeAccount(const string& username, const string& password, int& mails, map<string, string>& userInfo)
{
	cout << "Are you sure you want to delete your account? Enter your password to continue: ";
	string inputPass;
	cin >> inputPass;

	hash<string> passHash;
	inputPass = to_string(passHash(inputPass));

	if (inputPass != password)
	{
		cout << "Wrong password!";
		return false;
	}

	if (!deleteDirectory(username, mails) || !rewriteFile(username, password))
	{
		cout << "An error occured while deleting this user's profile. Please, try closing the account later." << endl;
		return false;
	}

	userInfo.erase(username);

	cout << "Account deleted successfully!" << endl;
	return true;
}

bool deleteDirectory(const string& username, int& mails)
{
	// the directory has to be empty in order to be deleted
	if (!deleteAllUserMails(username, mails) || !deleteTotalMailsFile(username))
	{
		return false;
	}

	char* directoryName = stringToArray(username);

	#if _WIN32
	if (directoryName == nullptr || _rmdir(directoryName) != 0)
	{
		delete[] directoryName;
		return false;
	}

	#else
	if (directoryName == nullptr || rmdir(directoryName) != 0)
	{
		delete[] directoryName;
		return false;
	}
	#endif

	delete[] directoryName;
	return true;
}


bool deleteAllUserMails(const string& username, int& mails)
{
	string fileName = "";
	int cnt = 0;

	for (int i = 1; i <= mails; i++)
	{
		fileName = username + '/' + to_string(i) + ".txt";
		char* currentMail = stringToArray(fileName);	// the remove function accepts only char arrays

		if (currentMail == nullptr || remove(currentMail) != 0)
		{
			delete[] currentMail;
			return false;
		}
		delete[] currentMail;
	}

	mails = 0;
	return true;
}

bool deleteTotalMailsFile(const string& username)
{
	int cnt = 0;
	string fileName = username + "/totalMails.txt";
	char* totalMails = stringToArray(fileName);			// the remove function accepts only char arrays

	if (totalMails == nullptr || remove(totalMails) != 0)
	{
		delete[] totalMails;
		return false;
	}

	delete[] totalMails;
	return true;
}

bool rewriteFile(const string& username, const string& password)
{
	string buffer = "";

	fstream users, usersCopy;
	users.open("users.txt", fstream::in);
	usersCopy.open("usersCopy.txt", fstream::out | fstream::app);

	// rewrite the file with all info except the deleted user's
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