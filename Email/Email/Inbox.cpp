/**
*
* Solution to course project # 03
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Tsvetelina Tsvetanova
* @idnumber 3MI0600034
* @compiler VC
*
* This is the inbox functionality which allows users to see their mails' numbers and subjects in ascending order by number
*
*/

#include "Inbox.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printMailsSubject(const string& username, const int& mails)
{
	if (mails == 0)
	{
		cout << "You have no mails!" << endl;
		return;
	}

	for (int i = 1; i <= mails; i++)
	{
		if (!printOneMail(username, i))
		{
			continue;
		}
		cout << endl;
	}
}

bool printOneMail(const string& username, const int& mail)
{
	const int SUBJECT_LINE = 2;

	string fileName = username + '/' + to_string(mail) + ".txt";
	string buffer = "";

	ifstream mailInfo;
	mailInfo.open(fileName);

	if (!mailInfo.is_open())
	{
		return false;
	}

	for (int i = 0; i < SUBJECT_LINE; i++)
	{
		getline(mailInfo, buffer);
	}

	cout << mail << ": " << buffer;

	return true;
}