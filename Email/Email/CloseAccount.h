#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool closeAccount(const string&, const string&, int&, map<string, string>&);
bool deleteDirectory(const string&, int&);
bool rewriteFile(const string&, const string&);
bool deleteAllUserMails(const string&, int&);
bool deleteTotalMailsFile(const string&);