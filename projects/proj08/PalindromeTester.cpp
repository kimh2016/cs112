/*
 * PlindromeTester.cpp
 *
 *  Created on: Nov 14, 2021
 *  Author: Hansol Kim
 */

#include "PalindromeTester.h"
#include <cassert>


void PalindromeTester::runTests() {
	cout << "Testing class PalindromeDetector..." << endl;
	testIsPalindrome();
	testPalindromeDetector();
	cout << "All tests passed!\n" << endl;
}

void PalindromeTester::testIsPalindrome() {

	cout << "- testing isPalindrome... " << flush;
	// Check various ways of palindrome that can be done
	PalindromeChecker p("In.txt", "Out.txt");
	assert(!p.isPalindrome(""));
	cout << " 0 " << flush;
	string p1 = "madam";
	assert(p.isPalindrome(p1));
	cout << " 1 " << flush;
	string p2 = "ma dam";
	assert( p.isPalindrome(p2) );
	cout << " 2 " << flush;
	string p3 = "MA Dam";
	assert(p.isPalindrome (p3));
	cout << " 3 " << flush;
	string p4 = "bore two sons";
	assert( !p.isPalindrome(p4) );
	cout << " 4 " << flush;
	cout << "Passed!" << endl;
}

void PalindromeTester::testPalindromeDetector() {
	cout << "- testing palindromeDetector... " << flush;
	PalindromeChecker p("wordsIn.txt", "wordsOut.txt");
		ifstream fin("wordsIn.txt");
		ifstream fout("wordsOut.txt");
		string tempStrIn, tempStrOut;

		// Add *** on palindromes
		while (fin) {
			getline(fin, tempStrIn);
			getline(fout, tempStrOut);
			if (p.isPalindrome(tempStrIn)) {
				assert( tempStrOut == tempStrIn + " ***" );
			} else if (!p.isPalindrome(tempStrIn)) {
				assert( tempStrOut == tempStrIn + "" );
			} else {
				assert( false );
			}
		}

		fin.close();
		fout.close();
		cout << " Passed!" << endl;
	}
