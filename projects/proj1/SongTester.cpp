/*
 * SongTester.cpp defines the test-methods for class SongTester.
 * Student Name and UserId: Hansol Kim hk94
 * Date: Sep 4, 2021
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 */

#include "SongTester.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include "Song.h"

using namespace std;

void SongTester::runTests() {
	cout << "Testing class Song..." << endl;
	testConstructors();
	testReadFrom();
	testWriteTo();
	cout << "All tests passed!" << endl;
}

void SongTester::testConstructors() {
	cout << "- constructors ... " << flush;
	// default constructor
	Song s;
	assert( s.getTitle() == "" );
	assert( s.getArtist() == "" );
	assert( s.getYear() == 0 );
	cout << " 0 " << flush;

	// explicit constructor
	Song s1("Badge", "Cream", 1969);
	assert( s1.getTitle() == "Badge" );
	assert( s1.getArtist() == "Cream" );
	assert( s1.getYear() == 1969 );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

void SongTester::testReadFrom() {
	cout << "- readFrom()... " << flush;
	ifstream fin("testSongs.txt");
	assert( fin.is_open() );
	Song s;
	string separator;

	// read first song and separator in test playlist
	s.readFrom(fin);
	getline(fin, separator);
	assert( s.getTitle() == "Call Me Maybe" );
	assert( s.getArtist() == "Carly Rae Jepsen" );
	assert( s.getYear() == 2012 );
	cout << " 0 " << flush;

	// read second song and separator in test playlist
	s.readFrom(fin);
	getline(fin, separator);
	assert( s.getTitle() == "Let It Be" );
	assert( s.getArtist() == "The Beatles" );
	assert( s.getYear() == 1967 );
	cout << " 1 " << flush;

	// read third song and separator in test playlist
	s.readFrom(fin);
	getline(fin, separator);
	assert( s.getTitle() == "Let It Be" );
	assert( s.getArtist() == "Joan Baez" );
	assert( s.getYear() == 1971 );
	cout << " 2 " << flush;

	// read third song and separator in test playlist
	s.readFrom(fin);
	getline(fin, separator);
	assert( s.getTitle() == "Penny Lane" );
	assert( s.getArtist() == "The Beatles" );
	assert( s.getYear() == 1967 );
	cout << " 3 " << flush;

}

void SongTester::testWriteTo() {
	cout << "- writeTo()... " << flush;

	// declare three songs
	Song s1("Badge", "Cream", 1969);
	Song s2("Godzilla", "Blue Oyster Cult", 1977);
	Song s3("Behind Blue Eyes", "The Who", 1971);

	// write the three songs to an output file
	ofstream fout("testSongOutput.txt");
	assert( fout.is_open() );
	s1.writeTo(fout);
	fout << "---\n";
	s2.writeTo(fout);
	fout << "---\n";
	s3.writeTo(fout);
	fout << "---\n";
	fout.close();

	// use readFrom() to see if writeTo() worked
	ifstream fin("testSongOutput.txt");
	assert( fin.is_open() );
	Song s4, s5, s6;
	string separator;

	// read and check the first song
	s4.readFrom(fin);
	getline(fin, separator);
	assert( s4.getTitle() == "Badge" );
	assert( s4.getArtist() == "Cream" );
	assert( s4.getYear() == 1969 );
	cout << " 0 " << flush;

	// read and check the second song
	s5.readFrom(fin);
	getline(fin, separator);
	assert( s5.getTitle() == "Godzilla" );
	assert( s5.getArtist() == "Blue Oyster Cult" );
	assert( s5.getYear() == 1977 );
	cout << " 1 " << flush;

	// read and check the third song
	s6.readFrom(fin);
	getline(fin, separator);
	assert( s6.getTitle() == "Behind Blue Eyes" );
	assert( s6.getArtist() == "The Who" );
	assert( s6.getYear() == 1971 );
	cout << " 2 " << flush;

	fin.close();
	cout << " Passed!" << endl;
}

// A test for all possible outcomes.

void SongTester::testEquality() {
	cout << "-Equality()..." << flush;

	Song s7("H", "A", 1996); // When all three match
	Song s8("H", "A", 1996);
	assert (s7 == s8);
	cout << "0" << flush;

	Song s9("N", "A", 1996); // When title doesn't match
	assert( !(s7 == s9));
	cout << "1" << flush;

	Song s10("H", "S", 1996); // When artists don't match
	assert( !(s7 == s10));
	cout << "2" << flush;

	Song s11("H", "A", 1997); // When years don't match
	assert( !(s7 ==s11));
	cout << "3" << flush;

	Song s12("N", "S", 1997); // When none of them matches
	assert( !(s7 ==s12));
	cout << "4" << flush;
	cout << "Passed!" << endl;

}










