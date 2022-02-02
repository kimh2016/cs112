/* Vec.h provides a simple vector class named Vec.
 * Student Name: Hansol Kim (hk94), Oghenesuvwe Ogedegbe(oko2)
 * Date: September 21, 2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

template<class Item>

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	Vec& operator =(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator == (const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	virtual ~Vec();
	Item& operator[](unsigned index); // write version
	const Item& operator[](unsigned index) const; // read version
	Vec operator+(const Vec& v2) const;
	Vec operator-(const Vec& v2) const;
	bool operator != (const Vec& v2) const;


private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;

};

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = nullptr;
}

// Explicit-Value Constructor
template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	(size > 0)? myArray = new Item[size]():
			myArray = nullptr;
}

template<class Item>
Vec<Item>::Vec(const Vec& original) {
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
template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = nullptr;
	mySize = 0;
}

template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
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

template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (mySize > index) {
		myArray[index] = it;
	} else {
		throw range_error("Invalid Index");
	}
}

template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (mySize > index) {
		return myArray[index];
	} else {
		throw range_error("Invalid Index");
	}

}

template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
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

template<class Item>
bool Vec<Item>::operator ==(const Vec<Item>& v2) const {
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

template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << " ";
	}
}

template<class Item>
void Vec<Item>::readFrom(istream& in) {
	if (mySize > 0) {
		for (unsigned i = 0; i < mySize; i++) {
			in >> myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Bad Index Value");
	}
	return myArray[index];
}

template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Bad Index Value");
	}
	return myArray[index];
}

template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) const {
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

template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2) const {
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

template<class Item>
bool Vec<Item>::operator !=(const Vec<Item>& v2) const {
	return !((*this) == v2);
}


#endif /*VEC_H_*/
