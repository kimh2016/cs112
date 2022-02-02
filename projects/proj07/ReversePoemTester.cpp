/*
 * ReversePoemTester.cpp tests out methods of ReversePoem
 *
 *  Created on: Nov 1, 2021
 *      Author: Hansol Kim hk94
 */

#include "ReversePoemTester.h"
#include "ReversePoem.h"

void ReversePoemTester::runTests() {
	cout << "- Testing ReversePoem class... " << endl;
	testConstructors();
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
	cout << " All tests passed! " << endl;

}

void ReversePoemTester::testConstructors() {
	cout << "- Testing testConstructors... " << flush;

	// check fileNames
	ReversePoem r0("Poems/anorexia.txt");
	cout << " 0 " << flush;
	ReversePoem r1("Poems/cats.txt");
	cout << " 1 " << flush;
	ReversePoem r2("Poems/keepTheFaith.txt");
	cout << " 2 " << flush;
	ReversePoem r3("Poems/lostGeneration.txt");
	cout << " 3 " << flush;
	ReversePoem r4("Poems/love.txt");
	cout << " 4 " << flush;
	ReversePoem r5("Poems/ourGeneration.txt");
	cout << " 5 " << flush;
	ReversePoem r6("Poems/theKiss.txt");
	cout << " 6 " << flush;
	ReversePoem r7("Poems/worstDayEver.txt");
	cout << " 7 " << flush;

	cout << " Passed! " << endl;
}

void ReversePoemTester::testGetTitle() {
	cout << "- Testing getTitle()... " << flush;

	// Check titles
	ReversePoem r0("Poems/anorexia.txt");
	assert( r0.getTitle() == "Anorexia");
	cout << " 0 " << flush;
	ReversePoem r1("Poems/cats.txt");
	assert( r1.getTitle() == "Cats");
	cout << " 1 " << flush;
	ReversePoem r2("Poems/keepTheFaith.txt");
	assert( r2.getTitle() == "Keep The Faith");
	cout << " 2 " << flush;
	ReversePoem r3("Poems/lostGeneration.txt");
	assert( r3.getTitle() == "Lost Generation");
	cout << " 3 " << flush;
	ReversePoem r4("Poems/love.txt");
	assert( r4.getTitle() == "Love?");
	cout << " 4 " << flush;
	ReversePoem r5("Poems/ourGeneration.txt");
	assert( r5.getTitle() == "Our Generation");
	cout << " 5 " << flush;
	ReversePoem r6("Poems/theKiss.txt");
	assert( r6.getTitle() == "The Kiss");
	cout << " 6 " << flush;
	ReversePoem r7("Poems/worstDayEver.txt");
	assert( r7.getTitle() == "Worst Day Ever?");
	cout << " 7 " << flush;

	cout << " Passed! " << endl;

}

void ReversePoemTester::testGetAuthor() {
	cout << "- Testing getAuthor()... " << flush;

	// Check authors
	ReversePoem r0("Poems/anorexia.txt");
	assert( r0.getAuthor() == "Anonymous");
	cout << " 0 " << flush;
	ReversePoem r1("Poems/cats.txt");
	assert( r1.getAuthor() == "Leo J. Smada");
	cout << " 1 " << flush;
	ReversePoem r2("Poems/keepTheFaith.txt");
	assert( r2.getAuthor() == "Tiffany Cheung");
	cout << " 2 " << flush;
	ReversePoem r3("Poems/lostGeneration.txt");
	assert( r3.getAuthor() == "Jonathan Reed");
	cout << " 3 " << flush;
	ReversePoem r4("Poems/love.txt");
	assert( r4.getAuthor() == "Anonymous");
	cout << " 4 " << flush;
	ReversePoem r5("Poems/ourGeneration.txt");
	assert( r5.getAuthor() == "Jordan Nichols");
	cout << " 5 " << flush;
	ReversePoem r6("Poems/theKiss.txt");
	assert( r6.getAuthor() == "R. Lamoureux");
	cout << " 6 " << flush;
	ReversePoem r7("Poems/worstDayEver.txt");
	assert( r7.getAuthor() == "Chanie Gorkin");
	cout << " 7 " << flush;

	cout << " Passed! " << endl;
}

void ReversePoemTester::testGetBody() {
	cout << "- Testing getBody()... " << flush;

	// Check body
	ReversePoem r0("Poems/cats.txt");
	assert( r0.getBody() == "I love it when cats rub against me.\n"
			"I could never say\n"
			"I hate those purring felines.");
	cout << " 0 " << flush;

	cout << " Passed! " << endl;
}

void ReversePoemTester::testGetBodyReversed() {
	cout << "- Testing getBodyReversed()... " << flush;

	// Check body reversed
	ReversePoem r0("Poems/cats.txt");
	assert( r0.getBodyReversed() == "I hate those purring felines.\n"
			"I could never say\n"
			"I love it when cats rub against me.");
	cout << " 0 " << flush;

	cout << " Passed! " << endl;

}

