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
* This is the header file for MainMenu.cpp
*
*/

#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

int mainMenuScreen(string&, string&, map<string, string>&);
int getTotalMails(const string&);
void printMainMenuGuide(const int&);
bool goToMainMenu();