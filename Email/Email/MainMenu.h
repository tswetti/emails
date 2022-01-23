#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

int mainMenuScreen(string&, string&, map<string, string>&);
int getTotalMails(const string&);
void printMainMenuGuide(const int&);
bool goToMainMenu();