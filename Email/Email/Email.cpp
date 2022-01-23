#include "StartMenu.h"
#include "MainMenu.h"
#include "Validation.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	if (!isValidUsersFile())
	{
		cout << "An error has occured. Please, start the application later.";
		return 1;
	}

	string username = "", password = "";

	map<string, string> usersPass;
	usersInfoToMap(usersPass);		// add users' usernames and hashed passwords to the map

	int mainMenuRes = 1;

	do
	{
		int startMenuRes = startMenuScreen(usersPass, username, password);
		if (startMenuRes == 1)		// 1 is code for an error or quit command
		{
			break;
		}

		mainMenuRes = mainMenuScreen(username, password, usersPass);
		while (mainMenuRes == 2)	// 2 is code for going back to the main menu
		{
			cout << endl << "You are back to the main menu!" << endl;
			mainMenuRes = mainMenuScreen(username, password, usersPass);
		}
	}
	while (mainMenuRes == 0);		// 0 is code for going from main menu to start menu

	cout << endl << "Thank you for using this application!";
	return 0;
}