#include "SendMail.h"
#include "MainMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int SendMail(const string& username, const map<string, string>& users)
{
	string recipient, subject, content;
	getNewMailInfo(username, recipient, subject, content, users);

	int recMails = GetTotalMails(recipient);

	NewMailNotification(username, recipient);
	
	AddNewMailInfo(username, recipient, recMails, subject, content);

	return 0;
}

void getNewMailInfo(const string& sender, string& recipient, string& subject, string& content, const map<string, string>& users)
{
	bool match = false;
	bool sameUser = false;
	do
	{
		cout << "To: ";
		cin >> recipient;
		sameUser = false;

		for (auto& pair : users)
		{
			if (sender == recipient)
			{
				sameUser = true;
				break;
			}
			if (recipient == pair.first)
			{
				match = true;
				break;
			}
		}

		if (sameUser)
		{
			cout << "Can't send mails to yourself!" << endl;
		}
		else if (!match)
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

void NewMailNotification(const string& username, const string& recipient)
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