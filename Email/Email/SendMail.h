#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

int SendMail(const string&, const map<string, string>&);
void getNewMailInfo(string&, string&, string&, const map<string, string>&);
void NewMailToMailCnt(const string&, const string&);
void AddNewMailInfo(const string&, const string&, int&, const string&, const string&);