/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Hansol Kim,. Omari Nyarko
 * Date: November 9, 2021
 */

#include "LinkedQueue.h"


LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = nullptr;
	} else {
		myFirstPtr = new Node(original.getFirst(), nullptr);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != nullptr) {
			temp1->myNextPtr = new Node(temp0->myItem, nullptr);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = nullptr;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}



LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirstPtr = myLastPtr = nullptr;
}

Item LinkedQueue::getFirst() const {
	if (myFirstPtr) {
		return myFirstPtr -> myItem;
	}
	throw EmptyQueueException("LinkedQueue::getFirst()");
}

Item LinkedQueue::getLast() const {
	if (myLastPtr) {
		return myLastPtr -> myItem;
	}
	throw EmptyQueueException("LinkedQueue::getLast()");
}


void LinkedQueue::append(const Item& it) {

	Node* nPtr;
	try {
		nPtr = new Node(it, nullptr);
	}
	catch (std::bad_alloc&) {
		throw FullQueueException("LinkedQueue::append()");
	}
	if (mySize == 0) {
		myFirstPtr = nPtr;
	}
	else {
		myLastPtr -> myNextPtr = nPtr;
	}
	myLastPtr = nPtr;
	++mySize;
}


Item LinkedQueue::remove() {

	if (mySize == 0) {
		throw EmptyQueueException("LinkedQueue::remove()");
	}
	else {
		Item result = myFirstPtr -> myItem;
		Node* temp = myFirstPtr;
		myFirstPtr = myFirstPtr -> myNextPtr;
		temp -> myNextPtr = nullptr;
		delete temp;
		--mySize;
		return result;
	}
}





