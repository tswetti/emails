#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isSuccessfulRegistration(map<string, string>&, string&, string&);
bool createDirectory(const string&);
void saveNewUser(map<string, string>&, const string&, const string&);
