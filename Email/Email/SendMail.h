#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isSentMail(const string&, const map<string, string>&);
bool getNewMailInfo(const string&, string&, string&, string&, const map<string, string>&);
void newMailNotification(const string&, const string&);
void addNewMailInfo(const string&, const string&, int&, const string&, const string&);