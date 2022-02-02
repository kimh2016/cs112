/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Hansol Kim,. Omari Nyarko
 * Date: November 9, 2021
 */

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
using namespace std;


ArrayQueue::ArrayQueue(int capacity) {
	if (capacity == 0) {
		throw EmptyQueueException("ArrayQueue(int capacity)");
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
ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
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
ArrayQueue::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = nullptr;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
unsigned ArrayQueue::getSize() const {
	return mySize;
}

Item ArrayQueue::getFirst() {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::getFirst()");
	}
	return myArrayPtr[myFirstIndex];
}

Item ArrayQueue::getLast() {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::getFirst()");
	}
	return myArrayPtr[myLastIndex];
}

void ArrayQueue::append(const Item& it) {
	if (isFull()) {
		throw FullQueueException("ArrayQueue::append(const Item)");
	}
	myLastIndex = (myLastIndex + 1) % myCapacity;
	myArrayPtr[myLastIndex] = it;
	mySize++;
}

Item ArrayQueue::remove() {
	if (mySize == 0) {
		throw EmptyQueueException("ArrayQueue::remove()");

	}
	mySize--;
	Item temp = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex + 1) % myCapacity;
	return temp;
}











