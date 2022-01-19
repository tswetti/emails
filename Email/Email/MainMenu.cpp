#include "MainMenu.h"
#include "StartMenu.h"
#include "CloseAccount.h"
#include "SendMail.h"
#include "Inbox.h"
#include "OpenMail.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
#include <direct.h>

using namespace std;

int MainMenu(string& username, string& password, map<string, string>& userInfo)
{
	int mails = GetTotalMails(username);
	if (mails == -1)
	{
		return 0;
	}
	
	PrintMainMenuGuide(mails);
	cout << "Type a command: ";
	char command;
	cin >> command;

	if (command == 'C')
	{
		if (CloseAccount(username, password, userInfo) == false)
		{
			return 0;
		}
		username = "";
		password = "";
		cout << endl;
		return 1;
	}
	else if (command == 'I')
	{
		PrintMailsSubject(username, mails);
		cout << endl;
		return 2;
	}
	else if (command == 'L')
	{
		username = "";
		password = "";
		cout << endl;
		return 1;
	}
	else if (command == 'O')
	{
		OpenMail(username);
		cout << endl;
		return 2;
	}
	else if (command == 'S')
	{
		SendMail(username, userInfo);
		cout << endl;
		return 2;
	}

	return 0;
}

void PrintMainMenuGuide(int mails)
{
	cout << "You have " << mails << " mails. Choose one of the following options:" << endl;
	cout << "C - close account" << endl
		<< "I - inbox" << endl
		<< "L - logout" << endl
		<< "O - open" << endl
		<< "S - send" << endl
		<< endl;
}

int GetTotalMails(string username)
{
	fstream totalMails;
	string fileName = username + "/totalMails.txt";
	string buffer = "";
	int cnt = 0;
	totalMails.open(fileName, fstream::out | fstream::app);

	if (!totalMails.is_open())
	{
		cout << "Error loading mails count. Please, try again later.";
		return -1;
	}

	totalMails.close();

	totalMails.open(fileName, fstream::in);
	while (getline(totalMails, buffer))
	{
		cnt++;
	}

	totalMails.close();
	return cnt;
}