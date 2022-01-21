#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CloseAccount(const string&, const string&, map<string, string>&);
bool DeleteDirectory(const string&);
bool RewriteFile(const string&, const string&);
bool DeleteAllUserMails(const string&);
bool DeleteTotalMailsFile(const string&);
char* StringToArray(const string&);