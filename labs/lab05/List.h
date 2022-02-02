/*
 * List.h declares class named List.
 *
 *  Created on: Oct 5, 2021
 *      Author: Hansol Kim, Afua Brantuo
 */

#ifndef LIST_H_
#define LIST_H_

typedef double Item;
#include <iostream>
using namespace std;


class List {
public:
	List();
	unsigned getSize() const {return mySize; }
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	List(const List& original);
	List& operator=(const List& rhs);


	virtual ~List();
private:
	struct Node{
		Node();
		Node(const Item& it, Node* next);
		~Node();
		Item myItem;
		Node* myNext;
	};
	unsigned mySize;
	Node* myFirst;
	Node* myLast;

	void makeMeACopyOf(const List &original);

	friend class ListTester;

};

#endif /* LIST_H_ */
