#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CloseAccount(const string&, const string&, map<string, string>&);
bool DeleteDirectory(const string&);
void RewriteFile(const string&, const string&);