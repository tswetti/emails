#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

int StartMenuScreen(map<string, string>&, string&, string&);
void printStartMenuGuide();
void UsersInfoToMap(map<string, string>&);
char* StringToArray(const string&);