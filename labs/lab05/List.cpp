/*
 * List.cpp defines the methods for List.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Hansol Kim, Afua Brantuo
 */

#include "List.h"
#include <stdexcept>

List::List() {
	mySize = 0;
	myFirst = nullptr;
	myLast = nullptr;
}

List::Node::Node(){

	myItem = Item();
	myNext = nullptr;
}
List::Node::Node(const Item& it, Node* next) {
	myItem = it;
	myNext = next;
}

Item List::getFirst() const {
	if (mySize == 0) {
		throw underflow_error(" Empty Size");
	}
	return myFirst->myItem;
}

Item List::getLast() const{
	if (mySize == 0) {
		throw underflow_error(" Empty Size");
	}
	return myLast->myItem;
}

void List::append( const Item& it) {
	if (mySize== 0){
		Node* tempPtr = new Node(it, nullptr);
		myFirst = tempPtr;
		myLast = tempPtr;
		++mySize;
	} else{
		Node* tempPtr = new Node(it, nullptr);
		myLast-> myNext = tempPtr;
		myLast = tempPtr;
		++mySize;
	}
}

List::~List() {
	delete myFirst;             // delete first node, invoking ~Node()
	//  (does nothing if myFirst == nullptr)
	myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
	mySize = 0;                 // clear mySize (optional)
}

List::Node::~Node() {
	cout << "~Node() is deallocating the node containing item "
			<< myItem << endl;
	delete myNext;       // delete the next node, invoking ~Node() in it
	// (does nothing if myNext == nullptr)
}

void List::makeMeACopyOf(const List &original) {
	myFirst = myLast = nullptr; //  set pointers
	mySize = 0; //   and size to 'empty' values
	Node *oPtr = original.myFirst; //  start at original's first node
	while (oPtr != nullptr) {
		//  while there are nodes to copy:
		append(oPtr->myItem); //   append the item in that node
		oPtr = oPtr->myNext; //   advance to next node
	}
}

List::List(const List& original) {
	makeMeACopyOf(original);
 }

List& List::operator=(const List& rhs) { // rhs == right hand side
	if (this != &rhs) {
		delete myFirst;
		makeMeACopyOf(rhs);
	}
	return *this;
}
