/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:
 * Date:
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

typedef int Item;

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
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot; // pointer to the first item we insert
	unsigned myNumItems; // number of items I contain
	friend class BST_Tester;
};

#endif /*BST_H_*/

