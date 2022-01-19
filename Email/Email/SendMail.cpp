#include "SendMail.h"
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

int SendMail(const string& username, const map<string, string>& users)
{
	string recipient, subject, content;
	getNewMailInfo(recipient, subject, content, users);

	int recMails = GetTotalMails(recipient);

	NewMailToMailCnt(username, recipient);
	
	AddNewMailInfo(username, recipient, recMails, subject, content);

	return 0;
}

void getNewMailInfo(string& recipient, string& subject, string& content, const map<string, string>& users)
{
	bool match = false;
	do
	{
		cout << "To: ";
		cin >> recipient;

		for (auto& pair : users)
		{
			if (recipient == pair.first)
			{
				match = true;
				break;
			}
		}

		if (!match)
		{
			cout << "No such user!";
		}
	} while (!match);

	cout << "Subject: ";
	cin.ignore();
	getline(cin, subject);
	cout << "Content: ";
	getline(cin, content);
}

void NewMailToMailCnt(const string& username, const string& recipient)
{
	string recFileName = recipient + "/totalMails.txt";
	fstream newMail;
	newMail.open(recFileName, fstream::out | fstream::app);
	newMail << "New mail from " << username << "!" << endl;
	newMail.close();
}

void AddNewMailInfo(const string& username, const string& recipient, int& mails, const string& subject, const string& content)
{
	fstream newMailInfo;
	string recFileName = recipient + "/" + to_string(++mails) + ".txt";
	newMailInfo.open(recFileName, fstream::out);
	newMailInfo << username << endl << subject << endl << content << endl;
	newMailInfo.close();
}