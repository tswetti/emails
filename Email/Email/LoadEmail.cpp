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
* This file contains the function which manages the other two main functions. It also contains two functions which are not specific to another functionality
*
*/

#include "LoadEmail.h"
#include "StartMenu.h"
#include "MainMenu.h"
#include "Validation.h"

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

void loadEmailApp()
{
	if (!validateUsersFile())
	{
		cout << "An error has occured. Please, open the application later.";
		return;
	}

	string username = "", password = "";

	map<string, string> usersPass;
	usersInfoToMap(usersPass);		// add users' usernames and hashed passwords to the map

	int mainMenuRes = 1;

	do
	{
		int startMenuRes = startMenuScreen(username, password, usersPass);
		if (startMenuRes == 1)		// 1 is code for an error or quit command
		{
			break;
		}

		do
		{
			mainMenuRes = mainMenuScreen(username, password, usersPass);
		}
		while (mainMenuRes == 2);	// 2 is code for going back to the main meu
	}
	while (mainMenuRes == 0);		// 0 is code for going from main menu to start menu

	cout << endl << "Thank you for using this application!";
	return;
}

void usersInfoToMap(map<string, string>& info)
{
	string key, value, buffer, fileName = "users.txt";
	const char DELIMITER = ':';

	ifstream usersInfo;
	usersInfo.open(fileName);

	while (getline(usersInfo, buffer))
	{
		key = buffer.substr(0, buffer.find(DELIMITER));		// get the username which stops at :
		value = buffer.substr(buffer.find(DELIMITER) + 1);	// get the hashed password which starts right after :

		info.insert(pair<string, string>(key, value));
	}
	usersInfo.close();
}

char* stringToArray(const string& str)
{
	int cnt = 0;
	int newLength = str.length() + 1;

	char* arr = new char[newLength];
	for (int i = 0; i < newLength - 1; i++)
	{
		arr[i] = str[cnt++];
	}

	arr[cnt] = '\0';

	return arr;
}