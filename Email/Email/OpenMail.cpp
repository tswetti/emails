#include "OpenMail.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void OpenMail(const string& username)
{
	int mail;
	cout << "Which mail do you want to open? ";
	cin >> mail;
	string fileName = username + "/" + to_string(mail) + ".txt";
	string buffer = "";
	fstream mailInfo;
	mailInfo.open(fileName, fstream::in);

	for (int i = 0;i < 3;i++)
	{
		if (i == 0)
		{
			getline(mailInfo, buffer);
			cout << "From: " << buffer << endl;
		}
		if (i == 1)
		{
			getline(mailInfo, buffer);
			cout << "Subject: " << buffer << endl;
		}
		if (i == 2)
		{
			getline(mailInfo, buffer);
			cout << "Content: " << buffer << endl;
		}
	}

	mailInfo.close();
}