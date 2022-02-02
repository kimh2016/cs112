///* Matrix.cpp defines Matrix class methods.
// * Student Name: Hansol Kim (hk94), Oghenesuvwe Ogedegbe (oko2)
// * Date: 28 September 2021
// * Begun by: Joel Adams, for CS 112 at Calvin University.
// */
//
//#include "Matrix.h"
//#include <cassert>
//
//
//Matrix::Matrix() {
//	myRows = myColumns = 0;
//}
//
//unsigned Matrix::getRows() const{
//	return myRows;
//}
//
//unsigned Matrix::getColumns() const {
//	return myColumns;
//}
//
//
//Matrix::Matrix(unsigned rows, unsigned columns) {
//	myRows = rows;
//	myColumns = columns;
//	myVec.setSize(rows);
//	for (unsigned i = 0; i < rows; i++) {
//		myVec[i].setSize(columns);
//	}
//}
//
//
//Vec<Item>& Matrix::operator[](unsigned index) {
//	if (index > myRows) {
//			throw range_error("Bad Index Value");
//		}
//		return myVec[index];
//	}
//
//const Vec<Item>& Matrix::operator[](unsigned index) const {
//	if (index > myColumns) {
//		throw range_error("Bad Index Value");
//	}
//	return myVec[index];
//}
//
//
//bool Matrix::operator==(const Matrix& m2) const {
//   if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//        return false;
//   } else {
//        return myVec == m2.myVec;
//   }
//}
//
//bool Matrix::operator!=(const Matrix& m2) const {
//	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//		return true;
//	} else {
//		return myVec != m2.myVec;
//	}
//}
//
//void Matrix::readFrom( istream& in ) {
//	for (unsigned i = 0; i < myRows; ++i) {
//		myVec[i].readFrom(in);
//	}
//}
//
//void Matrix::writeTo( ostream& out ) const {
//	for ( unsigned i = 0; i < myRows; ++i ) {
//		myVec[i].writeTo(out);
//		out << "\n";
//	}
//}
