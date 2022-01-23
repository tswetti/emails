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
* This is the header file for Validation.cpp
*
*/

#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool validateUsersFile();
bool isValidCommandLength(char&);
bool isLowercaseLetter(const char&);
bool isUppercaseLetter(const char&);
bool isDigit(const char&);
bool isAllowedSpecialSymbol(const char&);
bool isValidStrInput(const string&);
bool isValidPassword(const string&);
bool isValidUsername(const map<string, string>&, const string&);