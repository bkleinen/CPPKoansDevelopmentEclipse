/*
 * AboutFunctionCalls.cpp
 *
 *  Created on: 15.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include "AboutFunctionCalls.h"
#include "Assert.h"
#include <vector>
#define W "About Function Calls"

// aboutCallByValue
void someFunction1(int x, int y) {
	x = 0;
	y++;
}
void aboutCallByValue() {
	int a = 4711, b = 13;
	someFunction1(a, b);
	expectThat("if parameters are passed by value, ...", 4711, a);
	expectThat("they are not changed in the outside context", 13, b);
}

//aboutCallByReference
// pass by reference: just add a &
void someFunction2(int x, int &y) {
	x = 0;
	y++;
}
void aboutCallByReference() {
	int a = 4711, b = 13;
	someFunction2(a, b);
	expectThat("if parameters are passed by reference, ...", 4711, a);
	expectThat("they *are* changed in the outside context", 14, b);
}

// aboutConstCallByReference
class IntList {
public:
	int i;
	IntList* next;
};
void f1(IntList &list) {
	IntList localList;
	localList.i = 5;
	list = localList;
}
void f2(const IntList &list) {
	//now, list cant be changed anymore, so this wouldn't compile.
	//list = localList;
	// neither does this
	//list.i = 28;
	// this works as assigment makes a copy.
	IntList localList = list;
	localList.i = 28;
}
void aboutConstCallByReference() {
	IntList myList;
	myList.i = 2;
	f1(myList);
	expectThat("myList has been changed", 5, myList.i);
	f2(myList);
	expectThat("myList has been changed 2", 5, myList.i);
}

//about changing parameters in CBV
void f(int *p) {
	*p = 5;
	p = NULL;
}
void aboutChangingParametersInCBV() {
	int x = 2;
	int *q = &x;
	f(q);
	expectThat("the value of x has changed", 5, x);
	expectThatNot("only the pointer cannot be changed", NULL, q);
	expectThat("but the value it points to can", 5, *q);
}

//aboutArraysBeingAlwaysPassedByReference
void fa(char a[]) {
	a[1] = 'u';
	a[4] = 'u';
}
vector<char> fav(vector<char> a) {
	a[1] = 'u';
	a[4] = 'u';
	return a;
}

void aboutArraysBeingAlwaysPassedByReference() {
	char s1[] = "hallo";
	fa(s1);
	expectThat("s1 has changed to...", 0, strcmp("hullu", s1));
}

void aboutUsingVectorsInsteadOfArrays(){
	vector<char> v(6) ;
	char s[] = "Hallo";
	for (int i = 0;i<6;i++)
		v[i] = s[i];
	vector<char> copy = v;
	vector<char> formalParameter = fav(v);
	expectThat(W,"s has not changed", 0, strcmp("Hallo", s));
	expectThat("v hasn't changed",copy,v);
	expectThatNot("but the vector inside the function is different",copy,formalParameter);
}


void AboutFunctionCalls::meditate() {
	aboutCallByValue();
	aboutCallByReference();
	aboutConstCallByReference();
	aboutChangingParametersInCBV();
	aboutArraysBeingAlwaysPassedByReference();
	aboutUsingVectorsInsteadOfArrays();
}
