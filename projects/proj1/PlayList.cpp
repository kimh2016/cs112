/*
 * PlayList.cpp defines the PlayList methods.
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 4 2021
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 */

#include "PlayList.h"
#include <fstream>      // ifstream
#include <cassert>      // assert()
using namespace std;

/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */

PlayList::PlayList() {};
PlayList::PlayList(const string& fileName) {
	// open a stream to the playlist file
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	// read each song and append it to mySongs
	Song s;
	string separator;
	while (true) {
		s.readFrom(fin);
		if ( !fin ) { break; }
		getline(fin, separator);
		mySongs.push_back(s);
	}

	// close the stream
	fin.close();
}

/* Retrieve length of the playlist
 * Return: the number of songs in the playlist.
 */
unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}

/* Search by artist
 * @param: artist, a string.
 * Return: a vector containing all the Songs in mySongs by artist.
 */
vector<Song> PlayList::searchByArtist(const string& artist) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getArtist().find(artist) != string::npos ) {
			v.push_back( mySongs[i] );
		}
	}

	return v;
}
// Searching by year param as unsigned year.
vector<Song> PlayList::searchByYear(unsigned year) {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getYear() == year) {
			v.push_back( mySongs[i] );
		}
	}

	return v;
}
// Searching by Title phrase by string phrase.
vector<Song> PlayList::searchByTitlePhrase(const string& phrase) {
	vector<Song> v;
	for (unsigned i = 0; i < mySongs.size(); i++) {
		if (mySongs[i].getTitle().find(phrase) != string::npos) {
			v.push_back(mySongs[i]);
		}
	}
	return v;
}

void PlayList::addSong(const Song& newSong) {
	mySongs.push_back(newSong);
} // Simply adds the song.

void PlayList::removeSong(const Song &song) {
	for (unsigned i = 0; i < mySongs.size(); i++) {
		if (mySongs[i]==song) {
			mySongs.erase(mySongs.begin() + i);
			break;
		}
	} // Removes the song.
}
void PlayList::save() const {
	ofstream fout("testPlayListSave.txt");
	for (unsigned i = 0; i < mySongs.size(); i++ ) {
		mySongs[i].writeTo(fout);
		fout << "\n";
	} // Saves the song.
}
