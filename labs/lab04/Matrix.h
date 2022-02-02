/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Hansol Kim (hk94), Oghenesuvwe Ogedegbe(oko2)
 * Date:28th September 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include "Vec.h"

typedef double Item;

class Matrix {
public:
	Matrix();
	unsigned getRows() const;
	unsigned getColumns() const;
	Matrix(unsigned rows, unsigned columns);
	Vec<Item>& operator[](unsigned index);
	const Vec<Item>& operator[](unsigned index) const;
	bool operator==(const Matrix& m2) const;
private:
	unsigned         myRows;
	unsigned         myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

#endif
