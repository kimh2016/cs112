/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Hansol Kim
 * Date: November 22, 2021
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == nullptr ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template <class Item>

class BST {
public:
	BST();

	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	void insert(const Item& item);
	bool contains(const Item& item) const;
	unsigned getHeight() const;


private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            void nodeInsert(const Item& item);
            bool nodeContains(const Item& item) const;
            unsigned getHeightNode() const;
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot; // pointer to the first item we insert
	unsigned myNumItems; // number of items I contain
	friend class BST_Tester;
};

template <class Item>
BST<Item>::BST() {
	myNumItems = 0;
	myRoot = nullptr;

}

template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = nullptr;
   myRight = nullptr;
}

template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

template <class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != nullptr) {
		myLeft -> traverseInorder();
	}
	processItem();
	if (myRight != nullptr) {
		myRight -> traverseInorder();
	}
}

template <class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != nullptr) {
		myLeft -> traversePostorder();
	}
	if (myRight != nullptr) {
		myRight -> traversePostorder();
	}
	processItem();
}

template <class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

template <class Item>
void BST<Item>::insert(const Item& item) {
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

template <class Item>
void BST<Item>::Node::nodeInsert(const Item& item) {
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

template <class Item>
bool BST<Item>::contains(const Item& item) const {
	if ( isEmpty() ) {
		return false;
	} else {
		return myRoot -> nodeContains(item);
	}
}

template <class Item>
bool BST<Item>::Node::nodeContains(const Item& item) const {
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
/* This method calls another
 * method called getHeightNode
 */
template <class Item>
unsigned BST<Item>::getHeight() const {
	if (isEmpty() ) {
		return 0;
	} else {
		return myRoot -> getHeightNode();
	}
}

/* This method calls itself
 * getHeightNode() and
 * increments the height of
 * binary search tree.
 *
 */
template <class Item>
unsigned BST<Item>::Node::getHeightNode() const {
	unsigned myLeftHeight = 0;
	unsigned myRightHeight = 0;
	if (myLeft != nullptr) {
		myLeftHeight = myLeft -> getHeightNode();
	}
	if (myRight != nullptr) {
		myRightHeight = myRight -> getHeightNode();
	}
	if (myLeftHeight > myRightHeight) {
		return myLeftHeight + 1;
	} else {
		return myRightHeight + 1;
	}
}

#endif /*BST_H_*/

