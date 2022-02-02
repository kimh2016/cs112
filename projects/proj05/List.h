/*
 * List.h declares class named List.
 *
 *  Created on: Oct 5, 2021
 *      Author: Hansol Kim
 */

#ifndef LIST_H_
#define LIST_H_

typedef double Item;
#include <iostream>
#include <cassert>
#include <fstream>
#include <cstring>
using namespace std;

template <class Item>

class List {
public:
	List();
	unsigned getSize() const {return mySize; }
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	List(const List<Item>& original);
	List<Item>& operator=(const List<Item>& rhs);
	void testEquality();
	bool operator==(const List<Item>& original);
	bool operator!=(const List<Item>& l2) const;
	void readFrom (istream &in);
	void writeTo( ostream &out, const char &separator);
	void readFrom( const string &fileName );
	void writeTo(const string &fileName);
	void prepend(const Item& it);
	int getIndexOf( const Item& it );
	void Insert(const Item it, unsigned index);
	Item remove( unsigned index );



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

	void makeMeACopyOf(const List<Item> &original);

	friend class ListTester;

};

template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = nullptr;
	myLast = nullptr;
}

template <class Item>
List<Item>::Node::Node(){

	myItem = Item();
	myNext = nullptr;
}

template <class Item>
List<Item>::Node::Node(const Item& it, Node* next) {
	myItem = it;
	myNext = next;
}

template <class Item>
// returns the first value in the list.
Item List<Item>::getFirst() const {
	if (mySize == 0) {
		throw underflow_error(" Empty Size");
	}
	return myFirst->myItem;
}

template <class Item>
// returns the last value in the list.
Item List<Item>::getLast() const{
	if (mySize == 0) {
		throw underflow_error(" Empty Size");
	}
	return myLast->myItem;
}

template <class Item>
// adds a value to the list.
void List<Item>::append( const Item& it) {
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

template <class Item>
List<Item>::~List() {
	delete myFirst;             // delete first node, invoking ~Node()
	//  (does nothing if myFirst == nullptr)
	myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
	mySize = 0;                 // clear mySize (optional)
}

template <class Item>
List<Item>::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item "
//			<< myItem << endl;
	delete myNext;       // delete the next node, invoking ~Node() in it
	// (does nothing if myNext == nullptr)
}

template <class Item>
void List<Item>::makeMeACopyOf(const List &original) {
	myFirst = myLast = nullptr; //  set pointers
	mySize = 0; //   and size to 'empty' values
	Node *oPtr = original.myFirst; //  start at original's first node
	while (oPtr != nullptr) {
		//  while there are nodes to copy:
		append(oPtr->myItem); //   append the item in that node
		oPtr = oPtr->myNext; //   advance to next node
	}
}

template <class Item>
// copy constructor
List<Item>::List(const List& original) {
	makeMeACopyOf(original);
}

template <class Item>
// deallocating the chain nodes and makes a copy.
List<Item>& List<Item>::operator=(const List& rhs) { // rhs == right hand side
	if (this != &rhs) {
		delete myFirst;
		makeMeACopyOf(rhs);
	}
	return *this;
}

/* Equality operator
 * @param: original, a List template
 * Testing if dimensions of Items in Node match
 * returns the Node Item that matches.
 * AUTHORED BY:	Hansol Kim (hk94)
 */
template <class Item>
bool List<Item>::operator==(const List& original) {
	if (mySize == original.mySize) {
		if (mySize == 0) {
			return true;
		}
		Node *myPtr = original.myFirst;
		Node *myPtr2 = myFirst;

		while (myPtr != nullptr) {
			if (myPtr2 -> myItem != myPtr -> myItem) {
				return false;
			}
			else {
				return true;
			}
			myPtr = myPtr -> myNext;
			myPtr2 = myPtr2 -> myNext;
		}
	}
	if (mySize != original.mySize) {
		return false;
	}
	return true;
}

/* Inequality operator
 * @param: l2, a List template
 * Testing if dimensions of Items in Node doesn't match
 * returns the Node Item that doesn't match.
 * AUTHORED BY:	Hansol Kim (hk94)
 */
template <class Item>
bool List<Item>::operator!=(const List& l2) const {
	if ( mySize == l2.getSize() ) {
		Node* myNode = myFirst;
		Node* l2Node = l2.myFirst;
		while ( myNode != nullptr) {
			if ( myNode->myItem != l2Node->myItem ) {
				return true;
			}
			myNode = myNode->myNext;
			l2Node = l2Node->myNext;
		}
		return false;
	} else {
		return true;
	}
}

/* Read from Function
 * @param: istream in
 * Erase any items in current list and reads
 * arbitrary values from fin.
 * AUTHORED BY:	Hansol Kim (hk94)
 */
