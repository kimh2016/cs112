/*
 * PlayList.h declares PlayList class.
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 4 2021
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "Song.h"
#include<vector>
#include<string>

class PlayList {
public:
	PlayList();
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(unsigned year);
	vector<Song> searchByTitlePhrase(const string& phrase);
	void addSong(const Song& newSong);
	void removeSong(const Song& song);
	void save() const;


private:
	vector<Song> mySongs;
	string myPlayList;
};

#endif /*PLAYLIST_H_*/
