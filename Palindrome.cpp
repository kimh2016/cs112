/*
 * Palindrome.cpp
 *
 * Created on: November 14, 2021
 * Author: Hansol Kim
 */


#include "PalindromeTester.h"
#include <cctype>

/*
 * Constructor
 * parameters: string fileNameIn, string fileNameOut
 * FileIn holds value of fileNameIn
 * FileOut holds values of fileNameOut
 */
PalindromeChecker::PalindromeChecker(const string& fileNameIn, const string& fileNameOut) {
	FileIn = fileNameIn;
	FileOut = fileNameOut;
	palindromeDetector(FileIn, FileOut);
}

/*
 * isPalindrome
 * parameters: string palindrome
 * This method converts strings into lower case
 * pushes it onto a stack; and appends it to a
 * queue. It also pops a char from the stack
 * into ch1; removes a char from the queue into
 * char2; and if char1 and ch2 are different, then
 * returns false.
 */
bool PalindromeChecker::isPalindrome(const string& palindrome) {
	if (palindrome.length() == 0) {
		return false;
	}
	Stack<char> s1(1);
	ArrayQueue<char> q1(1);

	for (unsigned i = 0; i < palindrome.length(); i++) {
		if (isalpha(palindrome[i])) {
			try {
				q1.append(tolower(palindrome[i]));
			} catch (FullQueueException& se) {
				q1.setCapacity(q1.getCapacity() * 2);
				q1.append(tolower(palindrome[i]));
			}
			try {
				s1.push(tolower(palindrome[i]));
			} catch (StackException& se) {
				s1.setCapacity(s1.getCapacity() * 2);
				s1.push(tolower(palindrome[i]));
			}
		}
	}

	char ch1;
	char ch2;
	unsigned length = q1.getSize();

	for (unsigned i = 0; i < length; i++) {
		ch1 = s1.pop();
		ch2 = q1.remove();
		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}

/*
 * palindromeDetector
 * parameters: string fileNameIn, string fileNameOut
 * Reads lines and the strings that are palindromes
 * are detected and are written in the ouput file
 * with ***.
 */
void PalindromeChecker::palindromeDetector(const string& fileNameIn, const string& fileNameOut) {
	ifstream fin(fileNameIn);
		ofstream fout(fileNameOut);
		string tempStr;
		while (fin) {
			getline(fin, tempStr);

			if (isPalindrome(tempStr)) {
				fout << tempStr + " ***" << endl;
			} else {
				fout << tempStr << endl;
			}
		}
		fin.close();
		fout.close();
	}














