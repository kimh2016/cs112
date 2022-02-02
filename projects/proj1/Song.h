/*
 * Song.h declares a class for storing song information.
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 4 2021
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 */

#ifndef SONG_H
#define SONG_H

#include <string>
#include<iostream>


using namespace std;

class Song {
public:
	Song();
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	Song(const string& title, const string& artist, unsigned year);
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	bool operator == (const Song& song2) const;
	//Song a = new Song("hello", "beetles", 1994);
	// boolean hi = a == b;

private:
	string   myTitle;
	string   myArtist;
	unsigned myYear;
};

#endif /*SONG_H_*/
