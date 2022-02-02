/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:
 * Date:
 */
 
#include "BST.h"
#include "Exception.h"

BST::BST() {
	myNumItems = 0;
	myRoot = nullptr;

}

BST::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = nullptr;
   myRight = nullptr;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}
void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

void BST::Node::traverseInorder() {
	if (myLeft != nullptr) {
		myLeft -> traverseInorder();
	}
	processItem();
	if (myRight != nullptr) {
		myRight -> traverseInorder();
	}
}

void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}
void BST::Node::traversePostorder() {
	if (myLeft != nullptr) {
		myLeft -> traversePostorder();
	}
	if (myRight != nullptr) {
		myRight -> traversePostorder();
	}
	processItem();
}
void BST::Node::processItem() {
		cout << ' ' << myItem;
}

void BST::insert(const Item& item) {
	if ( isEmpty() ) {
		myRoot = new Node(item);
		++ myNumItems;
	} else {
		try {
		myRoot -> nodeInsert(item);
		++myNumItems;
		}
		catch(Exception& e) {
			throw e;
		}
	}
}

void BST::Node::nodeInsert(const Item& item) {
	if (item < myItem) { 			// case 1: item goes to the left
		if (myLeft == nullptr) { 	// Basis 1:
			myLeft = new Node(item);
		} else {					// I-Step 1:
			myLeft -> nodeInsert(item);
		}
	} else if (item > myItem) {		// case 2: item goes to the right
		if (myRight == nullptr) {	// Basis 2:
			myRight = new Node(item);
		} else {						// I-step 2:
			myRight -> nodeInsert(item);
		}
	} else {
		throw Exception("nodeInsert()", "item already in BST");
	}
}


bool BST::contains(const Item& item) const {
	if ( isEmpty() ) {
		return false;
	} else {
		return myRoot -> nodeContains(item);
	}
}

bool BST::Node::nodeContains(const Item& item) const {
	if (item < myItem) {
		if (myLeft == nullptr) {
			return false;
		} else {
			return myLeft -> nodeContains(item);
		}
	} else if(item > myItem) {
			if (myRight == nullptr) {
				return false;
			} else {
				return myRight -> nodeContains(item);
			}
		}
	return true;
}









