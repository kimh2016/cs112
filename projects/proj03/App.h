/*
 * App.h declares the application class called App.
 *
 * Student Name: Hansol Kim (hk94)
 * Date: September 21, 2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef APP_H_
#define APP_H_

#include "Vec.h"

class App {
public:
	App();
	void run();

private:
	unsigned printInstructions();
	Vec getStartingPosition(unsigned numDims);
	Vec getVectors(const Vec & startVec);
	void printResults(const Vec &start, const Vec &end);
	Vec getVectorFromUser(unsigned numDims);
};

#endif /* APP_H_ */
