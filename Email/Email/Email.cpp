#include "StartMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

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

	if (StartMenuScreen(userPass) == 1)
	{
		return 1;
	}

	return 0;
}