#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int StartMenu();

int StartMenu()
{
	//fstream users;
	//users.open("users.txt", fstream::in);

	char command;

	cout << "Type a command: ";
	do
	{
		cin >> command;
		if (command == 'L')
		{
			return 0;
		}
		else if (command == 'R')
		{
			return 0;
		}
		else if (command == 'Q')
		{
			//users.close();
			return 1;
		}
		else 
		{
			cout << "Invalid command! Try again: ";
		}
	} while (true);
}

int main()
{
	if (StartMenu() == 1)
	{
		return 1;
	}

	return 0;
}