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
* This is the header file for SendMail.cpp
*
*/

#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isSentMail(const string&, const map<string, string>&);
bool getNewMailInfo(const string&, string&, string&, string&, const map<string, string>&);
void newMailNotification(const string&, const string&);
void addNewMailInfo(const string&, const string&, int&, const string&, const string&);