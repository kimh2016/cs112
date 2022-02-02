/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: Hansol Kim,. Omari Nyarko
 * Date: November 9, 2021
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 * 
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>

template<class Item>
 
class ArrayQueue {
public:

	ArrayQueue(const ArrayQueue<Item>& original);
	virtual ~ArrayQueue();
	ArrayQueue<Item>& operator=(const ArrayQueue<Item>& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;

	void append(const Item& item);
	Item getLast();
	Item getFirst();
	Item remove();
	ArrayQueue(unsigned capacity);
	void setCapacity(unsigned newCapacity);

protected:
	virtual void makeCopyOf(const ArrayQueue<Item>& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirstIndex; // index of oldest item (if any)
	unsigned myLastIndex;  // index of newest item (if any)
	Item*    myArrayPtr;   // dynamic array of items

	friend class ArrayQueueTester;
};
template<class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
	if (capacity == 0) {
		throw QueueException("Constructor", "Invalid Capacity");
	}
	myArrayPtr = new Item[capacity];
	myCapacity = capacity;
	mySize = 0;
	myFirstIndex = 0;
	myLastIndex = capacity - 1;
}

/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = nullptr;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

template<class Item>
Item ArrayQueue<Item>::getFirst() {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::getFirst()");
	}
	return myArrayPtr[myFirstIndex];
}

template<class Item>
Item ArrayQueue<Item>::getLast() {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::getFirst()");
	}
	return myArrayPtr[myLastIndex];
}

template<class Item>
void ArrayQueue<Item>::append(const Item& it) {
	if (isFull()) {
		throw FullQueueException("ArrayQueue::append(const Item)");
	}
	myLastIndex = (myLastIndex + 1) % myCapacity;
	myArrayPtr[myLastIndex] = it;
	mySize++;
}

template<class Item>
Item ArrayQueue<Item>::remove() {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::remove()");

	}
	mySize--;
	Item temp = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex + 1) % myCapacity;
	return temp;
}

/* setCapacity function
 * parameters: unsigned newCapacity
 * myCapacity is now equal to
 * newCapacity which allows to change
 * the capacity of the Array.
 *
 */
template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity) {
	if (!newCapacity) {
		throw EmptyQueueException("ArrayQueue<Item::setCapacity(unsigned)");
	} else if (newCapacity < mySize) {
		throw FullQueueException("ArrayQueue<Item>::setCapacity(unsigned)");
	}
	Item* tempArrayPtr = myArrayPtr;
	myArrayPtr = new Item[newCapacity];
	for (unsigned i = 0; i < mySize; i++) {
		myArrayPtr[i] = tempArrayPtr[(i + myFirstIndex) % myCapacity];
	}
	delete [] tempArrayPtr;
	myFirstIndex = 0;
	myLastIndex = mySize - 1;
	myCapacity = newCapacity;
}









#endif /*ARRAY_QUEUE_H_*/
