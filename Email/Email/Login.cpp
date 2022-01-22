#include "Login.h"
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>	// used for hashing

using namespace std;

bool isSuccessfulLogin(const map<string, string>& userInfo, string& username, string& password)
{
	const int MAX_ATTEMPTS = 3;
	hash<string> passHash;

	for (int i = 0; i < MAX_ATTEMPTS; i++)
	{
		cout << "Type your username: ";
		cin >> username;

		if (username == "Q" || username == "q")
		{
			return false;
		}

		cout << "Type your password: ";
		cin >> password;

		if (password == "Q" || password == "q")
		{
			return false;
		}

		password = to_string(passHash(password));

		for (auto pair : userInfo)
		{
			if (pair.first == username && pair.second == password)
			{
				cout << "Successful login!" << endl;
				return true;
			}
		}
		cout << "Unsuccessful login." << endl;
	}

	cout << "Your username or password was wrong 3 times. Please, try logging in later." << endl;
	return false;
}