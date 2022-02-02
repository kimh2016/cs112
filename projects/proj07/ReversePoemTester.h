/*
 * ReversePoemTester.h declares test methods.
 *
 *  Created on: Nov 1, 2021
 *      Author: Hansol Kim hk94
 */

#ifndef REVERSEPOEMTESTER_H_
#define REVERSEPOEMTESTER_H_

#include "Stack.h"

class ReversePoemTester {
public:
	void runTests();
	void testConstructors();
	void testGetTitle();
	void testGetAuthor();
	void testGetBody();
	void testGetBodyReversed();

};

#endif /* REVERSEPOEMTESTER_H_ */
