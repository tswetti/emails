#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int StartMenu(map<string, string>);
bool Login(map<string, string>);

int StartMenu(map<string, string> loginInfo)
{
	int loginAttempts = 1, maxAttempts = 3;
	char command;
	cout << "Type a command: ";

	do
	{
		cin >> command;
		if (command == 'L')
		{
			cout << endl;
			while (maxAttempts >= loginAttempts++ && !Login(loginInfo));
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

bool Login(map<string, string> userInfo)
{
	string username, password;
	bool match = false;

	cout << "Type your username: ";
	cin >> username;
	cout << "Type your password: ";
	cin >> password;

	for (auto& pair : userInfo)
	{
		if (pair.first == username && pair.second == password)
		{
			match = true;
			break;
		}
	}

	if (match)
	{
		cout << "Successful login!" << endl;
		return true;
	}
	else
	{
		cout << "Unsuccessful login. Try again!" << endl;
		return false;
	}
}

int main()
{
	fstream users;
	users.open("users.txt", fstream::in);

	map<string, string> userPass;
	string username, password, buffer;
	const char DELIMITER = ':';

	while (getline(users, buffer))
	{
		username = buffer.substr(0, buffer.find(DELIMITER));
		password = buffer.substr(buffer.find(DELIMITER) + 1);
		userPass.insert(pair<string, string>(username, password));
	}

	users.close();

	/*for (auto& t : userPass)
	{
		cout << t.first << " "
			<< t.second << " "
			<< "\n";
	}*/

	if (StartMenu(userPass) == 1)
	{
		return 1;
	}

	return 0;
}