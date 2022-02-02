/*
 * App.cpp creates an application or the instruction for the user to input for any size of a vector.
 * Then the application receives the users input and writes them out as vectors.
 *
 * Student Name: Hansol Kim (hk94)
 * Date: September 21, 2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "App.h"
#include <iostream>
#include "Vec.h"
using namespace std;


void App::run() {
    unsigned numDims = printInstructions();
    Vec startingPos = getStartingPosition(numDims);
    Vec resultingPos = getVectors(startingPos);
    printResults(startingPos, resultingPos);
}

unsigned App::printInstructions() {
    unsigned numDims;
    cout << "This application simulates how to move through space by\nadding "
            "together any number of vectors of a given size."
         << endl;
    cout << "How many dimensions would you like to work with? ";
    cin >> numDims;


    return numDims;
}

Vec App::getStartingPosition(unsigned numDims) {
    cout << "Enter starting position: " << endl;
    return getVectorFromUser(numDims);
}

/* This function read the users input and creates
 * a vector out of it.
 */
Vec App::getVectorFromUser(unsigned numDims) {
	Vec vec(numDims);
	vec.readFrom(cin);
	return vec;
}

Vec App::getVectors(const Vec& startVec) {
    char yorn;
    Vec res(startVec);
    while (true) {
        cout << "Do you want to enter another vector? (y/n): ";
        cin >> yorn;
        if (yorn == 'y') {
            Vec v = getVectorFromUser(startVec.getSize());
            res = res + v;
        } else {
            break;
        }
    }
    return res;
}

/*
 * This function writes out the user's starting
 * and ending input into vectors.
 */
void App::printResults(const Vec &start, const Vec &end) {
	start.writeTo(cout);
	cout << endl;
	end.writeTo(cout);
	cout << endl;
}

























