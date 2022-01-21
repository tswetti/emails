#include "Login.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

bool isLoggedIn(const map<string, string>& userInfo, string& username, string& password)
{
	const int MAX_ATTEMPTS = 3;
	for (int i = 0; i < MAX_ATTEMPTS; i++)
	{
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
				cout << "Successful login!" << endl;
				return true;
			}
		}
		cout << "Unsuccessful login." << endl;
		username = "";
		password = "";
	}
	cout << "Your username or password was wrong 3 times. Please, try logging in later." << endl;
	return false;
}