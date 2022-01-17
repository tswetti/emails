#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

int SendMail(string, map<string, string>);
void getNewMailInfo(string&, string&, string&, map<string, string>);
void NewMailToMailCnt(string, string);
void AddNewMailInfo(string, string, int&, string, string);