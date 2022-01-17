#include "Inbox.h"
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

void PrintMailsSubject(string username, int mails)
{
	for (int i = 1; i <= mails; i++)
	{
		PrintOneMail(username, i);
		cout << endl;
	}
}

void PrintOneMail(string username, int mail)
{
	string fileName = username + "/" + to_string(mail) + ".txt";
	fstream mailInfo;
	mailInfo.open(fileName, fstream::in);
	string buffer = "";
	for (int i = 0;i < 2;i++)
	{
		getline(mailInfo, buffer);
	}
	cout << mail << ": " << buffer;
}