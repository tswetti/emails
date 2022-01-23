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
* This is the header file for LoadEmail.cpp
*
*/

#pragma once

#include <string>
#include <map>

using namespace std;

void loadEmailApp();
void usersInfoToMap(map<string, string>&);
char* stringToArray(const string&);