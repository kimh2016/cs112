/*
 * PlayListTester.cpp defines the PlayList test-methods.
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 4 2021
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 */


#include "PlayListTester.h"
#include <iostream>
#include <cassert>
#include "PlayList.h"
using namespace std;

void PlayListTester::testConstructors() {
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );
	cout << " 0 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::runTests() {
	cout << "Testing class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	testSearchByYear();
	testSearchByTitlePhrase();
	testAddSong();
	testRemoveSong();
	testSave();
	cout << "All tests passed!" << endl;
} // runs all the tests

void PlayListTester::testSearchByArtist() {
	cout << "- searchByArtist()..." << flush;
	PlayList pList("testSongs.txt");

	vector<Song> searchResult = pList.searchByArtist("NULL");
	assert( searchResult.size() == 0);
	cout << "0" << flush;

	searchResult = pList.searchByArtist("Baez");
	assert( searchResult.size() == 1);
	assert( searchResult[0].getTitle() == "Let It Be");
	cout << "1" << flush;

	searchResult = pList.searchByArtist("Beatles");
	assert( searchResult.size() == 2);
	assert( searchResult[0].getTitle() == "Let It Be");
	assert( searchResult[1].getTitle() == "Penny Lane");
	cout << "2" << flush;
	cout << "Passed!" << endl;
} // Runs the test on the Artist.

void PlayListTester::testSearchByYear() {
	cout << "- searchByYear()..." << flush;
	PlayList pList("testSongs.txt");

	vector<Song> searchResult = pList.searchByYear(0000);
	assert( searchResult.size() == 0);
	cout << "0" << flush;

	searchResult = pList.searchByYear(2012);
	assert( searchResult.size() == 1);
	assert( searchResult[0].getTitle() == "Call Me Maybe");
	cout << "1" << flush;

	searchResult = pList.searchByYear(1967);
	assert( searchResult.size() == 2);
	assert( searchResult[0].getArtist() == "The Beatles");
	assert( searchResult[1].getArtist() == "The Beatles");
	cout << "2" << flush;
	cout << "Passed!" << endl;

} // Runs the test on searching by year.

void PlayListTester::testSearchByTitlePhrase() {
	cout << "- searchByTitlePhrase()..." << flush;
	PlayList pList("testSongs.txt");

	vector<Song> searchResult = pList.searchByTitlePhrase("NULL");
	assert( searchResult.size() == 0);
	cout << "0" << flush;

	searchResult = pList.searchByTitlePhrase("Maybe");
	assert( searchResult.size() == 1);
	assert( searchResult[0].getArtist() == "Carly Rae Jepsen");
	cout << "1" << flush;

	searchResult = pList.searchByTitlePhrase("Let");
	assert( searchResult.size() == 2);
	assert( searchResult[0].getArtist() == "The Beatles");
	assert( searchResult[1].getArtist() == "Joan Baez");
	cout << "2" << flush;
	cout << "Passed!" << endl;
} // Runs the test searching by the Title phrase.

void PlayListTester::testAddSong() {

	cout << "- addSong()..." << flush;

	PlayList pList("testSongs.txt"); // list
	assert(pList.getNumSongs() == 4);

	Song s1("Isn't She Lovely", "Stevie Wonder", 1976);
	pList.addSong(s1);
	assert(pList.getNumSongs() == 5);
	cout << "0" << flush;

	vector<Song> searchResult = pList.searchByTitlePhrase("She");
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Isn't She Lovely");
	assert(searchResult[0].getArtist() == "Stevie Wonder");
	assert(searchResult[0].getYear() == 1976);
	cout << "1" << flush;
	cout << "Passed!" << endl;

} // Runs the test adding songs.

void PlayListTester::testRemoveSong() {

	cout << "-removeSong()..." << flush;

	PlayList pList("testSongs.txt");
	assert(pList.getNumSongs() == 4);

	Song s1("Isn't She Lovely", "Stevie Wonder", 1976);
	pList.addSong(s1);
	assert(pList.getNumSongs() == 5);
	cout << "0" << flush;

	pList.removeSong(s1);
	assert(pList.getNumSongs() == 4);
	cout << "1" << flush;

	vector<Song> searchResult = pList.searchByArtist("Stevie Wonder");
	assert(searchResult.size() == 0);
	cout << "2" << flush;
	cout << "Passed!" << endl;

} // Runs the test on remvoving songs.

void PlayListTester::testSave() {
	cout << "-save()..." << flush;
	PlayList pList1("testSongs.txt");
	Song s1("Isn't She Lovely", "Stevie Wonder", 1976);
	pList1.addSong(s1);
	assert(pList1.getNumSongs() == 5);
	pList1.save();
	cout << "0" << flush;
} // Runs the test on saving the song.

























