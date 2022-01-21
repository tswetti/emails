#include "StartMenu.h"
#include "MainMenu.h"
#include "Validation.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ValidateUsersFile();
	string username = "", password = "";
	map<string, string> usersPass;

	UsersInfoToMap(usersPass);

	int mainMenuRes = 0;
	do
	{
		int startMenuRes = StartMenuScreen(usersPass, username, password);
		if (startMenuRes == 1)
		{
			return 1;
		}

		mainMenuRes = MainMenu(username, password, usersPass);
		while (mainMenuRes == 2)
		{
			mainMenuRes = MainMenu(username, password, usersPass);
		}
	} while (mainMenuRes == 1);

	return 0;
}