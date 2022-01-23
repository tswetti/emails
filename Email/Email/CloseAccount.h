/**
*
* Solution to course project # 03
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Tsvetelina Tsvetanova
* @idnumber 3MI0600034
* @compiler VC
*
* This is the header file for CloseAccount.cpp
*
*/

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