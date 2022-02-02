/*
 * Application.cpp puts out the input for the user and
 * calls the other methods. In other words, method of
 * of each menu is being called. Application also
 * displays the menu for the user.
 *
 * Created on: Sep 13 2021
 * Author: Hansol Kim hk94
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 */

#include "Application.h"

#include <iostream>
using namespace std;
#include "Song.h"
#include "PlayList.h"


Application::Application() {
	string fname;
	cout << "Welcome to the PlayList Manager" << endl << endl;
	cout << "Please enter a file containing a play list: " << flush;
	getline(cin, fname);
	myPlayList = PlayList(fname);
}

/*
 * Run the application.
 */
void Application::run() {
	while (true) {
		displayMenu();
		char choice = getChoice();
		// cout << "got choice " << choice << endl;
		if (choice == 'q') {
			break;
		}
		processChoice(choice);
	}
}

void Application::displayMenu() const {
	cout << "Please enter:" << endl;
	cout << "a - to add a new song to the playlist" << endl;
	cout << "r - to remove a song from the playlist" << endl;
	cout << "s - to save the playlist" << endl;
	cout << "A - to search the playlist for songs by a given artist" << endl;
	cout << "Y - to search the playlist for songs in a given year" << endl;
	cout << "P - to search the playlist for songs with a given phrase in the title" << endl;
	cout << "q - to quit" << endl;
}

char Application::getChoice() const {
	cout << endl << "Please enter your choice: " << flush;
	char choice;
	cin >> choice;
	cin.get();
	return choice; // Returns the choice that user has chosen.
}

Song Application::getSong() {
	string artist;
	string title;
	unsigned year;
	string yearStr;

	cout << "  Enter artist: ";
	getline(cin, artist);
	cout << "  Enter title: ";
	getline(cin, title);
	cout << "  Enter year: ";
	cin >> year;
    cin.get();
	return Song(title, artist, year);
}

void Application::processChoice(char choice) {
	switch(choice) {
	case 'a': {
		cout << "Add an song to the playlist..." << endl;
        Song newSong = getSong();
        myPlayList.addSong(newSong);
		break;
	} // Adds an song to the play list.
	case 's': {
		myPlayList.save(); // Saves the song
		break;
	}
	case 'r': {
		cout << "Remove a song from the playlist..." << endl;
		Song newSong = getSong();
		myPlayList.removeSong(newSong); // Removes the song from the play list.
		break;
	}
	case 'Y': {
		cout << "Searching playlist by year..." << endl;
		unsigned year;
		cout << "Enter year: ";
		cin >> year;
		cin.get();
		vector<Song> yearSong = myPlayList.searchByYear(year); // Searches the song by the year.

		displaySongs(yearSong);
		break;
	}
	case 'P': {
		cout << "Searching playlist by title phrase..." << endl;
		string phrase;
		cout << "Enter phrase: ";
		cin >> phrase;
        vector<Song> phraseSong = myPlayList.searchByTitlePhrase(phrase); // Searches the song by the Title phrase.
		displaySongs(phraseSong);
		break;
	}
	case 'A': {
		cout << "Searching playlist by artist..." << endl;
		string artist;
		cout << "Enter artist: ";
		cin >> artist;
        vector<Song> artistSong = myPlayList.searchByArtist(artist);
		displaySongs(artistSong); // Searches the song by artist.
		break;
	}
	}
}

void Application::displaySongs(vector<Song> songs) const {
    for (unsigned i = 0; i < songs.size(); i++) {
    	songs[i].writeTo(cout);
    }
}


