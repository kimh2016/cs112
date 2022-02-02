/*
 * ReversePoem.cpp runs methods of ReversePoem
 *
 *  Created on: Nov 1, 2021
 *      Author: Hansol Kim hk94
 */

#include "ReversePoem.h"

/* Method to run ReversePoem,
 * Parameter: string fileName
 * myTitle, myAuthor, myBody, and
 * myBodyReversed are no longer
 * empty strings " ".
 */

/* The ReversePoem reads top to bottom but
 * somehow it only reads 1/3 of the bottom to top
 */

ReversePoem::ReversePoem(const string& fileName) {
	ifstream fin(fileName);
	assert( fin.is_open() );
	//string emptyline;
	string currentline;
	getline(fin, myTitle);
	getline(fin, myAuthor);
	getline(fin, currentline);
	Stack<string> p0(1);
	while (getline(fin,currentline)) {
		try { p0.push(currentline);
		} catch (const StackException& se) {
			p0.setCapacity(p0.getCapacity()*2);
			p0.push(currentline);
		}
		myBody += currentline + "\n";
	}
	while (!p0.isEmpty() ) {
		myBodyReversed = myBodyReversed + p0.pop() + "\n";
	}
	fin.close();
}









