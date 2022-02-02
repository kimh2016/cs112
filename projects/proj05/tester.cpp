/* Application.cpp performs matrix operations interactive with a user
 * Student Name: Hansol Kim (hk94), Oghenesuvwe Ogedegbe(oko2)
 * Date:4th October 2021
 */

#include "Application.h"
#include "MatrixTester.h"
#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

/* Run method for Application class
 * @param: no parameters
 * return: void
 */
void Application::run(){
	int command = -1;
	string fileName = "";

	while ( command != 0 )
	{
		/* Display menu for Matrix operations
		 */
		cout << "\nMatrix Application\n" << endl;
		cout << "Press 1 to Add" << endl;
		cout << "Press 2 to Subtract" << endl;
		cout << "Press 3 to Transpose" << endl;
		cout << "Press 0 to Quit" << endl;
		cout << "Please type one of these numbers:\n";

		cin >> command;

		/* Perform addition operation
		 */
		if ( command == 1 ) {
			cout << "Please enter a fileName." << endl;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName);
			cout << "Matrix 1:" << endl;
			m1.writeTo(cout);

			cout << "Please enter another fileName." << endl;
			cin >> fileName;
			Matrix<double> m2;
			m2.readFrom(fileName);
			cout << "Matrix 2:" << endl;
			m2.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			m3 = m1 + m2;
			cout << "Added Matrix:" << endl;
			m3.writeTo(cout);

		} else if ( command == 2 ) {
			/* Perform subtraction operation
			 */
			cout << "Please enter a fileName." << endl;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName);
			cout << "Matrix 1:" << endl;
			m1.writeTo(cout);

			cout << "Please enter another fileName." << endl;
			cin >> fileName;
			Matrix<double> m2;
			m2.readFrom(fileName);
			cout << "Matrix 2:" << endl;
			m2.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			m3 = m2 - m1;
			cout << "Subtracted Matrix:" << endl;
			m3.writeTo(cout);

		} else if ( command == 3 ) {
			/* Perform transpose operation
			 */
			cout << "Please enter a fileName." << endl;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName);
			cout << "Matrix 1:" << endl;
			m1.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			m3 = m1.getTranspose();
			cout << "Transposed Matrix:" << endl;
			m3.writeTo(cout);

		} else {
			/* Terminate/ end program
			 */
			if ( command != 0 ) { cout << "Invalid command." << endl; }
		}
	}
}


