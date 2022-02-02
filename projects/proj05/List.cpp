/*
 * List.cpp defines the methods for List.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Hansol Kim
 */

//#include "List.h"
//#include <stdexcept>

//List::List() {
//	mySize = 0;
//	myFirst = nullptr;
//	myLast = nullptr;
//}
//
//List::Node::Node(){
//
//	myItem = Item();
//	myNext = nullptr;
//}
//List::Node::Node(const Item& it, Node* next) {
//	myItem = it;
//	myNext = next;
//}
//
//// returns the first value in the list.
//Item List::getFirst() const {
//	if (mySize == 0) {
//		throw underflow_error(" Empty Size");
//	}
//	return myFirst->myItem;
//}
//
//// returns the last value in the list.
//Item List::getLast() const{
//	if (mySize == 0) {
//		throw underflow_error(" Empty Size");
//	}
//	return myLast->myItem;
//}
//
//// adds a value to the list.
//void List::append( const Item& it) {
//	if (mySize== 0){
//		Node* tempPtr = new Node(it, nullptr);
//		myFirst = tempPtr;
//		myLast = tempPtr;
//		++mySize;
//	} else{
//		Node* tempPtr = new Node(it, nullptr);
//		myLast-> myNext = tempPtr;
//		myLast = tempPtr;
//		++mySize;
//	}
//}
//
//List::~List() {
//	delete myFirst;             // delete first node, invoking ~Node()
//	//  (does nothing if myFirst == nullptr)
//	myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
//	mySize = 0;                 // clear mySize (optional)
//}
//
//List::Node::~Node() {
////	cout << "~Node() is deallocating the node containing item "
////			<< myItem << endl;
//	delete myNext;       // delete the next node, invoking ~Node() in it
//	// (does nothing if myNext == nullptr)
//}
//
//void List::makeMeACopyOf(const List &original) {
//	myFirst = myLast = nullptr; //  set pointers
//	mySize = 0; //   and size to 'empty' values
//	Node *oPtr = original.myFirst; //  start at original's first node
//	while (oPtr != nullptr) {
//		//  while there are nodes to copy:
//		append(oPtr->myItem); //   append the item in that node
//		oPtr = oPtr->myNext; //   advance to next node
//	}
//}
//
//// copy constructor
//List::List(const List& original) {
//	makeMeACopyOf(original);
//}
//
//// deallocating the chain nodes and makes a copy.
//List& List::operator=(const List& rhs) { // rhs == right hand side
//	if (this != &rhs) {
//		delete myFirst;
//		makeMeACopyOf(rhs);
//	}
//	return *this;
//}
//
//bool List::operator==(const List& original) {
//	if (mySize == original.mySize) {
//		if (mySize == 0) {
//			return true;
//		}
//		Node *myPtr = original.myFirst;
//		Node *myPtr2 = myFirst;
//
//		while (myPtr != nullptr) {
//			if (myPtr2 -> myItem != myPtr -> myItem) {
//				return false;
//			}
//			else {
//				return true;
//			}
//			myPtr = myPtr -> myNext;
//			myPtr2 = myPtr2 -> myNext;
//		}
//	}
//	if (mySize != original.mySize) {
//		return false;
//	}
//	return true;
//}
//
//bool List::operator!=(const List& l2) const {
//	if ( mySize == l2.getSize() ) {
//		Node* myNode = myFirst;
//		Node* l2Node = l2.myFirst;
//		while ( myNode != nullptr) {
//			if ( myNode->myItem != l2Node->myItem ) {
//				return true;
//			}
//			myNode = myNode->myNext;
//			l2Node = l2Node->myNext;
//		}
//		return false;
//	} else {
//		return true;
//	}
//}
//
//void List::readFrom(istream &in) {
//	if (mySize != 0) {
//		delete myFirst;
//	}
//	Item it;
//	while(in) {
//		if ( in.peek() == '\n' ) {
//			break;
//		}
//		in >> it;
//		append(it);
//	}
//	//	delete myFirst;
//	//	Item it;
//	//	in >> it;
//	//	while (in) {
//	//		if ( in.peek() == '\n' ) break;
//	//		in >> it;
//	//		append(it);
//	//	}
//}
//
//void List::writeTo( ostream &out, const char &separator) {
//	Node* myNode = myFirst;
//	for ( unsigned i = 0; i < mySize; i++ ) {
//		out << myNode->myItem << separator;
//		myNode = myNode->myNext;
//	}
//}
//
//void List::readFrom( const string &fileName ) {
//	delete myFirst;
//	myFirst = myLast = nullptr;
//	mySize = 0;
//	ifstream fin( fileName);
//	assert( fin.is_open() );
//	Item it;
//	fin >> it;
//	while( fin ) {
//		append(it);
//		fin >> it;
//	}
//	fin.close();
//}
//
//void List::writeTo(const string &fileName) {
//	ofstream fout(fileName);
//	assert(fout.is_open());
//	writeTo(fout, ' ');
////	Node* myPtr = myFirst;
////	while(myPtr) {
////		fout << myPtr->myItem << separator;
////		myPtr = myPtr->myNext;
////	}
//}
//
//void List::prepend(const Item& it) {
//	Node *myPtr = new Node(it, myFirst );
//	if ( mySize == 0 ) { myLast = myPtr; }
//	myFirst = myPtr;
//	mySize++;
//}
//
//int List::getIndexOf( const Item& it ) {
//	Node* myNode = myFirst;
//	int index = 0;
//	if ( mySize > 0 ) {
//		while ( it != myNode->myItem ) {
//			if ( myNode == nullptr ) {break;
//			} else {
//				myNode = myNode->myNext;
//				index++;
//			}
//		}
//		return index;
//	} else {
//		return -1;
//	}
//}
//
//void List::Insert(const Item it, unsigned index) {
//	Node *nodePtr2 = myFirst;
//
//	if(mySize == 0||index == 0) {
//		prepend(it);
//	}
//	else{
//		for(unsigned i = 0; i <index-1; i++){
//			nodePtr2 = nodePtr2->myNext;
//		}
//		nodePtr2->myNext = new Node(it,nodePtr2->myNext);
//		if (index >= mySize) {
//			myLast = new Node(it, nullptr);
//		}
//		mySize++;
//	}
//}
//
//Item List::remove( unsigned index ) {
//	Node* myNode = myFirst;
//	for ( unsigned i = 0; i <= index; i++ ) {
//		if ( i+1 == index ) {
//			Node* temp = myNode->myNext->myNext;
//			myNode->myNext = nullptr;
//			delete myNode->myNext;
//			myNode->myNext = temp;
//			mySize--;
//			break;
//		} else if (index == 0) {
//			Node* temp = myFirst->myNext;
//			myFirst->myNext = nullptr;
//			delete myFirst;
//			myFirst = temp;
//			mySize--;
//			break;
//		} else {
//			myNode = myNode->myNext;
//		}
//	}
//	return myNode->myItem;
//}




