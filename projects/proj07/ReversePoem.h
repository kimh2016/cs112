/*
 * ReversePoem.h declares test methods.
 *
 *  Created on: Nov 1, 2021
 *      Author: Hansol Kim hk94
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include "Stack.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>


class ReversePoem {
public:
	ReversePoem(const string& fileName);
	// getters return strings.
	string getTitle() const {return myTitle;}
	string getAuthor() const {return myAuthor;}
	string getBody() const {return myBody;}
	string getBodyReversed() const {return myBodyReversed;}


private:
	// initialized to null.
	string myTitle = "";
	string myAuthor = "";
	string myBody = "";
	string myBodyReversed = "";
	friend class ReversePoemTester;
};

#endif /* REVERSEPOEM_H_ */
