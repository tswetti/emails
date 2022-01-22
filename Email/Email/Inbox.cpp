#include "Inbox.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintMailsSubject(const string& username, const int& mails)
{
	if (mails == 0)
	{
		cout << "You have no mails!" << endl;
		return;
	}

	for (int i = 1; i <= mails; i++)
	{
		PrintOneMail(username, i);
		cout << endl;
	}
}

void PrintOneMail(const string& username, const int& mail)
{
	const int SUBJECT_LINE = 2;
	string fileName = username + "/" + to_string(mail) + ".txt";
	string buffer = "";

	ifstream mailInfo;
	mailInfo.open(fileName);

	for (int i = 0; i < SUBJECT_LINE; i++)
	{
		getline(mailInfo, buffer);
	}
	cout << mail << ": " << buffer;
}