/* LinkedQueue.h declares a Queue class using linked nodes.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: Hansol Kim,. Omari Nyarko
 * Date: November 9, 2021
 * 
 * Class Invariant: 
 *    mySize == 0 && myFirstPtr == nullptr && myLastPtr == nullptr ||
 *    mySize > 0 && myFirstPtr == the address of a node containing the oldest item
 *               && myLastPtr == the address of a node containing the newest item.
 */

#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_

#include "QueueException.h"

typedef int Item;

class LinkedQueue {
public:

	LinkedQueue(const LinkedQueue& original);
	virtual ~LinkedQueue();
	LinkedQueue& operator=(const LinkedQueue& original);
	unsigned getSize() const { return mySize; }
	bool isEmpty() const { return mySize == 0; }
	bool isFull() const { return false; }


	LinkedQueue();
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	Item remove();

protected:
	void makeCopyOf(const LinkedQueue& original);
private:
	unsigned mySize;
	struct Node {
		Item myItem;
		Node * myNextPtr;
		
		Node(const Item& it, Node* nextPtr) { myItem = it; myNextPtr = nextPtr; }
		~Node() { delete myNextPtr; }
	};
	Node * myFirstPtr; // address of Node containing my oldest item
	Node * myLastPtr;  // address of Node containing my newest item

	friend class LinkedQueueTester;
};

#endif /*LINKED_QUEUE_H_*/

