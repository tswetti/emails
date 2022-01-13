#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool Registration(map<string, string>, string&, string&);
bool isValidPassword(string);
bool isValidUsername(map<string, string>, string);
bool CreateDirectory(string);
void SaveNewUser(map<string, string>&, string, string);
