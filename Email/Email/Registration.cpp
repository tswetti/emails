#include "LoadEmail.h"
#include "Registration.h"
#include "Validation.h"
#include "StartMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>	// used for hashing

// used for creating directories
#ifdef _WIN32
#include <direct.h>	
#else
#include <sys/types.h>
#include <sys/stat.h>
#endif

using namespace std;

bool isSuccessfulRegistration(map<string, string>& usersInfo, string& username, string& password)
{
	do
	{
		cout << "Type a username: ";
		cin >> username;

		if (username == "Q" || username == "q")
		{
			return false;
		}
	}
	while (!isValidUsername(usersInfo, username));

	do
	{
		cout << "Type a password: ";
		cin >> password;

		if (password == "Q" || password == "q")
		{
			return false;
		}
	}
	while (!isValidPassword(password));

	hash<string> passHash;
	password = to_string(passHash(password));

	if (!createDirectory(username))
	{
		cout << "Unable to create a directory. Registration failed." << endl;
		return false;
	}

	saveNewUser(usersInfo, username, password);

	cout << "Successful registration!" << endl;
	return true;
}

bool createDirectory(const string& username)
{
	#if _WIN32
	char* directoryName = stringToArray(username);
	if (directoryName == nullptr || _mkdir(directoryName) != 0)
	{
		delete[] directoryName;
		return false;
	}
	delete[] directoryName;

	#else
	const int status = mkdir(username, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (status == -1)
	{
		return false;
	}
	#endif

	return true;
}

void saveNewUser(map<string, string>& usersInfo, const string& username, const string& password)
{
	ofstream users;
	users.open("users.txt", fstream::app);
	users << username << ':' << password << endl;
	users.close();

	usersInfo.insert(pair<string, string>(username, password));
}