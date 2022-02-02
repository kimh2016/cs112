/*
 * Song.h declares a class for storing song information.
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 4 2021
 * Begun by: Hansol Kim, for CS 112 lab at Calvin University.
 */

#ifndef SONG_H
#define SONG_H

#include <string>

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

private:
	string   myTitle;
	string   myArtist;
	unsigned myYear;
};

#endif /*SONG_H_*/
