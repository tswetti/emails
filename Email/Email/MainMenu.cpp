#include "MainMenu.h"
#include "StartMenu.h"
#include "CloseAccount.h"
#include "SendMail.h"
#include "Inbox.h"
#include "OpenMail.h"
#include "Validation.h"
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
	char command = '\0';

	do
	{
		if (!isValidCommandLength(command))
		{
			cout << "The command should consist of one letter only. " << endl << "Please, try again: ";
			continue;
		}

		if (command == 'C' || command=='c')
		{
			if (CloseAccount(username, password, userInfo) == false)
			{
				return 0;
			}
			username = "";
			password = "";
			cout << endl;
			cin.ignore();
			return 1;
		}
		else if (command == 'I' || command =='i')
		{
			PrintMailsSubject(username, mails);
			cout << endl;
			if (goToMainMenu())
			{
				return 2;
			}
			return 0;
		}
		else if (command == 'L' || command=='l')
		{
			username = "";
			password = "";
			cout << "You logged out successfully!" << endl;
			return 1;
		}
		else if (command == 'O' || command =='o')
		{
			if (!OpenMail(username, mails))
			{
				cout << "No such mail!" << endl;
			}
			cout << endl;
			cin.ignore();
			if (goToMainMenu())
			{
				return 2;
			}
			return 0;
		}
		else if (command == 'S' || command=='s')
		{
			int sendRes = SendMail(username, userInfo);
			cout << "Message sent successfully!" << endl;
			if (goToMainMenu())
			{
				return 2;
			}
			return 0;
		}
		else if (command == 'Q' || command=='q')
		{
			return 0;
		}
		else
		{
			cout << "Invalid command! Please, try again: ";
		}
	} while (true);

	return 0;
}

void PrintMainMenuGuide(const int& mails)
{
	cout << "You have " << mails;
	cout << ((mails == 1) ? " mail. " : " mails. ");
	cout << "Choose one of the following options: " << endl;
	cout << "C - close account" << endl
		<< "I - inbox" << endl
		<< "L - logout" << endl
		<< "O - open" << endl
		<< "S - send" << endl
		<< "Q - quit" << endl
		<< endl;
}

int GetTotalMails(const string& username)
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