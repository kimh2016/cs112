/*
 * PlayListTester.h tests the PlayList class.
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 4 2021
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 */

#ifndef PLAYLISTTESTER_
#define PLAYLISTTESTER_

class PlayListTester {
public:
	void runTests();
	void testConstructors();
	void testAddSong();
	void testRemoveSong();
	void testSave();
	void testSearchByArtist();
	void testSearchByTitlePhrase();
	void testSearchByYear();
};

#endif /* PLAYLISTTESTER_H_ */
