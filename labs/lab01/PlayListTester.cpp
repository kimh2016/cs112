/*
 * PlayListTester.cpp defines the PlayList test-methods.
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 4 2021
 * Begun by: Hansol Kim, for CS 112 lab at Calvin University.
 */


#include "PlayListTester.h"
#include <iostream>
#include <cassert>
#include "PlayList.h"
using namespace std;

void PlayListTester::testConstructors() {
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );
	cout << " 0 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::runTests() {
	cout << "Testing class PlayList..." << endl;
	testConstructors();
	cout << "All tests passed!" << endl;
}


