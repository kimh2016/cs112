/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Hansol Kim (hk94)
 * Date: September 21, 2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"
#include <stdexcept>
using namespace std;

Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}

// Explicit-Value Constructor
Vec::Vec(unsigned size) {
	mySize = size;
	(size > 0)? myArray = new Item[size]():
			myArray = nullptr;
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray = new Item[mySize]();
		for (unsigned i = 0; i < mySize; i++){
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

Vec::~Vec() {
	delete [] myArray;
	myArray = nullptr;
	mySize = 0;
}

Vec& Vec::operator=(const Vec& original) {
	if (mySize != original.mySize) {
		if (mySize > 0) {
			delete [] myArray;
			mySize = 0;
			myArray = nullptr;
		}
		if (original.mySize > 0) {
			myArray = new Item[original.mySize]();
		}
		mySize = original.mySize;
	}
	for (unsigned i = 0; i < mySize; i++) {
		myArray[i] = original.myArray[i];
	}
	return *this;
}

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (mySize > index) {
		myArray[index] = it;
	} else {
		throw range_error("Invalid Index");
	}
}

Item Vec::getItem(unsigned index) const {
	if (mySize > index) {
		return myArray[index];
	} else {
		throw range_error("Invalid Index");
	}

}

void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0){
			delete[] myArray;
			myArray = nullptr;
			mySize = 0;
		} else {
			Item * newArray;
			newArray = new Item[newSize]();
			if (mySize < newSize) {
				for (unsigned i =0; i < mySize; i++) {
					newArray[i] = myArray[i];
				} for (unsigned i = mySize; i < newSize; i++) {
					newArray[i] = 0;
				}
			} else {
				for (unsigned i = 0; i < newSize; i++) {
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete[] myArray;
			myArray = newArray;
		}
	}
}

bool Vec::operator ==(const Vec& v2) const {
	if (mySize == v2.mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] != v2.myArray[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << " ";
	}
}

void Vec::readFrom(istream& in) {
	if (mySize > 0) {
		for (unsigned i = 0; i < mySize; i++) {
			in >> myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

/* Takes an index as an argument and goes through an if
 * statement to see if there are bad index passes when
 * index is equal to or greater than mySize.
 */
Item& Vec::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Bad Index Value");
	}
	return myArray[index];
}

/* Takes an index as an argument and goes through an if
 * statement to see if there are bad index passes when
 * index is equal to or greater than mySize.
 */
const Item& Vec::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Bad Index Value");
	}
	return myArray[index];
}


/*
 * This function does not allow different sizes of vectors
 * for addition or else individual elements are added together.
 *
 */
Vec Vec::operator+(const Vec& v2) const {
	if (mySize != v2.mySize) {
		throw invalid_argument("Not the same size.");

	} else {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] + v2.myArray[i];
		}
		return v3;
	}
}

/*
 * This function does not allow different sizes of vectors
 * for subtraction or else individual elements are subtracted
 * from each other.
 */
Vec Vec::operator-(const Vec& v2) const {
	if (mySize != v2.mySize) {
		throw invalid_argument("Not the same size.");

	} else {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] - v2.myArray[i];
		}
		return v3;
	}
}


















