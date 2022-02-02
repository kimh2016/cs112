 /*
 * Palindrome.h
 *
 *  Created on: Nov 14, 2021
 *      Author: Hansol Kim
 */

#ifndef PALINDROMECHECKER_H_
#define PALINDROMECHECKER_H_

#include "Stack.h"
#include "ArrayQueue.h"
#include <fstream>
#include <cassert>
#include <cstdlib>
using namespace std;

class PalindromeChecker {
public:
	PalindromeChecker(const string& fileNameIn, const string& fileNameOut);
	void palindromeDetector(const string& fileNameIn, const string& fileNameOut);
	bool isPalindrome(const string& palindrome);
private:
	string FileIn;
	string FileOut;
};
#endif /* PALINDROME_H_ */
