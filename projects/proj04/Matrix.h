/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Hansol Kim (hk94), Oghenesuvwe Ogedegbe(oko2)
 * Date:28th September 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include "Vec.h"
#include<cassert>

typedef double Item;

template<class Item>
class Matrix {
public:
	Matrix();
	unsigned getRows() const;
	unsigned getColumns() const;
	Matrix(unsigned rows, unsigned columns);
	Vec<Item>& operator[](unsigned index);
	const Vec<Item>& operator[](unsigned index) const;
	bool operator==(const Matrix& m2) const;
	bool operator!=(const Matrix& m2) const;
	void readFrom( istream& in);
	void writeTo( ostream& out) const;
	void readFrom( const string& fileName );
	void writeTo(const string& fileName );
	Matrix<Item> operator+(const Matrix<Item>& m2) const;
	Matrix<Item> operator-(const Matrix<Item>& m2);
	Matrix<Item> getTranspose();
private:
	unsigned         myRows;
	unsigned         myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

/* Default constructor
 * @param: no parameters
 * return: Matrix object
 */
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

/* Get Rows operation
 * @param: no parameters
 * return: unsigned rows
 */
template<class Item>
unsigned Matrix<Item>::getRows() const{
	return myRows;
}

/* Get Columns operation
 * @param: no parameters
 * return: unsigned columns
 */
template<class Item>
unsigned Matrix<Item>::getColumns() const {
	return myColumns;
}

/* Explicit constructor
 * @param: rows, and unisgned & columns, an unsigned
 * return: Matrix object
 */
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

/* Subscript operator
 * @param: index, an unsigned
 * return: A Vec object
 */
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index) {
	if (index > myRows) {
		throw range_error("Bad Index Value");
	}
	return myVec[index];
}

/* Subscript operator
 * @param: index, an unsigned
 * return: A Vec object
 */
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const {
	if (index > myColumns) {
		throw range_error("Bad Index Value");
	}
	return myVec[index];
}

/* Equality operator
 * @param: Matrix, a matrix object & m2, a Matrix object
 * return: bool
 */
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

/* Inequality operator
 * @param: Matrix, a Matrix object & m2, a Matrix object
 * return: bool
 * written by: Oghenesuvwe Ogedegbe (oko2)
 */
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return true;
	} else {
		return myVec != m2.myVec;
	}
}

/* Readfromstream operator
 * @param:in, an istream
 * Precondtion: in contains the data for the Matrix
 * return: void
 * written by: Hansol Kim (hk94)
 */
template<class Item>
void Matrix<Item>::readFrom( istream& in ) {
	for (unsigned i = 0; i < myRows; ++i) {
		myVec[i].readFrom(in);
	}
}

/* Writetostream operator
 * @param: out, an ostream
 * return: void
 * written by: Hansol Kim (hk94)
 */
template<class Item>
void Matrix<Item>::writeTo( ostream& out ) const {
	for ( unsigned i = 0; i < myRows; ++i ) {
		myVec[i].writeTo(out);
		out << "\n";
	}
}

/* Readfromfile operator
 * @param: filename, a string
 * Precondition: filename contains the data for a Matrix object
 * return: void
 * written by: Hansol Kim (hk94)
 */
template<class Item>
void Matrix<Item>::readFrom( const string& fileName ) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );
	fin >> myRows >> myColumns;
	myVec.setSize(myRows);
	for ( unsigned i = 0; i < myRows; ++i ) {
		myVec[i].setSize(myColumns);
		myVec[i].readFrom(fin);
	}
	fin.close();
}

/* Writetofile operator
 * @param: filename, a string
 * return: void
 * written by: Hansol Kim (hk94)
 */
template<class Item>
void Matrix<Item>::writeTo(const string& fileName) {
	ofstream fout( fileName.c_str() );
	assert( fout.is_open() );

	fout << myRows << '\t' << myColumns;
	for ( unsigned i = 0; i < myRows; ++i) {
		fout << '\n';
		for (unsigned j = 0; j < myColumns; ++j) {
			fout << myVec[i][j] << "\t";
		}
	}
	fout.close();
}

/* Addition operator
 * @param: Matrix, a matrix object & m2, a Matrix object
 * return: a Matrix object
 * written by: Oghenesuvwe Ogedegbe (oko2)
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		cout << m2.getRows() << " " << m2.getColumns() << " " << myRows << " " << myColumns << flush;
		throw invalid_argument("Matrices are not the same size.");
	} else {
		Matrix temp(myRows,myColumns);
		for( unsigned i = 0; i < myRows; i++) {
			for( unsigned j = 0; j < myColumns; j++) {
				temp[i][j] = myVec[i][j] + m2[i][j];
			}
		}
		return temp;
	}
}

/* Subtraction operator
 * @param: Matrix, a matrix object & m2, a Matrix object
 * return: a Matrix object
 * written by: Oghenesuvwe Ogedegbe (oko2)
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator-( const Matrix<Item>& m2 ) {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		throw invalid_argument( "Matrices are not the same size." );
	} else {
		Matrix temp( myRows, myColumns );
		for ( unsigned i = 0; i < myRows; i++ ) {
			for ( unsigned j = 0; j < myColumns; j++ ) {
				temp[i][j] = myVec[i][j] - m2[i][j];
			}
		}
		return temp;
	}
}

/* Transpose operator
 * @param: no parameters
 * return: a Matrix object
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() {
	Matrix temp( myColumns, myRows );
	for ( unsigned i = 0; i < myRows; i++ ) {
		for ( unsigned j = 0; j < myColumns; j++ ) {
			temp[j][i] = myVec[i][j];
		}
	}
	return temp;
}

#endif
