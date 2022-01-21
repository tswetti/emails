#include "Inbox.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void PrintMailsSubject(const string& username, const int& mails)
{
	for (int i = 1; i <= mails; i++)
	{
		PrintOneMail(username, i);
		cout << endl;
	}
}

void PrintOneMail(const string& username, const int& mail)
{
	string fileName = username + "/" + to_string(mail) + ".txt";
	fstream mailInfo;
	mailInfo.open(fileName, fstream::in);
	string buffer = "";
	for (int i = 0; i < 2; i++)
	{
		getline(mailInfo, buffer);
	}
	cout << mail << ": " << buffer;
}