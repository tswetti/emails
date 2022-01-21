#include "Login.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

bool Login(const map<string, string>& userInfo, string& username, string& password)
{
	bool match = false;

	cout << "Type your username: ";
	cin >> username;
	cout << "Type your password: ";
	cin >> password;

	hash<string> passHash;
	password = to_string(passHash(password));

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
		cout << "Unsuccessful login." << endl;
		username = "";
		password = "";
		return false;
	}
}