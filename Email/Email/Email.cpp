#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int StartMenu();
int Login();

int StartMenu()
{
	char command;
	cout << "Type a command: ";

	do
	{
		cin >> command;
		if (command == 'L')
		{
			cout << endl;
			Login();
			return 0;
		}
		else if (command == 'R')
		{
			return 0;
		}
		else if (command == 'Q')
		{
			return 1;
		}
		else 
		{
			cout << "Invalid command! Try again: ";
		}
	} while (true);
}

int Login()
{
	string username, password, buffer;
	const char DELIMITER = ':';
	int position = 0, positionPass = 0;
	bool match = true;

	cout << "Type your username: ";
	cin >> username;

	cout << "Type your password: ";
	cin >> password;

	fstream users;
	users.open("users.txt", fstream::in);

	while (getline(users, buffer))
	{
		while(buffer[position] != DELIMITER)
		{
			if (buffer[position] != username[position++])
			{
				match = false;
				break;
			}
		}

		position++;

		while (match && buffer[position] != '\0')
		{
			if (buffer[position++] != password[positionPass++])
			{
				match = false;
				break;
			}
		}

		if (match)
		{
			cout << "Login successful!";
			return 1;
		}
	}

	cout << "Login unsuccessful!";
	users.close();
	return 0;

}

int main()
{
	if (StartMenu() == 1)
	{
		return 1;
	}

	return 0;
}