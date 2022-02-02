/*
 * PlayList.h class PlayList.
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 4 2021
 * Begun by: Hansol Kim, for CS 112 lab at Calvin University.
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "Song.h"
#include<vector> // STL server
#include<string>
using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist) const;

private:
	vector<Song> mySongs;
};

#endif /*PLAYLIST_H_*/
