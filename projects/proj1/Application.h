/* Application.h declares the application class for our PlayList class.
 *
 * Student Name and Username: Hansol Kim hk94
 * Date: Sep 13 2021
 * Begun by: Hansol Kim, for CS 112 project at Calvin University.
 *
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "PlayList.h"

class Application {
public:
	Application();
	void run();

private:
	void displayMenu() const;
	char getChoice() const;
	void processChoice(char choice);
	Song getSong();
	void displaySongs(vector<Song> songs) const;

	PlayList myPlayList;
};

#endif /* APPLICATION_H_ */
