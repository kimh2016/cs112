/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin University.
 *      Created on: Oct 22, 2021
 *      Author: Hansol Kim
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
	void testInequality() const;
	void testReadFromStream() const;
	void testWriteToStream();
	void testReadFromString();
	void testWriteToString();
	void testPrepend();
	void testGetIndexOf();
	void testInsertion();
	void testRemove();
	void testOutput();
	void testInsertAfter();
	void testInsertBefore();
};

#endif /*LISTTESTER_H_*/
