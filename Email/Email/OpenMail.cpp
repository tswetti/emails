#include "OpenMail.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isOpenMail(const string& username, const int& mailsCnt)
{
	const int SENDER_LINE = 0, SUBJECT_LINE = 1, CONTENT_LINE = 2;
	int mail;

	cout << "Which mail do you want to open? ";
	cin >> mail;

	if (mail > mailsCnt)
	{
		return false;
	}

	string fileName = username + '/' + to_string(mail) + ".txt";
	string buffer = "";

	ifstream mailInfo;
	mailInfo.open(fileName);

	if (!mailInfo.is_open())
	{
		return false;
	}

	cout << endl;

	for (int i = 0; i < CONTENT_LINE + 1; i++)
	{
		if (i == SENDER_LINE)
		{
			getline(mailInfo, buffer);
			cout << "From: " << buffer << endl;
		}
		if (i == SUBJECT_LINE)
		{
			getline(mailInfo, buffer);
			cout << "Subject: " << buffer << endl;
		}
		if (i == CONTENT_LINE)
		{
			getline(mailInfo, buffer);
			cout << "Content: " << buffer << endl;
		}
	}

	mailInfo.close();
	return true;
}