template <class Item>
void List<Item>::readFrom(istream &in) {
	if (mySize != 0) {
		delete myFirst;
	}
	Item it;
	while(in) {
		if ( in.peek() == '\n' ) {
			break;
		}
		in >> it;
		append(it);
	}
	//	delete myFirst;
	//	Item it;
	//	in >> it;
	//	while (in) {
	//		if ( in.peek() == '\n' ) break;
	//		in >> it;
	//		append(it);
	//	}
}

/* Write to Function
 * @param:	ostream out
 * Contains values in list and
 * values are then printed to screen
 * AUTHORED BY: Hansol Kim (hk94)
 */
template <class Item>
void List<Item>::writeTo( ostream &out, const char &separator) {
	Node* myNode = myFirst;
	for ( unsigned i = 0; i < mySize; i++ ) {
		out << myNode->myItem << separator;
		myNode = myNode->myNext;
	}
}

/* File Input Function
 * @param: fileName
 * Empties the current items in the list and fills
 * the list with values stored in the fileName. This
 * function then reads and appends values in the list
 * until the end of the file.
 * AUTHORED BY:	Hansol Kim (hk94)
 */
template <class Item>
void List<Item>::readFrom( const string &fileName ) {
	delete myFirst;
	myFirst = myLast = nullptr;
	mySize = 0;
	ifstream fin( fileName);
	assert( fin.is_open() );
	Item it;
	fin >> it;
	while( fin ) {
		append(it);
		fin >> it;
	}
	fin.close();
}

/* File Output Function
 * @param: fileName
 * Writes all the values in the list to the
 * file named by fileName, each item on a
 * separate line of the file.
 * AUTHORED BY:	Hansol Kim (hk94)
 */
template <class Item>
void List<Item>::writeTo(const string &fileName) {
	ofstream fout(fileName);
	assert(fout.is_open());
	writeTo(fout, ' ');
//	Node* myPtr = myFirst;
//	while(myPtr) {
//		fout << myPtr->myItem << separator;
//		myPtr = myPtr->myNext;
//	}
}

/* Prepend Function
 * @param: Item it
 * Adds a value it at the
 * beginning of the list.
 * AUTHORED BY:	Hansol Kim (hk94)
 */
template <class Item>
void List<Item>::prepend(const Item& it) {
	Node *myPtr = new Node(it, myFirst );
	if ( mySize == 0 ) { myLast = myPtr; }
	myFirst = myPtr;
	mySize++;
}

/* Index Function
 * @param: it, an Item
 * Contains a value in the node and
 * function returns position in list
 * AUTHORED BY:	Hansol Kim (hk94)
 */
template <class Item>
int List<Item>::getIndexOf( const Item& it ) {
	Node* myNode = myFirst;
	int index = 0;
	if ( mySize > 0 ) {
		while ( it != myNode->myItem ) {
			if ( myNode == nullptr ) {break;
			} else {
				myNode = myNode->myNext;
				index++;
			}
		}
		return index;
	} else {
		return -1;
	}
}

/* Node Insert Function
 * @param: unsigned index and Item
 * In list2.insert(0,1); insert the
 * value 0 into list2 at index 1.
 * AUTHORED BY: Hansol Kim (hk94)
 */
template <class Item>
void List<Item>::Insert(const Item it, unsigned index) {
	Node *nodePtr2 = myFirst;

	if(mySize == 0||index == 0) {
		prepend(it);
	}
	else{
		for(unsigned i = 0; i <index-1; i++){
			nodePtr2 = nodePtr2->myNext;
		}
		nodePtr2->myNext = new Node(it,nodePtr2->myNext);
		if (index >= mySize) {
			myLast = new Node(it, nullptr);
		}
		mySize++;
	}
}

/* Node Remove Function
 * @param: unsigned index
 * node at index is removed
 * AUTHORED BY: Hansol Kim (hk94)
 */
template <class Item>
Item List<Item>::remove( unsigned index ) {
	Node* myNode = myFirst;
	for ( unsigned i = 0; i <= index; i++ ) {
		if ( i+1 == index ) {
			Node* temp = myNode->myNext->myNext;
			myNode->myNext = nullptr;
			delete myNode->myNext;
			myNode->myNext = temp;
			mySize--;
			break;
		} else if (index == 0) {
			Node* temp = myFirst->myNext;
			myFirst->myNext = nullptr;
			delete myFirst;
			myFirst = temp;
			mySize--;
			break;
		} else {
			myNode = myNode->myNext;
		}
	}
	return myNode->myItem;
}

#endif /* LIST_H_ */
