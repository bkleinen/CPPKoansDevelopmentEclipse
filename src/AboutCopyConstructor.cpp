/*
 * AboutCopyConstructor.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: kleinen
 *    for a great tutorial on this, see
 *    "Classes with Pointer Data Members" by Beck Hasti
 *    http://pages.cs.wisc.edu/~hasti/cs368/CppTutorial/NOTES/CLASSES-PTRS.html
 */
#include "Assert.h"
#include "AboutCopyConstructor.h"
#include <cstddef>

class ListPlain {
public:
	ListPlain() :
			i(0), next(NULL) {
	}
	ListPlain(int x) :
			i(x), next(NULL) {
	}
	ListPlain(int x, ListPlain * n) :
			i(x), next(n) {
	}
	int i;
	ListPlain *next;
	int countElements() {
		int c = 0;
		for (ListPlain *p = this; p != NULL; p = p->next)
			c++;
		return c;
	}
};

void aboutListPlain() {
	ListPlain * list = new ListPlain(3);
	list = new ListPlain(2, list);
	list = new ListPlain(1, list);
	list = new ListPlain(0, list);
	expectThat("countElements counts the Elements", 4, list->countElements());
}
void aboutCopyingListPlain() {
	ListPlain secondElement(2);
	ListPlain firstElement(1, &secondElement);
	expectThat("check on length", 2, firstElement.countElements());
	// this results in a shallow copy.
	ListPlain copy = firstElement;
	copy.i = 3;
	expectThat("first element of list has not changed", 1, firstElement.i);
	copy.next->i = 47;
	expectThat("now the second element of the first list has also changed", 47,
			secondElement.i);
}

class List {
public:
	List(int x);
	List(int x, List * n);
	List(const List & l);
	int i;
	List *next;
	int length();
};
List::List(int x) :
		i(x) {
	next = NULL;
}
;
List::List(int x, List * n) :
		i(x), next(n) {
}
;
// copy constructor
List::List(const List & l) :
		i(l.i) {
	if (l.next == NULL)
		next = NULL;
	else {
		next = new List(l.next->i);
	}
}
;
int List::length() {
	int c = 0;
	for (List *p = this; p != NULL; p = p->next)
		c++;
	return c;
}
class ListOp: public List {
public:
	ListOp(int i);
	ListOp(int x, ListOp * n);
	ListOp(const ListOp & l);
	ListOp & operator=(const ListOp &L);

};
ListOp::ListOp(int i): List(i){};
ListOp::ListOp(int x, ListOp * n): List(x,n){};
ListOp::ListOp(const ListOp & l): List(l){};
ListOp & ListOp::operator=(const ListOp &L) {
	if (this != &L) {
		delete next; // free the storage pointed to by Items
		if (L.next != NULL)
			next = new ListOp(L.next->i);
	}
	return *this; // return this IntList
}

void aboutDeepCopyingListWithCopyOperator() {
	List secondElement(2);
	List firstElement(1, &secondElement);
	expectThat("check on length", 2, firstElement.length());
	// this results in a shallow copy.
	List copy = firstElement;
	copy.i = 3;
	expectThat("first element of list has not changed", 1, firstElement.i);
	copy.next->i = 47;
	expectThat("with a deep copy, the second element is not affected", 2,
			secondElement.i);
	expectThat("the second element of the copy is set differently", 47,
			copy.next->i);
	expectThat("the length of the copy is the same as the original", 2,
			copy.length());

}

void aboutOperatorOverloading() {
	List secondElement(2);
	List firstElement(1, &secondElement);
	expectThat("check on length", 2, firstElement.length());
	// this results in a shallow copy.
	List copy(0);
	// here, the copy operator is not called automatically!
	copy = firstElement;
	copy.i = 3;
	expectThat("first element of list has not changed", 1, firstElement.i);
	copy.next->i = 47;
	expectThat(
			"as the copy operator was not called in this case, the second element is affected",
			47, secondElement.i);
}

void aboutOperatorOverloadingTwo() {
	ListOp secondElement(2);
	ListOp firstElement(1, &secondElement);
	expectThat("check on length", 2, firstElement.length());
	// this results in a shallow copy.
	ListOp copy(0);
	// here, the copy operator is not called automatically!
	copy = firstElement;
	copy.i = 3;
	copy.next->i = 47;
	expectThat(
			"as the = operator is overloaded, this works",
			2, secondElement.i);
}
void AboutCopyConstructor::meditate() {
	aboutListPlain();
	aboutCopyingListPlain();
	aboutDeepCopyingListWithCopyOperator();
	aboutOperatorOverloading();
	aboutOperatorOverloadingTwo();

}

