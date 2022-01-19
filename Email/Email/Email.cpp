#include "StartMenu.h"
#include "Registration.h"
#include "MainMenu.h"
#include "CloseAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string username = "", password = "";
	map<string, string> usersPass;

	UsersInfoToMap(usersPass);

	int mainMenuRes = 5;
	do
	{
		int startMenuRes = StartMenuScreen(usersPass, username, password);
		if (startMenuRes == 1)
		{
			return 1;
		}
		else if (startMenuRes == 2)
		{
			cout << endl << "Welcome back, " << username << '!' << endl;
		}
		else if (startMenuRes == 3)
		{
			cout << endl << "Welcome, " << username << '!' << endl;
		}

		mainMenuRes = MainMenu(username, password, usersPass);
		while (mainMenuRes == 2)
		{
			mainMenuRes = MainMenu(username, password, usersPass);
		}
	} while (mainMenuRes == 1);
	/*if (mainMenuRes == 1)
	{
		StartMenuScreen(usersPass, username, password);
	}
	else if (mainMenuRes == 2)
	{
		MainMenu(username, password, usersPass);
	}*/

	return 0;
}