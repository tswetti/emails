#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

int startMenuScreen(map<string, string>&, string&, string&);
void printStartMenuGuide();
void usersInfoToMap(map<string, string>&);
char* stringToArray(const string&);