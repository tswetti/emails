#include "MainMenu.h"
#include "StartMenu.h"
#include "CloseAccount.h"
#include "SendMail.h"
#include "Inbox.h"
#include "OpenMail.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int mainMenuScreen(string& username, string& password, map<string, string>& userInfo)
{
	const char	CLOSE_UPPER = 'C', CLOSE_LOWER = 'c',
				INBOX_UPPER = 'I', INBOX_LOWER = 'i',
				LOG_OFF_UPPER = 'L', LOG_OFF_LOWER = 'l',
				OPEN_UPPER = 'O', OPEN_LOWER = 'o',
				SEND_UPPER = 'S', SEND_LOWER = 's',
				QUIT_UPPER = 'Q', QUIT_LOWER = 'q';

	int mails = getTotalMails(username);

	printMainMenuGuide(mails);

	cout << "Type a command: ";
	char command;

	do
	{
		if (!isValidCommandLength(command))
		{
			cout << "The command should consist of one letter only. " << endl << "Please, try again: ";
			continue;
		}

		if (command == CLOSE_UPPER || command == CLOSE_LOWER)
		{
			if (!closeAccount(username, password, mails, userInfo))
			{
				return 1;
			}

			cout << endl;
			cin.ignore();
			return 0;
		}
		else if (command == INBOX_UPPER || command == INBOX_LOWER)
		{
			printMailsSubject(username, mails);
			cout << endl;

			if (!goToMainMenu())
			{
				return 1;
			}
			return 2;
		}
		else if (command == LOG_OFF_UPPER || command == LOG_OFF_LOWER)
		{
			username = "";
			password = "";
			cout << "You logged out successfully!" << endl << endl;
			return 0;
		}
		else if (command == OPEN_UPPER || command == OPEN_LOWER)
		{
			if (!isOpenMail(username, mails))
			{
				cout << "No such mail!" << endl;
			}

			cout << endl;
			cin.ignore();

			if (!goToMainMenu())
			{
				return 1;
			}
			return 2;
		}
		else if (command == SEND_UPPER || command == SEND_LOWER)
		{
			if (!isSentMail(username, userInfo))
			{
				return 1;
			}

			cout << endl;

			if (!goToMainMenu())
			{
				return 1;
			}
			return 2;
		}
		else if (command == QUIT_UPPER || command == QUIT_LOWER)
		{
			return 1;
		}
		else
		{
			cout << "Invalid command! Please, try again: ";
		}
	} while (true);

	return 1;
}

void printMainMenuGuide(const int& mails)
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

int getTotalMails(const string& username)
{
	string fileName = username + "/totalMails.txt";
	string buffer = "";
	int cnt = 0;

	fstream totalMails;
	totalMails.open(fileName, fstream::in | fstream:: out | fstream::app);

	// every time a mail is sent, a new line is added to the totalMails file, thus the lines count is equal to the mails count
	while (getline(totalMails, buffer))
	{
		cnt++;
	}

	totalMails.close();
	return cnt;
}

bool goToMainMenu()
{
	const char	MENU_UPPER = 'M', MENU_LOWER = 'm',
				QUIT_UPPER = 'Q', QUIT_LOWER = 'q';
	char command;

	cout << "Press <M> to go back to the menu or <Q> to quit." << endl;

	do
	{
		if (!isValidCommandLength(command))
		{
			cout << "The command should consist of one letter only. " << endl << "Please, try again: ";
			continue;
		}

		if (command == MENU_UPPER || command == MENU_LOWER)
		{
			return true;
		}
		else if (command == QUIT_UPPER || command == QUIT_LOWER)
		{
			return false;
		}
		else
		{
			cout << "Invalid command! Please, try again: ";
		}
	} while (true);

	return false;
}