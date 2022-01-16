#include "MainMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int MainMenu(string username, string password)
{
	int totalEmails = GetTotalEmails(username);
	if (totalEmails == -1)
	{
		return 1;
	}

	cout << "You have " << totalEmails <<" mails. Choose one of the following options:"<< endl;
	cout << "C - close account" << endl
		<< "I - inbox" << endl
		<< "L - logout" << endl
		<< "O - open" << endl
		<< "S - send" << endl;

	return 0;
}

int GetTotalEmails(string username)
{
	fstream totalEmails;
	string fileName = username + "/totalEmails.txt";
	string buffer = "";
	int cnt = 0;
	totalEmails.open(fileName, fstream::in);

	if (!totalEmails.is_open())
	{
		cout << "Error loading total emails. Please, try again later.";
		return -1;
	}

	while (getline(totalEmails, buffer))
	{
		cnt++;
	}

	totalEmails.close();
	return cnt;
}

