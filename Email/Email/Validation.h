#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool validateUsersFile();
bool isValidCommandLength(char&);
bool isLowercaseLetter(const char&);
bool isUppercaseLetter(const char&);
bool isDigit(const char&);
bool isAllowedSpecialSymbol(const char&);
bool isValidStrInput(const string&);
bool isValidPassword(const string&);
bool isValidUsername(const map<string, string>&, const string&);
