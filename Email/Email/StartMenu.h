#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

void UsersInfoToMap(map<string, string>&);
int StartMenuScreen(const map<string, string>&, string&, string&);
bool Login(const map<string, string>&, string&, string&);