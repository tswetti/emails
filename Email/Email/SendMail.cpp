#include "SendMail.h"
#include "MainMenu.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

bool isSentMail(const string& username, const map<string, string>& users)
{
	string recipient, subject, content;

	if (!getNewMailInfo(username, recipient, subject, content, users))
	{
		return false;
	}

	int recMails = getTotalMails(recipient);

	addNewMailInfo(username, recipient, recMails, subject, content);

	newMailNotification(username, recipient);

	cout << "Message sent successfully!" << endl;
	return true;
}

bool getNewMailInfo(const string& sender, string& recipient, string& subject, string& content, const map<string, string>& users)
{
	bool match = false;
	bool sameUser = false;

	do
	{
		cout << "To: ";
		cin >> recipient;

		if (recipient == "Q" || recipient == "q")
		{
			return false;
		}

		cin.ignore();
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
			cout << "Sender and recipient cannot be the same person!" << endl;
		}
		else if (!match)
		{
			cout << "No such user!" << endl;
		}
	}
	while (!match);

	do
	{
		cout << "Subject: ";
		getline(cin, subject);

		if (subject.empty() || !isValidStrInput(subject))
		{
			cout << "Subject can't be empty or have invalid characters!" << endl;
		}
	}
	while (subject.empty() || !isValidStrInput(subject));

	cout << "Content: ";
	getline(cin, content);

	return true;
}

// update the recipients log file that they received a new mail
void newMailNotification(const string& username, const string& recipient)
{
	string recFileName = recipient + "/totalMails.txt";

	ofstream newMail;
	newMail.open(recFileName, fstream::app);

	newMail << "New mail from " << username << "!" << endl;

	newMail.close();
}

// add the new mail to the recipient's directory
void addNewMailInfo(const string& username, const string& recipient, int& mails, const string& subject, const string& content)
{
	string recFileName = recipient + "/" + to_string(++mails) + ".txt";

	ofstream newMailInfo;
	newMailInfo.open(recFileName);

	newMailInfo << username << endl << subject << endl << content << endl;

	newMailInfo.close();
}