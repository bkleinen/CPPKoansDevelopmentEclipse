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
	ListPlain firstElement(1,&secondElement);

	ListPlain * list = new ListPlain(2);
	list = new ListPlain(1, list);
	expectThat("check on length", 2, list->countElements());
	// this results in a shallow copy.
	ListPlain list2 = *list;
	list2.i = 3;
	expectThat("go on here...", 2, 3);

}

class List {
public:
	List(int x) :
			i(x) {
		next = NULL;
	}
	List(int x, List * n) :
			i(x), next(n) {
	}
	int i;
	List *next;
	int countElements() {
		int c = 0;
		for (List *p = this; p != NULL; p = p->next)
			c++;
		return c;
	}
};

void aboutDeepCopyingList() {
	expectThat(
			"now create an copy constructor and overload = to get correct behavior.",
			0, 1);
}
void AboutCopyConstructor::meditate() {
	aboutListPlain();
	aboutCopyingListPlain();
	aboutDeepCopyingList();

}

