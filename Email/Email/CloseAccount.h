#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CloseAccount(const string&, const string&, int&, map<string, string>&);
bool DeleteDirectory(const string&, int&);
bool RewriteFile(const string&, const string&);
bool DeleteAllUserMails(const string&, int&);
bool DeleteTotalMailsFile(const string&);