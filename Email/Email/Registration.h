#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isSuccessfulRegistration(map<string, string>&, string&, string&);
bool CreateDirectory(const string&);
void SaveNewUser(map<string, string>&, const string&, const string&);
