/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin University.
 *      Created on: Oct 5, 2021
 *      Author: Hansol Kim, Afua Brantuo
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
};

#endif /*LISTTESTER_H_*/
