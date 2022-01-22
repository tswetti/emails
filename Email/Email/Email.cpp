#include "StartMenu.h"
#include "MainMenu.h"
#include "Validation.h"
#include <iostream>
#include <string>
#include <map>

/*#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif*/

using namespace std;

int main()
{
	if (!isValidUsersFile())
	{
		cout << "An error occured. Please, start the application later.";
		return 1;
	}

	string username = "", password = "";

	map<string, string> usersPass;
	UsersInfoToMap(usersPass);

	int mainMenuRes = 1;
	do
	{
		int startMenuRes = StartMenuScreen(usersPass, username, password);
		if (startMenuRes == 1)
		{
			break;
		}

		mainMenuRes = MainMenu(username, password, usersPass);
		while (mainMenuRes == 2)
		{
			cout << endl << "You are back to the main menu!" << endl;
			mainMenuRes = MainMenu(username, password, usersPass);
		}
	}
	while (mainMenuRes == 0);

	cout << endl << "Thank you for using this application!";
	return 0;
}