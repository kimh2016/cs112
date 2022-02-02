/*
 * main.cpp
 * Student Name and UserId: Hansol Kim hk94
 * Date: Sep 4, 2021
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 */

#include "SongTester.h"
#include "PlayListTester.h"
#include "Application.h"
#include <iostream>

int main() {
	SongTester sTester;
	sTester.runTests();
	PlayListTester plTester;
	plTester.runTests();
	Application app;
	app.run();
}



