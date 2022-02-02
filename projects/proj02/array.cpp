/* array.cpp defines "C style" array operations
 * Name: Hansol Kim (hk94)
 * Date: September 14, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "array.h"
#include<fstream>

double sum(double *a, unsigned size) {
	double sum = 0.0;
	for (unsigned i = 0; i < size; i++, a++) {
		sum += *a;
	}
	return sum; // returns the sum of the values in the array.
}

void read(istream& in, double *a, unsigned size) {
	initialize(a, size);
	for (unsigned i = 0; i < size; i++, a++) {
		string getSize;
		double arraySize;
		getline(in, getSize);
		arraySize = atof( getSize.c_str() );
		*a = arraySize;
	} // read size values from in and store them in a.
}

/* This function opens an ifstream to the file named fileName, reads an integer from the file into
 * numValues, dynamically allocate an array of numvalues double values, storing its address in a,
 * reads numValues values from the file, storing them in the dynamic array, and closes ifstream.
 */
void fill(const string& fileName, double *&a, unsigned &numValues) {
	delete[] a;
	ifstream fin(fileName.c_str() );
	assert( fin.is_open() );

	string getValues;
	getline(fin, getValues);
	numValues = atoi( getValues.c_str() );
	a = new double[numValues];

	read(fin, a, numValues);
	fin.close();
}

/*This function changes the size of the array from oldSize to newSize. If newSize > oldSize, all of the
 * values in the old array must be copied into the new array. If newSize < oldSize, only the first newSize
 * elements of the array can be copied; the end-elements of the array should be truncated.
 */
void resize(double *&a, unsigned oldSize, unsigned newSize) {
	double *tempA = a;
	a = new double[newSize]();
	unsigned breakout = 0;
	newSize>oldSize? breakout = oldSize: breakout=newSize;
	for (unsigned i = 0; i < breakout; i++) {
		a[i] = tempA[i];
	}
	delete [] tempA;
}

/*This function takes in arrays a1 and a2, of size1 and size2 respectively, and pass back (i) array
 * a3 containing the values of a1 followed by those of a2; and (ii) size3 equal to size1 plus size2.
 */
void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3) {
	size3 = size1 + size2;
	delete[] a3;
	a3 = new double[size3];
	for (unsigned i = 0; i < size3; i++ ) {
		i<size1? a3[i]=a1[i] : a3[i]=a2[i - size1];
	}
}


void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; ++i) {
		val = i+1;
		a[i] = val;
	}
}

void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		cout << *a << '\t';
		a++;
	}
}		
/*This function uses the sum function to divide by the number of elements in the array and returns
 * the average.
 */
double average(double *a, unsigned size) {
	double sum = 0.0;
	for (unsigned i = 0; i < size; i++, a++) {
		sum += *a;
	}
	return sum/size;
}
