#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool Registration(map<string, string>&, string&, string&);
bool isValidPassword(const string&);
bool isValidUsername(const map<string, string>&, const string&);
bool CreateDirectory(const string&);
void SaveNewUser(map<string, string>&, const string&, const string&);
bool isLowercaseLetter(const char&);
bool isUppercaseLetter(const char&);
bool isDigit(const char&);
bool isAllowedSpecialSymbol(const char&);
